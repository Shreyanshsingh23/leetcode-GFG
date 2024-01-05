//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            String[] str = br.readLine().trim().split(" ");
            int[] array = new int[n - 1];
            for (int i = 0; i < n - 1; i++) {
                array[i] = Integer.parseInt(str[i]);
            }
            Solution sln = new Solution();
            System.out.println(sln.missingNumber(array, n));
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    int missingNumber(int array[], int n) {
//       sort(array);
//       for(int i = 0; i < array.length  ; i++){
//           if(array[i] != i+1){
//               return i+1;
//           }
//       }
//       return array.length + 1;

  // the most easiest way now 
  // calculate the sum by formula 
  // int sum = (n*(n+1))/2;
  //then calculate the sum of all the numbers of array
  // then substract by previous sum, the difference is the answer
   
        int sum = (n*(n+1))/2;
        
        int sumofarray = 0;
        for(int i = 0; i < array.length ; i++){
            sumofarray += array[i];
            
        }
        
        return sum - sumofarray;
  
    }
    
//     static void sort(int [] arr){
    
//   for(int i = 0; i < arr.length - 1;i++){
//       for(int j = i+1; j > 0 ; j--){
//           if(arr[j] < arr[j-1]){
//               swap(arr,j,j-1);
//           }
//           else{
//               break;
//       }
//   }
//   }
//     }
     
//      static void swap(int[] arr, int first, int second){
//          int temp = arr[first];
//          arr[first] = arr[second];
//          arr[second] = temp;
//     }
     }
