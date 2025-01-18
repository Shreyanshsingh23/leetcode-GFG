class Solution {
public:
    void rec(vector<vector<int>>& a, int i, int j, int color, int org, set<pair<int,int>>& vis){
        int n = a.size(), m = a[0].size();
        if(i >= n or j >= m)return;
        if(a[i][j] == org)a[i][j] = color;
        vis.insert({i,j});
        if(i+1 < n and a[i+1][j] == org and !vis.count({i+1,j})) {rec(a,i+1,j,color,org,vis);
        vis.erase({i,j});
        }
        if(i-1 >= 0 and a[i-1][j] == org and !vis.count({i-1,j})){rec(a,i-1,j,color,org,vis);
        vis.erase({i,j});
        }
        if(j+1 < m and a[i][j+1] == org and !vis.count({i,j+1})){rec(a,i,j+1,color,org,vis);
        vis.erase({i,j});
        }
        if(j-1 >= 0 and a[i][j-1] == org and !vis.count({i,j-1})){rec(a,i,j-1,color,org,vis);
        vis.erase({i,j});
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        set<pair<int,int>> st;
        rec(image,sr,sc,color,image[sr][sc],st);
        return image;
    }
};