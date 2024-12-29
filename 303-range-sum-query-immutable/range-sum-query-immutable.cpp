class NumArray {
public:
    vector<int> pref;
    NumArray(vector<int>& a) {
        pref.push_back(a[0]);
        int n = a.size();
        for(int i = 1; i< n; ++i){
            pref.push_back(pref[i-1] + a[i]);
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0)return pref[right];
        else return pref[right] - pref[left -1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */