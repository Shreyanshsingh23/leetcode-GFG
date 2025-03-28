#define pb push_back
class Solution {
public:
    int f(int node, int steps, vector<bool>& hasApple, vector<vector<int>>& a,
          int prev) {
        int ans = 0;

        for (auto e : a[node]) {
            if (e != prev) {
                ans += f(e, steps + 1, hasApple, a, node);
            }
        }
        cout << "node,ans: " << node << ' ' << ans << '\n';
        if(node == 0)return ans;
        if((hasApple[node] == 0 and ans > 0 and node != 0) or hasApple[node] == 1)ans += 2;
        return ans;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> a(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            a[u].pb(v);
            a[v].pb(u);
        }

        return f(0, 0, hasApple, a, -1);
    }
};