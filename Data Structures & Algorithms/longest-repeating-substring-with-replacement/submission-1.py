class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        res = 0

        for i in range(len(s)):
            tmp,changes = 1,0

            while changes <= k:
                for j in range(i+1,len(s)):
                    if s[i] != s[j]:
                        changes+=1 
                        if changes > k:
                            break
                    tmp+=1
                if changes <= k:
                    for j in range(i-1,-1,-1):
                        if s[i] != s[j]:
                            changes+=1
                            if changes > k:
                                break
                        tmp+=1
                res = max(tmp,res)
                break
        return res


                
                    
