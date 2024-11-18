class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
      
        int n = code.size();
        vector<int> pref(n);
        pref[0] = code[0];
        for(int i = 1; i< n; i++){
            pref[i] = pref[i-1] + code[i];
        }
        vector<int> ans(n);
        if(k > 0){
            for(int i = 0; i< n; i++){
                if(i+k >= n){
                    ans[i] = pref[n-1] - pref[i];
                    cout << ans[i] << ' ';
                    ans[i] += pref[(i+k)%(n)];
                    cout << ans[i] << endl;
                }
                else{
                    ans[i] = pref[i+k] - pref[i];
                }
            }
        }
        else if(k < 0){
                k *= -1;
               for(int i = 0; i< n; i++){
                code.push_back(code[i]);
               }
             vector<int> pre(2*n);
             pre[0] = code[0];
             for(int i = 1; i< 2*n;i++){
                pre[i] = pre[i-1]+code[i];
             }
             ans[0] = pre[k-1];
             for(int i = k+1; i < k+1+n; i++){
                ans[i%n] = pre[i] - code[i] - pre[i-k-1];
             }


            //    for(int i = k; i< k+n; i++){
            //     ans[i] = 
            //    }
        }
        return ans;
    }
};