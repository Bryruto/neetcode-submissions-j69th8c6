#include <vector>
#include <queue>
#include <functional>

struct compare{
    bool operator()(const vector<int>& a,const vector<int>& b){
        return sqrt(pow(a[0],2) + pow(a[1],2)) > sqrt(pow(b[0],2) + pow(b[1],2));
    }
}; 

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //sqrt((x1)^2 + (y1)^2)
        std::priority_queue<std::vector<int>,std::vector<std::vector<int>>,compare> min_q;

        for(auto vec : points){
            min_q.push(vec);
        }

        std::vector<std::vector<int>> result;
        for(size_t i{};i<k;i++){
            result.push_back(min_q.top());
            min_q.pop();
        }

        return result;
    }
};
