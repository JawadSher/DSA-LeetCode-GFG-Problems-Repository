<h1 align='center'>Sort - A - Stack</h1>

## Problem Statement

**Problem URL :** [Sort a Stack](https://www.geeksforgeeks.org/problems/sort-a-stack/1)

![image](https://github.com/user-attachments/assets/600be5b0-b08f-4d29-a74f-91a027c46db2)

## Problem Explanation
You are given a stack of integers, and your task is to sort the stack in **ascending order** using **recursion**. You cannot use any additional data structures like arrays or another stack for sorting.

---

### Example

- **Input**: Stack `s = [3, 1, 2]` (top is `2`)
- **Output**: Sorted Stack `s = [1, 2, 3]` (top is `3`)

---

### Approach

The problem is about sorting a stack without using extra space. The main idea here is to recursively pop elements from the stack until it's empty, sort the remaining stack, and then insert the popped elements back in their correct position using another recursive function called `sortedInsertion`.

#### Steps:
1. **Base Case**: If the stack is empty, return.
2. **Recursive Step**: Pop the top element, recursively sort the remaining stack, and then insert the popped element into the sorted stack at its correct position using the `sortedInsertion` function.

---

## Problem Solution
```cpp
void sortedInsertion(stack<int> &st, int num){
    if(st.empty() || st.top() <= num){
        st.push(num);
        return;
    }
    
    int preserveNum = st.top();
    st.pop();
    
    sortedInsertion(st, num);
    
    st.push(preserveNum);
}

void SortedStack :: sort() {
    if(s.empty()) return;
    
    int preserveNum = s.top();
    s.pop();
    
    sort();
    
    sortedInsertion(s, preserveNum);
}

```

## Problem Solution Explanation

The solution consists of two functions:
1. `sortedInsertion`: This helper function inserts an element into a sorted stack.
2. `sort`: The main function that sorts the stack using recursion.

---

### Helper Function: `sortedInsertion`

```cpp
void sortedInsertion(stack<int> &st, int num) {
```

This function takes a reference to the stack `st` and an integer `num`. Its task is to insert `num` in such a way that the stack remains sorted in **ascending order**.

---

### Step 1: Base Case – Insert When the Stack is Empty or `num` is Greater Than the Top Element

```cpp
if(st.empty() || st.top() <= num) {
    st.push(num);
    return;
}
```

If the stack is **empty** or the top element is **less than or equal** to `num`, it means `num` is in the correct position to be pushed onto the stack. So, we **push** `num` and return.

- **Example 1**:
    - Input: `st = [1, 2]`, `num = 3`.
    - Since the top element (`2`) is less than or equal to `3`, we push `3` → Stack becomes `[1, 2, 3]`.

---

### Step 2: Recursive Call – Temporarily Remove the Top Element

```cpp
int preserveNum = st.top();
st.pop();
```

If `num` is smaller than the top element, we **store** the top element in `preserveNum` and **pop** it, which allows us to insert `num` into the stack in the correct position.

- **Example 2**:
    - Input: `st = [2, 3]`, `num = 1`.
    - The top element is `3`, which is greater than `1`. We store `preserveNum = 3` and pop it → Stack becomes `[2]`.

---

### Step 3: Recursive Insertion into the Stack

```cpp
sortedInsertion(st, num);
```

We recursively call `sortedInsertion` to insert `num` into the correct position in the stack.

- **Example 2 (continued)**:
    - After popping `3`, we call `sortedInsertion([2], 1)`.
    - The top element is `2`, which is greater than `1`. We pop `2`, then call `sortedInsertion([], 1)`.
    - Stack is empty, so we push `1` → Stack becomes `[1]`.

---

### Step 4: Reinsert the Popped Elements

```cpp
st.push(preserveNum);
```

Once `num` is inserted at the correct position, we **push** back the previously popped elements in reverse order, maintaining the original order above `num`.

- **Example 2 (continued)**:
    - After pushing `1`, we push back `2` → Stack: `[1, 2]`.
    - Then, we push back `3` → Stack: `[1, 2, 3]`.

---

### Main Function: `sort`

```cpp
void SortedStack::sort() {
```

The `sort` function is the main function that sorts the stack recursively. It takes a reference to the stack `s`.

---

### Step 1: Base Case – Stop When the Stack is Empty

```cpp
if(s.empty()) return;
```

If the stack is **empty**, we return. This serves as the base case to stop the recursion.

- **Example**:
    - Input: `s = []`.
    - Output: Nothing happens, the function just returns.

---

### Step 2: Recursive Call – Temporarily Remove the Top Element

```cpp
int preserveNum = s.top();
s.pop();
```

We **pop** the top element from the stack and store it in `preserveNum`. This allows us to sort the remaining stack first.

- **Example**:
    - Input: `s = [3, 1, 2]`.
    - We store `preserveNum = 2` and pop it → Stack becomes `[3, 1]`.

---

### Step 3: Recursively Sort the Remaining Stack

```cpp
sort();
```

We recursively call `sort()` to sort the remaining elements of the stack.

- **Example (continued)**:
    - After popping `2`, we call `sort([3, 1])`.
    - After popping `1`, we call `sort([3])`.
    - Finally, after popping `3`, we call `sort([])` (stack is empty now).

---

### Step 4: Insert the Popped Element in the Sorted Stack

```cpp
sortedInsertion(s, preserveNum);
```

After sorting the remaining stack, we **insert** the previously popped element (`preserveNum`) back into the sorted stack using the helper function `sortedInsertion`.

- **Example (continued)**:
    - Once the stack is sorted, we insert the elements in reverse order.
    - Insert `1` → Stack: `[1]`.
    - Insert `2` → Stack: `[1, 2]`.
    - Insert `3` → Stack: `[1, 2, 3]`.

---

### Example Execution

#### Example 1: `s = [3, 1, 2]`

1. Start with `s = [3, 1, 2]` (top is `2`).
2. Pop `2` and recursively call `sort([3, 1])`.
3. Pop `1` and recursively call `sort([3])`.
4. Pop `3` and recursively call `sort([])` (stack is empty now).
5. Stack is empty, so return.
6. Insert `3` → Stack: `[3]`.
7. Insert `1` into `[3]` → Stack: `[1, 3]`.
8. Insert `2` into `[1, 3]` → Stack: `[1, 2, 3]`.

---

### Time and Space Complexity

1. **Time Complexity: O(n²)**:
   - The `sort` function is called for each element in the stack, and for each element, the `sortedInsertion` function may traverse the stack to find the correct position, leading to a quadratic time complexity.

2. **Space Complexity: O(n)**:
   - The space complexity is `O(n)` due to the recursive stack calls. For each element, we push and pop it during the recursion, so the depth of recursion is `n`.

---

This solution sorts a stack using recursion without using any extra data structures, except for the call stack used during recursion. The process involves popping elements, recursively sorting, and inserting elements back into the stack in sorted order.
