class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {

        int n = nums.size();

        vector<int> leftSum,rightSum,ans;
        leftSum.push_back(0);
        
        int sum = 0;
        for(int i=0; i<n-1; i++){
            sum = sum+nums[i];
            leftSum.push_back(sum);
        }

        sum += nums[n-1];

        for(int i=0; i<n-1; i++){
            sum -= nums[i];
            rightSum.push_back(sum);
        }

        rightSum.push_back(0);

        for(int i=0; i<n; i++){
            ans.push_back(abs(leftSum[i]-rightSum[i]));
        }

        return ans;

    }
};