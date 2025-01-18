# define pb push_back
class Solution {
public:

    vector<int> ans;
    set<pair<int,int>> st;
    void rec(vector<vector<int>>& a,int i , int j){
        int n = a.size(), m = a[0].size();
        if(i < 0 or i >= a.size() or j < 0 or j >= a[0].size()){
            ans.pb(1);
            return;
        }
        if(a[i][j] == 0){
            ans.pb(1);
            return;
        }
        st.insert({i,j});
        if(!st.count({i+1,j})) rec(a,i+1,j);
        if(!st.count({i-1,j})) rec(a,i-1,j);
        if(!st.count({i,j+1})) rec(a,i,j+1);
        if(!st.count({i,j-1})) rec(a,i,j-1);
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
        rec(grid,x,y);
        return ans.size();
    }
};