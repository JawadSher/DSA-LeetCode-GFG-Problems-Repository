<h1 align='center'>Min - Stack</h1>

## Problem Statement

**Problem URL :** [Min Stack](https://leetcode.com/problems/min-stack/)

![image](https://github.com/user-attachments/assets/37f96d5b-2050-44c6-8e33-c768155ca2ed)
![image](https://github.com/user-attachments/assets/1d6a2e9e-513e-44fa-80d2-fc8f4e3afddd)

## Problem Explanation

You are tasked with designing a **MinStack** data structure that supports the following operations efficiently:

1. **push(int val)**: Push element `val` onto the stack.
2. **pop()**: Remove the top element from the stack.
3. **top()**: Get the top element without removing it.
4. **getMin()**: Retrieve the minimum element in the stack.

The challenge is to ensure that these operations, especially `getMin()`, work in constant time **O(1)**, and the stack operates correctly even if minimum values are pushed and popped.

### Approach and Explanation for Beginners

A simple stack cannot directly track the minimum efficiently without additional data structures or methods, so we can use an encoding technique. This method allows us to store values in such a way that even after several `push()` and `pop()` operations, we can track the minimum element in constant time.

The idea is to store an encoded value in the stack when the pushed value is smaller than the current minimum. This encoding is done using a formula, and by decoding the top value, we can update the minimum when necessary.

### Encoding Formula:

When pushing an element `val`:
- If `val` is smaller than the current minimum (`mini`), push an encoded value `2 * val - mini` onto the stack and update the `mini` to `val`. This encoding helps us restore the previous minimum when the encoded value is popped.

When popping an element:
- If the popped value is encoded (i.e., it's smaller than the current minimum), update the minimum using `mini = 2 * mini - curr`.

### Why Use Long Long?

In this implementation, we use `long long` (`LL`) to handle potential overflow issues when the encoding calculation `2 * val - mini` results in a value too large or too small for a standard `int`. This ensures that the stack can store values without encountering overflow errors.

### Example:

1. **push(5)**:
   - Stack: [5]
   - `mini = 5`

2. **push(2)**:
   - Stack: [5, -1] (`2 * 2 - 5 = -1`)
   - `mini = 2`

3. **push(8)**:
   - Stack: [5, -1, 8]
   - `mini = 2`

4. **pop()** (popping `8`):
   - Stack: [5, -1]
   - `mini = 2` (no change)

5. **pop()** (popping `-1`):
   - Stack: [5]
   - `mini = 5` (`mini = 2 * 5 - (-1) = 5`)

## Problem Solution
```cpp
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

```

## Problem Solution Explanation

```cpp
class MinStack {
    long long mini;          // Keeps track of the current minimum element
    stack<long long> st;     // Stack to store elements, using long long to prevent overflow

public:
    // Constructor to initialize the minimum to the maximum possible value
    MinStack() {
        mini = LLONG_MAX;
    }
```
- **mini**: A `long long` variable that holds the current minimum element in the stack.
- **st**: A stack of type `long long` to store both normal and encoded values.
- **MinStack()**: Initializes the stack with `mini = LLONG_MAX`, which represents the highest possible value for a long long, ensuring that the first pushed element will always be treated as the minimum.

---

```cpp
    void push(int val) {
        if (st.empty()) {
            st.push(val);  // First value is pushed directly
            mini = val;    // Update mini to the first value
        } else {
            if (val < mini) {
                // Push an encoded value to keep track of the minimum
                st.push(2LL * val - mini);
                mini = val;  // Update mini to the new minimum value
            } else {
                st.push(val);  // Push normally if val >= mini
            }
        }
    }
```
- **push(int val)**:
  - If the stack is empty, push the value directly and set `mini = val`.
  - If `val` is smaller than `mini`, we push the encoded value `2 * val - mini` to the stack and update `mini` to `val`. This ensures we can track the minimum even when popping elements.
  - If `val` is greater than or equal to `mini`, push `val` directly without encoding.

---

```cpp
    void pop() {
        if (st.empty()) return;  // Do nothing if the stack is empty

        long long curr = st.top();
        st.pop();

        // If the top value is encoded (i.e., less than mini), update mini
        if (curr < mini) {
            mini = 2LL * mini - curr;  // Decode to get the previous minimum
        }
    }
```
- **pop()**:
  - If the stack is empty, return immediately.
  - Pop the top element from the stack.
  - If the top element is encoded (i.e., it’s less than the current minimum), use `mini = 2 * mini - curr` to decode and update the previous minimum.

---

```cpp
    int top() {
        if (st.empty()) return -1;  // Return -1 if the stack is empty

        long long curr = st.top();
        // If the top value is an encoded value, return the minimum
        return (mini < curr) ? curr : mini;
    }
```
- **top()**:
  - If the stack is empty, return `-1`.
  - Otherwise, check if the top value is encoded (i.e., less than the current `mini`). If it is, return `mini` as the true top element. Otherwise, return the actual top value.

---

```cpp
    int getMin() {
        return (st.empty()) ? -1 : mini;
    }
};
```
- **getMin()**:
  - Simply return the current minimum (`mini`). If the stack is empty, return `-1`.

---

### Time and Space Complexities

#### Time Complexity:
- **Push Operation**: O(1) because we perform simple calculations and stack operations.
- **Pop Operation**: O(1) as we directly pop elements and update the minimum in constant time.
- **Top Operation**: O(1) because we just check the top of the stack.
- **GetMin Operation**: O(1) as the minimum is stored in a variable.

#### Space Complexity:
- **Space Complexity**: O(n), where `n` is the number of elements in the stack. We only use extra space for the stack and the `mini` variable.
