class Solution {
public:
    vector<int> ans;
    int f(vector<int>& a, int k, int i)
    {
        int n = a.size();
        if(i == n){
            return *max_element(ans.begin(),ans.end());
        }
        int res = 1e9;
        for(int j = 0; j < k; ++j)
        {
            ans[j] += a[i];
            res = min(res,f(a,k,i+1));
            ans[j] -= a[i];
        }

        return res;
    }
    int distributeCookies(vector<int>& a, int k) {
        ans.resize(k,0);
        sort(a.rbegin(),a.rend());

        return f(a,k,0);
    }
};