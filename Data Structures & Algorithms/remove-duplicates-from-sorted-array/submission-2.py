class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        unique = list(set(nums))
        unique.sort()
        length = len(unique)
        for i in range(length):
            nums[i]=unique[i]
        return length        