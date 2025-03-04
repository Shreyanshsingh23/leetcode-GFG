class Solution {
public:

    bool f(int n, int i){
        if(n == 0)return 1;

        int ans = 0;
        for(int j = i+1; ; ++j){
            int t = pow(3,j);
            if(t > n)break;
            ans |= f(n-t,j);
            if(ans)break;
        }

        return ans;
    }

    bool checkPowersOfThree(int n) {
        return f(n,-1);
    }
};