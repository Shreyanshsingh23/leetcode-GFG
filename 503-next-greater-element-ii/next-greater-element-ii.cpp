class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        stack<int> st;
        vector<int> ans, b = a;
        for(auto e: a)b.push_back(e);
        int n = a.size();
        for(int i = 2*n-1; i >= 0; --i){
            while(!st.empty() and st.top() <= b[i])st.pop();

            if(i <= n-1){
                if(st.empty())ans.push_back(-1);
                else ans.push_back(st.top());
            }
            st.push(b[i]);
        }
        reverse(ans.begin(),ans.end());
       return ans;
    }
};