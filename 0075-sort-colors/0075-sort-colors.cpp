class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        unordered_map<int,int> hashMap;

        for(int num: nums){
            hashMap[num]++;
        }

        int j =0;
        for(int i = 0; i<3;i++){

            while(hashMap[i]>0){
                nums[j++] = i; 
                hashMap[i]--;
            }
      

        }


    }
};