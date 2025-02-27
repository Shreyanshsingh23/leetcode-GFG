class Solution {
public:
    int f(int n, int k)
    {
        if(n == 1)return 0;
        if(k == (1 << (n-1)))return 1;

        if(k > (1 << (n-1))){
            return 1 - f(n-1,(1 << n) - k);
        }
        else return f(n-1,k);
    }

    char findKthBit(int n, int k) {
        int ans = f(n,k);
        cout << ans << endl;
        return ans + '0';
    }
};