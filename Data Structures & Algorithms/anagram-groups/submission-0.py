class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        string_list = {}
        final_list = []
        for s in strs:
            sort_s = "".join(sorted(s))
            if sort_s in string_list:
                string_list[sort_s].append(s)
            else:
                string_list[sort_s] = []
                string_list[sort_s].append(s)
        for key in string_list:
            final_list.append(string_list[key]) 
        return final_list