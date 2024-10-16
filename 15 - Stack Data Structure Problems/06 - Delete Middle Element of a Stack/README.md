<h1 align='center'>Delete - Middle - Element - Of a - Stack</h1>

## Problem Statement

**Problem URL :** [Delete Middle Element of a Stack](https://www.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1)

![image](https://github.com/user-attachments/assets/ea97d15a-9692-4a01-b19a-bf30f6dc80c6)

## Problem Explanation

You are given a stack of integers, and the goal is to **delete the middle element** from the stack without using any additional data structures (like arrays or queues). After deleting the middle element, the remaining elements should maintain their order.

### Beginner Approach and Thought Process

A beginner can approach this problem step by step:
1. **Understand the Stack's Behavior**: A stack follows the **LIFO (Last In, First Out)** principle, which means that the element that was last pushed into the stack is the first to be removed. To delete the middle element, we need to carefully manipulate the stack without violating this property.
2. **Recursion for Backtracking**: To remove the middle element, we can use recursion to reach the middle of the stack, pop the middle element, and then put the elements back in the same order.
3. **Recursion Depth**: The key idea is to recursively pop elements from the stack until we reach the middle element, delete it, and then push the previously popped elements back onto the stack.

## Problem Solution
```cpp
class Solution {
  private:
    void helper(stack<int>& inputStack, int count, int size){
        // base case
        if(count == size/2){
            inputStack.pop();
            return;
        }
        
        int storeNum = inputStack.top();
        inputStack.pop();
        
        helper(inputStack, count+1, size);
        
        inputStack.push(storeNum);
        
    }
  public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& inputStack, int size) {
        int count = 0;
        
        
        return helper(inputStack, count, size);
        
    }
};
```

## Problem Solution Explanation
```cpp
class Solution {
  private:
    void helper(stack<int>& inputStack, int count, int size){
        // base case
        if(count == size/2){
            inputStack.pop();
            return;
        }
```

- `helper(stack<int>& inputStack, int count, int size)`: This is a helper function that is used to recursively delete the middle element. It takes three arguments:
  - `inputStack`: The stack from which we want to delete the middle element.
  - `count`: Keeps track of the number of elements we've popped so far.
  - `size`: The total size of the stack, which helps to calculate the middle position.

- **Base Case**: 
  - `if(count == size / 2)`: When `count` reaches `size / 2`, this means we've reached the middle element of the stack. At this point, we want to remove it.
  - `inputStack.pop()`: Pops (removes) the middle element from the stack.
  - `return`: After removing the middle element, the recursion terminates.

```cpp
        int storeNum = inputStack.top();
        inputStack.pop();
```

- `int storeNum = inputStack.top();`: This retrieves the top element of the stack and stores it in the variable `storeNum`.
- `inputStack.pop();`: Pops the top element from the stack. This is done temporarily as we will push it back after removing the middle element.

Example:
- If the stack is `[5, 3, 8, 1, 4]` and we are trying to delete the middle element (`8`), we need to first pop elements `4` and `1` before we reach the middle.

```cpp
        helper(inputStack, count+1, size);
```

- `helper(inputStack, count + 1, size)`: This is the recursive call that goes deeper into the stack by increasing the `count`. It pops the next element, effectively moving towards the middle.

Example:
- The recursion continues until we reach the middle element (count == size / 2).

```cpp
        inputStack.push(storeNum);
```

- `inputStack.push(storeNum);`: After the middle element is removed, this line pushes the previously popped elements back onto the stack. This ensures that the elements maintain their original order.

Example:
- After popping and removing the middle element, the recursive function pushes back the elements that were popped earlier (i.e., `1` and `4`).

---

```cpp
  public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& inputStack, int size) {
        int count = 0;
        
        return helper(inputStack, count, size);
    }
};
```

- **Public Function**: `deleteMid(stack<int>& inputStack, int size)`: This is the main function that is called to delete the middle element. It initializes the `count` to `0` and calls the helper function to start the process.
  
- `helper(inputStack, count, size)`: The recursive helper function is invoked here to perform the actual deletion of the middle element.

---

### Example Walkthrough:

#### Example 1:
**Input**: Stack = `[1, 2, 3, 4, 5]`  
Middle Element = `3`

**Steps**:
- First, pop `5` and `4` and store them temporarily.
- Now, the top of the stack is `3`, which is the middle element. Pop and remove it.
- Push `4` and `5` back to maintain the original order of the remaining elements.

**Output**: Stack after deleting middle element = `[1, 2, 4, 5]`

---

#### Example 2:
**Input**: Stack = `[10, 20, 30, 40, 50, 60]`  
Middle Element = `30`

**Steps**:
- First, pop `60`, `50`, and `40`.
- Now, the top of the stack is `30`, which is the middle element. Pop and remove it.
- Push `40`, `50`, and `60` back to maintain the original order of the remaining elements.

**Output**: Stack after deleting middle element = `[10, 20, 40, 50, 60]`

---

### Time Complexity:

- Each recursive call removes one element from the stack until the middle is reached, which takes \(O(N / 2)\) steps, where \(N\) is the size of the stack.
- After removing the middle element, the function restores the previously popped elements back into the stack, which also takes \(O(N / 2)\).
- Hence, the overall **time complexity** is \(O(N)\), where \(N\) is the size of the stack.

### Space Complexity:

- The recursion stack will have depth \(N / 2\) in the worst case, which makes the **space complexity** \(O(N)\), where \(N\) is the size of the input stack.

---

### Summary:
This approach efficiently deletes the middle element of a stack using recursion. By temporarily removing elements, reaching the middle, and then restoring the original order, it ensures the problem is solved without using extra space for additional data structures. The time and space complexity of the solution is both \(O(N)\).
