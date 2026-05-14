class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // height times width is area of rectangle

        int best{0};
        int curr{0};
        for(;curr < heights.size();curr++){
            int left = curr -1; 
            int right = curr + 1;
            
            int width = 1;
            int height = heights[curr];

            for(;left>=0;left--){
                if(height > heights[left])
                    break;
                
                width++;
            }

            for(;right<heights.size();right++){
                if(height > heights[right])
                    break;
                
                width++;
            }

            int area = width * height;
            if(area > best)
                best = area;
            

        }

        return best;
    }
};
