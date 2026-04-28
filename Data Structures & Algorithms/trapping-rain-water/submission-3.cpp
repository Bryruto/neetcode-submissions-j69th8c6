class Solution {
public:
    int trap(vector<int>& height) {
        //find max on left and right
        int water{};
        for(size_t i{};i + 1<height.size();i++){
            
            int maxL{0},maxR{0};

            for(size_t j = 0;j < i ;j++)
                if(maxL < height[j])
                    maxL = height[j];
            
            for(size_t j = i + 1;j < height.size();j++)
                if(maxR < height[j])
                    maxR = height[j];
            
            int min = maxL > maxR ? maxR : maxL;
            water += min - height[i] > 0 ? min - height[i] : 0;
        }
        return water;
        //find min of the maxxes 
        //subtract that from current index
    }
};
