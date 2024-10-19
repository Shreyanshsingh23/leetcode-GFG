class Solution {
public:
 string revInv(string s)
    { for(int i=0;i<s.size();i++){
        s[i]=='1'?s[i]='0':s[i]='1';
    }
    return s;

    } 
        
    char findKthBit(int n, int k) {
        string s = "0";
        for(int i = 0; i < n; i++){
            string inv = revInv(s);
            reverse(inv.begin(),inv.end());
            s += "1" + inv;

        }
        return s[k-1];
    }
};