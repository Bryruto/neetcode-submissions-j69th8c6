class TimeMap {
private:
    std::unordered_map<std::string,std::unordered_map<int,std::string>> feeling;
public:
    TimeMap(){}
    
    void set(string key, string value, int timestamp) {
        feeling[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(feeling.find(key) != feeling.end() && feeling[key].find(timestamp) != feeling[key].end()){
            return feeling[key][timestamp];
        }

        int closest{};
        for(auto& [key,value] : feeling[key]){
            if(key > closest && key < timestamp){
                closest = key;
            }
        }

        return feeling[key].find(closest) != feeling[key].end() ? feeling[key][closest] : "";
    }
};
