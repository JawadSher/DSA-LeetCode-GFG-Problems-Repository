<h1 align='center'>Get - Minimum - Element - from - Stack</h1>

## Problem Statement

**Problem URL :** [Get Minimum Element from Stack](https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/ba473d21-f829-4577-9a86-f859640a1a92)
![image](https://github.com/user-attachments/assets/7cfbb1b4-3927-4a46-a989-5461ddde0cb0)
![image](https://github.com/user-attachments/assets/72094a19-27bf-4c1d-bf5a-0b38568d7e5c)

## Problem Explanation

In this problem, you are asked to implement a stack that supports the following operations efficiently:

1. **Push(x)**: Push element `x` into the stack.
2. **Pop()**: Pop the top element from the stack and return it.
3. **Top()**: Return the top element of the stack without removing it.
4. **GetMin()**: Return the minimum element from the stack.

**Additional Constraints**:
- The stack should support the `GetMin()` operation in constant time **O(1)**, even if the stack undergoes `Push()` and `Pop()` operations.
  
### Approach and Explanation for Beginners

To solve this problem, a beginner might think of keeping track of the minimum element in the stack by iterating through all elements when asked for the minimum. However, this approach would require **O(n)** time for the `GetMin()` function (where `n` is the number of elements in the stack), which is inefficient.

Instead, we need a way to maintain the minimum element dynamically while keeping track of the elements in the stack. We can achieve this using a clever encoding technique when pushing values to the stack.

### The Key Idea: Encoding Technique

The stack will store elements in a way that helps us track the minimum at each stage:
- Maintain a variable `mini` that stores the current minimum element.
- Whenever a new element is pushed to the stack that is smaller than `mini`, push an encoded value that helps us keep track of the previous minimum.
- If the top of the stack is an encoded value, it tells us that a new minimum was encountered when that element was pushed.

### Formula:
When pushing an element `x`:
- If `x` is smaller than the current minimum (`mini`), push `2 * x - mini` to the stack and update `mini` to `x`. This ensures that we store a value that encodes both the new minimum and helps us restore the previous minimum when popped.

When popping an element:
- If the popped element is encoded (i.e., it’s less than the current `mini`), use the formula `mini = 2 * mini - curr` to update the minimum to the previous value.

### Example:

1. **Push(5)**:
   - Stack: [5]
   - `mini = 5`

2. **Push(2)**:
   - Stack: [5, -1] (where `-1` is the encoded value `2 * 2 - 5 = -1`)
   - `mini = 2`

3. **Push(8)**:
   - Stack: [5, -1, 8]
   - `mini = 2`

4. **Pop()** (popping `8`):
   - Stack: [5, -1]
   - `mini = 2` (no change)

5. **Pop()** (popping `-1`):
   - Stack: [5]
   - `mini = 5` (decoded as `mini = 2 * 5 - (-1) = 5`)

## Problem Solution
```cpp
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
```


## Problem Solution Explanation

```cpp
class Solution {
    int mini;          // Stores the minimum element in the stack
    stack<int> st;     // Stack to store elements, with special encoding for minimum tracking

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
```
- **mini**: Keeps track of the current minimum element in the stack.
- **st**: The stack that holds the elements, and sometimes encoded values.
- **top()**: If the current top element is encoded (i.e., it's less than `mini`), return `mini`, otherwise return the top value.

---

```cpp
    /* Checks if the stack is empty */
    bool isEmpty() {
        return st.empty();
    }
```
- **isEmpty()**: Simply checks if the stack is empty and returns a boolean value.

---

```cpp
    /* Returns the minimum element from the stack */
    int getMin() {
        return (st.empty()) ? -1 : mini;
    }
```
- **getMin()**: Returns the current minimum element. If the stack is empty, it returns `-1`.

---

```cpp
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
```
- **pop()**: 
  - If the stack is empty, return `-1`.
  - If the top element is greater than `mini`, it means it's a normal value, so just return it.
  - If the top element is encoded (i.e., smaller than `mini`), we decode the previous minimum using `mini = 2 * mini - curr`, update `mini`, and return the previous minimum.

---

```cpp
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
```
- **push()**:
  - If the stack is empty, push the value `x` directly and set `mini = x`.
  - If `x` is smaller than the current `mini`, push the encoded value `2 * x - mini` and update `mini`.
  - Otherwise, push `x` directly.

---

### Time Complexity:
- **Push Operation**: O(1) because we are simply pushing a value to the stack.
- **Pop Operation**: O(1) because we pop an element and, if necessary, update the minimum in constant time.
- **Top Operation**: O(1) because we only need to check the top element.
- **GetMin Operation**: O(1) because we store the minimum value and can return it in constant time.

### Space Complexity:
- **Space Complexity**: O(n), where `n` is the number of elements in the stack.
