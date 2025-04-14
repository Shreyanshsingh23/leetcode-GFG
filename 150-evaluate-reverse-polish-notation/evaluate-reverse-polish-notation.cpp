class Solution {
public:
    int evalRPN(vector<string>& a) {
        stack<int> st;
    for(auto e: a)
    {
        if(e == "+")
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(a+b);
        }
        else if(e == "-")
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b-a);
        }
        else if(e == "*")
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(a*b);
        }
        else if(e == "/")
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b/a);
        }
        else st.push(stoi(e));
    }
    return st.top();
    }
};