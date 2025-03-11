#include <stdbool.h>

bool isMonotonic(int* nums, int numsSize) {

    int i=0,j=1;

    int k = nums[0] - nums[numsSize-1]; //figuring out if k is +ve or -ve

    if(k>0){ //if k positive then it has to be descending

        while(i<numsSize && j<numsSize){
            if(nums[i]>=nums[j]){ //checking ascending
                i++;
                j++;
            }else{ //it was not descending
                return false;
            }
        }
        

    }else{ //else itll be ascending
        while(i<numsSize && j<numsSize){
            if(nums[i]<=nums[j]){ //checking descending
                i++;
                j++;
            }else{ //it was not ascending 
                return false;
            }
    }

}
return true; //we won if we successfully dodged other returns
}
