

class Solution {
    public int[] searchRange(int[] nums, int target) {
       int [] ans = new int[2];
        ans = index(nums,target);
        return ans;
    }
    
    static int[] index(int[] array, int target){
         int [] ans = {-1,-1};
        ans[0] = findindex(array,target,true);
        ans[1] = findindex(array,target,false);
        
        return ans;
    }
    
    static  int findindex(int [] array, int  target, boolean bool){
        int start = 0;
        int end = array.length - 1;
        int mid = 0;
        int ans = -1;
        
        while(start <= end ){
            mid = start + (end - start)/2;
            
            if(array[mid] < target){
                start = mid + 1;}
               else if(array[mid] > target){
                  end = mid - 1;
                }
            
        else{ 
            ans = mid;
             if(bool)
             {end = mid - 1;}
             
             else{
            start = mid + 1;
        }
       
        
    }
    }return ans;
    }
   
}