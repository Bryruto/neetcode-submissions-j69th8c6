class Solution:#best way and not hard at all it is an easy but i did both in 10 mins maybe even less
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        lowest = prices[0]


        for i in prices:
            lowest = min(lowest,i)
            profit = max(profit,i - lowest)
        
        return profit