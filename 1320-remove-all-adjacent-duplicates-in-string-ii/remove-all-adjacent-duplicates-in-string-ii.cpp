class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        for(auto e: s){
            if(st.empty()){
                st.push({e,1});
                continue;
            }
            if(e == st.top().first){
                st.push({e,st.top().second+1});
                if(st.top().second >= k){
                    for(int i = 0; i < k; ++i){
                        st.pop();
                    }
                }
            }
            else{
                st.push({e,1});
            }
        }

        string ans = "";
        while(!st.empty()){
            auto e = st.top();
            ans += e.first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};