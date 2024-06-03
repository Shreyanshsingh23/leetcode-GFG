class Solution {
    public boolean containsDuplicate(int[] nums) {
        // bubbleSort(nums,nums.length-1,0);
        
        Arrays.sort(nums);
        
        for(int i = 0; i < nums.length-1 ; i ++ ){
            
            if(nums[i+1] == nums[i]){
                return true;
            }
}
        
        return false;
    }
    
    
static void bubbleSort(int[] arr,int r, int c){
        if(r==0){
            return;
        }

        if(c<r){
          if(arr[c] > arr[c+1]){
            swap(arr,c,c+1);
             bubbleSort(arr,r,c+1);
          }
          else{
            bubbleSort(arr,r,c+1);
          }

        }
        else{
             bubbleSort(arr,r-1,0);
        }
    }
    static void swap(int[] arr, int f, int s){
        int temp = arr[f];
        arr[f] = arr[s];
        arr[s] = temp;
    }
}