class Solution {
    public int findDuplicate(int[] arr) {
        for(int i = 0; i < arr.length ;) {
        int correctIndex = arr[i]-1;
        if(arr[i] != i+1){
            if(arr[i] != arr[correctIndex]){
                int temp = arr[i];
            arr[i] = arr[correctIndex];
            arr[correctIndex] = temp;
            }
            else{
                return (arr[i]); 
            }
        }
        else{
            i++;
        }
    }
    return -1;
    
}
}