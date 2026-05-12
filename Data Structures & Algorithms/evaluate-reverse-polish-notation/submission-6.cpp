class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> i;

        for(auto& c:tokens){
            if(c == "+" || c == "-" || c == "/" || c == "*"){
                int a = i.top();
                i.pop();
                int b = i.top();
                i.pop();
                switch(c[0]){
                    case '+':i.push(b + a);break; 
                    case '-':i.push(b - a);break; 
                    case '/':i.push(b / a);break;
                    case '*':i.push(b * a);break;
                }
            }
            else{
                i.push(std::stoi(c));
            }
        }
        return i.top();
    }
};
