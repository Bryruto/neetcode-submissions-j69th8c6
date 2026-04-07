class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        s1 = "".join(sorted(s1))
        length = len(s1)
        for i in range(len(s2)-length+1):
            tmp ="".join(sorted(s2[i:i+length]))
            if s1 == tmp:
                return True
        return False
