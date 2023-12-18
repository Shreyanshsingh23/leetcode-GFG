class Solution {
    public int maximumWealth(int[][] accounts) {
        int total = Integer.MIN_VALUE;
        
        int sum ; 
        for(int i = 0; i < accounts.length ; i ++){
            sum = 0;
            for(int j = 0; j < accounts[i].length ; j++){
              sum +=  accounts[i][j];
              if(sum > total){
                  total = sum;
              }
            }
        }
        return total;
    }
}