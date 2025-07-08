class Solution { // bs on asnwers
public:

    int isPossible(vector<int>& nums, int k, int mid){

        int split = 1, maxi = 0;

        for(int i: nums){

            if(maxi + i <= mid){
                maxi += i;
            }else{
                maxi = i;
                split++;
            }

        }

        if(split <= k){
            return 1;
        }else{
            return 0;
        }

    }

    int splitArray(vector<int>& nums, int k) {
        
        int x = accumulate(nums.begin(),nums.end(),0);
        int l = *max_element(nums.begin(), nums.end());
        int r = x, res; 

        while(l<=r){

            int mid = l + (r-l)/2;

            if(isPossible(nums, k, mid)){
                res = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

    return res;

    }
};