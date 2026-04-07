class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        #make a list for the unique numbers
        #to do this i make a set this takes all elements that are the same out and gives me a set 
        temp = set(nums)
        #i convert back to a list
        unique = list(temp)
        #sort
        unique.sort()
        #get the size of the unique elements 
        length = len(unique)

        #for the elements inbetween 0 and len set to unqiue // change the original  list
        nums[ :length] = unique
        return length