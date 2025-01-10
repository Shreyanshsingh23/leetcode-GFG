class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        vector<int> left(n), right(n), ans(n);
        left[0] = a[0];right[n-1] = a[n-1];
        for(int i = 1; i < n; ++i){
            left[i] = max(left[i-1], a[i]);
        }
        
        for(int i = n-2; i >= 0; --i){
            right[i] = max(right[i+1], a[i]);
        }
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            ans[i] = min(left[i], right[i]) - a[i];
            if(ans[i] < 0)ans[i] = 0;
            cnt += ans[i];
        }

       return cnt;
    }
};