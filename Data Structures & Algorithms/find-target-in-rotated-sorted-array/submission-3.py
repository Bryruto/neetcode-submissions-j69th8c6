class Solution:
    def search(self, nums: List[int], target: int) -> int:
        #binary search i tried and failed i was very close 
        #get index start of array and end of array assign to variables l and r
        #iterate through list as long as l < r
            #find the mid point of what you are searching assign to variable mid
            #check to see if the mid point value is your target 
                #return mid
            #calulate if target is between l and mid
            #is between 
                #update the r to mid -1 
            #not between
                #update the l to mid + 1
        #did not find target return -1

        l,r = 0, len(nums) - 1

        while l <= r:
            mid = (l + r) // 2
            if nums[mid] == target:
                return mid
            
            # Identify which side is sorted
            if nums[l] <= nums[mid]:
                # Left side is sorted
                if nums[l] <= target < nums[mid]:
                    r = mid - 1
                else:
                    l = mid + 1
            else:
                # Right side is sorted
                if nums[mid] < target <= nums[r]:
                    l = mid + 1
                else:
                    r = mid - 1
        return -1
