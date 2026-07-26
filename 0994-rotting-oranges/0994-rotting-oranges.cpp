class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size(); // rows
        int m = grid[0].size(); // number of colms in a row

        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(n,vector<int>(m,0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                if(grid[i][j] == 2){
                    visited[i][j] = 2;
                    q.push({{i,j},0});
                }

            }
        }

        int time = 0;
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};

        while(!q.empty()){

            int trow = q.front().first.first;
            int tcol = q.front().first.second;
            int t = q.front().second;
            q.pop();

            time = max(time,t);

            for(int i=0; i<4; i++){

                int crow = trow + drow[i];
                int ccol = tcol + dcol[i];

                if(crow>=0 && crow<n && ccol>=0 && ccol<m && grid[crow][ccol] == 1 && visited[crow][ccol] != 2){

                    q.push({{crow,ccol},t+1});
                    visited[crow][ccol] = 2;

                }

            }

        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(visited[i][j] != 2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }




        return time;



    }
};