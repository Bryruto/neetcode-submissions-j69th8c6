class Solution:
    def isPalindrome(self, s: str) -> bool:
        new_str = ""
        for c in s.lower():
            if c.isalpha() or c.isnumeric():
                new_str += c
        if new_str == new_str[::-1]:
            return True 
        return False

                
