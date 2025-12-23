class Solution {
public:

    int rec(int currM, int currN, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp ){

        if(currM == 0 && currN == 0){
            return 1;
        }

        if(currM < 0 || currN < 0 || obstacleGrid[currM][currN] == 1){
            return 0;
        }

        if(dp[currM][currN] != -1){
            return dp[currM][currN];
        }

        int left = rec(currM, currN-1, obstacleGrid, dp);
        int up = rec(currM-1, currN, obstacleGrid, dp);

        return dp[currM][currN] = left+up;

    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1){
            return 0;
        }
        int currM = m-1, currN = n-1;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return rec(currM, currN, obstacleGrid, dp);

    }


};