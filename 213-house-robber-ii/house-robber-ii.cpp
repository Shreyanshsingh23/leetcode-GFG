class Solution {
public:

    int dp[101][2][2];
    int f(vector<int>& a, int i, bool prev, bool first)
    {
        const int n = a.size();
        if(i == n)return 0;

        int& ans = dp[i][prev][first];
        if(ans != -1)return ans;
        // not take
        int ans1 = f(a,i+1,false,first);

        // take if possible
        bool canTake = prev? false:true;
        if(i == n-1)canTake &= !first;
        int ans2 = 0;
        if(canTake){
            ans2 = a[i] + f(a,i+1,true,first or i == 0);
        }
        ans = max(ans1, ans2);
        return ans;
        
    }

    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        
        return f(nums,0,0,0);
    }
};