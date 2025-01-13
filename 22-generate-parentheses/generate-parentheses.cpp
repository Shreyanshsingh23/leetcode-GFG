#define pb push_back
class Solution {
public:
    vector<string> ans;
    
    void rec(int n, string& s, int l, int r){
        //positive basecase
        if(l == n and r == n){ 
            ans.pb(s);
            return;
        }
        //negative basecase
       
        if(l < n) {
            s += "(";
            rec(n,s, l+1, r);
            s.pop_back();
        }
        if(r < n and r < l) {
            s += ")";
            rec(n,s, l, r+1);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string t = "";
       rec(n,t, 0, 0);
       return ans;
    }
};