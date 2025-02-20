class Solution {
    vector<int> cur;
    vector<vector<int>> ans;
public:

    void f(vector<int>& candidates, int target, int i)
    {
        
        
        int n = candidates.size();
        if(i == n){
        if(target == 0){
            ans.push_back(cur);
        }
            return;
        }

        f(candidates,target,i + 1);
        cur.push_back(candidates[i]);
        if(target - candidates[i] >= 0) f(candidates,target - candidates[i], i);
        cur.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        f(candidates,target,0);
        return ans;
    }
};