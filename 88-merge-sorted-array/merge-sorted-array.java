class Solution {
    public void merge(int[] arr1, int m, int[] arr2, int n) {


        
        // as we know that all the arrays are sorted themselves, given in question itself

        /* Approach : Two Pointer
 We can start with two pointers i and j,
 initialized to m-1 and n-1, respectively.
  We will also have another pointer k initialized
   to m+n-1, which will be used to keep track of the
    position in nums1 where we will be placing the
     larger element. Then we can start iterating from 
     the end of the arrays i and j, and compare the
      elements at these positions. We will place the 
      larger element in nums1 at position k, and decrement 
      the corresponding pointer i or j accordingly. 
      We will continue doing this until we have iterated
       through all the elements in nums2. If there
        are still elements left in nums1, we don't need
         to do anything because they are already in their correct place. */          
        
        int i = m-1;
        int j = n-1;
        int k = m+n-1;

        while(j>=0){
            if(i>=0 && arr1[i] > arr2[j]){
                
                arr1[k--] = arr1[i--];
            }
            else{
                arr1[k--] = arr2[j--];
            }
        }
    
        // for(int i = m-1; i  m; ){
        //     for(int j = n-1; j < n; ){
        //         if(arr3[i] < arr2[j]){
        //             arr1[k++] = arr3[i++];
        //         }
        //         else if(arr3[i] > arr2[j]){
        //             arr1[k++] = arr2[j++];
        //         }
        //         else{ // arr3[i] == arr2[j]
        //             arr1[k++] = arr3[i++];
        //             arr1[k++] = arr2[j++];
        //         }
        //     }
        // }


    }
    
}