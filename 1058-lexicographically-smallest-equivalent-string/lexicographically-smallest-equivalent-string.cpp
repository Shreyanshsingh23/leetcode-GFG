struct DSU{
    vector<int> parent;
    vector<int> size;

    DSU(int n)
    {
        parent.resize(n);
        size.resize(n);

        for(int i = 0; i < n; ++i)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int getLeader(int node)
    {
        if(parent[node] == node)return node;

        return parent[node] = getLeader(parent[node]);
    }

    void merge(int x, int y)
    {
        x = getLeader(x);
        y = getLeader(y);

        if(x == y)return;

        if(y < x){
            parent[x] = y;
            size[y] += size[x];
        }else{
            parent[y] = x;
            size[x] += size[y];
        }
    }

};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        DSU dsu(26);
        for(int i = 0; i < n; ++i)
        {
            if(s1[i] == s2[i])continue;
            dsu.merge(s1[i]-'a', s2[i]-'a');
        }

        for(auto& e: baseStr){
            e = dsu.getLeader(e-'a')+'a';
        }
        return baseStr;
    }
};