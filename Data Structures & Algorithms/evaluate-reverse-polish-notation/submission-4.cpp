class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(auto& c:tokens){
            if(c == "/" || c == "*" || c == "-" || c == "+"){
                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();

                switch(c[0]){
                    case '+':st.push(a+b);break;
                    case '-':st.push(b-a);break; 
                    case '*':st.push(a*b);break;
                    case '/':st.push(b/a);break;
                }
            }
            else{
                st.push(stoi(c));
            }
        }
        return st.top();
    }
};
