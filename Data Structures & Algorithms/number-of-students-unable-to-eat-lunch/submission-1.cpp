#include <unordered_map>
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        unordered_map<int,int> hash;
        int count{};

        for(int &i:students) hash[i]++;

        for(int &i:sandwiches){
            if(hash[i] == 0) return students.size() - count;
            hash[i]--;
            count++;
        }

        return 0;
    }
};