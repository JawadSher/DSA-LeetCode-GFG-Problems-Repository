<h1 align='center'>Linear - Queue - Array - Implementation - NO STL</h1>

### **What is a Queue?**

A **queue** is a linear data structure that follows the **FIFO (First In First Out)** principle. It means that the element inserted first will be the first to be removed. This is analogous to a queue of people waiting in line; the first person in line gets served first.

### **Queue Operations**
1. **Enqueue (push)**: Add an element to the rear (end) of the queue.
2. **Dequeue (pop)**: Remove an element from the front of the queue.
3. **isEmpty**: Check if the queue is empty.
4. **isFull**: Check if the queue is full (for a fixed-size queue).
5. **getFront**: Get the element at the front of the queue without removing it.
6. **getRear**: Get the element at the rear of the queue without removing it.
7. **getSize**: Get the current number of elements in the queue.

### **Queue Structure**
- **Front**: Refers to the first element in the queue.
- **Rear**: Refers to the position where the next element will be inserted.
- **Size**: Maximum capacity of the queue.

### **Queue Example**

Consider a queue that can hold a maximum of 5 integers. The queue is initially empty:

| 10 | 20 | 30 | 40 | 50 |
|:--:|:--:|:--:|:--:|:--:|
|    |    |    |    |    |
Front=0 | Rear=0

If we `push(10)`, `push(20)`, and `push(30)`, the queue will look like this:

| 10 | 20 | 30 |    |    |
|:--:|:--:|:--:|:--:|:--:|
Front=0 | Rear=3

Now, if we `pop()` (dequeue), the first element (10) will be removed:

| -1 | 20 | 30 |    |    |
|:--:|:--:|:--:|:--:|:--:|
Front=1 | Rear=3

---

## **Problem Statement**

We want to implement a queue with the following functionalities:
1. **Push (Enqueue)**: Add elements to the queue.
2. **Pop (Dequeue)**: Remove and return the front element.
3. **Get Front**: Retrieve the first element of the queue without removing it.
4. **Get Rear**: Retrieve the last element added.
5. **Check if the Queue is Full or Empty**.

### **Approach**

We will use an array to implement the queue. We'll keep two variables:
- `front` to track the first element.
- `rear` to track where to insert the next element.

Whenever an element is added, we increment `rear`. When an element is removed, we increment `front`.

If the `front` and `rear` are equal, the queue is empty. If `rear` equals the queue's capacity (size), the queue is full.

### **Example**
Let's create a queue with a capacity of 5:
```cpp
Queue q(5);
q.push(10);   // Queue: [10]
q.push(20);   // Queue: [10, 20]
q.push(30);   // Queue: [10, 20, 30]

q.pop();      // Popped: 10, Queue: [20, 30]
q.getFront(); // Output: 20 (front of the queue)
q.getRear();  // Output: 30 (last element added)
q.getSize();  // Output: 2 (2 elements remaining)
```

---

## Problem Solution
```cpp
#include <iostream>
using namespace std;

class Queue{
  public:
    int *arr;
    int size;
    int rear;
    int front;

  Queue(int s = 100){
    this -> size = s;
    arr = new int[size];
    rear = 0;
    front = 0;
  }

  bool isEmpty(){
    return front == rear;
  }

  bool isFull(){
    if(front == 0 && rear == size-1) return true;
    
    return false;
  }

  void getSize(){
    cout << "Size of Queue is : " << rear - front <<endl ;
  }

  void getFront(){
    if(isEmpty()){
      cout << "Queue is Empty" << endl; 
      return;
    }
    cout << "First value is : " << arr[front] << endl;
  }

  void getRear(){
    if(isEmpty()){
      cout << "Queue is Empty" << endl; 
      return;
    }
    cout << "Last value is : " << arr[rear-1] << endl;
  }

  void push(int val){
    if(isFull()) cout << "Queue is Full" << endl;
    
    arr[rear++] = val; 
  }

  void pop(){
    if(isEmpty()){
      cout << "Queue is Empty" << endl;
      return;
    }else {
      int element = arr[front];
      arr[front++] = -1;
      cout << "Poped Element : " << element << endl;

      if(front == rear) rear = 0, front = 0;
    }
  }

  ~Queue(){
    delete [] arr;
  }
};

int main() {
  // creation of Queue
  Queue q(10);

  // Pushing Element to Queue
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);

  // pop Element from Queue
  q.pop();
  q.pop();

  // Size of Queue
  q.getSize();

  // front value of Queue
  q.getFront();

  // last value of Queue
  q.getRear();


  
  return 0;
}
```

