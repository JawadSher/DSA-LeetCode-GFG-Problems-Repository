<h1 align='center'>Implement - N Stacks - In a - Single - Array</h1>
We are asked to implement `NStacks` that allows managing multiple stacks using a single array. The objective is to design a data structure that can handle multiple stacks efficiently with a shared memory space, using minimal space and avoiding overflow/underflow conditions.

### Key Operations:
- **Push an element onto a specific stack**.
- **Pop an element from a specific stack**.

The class `NStacks` is designed to:
- Maintain `N` stacks using a single array.
- Allow dynamic push and pop operations on each stack.
- Efficiently track available/free spaces for pushing elements, so no space is wasted.

### Approach:
The solution involves three arrays:
1. `arr[]`: Stores all the stack elements.
2. `top[]`: Keeps track of the index of the top element of each stack.
3. `next[]`: Maintains the next free spot in the array or the next element in a particular stack.

Additionally, we use an integer `freeSpot` to keep track of the first free index in the array for the next element to be inserted.

#### Steps:
- **Push Operation**: 
    - Find a free index using `freeSpot`.
    - Insert the element at this free index and update the `freeSpot` to the next available free spot.
    - Update the `next[]` array to point to the previous top of the stack and make this new index the new top.
  
- **Pop Operation**: 
    - Retrieve the top element from the desired stack.
    - Update the top pointer to the next element in that stack.
    - Link the freed index back to the free spots list.

## Problem Solution
```cpp
#include <iostream>
using namespace std;

class NStacks {
    int *arr;      // Array to store elements of all stacks
    int *top;      // Array to store indexes of top elements of stacks
    int *next;     // Array to store next entry in all stacks and free list
    int n, s;      // n: total size of array, s: number of stacks
    int freeSpot;  // To store the beginning index of the free spots

public:
    // Constructor to initialize N stacks in a single array
    NStacks(int N, int S) {
        this->n = N;
        this->s = S;
        arr = new int[n];     // Array of size n to store elements
        top = new int[s];     // Array to store tops of stacks
        next = new int[n];    // Array to maintain the free spots

        // Initialize all stacks as empty (top = -1)
        fill(top, top + s, -1);

        // Initialize all spots as free and create free list
        freeSpot = 0;
        for (int i = 0; i < n - 1; i++) {
            next[i] = i + 1;
        }
        next[n - 1] = -1;  // End of free list
    }

    // Function to push an element onto stack 'stackNum'
    bool push(int value, int stackNum) {
        // check for overflow
        if (freeSpot == -1) {
            return false;  // No free space left
        }

        // find index
        int index = freeSpot;

        // update freeSpot
        freeSpot = next[index];

        // insert element into array
        arr[index] = value;

        // update next to point to the previous top element
        next[index] = top[stackNum - 1];

        // update top to point to the current index
        top[stackNum - 1] = index;

        return true;
    }

    // Function to pop an element from stack 'stackNum'
    int pop(int stackNum) {
        // check underflow condition
        if (top[stackNum - 1] == -1) return -1;  // Stack is empty

        int index = top[stackNum - 1];

        // update top to point to the next element in the stack
        top[stackNum - 1] = next[index];

        // link the popped index back to the free list
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }
};

int main() {
    int numOfStacks = 3, sizeOfArray = 6;
    NStacks stacks(sizeOfArray, numOfStacks);  // NStacks(total array size, number of stacks)

    // Push elements onto different stacks
    cout << stacks.push(10, 1) << endl;  // Expected: 1 (true)
    cout << stacks.push(20, 2) << endl;  // Expected: 1 (true)
    cout << stacks.push(30, 1) << endl;  // Expected: 1 (true)
    cout << stacks.push(40, 3) << endl;  // Expected: 1 (true)
    cout << stacks.push(50, 2) << endl;  // Expected: 1 (true)
    cout << stacks.push(60, 3) << endl;  // Expected: 1 (true)

    // Try pushing when array is full
    cout << stacks.push(70, 1) << endl;  // Expected: 0 (false) - Overflow

    // Pop elements from stacks
    cout << stacks.pop(1) << endl;  // Expected: 30
    cout << stacks.pop(2) << endl;  // Expected: 50
    cout << stacks.pop(3) << endl;  // Expected: 60

    // Pop again from stack 1
    cout << stacks.pop(1) << endl;  // Expected: 10

    // Try popping from empty stack
    cout << stacks.pop(1) << endl;  // Expected: -1 (Underflow)
}
```

## Problem Solution Explanation

```cpp
class NStacks {
    int *arr;      // Array to store elements of all stacks
    int *top;      // Array to store indexes of top elements of stacks
    int *next;     // Array to store next entry in all stacks and free list
    int n, s;      // n: total size of array, s: number of stacks
    int freeSpot;  // To store the beginning index of the free spots
```
- `arr[]`: A single array to store elements of all `N` stacks.
- `top[]`: Stores the index of the top element for each stack.
- `next[]`: Keeps track of the next available free index or the next element in a particular stack.
- `n`: The total size of the `arr[]` array.
- `s`: The number of stacks.
- `freeSpot`: Stores the first free index in `arr[]` where the next element can be pushed.

```cpp
public:
    NStacks(int N, int S) {
        this->n = N;
        this->s = S;
        arr = new int[n];     // Array of size n to store elements
        top = new int[s];     // Array to store tops of stacks
        next = new int[n];    // Array to maintain the free spots
```
- Constructor to initialize the `NStacks` class with `N` as the total array size and `S` as the number of stacks.
- `arr[]` is initialized to size `N` to store all elements.
- `top[]` is initialized to size `S` to track the top element of each stack.
- `next[]` is initialized to size `N` to help manage free spots.

```cpp
        fill(top, top + s, -1);  // Initialize all stacks as empty (top = -1)
```
- The `fill` function sets all entries in `top[]` to `-1`, indicating that all stacks are empty at the start.

```cpp
        freeSpot = 0;  // The first free spot is index 0
        for (int i = 0; i < n - 1; i++) {
            next[i] = i + 1;  // Free spots are chained together
        }
        next[n - 1] = -1;  // Last spot doesn't have a next free index
    }
```
- `freeSpot = 0`: The first free index is initialized to 0 (beginning of the array).
- The `for` loop sets up the free list: `next[]` points from one free index to the next. For example, `next[0] = 1`, `next[1] = 2`, and so on.
- `next[n - 1] = -1`: The last element in the free list has no next spot (end of free list).

---

#### Push Function:
```cpp
bool push(int value, int stackNum) {
    if (freeSpot == -1) {
        return false;  // No free space left
    }
```
- Checks for overflow: If `freeSpot == -1`, it means there's no available space to push any more elements, so it returns `false`.

```cpp
    int index = freeSpot;  // Use the free spot for the new element
    freeSpot = next[index];  // Update freeSpot to the next available free spot
```
- `index` is set to the current free spot.
- The `freeSpot` is updated to point to the next available free index (via `next[]`).

```cpp
    arr[index] = value;  // Insert the value into the array at the free spot
```
- The new element is inserted into the array at `index`.

```cpp
    next[index] = top[stackNum - 1];  // Link to the previous top element
    top[stackNum - 1] = index;        // Update top to the current index
```
- The `next[]` at `index` is updated to point to the previous top element of the stack.
- The `top[]` of the corresponding stack is updated to point to this new index.

```cpp
    return true;  // Push operation was successful
}
```
- Returns `true` indicating the push was successful.

---

#### Pop Function:
```cpp
int pop(int stackNum) {
    if (top[stackNum - 1] == -1) return -1;  // Stack is empty
```
- Checks for underflow: If `top[]` for the requested stack is `-1`, it means the stack is empty, and it returns `-1`.

```cpp
    int index = top[stackNum - 1];  // Get the current top index
    top[stackNum - 1] = next[index];  // Update top to the next element
```
- The `index` of the top element of the stack is saved.
- `top[]` is updated to point to the next element in the stack (via `next[]`).

```cpp
    next[index] = freeSpot;  // Link the freed index back to the free list
    freeSpot = index;        // Update freeSpot to the current index
```
- The freed `index` is linked back to the free list using `next[]`.
- `freeSpot` is updated to point to the newly freed spot.

```cpp
    return arr[index];  // Return the popped element
}
```
- Returns the popped element.

---

### Example Flow:

1. **Push Operations**:
   - `push(10, 1)`: Inserts `10` into stack 1 at index 0.
   - `push(20, 2)`: Inserts `20` into stack 2 at index 1.
   - `push(30, 1)`: Inserts `30` into stack 1 at index 2.
   
   **State**: 
   - `arr[] = {10, 20, 30, _, _, _}`
   - `top[] = {2, 1, -1}`
   - `next[] = {-1, -1, 0, 4, 5, -1}`
   - `freeSpot = 3`

2. **Pop Operations**:
   - `pop(1)`: Pops `30` from stack 1 (from index 2).
   - `pop(2)`: Pops `50` from stack 2 (from index 4).
  
## Problem Solution Explanation (2nd) :
The task is to implement **NStacks** (N stacks) using a single array. Instead of creating separate arrays for each stack, we will use one array to hold all the elements of the stacks. We need to manage these stacks so that:
- Each stack can grow and shrink independently.
- We can push (add) and pop (remove) elements from any stack.
- We need to handle cases where we try to push onto a full stack or pop from an empty stack.

### Key Components of the Code

1. **Variables**:
   - `arr`: This is the main array where all the stack elements are stored.
   - `top`: An array that keeps track of the top element's index of each stack. Each stack has its own top index.
   - `next`: An array that helps manage the free spaces in the `arr`. It points to the next available space in `arr`.
   - `n`: The total size of the `arr`.
   - `s`: The number of stacks.
   - `freeSpot`: This variable stores the index of the first available (free) position in the `arr`.

### Constructor Explanation

```cpp
NStacks(int N, int S) {
    this->n = N;      // Set the total size of the array
    this->s = S;      // Set the number of stacks
    arr = new int[n]; // Create the array to store stack elements
    top = new int[s]; // Create an array to track the top of each stack
    next = new int[n];// Create an array for the next available position

    // Initialize all stacks as empty (top = -1)
    fill(top, top + s, -1);

    // Initialize all spots as free and create free list
    freeSpot = 0; // Start from the first index
    for (int i = 0; i < n - 1; i++) {
        next[i] = i + 1; // Link the current index to the next
    }
    next[n - 1] = -1; // End of free list (no next element)
}
```

- **Purpose**: This constructor initializes the `NStacks` class by creating the necessary arrays and setting their initial values.
- **`top` Initialization**: Setting `top` to `-1` indicates that all stacks are initially empty.
- **`next` Initialization**: Each index points to the next free index. For example, if `next[0]` is `1`, it means index `0` is free and the next free index is `1`. The last element points to `-1`, indicating there are no more free spots.

### Core Logic

#### Push Operation

```cpp
bool push(int value, int stackNum) {
    if (freeSpot == -1) {
        return false;  // No free space left
    }

    int index = freeSpot; // Get the index of the free spot
    freeSpot = next[index]; // Update freeSpot to point to the next free index

    arr[index] = value; // Insert the value into the array

    next[index] = top[stackNum - 1]; // Link the new index to the previous top
    top[stackNum - 1] = index; // Update top to point to the new top element

    return true; // Push successful
}
```

- **Flow of Code**:
  - Check if there's a free spot to push the element.
  - Store the index of the free spot in `index`.
  - Update `freeSpot` to the next available free index.
  - Insert the new value at the `index`.
  - Update `next` so that the new top points to the previous top.
  - Finally, update the `top` array to reflect the new top of the stack.

- **Purpose of `top`**: The `top` array keeps track of the current top element of each stack. When you push an element onto a stack, you update the top index to point to this new element.

#### Pop Operation

```cpp
int pop(int stackNum) {
    if (top[stackNum - 1] == -1) return -1;  // Stack is empty

    int index = top[stackNum - 1]; // Get the current top index
    top[stackNum - 1] = next[index]; // Update top to the next element in the stack

    next[index] = freeSpot; // Link the popped index back to the free list
    freeSpot = index; // Update freeSpot to the popped index

    return arr[index]; // Return the popped value
}
```

- **Flow of Code**:
  - Check if the stack is empty. If it is, return `-1` (indicating underflow).
  - Get the current top index and store it in `index`.
  - Update the `top` index to point to the next element in the stack.
  - Link the popped index back to the free list by updating `next[index]`.
  - Update `freeSpot` to now include this index.
  - Return the value of the popped element.

### Example

Let’s say we have 3 stacks and we push some values onto them:

1. Push `10` to Stack 1: 
   - `top` becomes `[0, -1, -1]` (Stack 1's top is now at index `0`).
   - `arr` becomes `[10, _, _ , _, _, _]`.

2. Push `20` to Stack 2:
   - `top` becomes `[0, 1, -1]`.
   - `arr` becomes `[10, 20, _ , _, _, _]`.

3. Push `30` to Stack 1:
   - `top` becomes `[2, 1, -1]`.
   - `arr` becomes `[10, 20, 30, _, _, _]`.

### Summary of Key Variables

- **`arr`**: Holds all the elements for the stacks.
- **`top`**: Indicates the index of the top element for each stack.
- **`next`**: Manages the free spaces by pointing to the next free index.
- **`freeSpot`**: Keeps track of the first free index available for pushing new elements.

### Conclusion

This implementation efficiently allows for multiple stacks to coexist within a single array while managing memory for the stacks intelligently using the `next` array. Each push and pop operation is performed in constant time \(O(1)\), which is efficient for stack operations.
