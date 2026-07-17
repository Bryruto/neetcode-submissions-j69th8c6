class Solution {
public:
    int lastStoneWeight(vector<int>& s) {
        priority_queue<int> stones;
        
        for(auto& i:s)
            stones.push(i); 
        
        while(stones.size() > 1){
            int a = stones.top();
            stones.pop();
            int b = stones.top();
            stones.pop();

            if(a-b > 0)
                stones.push(a - b);
        }

        return stones.empty() ? 0 : stones.top();
    }
};
