<h1 align='center'>Stack - Implementation - Using - Linked - List</h1>

To implement a stack using linked lists, you need to create two main components:
1. A **Node** class (or struct) that will store the data and the reference (or pointer) to the next node.
2. A **Stack** class that will manage the linked list and provide the typical stack operations like `push`, `pop`, `peek`, and `isEmpty`.

### Why Use Linked Lists for a Stack?
- **Dynamic Memory Allocation**: Unlike arrays where the size of the stack needs to be predefined, linked lists allow the stack to grow and shrink dynamically as needed.
- **No Size Limit**: You don’t have to worry about exceeding the capacity like you would with arrays.

### Key Operations in a Stack:
- **Push**: Add an element to the top of the stack.
- **Pop**: Remove and return the element at the top of the stack.
- **Peek**: View the top element of the stack without removing it.
- **IsEmpty**: Check whether the stack is empty.

## Source Code 
```cpp
#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        
        Node(int v){
            this -> data = v;
            this -> next = NULL;
        }
};

class Stack{
    public:
        Node* head;

        
        Stack(){
            head = NULL;

        }
        
        void push(int d){
            Node* newNode = new Node(d);
            newNode -> next = head;
            head = newNode;
        }
        
        void pushRange(int *arr, int size){
            
            for(int i = 0; i < size; i++){
                Node* newNode = new Node(arr[i]);
                newNode -> next = head;
                head = newNode;
            }
        }
        
        int pop(){
            if(isEmpty()){
                cout << "Stack is Empty" <<endl;
                return -1;
            }
            int value = head -> data;
            Node* temp = head;
            head = head -> next;
            delete temp;
            return value;
        }
        
        int peek(){
            if(isEmpty()){
                cout << "Stack is Empty" <<endl;
                return -1;
            }
            return head -> data;
        }
        
        bool isEmpty(){
            return head == NULL; 
        }
        
        void allElements(){
            Node* temp = head;
            while(temp != NULL){
                cout << temp -> data << ' ';
                temp = temp -> next;
            }
        }
};

int main(){
    Stack st;
    
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    
    int arr[5] = {50, 60, 70, 80, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    st.pushRange(arr, size);
    
    cout << "head element : " << st.peek() << endl;
    
    int value = st.pop();
    cout << "Poped Element : " << value <<endl;
    
    cout << "After poped - head element : " << st.peek() << endl;
    
    cout << "All Stack Elements : ";
    st.allElements();
    
    return 0;
}
```

## Source Code Explanation

Let’s break down the code line by line and explain how a stack can be implemented using linked lists. This explanation will include an example and how each part works in detail.

### Class Definitions

```cpp
class Node {
    public:
        int data;  // stores the integer value of the node
        Node* next;  // points to the next node in the list

        Node(int v) {
            this->data = v;  // set the data value of the node
            this->next = NULL;  // initialize the next pointer to NULL
        }
};
```
- **Purpose**: The `Node` class represents a single element in the stack. Each `Node` stores some `data` (the integer value) and a `next` pointer to the next `Node` in the stack.
- **Example**: A node could store a value like `50` and point to the next node.

```cpp
class Stack {
    public:
        Node* head;  // the head pointer refers to the top of the stack

        Stack() {
            head = NULL;  // initially, the stack is empty (head is NULL)
        }
```
- **Purpose**: The `Stack` class represents the stack itself. It manages the linked list of `Node` objects. The `head` pointer keeps track of the topmost element in the stack (the "head" of the linked list).
- **Example**: When the stack is empty, `head` is `NULL`. When we push values onto the stack, the head points to the topmost node.

### Methods

```cpp
void push(int d) {
    Node* newNode = new Node(d);  // create a new node with the value 'd'
    newNode->next = head;  // link the new node to the current top node
    head = newNode;  // make the new node the new head (top of the stack)
}
```
- **Purpose**: The `push` function adds a new element to the top of the stack.
- **Step-by-Step Example**:
  1. If the stack is empty (`head = NULL`), pushing `10` creates a new node with value `10`, and the head points to this new node.
  2. Next, pushing `20` creates a new node with value `20`. This node’s `next` pointer points to the node with `10`. Now, the head points to the node with `20`.

