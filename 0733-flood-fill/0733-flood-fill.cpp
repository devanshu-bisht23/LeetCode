class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        
        int n = image.size();
        int m = image[0].size();

        int originalColor = image[sr][sc];

        if (originalColor == color) {
            return image;
        } 

        queue<pair<int,int>> q; 

        q.push({sr,sc});
        
        image[sr][sc] = color;
        

        while(!q.empty()){
            int u = q.front().first;
            int v = q.front().second;

            q.pop();

            int drow[] = {-1,0,1,0};
            int dcol[] = {0,1,0,-1};

            for(int i=0; i<4; i++){
                int nrow = u + drow[i];
                int ncol = v + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol] == originalColor){ 
                    image[nrow][ncol] = color;
                    q.push({nrow,ncol});
                }
                
            }
        }

        return image;

    }
};