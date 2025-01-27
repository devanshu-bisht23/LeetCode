class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map<int,int> hashMap;

        for(int i=0;i<nums.size();i++){
            int target = nums[i];
            if(hashMap.count(target)){
                return true;
            }
        hashMap[nums[i]] = i;
        }
return false;
    }
};