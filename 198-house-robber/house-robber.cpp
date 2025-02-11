class Solution {
public:
    int dp[400];
    int f(int i, vector<int>& a){
        int n = a.size();
        if(i >= n){
            return 0;
        }

        if(dp[i] != -1)return dp[i];
        
        // dont rob this house
        int ans = f(i+1,a);

        //rob this house
        ans = max(ans,f(i+2,a)+a[i]);
        return dp[i] = ans;
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return f(0,nums);
    }
};