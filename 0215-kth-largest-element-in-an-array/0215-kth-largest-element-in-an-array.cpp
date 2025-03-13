class Solution {
public:

    int search(vector<int>& nums, int l, int r){

        // int x = l + rand() % (r - l + 1); // choose a random element's index
        // swap(nums[x], nums[r]); //swap the random element with last element

        int pivot = nums[r];
        int i = l-1;

        for(int j = i+1; j<r; j++){

            if(nums[j]<pivot){
                i++;
                swap(nums[i],nums[j]);
            }
        }

        swap(nums[i+1],nums[r]);
        return (i+1);

    }

    int quickSearch(vector<int>& nums, int l, int r,int k){

        if (l == r) {
            return nums[l];
        }

        //int n = nums.size()-k;
        if(l<=r){
            int p = search(nums,l,r);
            
            if(p == nums.size()-k){
                return nums[p];
            }
            
            else if (p > nums.size() - k) {
                return quickSearch(nums, l, p - 1, k);  // Search left part
            } 
            else {
                return quickSearch(nums, p + 1, r, k);  // Search right part
            }

        }
    return -1;
    } 

    int findKthLargest(vector<int>& nums, int k) {
        
        return quickSearch(nums, 0, nums.size()-1, k);
        
    }
};