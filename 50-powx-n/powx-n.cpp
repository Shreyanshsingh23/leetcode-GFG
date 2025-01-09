class Solution {
public:
    double rec(double x, long long n){
        if(n == 0)return 1.0;

        if(!(n&1)){
            double a = rec(x,n/2);
            return a*a;
        }
        else{
            double a = rec(x,(n-1)/2);
            return a*a*x;
        }

    }
    double myPow(double x, int n) {
        long long N = n;
       if(N < 0){
         N *= -1;
         double ans = rec(x,N);
         return 1.0/ans;
       }

        return rec(x,N);
        
    }
};