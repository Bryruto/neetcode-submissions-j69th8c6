class Solution {
public:
    int lastStoneWeight(vector<int>& s) {
        priority_queue<int> stones(s.begin(),s.end());
        
        
        while(stones.size() > 1){
        
            int a = stones.top();
            stones.pop();
            int b = stones.top();
            stones.pop();

            if(a != b){ 
                stones.push(a - b);
            }
        }

        return stones.empty() ? 0 : stones.top();
    }
};
