


class Solution {
public:


    long long carsRequired = 0;
    int s = 0;
    vector<vector<int>> adj;

    //dfs(cur,root) -> returns the number of people exist from leaf till cur node
    int dfs(int cur, int prev)
    {
        int ans = 1;
        for(auto e : adj[cur]){
            if(e != prev){
                ans +=  dfs(e,cur);
            }
        }

        if(cur != 0){
            carsRequired += (ans+s-1)/s;
        }

        return ans;
    }



    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        
        int n = roads.size();
        adj.resize(n+1);
        s = seats;
        for(auto& e:roads){
            int x = e[0], y = e[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        dfs(0,0);
        return carsRequired;
    }
};