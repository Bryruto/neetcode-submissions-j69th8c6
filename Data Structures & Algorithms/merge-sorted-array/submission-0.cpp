class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        //make a copy of nums1 so i know the elements 
        vector<int> copy(nums1);
        
        //make index for nums1/copy and nums2
        int i{0},n1{0},n2{0}; 
        while(n1 <= m-1 && n2 <= n-1){
            if(copy[n1] <= nums2[n2]){
                nums1[i] = copy[n1];
                n1++;
            }
            else{
                nums1[i] = nums2[n2];
                n2++;
            }
            i++;
        }

        while(n1<= m-1){
            nums1[i] = copy[n1];
            n1++;
            i++;
        }
        while(n2 <= n-1){
            nums1[i] = nums2[n2];
            n2++;
            i++;
        }

    }
};