```cpp
void pushRange(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        Node* newNode = new Node(arr[i]);  // create a node for each array element
        newNode->next = head;  // link the new node to the current top node
        head = newNode;  // make the new node the new head (top of the stack)
    }
}
```
- **Purpose**: This function pushes multiple elements onto the stack using an array. For each element in the array, it calls the `push` logic to insert it at the top of the stack.
- **Example**: 
  - For an array `[50, 60, 70]`, it will first push `50` to the stack, making `50` the top. Then, it pushes `60`, making `60` the new top, and so on. After the entire array is pushed, `70` will be at the top of the stack.

```cpp
int pop() {
    if (isEmpty()) {
        cout << "Stack is Empty" << endl;
        return -1;
    }
    int value = head->data;  // save the value of the current top node
    Node* temp = head;  // temporarily store the current top node
    head = head->next;  // move the head to the next node in the stack
    delete temp;  // delete the old top node
    return value;  // return the popped value
}
```
- **Purpose**: The `pop` function removes and returns the top element from the stack.
- **Step-by-Step Example**:
  1. If the stack contains `[90, 80, 70]` (where `90` is at the top), calling `pop()` will remove `90`, return its value, and make `80` the new top of the stack.
  2. If the stack is empty, it will print an error message.

```cpp
int peek() {
    if (isEmpty()) {
        cout << "Stack is Empty" << endl;
        return -1;
    }
    return head->data;  // return the value at the top of the stack
}
```
- **Purpose**: The `peek` function returns the top element of the stack without removing it.
- **Example**: If the stack contains `[80, 70, 60]` (where `80` is at the top), calling `peek()` will return `80`.

```cpp
bool isEmpty() {
    return head == NULL;  // return true if the stack is empty
}
```
- **Purpose**: The `isEmpty` function checks whether the stack is empty or not.
- **Example**: It returns `true` if the stack has no elements (i.e., `head == NULL`).

```cpp
void allElements() {
    Node* temp = head;  // start at the top of the stack
    while (temp != NULL) {  // traverse through all the nodes
        cout << temp->data << ' ';  // print the value of the current node
        temp = temp->next;  // move to the next node in the stack
    }
    cout << endl;  // print a newline after displaying all elements
}
```
- **Purpose**: The `allElements` function prints all the elements in the stack.
- **Example**: If the stack contains `[80, 70, 60]`, it will print `80 70 60`.

### Main Function (Example Usage)

```cpp
int main() {
    Stack st;  // create an empty stack

    st.push(10);  // push 10 onto the stack
    st.push(20);  // push 20 onto the stack
    st.push(30);  // push 30 onto the stack
    st.push(40);  // push 40 onto the stack

    int arr[5] = {50, 60, 70, 80, 90};  // create an array of values
    int size = sizeof(arr) / sizeof(arr[0]);  // calculate the size of the array

    st.pushRange(arr, size);  // push all the elements from the array onto the stack

    cout << "head element : " << st.peek() << endl;  // print the top element (should be 90)

    int value = st.pop();  // pop the top element (90)
    cout << "Poped Element : " << value << endl;  // print the popped value

    cout << "After poped - head element : " << st.peek() << endl;  // print the new top element (should be 80)

    cout << "All Stack Elements : ";
    st.allElements();  // print all the elements in the stack

    return 0;
}
```

### Example Walkthrough:
1. **Pushing Elements**:
   - `st.push(10)` → Stack: `10`
   - `st.push(20)` → Stack: `20 -> 10`
   - `st.push(30)` → Stack: `30 -> 20 -> 10`
   - `st.push(40)` → Stack: `40 -> 30 -> 20 -> 10`
2. **Pushing an Array**:
   - Array `{50, 60, 70, 80, 90}`
   - After `pushRange(arr, size)`:
     - Stack: `90 -> 80 -> 70 -> 60 -> 50 -> 40 -> 30 -> 20 -> 10`
3. **Peeking**: `st.peek()` will return `90`.
4. **Popping**:
   - `st.pop()` will remove `90`, making `80` the new top.
   - Stack: `80 -> 70 -> 60 -> 50 -> 40 -> 30 -> 20 -> 10`
5. **Printing All Elements**:
   - `st.allElements()` will print: `80 70 60 50 40 30 20 10`.

### Explanation of How a Stack Works Using Linked List:
- **Push**: Adds a new element to the front of the linked list (top of the stack).
- **Pop**: Removes the element from the front of the linked list (top of the stack).
- **Linked List Advantage**: Unlike arrays, a linked list can dynamically grow as elements are pushed, without worrying about size constraints.
