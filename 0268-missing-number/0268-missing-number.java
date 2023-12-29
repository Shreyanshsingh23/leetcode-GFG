class Solution {
    public int missingNumber(int[] arr) {
        
    int n = arr.length;
    
    int i = 0;

    while(i<n){
          
        int correctIndex= arr[i];
        
        if(arr[i] < arr.length && arr[i] != arr[correctIndex]){
              swap(arr,i,correctIndex);
        }
        else{
          i++;
        }
    }

        // finding missing number in the array 
        
        
        for (int index = 0; index < arr.length; index++) {
          
        
        
             
            if(arr[index] != index) {
                return index;
            }
        }
    
        return n;
    
  }

  static void swap (int [] arr, int first, int second){
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second]  = temp;
  
  }

    }
