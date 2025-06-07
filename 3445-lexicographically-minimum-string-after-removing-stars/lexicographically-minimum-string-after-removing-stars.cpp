class Solution {
public:
    string clearStars(string s) {
        if(count(s.begin(), s.end(), '*') == 0)return s;
        set<int> st[26]; // will store the indicies of the character 
        int n = s.size();
        multiset<char> mst;
        for(int i = 0; i < n; ++i)
        {
            
             if(s[i] == '*')
             {
                char target = *mst.begin();
                mst.erase(mst.begin());
                s[*st[target - 'a'].rbegin()] = '*';
                st[target - 'a'].erase(*st[target - 'a'].rbegin());
             }
             else{ mst.insert(s[i]); st[s[i]-'a'].insert(i);}
        }

        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};