<h1 align='center'>Linear(simple) - Queue - Example</h1>

## Problem Statement
The provided code demonstrates the basic operations of a **queue** data structure using C++. A queue is a linear data structure that follows the **First In First Out (FIFO)** principle, meaning that elements are inserted from one end (rear) and removed from the other end (front).

In this code, we:
1. Create a queue of integers.
2. Push (add) elements to the queue.
3. Display the size of the queue before and after popping (removing) an element.
4. Get and display the element at the front of the queue.
5. Check if the queue is empty or not.

---

### Queue Data Structure:

A **[Queue](https://en.cppreference.com/w/cpp/container/queue)** is a linear data structure used to store elements in which the **insertion** of elements happens at one end (called the **rear**) and the **deletion** of elements happens at the other end (called the **front**). This behavior is known as **FIFO** (First In First Out), meaning the element that is added first will be the one to be removed first.

#### Key Operations of Queue:
1. **Enqueue (push)**: Adds an element to the rear of the queue.
2. **Dequeue (pop)**: Removes an element from the front of the queue.
3. **Front**: Returns the element at the front without removing it.
4. **Size**: Returns the number of elements in the queue.
5. **Empty**: Checks if the queue is empty or not.



#### Real-Life Example:
Think of a queue at a bank. The first person who joins the queue is the first person to be served, and the last person has to wait for all the people in front to be served first.

## Problem Solution 
```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
  // Creation of Queue
  queue<int> q;

  // Push Element to Queue
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);

  // Size of Queue
  cout<< "Size of Queue : " << q.size() << endl;

  // Remove Element from Queue
  q.pop();

  // Get the Front Element
  cout<< "Front Element : " << q.front() <<endl;

  // Size of Queue
  cout<< "After Pop - Size of Queue : " << q.size() << endl;

  // Check is Queue empty or not
  if(q.empty()) cout << "Queue is Empty" <<endl;
  else cout << "Queue is Not Empty" <<endl;

  return 0;
}
```

## Source Code Explanation

1. **Creating a Queue:**
   ```cpp
   queue<int> q;
   ```
   - An empty queue `q` is created, which can hold integers.

2. **Adding (Enqueue) Elements to the Queue:**
   ```cpp
   q.push(10);
   q.push(20);
   q.push(30);
   q.push(40);
   ```
   - Four elements (`10`, `20`, `30`, `40`) are added to the queue in sequence. After these operations, the queue looks like this:
     ```
     Front -> [10, 20, 30, 40] <- Rear
     ```

3. **Size of Queue:**
   ```cpp
   cout<< "Size of Queue : " << q.size() << endl;
   ```
   - The size of the queue is displayed, which would be `4` since there are four elements in it.

4. **Removing (Dequeue) an Element:**
   ```cpp
   q.pop();
   ```
   - The element at the front (i.e., `10`) is removed. Now the queue looks like this:
     ```
     Front -> [20, 30, 40] <- Rear
     ```

5. **Getting the Front Element:**
   ```cpp
   cout<< "Front Element : " << q.front() <<endl;
   ```
   - The front element of the queue is `20` (since `10` was removed).

6. **Size of Queue After Pop:**
   ```cpp
   cout<< "After Pop - Size of Queue : " << q.size() << endl;
   ```
   - The size of the queue is now `3` after the `pop` operation.

7. **Checking if Queue is Empty:**
   ```cpp
   if(q.empty()) cout << "Queue is Empty" <<endl;
   else cout << "Queue is Not Empty" <<endl;
   ```
   - The queue is not empty, so it prints "Queue is Not Empty."

---

### Time Complexities of Queue Operations:

| Operation   | Time Complexity |
|-------------|-----------------|
| Enqueue     | O(1)            |
| Dequeue     | O(1)            |
| Front       | O(1)            |
| Size        | O(1)            |
| Empty       | O(1)            |

- **Enqueue** and **Dequeue** operations both take constant time, O(1), because they involve simple pointer manipulations to insert at the rear and remove from the front.
- **Front**, **Size**, and **Empty** operations also take constant time, O(1), since these are basic checks.

In conclusion, a queue is an efficient data structure for handling elements in the order they were added, and it is widely used in scenarios where **order of processing** matters, such as task scheduling, managing requests in a server, or handling asynchronous tasks.
