class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
       
        bool ans = true;
        for(int i = 0;i< s.size(); i++){
            if(s[i] == ')'){
                if(st.size()>0 and st.top() == '(')st.pop();
                else{
                    ans = false;
                    break;
                }
            }
                else  if(s[i] == ']'){
                if(st.size()>0 and st.top() == '[')st.pop();
                else{
                    ans = false;
                    break;
                } 
                }
                else  if(s[i] == '}'){
                if(st.size()>0 and st.top() == '{')st.pop();
                else{
                    ans = false;
                    break;
                } 
                 }
            else{
                st.push(s[i]);
                
            }
        }
         if(!st.empty()) return false;
        if(ans) return true;
        return false;
    }
};