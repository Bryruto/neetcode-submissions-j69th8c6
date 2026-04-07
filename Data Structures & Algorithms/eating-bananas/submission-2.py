from math import ceil

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        #make a variable to track trys and use as 
        #while True 
            #count variable set to 0 
            #iterate through the array as i
                #update the count += ceil(i / number)
                #check to see if count is greater than h
                    #break out of the loop 
            #if count == h 
                #return number
            #else number+=1


        low = 1
        high = max(piles)
        res = high

        while low <= high:
            b = (low + high) // 2
            count = 0
            for i in piles:
                count += ceil(i/b)
                if count > h:
                    break

            if count <= h:
                res = b
                high = b - 1
            else:
                low = b + 1
        return res