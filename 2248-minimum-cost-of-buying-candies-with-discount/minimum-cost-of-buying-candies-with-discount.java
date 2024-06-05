class Solution {
    public int minimumCost(int[] cost) {
        Arrays.sort(cost);

        int sum =0; 

        int i = cost.length -1;
      
      while(i>=0){
        sum += cost[i];
       if(i>0) {sum += cost[i-1];
}
        i -= 3;
      }
        return sum;
    }
}