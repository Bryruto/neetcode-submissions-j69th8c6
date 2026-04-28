class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;

        int maxL[height.size()];
        int maxR[height.size()];
        int indexR = height.size()-1,indexL{},valueR{},valueL{}; 
        

        for(size_t i{};i<height.size()-1;i++){
            if(height[indexR] > valueR) valueR = height[indexR];
            if(height[indexL] > valueL) valueL = height[indexL];

            maxL[indexL+1] = valueL;
            maxR[indexR-1] = valueR;

            indexR--;
            indexL++;
        }

        int water{};
        for(size_t i{1};i + 1 <height.size();i++){
            int min = maxL[i] > maxR[i] ? maxR[i] : maxL[i];

            water += min - height[i] > 0 ? min - height[i] : 0; 
        }

        return water;
    }
};
