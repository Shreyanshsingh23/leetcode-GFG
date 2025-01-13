#define pb push_back
class Solution {
public:
    int n;
    void rec(int i, vector<vector<int>>& ans, vector<int>& curr){
        if(i == n){
            ans.pb(curr);
            return;
        }

        for(int j = i; j < n; ++j){
            swap(curr[i],curr[j]);
            rec(i+1,ans,curr);
            swap(curr[i],curr[j]);

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        n = nums.size();
        rec(0,ans,nums);
        return ans;
    }
};