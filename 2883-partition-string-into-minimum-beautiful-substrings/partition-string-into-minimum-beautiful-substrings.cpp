class Solution {
public:
    vector<string> a;
    int f(string& s, int i)
    {   
        int n = s.size();
        if(i == n)
        {
            for(auto& e: a)
            {
                if(e[0] == '0')return 1e9;
                long long  val = 0;
                int cnt = 0;
                for(int j = e.size() - 1; j >= 0; j--){
                    int digit = e[j] - '0';
                    if(digit == 1){
                         val += ((e[j] - '0') * (1 << cnt));
                    }
                    cnt++;
                }
                while(val >= 5){
                    if(val%5 != 0)return 1e9;
                    val /= 5;
                }
                if(val != 1)return 1e9;
            }
            
            return a.size();
        }
        int ans = 1e9;
        if(a.size()){
            a.back() += s[i];
            ans = min(ans,f(s,i+1));
            a.back().pop_back();
        }

        string ns = s.substr(i,1);
        a.push_back(ns);
        ans = min(ans,f(s,i+1));
        a.pop_back();

        return ans;
    }

    int minimumBeautifulSubstrings(string s) {
        int ans = f(s,0);
        if(ans == 1e9)return -1;
        return ans;
    }
};