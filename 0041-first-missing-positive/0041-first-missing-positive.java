class Solution {
    public int firstMissingPositive(int[] arr) {
       int i = 0;
          
         while(i < arr.length){
             int correctIndex = arr[i]-1;
             if(arr[i] > 0 && arr[i] < arr.length && arr[i] != arr[correctIndex]){    // we will ignore negatives and sort all the positive elements and used cyclic sort because all positive numbers will be continous i.e. in order of 1 to N
             
                 int temp = arr[i];
                 arr[i] = arr[correctIndex];
                 arr[correctIndex] = temp;
             }
             else{
                 i++;
             }
    }   

     // now the array will be sorted i.e. all positve elements are sorted
     // example: [1,2,3,-2,5,6] 
     // now we will start checking from 0th index and arr[0] should be equal to 1 and next should be 2 and so on
     // the index on which the element is not equal to index+1 , will return the answer index+1

        for(int j = 0; j < arr.length; j++){
            if(arr[j] != j+1){
                return j+1;
            }
        }

        return arr.length + 1;
   }
}