class Solution:
    def maxArea(self, heights: List[int]) -> int:
        res,area = 0,0 
        for i in range(len(heights)):
            best = 0
            for i2 in range(i+1,len(heights)):
                if heights[i] >= heights[i2]:
                    area=(i2-i)*heights[i2]
                else:
                    area=(i2-i)*heights[i]

                if area > best:
                    best = area

            if best > res:
                res = best
        return res

            
        
        
