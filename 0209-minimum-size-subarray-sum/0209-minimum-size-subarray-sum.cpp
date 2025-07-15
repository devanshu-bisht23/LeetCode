class Solution {
public:

    int isAns(vector<int> &nums, int target, int mid) {
    int sum = 0;

    for (int i = 0; i < mid; i++) {
        sum += nums[i];
    }

    if (sum >= target) return 1;

    for (int i = mid; i < nums.size(); i++) {
        sum += nums[i] - nums[i - mid];
        if (sum >= target) return 1;
    }

    return 0;
}

    int minSubArrayLen(int target, vector<int>& nums) {
        
        int l = 0, r = nums.size();
        int res = 0;

        while(l<=r){

            int mid = l + (r-l)/2;

            if(isAns(nums, target, mid)){
                res = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }

        }

        return res;

    }
};