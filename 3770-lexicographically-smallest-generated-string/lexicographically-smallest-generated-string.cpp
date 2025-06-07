bool vis[100000];

class Solution {
public:
    string generateString(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        // for(int i = 0; i < 100000; ++i)vis[i] = false;
        string ans(n+m-1,'@');
        cout << ans[0] << '\n';
        for(int i = 0;  i < n; ++i)
        {
            if(s1[i] == 'T')
            {
                for(int j = 0; j < m; ++j)
                {
                    if(ans[i+j] != '@' and ans[i+j] != s2[j])return "";
                    ans[i+j] =  s2[j];
                    vis[i+j] = true;
                }
            }
        }

        for(int i = 0; i < n+m; ++i)
        {
            if(ans[i] == '@')
            {
                ans[i] = 'a';
                vis[i] = false;
            }
        }

        for(int i = 0; i < n; ++i)
        {
            if(s1[i] == 'F')
            {
                if(equalInterval(ans,s2,i,m))
                {
                    bool free = true;
                    for(int j = m-1; j >= 0; --j)
                    {
                        if(vis[i+j] == false)
                        {
                            ans[i+j] = 'b';
                            // kyuki yahi vo position hai jo free bhi hai aur sabse last me bhi hai,
                            //aur 'b' isliye daal rhe kyuki already free thi mtlb pehle se 'a' rha hoga jo s2[i+b]
                            // ke barabar ho rha tha isliye 'b'
                            vis[i+j] = true;
                            free = false;
                            break;
                        }
                    }
                    if(free)return "";
                }
                else
                {
                    //agr interval equal nhi hai toh koi dikkat nhi hai kyuki already baaki me 'a' hi pada hai jo sabse chota 
                    // hai isliye hum kuch change nhi kar rhe
                }
            }
        }

        return ans;
    }

    bool equalInterval( string& s,  string& s2, int i, int m) {
        for (int j = 0; j < m; j++) {
            if (s[i + j] == 0 or s[i + j] != s2[j]) {
                return false;
            }
        }
        return true;
    }
};