class Solution {
    public boolean isPowerOfTwo(int n) {
         if(n==1){
            return true;
        }
        
      //  boolean bool = check(n,1);
          boolean bool = checkByBitOperator(n);
        return bool;
    }

    static boolean checkByBitOperator(int n){
       long n1 = (long) n;
       
       if(n==0){
           return false;
       }
       
        long ans = n1 & n1-1;
        if(ans == 0){
            return true;
        }
        return false;
    }
    
    static boolean check(int n, int x){
        
        // base condition
        if(n < Math.pow(2,x)){
            return false;
        }
        
       
            
            if(n == Math.pow(2,x)){

                return true;
                
            }
        
         return check(n,x+1);
            
    }
}