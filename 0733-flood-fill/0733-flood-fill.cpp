class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> visited(n, vector(m,0));

        queue<pair<int,int>> q;

        q.push({sr,sc});
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        int initialColor = image[sr][sc];
        
        visited[sr][sc] = 1;
        image[sr][sc] = color;

        while(!q.empty()){
            
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){

                int nrow = r+drow[i];
                int ncol = c+dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol] == initialColor && visited[nrow][ncol] == 0){
                    visited[nrow][ncol] = 1;
                    image[nrow][ncol] = color;
                    q.push({nrow,ncol});
                }

            }


        }

        return image;

    }
};