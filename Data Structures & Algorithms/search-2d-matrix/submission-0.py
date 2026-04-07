class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        
        for i in matrix:
            l,r = 0,len(i)-1

            if i[r] < target:
                continue

            while l <= r:

                mid = (l + r)//2
                if i[mid] == target : return True
                if i[mid] < target:
                    l = mid + 1
                else:
                    r = mid - 1

        return False