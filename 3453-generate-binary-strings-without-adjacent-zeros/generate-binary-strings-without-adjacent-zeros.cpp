class Solution {
public:
    vector<string> ans;
    void f(int n, string& cur)
    {
        if(n == 0){
            ans.push_back(cur);
            return;
        }

        cur += '1';
        f(n-1,cur);
        cur.pop_back();

        if(cur.size() == 0 or cur.back() == '1'){
            cur += '0';
            f(n-1,cur);
            cur.pop_back();
        }
    }

    vector<string> validStrings(int n) {
        string s = "";
        f(n,s);
        return ans;
    }
};