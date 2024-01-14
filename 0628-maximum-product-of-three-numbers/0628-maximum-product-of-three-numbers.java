class Solution {
    public int maximumProduct(int[] nums) {
        sort(nums);
        // now array is sorted
        // so last three numbers of array will be maximum
        return product(nums);
    }
    
    static void sort(int[] arr){
        int n = arr.length;
        
        for(int i = 0 ; i < n -1; i++){

            for(int j = i+1 ; j >0 ; j--){
                if(arr[j] < arr[j-1]){
                    swap(arr,j-1,j);
                }
                else{
                    break;
                     }
            }
            
        
        }
    }
    static void swap(int[] arr, int f , int s){

        int temp = arr[f];
        arr[f]= arr[s];
        arr[s]= temp;
    }
    
    static int product(int[] arr){

        int n = arr.length;
        // product1 is the product of three biggest positive numbers
        int product1 = arr[n-1] * arr[n-2] * arr[n-3] ;
        
        int product2 = arr[0] * arr[1] * arr[n-1];
        
        
        return Math.max(product1,product2);
    }
}