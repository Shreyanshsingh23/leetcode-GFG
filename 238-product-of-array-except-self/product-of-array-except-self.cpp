class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int n = a.size();
        int cnt = 0;
        int prod = 1;
        for(int i = 0; i< n; ++i){
            if(a[i] == 0){
                ++cnt;
            }
            else{
                prod *= a[i];
            }
        }
        vector<int> ans (n,0);
        if(cnt > 1){
            return ans;
        }
        for(int i = 0; i < n ; ++i){
            if(a[i] == 0){
                ans[i] = prod;
            }
            else{
                if(cnt > 0)ans[i] = 0;
                else
                ans[i] = prod/a[i];
            }
        }

        return ans;
       
    }
};