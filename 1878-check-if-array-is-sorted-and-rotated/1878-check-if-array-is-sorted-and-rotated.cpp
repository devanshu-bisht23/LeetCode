// Given an array nums
// return true if the array was originally sorted, then rotated some number of positions
// Otherwise, return false.

// There may be duplicates in the original array.

// An array A rotated by x positions results in an array B
// B[i] == A[(i+x) % A.length] for every valid index i

class Solution {
public:
    bool check(vector<int>& nums) {

        int count = 1;
        int n = nums.size();

        if(n==1){
            return true;
        }
        
        for(int i=1; i<n*2; i++){

            if(nums[(i-1) % n] <= nums[i % n]){
                count++;
                if(count == n){
                    return true;
                }
            }else{
                count = 1;
            }

        }
    return false;
    }
};