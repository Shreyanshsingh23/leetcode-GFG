#define pb push_back
class Solution {
public:
    vector<vector<int>> ans;

    void rec(vector<int> a, vector<int> curr){
       if(a.size() == 0){
        ans.pb(curr);
        curr = {};
        return;
       }

        int n = a.size();
       for(int i = 0; i < n; ++i){
        int element = a[i];
        vector<int> temp;
        for(int j = 0; j < n; ++j){
            if(j != i)temp.pb(a[j]);
        }
        curr.pb(element);
        rec(temp,curr);
        curr.pop_back();
       }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        rec(nums,temp);
        return ans;
    }
};