<h1 align='center'>Implement - K - Queues - In an - Single - Array</h1>

## Problem Statement

**Problem URL :** [Impelement k Queues in an Single Array](https://www.geeksforgeeks.org/efficiently-implement-k-queues-single-array/)

You are given **`k`** queues and an array of size **`n`**. The challenge is to implement these **`k`** queues efficiently using a **single array** of size **`n`**. The program should support standard queue operations, namely:
1. **Enqueue (push an element into a specific queue)**.
2. **Dequeue (remove an element from a specific queue)**.

The goal is to:
- **Efficiently manage multiple queues** using only one array.
- Ensure that the space in the array is reused optimally when items are dequeued.
  
This is also called the **k-queue problem** where we need to use a single array to store elements of multiple queues.

### Beginner's Approach:

A beginner DSA student can break down the problem as follows:
1. **Understanding the problem**: Instead of creating separate arrays for each queue, you need to use a single array to manage multiple queues. This is space-efficient.
2. **Front and Rear management**: Each queue has its own `front` and `rear` to keep track of where elements are added and removed.
3. **Array space reuse**: When an element is dequeued, the space it used can be recycled and made available for future enqueue operations.

### Key Ideas:
- We maintain an array to store the actual elements.
- We use an additional `front` and `rear` array for each queue.
- A `next` array helps link the different spaces in the single array, similar to how nodes are linked in a linked list.
- A `freeSpot` variable keeps track of the next available free space in the array.

### Approach:
1. **Initialization**: Start with an array that stores the queue elements, a `front[]` and `rear[]` array to keep track of each queue's front and rear. Also, maintain a `next[]` array to point to the next free space or the next element in the queue.
2. **Enqueue**:
   - Check if there's a free space using `freeSpot`.
   - Insert the element at the free space and update the necessary pointers (update `rear[]`, `front[]`, and `next[]` arrays).
3. **Dequeue**:
   - Check if the queue is empty by checking `front[]`.
   - Remove the front element from the queue, update the pointers, and recycle the space by updating `freeSpot`.
## Problem Solution
```cpp
#include <iostream>
using namespace std;

class kQueue{
  public:
    int *arr;
    int k;
    int n;
    int *front;
    int *rear;
    int freeSpot;
    int *next;

    kQueue(int n, int k){
      this -> n = n;
      this -> k = k;
      arr = new int[n];
      front = new int[k];
      rear = new int[k];
      next = new int[n];
      freeSpot = 0;

      for(int i = 0; i < k; i++){
        front[i] = -1;
        rear [i] = -1;
      }

      for(int i = 0; i < n-1; i++){
        next[i] = i + 1;
      }
      next[n-1] = -1;
    }

    void enQueue(int data, int qn){
      // overflow 
      if(freeSpot == -1){
        cout << "No empty space is available" << endl;
        return;
      }

      // find first free index;
      int index = freeSpot;

      // update freeSpot;
      freeSpot = next[index];

      // check wheather first element
      if(front[qn-1] == -1){
        front[qn-1] = index;
      }else{
        // link new element to the prev element
        next[rear[qn-1]] = index;
      }

      // update next;
      next[index] = -1;

      // update rear;
      rear[qn-1] = index;

      // push element;
      arr[index] = data;

    }

    int deQueue(int qn){
      // underflow
      if(front[qn-1] == -1){
        cout << "Queue underflow" <<endl;
        return -1;
      }

      // find index to pop
      int index = front[qn-1];

      // update front pointer
      front[qn-1] = next[index];

      // next freeSpot
      next[index] = freeSpot;
      freeSpot = index;

      return arr[index];
    }
};

int main() {
  kQueue q(10, 3);

  q.enQueue(10, 1);
  q.enQueue(15, 1);
  q.enQueue(20, 2);
  q.enQueue(25, 1);
  q.enQueue(30, 2);
  q.enQueue(35, 3);

  cout << "Element poped from q1 : " << q.deQueue(1) <<endl;
  cout << "Element poped from q1 : " << q.deQueue(1) <<endl;
  cout << "Element poped from q2 : " << q.deQueue(2) <<endl;
  cout << "Element poped from q3 : " << q.deQueue(3) <<endl;
  return 0;
}
```

## Problem Solution Explanation
Here's a detailed explanation of the source code, walking through it step by step:

### 1. **Class and Member Variables**

```cpp
class kQueue{
  public:
    int *arr; // Array to store elements for all the queues
    int k;    // Number of queues
    int n;    // Total size of the array (capacity)
    int *front;  // Array to store front indices of all queues
    int *rear;   // Array to store rear indices of all queues
    int freeSpot; // Index of the next free spot in the array
    int *next;   // Array to manage the next free index or the next element in a queue
```

This declares the class `kQueue` and the member variables. Here’s what each variable does:
- **`arr[]`**: Stores the actual elements for all the queues.
- **`k`**: The number of queues.
- **`n`**: The total size of the array.
- **`front[]`**: Keeps track of the front (starting) index of each queue.
- **`rear[]`**: Keeps track of the rear (last) index of each queue.
- **`freeSpot`**: Index of the next available free spot in the array.
- **`next[]`**: This helps manage both free spots and the linked structure of queues.

### 2. **Constructor**

```cpp
kQueue(int n, int k){
  this -> n = n;
  this -> k = k;
  arr = new int[n];
  front = new int[k];
  rear = new int[k];
  next = new int[n];
  freeSpot = 0;

  for(int i = 0; i < k; i++){
    front[i] = -1;
    rear[i] = -1;
  }

  for(int i = 0; i < n-1; i++){
    next[i] = i + 1;
  }
  next[n-1] = -1;
}
```

Here’s what happens:
- **`this -> n = n` and `this -> k = k`**: Initialize the total size (`n`) and number of queues (`k`).
- **`arr = new int[n]`**: Allocate memory for the array that holds all elements.
- **`front[]` and `rear[]`**: Arrays to hold front and rear indices for each queue. Initially, each queue is empty, so both are set to `-1`.
- **`next[]`**: Helps track the next free spot and link elements within queues. Initially, all slots are free and linked to the next one in sequence (`next[i] = i + 1`). For example, `next[0] = 1`, `next[1] = 2`, and so on. The last index (`next[n-1] = -1`) indicates that there are no more free spots.

**Example Setup**:
Let’s say `n = 10` (array size) and `k = 3` (three queues):
- Initially:  
  - `arr[] = { _, _, _, _, _, _, _, _, _, _ }` (empty array)
  - `front[] = { -1, -1, -1 }` (no front indices yet)
  - `rear[] = { -1, -1, -1 }` (no rear indices yet)
  - `next[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, -1 }` (linked free spots)
  - `freeSpot = 0` (next free spot is index 0)

### 3. **Enqueue Operation**

```cpp
void enQueue(int data, int qn){
  if(freeSpot == -1){
    cout << "No empty space is available" << endl;
    return;
  }
  
  int index = freeSpot; // Get the free index
  freeSpot = next[index]; // Update freeSpot to the next available spot
  
  if(front[qn-1] == -1){ // If the queue is empty
    front[qn-1] = index; // Set front of the queue to this index
  } else {
    next[rear[qn-1]] = index; // Link the new element to the previous rear
  }

  next[index] = -1; // Set next of the new element to -1 (end of queue)
  rear[qn-1] = index; // Update rear to the new index
  arr[index] = data; // Add the element to the array
}
```

- **Check for overflow**: If `freeSpot == -1`, there are no free spots left.
- **Allocate a free spot**: `index = freeSpot` gives us the current free index. `freeSpot = next[index]` updates the free spot to the next available one.
- **Add the element**:
  - If the queue is empty (`front[qn-1] == -1`), set the front of the queue to this index.
  - Otherwise, link the new element to the existing queue by updating `next[rear[qn-1]] = index`.
- **Set `next[index] = -1`** to mark the new element as the last element of the queue.
- **Update `rear[qn-1] = index`** to point to the newly added element.
- **Store the data**: Finally, `arr[index] = data` stores the new element in the array.

**Example**:
Let’s enqueue `10` into Queue 1 (`qn = 1`):
- **Before enqueue**:
  - `freeSpot = 0`
  - `front[] = { -1, -1, -1 }`
  - `rear[] = { -1, -1, -1 }`
- **Steps**:
  - Free spot is 0 (`index = 0`).
  - Set `freeSpot = next[0] = 1` (next free spot is 1).
  - Queue 1 is empty, so `front[0] = 0`.
  - Set `next[0] = -1` and `rear[0] = 0`.
  - Store `arr[0] = 10`.

The array looks like this after enqueuing:
- `arr[] = { 10, _, _, _, _, _, _, _, _, _ }`
- `front[] = { 0, -1, -1 }`
- `rear[] = { 0, -1, -1 }`
- `freeSpot = 1`

### 4. **Dequeue Operation**

```cpp
int deQueue(int qn){
  if(front[qn-1] == -1){
    cout << "Queue underflow" << endl;
    return -1;
  }
  
  int index = front[qn-1]; // Get the front index
  front[qn-1] = next[index]; // Update the front to the next element
  
  next[index] = freeSpot; // Add the current index to the free list
  freeSpot = index; // Update freeSpot to this newly freed index
  
  return arr[index]; // Return the dequeued element
}
```

- **Check for underflow**: If `front[qn-1] == -1`, the queue is empty.
- **Dequeue the front element**: Save the front index (`index = front[qn-1]`), then update the front to the next element (`front[qn-1] = next[index]`).
- **Free the current spot**: Add the dequeued spot to the list of free spots by setting `next[index] = freeSpot`, and update `freeSpot = index`.
- **Return the dequeued element**: Finally, return the element stored in `arr[index]`.

**Example**:
Let’s dequeue an element from Queue 1:
- **Before dequeue**:
  - `front[0] = 0` (points to index 0 where `10` is stored).
  - `rear[0] = 0`.
- **Steps**:
  - Dequeue `arr[0] = 10`.
  - Set `front[0] = next[0] = -1` (Queue 1 becomes empty).
  - Set `next[0] = freeSpot = 1` (index 0 is now free).
  - Update `freeSpot = 0`.

The array after dequeue:
- `arr[] = { 10, _, _, _, _, _, _, _, _, _ }` (element is still in the array but not part of the queue)
- `front[] = { -1, -1, -1 }`
- `rear[] = { -1, -1, -1 }`
- `freeSpot = 0`

### 5. **Main Function Example**

```cpp
int main() {
  kQueue q(10, 3);

  q.enQueue(10, 1); // Enqueue 10 to Queue 1
  q.enQueue(15, 1); // Enqueue 15 to Queue 1
  q.enQueue(20, 2); // Enqueue 20 to Queue 2
  q.enQueue(25, 1); // Enqueue 25 to Queue 1
  q.enQueue(30, 2); // Enqueue 30 to Queue 2
  q.enQueue(35, 3); // Enqueue 35 to Queue 3

  cout << "Element poped from

 queue 1 is " << q.deQueue(1) << endl;
  cout << "Element poped from queue 2 is " << q.deQueue(2) << endl;
  cout << "Element poped from queue 3 is " << q.deQueue(3) << endl;
}
```

- Enqueues 10, 15, and 25 into Queue 1, 20 and 30 into Queue 2, and 35 into Queue 3.
- Dequeues elements from Queue 1, Queue 2, and Queue 3 and prints them.

### Time and Space Complexities of the `kQueue` Implementation:

#### 1. **Space Complexity:**

Let’s break down the space usage:

- **`arr[]`**: The array stores the elements of all the queues, and its size is `n` (the total capacity of all queues combined).
- **`front[]` and `rear[]`**: Two arrays of size `k` (the number of queues) to store the front and rear indices of each queue.
- **`next[]`**: An array of size `n` to manage free spots and links between elements within the queues.
- **Miscellaneous**: A few integer variables (`n`, `k`, `freeSpot`), which take constant space.

**Space complexity** is therefore:
\[
\text{Space Complexity} = O(n) + O(k) + O(n) = O(n + k)
\]
Where:
- `O(n)` is for storing the elements in `arr[]` and `next[]`.
- `O(k)` is for the `front[]` and `rear[]` arrays, which store the indices for each of the `k` queues.

#### 2. **Time Complexity:**

The two primary operations, `enQueue` and `deQueue`, are both constant time operations due to the efficient usage of the `next[]` array and index tracking.

##### **a. `enQueue(int data, int qn)`**

1. **Checking for available space** (`if(freeSpot == -1)`): This is a constant time check, `O(1)`.
2. **Allocating space**: Fetching a free spot and updating the `freeSpot` pointer is constant time (`O(1)`).
3. **Updating the `front[]` and `rear[]` arrays**: Setting front or rear indices and updating the `next[]` array takes constant time, `O(1)`.
4. **Storing the data in `arr[]`**: Simply involves assigning a value to the array, which is constant time, `O(1)`.

Thus, the overall **time complexity of the `enQueue` operation** is:
\[
O(1)
\]

##### **b. `deQueue(int qn)`**

1. **Checking for underflow** (`if(front[qn-1] == -1)`): This is a constant time check, `O(1)`.
2. **Fetching the front element**: Retrieving the element and updating the `front[]` pointer takes constant time, `O(1)`.
3. **Releasing the space**: Adding the index back to the list of free spots (by updating `freeSpot` and `next[]`) is done in constant time, `O(1)`.

Thus, the overall **time complexity of the `deQueue` operation** is:
\[
O(1)
\]

### Summary of Complexities:

- **Time Complexity**:
  - **`enQueue`**: `O(1)`
  - **`deQueue`**: `O(1)`

- **Space Complexity**: `O(n + k)`, where `n` is the total capacity of the array for all queues, and `k` is the number of queues.

This implementation is highly efficient in terms of time complexity, as both enqueue and dequeue operations take constant time (`O(1)`), making it ideal for real-time applications where multiple queues need to be managed in a memory-efficient manner.



