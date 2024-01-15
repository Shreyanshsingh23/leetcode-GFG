class Solution {
    public void reverseString(char[] s) {
        reverse(s,0,s.length-1);
        
    }

    static void reverse(char[] s, int start, int end){
        
        // base condition
        if(start >= end){
            return;
        }

        swap(s,start,end);
        reverse(s,start+1,end-1);
    }

     static void swap(char[] s, int a , int b){
         char temp = s[a];
         s[a] = s[b];
         s[b] = temp;

     }
}