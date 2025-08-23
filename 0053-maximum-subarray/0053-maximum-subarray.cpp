class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum = 0, res=INT_MIN;

        for(int i=0; i<nums.size(); i++){

            sum+= nums[i];

            if(sum>res){
                res = max(sum,res);
            }

            if(sum<0){
                
                sum = 0;
            }

        }
    return res;
    }
};