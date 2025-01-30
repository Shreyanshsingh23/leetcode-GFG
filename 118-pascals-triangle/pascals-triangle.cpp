class Solution {
public:
    void f(int i, int n, vector<vector<int>>& ans){
        if(i == n)return;

        for(int j = 1; j < i; ++j){
            ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
        }
        f(i+1,n,ans);
    }

    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        for(int i = 1; i <= n; ++i){
            vector<int> t(i,1);
            ans.push_back(t);
        }
        if(n >= 2)
        f(2,n,ans);
    return ans;
    }
};