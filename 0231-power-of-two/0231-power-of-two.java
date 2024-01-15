class Solution {
    public boolean isPowerOfTwo(int n) {
         if(n==1){
            return true;
        }
        
        boolean bool = check(n,1);
        return bool;
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