class Solution {
public:

    int f(int ind, int sum, vector<int>& nums, int target) {

        if(ind == nums.size())
            return (sum == target);

        int plus = f(ind + 1, sum + nums[ind], nums, target);

        int minus = f(ind + 1, sum - nums[ind], nums, target);

        return plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        return f(0,0,nums,target);

    }

};