class Solution {
public:
    int lastRemaining(int n) {
        int head = 1, step = 1;
        bool direction = true; // true ---> , false <---

        while(n > 1)
        {
             if(direction){
                head += step;
             }
             else{
                if(n&1){
                    head += step;
                }
             }
             step <<= 1;
             n >>= 1;
             direction = !direction;

        }

        return head;
    }
};