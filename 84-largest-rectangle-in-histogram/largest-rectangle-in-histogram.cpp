class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int n = a.size();
        vector<int> nsl(n,-1), nsr(n,n);
        stack<int> st;
        for(int i = 0; i < n; ++i){
            while(!st.empty() and a[st.top()] >= a[i])st.pop();
            if(st.size())nsl[i] = st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i = n-1; i >= 0; --i){
            while(!st.empty() and a[st.top()] >= a[i])st.pop();
            if(st.size()) nsr[i] = st.top();
            st.push(i);
        }
        
        int ans = 0;
        for(int i = 0; i< n; ++i){
            int w = nsr[i]-nsl[i]-1;
            
            ans = max(ans,a[i]*w);
        }
        return ans;
    }
};