## Problem Solution Explanation

### **Class Definition**

```cpp
class Queue {
public:
    int *arr;  // Array to store queue elements
    int size;  // Maximum size of the queue
    int rear;  // Index where next element will be added
    int front; // Index where the current element is stored
```

- `arr`: This is a pointer to dynamically allocate an array to hold queue elements.
- `size`: The maximum number of elements the queue can hold.
- `rear`: Points to the position where the next element will be inserted.
- `front`: Points to the first element in the queue.

### **Constructor**

```cpp
Queue(int s = 100) {
    this->size = s;
    arr = new int[size];
    rear = 0;
    front = 0;
}
```

- The constructor initializes the queue. It sets the maximum size of the queue, creates an array dynamically using `new`, and initializes `rear` and `front` to 0, indicating an empty queue.

### **`isEmpty` Function**

```cpp
bool isEmpty() {
    return front == rear;
}
```

- **Purpose**: Checks if the queue is empty.
- **Explanation**: If `front` and `rear` are equal, there are no elements in the queue, so it returns `true`.

### **`isFull` Function**

```cpp
 bool isFull(){
    if(front == 0 && rear == size-1) return true;
    
    return false;
  }
```

- **Purpose**: Checks if the queue is full.
- **Explanation**: If `front` equals to 0 and `rear` has reached the last index (`size - 1`), it means the queue is full and no more elements can be inserted.

### **`getSize` Function**

```cpp
void getSize() {
    cout << "Size of Queue is: " << rear - front << endl;
}
```

- **Purpose**: Displays the current number of elements in the queue.
- **Explanation**: The size is calculated by subtracting the `front` index from the `rear` index.

### **`getFront` Function**

```cpp
void getFront() {
    if (isEmpty()) {
        cout << "Queue is Empty" << endl;
        return;
    }
    cout << "First value is: " << arr[front] << endl;
}
```

- **Purpose**: Retrieves and displays the front element.
- **Explanation**: If the queue is not empty, it prints the value at `front`.

### **`getRear` Function**

```cpp
void getRear() {
    if (isEmpty()) {
        cout << "Queue is Empty" << endl;
        return;
    }
    cout << "Last value is: " << arr[rear - 1] << endl;
}
```

- **Purpose**: Retrieves and displays the rear element.
- **Explanation**: If the queue is not empty, it prints the value at `rear - 1`.

### **`push` Function**

```cpp
void push(int val) {
    if (isFull()) {
        cout << "Queue is Full" << endl;
        return;
    }
    arr[rear++] = val;
}
```

- **Purpose**: Adds a new element to the queue.
- **Explanation**: If the queue is not full, it inserts the element at `rear` and then increments `rear`.

### **`pop` Function**

```cpp
void pop() {
    if (isEmpty()) {
        cout << "Queue is Empty" << endl;
        return;
    } else {
        int element = arr[front];
        arr[front++] = -1;
        cout << "Popped Element: " << element << endl;

        if (front == rear) {
            rear = 0;
            front = 0;
        }
    }
}
```

- **Purpose**: Removes the front element from the queue.
- **Explanation**: If the queue is not empty, it prints and removes the element at `front`. After removing, it increments `front`. If the queue becomes empty (i.e., `front` equals `rear`), it resets both `front` and `rear` to 0.

### **Destructor**

```cpp
~Queue() {
    delete[] arr;
}
```

- **Purpose**: Frees up the memory allocated for the queue.
- **Explanation**: This releases the memory that was dynamically allocated for the queue's array.

---

## **Time and Space Complexities**

1. **Space Complexity**:
   - The space complexity is **O(n)**, where `n` is the size of the queue. This is because we are dynamically allocating an array of size `n`.

2. **Time Complexities**:
   - **Push**: O(1) – Inserting an element at the `rear` takes constant time.
   - **Pop**: O(1) – Removing an element from the `front` takes constant time.
   - **isEmpty**: O(1) – Simply checks the value of `front` and `rear`.
   - **isFull**: O(1) – Simply checks the value of `rear`.
   - **getFront**: O(1) – Accesses the front element in constant time.
   - **getRear**: O(1) – Accesses the rear element in constant time.
   - **getSize**: O(1) – Simply prints the difference between `rear` and `front`.

---

This is a basic implementation of a queue using arrays. It efficiently handles common queue operations in constant time.
