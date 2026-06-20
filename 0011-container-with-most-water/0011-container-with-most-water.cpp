class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int res = INT_MIN;
        int l = 0, r = height.size()-1;
        int x,y,prod;
        
        while(l<r){

            y = min(height[l],height[r]);
            x = r - l;
            prod = x*y;
            res = max(res, prod);

            if(height[l] <= height[r]){
                l++;
            }else{
                r--;
            }

        }

        return res;


    }
};