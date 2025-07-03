class Solution {
public:

    int ub(vector<int>& nums, int l, int r, int target){
        int n = r + 1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid]>target){
                n = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return n;
    }

    int lb(vector<int>& nums, int l, int r, int target){
        int n = r + 1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid]>=target){
                n = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return n;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        
        int l = 0, r = nums.size() - 1;
        vector<int> res;
        int n = lb(nums, l, r, target);
        if(n == nums.size() || nums[n] != target){
            return {-1, -1};
        }
        int m = ub(nums, l, r, target) - 1;
        return {n, m};
        
    }
};