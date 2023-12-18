class Solution {
    public int findNumbers(int[] nums) {
        int ans = 0;
        for(int i = 0; i < nums.length ; i++){
            int a = nums[i];
            int x = 0;
            while(a != 0){
                a = a / 10;
                x ++;
            }
            if(x%2 == 0){
                ans ++;
            }
        }
        return ans;
    }
}