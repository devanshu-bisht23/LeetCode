class Solution {
public:

    int rec(int currM, int currN, vector<vector<int>>& grid, vector<vector<int>> &dp){

        if(currM == 0 && currN == 0){
            return grid[0][0];
        }

        if(currM < 0 || currN < 0){
            return 1e9;
        }

        if(dp[currM][currN] != -1){
            return dp[currM][currN];
        }

        int left = rec(currM, currN-1, grid, dp) + grid[currM][currN];
        int up = rec(currM-1, currN, grid, dp) + grid[currM][currN];
        
        return dp[currM][currN] = min(up,left);

    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int currM = m-1, currN = n-1;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return rec(currM, currN, grid, dp);
    }
};