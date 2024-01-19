class Solution {
    public int minFallingPathSum(int[][] matrix) {
    
    // I applied Greedy Algorithm, and it is giving wrong answers in most testcases because it finds 
    // efficient solution of sub problems but i need to apply dp because it finds overall most efficient solution

//     static int calculate (int[][] arr, int row, int col, int sum){
//         int value = Integer.MAX_VALUE;
        

//         // base condition
//         if(row == arr.length){
//             return sum;
//         }


//         if (row == 0){ 
//         for(int i = 0; i < arr[row].length;i++){
//             if(arr[row][i] < value){
//                 value = arr[row][i];
//                  col = i;
//                 }
//            }

           
         
//          sum += value;
//         return calculate(arr,1,col,sum);
//         }

//         // for(int i = col-1; i <= col+1 ;i++){
//         //     if(i>=0 && i < arr[row].length && arr[row][i] < value){
//         //       value = arr[row][i];
//         //        col = i;
//         //     }
//         // }

//         for (int i = Math.max(0, col - 1); i <= Math.min(col + 1, arr[row].length - 1); i++) {
         
//          if (arr[row][i] < value) {
//         value = arr[row][i];
//         col = i;
//     }
// }

         
//          sum += value;
//         return calculate(arr,row+1,col,sum);

//     }
// }



        int rows = matrix.length;
        int cols = matrix[0].length;

        // Create a DP array to store minimum falling path sum
        int[][] dp = new int[rows][cols];

        // Base case: Copy the first row of the matrix to the DP array
        for (int i = 0; i < cols; i++) {
            dp[0][i] = matrix[0][i];
        }

        // Iterate through the remaining rows and update the DP array
        for (int i = 1; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Calculate the minimum falling path sum for the current cell
                dp[i][j] = matrix[i][j] + Math.min(
                        dp[i - 1][j],
                        Math.min(dp[i - 1][Math.max(0, j - 1)], dp[i - 1][Math.min(cols - 1, j + 1)])
                );
            }
        }

        // Find the minimum value in the last row of the DP array
        int result = Integer.MAX_VALUE;
        for (int i = 0; i < cols; i++) {
            result = Math.min(result, dp[rows - 1][i]);
        }

        return result;
    }
}
