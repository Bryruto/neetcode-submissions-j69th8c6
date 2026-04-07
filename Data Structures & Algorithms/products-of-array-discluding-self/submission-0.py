class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        output = []
        for i in range(len(nums)):
            result = 1
            for j in range(len(nums)):
                if i == j:
                    continue
                result *= nums[j]
            output.append(result)
        return output