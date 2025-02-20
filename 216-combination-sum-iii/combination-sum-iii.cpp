class Solution {
public:

    vector<int> cur;
    vector<vector<int>> ans;

    void f(int k, int n, int choice)
    {
        if(k == 0){
            if(n == 0)ans.push_back(cur);
            return;
        }
        if(choice > 9)return;

        f(k,n,choice+1);

        cur.push_back(choice);
        f(k-1,n - choice,choice + 1);
        cur.pop_back();
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        f(k,n,1);
        return ans;
    }
};