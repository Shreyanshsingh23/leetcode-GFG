#define pb push_back
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 1){
            vector<string> ans;
            ans.pb("()");
            return ans;
        }

        vector<string> prev = generateParenthesis(n-1);
        vector<string> ans;
        set<string> st;
        string t = "()";
        for(auto e : prev){
            for(int i = 0; i < e.size(); ++i){
                string left = e.substr(0,i);
                // cout << "l: " << left << endl;
                string right = e.substr(i);
                // cout << "r: " << right << endl;
                string res = left;
                res += t;
                res += right;
                st.insert(res);
            }
        }

        for(auto e : st){
            ans.pb(e);
        }

        return ans;
    }
};