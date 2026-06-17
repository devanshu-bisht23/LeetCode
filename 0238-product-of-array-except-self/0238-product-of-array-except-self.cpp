class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> prefix;
        vector<int> suffix;
        vector<int> ans;

        prefix.push_back(1);

        int prod = 1;
        for(int i=0; i<n-1; i++){
            prod *= nums[i];
            prefix.push_back(prod);
        }

        prod = 1;
        suffix.push_back(1);
        for(int i=n-1; i>0; i--){
            prod *= nums[i];
            suffix.push_back(prod);
        }

        reverse(suffix.begin(),suffix.end());

        for(int i=0; i<n; i++){
            if(i==0){
                ans.push_back(suffix[i]);
            }else if(i==n-1){
                ans.push_back(prefix[i]);
            }else{
                ans.push_back(prefix[i] * suffix[i]);
            }
        }

        return ans;

    }
};