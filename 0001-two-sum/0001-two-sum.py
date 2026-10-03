class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        
        hash = {}

        for i in range(len(nums)):
            diff = target - nums[i]

            if diff in hash:
                return [hash[diff],i]
            
            hash[nums[i]] = i

        return 