class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        result = {}#val -> index
        #loop through the list and get the difference
        for i,n in enumerate(nums):#loop with enumerate because you get the index and the value
            diff = target - n
            if diff in result:
                return [result[diff], i]
        #if difference in the list get the index and return the index of the value you are looking at and that of the difference
            result[n] = i