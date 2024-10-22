<h1 align='center'>(Deque) Doubly - Ended - Queue - Example</h1>
A **Doubly Ended Queue** (deque) is a data structure that allows insertion and deletion of elements from both ends (front and back). This flexibility makes deques more versatile than standard queues or stacks, as they can be used in various scenarios where elements need to be added or removed from both ends.

### Features of a Deque

1. **Insertion/Deletion from Both Ends**: Elements can be added or removed from the front or back.
2. **Dynamic Size**: Deques can grow and shrink in size dynamically, making them efficient for memory usage.
3. **Random Access**: Unlike linked lists, deques allow access to elements in constant time, making them efficient for certain operations.

### Problem Statement

**Problem Statement**: Implement a basic deque that supports the following operations:
1. **Insert Front**: Insert an element at the front of the deque.
2. **Insert Back**: Insert an element at the back of the deque.
3. **Delete Front**: Remove an element from the front of the deque.
4. **Delete Back**: Remove an element from the back of the deque.
5. **Get Front**: Retrieve the front element without removing it.
6. **Get Back**: Retrieve the back element without removing it.
7. **Check Empty**: Determine if the deque is empty.
8. **Get Size**: Retrieve the current size of the deque.

### Examples

1. **Example 1**:
   - **Operations**: Insert 10, 20, 30 into the back. Insert 5, 9 into the front. Delete from back and front.
   - **Initial Deque**: `[]`
   - **After inserting 10, 20, 30**: `[10, 20, 30]`
   - **After inserting 5, 9 at front**: `[9, 5, 10, 20, 30]`
   - **After deleting from back**: `[9, 5, 10, 20]`
   - **After deleting from front**: `[5, 10, 20]`

2. **Example 2**:
   - **Operations**: Start with an empty deque, insert 1, insert 2, delete from front, get front and back.
   - **Initial Deque**: `[]`
   - **After inserting 1, 2**: `[1, 2]`
   - **After deleting from front**: `[2]`
   - **Front Value**: `2`, **Back Value**: `2`

### Complexity Analysis

1. **Time Complexity**:
   - **Insertion** (front or back): O(1) — Adding an element at either end takes constant time.
   - **Deletion** (front or back): O(1) — Removing an element from either end also takes constant time.
   - **Access (front or back)**: O(1) — Retrieving elements from either end takes constant time.
   - **Check Empty**: O(1) — Checking if the deque is empty is constant time.
   - **Get Size**: O(1) — Retrieving the size of the deque is constant time.

2. **Space Complexity**:
   - The space complexity of a deque is O(n), where n is the number of elements stored in it. This is because we need to allocate memory for n elements.

### Example Implementation

The following code demonstrates the basic operations of a deque using the C++ Standard Library:

```cpp
#include <iostream>
#include <deque>
using namespace std;

int main() {
    // deque creation
    deque<int> dq;

    // push back
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    dq.push_back(40);

    cout << "Size of Deque is : " << dq.size() << endl;

    cout << "Front Value : " << dq.front() << endl;  // Output: 10
    cout << "Last Value : " << dq.back() << endl;   // Output: 40

    // push front
    dq.push_front(5);
    dq.push_front(9);

    cout << "After push front - Front Value : " << dq.front() << endl;  // Output: 9
    cout << "After push front - Last Value : " << dq.back() << endl;   // Output: 40

    // pop back
    dq.pop_back();
    cout << "After pop back - Front Value : " << dq.front() << endl;   // Output: 9
    cout << "After pop back - Last Value : " << dq.back() << endl;    // Output: 30

    // pop front
    dq.pop_front();
    cout << "After pop front - Front Value : " << dq.front() << endl;  // Output: 5
    cout << "After pop front - Last Value : " << dq.back() << endl;   // Output: 30

    // Check Empty
    if(dq.empty()) cout << "Deque is Empty" << endl;
    else cout << "Deque is Not Empty" << endl;

    // Check Size
    cout << "Size of Deque is : " << dq.size() << endl; // Output: 2
    return 0;
}
```

### Conclusion

Deques are highly versatile and efficient data structures that offer both insertion and deletion capabilities at both ends. Their constant-time complexity for the primary operations makes them suitable for various applications, including task scheduling, handling buffers, and more.
