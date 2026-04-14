class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        for(int &i : sandwiches){
            bool found = false;
            size_t j{}; 
            for(;j<students.size();j++){
                if(i == students[j]){
                    found = true;
                    break;
                }
            }
            if(found) students.erase(students.begin() + j);
            else return students.size();  
        }
        return 0;

    }
};