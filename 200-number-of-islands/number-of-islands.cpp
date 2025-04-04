class Solution {
public:
    void bfs(vector<vector<char>>& a, int i, int j){
        int n = a.size(), m = a[0].size();
        if(a[i][j] == 'x' or a[i][j] == '0')return;

        a[i][j] = 'x';
       if(i+1 < n) bfs(a,i+1,j); 
       if(i > 0) bfs(a,i-1,j); 
       if(j+1 < m) bfs(a,i,j+1); 
       if(j > 0) bfs(a,i,j-1); 
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