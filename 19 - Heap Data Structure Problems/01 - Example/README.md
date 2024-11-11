<h1 align='center'>Heap - Data - Structure - Example</h1>

A **Heap** is a special tree-based data structure that satisfies the *heap property*. In a heap, the parent node has a specific relationship with its children, making it efficient for priority-based operations, especially for scenarios like priority queues. 

### Types of Heaps

There are mainly two types of heaps:

1. **Max Heap**: In a max heap, the value of each node is greater than or equal to the values of its children, meaning the root node has the maximum value.
2. **Min Heap**: In a min heap, the value of each node is less than or equal to the values of its children, meaning the root node has the minimum value.

### Properties of Heaps

1. **Complete Binary Tree**: A heap is always a complete binary tree, meaning all levels are completely filled except possibly the last level, which is filled from left to right.
2. **Heap Property**: 
   - For a max heap, the parent’s key is greater than or equal to its children’s keys.
   - For a min heap, the parent’s key is less than or equal to its children’s keys.

### Applications of Heaps

1. **Priority Queues**: Heaps are used to implement priority queues, where elements with higher priority are dequeued before those with lower priority.
2. **Heap Sort**: Heaps are used in the heap sort algorithm to sort an array or list in ascending or descending order.
3. **Finding Minimum/Maximum Elements**: Quickly finding the minimum (in a min heap) or maximum (in a max heap) element.
4. **Median Maintenance**: Maintaining the median of a dynamically changing dataset.

### Structure of a Heap in an Array

Heaps are usually represented as arrays for ease of storage and access. For a node at index `i` in a 0-based array:
- The left child is at index `2*i + 1`
- The right child is at index `2*i + 2`
- The parent node is at index `(i - 1) // 2`

### Operations on a Heap

1. **Insertion**:
   - Insert the new element at the end of the heap.
   - Perform an “up-heap” (or "heapify up") operation to restore the heap property by comparing and swapping the element with its parent until the heap property is satisfied.

2. **Deletion (usually deleting the root)**:
   - Replace the root element with the last element in the heap.
   - Remove the last element.
   - Perform a “down-heap” (or "heapify down") operation by comparing the root with its children and swapping it with the smaller child (in a min heap) or larger child (in a max heap) until the heap property is restored.

3. **Heapify**:
   - Converts an unordered array into a heap by applying down-heap operations from the last non-leaf node to the root node.

### Examples

#### Max Heap Example

Let's build a max heap step-by-step by inserting the elements `[10, 20, 15, 30, 40]`.

1. **Insert `10`**: Heap is `[10]`
2. **Insert `20`**: Heap becomes `[20, 10]`
3. **Insert `15`**: Heap becomes `[20, 10, 15]`
4. **Insert `30`**: 
   - Insert `30` at the end: `[20, 10, 15, 30]`
   - Swap `30` with `20`: `[30, 20, 15, 10]`
5. **Insert `40`**:
   - Insert `40` at the end: `[30, 20, 15, 10, 40]`
   - Swap `40` with `20`: `[30, 40, 15, 10, 20]`
   - Swap `40` with `30`: `[40, 30, 15, 10, 20]`

The max heap is now: `[40, 30, 15, 10, 20]`

#### Min Heap Example

Let's build a min heap step-by-step by inserting the elements `[10, 20, 15, 30, 40]`.

1. **Insert `10`**: Heap is `[10]`
2. **Insert `20`**: Heap becomes `[10, 20]`
3. **Insert `15`**: Heap becomes `[10, 20, 15]`
4. **Insert `30`**: Heap becomes `[10, 20, 15, 30]`
5. **Insert `40`**: Heap becomes `[10, 20, 15, 30, 40]`

The min heap is now: `[10, 20, 15, 30, 40]`

### Heapify Algorithm 
The **Heapify** algorithm is a fundamental process used in heaps to maintain the heap property, ensuring that for max-heaps, each parent node is greater than or equal to its child nodes, and for min-heaps, each parent node is less than or equal to its child nodes. There are two main types of heapify operations:

1. **Max-Heapify**: Ensures the max-heap property, where the largest element is at the root.
2. **Min-Heapify**: Ensures the min-heap property, where the smallest element is at the root.

