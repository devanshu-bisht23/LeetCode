class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        if(n==1) return true;
        for(int i =0; i<2*n; i++){
            if(nums[i%n] <= nums[(i+1) % n]){
                count +=1;
            }else{
                count = 1;
            }

            if(count == n){
                return true;
            }
        }
       return false;
    }
};
