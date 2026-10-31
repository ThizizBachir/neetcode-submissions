class MinStack {
private: 
    vector<int> elems;
    stack<int> mins;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        elems.push_back(val);
        if(mins.empty() || mins.top()>=val)
        {
            mins.push(val);
        }
        else
        {
            mins.push(mins.top());
        }
        
    }
    
    void pop() {
        elems.pop_back();
        mins.pop();

    }
    
    int top() {
        return elems.back();
        
    }
    
    int getMin() {
        return mins.top();
        
    }
};
