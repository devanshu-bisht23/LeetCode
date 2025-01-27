class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> hashMap; // To store the number and its index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; 
           
            if (hashMap.count(complement)) { // '.count' returns 1 if key exists and 0 if not
                return {hashMap[complement], i}; 
            }
            hashMap[nums[i]] = i; // Add the current number and its index to the map
        }
        return {};
    }
};