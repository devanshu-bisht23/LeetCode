class Solution {
public:

    int findMax(int i, int j, vector<int> &nums, vector<vector<int>> &dp){

        if(i>j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int maxc = INT_MIN;

        for(int k=i; k<=j; k++){

            int ans = nums[i-1] * nums[k] * nums[j+1] + findMax(i,k-1,nums,dp) + findMax(k+1,j,nums,dp);

            maxc = max(ans,maxc);

        }

    return dp[i][j] = maxc;

    }

    int maxCoins(vector<int>& nums) {

        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));

        return findMax(1,n,nums,dp);
    }
};