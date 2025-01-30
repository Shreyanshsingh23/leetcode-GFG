class Solution {
public:
 
 int dp[50] = {0};
 int f(int i, int n){
    if(i == 0)return 1;
        if(i < 0)return 0;
        if(dp[i] != -1)return dp[i];
        int ans = 0;
        ans += f(i-1,n);
        ans += f(i-2,n);
        return dp[i] = ans;
 }

    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return f(n,n);
    }
};