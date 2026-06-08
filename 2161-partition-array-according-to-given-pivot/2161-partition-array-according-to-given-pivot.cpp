class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        vector<int> less, equal, greater;

        for (auto &num : nums) {
            if (num < pivot) {
                less.push_back(num);
            } 
            else if (num == pivot) {
                equal.push_back(num);
            } 
            else {
                greater.push_back(num);
            }
        }

        nums.clear();

        for (int num : less) nums.push_back(num);
        for (int num : equal) nums.push_back(num);
        for (int num : greater) nums.push_back(num);

        return nums;
    }
};