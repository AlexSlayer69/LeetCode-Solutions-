class MinStack {
public:
    vector<pair<int,int>> arr;
    MinStack() {

    }
    
    void push(int val) {
        if(arr.size() == 0)
            arr.push_back({val,val});
        else
            arr.push_back({val,min(arr[arr.size()-1].second,val)});
    }
    
    void pop() {
        arr.pop_back();
    }
    
    int top() {
        return arr[arr.size()-1].first;
    }
    
    int getMin() {
        return arr[arr.size()-1].second;
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