class MinStack {
public:
    stack <pair<int,int>> s; // pair <val , last min val>
    int minValue = INT_MAX;
    MinStack() {
    }

    void push(int val) {
        s.push(pair(val,minValue));
        minValue = min(val, minValue);
    }
    
    void pop() {
        if(s.top().first == minValue){
            minValue = s.top().second;
        }
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return minValue;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
