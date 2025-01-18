# define pb push_back
class Solution {
public:
    int ans = 0;
    void rec(vector<vector<int>>& a,int i , int j, int& ans){
        int n = a.size(), m = a[0].size();
        if(i < 0 or i >= a.size() or j < 0 or j >= a[0].size() or a[i][j] == 0){
            ++ans;
            return;
        }
        if(a[i][j] == -1){
            return;
        }
        a[i][j] = -1;
         rec(a,i+1,j,ans);
         rec(a,i-1,j,ans);
         rec(a,i,j+1,ans);
         rec(a,i,j-1,ans);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int x,y;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 1){
                    x = i;y = j;
                    break;
                }
            }
        }
        rec(grid,x,y,ans);
        return ans;
    }
};