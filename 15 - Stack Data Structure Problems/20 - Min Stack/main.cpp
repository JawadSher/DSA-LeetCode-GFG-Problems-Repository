class MinStack {
    long long mini;
    stack<long long> st;
public:
    MinStack() {
        mini = LLONG_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini = val;
        }else{
            if(val < mini){
                st.push(2LL * val - mini);
                mini = val;
            }else{
                st.push(val);
            }
        }

    }
    
    void pop() {
        if(st.empty()) return;

        long long curr = st.top();
        st.pop();

        if(curr < mini) mini = 2LL * mini - curr;;

    }
    
    int top() {
        if(st.empty()) return -1;
        
        long long curr = st.top();
        return (mini < curr) ? curr : mini;
    }
    
    int getMin() {
        return (st.empty()) ? -1 : mini;
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
