class Solution {
    public int mySqrt(int x) {
        long start = 1, end = x/2;
        
        if(x==1){
            return 1;
        }
        while(start <= end){
            long mid = start + ((end - start)/2);
            if((mid*mid) > x ){
                end = mid - 1;
            }
            else if((mid*mid) <= x){
                start = mid + 1;
            }
           
        }
        return (int)end;
    }
}