class Solution {
    public List<Integer> findDuplicates(int[] arr) {

        ArrayList <Integer> list = new ArrayList <>();
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
    // now the array is sorted
    // now we will find the duplicate elements

    for(int j = 0; j < arr.length;  j++){
         if(arr[j] != j+1){
                list.add(arr[j]);
           }
    }

    return list;
}
}