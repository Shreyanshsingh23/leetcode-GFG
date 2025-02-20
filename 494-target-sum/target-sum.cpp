class Solution {
public:

    int f(vector<int>& nums, int target, int i)
    {
        int n = nums.size();
        if(i == n){
            if(target == 0)return 1;
            return 0;
        }

        int ans = 0;
        ans += f(nums,target + nums[i], i+1);
        ans += f(nums,target - nums[i], i+1);

        return ans;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return f(nums,target,0);
    }
};