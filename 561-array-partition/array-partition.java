class Solution {
    public int arrayPairSum(int[] nums) {
        int numberOfPairs = nums.length /2 ;

        int numberOfMax = numberOfPairs/2;
        int numberOfMin = numberOfPairs/2;

        Arrays.sort(nums);

        int i = 1;
        int j =nums.length-1;
        

        int sum = 0;
        while(i<= 2*numberOfMax){
            sum = sum + nums[i-1];
            sum = sum  +  nums[j-1];
             
            i+=2;
            j-=2;
        }

        if((numberOfPairs&1) == 1){   // if numbers of pairs are odd
            return sum + nums[i-1];
        }

        return sum;
    }
}