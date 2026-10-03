class Solution:

    def r(self,nums,i,j):
        
        while(i<j):
            nums[i],nums[j] = nums[j],nums[i]
            i = i+1
            j = j-1


    def rotate(self, nums: list[int], k: int) -> None:

        k = k%len(nums)

        self.r(nums,0,len(nums)-1)
        self.r(nums,0,k-1)
        self.r(nums,k,len(nums)-1)


        