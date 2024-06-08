class Solution {
    public String triangleType(int[] nums) {
        boolean bool = checkValidity(nums);

        int a = nums[0];
        int b = nums[1];
        int c = nums[2];

        if(bool){
            if((a==b) && (b==c)){
                return "equilateral";
            }
            else if((a==b) || (b==c)  || (a==c)){
                     return "isosceles";
            }
            else{
                return "scalene";
            }
        }
        else{
            return "none";
        }


           
    }

    static boolean checkValidity(int [] nums){
    

        int a = nums[0];
        int b = nums[1];
        int c = nums[2];

        // check condition of triangle
           // condition should be strictly applied on all three sets
           // sum of two sides should be greater than three sets
           
        if (a + b <= c || a + c <= b || b + c <= a)   
            return false; 
        else
            return true; 
    } 
    
}