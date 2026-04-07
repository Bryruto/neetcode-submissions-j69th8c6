class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        new_nums = []

        for i in range(2):
            for j in nums:
                new_nums.append(j)
        
        return new_nums
        