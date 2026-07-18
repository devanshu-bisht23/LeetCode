class Solution {
public:

    void findIdx(int target, vector<int> &ans, vector<int> &nums2, vector<int> &nextGreater){

        for(int i=0; i<nums2.size();i++){
            if(target == nums2[i]){
                ans.push_back(nextGreater[i]);
                return;
            }
        }

    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> st;
        vector<int> nextGreater;
        for(int i=nums2.size()-1; i>=0; i--){

            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            
            if(st.empty()){
                nextGreater.push_back(-1);
            }else{
                nextGreater.push_back(st.top());
            }
        
            st.push(nums2[i]);

        }

        reverse(nextGreater.begin(), nextGreater.end());

        vector<int> ans;

        for(int i = 0; i<nums1.size(); i++){
            
            findIdx(nums1[i],ans,nums2,nextGreater);

        }

        return ans;


    }
};