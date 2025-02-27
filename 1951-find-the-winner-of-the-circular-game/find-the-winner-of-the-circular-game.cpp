class Solution {
public:
    int f(int n, int k)
    {
        if(n == 1)return 0;

        int prevAns = f(n-1,k);
        prevAns += k;
        prevAns %= n;
        return prevAns;
    }

    int findTheWinner(int n, int k) {
        return f(n,k) + 1; //1 - based indexing
    }
};