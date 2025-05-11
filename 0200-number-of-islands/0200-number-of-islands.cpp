class Solution {
public:

    void bfs(int row, int column, vector<vector<int>> &visited, vector<vector<char>>& grid ){
        visited[row][column] = 1;
        queue<pair<int,int>> q;

        int n = grid.size(); // row
        int m = grid[0].size(); // column

        q.push({row, column});

        int drow[] = {-1, 0, 1, 0}; // directions: up, right, down, left
        int dcol[] = {0, 1, 0, -1}; // directions: up, right, down, left

        while(!q.empty()){ 
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++){

                int nrow = currRow + drow[i];
                int ncol = currCol + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                   !visited[nrow][ncol] && grid[nrow][ncol] == '1') {
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }   
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(); // row
        int m = grid[0].size(); // column
        int count = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int row = 0; row < n; row++) {
            for(int column = 0; column < m; column++) {
                if(!visited[row][column] && grid[row][column] == '1') {
                    count++;
                    bfs(row, column, visited, grid);
                }
            } 
        }

        return count;
    }
};
