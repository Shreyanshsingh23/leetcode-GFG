class Solution {
public:
void f(int open, int close,string &current ,vector<string>&result)
{
    if(open==0 && close==0)
    {
        result.push_back(current);
        return;
    }
    if(open>0)
    {
        current.push_back('(');
        f(open-1,close,current,result);
        current.pop_back();
    }
    if(close>0)
    {
        if(close>open)
        {
            current.push_back(')');
            f(open,close-1,current,result);
            current.pop_back();
        }
    }
}
    vector<string> generateParenthesis(int n) 
    {
        string current ;
        vector<string>result;
        f(n,n,current,result);
        return result;
    }
};