class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();

        // Selection sort but descending order
        for(int i = 0; i < n; i++) {
            int max_idx = i;
            for(int j = i + 1; j < n; j++) {
                if(nums[j] > nums[max_idx]) {
                    max_idx = j;
                }
            }
            swap(nums[i], nums[max_idx]);
        }

        int Count = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] != nums[i - 1]) { // Only for counting unique values
                Count++;
                if(Count == 3) {
                    return nums[i]; 
                }
            }
        }

        return nums[0]; // return max if no 3 distinct elements in arr
    }
};
