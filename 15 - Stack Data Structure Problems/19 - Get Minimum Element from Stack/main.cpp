class Solution {
    int mini;          // Stores the minimum element in the stack
    stack<int> st;     // Stack to store elements with special encoding for minimum tracking

public:
    
    /* Returns the top element of the stack */
    int top() {
        if (st.empty()) {
            return -1;  // Return -1 if stack is empty
        }

        int curr = st.top();
        // If the current top is an encoded value, return the actual minimum
        return (curr < mini) ? mini : curr;
    }
    
    /* Checks if the stack is empty */
    bool isEmpty() {
        return st.empty();
    }
    
    /* Returns the minimum element from the stack */
    int getMin() {
        return (st.empty()) ? -1 : mini;
    }
    
    /* Pops and returns the top element from the stack */
    int pop() {
        if (st.empty()) {
            return -1;  // Return -1 if stack is empty
        }

        int curr = st.top();
        st.pop();

        // If the popped value is greater than the current minimum, return it
        if (curr > mini) {
            return curr;
        } else {
            // If the popped value is encoded, decode and update the minimum
            int prevMini = mini;
            mini = 2 * mini - curr;
            return prevMini;
        }
    }
    
    /* Pushes an element x into the stack */
    void push(int x) {
        if (st.empty()) {
            st.push(x);
            mini = x;  // First element is both the top and the minimum
        } else {
            if (x < mini) {
                // Push an encoded value to track the new minimum
                st.push(2 * x - mini);
                mini = x;
            } else {
                // Push the actual value if it's greater than or equal to the current minimum
                st.push(x);
            }
        }
    }
};
