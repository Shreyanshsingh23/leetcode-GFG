class Solution {
public:
    
    bool f(vector<int>& a,int i, vector<int>& t)
    {

        if(i == a.size()){
            return 1;
        }
        
        // transitions
        int ans = 0;
        for(auto& e : t){
            if(e - a[i] >= 0){
                e -= a[i];
                if(f(a,i+1,t)) return true;
                e += a[i];
            }
        }
        return false;
    }

    bool makesquare(vector<int>& a) {
        int sum = 0;
        int n = a.size();
        for(int i = 0; i < n; ++i)sum += a[i];

        if(sum % 4 != 0)return 0;

        int x = sum / 4;
        vector<int> temp = {x,x,x,x};
        int target = x;
        sort(a.rbegin(), a.rend());
        return f(a,0,temp);

    }
};