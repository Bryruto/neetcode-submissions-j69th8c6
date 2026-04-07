class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        t,longest = 1,0

        new_nums=list(set(nums))
        new_nums.sort()

        for i in new_nums:
            if i + 1 not in new_nums or i - 1 not in new_nums:
                if t > longest:
                    longest = t
                t = 1 
            t += 1
        return longest

        