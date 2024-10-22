<h1 align='center'>Design - Circular - Queue</h1>

## Problem Statement

**Problem URL :** [Design Circular Queue](https://leetcode.com/problems/design-circular-queue/)

![image](https://github.com/user-attachments/assets/70ff8622-03da-4a52-aa53-7e4ad9525e66)
![image](https://github.com/user-attachments/assets/4f8a10cd-2080-4b41-ba64-982d21c6b787)

## Problem Explanation
The goal of this problem is to design and implement a circular queue data structure, which supports the following operations:

1. **`MyCircularQueue(int k)`**: Initializes the circular queue with a maximum size of `k`.
2. **`bool enQueue(int value)`**: Adds an item to the rear of the queue. Returns `true` if the operation is successful, or `false` if the queue is full.
3. **`bool deQueue()`**: Removes an item from the front of the queue. Returns `true` if the operation is successful, or `false` if the queue is empty.
4. **`int Front()`**: Gets the front item from the queue. If the queue is empty, return `-1`.
5. **`int Rear()`**: Gets the last item from the queue. If the queue is empty, return `-1`.
6. **`bool isEmpty()`**: Checks whether the circular queue is empty or not.
7. **`bool isFull()`**: Checks whether the circular queue is full or not.

### Approach
1. **Initialization**: 
   - Use an array to store the elements of the queue. Keep track of the `front` and `rear` indices to indicate the first and last elements in the queue.
   - Set `front` and `rear` to `-1` initially to indicate that the queue is empty.

2. **Enqueue Operation**:
   - Check if the queue is full. If it is, return `false`.
   - If the queue is empty (`front == -1`), set both `front` and `rear` to `0`.
   - If the `rear` reaches the end of the array and there are still available spaces (i.e., the `front` is not at index `0`), wrap around by setting `rear` to `0`.
   - Otherwise, increment the `rear` index and add the new element at that position.

3. **Dequeue Operation**:
   - Check if the queue is empty. If it is, return `false`.
   - Remove the element at the `front` index.
   - If the queue becomes empty after this operation, reset `front` and `rear` to `-1`.
   - If the `front` reaches the end of the array, wrap around by setting `front` to `0`. Otherwise, increment `front`.

4. **Accessors and Utility Functions**:
   - Implement functions to get the `front` and `rear` elements, check if the queue is empty or full.

### Example
- **Initialization**: Create a circular queue with a size of 3.
  ```cpp
  MyCircularQueue* queue = new MyCircularQueue(3);
  ```
- **Enqueue Operations**:
  - `queue->enQueue(1)` → Returns `true`, queue: `[1]`
  - `queue->enQueue(2)` → Returns `true`, queue: `[1, 2]`
  - `queue->enQueue(3)` → Returns `true`, queue: `[1, 2, 3]`
  - `queue->enQueue(4)` → Returns `false` (queue is full)
- **Dequeue Operation**:
  - `queue->deQueue()` → Returns `true`, queue: `[2, 3]`
- **Access Front and Rear**:
  - `queue->Front()` → Returns `2`
  - `queue->Rear()` → Returns `3`
- **Check Full and Empty**:
  - `queue->isFull()` → Returns `false`
  - `queue->isEmpty()` → Returns `false`

## Problem Solution
```cpp
class MyCircularQueue {
public:
    int *arr;
    int size;
    int front;
    int rear;

    MyCircularQueue(int k) {
        this -> size = k;
        arr = new int[size];
        front = -1;
        rear = -1;    
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;

        if(front == -1){
            front = rear = 0;
        }else if(rear == size -1 && front != 0){
            rear = 0;
        }else{
            rear ++;
        }

        arr[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;

        arr[front] = -1;
        if(front == rear){
            front = rear = -1;
        }else if(front == size - 1){
            front = 0;
        }else{
            front++;
        }

        return true;
    }
    
    int Front() {
        if(front == -1) return -1;

        return arr[front];
    }
    
    int Rear() {
        if(rear == -1) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return (front == 0 && rear == size - 1) || (rear == (front -1) % size);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
```

## Problem Solution Explanation
Let’s break down each function of the `MyCircularQueue` class separately, explaining their purposes, how they work, and including examples where applicable.

### 1. Constructor: `MyCircularQueue(int k)`
```cpp
MyCircularQueue(int k) {
    this->size = k;           // Initialize the size of the queue
    arr = new int[size];      // Dynamically allocate memory for the queue
    front = -1;               // Initialize front and rear as -1 (indicating the queue is empty)
    rear = -1;    
}
```
- **Purpose**: Initializes a circular queue with a maximum size of `k`.
- **How It Works**:
  - Allocates an array of integers of size `k` to hold the queue elements.
  - Sets both `front` and `rear` to `-1` to indicate that the queue is empty.
- **Example**: 
  ```cpp
  MyCircularQueue* queue = new MyCircularQueue(3); // Creates a circular queue of size 3
  ```

---

### 2. Function: `bool enQueue(int value)`
```cpp
bool enQueue(int value) {
    if(isFull()) return false;    // Check if the queue is full

    if(front == -1){               // If the queue is empty
        front = rear = 0;          // Set front and rear to 0
    } else if(rear == size - 1 && front != 0){ // If rear is at the end of the array
        rear = 0;                  // Wrap around to the start
    } else {
        rear++;                    // Increment the rear index
    }

    arr[rear] = value;            // Insert the new value at the rear position
    return true;                  // Operation successful
}
```
- **Purpose**: Adds an item to the rear of the queue.
- **How It Works**:
  - First, it checks if the queue is full using the `isFull()` function.
  - If the queue is empty, it initializes both `front` and `rear` to `0`.
  - If the `rear` has reached the end of the array and there are still available spaces, it wraps around to `0`.
  - If there is still space, it increments the `rear` and adds the value.
- **Example**:
  ```cpp
  queue->enQueue(1); // Returns true, queue: [1]
  queue->enQueue(2); // Returns true, queue: [1, 2]
  queue->enQueue(3); // Returns true, queue: [1, 2, 3]
  queue->enQueue(4); // Returns false (queue is full)
  ```

---

### 3. Function: `bool deQueue()`
```cpp
bool deQueue() {
    if(isEmpty()) return false;    // Check if the queue is empty

    arr[front] = -1;                // Optional: Mark the dequeued element as -1
    if(front == rear){              // If the queue becomes empty after this operation
        front = rear = -1;          // Reset front and rear
    } else if(front == size - 1){   // If front is at the end of the array
        front = 0;                  // Wrap around to the start
    } else {
        front++;                    // Increment the front index
    }

    return true;                   // Operation successful
}
```
- **Purpose**: Removes an item from the front of the queue.
- **How It Works**:
  - It first checks if the queue is empty using the `isEmpty()` function.
  - If the queue is not empty, it optionally marks the dequeued element as `-1`.
  - If the `front` index equals the `rear`, it indicates the queue is now empty, so both are reset to `-1`.
  - If the `front` is at the end of the array, it wraps around to `0`.
  - Otherwise, it increments the `front` index.
- **Example**:
  ```cpp
  queue->deQueue(); // Returns true, queue: [2, 3]
  ```

---

### 4. Function: `int Front()`
```cpp
int Front() {
    if(front == -1) return -1;      // Check if the queue is empty
    return arr[front];              // Return the front element
}
```
- **Purpose**: Gets the front item from the queue.
- **How It Works**:
  - It checks if the queue is empty. If it is, it returns `-1`.
  - If not, it returns the value at the `front` index.
- **Example**:
  ```cpp
  int frontValue = queue->Front(); // Returns 2 (the current front element)
  ```

---

### 5. Function: `int Rear()`
```cpp
int Rear() {
    if(rear == -1) return -1;       // Check if the queue is empty
    return arr[rear];               // Return the rear element
}
```
- **Purpose**: Gets the last item from the queue.
- **How It Works**:
  - It checks if the queue is empty. If it is, it returns `-1`.
  - If not, it returns the value at the `rear` index.
- **Example**:
  ```cpp
  int rearValue = queue->Rear(); // Returns 3 (the current rear element)
  ```

---

### 6. Function: `bool isEmpty()`
```cpp
bool isEmpty() {
    return front == -1;            // Returns true if front is -1 (queue is empty)
}
```
- **Purpose**: Checks whether the circular queue is empty.
- **How It Works**:
  - It checks if `front` is `-1`. If so, it indicates that the queue is empty and returns `true`.
- **Example**:
  ```cpp
  bool emptyStatus = queue->isEmpty(); // Returns false
  ```

---

### 7. Function: `bool isFull()`
```cpp
bool isFull() {
    return (front == 0 && rear == size - 1) || (rear == (front - 1) % size); // Returns true if full
}
```
- **Purpose**: Checks whether the circular queue is full.
- **How It Works**:
  - It checks two conditions:
    1. If `front` is `0` and `rear` is at the last index.
    2. If `rear` is the index before `front` (considering wrap-around).
  - If either condition is true, it returns `true`, indicating the queue is full.
- **Example**:
  ```cpp
  bool fullStatus = queue->isFull(); // Returns false (after enQueue operations)
  ```

---

### Summary of Operations
- **Initialization**: `MyCircularQueue* queue = new MyCircularQueue(3);`
- **Enqueue**: 
  - `queue->enQueue(1); // true`
  - `queue->enQueue(2); // true`
  - `queue->enQueue(3); // true`
  - `queue->enQueue(4); // false (full)`
- **Dequeue**: 
  - `queue->deQueue(); // true`
  - `queue->Front(); // returns 2`
  - `queue->Rear(); // returns 3`
- **Status Check**:
  - `queue->isEmpty(); // false`
  - `queue->isFull(); // false`

### Complexity Analysis
- **Time Complexity**:
  - **`enQueue`**: O(1) - Constant time for adding an element.
  - **`deQueue`**: O(1) - Constant time for removing an element.
  - **`Front`, `Rear`, `isEmpty`, `isFull`**: O(1) - All these checks are done in constant time.

- **Space Complexity**:
  - O(k) - The space required for the queue is proportional to its size `k`, since it uses an array of size `k` to store the elements.
