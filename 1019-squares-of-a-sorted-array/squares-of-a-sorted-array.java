class Solution {
    // public int[] sortedSquares(int[] nums) {
    //     for(int i = 0; i < nums.length;i++){
    //         nums[i]= Math.abs(nums[i]);
    //     }
    //    Arrays.sort(nums);
    //    for(int i = 0; i < nums.length;i++){
    //         nums[i] *= nums[i];
    //     }

    //         return nums;
    // }

    //correct but now will follow two pointers approach with O(n) complexitiy

    public int[] sortedSquares(int[] nums){
        

        //Square of each number is positive or 0 which means we don't have to care about negative 
        //or positive for original numbers. We can foucs on only numbers even if numbers are negative.
        // For example, 4 for -4 or 1 for -1

        // Numbers at edge of array will produce bigger number because input array is sorted and we only
        // focus on numbers. In this case, A number at index 0 or index 4 will produce the biggest square
        // number.

        int left = 0;
        int right = nums.length-1;

        int[] ans = new int[nums.length];

        int i = nums.length -1;
        while(right>=left){
           if(Math.abs(nums[right]) > Math.abs(nums[left]) ){
                ans[i--] = nums[right] * nums[right];
                right --;
           }

           else{
              ans[i--] = nums[left] * nums[left];
              left ++;
           }
        }

            return ans;

    }
}