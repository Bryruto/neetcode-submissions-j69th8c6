class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        res = 0 

        for i in range(len(prices)):
            for x in range(i+1,len(prices)):
                res = max(res,prices[x] - prices[i])
    
        return res