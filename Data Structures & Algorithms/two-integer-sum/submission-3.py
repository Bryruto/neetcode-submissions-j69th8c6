class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        #build a hashmap whith value:index 
        index = {}

        #enumerate over the given list
        for i,n  in enumerate(nums):
            diff = target - n
            if diff in index:
                return [index[diff],i]
            index[n] = i
        return 
        #check the difference 

        #add to hashmap if difference not found 


