class Solution {
    public int majorityElement(int[] arr) {
        int n = arr.length /2;
        int ans = majority(arr);
        
        return ans;
    }
    
    static int majority(int[]  arr){

        int candidate = arr[0];
        int count = 1;

        for (int i = 1; i < arr.length; i++) {
            if (count == 0) {
                candidate = arr[i];
                count = 1;
            } else if (candidate == arr[i]) {
                count++;
            } else {
                count--;
            }
        }

        // At this point, candidate is a potential majority element
        // You may want to add additional checks to verify it occurs more than n/2 times

        
        return candidate;
    }

}



    
