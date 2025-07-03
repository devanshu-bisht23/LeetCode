class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int res = INT_MAX;

        while(l<=r){

            int mid = l + (r-l)/2;

            if(nums[mid] < res){
                res = nums[mid];
            }
            
            if(nums[l]<=nums[mid]){

                if(nums[l] <= res && res < nums[r]){
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }

            }else{ 

                if(nums[mid] < res && res <= nums[r]){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }

            }

        }
        return res;
    }
};