

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
#define ll long long

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<pi> a(n);
        for(int i = 0; i < n; ++i)
        {
            int x = nums1[i];
            a[x].first = i;
        }
        for(int i = 0; i < n; ++i)
        {
            int x = nums2[i];
            a[x].second = i;
        }

        sort(a.begin(),a.end());
        ll ans = 0;
        OrderedSet<pi> b,c;
        for(int i = 0;i < n; ++i)c.insert({a[i].second, i});
        for(int i = 0; i< n; ++i)
        {
            c.erase({a[i].second, i});
            int x = b.countElementsLessThanX({a[i].second,-1});
            int y = c.countElementsAtleastX({a[i].second,1e9});
            ans += ((ll)x)*(ll)y;
            b.insert({a[i].second,i});
        }
        return ans;
    }
};