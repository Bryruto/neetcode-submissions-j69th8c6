class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        hashmap = {} # value to index

        for i,v in enumerate(numbers):
            goal = target - v
            hashmap[v] = i + 1
            if goal in hashmap:
                if hashmap[goal] < i + 1:
                    return [hashmap[goal],i + 1]

                

            