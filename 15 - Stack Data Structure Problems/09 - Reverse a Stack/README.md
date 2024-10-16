<h1 align='center'>Reverse - A - Stack</h1>

## Problem Statement

**Problem URL :** [Reverse a Stack](https://www.geeksforgeeks.org/problems/reverse-a-stack/1)

![image](https://github.com/user-attachments/assets/4bd601d1-827d-4f4b-acd8-811501749b11)
![image](https://github.com/user-attachments/assets/ce18b280-6f55-48aa-9637-6eb8d8f7147c)

## Problem Explanation

You are given a stack of integers, and your task is to reverse the stack such that the top element becomes the bottom-most element, and the bottom-most element becomes the top-most element.

### Example

- **Input**: Stack `st = [3, 2, 1]` (top is `1`)
- **Output**: Stack after reversal `st = [1, 2, 3]` (top is `3`)


### Approach

To reverse a stack, you cannot use extra space like another stack or array. Instead, you can solve the problem using **recursion**. 

The idea is to:
1. Recursively pop all elements of the stack.
2. Once the stack is empty, insert each element back at the **bottom** of the stack.

#### Steps:
1. **Base Case**: If the stack is empty, return. The stack is already reversed.
2. **Recursive Step**: Pop the top element, reverse the remaining stack recursively, and insert the popped element at the bottom of the reversed stack.

## Problem Solution
```cpp
class Solution{
private:
    void insertAtBottom(stack<int> &st, int num){
        if(st.empty()){
            st.push(num);
            return;
        }
        
        int preserveNum = st.top();
        st.pop();
        
        insertAtBottom(st, num);
        
        st.push(preserveNum);
        
    }
public:
    void Reverse(stack<int> &st){
        // base case
        if(st.empty()){
            return;
        }
        
        int preserveNum = st.top();
        st.pop();
        
        Reverse(st);
        
        insertAtBottom(st, preserveNum);
    }
};
```

## Problem Solution Explanation

The class `Solution` has two methods:
1. `insertAtBottom`: Helper function to insert an element at the bottom of the stack.
2. `Reverse`: The main function that reverses the stack recursively.

---

### Helper Function: `insertAtBottom`

```cpp
private:
    void insertAtBottom(stack<int> &st, int num) {
```

This function takes a reference to the stack `st` and an integer `num`. Its task is to insert `num` at the **bottom** of the stack.

---

### Step 1: Base Case – Insert when Stack is Empty

```cpp
if (st.empty()) {
    st.push(num);
    return;
}
```

If the stack is **empty**, it means we've reached the bottom. We simply **push** `num` onto the stack and return.

- **Example 1**: 
    - Input: `st = []`, `num = 4`.
    - Stack is empty, so push `4` → Stack: `[4]`.

---

### Step 2: Recursive Call – Temporarily Remove the Top Element

```cpp
int preserveNum = st.top();
st.pop();
```

If the stack is not empty, we **store** the top element in `preserveNum` and **pop** it. This helps us make space to insert `num` at the bottom.

- **Example 2**:
    - Input: `st = [3, 2]`, `num = 4`.
    - Top element is `2`. We store `preserveNum = 2` and pop it, so the stack becomes `st = [3]`.

---

### Step 3: Recursive Insertion at the Bottom

```cpp
insertAtBottom(st, num);
```

We recursively call `insertAtBottom` to continue popping elements and inserting `num` at the bottom. This continues until the stack is empty.

- **Example 2 (continued)**:
    - After popping `2`, we call `insertAtBottom(st = [3], 4)`.
    - After popping `3`, we call `insertAtBottom(st = [], 4)`.
    - Stack is empty, so we push `4`.

---

### Step 4: Reinsert the Popped Elements

```cpp
st.push(preserveNum);
```

Once `num` is inserted at the bottom, we **push** back the previously popped elements in reverse order, maintaining the original order.

- **Example 2 (continued)**:
    - After pushing `4`, we push back `3` → Stack: `[4, 3]`.
    - Then, we push back `2` → Stack: `[4, 3, 2]`.

---

### Step 5: No Return (void function)

```cpp
// The insertAtBottom function does not return any value.
```

---

### Main Function: `Reverse`

```cpp
public:
    void Reverse(stack<int> &st) {
```

The `Reverse` function is the main function that reverses the stack using recursion. It takes a reference to the stack `st`.

---

### Step 1: Base Case – Stop when the Stack is Empty

```cpp
if (st.empty()) {
    return;
}
```

If the stack is empty, we have finished the reversal process, so we return.

- **Example**: 
    - Input: `st = []`.
    - Output: Nothing happens, the function just returns.

---

### Step 2: Recursive Call – Temporarily Remove the Top Element

```cpp
int preserveNum = st.top();
st.pop();
```

We **pop** the top element from the stack and store it in `preserveNum`. This allows us to reverse the remaining stack first.

- **Example**:
    - Input: `st = [3, 2, 1]` (top is `1`).
    - We store `preserveNum = 1` and pop it → Stack becomes `[3, 2]`.

---

### Step 3: Recursively Reverse the Remaining Stack

```cpp
Reverse(st);
```

We recursively call `Reverse(st)` to reverse the remaining elements of the stack.

- **Example (continued)**:
    - After popping `1`, we call `Reverse([3, 2])`.
    - Then, after popping `2`, we call `Reverse([3])`.
    - Finally, after popping `3`, we call `Reverse([])` (stack is empty now).

---

### Step 4: Insert the Popped Element at the Bottom

```cpp
insertAtBottom(st, preserveNum);
```

After reversing the remaining stack, we **insert** the previously popped element (`preserveNum`) at the **bottom** of the reversed stack.

- **Example (continued)**:
    - Once the stack is reversed (from empty to `[1]`, then `[2, 1]`, and finally `[3, 2, 1]`), we insert the elements in reverse order.
    - First, we insert `3` at the bottom, then `2`, then `1`.

### Example Execution

#### Example 1: `st = [1, 2, 3]`

1. Start with `st = [3, 2, 1]` (top is `1`).
2. Pop `1` and recursively call `Reverse([3, 2])`.
3. Pop `2` and recursively call `Reverse([3])`.
4. Pop `3` and recursively call `Reverse([])`.
5. Stack is empty, so return.
6. Insert `3` at the bottom → Stack: `[3]`.
7. Insert `2` at the bottom → Stack: `[2, 3]`.
8. Insert `1` at the bottom → Stack: `[1, 2, 3]`.

---

### Time and Space Complexity

1. **Time Complexity: O(n)**:
   - For each element in the stack (of size `n`), we perform a series of operations (pop, push, and recursion), leading to a linear time complexity.

2. **Space Complexity: O(n)**:
   - Recursion adds to the call stack for each element in the original stack. Therefore, the space complexity is `O(n)` due to the depth of recursion.

---

This solution efficiently reverses a stack using recursion and helper functions, ensuring no additional space (like another stack) is used besides the call stack for recursion.
