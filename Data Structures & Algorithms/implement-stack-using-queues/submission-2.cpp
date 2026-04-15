class MyStack {
private:
    queue<int> q;    
public:
    MyStack(){}
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        queue<int> tmp;
        while(q.size() > 1){
            tmp.push(q.front());
            q.pop();
        }
        int result = q.front(); 
        q = tmp;
        return result;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
       return q.empty();
    }
};