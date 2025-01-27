class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map<int,int> hashMap; // we set out hashmap

        for(int i=0;i<nums.size();i++){ // loop through the array nums

            if(hashMap.count(nums[i])){
                return true; // return true if value is found again in the hashMap
            }

        hashMap[nums[i]] = i; // put value is that value isnt in hashMap
        }
        
return false; // return false if value aint repeating
    }
};