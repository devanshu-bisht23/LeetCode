class Solution {
public:

    void subsetSum(int idx, vector<int> &x, vector<int>& nums, vector<vector<int>>& ans){

        ans.push_back(x);

        for(int i=idx; i<nums.size(); i++){
            
            if(i!=idx && nums[i] == nums[i-1]) continue;
            
            x.push_back(nums[i]);
            subsetSum(i+1,x,nums,ans);
            x.pop_back();

        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> x;
        subsetSum(0,x,nums,ans);
        return ans;

    }
};