### 1. Max-Heapify Algorithm

**Max-Heapify** is used to rearrange an array into a max-heap. Given an array representation of a heap, the `max_heapify` function ensures that the subtree rooted at a given index satisfies the max-heap property.

#### Max-Heapify Steps

1. Select a node at index `i`.
2. Find the left child at `2 * i` and the right child at `2 * i + 1`.
3. Compare the value at `i` with its children:
   - If the left child is larger than the parent, set `largest = left`.
   - If the right child is larger than the current largest, set `largest = right`.
4. If `largest` is not `i`, swap the values at `i` and `largest`.
5. Recursively call `max_heapify` on the affected subtree to maintain the max-heap property down the tree.

#### Example of Max-Heapify

Consider an array `[54, 53, 55, 52, 50]` represented in a 1-based index as:
```
Index:  1   2   3   4   5
Array: [54, 53, 55, 52, 50]
```

Applying **Max-Heapify** from the last non-leaf node, which is at index `2`, we can illustrate the process:

- Start at `i = 2` (value = 53).
  - Left child is at index `4` (value = 52), and right child is at index `5` (value = 50).
  - Since 53 is greater than both 52 and 50, no swap is needed here.

- Now move to `i = 1` (value = 54).
  - Left child is at index `2` (value = 53), and right child is at index `3` (value = 55).
  - The right child (55) is greater than 54, so we swap 54 and 55.

The array after applying `max_heapify`:
```
Index:  1   2   3   4   5
Array: [55, 53, 54, 52, 50]
```

### 2. Min-Heapify Algorithm

**Min-Heapify** is similar to Max-Heapify but maintains the min-heap property, where each parent node is less than or equal to its children.

#### Min-Heapify Steps

1. Select a node at index `i`.
2. Find the left child at `2 * i + 1` and the right child at `2 * i + 2`.
3. Compare the value at `i` with its children:
   - If the left child is smaller than the parent, set `smallest = left`.
   - If the right child is smaller than the current smallest, set `smallest = right`.
4. If `smallest` is not `i`, swap the values at `i` and `smallest`.
5. Recursively call `min_heapify` on the affected subtree to maintain the min-heap property.

#### Example of Min-Heapify

Consider the array `[54, 53, 55, 52, 50]`, represented in a 0-based index:

```
Index:  0   1   2   3   4
Array: [54, 53, 55, 52, 50]
```

Starting from the last non-leaf node (`i = 1`):

- At `i = 1` (value = 53):
  - Left child is at index `3` (value = 52) and right child at index `4` (value = 50).
  - The right child (50) is the smallest, so swap 53 with 50.

Array after this swap:
```
[54, 50, 55, 52, 53]
```

- Move to `i = 0` (value = 54):
  - Left child is at index `1` (value = 50) and right child at index `2` (value = 55).
  - The left child (50) is smaller than 54, so swap 54 with 50.

Array after applying `min_heapify`:
```
[50, 54, 55, 52, 53]
```

#### Summary of Heapify Use-Cases
- **Max-Heapify** is typically used for creating max-heaps, which are useful for finding the maximum element quickly.
- **Min-Heapify** is used for creating min-heaps, which can help in finding the minimum element efficiently.

These algorithms are foundational for implementing efficient sorting (heap sort) and priority queues, making heaps a versatile data structure in various applications.

### Heapify Operation

Consider an array `[3, 9, 2, 1, 4, 5]` that we want to transform into a max heap:

1. Start with the last non-leaf node, which is at index `2`.
2. **Heapify at index `2`**: Compare `2` with its children `5` and make `5` the new parent. The array becomes `[3, 9, 5, 1, 4, 2]`.
3. **Heapify at index `1`**: Compare `9` with its children `1` and `4`. No changes are needed.
4. **Heapify at index `0`**: Compare `3` with its children `9` and `5`. Swap `3` with `9`. The array becomes `[9, 3, 5, 1, 4, 2]`.

The final max heap is `[9, 3, 5, 1, 4, 2]`. 

