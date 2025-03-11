class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> hashMap;

        for(const auto& num : nums){
            hashMap[num]++;
        }

        for(const auto& i: hashMap){
            if(i.second == 1){
                return i.first; 
            }
        }
        return 0;
    } 
};