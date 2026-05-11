class Solution {
public:
    string minWindow(string s, string t) {
        
        std::unordered_map<char,int> counts; //get the counts
        for(const char& c:t) counts[c]++;
        
        std::string small = "";//int to hold smallest found

        for(int i{};i<s.size();i++){//loop through string at each char 

            if(counts.find(s[i]) != counts.end()){ //if current char is in 2nd string 
                
                std::string tmp{}; // and string to get size later 
                std::unordered_map<char,int> tmp_counts; // make tmp counts 

                for(int j = i;j < s.size();j++){ //loop through everthing past where first char 
                    
                    tmp_counts[s[j]]++;//add to the char counts
                    tmp+=s[j];//building the string to get size
                    
                    //this is for checking if tmp_counts are equal or greater than counts 
                    bool run = true;
                    for(auto& [key,value] : counts){
                        if(value > tmp_counts[key]){
                            run = false;
                            break;
                        }
                    }
                    
                    //update the size if run test was passed
                    if(run){
                        if(small == "" || tmp.size() < small.size())
                            small = tmp;
                        break; 
                    }
                }
            }
        }

        return small;
    }
};