class Solution {
    public int countTestedDevices(int[] batteryPercentages) {
        int count = 0;
        for(int i = 0; i <  batteryPercentages.length - 1; i++){
            if( batteryPercentages[i]==0){
                continue;
            }
            else if( batteryPercentages[i] > 0){
                count ++;
                
                for(int j = i+1; j <  batteryPercentages.length; j ++){
                    if( batteryPercentages[j] > 0){
                         batteryPercentages[j] -= 1;
                    }
                }
                
                }
            }
                    if( batteryPercentages[ batteryPercentages.length - 1] > 0){
                    count ++;

        }
        return count;
    }
}