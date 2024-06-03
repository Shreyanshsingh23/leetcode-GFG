class Solution {
    public int heightChecker(int[] heights) {

        int[] expected = new int[heights.length];
        for(int j = 0; j < heights.length ;j++){
             expected[j] = heights[j];
        }
        bubbleSort(expected,expected.length-1,0);
         //now array expected is sorted in ascending order 

            int count = 0;
         for(int j = 0; j < heights.length; j++){
            if(expected[j] != heights[j]){
                count++;
            }
         }

         return count;
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