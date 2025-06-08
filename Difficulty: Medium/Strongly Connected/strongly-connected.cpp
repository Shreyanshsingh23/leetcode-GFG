//Position this line where user code will be pasted.
class Solution {
  public:
  
    void dfs(int node, vector<vector<int>> &adj, vector<bool>& vis)
    {
        vis[node] = true;
        for(auto e : adj[node])
        {
            if(!vis[e])dfs(e,adj,vis);
        }
    }
    
    void findOrder(int node, vector<vector<int>> &adj, vector<bool>& vis, vector<int>& order)
    {
        vis[node] = true;
        for(auto e : adj[node])
        {
            if(!vis[e])findOrder(e,adj,vis, order);
        }
        order.push_back(node);
    }
    
    
  
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<vector<int>> rev(n);
        for(int i = 0; i < n; ++i)
        {
            for(auto& e: adj[i])
            {
                rev[e].push_back(i);
            }
        }
        
        vector<bool> vis(n, false);
        vector<int> order;
        
        for(int i = 0; i < n; ++i)
        {
            if(!vis[i])
            {
                findOrder(i,adj,vis,order);
            }
        }
        
        for(int i = 0; i < n; ++i)vis[i] = false;
        
        int cnt = 0;
        for(int i = n-1; i >= 0; --i)
        {
            int node = order[i];
            if(!vis[node])
            {
                cnt++;
                dfs(node, rev, vis);
            }
        }
        
        return cnt;
        
    }
};