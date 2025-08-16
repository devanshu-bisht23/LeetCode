class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int,int> hashMap;
        for(int i = 0; i<n; i++){
            hashMap[nums[i]] = 1; 
        }

        for(int i=0; i<=n; i++){
            if(hashMap.find(i) == hashMap.end()){
                return i;
            }
        }
    return 0;
    }
};