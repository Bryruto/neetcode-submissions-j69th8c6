class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count= {}
        fre = []
        for n in range(len(nums)+1):
            fre.append([])
        
        for n in nums:
            count[n]= 1 + count.get(n,0)# count plus 1-aka-itself defult 0

        for n,c in count.items():
            fre[c].append(n) # number and count

        res = []
        for i in range(len(fre)-1,0,-1):# dont completely get this part why -1 how does that make it out of range 
            for n in fre[i]: #i is the count for the numbers 
                res.append(n) #n is the number we give back 
                if len(res) == k:
                    return res




            