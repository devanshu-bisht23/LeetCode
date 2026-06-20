class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int res = INT_MIN;
        int l = 0, r = height.size()-1;
        int x,y,prod;

        while(l<r){

            y = min(height[l],height[r]) * (r-l); // y axis
            
            // x = r - l; // x axis
            // prod = x*y; // product of x and y axis
            // res = max(res, prod);
            
            res = max(res, y);


            if(height[l] <= height[r]){
                l++;
            }else{
                r--;
            }

        }

        return res;


    }
};