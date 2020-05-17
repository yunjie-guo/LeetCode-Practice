class MinStack {

public:
    // first is its value
    // second is the min element when it is pushed into the stack
    stack<pair<int,int>> myStack;
    
    void push(int x) {
        int lmin; // local min
        if (myStack.empty())
        {
            lmin=x;
        }
        else
        {
            lmin=min(x,myStack.top().second);
        }
        
        myStack.push(make_pair(x,lmin));
    }
    
    void pop() {
        myStack.pop();
    }
    
    int top() {
        return myStack.top().first;
    }
    
    int getMin() {
        return myStack.top().second;
    }
};
