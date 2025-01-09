class Solution {
public:
    
    string decodeString(string s) {
        string cur = "";
        stack<pair<string,int>> st;
        int num = 0;
        for(auto e : s){
            if(e - '0' <= 9 and e -'0' >= 0){
                num = num* 10 + (e-'0');
            }
            else if(e == '['){
                st.push({cur,num});
                cur = "";num = 0;
            }
            else if(e == ']'){
                
                auto [lst,cnt]  = st.top();
                
                st.pop();
                string repeated = "";
                 for(int i = 0;i < cnt; ++i){
                   repeated += cur;
                 }
                 cur = lst + repeated;
            }
            else cur += e;
        }

        return cur;
    }
};