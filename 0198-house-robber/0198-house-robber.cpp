class Solution {
public:

    int func(int ind, int choice, vector<int> &nums, vector<vector<int>> &dp){

        if(ind == 0){
            if(choice == 0) return nums[ind];
            return 0;
        }

        if(dp[ind][choice] != -1) return dp[ind][choice];

        int notPick = func(ind-1,0,nums,dp) + 0;
        int pick = 0;

        if(choice != 1) pick = func(ind-1,1,nums,dp) + nums[ind];

        return dp[ind][choice] = max(pick,notPick);

    }

    int rob(vector<int>& nums) {
        int n = nums.size()-1;
        vector<vector<int>> dp(n+1, vector<int>(2,-1));
        return func(n,0, nums, dp); // 0 means nth picked
    }
};