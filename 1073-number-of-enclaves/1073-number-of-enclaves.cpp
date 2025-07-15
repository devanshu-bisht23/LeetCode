class Solution {
public:

    void dfs(vector<vector<int>>& grid, vector<vector<int>> &visited, int i, int j, int drow[], int dcol[], int n, int m){

        visited[i][j] = 1;

        for(int a=0; a<4; a++){

            int nrow = i + drow[a];
            int ncol = j + dcol[a]; 
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == 1 && !visited[nrow][ncol]){
                dfs(grid, visited, nrow, ncol, drow, dcol, n,m);
            }

        }

    }

    int numEnclaves(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m,0));

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        for(int i=0; i<m; i++){

            if(grid[0][i]==1 && !visited[0][i]){
                dfs(grid,visited,0,i,drow,dcol,n,m);
            }

            if(grid[n-1][i]==1 && !visited[n-1][i]){
                dfs(grid,visited,n-1,i,drow,dcol,n,m);
            }

        }

        for(int i=0; i<n; i++){
            if(grid[i][0]==1 && !visited[i][0]){ 
                dfs(grid,visited,i,0,drow,dcol,n,m);
            }

            if(grid[i][m-1]==1 && !visited[i][m-1]){
                dfs(grid,visited,i,m-1,drow,dcol,n,m);
            }
        }

        int res = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    res++;
                }
            }
        }

    return res;
    }
};