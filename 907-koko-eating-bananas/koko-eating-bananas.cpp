class Solution {
public:
bool check(long long mid, vector<int>& a,int h){
    long long ans = 0;
    for(int i = 0; i < a.size(); ++i){
        ans += (a[i] + mid - 1)/mid;
    }

    return ans <= h;
}
    int minEatingSpeed(vector<int>& a, int h) {
        long long l = 1, r = 1e18, mid;
        int ans = 0;
        while(l <= r){
            mid = (l+r) >> 1;
            if(check(mid,a,h)){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        return ans;
    }
};