<h1 align='center'>Circular - Queue - Implementation - Using - Arrays</h1>

## **Circular Queue Detailed Explanation**

A **circular queue** is a linear data structure that follows the **FIFO (First In First Out)** principle, but unlike a standard queue, it connects the end of the queue back to the beginning to form a circle. This allows for efficient use of space by avoiding the problem of unused slots that occur in a regular linear queue when elements are dequeued.

In a circular queue, when you try to enqueue an element into a full queue or dequeue an element from an empty queue, special cases arise that need to be handled correctly.

## **Problem Statement**

- **Circular Queue**: Implement a circular queue using an array to efficiently use memory. Support standard queue operations:
  1. `enqueue(val)` - Add an element `val` to the queue.
  2. `dequeue()` - Remove the front element from the queue.
  3. `getFront()` - Retrieve the front element without removing it.
  4. `getRear()` - Retrieve the last element without removing it.
  5. `isEmpty()` - Check if the queue is empty.
  6. `isFull()` - Check if the queue is full.

### **How a Circular Queue Works**

A circular queue maintains two pointers:
1. **`front`**: Points to the front element in the queue.
2. **`rear`**: Points to the last element in the queue.

Initially, both `front` and `rear` are set to `-1`, indicating an empty queue.

#### **Operations in a Circular Queue**

1. **Enqueue (Push) Operation**: 
    - **When queue is empty**: Both `front` and `rear` are set to `0` when the first element is added.
    - **When `rear` is at the last position**: The queue wraps around, and `rear` is set to `0` (circular behavior).
    - **Otherwise**: Increment `rear` to add the element at the next position.

2. **Dequeue (Pop) Operation**:
    - **When queue becomes empty after dequeue**: Both `front` and `rear` are reset to `-1`.
    - **When `front` is at the last position**: The queue wraps around, and `front` is set to `0` (circular behavior).
    - **Otherwise**: Increment `front` to point to the next element.

#### **Example**:
Let’s say the circular queue has a size of 5 (0 to 4 index).

- **Enqueue(10)**: 
  - `front = 0`, `rear = 0`
  - Queue: `[10, _, _, _, _]`

- **Enqueue(20)**:
  - `front = 0`, `rear = 1`
  - Queue: `[10, 20, _, _, _]`

- **Enqueue(30)**:
  - `front = 0`, `rear = 2`
  - Queue: `[10, 20, 30, _, _]`

- **Dequeue()**:
  - Remove `10`. Now, `front = 1`, `rear = 2`
  - Queue: `[_ , 20, 30, _, _]`

- **Enqueue(40)**:
  - `front = 1`, `rear = 3`
  - Queue: `[_ , 20, 30, 40, _]`

- **Enqueue(50)**:
  - `front = 1`, `rear = 4`
  - Queue: `[_ , 20, 30, 40, 50]`

- **Enqueue(60)**:
  - Now `rear` wraps around to `0`
  - Queue: `[60, 20, 30, 40, 50]`

#### **Key Points**:
- When the `rear` reaches the end of the array, it wraps around to the beginning (i.e., `rear = 0`).
- The queue is full when `front == 0` and `rear == size - 1`, or when `rear + 1 == front`.
- The queue is empty when `front == -1`.

### **Circular Queue Implementation Using Arrays**

The implementation involves:
1. **`arr`**: An array of a fixed size to store queue elements.
2. **`front`**: Tracks the front element.
3. **`rear`**: Tracks the last element.
4. **`size`**: The capacity of the queue.

## Problem Solution
```cpp
#include <iostream>
using namespace std;

class circularQueue {
  public:
    int *arr;
    int size;
    int rear;
    int front;

  circularQueue(int s = 100) {
    this->size = s;
    arr = new int[size];
    rear = -1;
    front = -1;
  }

  bool isEmpty() {
    return front == -1;
  }

  bool isFull() {
    return (front == 0 && rear == size - 1) || (rear == (front - 1) % size);
  }

  void getSize() {
    if (isEmpty()) {
      cout << "Queue is Empty" << endl;
      return;
    }
    if (rear >= front)
      cout << "Size of Queue is : " << rear - front + 1 << endl;
    else
      cout << "Size of Queue is : " << (size - front) + (rear + 1) << endl;
  }

  void getFront() {
    if (isEmpty()) {
      cout << "Queue is Empty" << endl;
      return;
    }
    cout << "First value is : " << arr[front] << endl;
  }

  void getRear() {
    if (isEmpty()) {
      cout << "Queue is Empty" << endl;
      return;
    }
    cout << "Last value is : " << arr[rear] << endl;
  }

  void push(int val) {
    if (isFull()) {
      cout << "Queue is Full" << endl;
      return;
    }
    if (front == -1) { // First element to be inserted
      front = rear = 0;
    } else if (rear == size - 1 && front != 0) {
      rear = 0; // Wrap around
    } else {
      rear++;
    }
    arr[rear] = val;
  }

  void pop() {
    if (isEmpty()) {
      cout << "Queue is Empty" << endl;
      return;
    }

    int element = arr[front];
    arr[front] = -1;
    cout << "Popped Element : " << element << endl;

    if (front == rear) { // Queue is empty after pop
      front = rear = -1;
    } else if (front == size - 1) {
      front = 0; // Wrap around
    } else {
      front++;
    }
  }

  ~circularQueue() {
    delete[] arr;
  }
};

int main() {
  circularQueue cq(10);

  cq.push(10);
  cq.push(20);
  cq.push(30);
  cq.push(40);
  cq.push(50);

  cq.pop();
  cq.pop();

  cq.getSize();
  cq.getFront();
  cq.getRear();

  return 0;
}

```

