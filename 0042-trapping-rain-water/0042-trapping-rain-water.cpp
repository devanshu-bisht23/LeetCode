class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = height[left];
        int rightMax = height[right];
        int water = 0;

        while(left<right){
            if(leftMax<rightMax){
                left++;
                if(leftMax<height[left]){ // can also use max()
                    leftMax = height[left];
                }
                water += leftMax - height[left];
            }else{
                right--;
                if(rightMax<height[right]){
                    rightMax = height[right];
                }               
                water += rightMax - height[right];
            }
        }
        return water;
    }
};