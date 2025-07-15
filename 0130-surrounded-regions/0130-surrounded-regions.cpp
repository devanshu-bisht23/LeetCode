class Solution {
public:

    void dfs(vector<vector<char>>& board, vector<vector<int>> &visited, int i, int j, int drow[], int dcol[],
    int n, int m ){ 

        visited[i][j] = 1;

        for(int a=0; a<4; a++){

            int nrow = i+drow[a];
            int ncol = j+dcol[a];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol] == 'O' && !visited[nrow][ncol]){
                dfs(board, visited, nrow,ncol, drow, dcol,n,m);
            }


        }

    }

    void solve(vector<vector<char>>& board) {
        
        int n = board.size();
        int m = board[0].size();

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        vector<vector<int>> visited(n, vector<int>(m,0));

        for(int i=0; i<m; i++){
            if(board[0][i] == 'O'){
                dfs(board, visited, 0,i,drow,dcol,n,m);
            }

            if(board[n-1][i] == 'O'){
                dfs(board, visited, n-1,i,drow,dcol,n,m);
            }
        }

        for(int i=0; i<n; i++){
            if(board[i][0] == 'O'){
                dfs(board, visited,i ,0,drow,dcol,n,m);
            }

            if(board[i][m-1] == 'O'){
                dfs(board, visited, i,m-1,drow,dcol,n,m);
            }
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] == 'O' && !visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }

    }
};