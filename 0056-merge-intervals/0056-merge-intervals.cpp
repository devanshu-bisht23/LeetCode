class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        int temp = nums[0][1];
        int val1 = nums[0][0];
        int i;

        for(i=1; i<n; i++){

            int f = nums[i][0];
            int s = nums[i][1];

            if(f<=temp){
                temp = max(temp,s);
            }else if(f>temp){
                ans.push_back({val1,temp});
                val1 = f;
                temp = s;
            }
        }


        ans.push_back({val1,temp});
        return ans;

    }
};