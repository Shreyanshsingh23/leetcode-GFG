class Solution {
public:

   

    void f(vector<int>& a, int target, int idx, vector<int>& cur,vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(cur);
            return;
        }
        int n = a.size();
        for(int i = idx; i < n; ++i){
            if(i > idx and a[i] == a[i-1])continue;
            if(a[i] > target)break;

            cur.push_back(a[i]);
            f(a,target - a[i], i + 1, cur,ans);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        sort(a.begin(),a.end());
        vector<vector<int>> ans;
        vector<int> cur;
        f(a,target,0,cur,ans);
        return ans;
    }
};