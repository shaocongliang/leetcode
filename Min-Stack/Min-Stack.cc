class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if (h.empty() || h.top() >= val) {
            h.push(val);
        }
    }
    
    void pop() {
        auto val = s.top();
        s.pop();
        if (val == h.top()) {
            h.pop();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return h.top();
    }
private:
    stack<int> s;
    stack<int> h;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
