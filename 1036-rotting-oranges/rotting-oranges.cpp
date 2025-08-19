
class Solution {
public:
    int orangesRotting(vector<vector<int>>& a) {
        queue<vector<int>> q;
        int time = 0;
        for(int i = 0; i < a.size(); ++i){
            for(int j = 0; j < a[0].size(); ++j){
                if(a[i][j] == 2){
                    q.push(vector<int>{i,j,time});
                }
            }
        }

        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int i = top[0], j = top[1], curTime = top[2];
            if(i>0 and a[i-1][j] == 1){
                a[i-1][j] = 2;
                q.push(vector<int>{i-1,j,curTime+1});
                time = max(time, curTime+1);
            }
            if(i+1 < a.size() and a[i+1][j] == 1){
                a[i+1][j] = 2;
                q.push(vector<int>{i+1,j,curTime+1});
                time = max(time, curTime+1);
            }
            if(j>0 and a[i][j-1] == 1){
                a[i][j-1] = 2;
                q.push(vector<int>{i,j-1,curTime+1});
                time = max(time, curTime+1);
            }
            if(j+1 < a[0].size() and a[i][j+1] == 1){
                a[i][j+1] = 2;
                q.push(vector<int>{i,j+1,curTime+1});
                time = max(time, curTime+1);
            }
        }

        for(int i = 0; i < a.size(); ++i){
            for(int j = 0; j < a[0].size(); ++j){
                if(a[i][j] == 1){
                    return -1;
                }
            }
        }
        return time;


    }
};