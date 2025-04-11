class Solution {
public:
    void findLeftMin(vector<int>&a, vector<int>&ans)
    {
        int n = a.size();
        stack<int>st;
        for(int i = 0;i < n; ++i)
        {
            while(!st.empty() and a[st.top()] >= a[i])
            {
                st.pop();
            }
            if(!st.empty())ans[i] = st.top();
            st.push(i);
        }
    }

    void findLeftMax(vector<int>&a, vector<int>&ans)
    {
        int n = a.size();
        stack<int>st;
        for(int i = 0;i < n; ++i)
        {
            while(!st.empty() and a[st.top()] <= a[i])
            {
                st.pop();
            }
            if(!st.empty())ans[i] = st.top();
            st.push(i);
        }
    }

    void findRightMin(vector<int>&a, vector<int>&ans)
    {
        int n = a.size();
        stack<int>st;
        for(int i = n-1;i >= 0; --i)
        {
            while(!st.empty() and a[st.top()] > a[i])
            {
                st.pop();
            }
            if(!st.empty())ans[i] = st.top();
            st.push(i);
        }
    }

    void findRightMax(vector<int>&a, vector<int>&ans)
    {
        int n = a.size();
        stack<int>st;
        for(int i = n-1;i >= 0; --i)
        {
            while(!st.empty() and a[st.top()] < a[i])
            {
                st.pop();
            }
            if(!st.empty())ans[i] = st.top();
            if(a[i] == 1 and !st.empty())cout << st.top() << endl;
            st.push(i);
        }
    }

    long long subArrayRanges(vector<int>& a) {
        int n = a.size();
        vector<int> leftMin(n,-1), rightMin(n,n), leftMax(n,-1), rightMax(n,n);
        findLeftMin(a,leftMin);
        findLeftMax(a,leftMax);
        findRightMin(a,rightMin);
        findRightMax(a,rightMax);
        long long ans = 0;
        for(int i = 0; i < n; ++i)
        {
            long long leftMinCount = i-leftMin[i]; 
            long long leftMaxCount = i-leftMax[i]; 
            long long rightMinCount = rightMin[i]-i; 
            long long rightMaxCount = rightMax[i]-i; 
            ans += (leftMaxCount*rightMaxCount - leftMinCount*rightMinCount)*a[i];
        }
        return ans;
    }
};