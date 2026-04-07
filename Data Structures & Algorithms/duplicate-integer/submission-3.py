class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        nums.sort()
        for num in range(1,len(nums)):
            if nums[num] == nums[num - 1]:
                return True
        return False