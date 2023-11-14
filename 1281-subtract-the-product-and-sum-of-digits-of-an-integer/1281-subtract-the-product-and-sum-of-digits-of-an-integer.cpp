class Solution {
public:
    int subtractProductAndSum(int n) {
    
    int prod = 1;
    int sum = 0;

    while(n != 0){
    int i = n % 10;
    n = n / 10;
    
    prod = prod * i;
    sum = sum + i;
    
    }
   int answer = prod - sum;
    return answer;





    }
};