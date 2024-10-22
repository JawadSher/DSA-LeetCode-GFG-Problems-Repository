<h1 align='center'>Design - Circular - Deque</h1>

## Problem Statement

**Problem URL :** [Design Cicular Deque](https://leetcode.com/problems/design-circular-deque/description/)

![image](https://github.com/user-attachments/assets/9064ac24-52ac-44cb-916f-aa009eaf41ff)
![image](https://github.com/user-attachments/assets/8f9f1473-8931-4daa-afa6-b07967e22ece)

## Problem Explanation
A **Circular Deque** (double-ended queue) is a linear data structure that allows insertion and deletion of elements from both ends. The key characteristic of a circular deque is that when the end of the deque is reached, it wraps around to the beginning. This is achieved using a fixed-size array to store elements, with two pointers (or indices) indicating the front and rear of the deque.

#### Problem Statement

Design and implement a circular deque with the following functionalities:
- **Insert an element at the front** (push_front).
- **Insert an element at the back** (push_back).
- **Delete an element from the front** (pop_front).
- **Delete an element from the back** (pop_back).
- **Get the front element** without removing it (getFront).
- **Get the rear element** without removing it (getRear).
- **Check if the deque is empty** (isEmpty).
- **Check if the deque is full** (isFull).

### Approach

1. **Data Structure**: Use a fixed-size array to hold the elements of the deque.
2. **Pointers/Indices**: Maintain two pointers:
   - `front` for the front of the deque.
   - `rear` for the rear of the deque.
3. **Circular Nature**: Use the modulus operator to wrap the indices around when they reach the boundaries of the array.
4. **Operations**:
   - **Insertions** and **Deletions** will involve checking if the deque is full or empty before proceeding.

## Problem Solution
```cpp
class MyCircularDeque {
public:
    int * arr;
    int front;
    int rear;
    int size;

    MyCircularDeque(int k) {
        this -> size = k;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;

        if(isEmpty()){
            front = rear = 0;
        }else{
            front = (front -1 + size) % size;
        }

        arr[front] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;

        if(isEmpty()){
            front = rear = 0;
        }else{
            rear = (rear + 1) % size;
        }

        arr[rear] = value;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;

        if(front == rear){
            front = rear = -1;
        }else{
            front = (front + 1) % size;
        }

        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        
        if(front == rear){
            rear = front = -1;
        }else{
            rear = (rear -1 + size) % size;
        }
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;

        return arr[front];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return ((rear + 1) % size == front);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
```

## Problem Solution Explanation
The mentioned code implements a circular deque using a class `MyCircularDeque`. Here’s a detailed breakdown of the code:

```cpp
class MyCircularDeque {
public:
    int * arr;       // Pointer to the dynamic array storing deque elements
    int front;       // Index of the front element
    int rear;        // Index of the rear element
    int size;        // Maximum size of the deque

    MyCircularDeque(int k) {
        this->size = k;               // Initialize size
        arr = new int[size];          // Create the array
        front = -1;                   // Indicate that the deque is empty
        rear = -1;                    // Indicate that the deque is empty
    }
```

1. **Constructor**: Initializes the deque with a fixed size `k`. It allocates memory for the array and sets the front and rear indices to `-1`, indicating that the deque is initially empty.

```cpp
    bool insertFront(int value) {
        if(isFull()) return false;     // Check if deque is full

        if(isEmpty()){
            front = rear = 0;          // If deque is empty, set both front and rear to 0
        } else {
            front = (front - 1 + size) % size; // Move front index to the left, wrapping around if necessary
        }

        arr[front] = value;            // Insert the new value at the front
        return true;                   // Insertion successful
    }
```

2. **insertFront()**: 
   - First, it checks if the deque is full using `isFull()`.
   - If the deque is empty, both `front` and `rear` are set to `0`.
   - Otherwise, the `front` pointer is decremented (wrapped around if it goes below `0`).
   - The new value is placed at the `front` index.
   - **Example**: For a deque of size 3, if you insert `5` then `6`, the array becomes `[6, _, 5]` (assuming insertion starts from the back).

```cpp
    bool insertLast(int value) {
        if(isFull()) return false;      // Check if deque is full

        if(isEmpty()){
            front = rear = 0;           // If deque is empty, set both front and rear to 0
        } else {
            rear = (rear + 1) % size;   // Move rear index to the right, wrapping around if necessary
        }

        arr[rear] = value;               // Insert the new value at the rear
        return true;                    // Insertion successful
    }
```

3. **insertLast()**:
   - Similar to `insertFront()`, it checks if the deque is full.
   - If empty, it sets `front` and `rear` to `0`.
   - Otherwise, it increments the `rear` index (wraps around if it exceeds `size - 1`).
   - The new value is stored at the `rear` index.
   - **Example**: Inserting `10` and `20` would place them at `[10, 20, _]` (assuming the `front` was at the second position).

```cpp
    bool deleteFront() {
        if(isEmpty()) return false;      // Check if deque is empty

        if(front == rear){                // If there's only one element
            front = rear = -1;            // Reset the deque
        } else {
            front = (front + 1) % size;   // Move front index to the right, wrapping around if necessary
        }

        return true;                    // Deletion successful
    }
```

4. **deleteFront()**:
   - Checks if the deque is empty.
   - If there’s only one element (i.e., `front == rear`), it resets both indices to `-1`.
   - Otherwise, it increments the `front` index (wraps around).
   - **Example**: If the current state is `[10, 20]` and `deleteFront()` is called, it will result in `[_, 20]`.

```cpp
    bool deleteLast() {
        if(isEmpty()) return false;      // Check if deque is empty
        
        if(front == rear){                // If there's only one element
            rear = front = -1;            // Reset the deque
        } else {
            rear = (rear -1 + size) % size; // Move rear index to the left, wrapping around if necessary
        }
        return true;                    // Deletion successful
    }
```

5. **deleteLast()**:
   - Similar logic to `deleteFront()`, but it decrements the `rear` index.
   - Resets if only one element is left.
   - **Example**: In a state of `[10, 20]`, calling `deleteLast()` will yield `[10, _]`.

```cpp
    int getFront() {
        if(isEmpty()) return -1;          // Return -1 if deque is empty

        return arr[front];                // Return the front value
    }
```

6. **getFront()**:
   - Checks if the deque is empty and returns `-1` if it is.
   - Otherwise, it returns the value at the `front` index.
   - **Example**: In the state `[10, 20]`, calling `getFront()` returns `10`.

```cpp
    int getRear() {
        if(isEmpty()) return -1;          // Return -1 if deque is empty
        return arr[rear];                 // Return the rear value
    }
```

7. **getRear()**:
   - Similar to `getFront()`, but returns the value at the `rear` index.
   - **Example**: In the state `[10, 20]`, calling `getRear()` returns `20`.

```cpp
    bool isEmpty() {
        return front == -1;               // Return true if deque is empty
    }
    
    bool isFull() {
        return ((rear + 1) % size == front); // Check if deque is full
    }
};
```

8. **isEmpty()**: Returns `true` if the deque is empty (both pointers are `-1`).

9. **isFull()**: Returns `true` if the next position of `rear` would be `front`, indicating that the deque cannot accept any more elements.

### Examples of Operations

1. **Creating a Deque**:
   - `MyCircularDeque* obj = new MyCircularDeque(3);` creates a deque with a capacity of 3.

2. **Inserting Values**:
   - `obj->insertLast(1);` → Returns `true`, deque: `[1, _, _]`
   - `obj->insertLast(2);` → Returns `true`, deque: `[1, 2, _]`
   - `obj->insertFront(3);` → Returns `true`, deque: `[3, 1, 2]`
   - `obj->insertFront(4);` → Returns `false` (deque is full), remains `[3, 1, 2]`

3. **Getting Values**:
   - `obj->getFront();` → Returns `3`
   - `obj->getRear();` → Returns `2`

4. **Deleting Values**:
   - `obj->deleteLast();` → Returns `true`, deque: `[3, 1, _]`
   - `obj->deleteFront();` → Returns `true`, deque: `[_, 1, _]`

### Complexity Analysis

1. **Time Complexity**:
   - **Insertions** (insertFront and insertLast): O(1) — Both operations require constant time.
   - **Deletions** (deleteFront and deleteLast): O(1) — Both operations also require constant time.
   - **Accessing** (getFront and getRear): O(1) — Retrieving values

 at the front and rear is constant time.

2. **Space Complexity**:
   - O(k) — The space complexity is linear concerning the size of the deque `k`, due to the storage of elements in the dynamic array.

### Conclusion

The provided code efficiently implements a circular deque that allows for O(1) time complexity for insertion and deletion operations from both ends. By wrapping the pointers, it efficiently uses a fixed-size array, avoiding the overhead associated with dynamic resizing. The careful handling of empty and full conditions ensures robustness in various operational scenarios.
