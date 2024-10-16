<h1 align='center'>Insert - An - Element - at The - Bottom - of A - Stack</h1>

## Problem Statement

**Problem URL :** [Insert an Element at The Bottom of a Stack](https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/0)

![image](https://github.com/user-attachments/assets/ca0db270-3612-433e-ac59-86a872b26525)
![image](https://github.com/user-attachments/assets/59afb5ae-b1db-4745-8f95-6dfaadc7e9c4)

## Problem Explanation

You are given a stack `st` of integers and an integer `x`. The task is to insert the integer `x` at the **bottom** of the stack while maintaining the original order of the other elements.

### Example

- **Input**: Stack `st = [3, 2, 1]` (top is `1`), `x = 4`.
- **Output**: Stack after insertion `[4, 3, 2, 1]` (top is `1`).

---

### Approach

The challenge is to insert the element `x` at the **bottom** of the stack, but you can only use the stack operations:
1. **push()**: Insert an element at the top of the stack.
2. **pop()**: Remove the top element of the stack.
3. **top()**: Peek at the top element of the stack.
4. **empty()**: Check if the stack is empty.

Since you cannot directly insert at the bottom of the stack, we use **recursion** to reverse the stack temporarily, insert the element, and then reinsert the original elements in their correct order.

#### Steps:
1. **Base Case**: If the stack is empty, insert `x` and return.
2. **Recursive Step**: Pop the top element, recursively call the function to insert `x` at the bottom, then push the popped element back onto the stack.

## Problem Solution
```cpp
class Solution{
public:
    stack<int> insertAtBottom(stack<int>& st,int x){
        // base case
        if(st.empty()){
            st.push(x);
            return st;
        }
        
        int preserveNum = st.top();
        st.pop();
        
        insertAtBottom(st, x);
        
        st.push(preserveNum);
        
        return st;
    }
};
```

## Problem Solution Explanation

```cpp
class Solution {
public:
    stack<int> insertAtBottom(stack<int>& st, int x) {
```

This defines the class `Solution` and a function `insertAtBottom` which takes a reference to a stack `st` and an integer `x` that we need to insert at the bottom. It returns the modified stack.

---

### Step 1: Base Case – Insert when Stack is Empty

```cpp
if (st.empty()) {
    st.push(x);
    return st;
}
```

Here, we check if the stack `st` is **empty**. If it's empty, this is our base case:
- We simply **push** `x` onto the stack because it's the only element.
- Return the stack.

- **Example 1**: 
    - Input: `st = []`, `x = 4`.
    - Stack is empty, so we push `4`.
    - Output: `st = [4]`.

---

### Step 2: Recursive Call – Temporarily Remove the Top Element

```cpp
int preserveNum = st.top();
st.pop();
```

If the stack is **not empty**, we store the **top element** in a variable `preserveNum` (this element is temporarily removed so we can reach the bottom of the stack).
- Then we **pop** the top element from the stack to reduce the size of the stack and continue the recursion.

- **Example 2**:
    - Input: `st = [3, 2, 1]`, `x = 4`.
    - First top element is `1`. We store `preserveNum = 1` and pop it, so `st = [3, 2]`.

---

### Step 3: Recursive Insertion at the Bottom

```cpp
insertAtBottom(st, x);
```

We recursively call the `insertAtBottom` function with the smaller stack (after popping the top element). The recursion continues until we reach the base case, which is when the stack becomes empty. This is where `x` gets inserted at the bottom.

- **Example 2 (continued)**:
    - After popping `1`, we call `insertAtBottom(st = [3, 2], 4)`.
    - Then, `2` is popped, and we call `insertAtBottom(st = [3], 4)`.
    - Then, `3` is popped, and we call `insertAtBottom(st = [], 4)`.
    - Stack is empty, so we push `4`.

---

### Step 4: Reinsert the Popped Elements

```cpp
st.push(preserveNum);
```

After `x` is inserted at the bottom, we now **push** back the previously popped elements in reverse order, so that the original order is maintained.

- **Example 2 (continued)**:
    - After pushing `4` into the empty stack, we push back the preserved elements.
    - First, we push `3` → Stack: `[4, 3]`.
    - Then, we push `2` → Stack: `[4, 3, 2]`.
    - Finally, we push `1` → Stack: `[4, 3, 2, 1]`.

---

### Step 5: Return the Stack

```cpp
return st;
```

Finally, return the modified stack with `x` inserted at the bottom.

- **Example 2 (final)**:
    - Input: `st = [3, 2, 1]`, `x = 4`.
    - Final Output: `st = [4, 3, 2, 1]`.


### Time and Space Complexity

1. **Time Complexity: O(n)**:
   - Each recursive call processes one element of the stack, so we have `n` recursive calls if there are `n` elements in the stack. The overall time complexity is `O(n)`.

2. **Space Complexity: O(n)**:
   - Since recursion uses the call stack, the space complexity depends on the depth of the recursion, which is `n` calls deep. Hence, the space complexity is also `O(n)`.

---

### Example Execution

#### Example 1: `st = [1, 2, 3]`, `x = 4`

1. Start with `st = [3, 2, 1]` (top is `1`), `x = 4`.
2. Pop `1` and recursively call `insertAtBottom([3, 2], 4)`.
3. Pop `2` and recursively call `insertAtBottom([3], 4)`.
4. Pop `3` and recursively call `insertAtBottom([], 4)`.
5. Stack is empty, so push `4`.
6. Push `3`, `2`, and `1` back onto the stack.
7. Final stack: `[4, 3, 2, 1]`.
