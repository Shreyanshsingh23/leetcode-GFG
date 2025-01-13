#define pb push_back
class Solution {
public:
    vector<string> ans;
    
    void rec(int n, string s, int l, int r){
        //positive basecase
        if(l == n and r == n){ 
            ans.pb(s);
            return;
        }
        //negative basecase
        if(l > n or r > n or r > l){
            return;
        }


        rec(n,s+'(', l+1, r);
        rec(n,s+')', l , r+1);
    }

    vector<string> generateParenthesis(int n) {
       rec(n,"", 0, 0);
       return ans;
    }
};