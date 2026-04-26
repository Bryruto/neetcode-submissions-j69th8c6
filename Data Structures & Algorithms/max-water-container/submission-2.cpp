class Solution {
public:
    int maxArea(vector<int>& heights) {
        int best{};
        for(int i{};i<heights.size();i++){
            for(int j = i+1;j<heights.size();j++){
                int tall = heights[i] <= heights[j]? heights[i] : heights[j];
                int wide = j - i;
                if(best < tall*wide)
                    best = tall*wide; 
            }
        }
        return best;
    }

};

/*
(1,7,2,5,4,7,3,6)
i= 0,0
j= 1,
tall = 1, 
wide = 1-0 = 1, 2-0 = 2
best = 
*/