## Problem Solution Explanation
Let's break down the implementation of the circular queue in C++ step by step. 

### **Class Definition**
```cpp
class circularQueue {
  public:
    int *arr;      // Pointer to the array that holds the queue elements
    int size;      // Maximum size of the queue
    int rear;      // Index of the last element
    int front;     // Index of the first element
```
- **arr**: An array to hold the queue elements.
- **size**: The maximum size of the queue.
- **rear**: The index where the last element is added.
- **front**: The index where the first element is removed.

### **Constructor**
```cpp
circularQueue(int s = 100) {
    this->size = s;
    arr = new int[size];  // Dynamically allocate memory for the queue
    rear = -1;            // Initially, both rear and front are -1 (indicating an empty queue)
    front = -1;
}
```
- The constructor initializes the size and allocates memory for the queue. Initially, both `front` and `rear` are set to -1, indicating the queue is empty.

### **Check If Empty**
```cpp
bool isEmpty() {
    return front == -1; // The queue is empty if front is -1
}
```
- This function checks if the queue is empty. If `front` is -1, it returns `true`.

### **Check If Full**
```cpp
bool isFull() {
    return (front == 0 && rear == size - 1) || (rear == (front - 1) % size);
}
```
- This function checks if the queue is full. It considers two cases:
  1. When the `front` is at the beginning (index 0) and `rear` is at the end (last index).
  2. When `rear` is just before `front`, considering the circular nature using modulo.

### **Get Size**
```cpp
void getSize() {
    if (isEmpty()) {
        cout << "Queue is Empty" << endl;
        return;
    }
    if (rear >= front)
        cout << "Size of Queue is : " << rear - front + 1 << endl; // Case 1: Normal order
    else
        cout << "Size of Queue is : " << (size - front) + (rear + 1) << endl; // Case 2: Wrapped around
}
```
- This function calculates and prints the number of elements in the queue. If the queue is empty, it indicates so.

### **Get Front Element**
```cpp
void getFront() {
    if (isEmpty()) {
        cout << "Queue is Empty" << endl;
        return;
    }
    cout << "First value is : " << arr[front] << endl;
}
```
- This function prints the element at the front of the queue.

### **Get Rear Element**
```cpp
void getRear() {
    if (isEmpty()) {
        cout << "Queue is Empty" << endl;
        return;
    }
    cout << "Last value is : " << arr[rear] << endl;
}
```
- This function prints the element at the rear of the queue.

### **Push Operation**
```cpp
void push(int val) {
    if (isFull()) {
        cout << "Queue is Full" << endl;
        return;
    }
    if (front == -1) { // First element to be inserted
        front = rear = 0; // Set both front and rear to 0
    } else if (rear == size - 1 && front != 0) {
        rear = 0; // Wrap around if rear reaches the end
    } else {
        rear++; // Increment rear
    }
    arr[rear] = val; // Add the new value
}
```
- This function adds a new element to the queue. It checks if the queue is full first. If the queue is empty (`front == -1`), it initializes both `front` and `rear` to 0. If the `rear` reaches the end of the array, it wraps around to the beginning. Finally, it adds the new value at the `rear` index.

### **Pop Operation**
```cpp
void pop() {
    if (isEmpty()) {
        cout << "Queue is Empty" << endl;
        return;
    }

    int element = arr[front]; // Get the front element
    arr[front] = -1;          // Optional: Mark the popped element as -1
    cout << "Popped Element : " << element << endl;

    if (front == rear) { // Queue is empty after pop
        front = rear = -1; // Reset to empty state
    } else if (front == size - 1) {
        front = 0; // Wrap around
    } else {
        front++; // Increment front
    }
}
```
- This function removes and returns the element at the front of the queue. It checks if the queue is empty and then retrieves the front element. If the queue becomes empty after popping, it resets `front` and `rear` to -1. Otherwise, it adjusts the `front` index, wrapping around if necessary.

### **Destructor**
```cpp
~circularQueue() {
    delete[] arr; // Release allocated memory
}
```
- The destructor releases the memory allocated for the queue when the object is destroyed.

### **Example Usage**
In the `main` function, we create a circular queue and perform several operations:
```cpp
int main() {
  circularQueue cq(10); // Create a circular queue with max size 10

  cq.push(10); // Queue becomes [10]
  cq.push(20); // Queue becomes [10, 20]
  cq.push(30); // Queue becomes [10, 20, 30]
  cq.push(40); // Queue becomes [10, 20, 30, 40]
  cq.push(50); // Queue becomes [10, 20, 30, 40, 50]

  cq.pop();    // Removes 10, Queue becomes [20, 30, 40, 50]
  cq.pop();    // Removes 20, Queue becomes [30, 40, 50]

  cq.getSize(); // Output: Size of Queue is : 3
  cq.getFront(); // Output: First value is : 30
  cq.getRear();  // Output: Last value is : 50

  return 0;
}
```

### **Complexity Analysis**
- **Time Complexity**:
  - **Push**: O(1) - Inserting an element takes constant time.
  - **Pop**: O(1) - Removing an element takes constant time.
  - **isEmpty, isFull, getSize, getFront, getRear**: O(1) - These operations also take constant time.

- **Space Complexity**: 
  - O(n) - Where `n` is the maximum size of the queue. This is due to the array storing the queue elements.

This circular queue implementation efficiently uses space and maintains the queue's properties, ensuring that all operations are performed in constant time.
