class Solution {
    public int findPeakElement(int[] nums) {
             int start = 0;
        int end = nums.length - 1;
                   int mid = 0;

        
        while(start < end ){
            mid = start + (end - start)/2;
       
            if(nums[mid] > nums[mid+1]){
               
                   end =  mid  ;
            }
                else{
                    start = mid + 1;
                    
                }  
            
        }
        return start;
    }
}