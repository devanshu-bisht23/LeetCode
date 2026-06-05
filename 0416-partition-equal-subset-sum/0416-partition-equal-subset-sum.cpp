class Solution {
public:

    bool rec(vector<int>& nums,int i, int target, vector<vector<int>> &dp){

        if(i==0) return (nums[0] == target);
        if(target == 0) return true;

        if(dp[i][target] != -1) return dp[i][target]; 

        bool notTake = rec(nums,i-1, target, dp);
        bool take = false;
        
        if(nums[i]<target)
        take = rec(nums, i-1, target-nums[i], dp);

        return dp[i][target] = take||notTake;

    }

    bool canPartition(vector<int>& nums) {
        

        int sum = accumulate(nums.begin(), nums.end(),0);

        if(sum%2 != 0) return false; 

        vector<vector<int>> dp(nums.size()+1, vector<int>((sum/2)+1, -1));

        return rec(nums, nums.size()-1, sum/2, dp);
 
    }
};