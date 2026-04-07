class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        strings = {}
        result = []
        for s in strs:
            sort = "".join(sorted(s))#returns a fuck list not a string so you nees join and '' empty string
            if sort not in strings:
                strings[sort] = []
            strings[sort].append(s)
        return list(strings.values())