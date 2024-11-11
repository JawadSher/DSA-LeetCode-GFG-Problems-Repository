<h1 align='center'>Heap - Data - Structure - Example STL</h1>

In C++, the Standard Template Library (STL) provides an efficient way to implement heaps (priority queues) using the `priority_queue` container. This makes it easy to create both max-heaps and min-heaps without having to implement the heap operations manually. Let’s go over the code you provided and explain each part, as well as the specifics of using STL for heaps.

## Source code
```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  // Creating Max and Min Heap using STL.

  // ------ Creation of Max Heap ------
  cout << "------ Creation of Max Heap ------" << endl;
  priority_queue<int> max_pq;  // Max-Heap by default

  // Adding elements to the Max-Heap
  max_pq.push(4);
  max_pq.push(2);
  max_pq.push(5);
  max_pq.push(3);

  // Displaying the top element of the Max-Heap
  cout << "Element at Top : " << max_pq.top() << endl;  // Should display the maximum element
  max_pq.pop();  // Removes the top (maximum) element
  cout << "Element at Top : " << max_pq.top() << endl;  // Displays the new top element after pop

  // Displaying the size of the Max-Heap
  cout << "Size of priority queue : " << max_pq.size() << endl;

  // Checking if the Max-Heap is empty
  if (max_pq.empty())
    cout << "Priority queue is empty" << endl;
  else
    cout << "Priority queue is not empty" << endl;

  // ------ Creation of Min Heap ------
  cout << endl << "------ Creation of Min Heap ------" << endl;
  priority_queue<int, vector<int>, greater<int>> min_pq;  // Min-Heap

  // Adding elements to the Min-Heap
  min_pq.push(4);
  min_pq.push(2);
  min_pq.push(5);
  min_pq.push(3);

  // Displaying the top element of the Min-Heap
  cout << "Element at Top : " << min_pq.top() << endl;  // Should display the minimum element
  min_pq.pop();  // Removes the top (minimum) element
  cout << "Element at Top : " << min_pq.top() << endl;  // Displays the new top element after pop

  // Displaying the size of the Min-Heap
  cout << "Size of priority queue : " << min_pq.size() << endl;

  // Checking if the Min-Heap is empty
  if (min_pq.empty())
    cout << "Priority queue is empty" << endl;
  else
    cout << "Priority queue is not empty" << endl;

  return 0;
}

```

## Source Code Explanation

1. **Including Libraries**
   ```cpp
   #include <iostream>
   #include <queue>
   #include <vector>
   using namespace std;
   ```

   - `iostream`: Used for input and output.
   - `queue`: Contains the `priority_queue` class, which is used to implement heaps.
   - `vector`: Required when we use `priority_queue` with a custom comparator (for min-heaps in this example).

2. **Creating a Max-Heap**

   ```cpp
   priority_queue<int> max_pq;  // Max-Heap by default
   ```

   - The default `priority_queue` in C++ is a max-heap, meaning the largest element has the highest priority.
   - We can add elements using `push`, and the element with the highest value will be at the top.

3. **Operations on Max-Heap**

   ```cpp
   max_pq.push(4);
   max_pq.push(2);
   max_pq.push(5);
   max_pq.push(3);
   ```

   - The `push` function inserts elements into the heap.
   - Since `priority_queue` is a max-heap by default, after adding these elements, the heap will automatically arrange them so the maximum element is at the top.

4. **Accessing and Removing Elements**

   ```cpp
   cout << "Element at Top : " << max_pq.top() << endl;  // Displays the maximum element
   max_pq.pop();  // Removes the maximum element (top)
   cout << "Element at Top : " << max_pq.top() << endl;
   ```

   - `top`: Returns the largest element (the root of the max-heap) without removing it.
   - `pop`: Removes the largest element from the heap. After `pop`, the next largest element moves to the top.

5. **Checking Size and Emptiness**

   ```cpp
   cout << "Size of priority queue : " << max_pq.size() << endl;
   if (max_pq.empty())
       cout << "Priority queue is empty" << endl;
   else
       cout << "Priority queue is not empty" << endl;
   ```

   - `size()`: Returns the number of elements in the heap.
   - `empty()`: Checks if the heap is empty.

6. **Creating a Min-Heap**

   ```cpp
   priority_queue<int, vector<int>, greater<int>> min_pq;  // Min-Heap
   ```

   - Unlike the default max-heap, a min-heap requires a custom comparator.
   - `greater<int>` specifies that the heap should order elements in ascending order, making it a min-heap.
   - `vector<int>` is the underlying container used to store the heap elements.

7. **Operations on Min-Heap**

   The operations (`push`, `top`, `pop`, `size`, `empty`) work similarly to those in the max-heap. However, because of the `greater<int>` comparator, the smallest element will be at the top.

---

### STL Implementation of `priority_queue`

The `priority_queue` class in the STL provides an implementation of a binary heap:

1. **Max-Heap (Default)**
   - The default `priority_queue` in C++ is implemented as a max-heap, where the largest element is at the root.
   - The internal representation is typically an array, where each parent node is greater than its child nodes.

2. **Min-Heap**
   - To create a min-heap, we can pass a custom comparator, like `greater<int>`.
   - This changes the heap property to maintain the smallest element at the root, rather than the largest.

### Complexity Analysis

- **Insertion (`push`)**: \(O(\log n)\)
- **Accessing Top Element (`top`)**: \(O(1)\)
- **Removing Top Element (`pop`)**: \(O(\log n)\)

### Example Output

For the given input elements, the output would be:

```plaintext
------ Creation of Max Heap ------
Element at Top : 5
Element at Top : 4
Size of priority queue : 3
Priority queue is not empty

------ Creation of Min Heap ------
Element at Top : 2
Element at Top : 3
Size of priority queue : 3
Priority queue is not empty
```

### Summary

The `priority_queue` in C++ is a flexible and efficient way to manage heaps. The default max-heap can be used directly for cases where the largest element should be given priority, and a min-heap can be created by specifying a custom comparator. Each of these operations is optimized to provide logarithmic time complexity for insertions and deletions, making `priority_queue` suitable for priority-based task management and similar applications.
