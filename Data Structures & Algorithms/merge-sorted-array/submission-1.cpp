class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result(nums1.size());
        size_t i{},j{},k{};
        for(;j < m  && k < n; i++)
            result[i] =  nums1[j] <= nums2[k] ? nums1[j++] : nums2[k++];

        while(j < m) result[i++] = nums1[j++];
        while(k < n) result[i++] = nums2[k++];

        nums1 = result; 
    }
};