## Source Code 
```cpp
#include <iostream>
#include <algorithm>  // For STL heap functions
#include <vector>
using namespace std;

class Heap {
public:
    int arr[100];
    int size;

    Heap() {
        arr[0] = -1; // Initialize array with -1 at index 0 (1-based indexing)
        size = 0;    // Initial size of heap is 0
    }

    // Insert a new element into the heap
    void insert(int value) {
        size++;
        int index = size;
        arr[index] = value;

        // Heapify up to maintain max heap property
        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;  // Move up to parent
            } else {
                return;
            }
        }
    }

    // Delete the root element from the heap
    void deleteFromHeap() {
        if (size == 0) {
            cout << "Nothing to delete" << endl;
            return;
        }

        // Replace root with the last element
        arr[1] = arr[size];
        size--;

        // Heapify down to maintain max heap property
        int i = 1;
        while (i <= size) {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            int largest = i;

            if (leftIndex <= size && arr[largest] < arr[leftIndex]) {
                largest = leftIndex;
            }
            if (rightIndex <= size && arr[largest] < arr[rightIndex]) {
                largest = rightIndex;
            }
            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else {
                return;
            }
        }
    }

    // Print the heap
    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Heapify for max heap
void max_heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left]) largest = left;
    if (right <= n && arr[largest] < arr[right]) largest = right;

    if (largest != i) {
        swap(arr[largest], arr[i]);
        max_heapify(arr, n, largest);
    }
}

// Heapify for min heap
void min_heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[smallest] > arr[left]) smallest = left;
    if (right < n && arr[smallest] > arr[right]) smallest = right;

    if (smallest != i) {
        swap(arr[smallest], arr[i]);
        min_heapify(arr, n, smallest);
    }
}

// Sort a max heap (ascending order)
void maxHeapSort(int arr[], int n) {
    // Build a max heap
    for (int i = n / 2; i > 0; i--) {
        max_heapify(arr, n, i);
    }

    // Sort
    for (int i = n; i > 1; i--) {
        swap(arr[1], arr[i]);
        max_heapify(arr, i - 1, 1);
    }
}

// Sort a min heap (descending order)
void minHeapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        min_heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        min_heapify(arr, i, 0);
    }
}

int main() {
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    cout << "Max Heap after insertions:" << endl;
    h.print();
    h.deleteFromHeap();
    cout << "Max Heap after deletion:" << endl;
    h.print();

    cout << endl;

    // Max Heap Creation using array
    int max_arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--) {
        max_heapify(max_arr, n, i);
    }

    cout << "Heapify array - Max Heap" << endl;
    for (int i = 1; i <= n; i++) {
        cout << max_arr[i] << " ";
    }
    cout << endl;

    maxHeapSort(max_arr, n);
    cout << "Printing max sorted heap (Ascending Order)" << endl;
    for (int i = 1; i <= n; i++) {
        cout << max_arr[i] << " ";
    }
    cout << endl << endl;

    // Min Heap Creation using array
    int min_arr[5] = {54, 53, 55, 52, 50};
    int m = 5;
    for (int i = m / 2 - 1; i >= 0; i--) {
        min_heapify(min_arr, m, i);
    }

    cout << "Heapify array - Min Heap" << endl;
    for (int i = 0; i < m; i++) {
        cout << min_arr[i] << " ";
    }
    cout << endl;

    minHeapSort(min_arr, m);
    cout << "Printing min sorted heap (Descending Order)" << endl;
    for (int i = 0; i < m; i++) {
        cout << min_arr[i] << " ";
    }
    cout << endl;

    return 0;
}

```

## Source Code Explanation

### 1. `class Heap`
This class represents a Max Heap, with functions to insert elements, delete the root element, and print the heap contents. It uses an array `arr` with 1-based indexing (index 0 is unused).

#### Attributes:
- `arr[100]`: Fixed-size array to store heap elements.
- `size`: Tracks the number of elements in the heap.

#### Constructor:
```cpp
Heap() {
    arr[0] = -1; // Initialize array with -1 at index 0 (1-based indexing)
    size = 0;    // Initial size of heap is 0
}
```
This sets up the heap array and initializes `size` to 0.

