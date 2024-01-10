class Solution {
    public int findDuplicate(int[] arr) {
        cyclicSort(arr);
        int ans = 0;
        for(int i = 0; i < arr.length ; i++){
            if(arr[i] != i+1){
                ans = arr[i];
            }
        }
        return ans;
        
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