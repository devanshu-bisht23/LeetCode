class Solution {
public:
    
    int isValue(vector<int>& nums, int mid, int threshold){
        
        int sum = 0;

        for(int i: nums){

            sum += ceil((double)i/mid);

        }

    if(sum<=threshold){
        return 1;
    }else{
        return 0;
    }

    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int l = 1, r = INT_MAX, res;

        for(int i:nums){
            r = max(r,i);
        }

        while(l<=r){

            int mid = l + (r-l)/2;

            if(isValue(nums, mid, threshold)){
                res = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }

        }
    return res;
    }
};