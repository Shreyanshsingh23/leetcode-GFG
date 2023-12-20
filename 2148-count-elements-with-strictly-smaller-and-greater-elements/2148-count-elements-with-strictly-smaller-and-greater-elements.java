class Solution {
    public int countElements(int[] nums) {
        int count = 0;
        boolean bool1 , bool2 ;
        for(int e : nums){
              bool1  = false;
            bool2 = false;
            for(int i = 0 ; i < nums.length ; i++){
                bool1 = nums[i] < e ;
                if(bool1){
                    break;
                }
            }
            if(bool1){
                for(int j = 0 ; j < nums.length ; j++){
                    bool2 = nums[j] > e;
                    if(bool2){
                        break;
                    }
                }
            }
         if(bool1 && bool2){
             count ++;
         }   
        }
        return count;
    }
}