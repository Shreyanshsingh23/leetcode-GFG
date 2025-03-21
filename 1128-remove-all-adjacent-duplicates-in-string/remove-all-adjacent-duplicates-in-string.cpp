class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(auto e: s){
            if(!st.empty() and e == st.top()){
                st.pop();
                continue;
            }
            else st.push(e);
        }

        string ans = "";
        while(!st.empty()){
            auto e = st.top();
            ans+=e;
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};