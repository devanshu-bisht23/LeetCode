class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        stack<int> st;
        vector<int> nextGreater;

        int n = nums.size();

        for(int i = n*2-1; i>=0; i--){

            while(!st.empty() && st.top() <= nums[i%n]){
                st.pop();
            }
            
            if (i < n) {
                if (st.empty()) {
                    nextGreater.push_back(-1);
                } else {
                    nextGreater.push_back(st.top());
                }
            }

            // if (st.empty()) {
            //     nextGreater.push_back(-1);
            // } else {
            //     nextGreater.push_back(st.top());
            // }
        
            st.push(nums[i%n]);

        }

        reverse(nextGreater.begin(), nextGreater.end());

        return nextGreater;

    }
};