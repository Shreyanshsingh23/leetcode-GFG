class Solution {
    public boolean satisfiesConditions(int[][] grid) {
        int m = grid.length  ;
        int n = grid[0].length ;

        int i = 0;
        int j = 0;

        return check(grid,m,n,m-1,0);
        

    }

    static boolean check(int[][] grid ,int m,int n,int i,int j){
        //base condition

        if( i == -1 ){
            return true;
        }

        if((i == 0) && (j < n-1)){
            if(grid[i][j] != grid[i][j+1]){
                return check(grid,m,n,i,j+1);
            }
            else{
                return false;
            }
        }

        else if((j== n-1 ) && (i>0)){
            if(grid[i][j] == grid[i-1][j]){
                return check(grid,m,n,i-1,0);
            }
            else{
                return false;
            }
        }

        else if((i>=1) && (j < n-1)){ 
         if((grid[i][j] == grid[i-1][j]) && (grid[i][j] != grid[i][j+1])){
            return check(grid,m,n,i,j+1);
        }
        else{
            return false;
        }
        
      }

      return check(grid,m,n,i-1,0);
    }
}