class Solution {
public:

    bool isPossible(string& s)
    {
        set<char> st  (s.begin(),s.end());
        return st.size() == s.size();
    }

    int f(vector<string>& a, vector<int>& taken , int i)
    {
        int n = a.size();

        if(i == n){
            return 0;
        }

        //transitions
        //not take
        int ans = f(a,taken,i+1);

        //try to take
        bool canTake = true;
        for(auto e : a[i]){
            if(taken[e- 'a']){
                canTake = false;
                break;
            }
        }

        if(canTake and isPossible(a[i]))
        {
            for(auto e : a[i]){
            taken[e- 'a'] = true;
            }
            ans = max(ans,(int) a[i].size() + f(a,taken,i+1));
            for(auto e : a[i]){
            taken[e- 'a'] = false;
            }
        }

        return ans;
        
        }
    

    int maxLength(vector<string>& arr) {
        vector<int> taken(26,0);
        return f(arr,taken,0);

    }
};