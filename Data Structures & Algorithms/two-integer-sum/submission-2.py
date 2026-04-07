class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        index = []
        for i in range(len(nums)):
            for j in range(len(nums)):
                if j != i:
                    if nums[i] + nums[j] == target:
                        index.append(i)
                        index.append(j)
                        return index
