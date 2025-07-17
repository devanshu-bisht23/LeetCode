class Solution {
public:
    int isValid(vector<int>& nums, int k, int mid, int n) {

        long long windowSum = 0;

        for (int i=0; i<mid-1; i++) {
            windowSum += nums[i];
        } 

        for (int i = mid-1; i<n; i++) {
            windowSum += nums[i];
            long long totalMax = 1LL * nums[i] * mid; 
            if (totalMax - windowSum <= k){ 
                return 1;
            }
            windowSum -= nums[i - mid + 1]; 
        }

        return 0;
    }

    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l=1, r=n, res=1;

        while (l <= r) {

            int mid = l + (r - l) / 2;
            if (isValid(nums,k, mid, n)) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
            
        }

        return res;
    }
};
