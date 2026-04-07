class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        #make the variable for days to count the days it takes to get a warmer temp
        #make a list variable that will store the days till warmer for all the days
        #itterate through the list of temperatures for every day
            #itterate thought the temperatures again but staring at the day you are looking at
            #ask if the the day temperature you are checking for is less than nexts days temp
                #if temp is less then append the days count to results,break from inner loop 
            #if it is greater than or equal to then add one to the day count move on to the next in the list
        days = 1
        results = []
        for i in range(len(temperatures)):
            for x in range(i + 1,len(temperatures)):
                if temperatures[i] < temperatures[x]:
                    results.append(days)
                    days = 1
                    break
                elif x + 1 == len(temperatures):
                    results.append(0)
                    days = 1
                else:
                    days+=1
        results.append(0)
        return results

