class Solution {
public:
    int backtrack(string&s , int start, set<string>& seen){
        if(start == s.size()){
            return 0;
        }
        int maxCnt = 0;
        for(int end = start+1; end <= s.size(); ++end){
            string subs = s.substr(start,end-start);
            if(seen.find(subs) == seen.end()){
                seen.insert(subs);

                maxCnt = max(maxCnt,1+backtrack(s,end,seen));
                seen.erase(subs);
            }
        }

        return maxCnt;
    }


    int maxUniqueSplit(string s) {
        set<string> seen;
        return backtrack(s,0,seen);
    }
    
};