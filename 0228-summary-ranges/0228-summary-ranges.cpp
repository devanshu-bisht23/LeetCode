class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        if (n == 0) return res; 

        int start = 0; // keeps address track

        for (int i = 1; i <= n; i++) { // notice <= n so we check after the last element

            if (i == n || nums[i] != nums[i-1] + 1) { // if prev value is less than 1 of the current value then its a seq
                if (start == i - 1) { // eg: 0 == 0 or 2==2 etc...
                    // for single element range
                    res.push_back(to_string(nums[start]));
                } else {
                    // for multiple element range
                    res.push_back(to_string(nums[start]) + "->" + to_string(nums[i-1]));
                }
                start = i; //update start to trak first value in a range
            }
            
        }

        return res;
    }
};
