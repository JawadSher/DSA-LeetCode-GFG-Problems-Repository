<h1 align='center'>Implement - Two - Stacks - In an - Array</h1>

## Problem Statement

**Problem URL :** [Implement Two Stacks in an Array](https://www.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1)

![image](https://github.com/user-attachments/assets/44c55363-c230-4f01-aa03-b55bdb23917d)
![image](https://github.com/user-attachments/assets/0791cbb6-4444-4ba7-9637-87d081d0ddd0)
![image](https://github.com/user-attachments/assets/5df31819-364d-4114-bdc0-a61feec29c95)
![image](https://github.com/user-attachments/assets/cc1d18f1-0503-45d6-a56d-f9195ed343ce)

## Problem Explanation
The goal of this problem is to **implement two stacks using a single array**. Each stack should support the standard operations like `push()` and `pop()`.

- You are given a fixed-size array, and you must maintain two independent stacks within this array.
- You must implement the following operations:
  1. **push1(x)**: Push an integer `x` onto stack 1.
  2. **push2(x)**: Push an integer `x` onto stack 2.
  3. **pop1()**: Pop and return the top element from stack 1. Return `-1` if stack 1 is empty.
  4. **pop2()**: Pop and return the top element from stack 2. Return `-1` if stack 2 is empty.

### Approach to Solve the Problem

1. **Intuition**:
   - Typically, when you implement a stack, you use an array where one end of the array is designated as the "top" of the stack.
   - The challenge here is to manage **two stacks** within **one array** such that both can operate independently without overlapping.

2. **Optimized Approach**:
   - Instead of splitting the array in half (which might lead to wasted space), we can start one stack from the **beginning of the array** (let's call it stack1), and the other stack from the **end of the array** (stack2). Stack1 grows towards the right (increasing index), and stack2 grows towards the left (decreasing index).
   - This ensures that the two stacks will only overlap if they fill the entire array.

3. **How Beginners Can Think**:
   - Visualize the array as a line:
     - Stack 1 starts at index 0 and grows towards the middle.
     - Stack 2 starts at the last index and grows towards the middle.
   - As long as the two stacks do not overlap, you can push more elements into both stacks.
   - When you perform a `pop()` operation, ensure that the top of each stack is tracked separately.

## Problem Solution
```cpp
class twoStacks {
  public:
    int *arr;
    int top1;
    int top2;
    int size;
    
    twoStacks(int size = 100) {
        this -> size = size;
        top1 = -1;
        top2 = size;
        arr = new int[size];
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        if(top2 - top1 > 1){
            top1++;
            arr[top1] = x;
        }else{
            return;
        }
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        if(top2 - top1 > 1){
            top2--;
            arr[top2] = x;
        }else{
            return;
        }
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        if(top1 >= 0){
            int ans = arr[top1];
            top1--;
            return ans;
        }else{
            return -1;
        }
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        if(top2 < size){
            int ans = arr[top2];
            top2++;
            return ans;
        }else{
            return -1;
        }
    }
};
```

## Problem Solution Explanation

```cpp
class twoStacks {
  public:
    int *arr;        // Dynamically allocated array to store elements of both stacks
    int top1;        // Top pointer for stack1
    int top2;        // Top pointer for stack2
    int size;        // Size of the array

    // Constructor to initialize the array and top pointers
    twoStacks(int size = 100) {
        this -> size = size;      // Set the size of the array
        top1 = -1;                // Initialize top1 to -1 (stack1 is empty)
        top2 = size;              // Initialize top2 to the last index of the array
        arr = new int[size];      // Dynamically allocate memory for the array
    }
```

- The class `twoStacks` contains:
  - **arr**: A dynamically allocated array to store the elements of both stacks.
  - **top1**: The index of the top element in stack1 (starts at -1 because stack1 is initially empty).
  - **top2**: The index of the top element in stack2 (starts at `size`, which is the last index of the array).
  - **size**: The size of the array (default is 100).
  
- In the constructor, the `size` of the array is set, and memory is allocated using `new`.

---

### Push Operations

```cpp
    // Function to push an integer into stack1
    void push1(int x) {
        if(top2 - top1 > 1){        // Ensure there's space between top1 and top2
            top1++;                 // Increment top1 (moving to the right)
            arr[top1] = x;          // Insert the element into the array at top1
        }else{
            return;                 // No space left for stack1
        }
    }
```

- **`push1(int x)`** pushes an element `x` into stack1.
  - **Check for space**: If the distance between `top1` and `top2` is more than 1, it means there's space to push an element.
  - **Increment `top1`**: The index of the top element in stack1 is incremented to the right.
  - **Insert element**: The new element is placed in the array at the updated `top1`.

```cpp
    // Function to push an integer into stack2
    void push2(int x) {
        if(top2 - top1 > 1){        // Ensure there's space between top1 and top2
            top2--;                 // Decrement top2 (moving to the left)
            arr[top2] = x;          // Insert the element into the array at top2
        }else{
            return;                 // No space left for stack2
        }
    }
```

- **`push2(int x)`** pushes an element `x` into stack2.
  - **Check for space**: Similar to `push1`, check if there’s space between `top1` and `top2`.
  - **Decrement `top2`**: The index of the top element in stack2 is decremented to the left.
  - **Insert element**: The new element is placed in the array at the updated `top2`.

---

### Pop Operations

```cpp
    // Function to remove an element from top of stack1
    int pop1() {
        if(top1 >= 0){              // If stack1 is not empty
            int ans = arr[top1];    // Get the top element from stack1
            top1--;                 // Decrement top1 (remove the top element)
            return ans;             // Return the popped element
        }else{
            return -1;              // Stack1 is empty
        }
    }
```

- **`pop1()`** removes and returns the top element from stack1.
  - **Check if stack1 is not empty**: `top1` should be greater than or equal to 0.
  - **Retrieve and remove the element**: Store the element at `top1`, decrement `top1`, and return the value.

```cpp
    // Function to remove an element from top of stack2
    int pop2() {
        if(top2 < size){            // If stack2 is not empty
            int ans = arr[top2];    // Get the top element from stack2
            top2++;                 // Increment top2 (remove the top element)
            return ans;             // Return the popped element
        }else{
            return -1;              // Stack2 is empty
        }
    }
```

- **`pop2()`** removes and returns the top element from stack2.
  - **Check if stack2 is not empty**: `top2` should be less than the size of the array.
  - **Retrieve and remove the element**: Store the element at `top2`, increment `top2`, and return the value.

---

### Example

1. **Push Elements into Both Stacks**:
   - Initially, `top1 = -1` and `top2 = size` (say 100).
   - Push 5 into stack1: `top1` becomes 0, and `arr[0] = 5`.
   - Push 10 into stack2: `top2` becomes 99, and `arr[99] = 10`.

   The array will look like:
   ```
   [5, _, _, ..., 10]
   ```

2. **Pop Elements**:
   - Pop from stack1: `top1` becomes -1, and the element 5 is returned.
   - Pop from stack2: `top2` becomes 100, and the element 10 is returned.

---

### Time and Space Complexity

- **Time Complexity**: 
  - `push1()`, `push2()`, `pop1()`, and `pop2()` all run in **O(1)** time. Each operation involves constant-time updates to the array and indices.
  
- **Space Complexity**:
  - The space complexity is **O(n)**, where `n` is the size of the array used to store elements of both stacks. Each element occupies a single array cell, and two pointers (`top1` and `top2`) track the tops of the stacks.
