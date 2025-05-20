class Solution {
public:

    bool checkSplit(vector<int>& nums, int k, int mid){

        int subArray = 0;
        int curSum = 0;

        for(int n: nums){
            curSum += n;

            if(curSum > mid){
                subArray++; // new subarray has been formed 
                curSum = n; // seprate subarray that is starting from n
            }
        }

        if (subArray + 1 <= k) {
            return true;
        }else{
            return false;
}


    }


    int splitArray(vector<int>& nums, int k) {
        
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
 
        while(l<=r){
            
            int mid = l + (r-l) / 2;

            if(checkSplit(nums , k , mid) == true){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

    return l;
    }
};