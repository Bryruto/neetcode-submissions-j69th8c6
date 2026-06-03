class LRUCache {
    private:
        int capacity;
        std::vector<int> last;
        std::unordered_map<int,int> cache;
    public:
        LRUCache(int capacity):capacity(capacity){
            last.reserve(capacity+1);
            cache.reserve(capacity);
        }
    
        int get(int key){
            if(cache.find(key) == cache.end()) 
                return -1;

            size_t i{}; 
            for(;i<last.size();i++){
                if(key == last[i]) break;
            }
            last.erase(last.begin() + i);//may need to add 1 to i
            last.push_back(key);//add number back to the end

            return cache[key];             
        }
    
        void put(int key, int value) {
            if(cache.find(key) != cache.end()){
                cache[key] = value;
                int trash = get(key);
                return; 
            }

            if(last.size() >= capacity){
                int oldKey = last[0];
                last.erase(last.begin());
                cache.erase(oldKey);
            }

            last.push_back(key);
            cache[key] = value;
        }
};
