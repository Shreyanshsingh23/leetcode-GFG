class Solution {
public:
    vector<int> leftRightDifference(vector<int>& a) {
        int n = a.size();
        vector<int> left(n), right (n);
        for(int i = 1; i < n; ++i){
            left[i] = left[i-1] + a[i-1];
            cout << left[i] << " ";
        }

        cout << endl;
        for(int i = n-2; i >= 0; --i){
            right[i] = right[i+1] + a[i+1];
            cout << right[i] << " ";
        }
        
        vector<int> ans(n);
        for(int i = 0; i< n; ++i){
            ans[i] = abs(left[i] - right[i]);
        }

        return ans;
    }
};