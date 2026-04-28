class Solution {
public:

    int findMin(int i, int j, vector<int> &cuts, vector<vector<int>> &dp){

        if(i>j) return 0; // no cuts remaining

        if (dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;

        for(int k = i; k<=j; k++){
            
            int cost = (cuts[j+1] - cuts[i-1]) + findMin(i,k-1,cuts,dp) + findMin(k+1,j,cuts,dp);

            mini = min(mini,cost);

        }

        return dp[i][j] = mini;

    }

    int minCost(int n, vector<int>& cuts) {
        
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());

        vector<vector<int>> dp(cuts.size()-1,vector<int>(cuts.size()-1,-1));

        int i = 1, j=cuts.size()-2;
        return findMin(i,j,cuts,dp);
        

    }
};