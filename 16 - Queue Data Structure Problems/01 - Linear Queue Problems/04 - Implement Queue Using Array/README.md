<h1 align='center'>Implement - Queue - Using - Array</h1>

## Problem Statement

**Problem URL :** [Implement Queue Using Array](https://www.geeksforgeeks.org/problems/implement-queue-using-array/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/00bdda0f-69ac-4be7-ae9d-8d3a03b55be5)
![image](https://github.com/user-attachments/assets/27850078-804d-4fef-b8ed-ba2203fd1c7f)

## Problem Explanation
In this problem, you are required to **implement a queue** data structure using **arrays**. Unlike the queue available in the C++ STL (Standard Template Library), you are asked to build a queue from scratch, which includes the following operations:

1. **push(x)**: Add element `x` to the back of the queue.
2. **pop()**: Remove and return the element at the front of the queue. If the queue is empty, return `-1`.

The queue operates on the **FIFO** (First In, First Out) principle, meaning the element that is added first will be the one that gets removed first.

### Approach:

To implement a queue using arrays, we will:
1. Use an array `arr[]` to store elements.
2. Maintain two pointers or indices:
   - `front`: Points to the front of the queue (where elements are removed).
   - `rear`: Points to the rear of the queue (where elements are added).
   
Initially, both `front` and `rear` are set to `0`.

#### Key Operations:
- **push(x)**: Adds the element `x` at the position indicated by `rear` and then increments `rear`.
- **pop()**: Returns the element at the `front` and increments the `front` pointer. If the queue is empty (i.e., `front == rear`), it returns `-1`.

### Example:
Consider implementing a queue of size 5 using an array.

1. **Initial State:**
   - Array: `[0, 0, 0, 0, 0]`
   - `front = 0`
   - `rear = 0`
   
   The queue is empty.

2. **Push Elements:**
   - `push(10)`: Add `10` at index `0` (rear) and increment `rear`.
     ```
     Array: [10, 0, 0, 0, 0]
     front = 0, rear = 1
     ```
   
   - `push(20)`: Add `20` at index `1` (rear) and increment `rear`.
     ```
     Array: [10, 20, 0, 0, 0]
     front = 0, rear = 2
     ```
   
   - `push(30)`: Add `30` at index `2` (rear) and increment `rear`.
     ```
     Array: [10, 20, 30, 0, 0]
     front = 0, rear = 3
     ```

3. **Pop Elements:**
   - `pop()`: Remove the element at index `0` (front), which is `10`. Increment `front`.
     ```
     Array: [10, 20, 30, 0, 0]
     front = 1, rear = 3
     Return 10
     ```

   - `pop()`: Remove the element at index `1` (front), which is `20`. Increment `front`.
     ```
     Array: [10, 20, 30, 0, 0]
     front = 2, rear = 3
     Return 20
     ```

4. **Queue Status:**
   After two pop operations, the remaining element in the queue is `30`, and the current status is:
   ```
   Array: [10, 20, 30, 0, 0]
   front = 2, rear = 3
   ```


## Problem Solution
```cpp
void MyQueue :: push(int x)
{
    arr[rear++] = x;
}

int MyQueue :: pop()
{
    if(front == rear) return -1;  
    return arr[front++];
}
```

## Problem Solution Explanation

Now let’s break down the provided source code based on the `push` and `pop` operations.

#### Code for `push`:

```cpp
void MyQueue :: push(int x)
{
    arr[rear++] = x;
}
```

- This method takes an integer `x` as input and adds it to the queue.
- The element `x` is placed at the `rear` index in the array `arr[]`.
- After placing the element, `rear` is incremented using `rear++`. This ensures that the next element will be added at the next available position in the array.

#### Code for `pop`:

```cpp
int MyQueue :: pop()
{
    if(front == rear) return -1;
    
    return arr[front++];
}
```

- **Condition**: `if(front == rear)` checks if the queue is empty. If `front` is equal to `rear`, it means there are no elements left in the queue. In this case, the function returns `-1` (indicating an empty queue).
- Otherwise, the element at the `front` index in the array `arr[]` is returned, and then `front` is incremented by `front++`, which moves the `front` pointer to the next element.

---

### Example Walkthrough of the Code:

Assume we have a queue with an array `arr[]` of size `5`, and we perform the following operations:

1. **Initial State:**
   ```
   arr[] = [0, 0, 0, 0, 0]
   front = 0, rear = 0
   ```

2. **Push 10:**
   - `push(10)`
   - Insert `10` at index `0` (rear = 0).
   - Increment `rear` to `1`.
   ```
   arr[] = [10, 0, 0, 0, 0]
   front = 0, rear = 1
   ```

3. **Push 20:**
   - `push(20)`
   - Insert `20` at index `1` (rear = 1).
   - Increment `rear` to `2`.
   ```
   arr[] = [10, 20, 0, 0, 0]
   front = 0, rear = 2
   ```

4. **Pop Element:**
   - `pop()`
   - Remove and return the element at index `0` (front = 0).
   - Increment `front` to `1`.
   ```
   arr[] = [10, 20, 0, 0, 0]
   front = 1, rear = 2
   Return 10
   ```

5. **Pop Element:**
   - `pop()`
   - Remove and return the element at index `1` (front = 1).
   - Increment `front` to `2`.
   ```
   arr[] = [10, 20, 0, 0, 0]
   front = 2, rear = 2
   Return 20
   ```

6. **Pop Again (Queue is Empty):**
   - `pop()`
   - Now `front == rear` (both are `2`), which means the queue is empty.
   - Return `-1` to indicate the queue is empty.

---

### Time Complexity:

- **Push Operation**: O(1)
  - The `push` operation just inserts an element at the rear of the queue and increments the `rear` index, so it takes constant time.

- **Pop Operation**: O(1)
  - The `pop` operation only removes the element at the `front` index and increments the `front`, so it also takes constant time.

### Space Complexity:

- The space complexity is **O(N)**, where `N` is the size of the array `arr[]`. We need an array of size `N` to store the queue elements.

---

### Summary:

In this solution, we implement a queue using an array. The `push` operation adds elements at the rear, while the `pop` operation removes elements from the front. If the queue is empty, the `pop` function returns `-1`. The queue operations are efficient, with constant time complexity for both `push` and `pop`.
