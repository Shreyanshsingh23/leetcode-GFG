class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)return 0;
        set<char> st;
        int ans = 1;
        int n = s.size();
        int i = 0;
        int j = 0;
        while(i < n)
        {
            while(j < i and st.count(s[i]))
            {
                st.erase(s[j]);
                ++j;
            }
            st.insert(s[i]);
            ans = max(ans, i-j+1);
            ++i;
            cout << i << ' ' << j << endl;
        }

        return ans;
    }
};