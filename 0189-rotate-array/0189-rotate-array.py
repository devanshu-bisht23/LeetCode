class Solution:
    
    def rotate(self, nums: list[int], k: int) -> None:

        k = k%len(nums)

        def r(nums,i,j):
        
            while(i<j):
                nums[i],nums[j] = nums[j],nums[i]
                i = i+1
                j = j-1

        
        r(nums,0,len(nums)-1)
        r(nums,0,k-1)
        r(nums,k,len(nums)-1)


        