class Solution {
public:
    int maximumSwap(int num) {
    string s = to_string(num);
    int maxInd = 0;
    int count = 0;
    while(true){
        char maxx = *max_element(s.begin()+count,s.end());
        if(s[count] == maxx){
            count ++;
        }
        else{
            for(int i = 0;i< s.size();i++){
                if(s[i] == maxx) maxInd = i;
            }

            swap(s[maxInd],s[count]);

            cout << maxx << endl;
            break;
        }

        if(count >= s.size()-1) break;
       
    }
        int ans = stoi(s);


        return ans;

    }
};