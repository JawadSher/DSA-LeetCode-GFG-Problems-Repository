<h1 align='center'>What is - Stack - Data - Structure</h1>

A **stack** is a linear data structure that follows the **LIFO** (Last In, First Out) principle. This means that the last element added to the stack will be the first one to be removed. Imagine a stack of plates where you can only take the top plate off the stack. The plate that was placed last is removed first.

### Key Stack Operations:
1. **Push**: Adds an element to the top of the stack.
2. **Pop**: Removes the topmost element from the stack.
3. **Top/Peek**: Retrieves the topmost element without removing it.
4. **IsEmpty**: Checks whether the stack is empty.
5. **Size**: Returns the number of elements in the stack.

Stacks can be implemented using arrays, linked lists, or dynamic data structures like the `stack` container in C++'s Standard Template Library (STL).

---

### Explanation of the Source Code

```cpp
#include <iostream>
#include <stack>
using namespace std;
```
The above lines include the necessary headers for input/output (`iostream`) and stack operations (`stack`). The `using namespace std;` allows us to avoid prefixing every standard function or class with `std::`.

---

#### 1. **Stack Creation**
```cpp
stack<int> s;
```
Here, we create a stack `s` that stores `int` data types. This stack can hold integer values.

- **Time Complexity**: O(1) (Constant time to initialize)
- **Space Complexity**: O(1) (No significant memory usage at initialization)

---

#### 2. **Push Operation**
```cpp
s.push(3);
s.push(5);
s.push(6);
s.push(8);
```
The `push()` operation adds elements to the top of the stack. In this case, we push the integers `3`, `5`, `6`, and `8` into the stack. After these operations, the stack looks like this (from bottom to top):
```
3 -> 5 -> 6 -> 8 (top)
```

- **Time Complexity**: O(1) (Each push operation takes constant time)
- **Space Complexity**: O(1) per push (Each integer takes constant space)

---

#### 3. **Pop Operation**
```cpp
s.pop();
```
The `pop()` operation removes the topmost element from the stack. In this case, it removes `8`, leaving the stack as:
```
3 -> 5 -> 6 (top)
```

- **Time Complexity**: O(1) (Removing the top element takes constant time)
- **Space Complexity**: O(1) (No extra space required)

---

#### 4. **Top Operation**
```cpp
cout << "Top Element : " << s.top() << endl;
```
The `top()` function retrieves the topmost element without removing it. After the pop operation, the top element is now `6`. Hence, this line prints:
```
Top Element: 6
```

- **Time Complexity**: O(1) (Accessing the top element takes constant time)
- **Space Complexity**: O(1) (No extra space required)

---

#### 5. **Empty Check**
```cpp
if(s.empty()) {
    cout<< "Stack is Empty" << endl;
} else {
    cout<< "Stack is Not Empty" << endl;
}
```
The `empty()` function checks whether the stack contains any elements. Since the stack still has three elements (`3`, `5`, and `6`), it will print:
```
Stack is Not Empty
```

- **Time Complexity**: O(1) (Checking if the stack is empty is a constant time operation)
- **Space Complexity**: O(1) (No extra space required)

---

#### 6. **Size Operation**
```cpp
cout << "Size of stack is : " << s.size() << endl;
```
The `size()` function returns the number of elements currently in the stack. Since we pushed 4 elements and popped 1, the stack now has 3 elements. This line prints:
```
Size of stack is: 3
```

- **Time Complexity**: O(1) (Fetching the size of the stack takes constant time)
- **Space Complexity**: O(1) (No extra space required)

---

### Summary of Time and Space Complexities

| Operation | Time Complexity | Space Complexity |
|-----------|-----------------|------------------|
| Push      | O(1)            | O(1) per element |
| Pop       | O(1)            | O(1)             |
| Top       | O(1)            | O(1)             |
| Empty     | O(1)            | O(1)             |
| Size      | O(1)            | O(1)             |

### Example Flow:

1. **Initial stack**: empty
2. **Push 3, 5, 6, 8** → Stack becomes: `3 -> 5 -> 6 -> 8`
3. **Pop 8** → Stack becomes: `3 -> 5 -> 6`
4. **Top element**: 6
5. **Check empty**: Stack is not empty
6. **Stack size**: 3 elements in the stack

This demonstrates how the stack operates in LIFO order, with efficient constant-time operations for push, pop, and accessing the top element.
