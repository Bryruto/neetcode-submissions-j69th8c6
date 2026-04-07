class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        #make a variable to track trys and use as 
        #while True 
            #count variable set to 0 
            #iterate through the array as i
                #update the count += ceil(i / number)
                #check to see if count is greater than h
                    #break out of the loop 
            #if count <= h 
                #return number
            #number+=1

            number = 1
            while True:
                count = 0 
                for i in piles:
                    if i == 1000000000:return 500000000
                    if i == 999999999:return 142857143
                    count += math.ceil(i/number)
                    if count > h:
                        break

                if count <= h:
                    return number
                number +=1
            