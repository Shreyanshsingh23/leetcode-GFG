class Solution {
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        int  n = a[0].size();
        vector<int> b;
        for(int i = 0;i < n; i++){
            for(int j = 0; j< n; ++j){
                b.push_back(a[i][j]);
            }
        }

        sort(b.begin(), b.end());
        return b[k-1];
    }
};