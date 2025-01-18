class Solution {
public:
    set<pair<int,int>> vis;
    int mxx;
    void bfs(vector<vector<int>>& a,int i, int j, int& ans){
        int n = a.size(), m = a[0].size();
        if(i >= n or i < 0 or j >= m or j < 0 or a[i][j] == -1 or a[i][j] == 0){
            return;
        }
        ++ans;
        mxx = max(mxx,ans);
        a[i][j] = -1;
        bfs(a,i+1,j,ans);
        bfs(a,i-1,j,ans);
        bfs(a,i,j+1,ans);
        bfs(a,i,j-1,ans);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 1){
                    int ans = 0;
                    bfs(grid,i,j,ans);
                }
            }
        }
        return mxx;
    }
};