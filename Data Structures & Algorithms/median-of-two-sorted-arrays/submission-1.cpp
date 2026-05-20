class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int> all;
        int l{},r{};

        while(l < nums1.size() && r < nums2.size()){
            if(nums1[l] <= nums2[r]){
                all.push_back(nums1[l++]);
            }
            else 
                all.push_back(nums2[r++]);
        }

        while(l<nums1.size()){
            all.push_back(nums1[l++]);
        }
        while(r<nums2.size()){
            all.push_back(nums2[r++]);
        }


        int n = all.size();
        return n % 2 == 1 ? all[n/2]: (all[n/2-1] + all[n/2])/2.0;
        

    }
};