class Solution {
public:

    // int bfs(vector<vector<int>>& grid, vector<vector<int>> &visited, int row, int col){

    //     visited[row][col] = 2;
    //     queue<pair<int,int>> q;

    //     int n = grid.size();
    //     int m = grid[0].size();

    //     int time = -1 ;

    //     q.push({row,col});

    //     while(!q.empty()){
    //         time++;
    //         int u = q.front().first;
    //         int v = q.front().second;

    //         q.pop();

    //         int drow[] = {-1,0,1,0};
    //         int dcol[] = {0,1,0,-1};

    //         for(int i=0; i<4; i++){
                
    //             int nrow = u+drow[i];
    //             int ncol = v+dcol[i];

    //             if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol] == 1) {

    //                 visited[nrow][ncol] = 2;
    //                 q.push({nrow,ncol});

    //             }
    //         }
    //     }

    //     return time;

    // }

    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        queue<pair<int,int>> q;
        vector<vector<int>> visited(n, vector<int> (m,0));

        for(int i = 0; i< n; i++){
            for(int j=0; j< m; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    visited[i][j] = 2; 
                }
            }
        }

        int time = 0;

        while(!q.empty()){

            int sz = q.size(); // process current level only
            bool rotted = false;

            int drow[] = {-1,0,1,0}; // directions
            int dcol[] = {0,1,0,-1};

            for (int i = 0; i < sz; i++) {
        int u = q.front().first;
        int v = q.front().second;
        q.pop();

        for (int j = 0; j < 4; j++) {
            int nrow = u + drow[j];
            int ncol = v + dcol[j];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            visited[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
            q.push({nrow, ncol});
            visited[nrow][ncol] = 2;
            rotted = true;
        }
    }
}
        if (rotted) time++;
        }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 1 && visited[i][j] != 2){
                return -1;
            }
        }
    }

    return time;

    }
};