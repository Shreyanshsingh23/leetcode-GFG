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
                string lst = "";
                int cnt = 0;
                pair<string,int> p  = st.top();
                lst = p.first;cnt = p.second;
                st.pop();
                string temp = cur;
                cur = lst;
                 for(int i = 0;i < cnt; ++i){
                    cur += temp;
                 }
            }
            else cur += e;
        }

        return cur;
    }
};