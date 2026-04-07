class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        count_s,count_t ={},{}
        for c in range(len(s)):
            count_t[t[c]] = count_t.get(t[c],0) + 1 #go to dict count at key char and add 1 if no such key make it set it to 0
            count_s[s[c]] = count_s.get(s[c],0) + 1 #then add 1 to it now you have a key with that vaule
        return count_s == count_t
            