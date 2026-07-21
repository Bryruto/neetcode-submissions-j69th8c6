class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time{};

        std::unordered_map<char,int> counts;//to get the counts faster
        std::priority_queue<int> pue; //to order
        std::queue<pair<int,int>> wait; //to tell me when i can remove 

        //count elements 
        for(auto c : tasks)
            counts[c]++;
        
        //add counts value to pue -> priority_queue
        for(const auto& [key,value]:counts)
            pue.push(value);
        

        //loop while wait has elements or pue has elements 
        while(!wait.empty() || !pue.empty()){
            
            //if wait has elements
            if(!wait.empty()){
                auto tmp = wait.front(); 
                if(time >= tmp.second){
                    pue.push(tmp.first);
                    wait.pop();
                }
            }

            if(!pue.empty()){
                int tmp = pue.top();
                pue.pop();
                if(--tmp != 0) wait.emplace(tmp,time + n + 1); 
            }
            time++; 
        }

        return time;

        
        /*/this will count all the elements buket sort is so much better 
        for(size_t i{};i<tasks.size();){
            int count{};
            for(size_t j = i+1;j<tasks.size();){
                if(tasks[i] == tasks[j]){
                    count++;
                    tasks.erase(tasks.begin() + j);
                }
                else j++;
            }
            tasks.erase(tasks.begin())
            pue.push(count);
        }
        */


    }
};
