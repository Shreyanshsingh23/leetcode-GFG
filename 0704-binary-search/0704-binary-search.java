class Solution {
    public int search(int[] nums, int target) {
        int ans = BS(nums,target,0,nums.length -1);
        return ans;
    }
    
    static int BS(int[] arr, int target, int start, int end){

        // base condition
        if(start > end){
            return -1;
        }
        
        // body
         
        int mid = start + (end - start )/2;
        
        if(arr[mid] == target){
            return mid;
        }
        
        if(arr[mid] > target){
            return BS(arr,target,start,mid-1);
        }
        
        return BS(arr,target,mid+1,end);
    
    }
}