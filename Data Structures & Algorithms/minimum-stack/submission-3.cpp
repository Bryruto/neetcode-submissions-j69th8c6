class MinStack {
public:
    std::stack<int> stk;
    MinStack(){}
    
    void push(int val) {
        stk.push(val);
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        std::stack<int> tmp = stk;
        int min = stk.top(); 
        for(size_t i{};i<stk.size();i++){
            if(tmp.top() < min ) min = tmp.top();
            tmp.pop();
        }
        return min;
    }
};
