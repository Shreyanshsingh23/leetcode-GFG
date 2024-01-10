class Solution {
    public List<Integer> findDisappearedNumbers(int[] arr) {
     //firstly we will sort the array
     // and will use cyclic sort because numbers are in the range  1 to n
     cyclicSort(arr);
     // now the arrray will be sorted
     // now I need to find the missing number
      ArrayList <Integer> list = new ArrayList<>();
        for(int i = 0; i < arr.length; i++){
            if(arr[i] != i+1){
                list.add(i+1);
            }
        }
        return list;  
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