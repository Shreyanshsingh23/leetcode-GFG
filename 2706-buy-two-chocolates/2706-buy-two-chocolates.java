class Solution {
    public int buyChoco(int[] prices, int money) {
        int sum = 0;
        int total = money;
        boolean bool = false;
        for(int i = 0 ; i < prices.length ; i ++){
            for(int j = 0 ; j < prices.length ; j++){
                if(i == j){
                    continue;
                }
                sum = prices[i] + prices[j];
                
                if(sum <= total){
                    total = sum;
                    bool = true;
                }
            }
        }
        if(bool != true){
            return money;
        }
        else{
            return money - total;
        }
        
    }
}