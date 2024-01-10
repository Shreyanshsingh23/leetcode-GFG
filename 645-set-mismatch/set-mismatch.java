class Solution {
    public int[] findErrorNums(int[] arr) {
        cyclicSort (arr);

        // now the array is sorted
        // now I need to find the duplicate number
     for(int i = 0; i < arr.length;){
         if(i < arr.length - 1){
          if(arr[i] != i + 1){
              return new int[] {arr[i],i+1};
          }
          else{
              i++;
          }
     }
     else{
         return new int[] {arr[i],arr.length};
     }
    }
    return new int[] {-1};
}
static void cyclicSort(int[] arr){
        int i = 0; 
        while(i < arr.length){
            int correctIndex = arr[i]-1;
            if(arr[i] != arr[correctIndex]){
                int temp = arr[i];
                arr[i] = arr[correctIndex];
                arr[correctIndex] = temp;
            }
            else{
                i++;
            }
        }
}
}