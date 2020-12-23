class MinStack {
    list<pair<int,int>> mList;
public:
    /** initialize your data structure here. */
    MinStack() {
        mList = list<pair<int,int>>();
    }
    
    void push(int x) {
        pair<int,int> p(x,x);
        if(mList.size())
            p.second = min(x, mList.back().second);
        mList.push_back(p);
    }
    
    void pop() {
        if(mList.size())
            mList.pop_back();
    }
    
    int top() {
        if(mList.size())
            return mList.back().first;
        
        return -1;
    }
    
    int getMin() {
        if(mList.size())
            return mList.back().second;
        
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */