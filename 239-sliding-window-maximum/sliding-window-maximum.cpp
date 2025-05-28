
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
template <typename T>
class OrderedSet {
private:
    tree< T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> st;
public:
    int countElementsLessThanX(T x) {
        return st.order_of_key(x);
    }

    int countElementsAtleastX(T x) {
        return st.size() - countElementsLessThanX(x);
    }

    T getKthElement(int k) {
        return *st.find_by_order(k);
    }
    
    void insert(T x) {
        st.insert(x);
    }
    
    void erase(T x) {
        st.erase(x);
    }
};
#define pi pair<int,int>
#define pb push_back
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        deque<int> dq;
        for(int i = 0; i < k; ++i)
        {
            while(!dq.empty() and a[dq.back()] <= a[i])dq.pop_back();
            dq.pb(i);
        }
        int n = a.size();
        vector<int> ans;
        ans.pb(a[dq.front()]);

        for(int i = k; i < n; ++i)
        {
            if(!dq.empty() and dq.front() == i-k)dq.pop_front();
            while(!dq.empty() and a[dq.back()] <= a[i])dq.pop_back();
            dq.pb(i);
            ans.pb(a[dq.front()]);
        }

        return ans;
    }
};