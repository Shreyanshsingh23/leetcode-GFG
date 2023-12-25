class Solution {
    public int splitArray(int[] nums, int k) {
        return calculate(nums,k);
    }

     int calculate(int[] arr, int k){ 
  
 
  int start = 0;
  int end = 0;
  // for obtaining max.sum and max.element we will run a loop

  for(int n : arr){
    start = Math.max(start,n);
    end += n;

  }

  // now we have got the range for binary search 

  while(start < end){ 
  int mid = start + (end - start) / 2;
 
      int sum= 0;
     int pieces = 1; // yeh values yahin pe rahengi kyuki jab tak mid ki nayi valur=e nhi aa jati tab tak values nhi reset karni hain

  for(int n : arr){
  
   
     if(sum + n > mid){
        sum = n;
        pieces ++;
     }
        else{
            sum += n;
        
     }
    }

  
    if(pieces > k){
       
         start = mid + 1;
    }
    else{
        end = mid;
    }
  }

  return end; // start and end will be equal here
} 
   
}