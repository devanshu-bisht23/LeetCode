class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));
        vector<vector<int>> res(n, vector<int>(m,0));

        queue<pair<int, pair<int,int>>> q;

        for(int i =0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){

                    visited[i][j] = 1;
                    // q.push({i,j,0}); 
                    q.push({i, {j, 0}}); 
                    
                }
            }
        }   

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty()){

            int u = q.front().first; // row
            int v = q.front().second.first; // col
            int w = q.front().second.second; // value 0,1,2...

            q.pop();

            res[u][v] = w;

            for(int i=0; i<4; i++){

                int nrow = u + drow[i];
                int ncol = v + dcol[i]; 

                if(nrow >= 0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol]){

                    visited[nrow][ncol] = 1;
                    q.push({nrow,{ncol, w+1}}); 

                }
            }
        }
    return res;
    }
};