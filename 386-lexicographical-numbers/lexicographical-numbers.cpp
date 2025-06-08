class Solution {
public:

    void f(int i, vector<int>& ans, int limit)
    {
           if(i > limit)return;
            ans.push_back(i);
            f(i*10,ans,limit);
            if((i+1)%10 > i%10) f(i+1,ans,limit);
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        f(1,ans,n);
        return ans;
    }
};