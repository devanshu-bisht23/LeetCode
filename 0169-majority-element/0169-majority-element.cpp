class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int,int> hashMap;

        for(int num:nums){
            hashMap[num] ++;
        }

        int majority = nums[0];
        int maxCount = 0;

         for(auto& hash : hashMap){
            if(hash.second > maxCount){
                maxCount = hash.second;
                majority = hash.first;
            }
        }
        
        return majority;

    }
};