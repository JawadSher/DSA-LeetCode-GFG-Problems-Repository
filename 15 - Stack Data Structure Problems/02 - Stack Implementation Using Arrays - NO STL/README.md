<h1 align='center'>Stack - Implementation - Using - Arrays</h1>

In addition to using a class, stacks can also be implemented using arrays. This is one of the most basic and efficient ways to implement a stack since arrays allow fast, direct access to elements.

---

### What is a Stack?

A **stack** is a linear data structure that follows the **LIFO** (Last In, First Out) principle. The last element that is inserted into the stack is the first one to be removed.

- **Push**: Insert an element into the stack.
- **Pop**: Remove the top element from the stack.
- **Peek (Top)**: View the top element without removing it.
- **IsEmpty**: Check if the stack is empty.

---

### Stack Using Arrays: Key Characteristics

- **Array-based** stacks use a fixed-size array to store elements.
- Operations like **push**, **pop**, and **peek** are performed in constant time, i.e., O(1).
- The main limitation of array-based stacks is the fixed size of the array, meaning once the stack is full, new elements cannot be pushed without resizing (which is not covered in basic array-based implementations).

### Explanation of the Source Code

This C++ program implements a stack using a **class** and **dynamic memory allocation** (using pointers). Here's a step-by-step explanation of the code, along with the key operations, time complexity, and space complexity analysis.

---

### 1. **Class Definition**

```cpp
class Stack {
  public:
    int *arr;
    int top;
    int size;
```
Here, a class named `Stack` is created with the following **properties**:
- `arr`: A dynamically allocated array to store stack elements.
- `top`: An integer that represents the index of the topmost element in the stack. It is initialized to `-1`, meaning the stack is empty.
- `size`: An integer that defines the maximum capacity of the stack.

---

### 2. **Constructor**

```cpp
Stack(int size){
    this -> size = size;
    arr = new int[size];
    top = -1;
}
```
The constructor takes a parameter `size` to initialize the stack with a maximum capacity. The array `arr` is dynamically allocated using `new`. The `top` is initialized to `-1`, indicating that the stack is initially empty.

- **Time Complexity**: O(1) (Constant time to allocate memory and initialize properties)
- **Space Complexity**: O(N), where N is the size of the stack

---

### 3. **Push Operation**

```cpp
void push(int element){
    if(size - top > 1){
      top++;
      arr[top] = element;
    } else {
      cout << "Stack Overflow" << endl;
    }
}
```
The `push()` function inserts an element into the stack. Before adding an element, it checks if there is space in the stack. If there is, the `top` is incremented, and the element is placed at that index in the array. If the stack is full, it prints "Stack Overflow."

Example:
- Initially, `top = -1`.
- After `push(10)`, `arr[0] = 10` and `top = 0`.
- After `push(20)`, `arr[1] = 20` and `top = 1`, and so on.

- **Time Complexity**: O(1) (Each push operation takes constant time)
- **Space Complexity**: O(1) (No extra space is required)

---

### 4. **Pop Operation**

```cpp
void pop(){
    if(top >= 0){
      top--;
    } else {
      cout << "Stack Underflow" << endl;
    }
}
```
The `pop()` function removes the topmost element from the stack. It checks if the stack is not empty (`top >= 0`), and then decrements the `top`. If the stack is already empty, it prints "Stack Underflow."

Example:
- Before `pop()`, the stack contains `10, 20, 30` with `top = 2`.
- After `pop()`, `top = 1`, meaning the top element (`30`) has been removed.

- **Time Complexity**: O(1) (Each pop operation takes constant time)
- **Space Complexity**: O(1) (No extra space is required)

---

### 5. **Peek Operation (Top Element)**

```cpp
int peek(){
    if(top >= 0){
      return arr[top];
    } else {
      cout << "Stack is Empty" << endl;
      return -1;
    }
}
```
The `peek()` function returns the value of the topmost element without removing it. If the stack is not empty (`top >= 0`), it returns `arr[top]`. If the stack is empty, it prints "Stack is Empty" and returns `-1`.

Example:
- After pushing `10, 20, 30`, the top element is `30`, and `peek()` will return `30`.

- **Time Complexity**: O(1) (Accessing the top element takes constant time)
- **Space Complexity**: O(1) (No extra space is required)

---

### 6. **IsEmpty Operation**

```cpp
bool isEmpty(){
    if(top == -1){
      return true;
    } else {
      return false;
    }
}
```
The `isEmpty()` function checks whether the stack is empty. If `top == -1`, it returns `true`, indicating that the stack is empty. Otherwise, it returns `false`.

Example:
- After pushing `10, 20, 30`, the stack is not empty, so `isEmpty()` will return `false`.
- If no elements have been pushed (or all have been popped), it will return `true`.

- **Time Complexity**: O(1) (Constant time to check if the stack is empty)
- **Space Complexity**: O(1) (No extra space is required)

---

### 7. **Main Function**

```cpp
int main() {
  // create a Stack
  Stack st(5);

  // insert elements
  st.push(10);
  st.push(20);
  st.push(30);

  // Getting the Top element
  cout <<"Top Element is : "<< st.peek() << endl;

  // Remove the top Element;
  st.pop();

  // Getting the Top element
  cout <<"After Pop - Top Element is : "<< st.peek() << endl;

  // Is Stack empty or not
  if(st.isEmpty()){
    cout << "Stack is Empty" <<endl;
  }else{
    cout << "Stack is Not Empty" << endl;
  }
  return 0;
}
```
The `main()` function demonstrates how to use the `Stack` class.

- **Step 1**: A stack `st` of size `5` is created.
- **Step 2**: Elements `10`, `20`, and `30` are pushed into the stack.
- **Step 3**: The topmost element is retrieved using `peek()`, which returns `30`.
- **Step 4**: The `pop()` function removes the top element (`30`), leaving `10, 20` in the stack.
- **Step 5**: The new topmost element is retrieved using `peek()`, which now returns `20`.
- **Step 6**: The `isEmpty()` function checks if the stack is empty, and since there are still elements (`10, 20`), it prints "Stack is Not Empty."

---

### Time and Space Complexity Summary

| Operation  | Time Complexity | Space Complexity |
|------------|-----------------|------------------|
| Push       | O(1)            | O(1)             |
| Pop        | O(1)            | O(1)             |
| Peek (Top) | O(1)            | O(1)             |
| IsEmpty    | O(1)            | O(1)             |
| Constructor| O(1)            | O(N) (where N is the stack size) |

---

### Example Flow

1. **Initial Stack**: Empty (`top = -1`).
2. **Push 10, 20, 30** → Stack becomes: `10 -> 20 -> 30 (top)`.
3. **Top element (peek)** → `30`.
4. **Pop** → Removes `30`, stack becomes: `10 -> 20 (top)`.
5. **Top element (peek)** → `20`.
6. **Is Stack empty** → "Stack is Not Empty".

This class-based implementation shows a manual stack structure with basic operations, and memory is dynamically managed for the stack size, allowing efficient operations.