### 2. `void insert(int value)`
Inserts a new value into the heap, maintaining the Max Heap property by "heapifying up."

```cpp
size++;
int index = size;
arr[index] = value;
```
Increases the heap size by 1 and places the new value at the end of the heap.

```cpp
while (index > 1) {
    int parent = index / 2;
    if (arr[parent] < arr[index]) {
        swap(arr[parent], arr[index]);
        index = parent;  // Move up to parent
    } else {
        return;
    }
}
```
This loop compares the inserted element with its parent and swaps if it’s larger, to maintain the Max Heap property.

### 3. `void deleteFromHeap()`
Deletes the root element (the maximum in a Max Heap) and restores the Max Heap property by "heapifying down."

```cpp
if (size == 0) {
    cout << "Nothing to delete" << endl;
    return;
}
```
Handles the edge case when the heap is empty.

```cpp
arr[1] = arr[size];
size--;
```
Replaces the root with the last element, then decreases the size.

```cpp
int i = 1;
while (i <= size) {
    int leftIndex = 2 * i;
    int rightIndex = 2 * i + 1;
    int largest = i;

    if (leftIndex <= size && arr[largest] < arr[leftIndex]) {
        largest = leftIndex;
    }
    if (rightIndex <= size && arr[largest] < arr[rightIndex]) {
        largest = rightIndex;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        i = largest;
    } else {
        return;
    }
}
```
This loop ensures the Max Heap property by moving the new root down if needed, swapping it with the largest child.

### 4. `void print()`
Prints all elements in the heap from index 1 to `size`.

```cpp
for (int i = 1; i <= size; i++) {
    cout << arr[i] << " ";
}
cout << endl;
```
This simple loop prints each element of the heap.

### 5. `void max_heapify(int arr[], int n, int i)`
Converts a subtree rooted at index `i` into a Max Heap, ensuring the largest element is at the root.

```cpp
int largest = i;
int left = 2 * i;
int right = 2 * i + 1;
```
Calculates `largest`, `left`, and `right` child indices.

```cpp
if (left <= n && arr[largest] < arr[left]) largest = left;
if (right <= n && arr[largest] < arr[right]) largest = right;
```
Compares the root with its children and sets `largest` to the index of the largest value.

```cpp
if (largest != i) {
    swap(arr[largest], arr[i]);
    max_heapify(arr, n, largest);
}
```
Swaps the root with the largest child if needed and calls `max_heapify` recursively on the affected subtree.

### 6. `void min_heapify(int arr[], int n, int i)`
Similar to `max_heapify`, but it arranges elements in Min Heap order.

```cpp
int smallest = i;
int left = 2 * i + 1;
int right = 2 * i + 2;
```
Calculates `smallest`, `left`, and `right` indices for 0-based indexing.

```cpp
if (left < n && arr[smallest] > arr[left]) smallest = left;
if (right < n && arr[smallest] > arr[right]) smallest = right;
```
Finds the smallest value among root and children.

```cpp
if (smallest != i) {
    swap(arr[smallest], arr[i]);
    min_heapify(arr, n, smallest);
}
```
Swaps if needed and calls `min_heapify` recursively to restore the Min Heap property.

### 7. `void maxHeapSort(int arr[], int n)`
Sorts an array in ascending order by converting it to a Max Heap and repeatedly moving the largest element to the end.

```cpp
for (int i = n / 2; i > 0; i--) {
    max_heapify(arr, n, i);
}
```
Converts the array into a Max Heap.

```cpp
for (int i = n; i > 1; i--) {
    swap(arr[1], arr[i]);
    max_heapify(arr, i - 1, 1);
}
```
Swaps the root with the last unsorted element, reducing the heap size by 1 each time.

### 8. `void minHeapSort(int arr[], int n)`
Sorts an array in descending order by converting it to a Min Heap and moving the smallest element to the end.

```cpp
for (int i = n / 2 - 1; i >= 0; i--) {
    min_heapify(arr, n, i);
}
```
Converts the array into a Min Heap.

```cpp
for (int i = n - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    min_heapify(arr, i, 0);
}
```
Swaps the root with the last unsorted element, reducing the heap size by 1.

### Example Usage
1. **Max Heap Operations**:
   ```cpp
   Heap h;
   h.insert(50);
   h.insert(55);
   h.insert(53);
   h.insert(52);
   h.insert(54);
   ```
   - The `insert` method adds elements and heapifies up to maintain the Max Heap property.
   - `h.deleteFromHeap();` removes the root element, restoring the Max Heap structure.

2. **Building Max Heap from Array**:
   ```cpp
   int max_arr[6] = {-1, 54, 53, 55, 52, 50}; // 1-based indexing
   int n = 5;
   for (int i = n / 2; i > 0; i--) {
       max_heapify(max_arr, n, i);
   }
   ```
   Converts `max_arr` to a Max Heap.

3. **Max Heap Sort**:
   ```cpp
   maxHeapSort(max_arr, n);
   ```
   Sorts the array in ascending order.

4. **Min Heap and Sorting**:
   ```cpp
   int min_arr[5] = {54, 53, 55, 52, 50};
   int m = 5;
   for (int i = m / 2 - 1; i >= 0; i--) {
       min_heapify(min_arr, m, i);
   }
   minHeapSort(min_arr, m);
   ```
   Converts `min_arr` to a Min Heap and sorts it in descending order. 

## Example output 
Let's go through the code step by step and observe its expected output.

1. **Heap Class Operations (Insert and Delete)**
    - Insert values `50, 55, 53, 52, 54` into a max heap and print it.
    - Delete the root element of the max heap (largest element) and print the heap again.

2. **Array-Based Max Heap and Sorting (Ascending Order)**
    - Create a max heap from an array `{-1, 54, 53, 55, 52, 50}` and print it.
    - Perform heap sort on this max heap and print the array in ascending order.

3. **Array-Based Min Heap and Sorting (Descending Order)**
    - Create a min heap from an array `{54, 53, 55, 52, 50}` and print it.
    - Perform heap sort on this min heap and print the array in descending order.

### Expected Output

Based on the code execution, here is the expected output:

```plaintext
Max Heap after insertions:
55 54 53 50 52 
Max Heap after deletion:
54 52 53 50 

Heapify array - Max Heap
55 54 53 52 50 
Printing max sorted heap (Ascending Order)
50 52 53 54 55 

Heapify array - Min Heap
50 52 55 54 53 
Printing min sorted heap (Descending Order)
55 54 53 52 50
```

### Explanation of Output

- **Max Heap after Insertions**:
  - After inserting elements, the heap arranges to maintain max heap properties. The largest element `55` becomes the root, followed by `54` and other elements arranged in decreasing order along levels.
  
- **Max Heap after Deletion**:
  - After deleting the root element (`55`), the next largest (`54`) takes its place, and the heap property is maintained.

- **Heapify Array - Max Heap**:
  - The array `{-1, 54, 53, 55, 52, 50}` is turned into a max heap, yielding `55 54 53 52 50`.

- **Max Sorted Heap (Ascending Order)**:
  - The array is sorted in ascending order as `50 52 53 54 55` after max heap sorting.

- **Heapify Array - Min Heap**:
  - The array `{54, 53, 55, 52, 50}` is transformed into a min heap as `50 52 55 54 53`.

- **Min Sorted Heap (Descending Order)**:
  - The array is sorted in descending order as `55 54 53 52 50` after min heap sorting.
 
## Time & Space Complexities
Let's analyze the time and space complexity of each operation in the given heap source code. We'll go through the operations one by one.

### 1. **Insertion (`insert` method)**

The `insert` method adds an element to the end of the heap array and then "heapifies up" by comparing the inserted element with its parent until the max-heap property is restored.

#### Time Complexity
- In the worst case, the element needs to be moved up to the root (for example, when inserting the largest element).
- The height of a heap with `n` elements is `O(log n)`, so in the worst case, `insert` takes `O(log n)` time.

#### Space Complexity
- This operation uses a constant amount of additional space, so the space complexity is `O(1)`.

### 2. **Deletion (`deleteFromHeap` method)**

The `deleteFromHeap` method removes the root element of the heap, replaces it with the last element, and then "heapifies down" to restore the max-heap property.

#### Time Complexity
- After removing the root, `deleteFromHeap` needs to perform "heapify down," which in the worst case goes from the root to the leaf level.
- The time complexity for this operation is `O(log n)`.

#### Space Complexity
- The operation only uses a constant amount of additional space, so the space complexity is `O(1)`.

### 3. **Printing the Heap (`print` method)**

The `print` method simply iterates through the heap array and prints each element.

#### Time Complexity
- This operation has to visit each element once, so its time complexity is `O(n)`.

#### Space Complexity
- It uses a constant amount of additional space (for the loop variable), so the space complexity is `O(1)`.

### 4. **Max-Heapify (`max_heapify` function)**

The `max_heapify` function ensures the max-heap property for a subtree rooted at a given index `i`. It compares the value at `i` with its children and recursively swaps it with the largest child if necessary.

#### Time Complexity
- In the worst case, the function will go down to the leaf level, resulting in a time complexity of `O(log n)`.

#### Space Complexity
- Since this function is recursive, the space complexity depends on the recursion stack depth, which in the worst case is `O(log n)` due to the height of the heap.

### 5. **Min-Heapify (`min_heapify` function)**

The `min_heapify` function ensures the min-heap property for a subtree rooted at a given index `i`. Similar to `max_heapify`, it compares the value at `i` with its children and recursively swaps it with the smallest child if necessary.

#### Time Complexity
- Similar to `max_heapify`, the worst-case time complexity is `O(log n)`.

#### Space Complexity
- This function is also recursive, and its space complexity depends on the recursion stack depth, which is `O(log n)`.

### 6. **Max Heap Sort (`maxHeapSort` function)**

The `maxHeapSort` function sorts an array in ascending order using a max-heap. It first builds a max-heap and then repeatedly extracts the maximum element (root) and places it at the end of the array.

#### Time Complexity
- Building the max-heap initially takes `O(n)` time.
- Each extraction operation takes `O(log n)`, and we perform it `n - 1` times, so the extraction phase takes `O(n log n)`.
- Therefore, the overall time complexity is `O(n log n)`.

#### Space Complexity
- The function operates in-place and uses only a constant amount of extra space, so the space complexity is `O(1)`.

### 7. **Min Heap Sort (`minHeapSort` function)**

The `minHeapSort` function sorts an array in descending order using a min-heap. It first builds a min-heap and then repeatedly extracts the minimum element (root) and places it at the end of the array.

#### Time Complexity
- Building the min-heap initially takes `O(n)` time.
- Each extraction operation takes `O(log n)`, and we perform it `n - 1` times, so the extraction phase takes `O(n log n)`.
- Therefore, the overall time complexity is `O(n log n)`.

#### Space Complexity
- The function operates in-place and uses only a constant amount of extra space, so the space complexity is `O(1)`.

### Summary Table

| Operation         | Time Complexity | Space Complexity |
|-------------------|-----------------|------------------|
| **Insertion**     | `O(log n)`      | `O(1)`          |
| **Deletion**      | `O(log n)`      | `O(1)`          |
| **Print**         | `O(n)`          | `O(1)`          |
| **Max-Heapify**   | `O(log n)`      | `O(log n)`      |
| **Min-Heapify**   | `O(log n)`      | `O(log n)`      |
| **Max Heap Sort** | `O(n log n)`    | `O(1)`          |
| **Min Heap Sort** | `O(n log n)`    | `O(1)`          |

### Examples of Complexity Analysis

1. **Insertion Example**: 
   - If we insert a new element into a heap of size 7, in the worst case, it may need to move up `log₂(7) ≈ 3` levels, resulting in an `O(log n)` time complexity.

2. **Max-Heapify Example**: 
   - Applying `max_heapify` on a heap with height 4 (e.g., `n = 15`) may require up to 4 recursive calls, so its time complexity is `O(log n)`.

3. **Heap Sort Example**: 
   - Sorting a max-heap of size 10 would take `O(10 log 10)` time in the worst case, as each extraction and heapify operation runs in `O(log n)`. 

Overall, the heap operations are efficient, with logarithmic complexities for most operations, making them suitable for priority queues and sorting applications.
