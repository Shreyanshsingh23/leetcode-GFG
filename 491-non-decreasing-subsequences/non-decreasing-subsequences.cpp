class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;

    void f(vector<int>& nums, int i)
    {
        int n = nums.size();
        if(i == n){
            if(cur.size() > 1)
            ans.push_back(cur);
            return;
        }

        f(nums,i+1);

        if(cur.empty() or cur.back() <= nums[i])
        {
            cur.push_back(nums[i]);
            f(nums,i+1);
            cur.pop_back();
        }

    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        f(nums,0);
        set<vector<int>> st = {ans.begin(),ans.end()};
        ans = {st.begin(),st.end()};
        return ans;

    }
};