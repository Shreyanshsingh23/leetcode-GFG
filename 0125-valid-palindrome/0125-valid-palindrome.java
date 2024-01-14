class Solution {
    public boolean isPalindrome(String s) {
     s = s.toLowerCase();
     if(s == null || s.length() == 0){
         return true;
     }
     //String[] arrOfStr = s.split("['!?,|{}\\:#%$&*\"._@ ]+");    
      //String[] arrOfStr = s.split("[^a-zA-Z]+");
      String[] arrOfStr = s.split("[^a-zA-Z0-9]+");
     s = "";
     for(int i = 0; i < arrOfStr.length ; i++){
         s = s + arrOfStr[i];
     }

     boolean bool = checkByRecursion(s,0,s.length()-1);
     return bool;
     
    }

    static boolean checkByRecursion(String s,int start, int end){

        // base case
        if(start > end){
            return true;

        }

        // edge case
        if(s==null || s.length() == 0){
            return true;
        }

        if(s.charAt(start) != s.charAt(end)){
            return false;

            
        }
        return checkByRecursion(s,start+1,end-1);
    }
}