void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = n - 1;  // index for nums2
    int j = m - 1;  // index for nums1 ////main array
    int k = m + n - 1;  // Last index for merged array in nums1 ////last 0

    while (i >= 0 && j >= 0) { // Merge nums2 into nums1 starting from last
        if (nums1[j] > nums2[i]) {
            nums1[k] = nums1[j];
            j--;
        } else {
            nums1[k] = nums2[i];
            i--;
        }
        k--;  
    }
    
    while (i >= 0) { // this runs when only nums2 has elements, but not nums1
        nums1[k] = nums2[i];
        i--;
        k--;
    }
}
