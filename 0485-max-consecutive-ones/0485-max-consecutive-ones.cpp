class Solution {
public:

    bool isValid(vector<int>& nums, int mid){

        int check = 0;

        for(int i = 0; i<nums.size(); i++){

            if(nums[i] == 1){
                check++;
            }else{
                check = 0;
            }
            if(check == mid){
                return true;
            }

        }
        return false;

    }

    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int l = 1, r = nums.size();
        int res;

        while(l<=r){

            int mid = l+(r-l)/2;

            if(isValid(nums, mid)){
                res = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }

        }

        return res;

    }
};