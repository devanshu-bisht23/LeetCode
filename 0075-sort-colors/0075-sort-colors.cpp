class Solution {
public:

    int partition (vector<int>&nums, int l, int r){

        int pivot = nums[r];
        int i = l-1;

        for(int j = l; j<r; j++){
            if(nums[j]<pivot){
                i++;
                swap(nums[i],nums[j]);
            }
        }

        swap(nums[i+1],nums[r]);
        return (i+1);

    }

    // vector<int> 
    void quickSort(vector<int>&nums, int l, int r){
        if(l<r){
            int p = partition(nums, l, r);
            quickSort(nums, l, p-1);
            quickSort(nums, p+1, r);
        }

        // return nums;
    }

    void sortColors(vector<int>& nums) {
        
        // vector<int> arr =
         quickSort(nums,0, nums.size()-1);
        // return arr; 
        
    }
}; 