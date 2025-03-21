class Solution {
public:

    int dp[2][2][2];
    
    int rob(vector<int>& a) {

        const int n = a.size();

        for(int i = n; i >= 0; --i){
            for(int prev = 1; prev >= 0; --prev){
                for(int first = 1; first >= 0; --first){
                    int& ans = dp[i&1][prev][first];

                    if(i == n){
                        ans = 0;
                        continue;
                    }
                    
                    int ans1 = dp[(i+1)&1][false][first];

                    bool canTake = prev? false:true;
                    if(i == n-1){
                        canTake &= !first;
                    }

                    int ans2 = 0;
                    if(canTake){
                        ans2 = a[i] + dp[(i+1)&1][true][first or i == 0];
                    }
                    ans = max(ans1,ans2);
                }
            }
        }
            return dp[0][0][0];

    }
};