class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int l{0};
        int r = matrix.size()-1;

        vector<int> found;

        while(found.empty() && l <= r){
            int middle = l +(r-l)/2;
            if(target>= matrix[middle][0] && target <= matrix[middle][matrix[middle].size()-1]) found = matrix[middle];
            else if(target > matrix[middle][matrix[middle].size()-1]) l = middle + 1;
            else if(target < matrix[middle][0]) r = middle -1;
        }


        if(!found.empty()){
            l = 0;
            r = found.size()-1;

            while(l <= r){
                int middle = l +(r-l)/2;
                if(target == found[middle]) return true;
                else if(target > found[middle])l = middle + 1;
                else if(target < found[middle]) r = middle -1;
            }
        }
        return false;
    }
};
