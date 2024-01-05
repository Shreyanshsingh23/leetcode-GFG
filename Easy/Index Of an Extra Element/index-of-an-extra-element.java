//{ Driver Code Starts
import java.util.*;
class ExtraElement {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] a = new int[n];
            int[] b = new int[n - 1];
            for (int i = 0; i < n; i++) a[i] = sc.nextInt();
            for (int i = 0; i < n - 1; i++) b[i] = sc.nextInt();
            Solution g = new Solution();
            System.out.println(g.findExtra(a, b, n));
        }
    }
}
// } Driver Code Ends


/*Complete the function below*/
class Solution {
    public int findExtra(int a[], int b[], int n) {
        // approach= by the sum of both the arrays we will find the missing number,once we found it,
        // we will set that as target element and by binary search we will find its index
        
        int sum1 = 0 , sum2 = 0;
        for(int i = 0; i < a.length ; i++){
            sum1 += a[i];
        }
         for(int i = 0; i < b.length ; i++){
            sum2 += b[i];
        }
        
        int target = sum1 - sum2 ;
        
        // now appling binary search 
        
        int start = 0 , end = a.length -1;
        
        while(start <= end){
            int mid = start + (end - start)/2;
            if(a[mid] == target){
                return mid;
            }
            else if(a[mid] > target){
                end = mid-1;
            }
            else{
                start = mid + 1;
            }
        }
        return -1;
    }
}