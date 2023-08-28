class MyStack {
public:
    queue <int> q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();

        }
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
    }
    
    int pop() {
        if(q2.size()){
            int a=q2.front();
            q2.pop();
            return a;

        }
        return -1;
    }
    
    int top() {
        if(q2.size()){
            return q2.front();
        }
        return -1;
    }
    
    bool empty() {
        return q2.size()==0;
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */