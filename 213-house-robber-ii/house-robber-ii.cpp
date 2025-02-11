class Solution {
public:
    int dp[500][2];
    bool done[500];
    int f(int i, vector<int>& a,int k){
        int n = a.size();
        if(i>= n)return 0;

       if(i == n-1){
        if(k == 0)return 0;
        else return a[i];
       }
        
        if(dp[i][k] != -1)return dp[i][k];

        //don't take
        int ans = f(i+1,a,k);

        //take
        done[i] = 1;
        ans = max(ans,f(i+2,a,k)+a[i]);
        done[i] = 0;

        return dp[i][k] = ans;

    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));

        return max(f(2,nums,0)+nums[0],f(1,nums,1));
    }
};