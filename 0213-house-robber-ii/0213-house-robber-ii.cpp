class Solution {
public:

    int rec(vector<int>& nums, int i, vector<int> &dp){

        if(i == 0){
            return nums[i];
        }

        if(i<0){
            return 0;
        }

        if(dp[i] != -1){ 
            return dp[i];
        } 
 
        int pick = nums[i] + rec(nums,i-2,dp); 

        int notPick = 0 + rec(nums,i-1,dp);

        return dp[i] = max(pick,notPick);
 
    }

    int rob(vector<int>& nums) {
        
        if (nums.size() == 1) return nums[0];
        
        vector <int> temp1(nums.begin(), nums.end()-1);
        vector<int> temp2(nums.begin()+1,nums.end());

        vector<int> dp1(temp1.size(), -1);
        vector<int> dp2(temp2.size(), -1);

        return max(
            rec(temp1,temp1.size()-1,dp1) , rec(temp2,temp2.size()-1,dp2)
            );

    }
};