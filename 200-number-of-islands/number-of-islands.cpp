class Solution {
public:
    void bfs(vector<vector<char>>& a, int i, int j){
        int n = a.size(), m = a[0].size();
        if(i >= n or i < 0 or j >= m or j < 0 or a[i][j] == 'x' or a[i][j] == '0')return;

        a[i][j] = 'x';
        bfs(a,i+1,j); 
        bfs(a,i-1,j); 
        bfs(a,i,j+1); 
        bfs(a,i,j-1); 
    }
    int numIslands(vector<vector<char>>& a) {
        int cnt = 0;
        for(int i = 0; i < a.size(); ++i){
            for(int j = 0; j < a[0].size(); ++j){
                if(a[i][j] == '1'){
                    ++cnt;
                    bfs(a,i,j);
                }
            }
        }

        return cnt;
    }
};