class Solution {
public:
    void quicksort(vector<pair<int,int>>& cars,int s,int e){
        if(s >= e)
            return; 
        
        pair<int,int> pivot = cars[e];
        int left = s;

        for(size_t i = s;i<e;i++){
            if(pivot.first > cars[i].first){
                pair<int,int> tmp = cars[i];
                cars[i] = cars[left];
                cars[left] = tmp;
                left++;
            }    
        }
        
        pair<int,int> tmp = cars[left];
        cars[left] = pivot;
        cars[e] = tmp;

        quicksort(cars,s,left-1);
        quicksort(cars,left+1,e);
    }


    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if(position.empty() || speed.empty())
            return 0;

        vector<pair<int,int>> cars;
        cars.reserve(position.size());

        for(size_t i{};i<position.size();i++)
            cars.emplace_back(position[i],speed[i]);
        
        quicksort(cars,0,cars.size()-1);

        stack<double> fleets;

        for(int i = cars.size()-1;i >= 0;i--){
            double time = 1.0 * (target - cars[i].first)/cars[i].second;
            
            if(fleets.empty())
                fleets.push(time);
            else if(fleets.top() < time)
                fleets.push(time);
        }

        return fleets.size(); 
    }
};
