class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int l = 0;
        int r = nums.size() - 1;
        int res = INT_MAX;

        while(l<=r){
            int mid = l + (r-l)/2;

            if(nums[l] <= nums[mid]){
                res = min(res,nums[l]);
                l = mid+1;
            }else{ //nums[mid] <= nums[r]
                res = min(res,nums[mid]);
                r = mid - 1;
            }
        }
    return res;
    }
};