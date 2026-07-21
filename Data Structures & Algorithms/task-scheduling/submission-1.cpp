class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::unordered_map<char,int> counts;
        for(const auto c : tasks) counts[c]++;

        std::priority_queue<int> que;
        for(const auto& [key,val]:counts) que.push(val);
        
        int time{};
        std::queue<pair<int,int>> wait;
        for(;!que.empty() || !wait.empty();time++){

            if(!wait.empty()){
                auto tmp = wait.front();
                if(time >= tmp.second){
                    wait.pop();
                    que.push(tmp.first);
                }
            }

            if(!que.empty()){
                int tmp = que.top();
                que.pop();
                if(--tmp > 0) wait.emplace(tmp,time + n + 1); 
            }
        }
        return time;
    }
};
