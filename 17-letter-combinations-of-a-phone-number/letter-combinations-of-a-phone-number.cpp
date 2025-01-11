class Solution {
public:
    map<char,string> mp;
    vector<string> rec(string s){
      if(s.size() == 0){
        vector<string> ans;
        return ans;
      }

      string curr = mp[s[0]];
      string rem = s.substr(1);
      vector<string> ans = rec(rem);
      if(ans.size() == 0)ans.push_back("");
      vector<string> temp;
      for(int i = 0; i < curr.size(); ++i){
        for(auto e :  ans){
            temp.push_back(curr[i]+e);
        }   
      }

      return temp;

    }
    vector<string> letterCombinations(string s) {
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "prqs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";


        return rec(s);

    }

};