class Solution {
public:

    char calculate(char ch, vector<char>& v){
        if(ch == '!'){
            if(v[0] == 't')return 'f';
            return 't';
        }
        else if(ch == '&'){
            for(int i = 0; i< v.size(); i++){
                if(v[i] == 'f'){
                    return 'f';
                }
            }
            return 't';
        }
        else{
            for(int i= 0; i< v.size(); i++){
                if(v[i] == 't')return 't';
            }

            return 'f';
        }
    }


    bool parseBoolExpr(string s) {
        stack<char> st;
        int i = 0;
        while(i < s.size()){
            if(s[i] == ')'){
                vector<char> v;
                while(true){
                    if(st.top() == '('){
                         st.pop();
                         char ch = st.top();
                         st.pop();
                         char res = calculate(ch,v);
                         st.push(res);
                         i++;
                         break;
                    }
                    v.push_back(st.top());
                    st.pop();
                    
                }

            }
            else{
                if(s[i] != ','){
                    st.push(s[i]);
                }
                i++;
            }
        }

        if(st.top()== 't') return true;
        return false;
    }
};