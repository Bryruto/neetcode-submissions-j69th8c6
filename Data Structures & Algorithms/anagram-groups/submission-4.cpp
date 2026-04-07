/*
make hash map data stucture then count word to times you see it 
make a dynamic array that takes arrays of strings result array
    iterate through the array 
        sort all the elements values in the array ascending order
    iterate through array with sorted elements
        count the times you see each word 
    make array for each work count and add that to result array 
*/
#include <unordered_map>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) return {};
        int size = strs.size();

        vector<string> copy = strs;

        //sort each word 
        for(std::string &str: copy){
            if (str.empty()) continue;
            bool flip;
            do{
                flip = false;
                for(int i{};i<(int)str.size()-1;i++){
                    if(str[i] > str[i+1]){
                        char tmp = str[i];
                        str[i] = str[i + 1]; 
                        str[i + 1] = tmp;
                        flip = true;
                    }
                }
            }while(flip);
        }


        //add the strings to the array 
        std::unordered_map<std::string,std::vector<int>> l_i;//hashmap
        for(int i{};i<size;i++){
            l_i[copy[i]].push_back(i);  
        }


        //convert indexs to string values and add to array
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> tmp;
        for(auto& el:l_i){
            for(int i:el.second){
                tmp.push_back(strs[i]);
            }
            result.push_back(tmp);
            tmp.clear();
        }
        
        return result;
    }
};
