class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best{};

        for(size_t i{};i<prices.size();i++)
            for(size_t j = i + 1;j<prices.size();j++)
                if(best < prices[j] - prices[i]) 
                    best = prices[j] - prices[i];
            
        return best;
    }
};
