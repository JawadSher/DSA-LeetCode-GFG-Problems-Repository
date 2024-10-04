<h1 align='center'>Singly - Linked - List - Data Structure</h1>

A **singly linked list** is a type of linked list where each node contains two components:
1. **Data**: The value stored in the node.
2. **Next pointer**: A reference to the next node in the sequence.

Unlike a doubly linked list, a singly linked list only allows traversal in **one direction**—from the first node (called the **head**) to the last node.

### Structure of a Singly Linked List Node:
Each node in a singly linked list has:
- A **data field** to store the value.
- A **pointer to the next node** (`next`).

### Example of a Singly Linked List:

Imagine a list with three nodes: `10`, `20`, and `30`. A singly linked list would look like this:

```
[10] -> [20] -> [30] -> NULL
```

- **Forward Traversal**: You can only go from `10` to `30` by following the `next` pointers.
  - Start at `10`, move to `20`, then to `30`.

### Operations:
1. **Insertion**: You can insert a new node at various positions (beginning, middle, or end) of the list.
   - Example: Inserting `15` between `10` and `20`:
     ```
     [10] -> [15] -> [20] -> [30] -> NULL
     ```

2. **Deletion**: A node can be deleted from the list, and the `next` pointers are adjusted to maintain the structure.
   - Example: Deleting `20` from the list:
     ```
     [10] -> [30] -> NULL
     ```

### Advantages of a Singly Linked List:
- **Less memory usage**: Each node only needs a single `next` pointer, unlike doubly linked lists that need two.
- **Simplicity**: Singly linked lists are simpler to implement and manage compared to doubly linked lists.

### Disadvantages:
- **Unidirectional traversal**: You can only traverse the list in one direction (from head to end). You cannot go backward.
- **Inefficient search**: To find a specific element, you may need to traverse the entire list, as there is no direct access to elements in the middle.

### Common Uses:
- **Queue structures**: Where elements are processed in a first-in, first-out (FIFO) manner.
- **Managing dynamic data**: When the size of the dataset changes frequently, singly linked lists provide flexibility in memory management.

## Problem Statement: Implementing a Singly Linked List

You are tasked with implementing a **Singly Linked List** data structure. A singly linked list consists of nodes, where each node contains a value and a pointer to the next node in the list. Your implementation should support the following operations:

### Operations
1. **Insert at Head**: Add a new node at the beginning of the list.
2. **Insert at Tail**: Add a new node at the end of the list.
3. **Insert at Any Position**: Insert a new node at a specific position in the list.
4. **Insert After**: Insert a new node after a specified node with a given value.
5. **Insert Before**: Insert a new node before a specified node with a given value.
6. **Delete Head Node**: Remove the head node from the list.
7. **Delete Tail Node**: Remove the tail node from the list.
8. **Delete Node at Position**: Remove a node at a specific position in the list.
9. **Delete All Before**: Remove all nodes before a specified position in the list.
10. **Delete All Nodes**: Remove all nodes from the list.
11. **Total Nodes**: Count and print the total number of nodes in the list.
12. **Search Node**: Search for a node with a specific value in the list.

### Input Format
- You will receive a series of commands indicating the operation to be performed, along with the necessary parameters.

### Output Format
- For each operation, if an error occurs (e.g., a specified target value is not found or the position is out of bounds), print an appropriate error message.
- Print the linked list after each successful operation that modifies the list.

### Example

**Input:**
```
insertAtHead(10)
insertAtTail(20)
insertAtAnyPosition(2, 15)
print()
insertAfter(15, 18)
print()
deleteNodeAtPosition(1)
print()
deleteAllBefore(2)
print()
```

**Output:**
```
List: 10 -> 20
List: 10 -> 15 -> 20
List: 15 -> 20
List: 20
```

### Constraints
- Ensure proper memory management to prevent memory leaks when deleting nodes.

## Problem Solution 
```cpp
#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int d){
            this -> data = d;
            this -> next = NULL; 
        }

        ~Node(){
            int value = this -> data;
            if(this -> next != NULL){
                delete next;
                this -> next = NULL;
            }

            cout << "Memory Free for node with data : "<< value << endl;
        }
};

void insertAtHead(Node* &head, int d){
    Node* temp = head;

    Node* node = new Node(d);
    node -> next = temp;
    head = node;
}

void insertAtTail(Node* &tail, int d){
    Node* temp = tail;

    Node* node = new Node(d);
    temp -> next = node;
    tail = node;
}

void insertAtanyPosition(Node* &tail, Node* &head, int position, int d){
    Node* temp = head;
    int count = 1;

    if(position == 1){
        insertAtHead(head, d);
        return;
    } 
    

    while(count < position-1){
        temp = temp -> next;
        count++;
    }

    if(temp -> next == NULL){
        insertAtTail(tail, d);
        return;
    }

    Node* node = new Node(d);
    node -> next = temp -> next;
    temp -> next = node;
}

void print(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }cout << endl;
}

void insertAfter(Node* &tail, Node* &head, int target, int d){
    Node* temp = head;

    if(temp -> next == NULL && temp -> data != target){
        cout << "Element Not Exist" << endl;
    }

    while(temp->data != target){
        temp = temp -> next;
    }

    if(temp->next == NULL){
        insertAtTail(tail, d);
        return;
    }

    Node* node = new Node(d);
    node -> next = temp -> next;
    temp -> next = node;
}

void insertBefore(Node* &tail, Node* &head, int target, int d){
    Node* temp = head;

    if(temp -> data == target){
        insertAtHead(head, d);
        return;
    }

    while(temp -> next -> data != target){
        temp = temp -> next;
    }

    if(temp -> next == NULL && temp -> data == target){
        insertAtTail(tail, d);
        return;
    }

    Node* node = new Node(d);
    node -> next = temp -> next;
    temp -> next = node;
}

void deleteNodeAtPosition(Node* &tail, Node* &head, int position){
    
    if(position == 1){
        Node* temp = head;
        head = head -> next;
        if(head == NULL){
            tail = NULL;
        }

        temp -> next = NULL;
        delete temp;
        return;
    }
    
    Node* current = head;
    Node* previous = NULL;

    int count = 1;
    while(count < position){
        previous = current;
        current = current -> next;
        count++;
    }

    if(current -> next == NULL){
        tail = previous;
    }

    previous -> next = current -> next;
    current -> next = NULL;
    delete current;
}

void deleteAllAfter(Node* &head, int position){

    if(head == NULL){
        return;
    }
    
    Node* temp = head;
    int count = 1;

    while(count < position && temp != NULL){
        count++;
        temp = temp -> next;
    }

    if(temp == NULL || temp -> next == NULL){
        return;
    }

    Node* nodeToDelete = temp -> next;
    temp -> next = NULL;

    while(nodeToDelete != NULL){
        Node* nextNode = nodeToDelete -> next;
        delete nodeToDelete;
        nodeToDelete = nextNode;
    }

}

void deleteAllNodes(Node* &head){

    Node* curr = head;
    Node* prev = NULL;

    while(curr != NULL){
        prev = curr;
        curr = curr -> next;

        delete prev;
    }

    head = curr;

}

void deleteHeadNode(Node* &head){
    if(head == NULL){
        return;
    }

    Node* temp = head;

    head = head -> next;
    temp -> next = NULL;
    delete temp;
}

void deleteTailNode(Node* &head, Node* &tail){
    if(head == NULL){
        return;
    }

    if(head -> next == NULL){
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp -> next;
    }
    tail = temp;
    Node* tailNode = temp->next;
    temp->next = NULL;
    delete tailNode;
}

void deleteAllBefore(Node* &head, int position){

    if(head == NULL){
        return;
    }

    if(head->next == NULL){
        deleteHeadNode(head);
    }

    int count = 1;
    while(count < position){
        deleteHeadNode(head);
        count++;
    }
}

void totalNodes(Node* head){
    int count = 0;
    while(head != NULL){
        count++;
        head = head -> next;
    }

    cout << "Total Nodes - Length of list : " << count <<endl;
}

void searchNode(Node* head, int target){
    
    if(head->next == NULL){
        return;
    }

    while(head->data != target){
        head = head -> next;
    }

    if(head->data == target){
        cout << "Node Found : "<< head -> data <<endl;
    }else{
        cout<< "Node Not Found!"<<endl;
    }
}

int main(){
    Node* sNode = new Node(10);
    
    Node* head = sNode;
    Node* tail = sNode;

    cout<< "Head : " << head -> data <<endl;
    totalNodes(head);

    insertAtHead(head, 5);
    print(head);
    cout<< "Head : " << head -> data <<endl;
    cout<< "Tail : " << tail -> data <<endl;
    totalNodes(head);
    cout<< "-------------------------"<<endl;

    
    insertAtTail(tail, 15);
    print(head);
    cout<< "Head : " << head -> data <<endl;
    cout<< "Tail : " << tail -> data <<endl;
    totalNodes(head);
    cout<< "-------------------------"<<endl;

    insertAtanyPosition(tail, head, 2, 25);
    print(head);
    cout<< "Head : " << head -> data <<endl;
    cout<< "Tail : " << tail -> data <<endl;
    totalNodes(head);
    cout<< "-------------------------"<<endl;

    insertAfter(tail, head, 10, 13);
    print(head);
    cout<< "Head : " << head -> data <<endl;
    cout<< "Tail : " << tail -> data <<endl;
    totalNodes(head);
    cout<< "-------------------------"<<endl;

    insertBefore(tail, head, 5, 9);
    print(head);
    cout<< "Head : " << head -> data <<endl;
    cout<< "Tail : " << tail -> data <<endl;
    totalNodes(head);
    cout<< "-------------------------"<<endl;

    deleteNodeAtPosition(tail, head, 1);
    print(head);
    cout<< "Head : " << head -> data <<endl;
    cout<< "Tail : " << tail -> data <<endl;
    totalNodes(head);
    cout<< "-------------------------"<<endl;

    // deleteAllAfter(head, 1);
    // print(head);
    // cout<< "Head : " << head -> data <<endl;
    // cout<< "Tail : " << tail -> data <<endl;
    // totalNodes(head);
    // cout<< "-------------------------"<<endl;

    // deleteAllNodes(head);
    // print(head);
    // cout<< "Head : " << head -> data <<endl;
    // cout<< "Tail : " << tail -> data <<endl;
    // totalNodes(head);
    // cout<< "-------------------------"<<endl;

    // deleteHeadNode(head);
    // print(head);
    // cout<< "Head : " << head -> data <<endl;
    // cout<< "Tail : " << tail -> data <<endl;
    // totalNodes(head);
    // cout<< "-------------------------"<<endl;

    // deleteTailNode(head, tail);
    // print(head);
    // cout<< "Head : " << head -> data <<endl;
    // cout<< "Tail : " << tail -> data <<endl;
    // totalNodes(head);
    // cout<< "-------------------------"<<endl;

    searchNode(head, 13);
    cout<<"---------------" <<endl;

    deleteAllBefore(head, 3);
    print(head);
    cout<< "Head : " << head -> data <<endl;
    cout<< "Tail : " << tail -> data <<endl;
    totalNodes(head);
    cout<< "-------------------------"<<endl;

    return 0;
}
```

## Source Code Explanation

Certainly! Let’s break down the provided code function by function, explaining how each function works, along with examples to illustrate their behavior. The code implements a singly linked list with basic operations such as insertion and deletion of nodes.

### Class Definition
```cpp
class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        this->data = d;
        this->next = NULL; 
    }

    ~Node() {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory Free for node with data: " << value << endl;
    }
};
```
- **Node**: This is a class that represents a node in the linked list. It has:
  - An integer `data` to store the node's value.
  - A pointer `next` that points to the next node in the list.
  - A constructor that initializes the node with a given value and sets `next` to `NULL`.
  - A destructor that frees the memory allocated to the node and prints a message when the node is deleted.

### Function 1: `insertAtHead`
```cpp
void insertAtHead(Node*& head, int d) {
    Node* temp = head;
    Node* node = new Node(d);
    node->next = temp;
    head = node;
}
```
- **Purpose**: Inserts a new node with value `d` at the beginning of the linked list.
- **Parameters**: 
  - `Node*& head`: A reference to the head pointer of the linked list.
  - `int d`: The value to be inserted.
  
#### Example:
```cpp
Node* head = NULL;  // Start with an empty list
insertAtHead(head, 10); // List: 10
insertAtHead(head, 20); // List: 20 -> 10
```

### Function 2: `insertAtTail`
```cpp
void insertAtTail(Node*& tail, int d) {
    Node* temp = tail;
    Node* node = new Node(d);
    temp->next = node;
    tail = node;
}
```
- **Purpose**: Inserts a new node with value `d` at the end of the linked list.
- **Parameters**:
  - `Node*& tail`: A reference to the tail pointer of the linked list.
  - `int d`: The value to be inserted.

#### Example:
```cpp
Node* head = NULL;
Node* tail = NULL;
insertAtHead(head, 10); // List: 10
tail = head; // Set tail to head
insertAtTail(tail, 20); // List: 10 -> 20
```

### Function 3: `insertAtanyPosition`
```cpp
void insertAtanyPosition(Node*& tail, Node*& head, int position, int d) {
    Node* temp = head;
    int count = 1;

    if (position == 1) {
        insertAtHead(head, d);
        return;
    } 

    while (count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL) {
        insertAtTail(tail, d);
        return;
    }

    Node* node = new Node(d);
    node->next = temp->next;
    temp->next = node;
}
```
- **Purpose**: Inserts a new node with value `d` at a specified position in the linked list.
- **Parameters**:
  - `Node*& tail`: A reference to the tail pointer of the linked list.
  - `Node*& head`: A reference to the head pointer of the linked list.
  - `int position`: The position to insert the new node (1-indexed).
  - `int d`: The value to be inserted.

#### Example:
```cpp
Node* head = NULL;
Node* tail = NULL;
insertAtHead(head, 10); // List: 10
tail = head;
insertAtanyPosition(tail, head, 2, 20); // List: 10 -> 20
insertAtanyPosition(tail, head, 2, 15); // List: 10 -> 15 -> 20
```

### Function 4: `print`
```cpp
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
```
- **Purpose**: Prints the entire linked list.
- **Parameters**:
  - `Node* head`: The head pointer of the linked list.

#### Example:
```cpp
print(head); // Output: 10 15 20
```

### Function 5: `insertAfter`
```cpp
void insertAfter(Node*& tail, Node*& head, int target, int d) {
    Node* temp = head;

    if (temp->next == NULL && temp->data != target) {
        cout << "Element Not Exist" << endl;
        return;
    }

    while (temp->data != target) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        insertAtTail(tail, d);
        return;
    }

    Node* node = new Node(d);
    node->next = temp->next;
    temp->next = node;
}
```
- **Purpose**: Inserts a new node with value `d` after a node containing `target` value.
- **Parameters**:
  - `Node*& tail`: A reference to the tail pointer of the linked list.
  - `Node*& head`: A reference to the head pointer of the linked list.
  - `int target`: The value after which to insert the new node.
  - `int d`: The value to be inserted.

#### Example:
```cpp
insertAfter(tail, head, 10, 15); // List: 10 -> 15 -> 20
insertAfter(tail, head, 15, 18); // List: 10 -> 15 -> 18 -> 20
insertAfter(tail, head, 30, 25); // Output: Element Not Exist
```

### Function 6: `insertBefore`
```cpp
void insertBefore(Node*& tail, Node*& head, int target, int d) {
    Node* temp = head;

    if (temp->data == target) {
        insertAtHead(head, d);
        return;
    }

    while (temp->next->data != target) {
        temp = temp->next;
    }

    if (temp->next == NULL && temp->data == target) {
        insertAtTail(tail, d);
        return;
    }

    Node* node = new Node(d);
    node->next = temp->next;
    temp->next = node;
}
```
- **Purpose**: Inserts a new node with value `d` before a node containing the `target` value.
- **Parameters**:
  - `Node*& tail`: A reference to the tail pointer of the linked list.
  - `Node*& head`: A reference to the head pointer of the linked list.
  - `int target`: The value before which to insert the new node.
  - `int d`: The value to be inserted.

#### Example:
```cpp
insertBefore(tail, head, 15, 12); // List: 10 -> 12 -> 15 -> 18 -> 20
insertBefore(tail, head, 10, 5); // List: 5 -> 10 -> 12 -> 15 -> 18 -> 20
```

### Function 7: `deleteNodeAtPosition`
```cpp
void deleteNodeAtPosition(Node*& tail, Node*& head, int position) {
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        temp->next = NULL;
        delete temp;
        return;
    }
    
    Node* current = head;
    Node* previous = NULL;

    int count = 1;
    while (count < position) {
        previous = current;
        current = current->next;
        count++;
    }

    if (current->next == NULL) {
        tail = previous;
    }

    previous->next = current->next;
    current->next = NULL;
    delete current;
}
```
- **Purpose**: Deletes a node at a specified position in the linked list.
- **Parameters**:
  - `Node*& tail`: A reference to the tail pointer of the linked list.
  - `Node*& head`: A reference to the head pointer of the linked list.
  - `int position`: The position of the node to be deleted (1-indexed).

#### Example:
```cpp
deleteNodeAtPosition(tail, head, 1); // List: 12 -> 15 -> 18 -> 20
deleteNodeAtPosition(tail, head, 2); // List: 12 -> 18 -> 20
```

### Function 8: `deleteAllAfter`
```cpp
void deleteAllAfter(Node*& head, int position) {
    if (head == NULL) {
        return;
    }
    
    Node* temp = head;
    int count = 1;

    while (count < position && temp != NULL) {
        count++;
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        return;
    }



    Node* current = temp->next;
    temp->next = NULL;

    while (current != NULL) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}
```
- **Purpose**: Deletes all nodes after a specified position in the linked list.
- **Parameters**:
  - `Node*& head`: A reference to the head pointer of the linked list.
  - `int position`: The position after which all nodes will be deleted.

#### Example:
```cpp
deleteAllAfter(head, 2); // List: 12 -> 18
```

Certainly! Let's explain each function in the provided code for managing a singly linked list, along with examples to illustrate how they work.

### 9. `deleteAllNodes(Node* &head)`
This function deletes all nodes in the linked list, freeing the memory allocated for each node.

**Explanation**:
- It initializes two pointers: `curr` (current node) and `prev` (previous node).
- It iterates through the list, deleting each node until the end of the list is reached.
- Finally, it sets the head pointer to `NULL`.

**Example**:
```cpp
Node* head = new Node(1);
head->next = new Node(2);
head->next->next = new Node(3);

// Before deletion: 1 -> 2 -> 3
deleteAllNodes(head);
// After deletion: head should be NULL
```

### 10. `deleteHeadNode(Node* &head)`
This function deletes the head node of the linked list.

**Explanation**:
- It first checks if the list is empty. If it is, it simply returns.
- It stores the current head in a temporary pointer, updates the head to the next node, and then deletes the temporary pointer.

**Example**:
```cpp
Node* head = new Node(10);
head->next = new Node(20);

// Before deletion: 10 -> 20
deleteHeadNode(head);
// After deletion: head should point to 20
```

### 11. `deleteTailNode(Node* &head, Node* &tail)`
This function deletes the tail node of the linked list.

**Explanation**:
- It checks if the list is empty; if so, it returns.
- If there is only one node, it deletes it and sets head to `NULL`.
- If there are multiple nodes, it traverses to the second-to-last node, updates the tail pointer, deletes the last node, and sets its next pointer to `NULL`.

**Example**:
```cpp
Node* head = new Node(1);
Node* tail = head;
tail->next = new Node(2);
// Before deletion: 1 -> 2
deleteTailNode(head, tail);
// After deletion: head should point to 1, tail should point to 1
```

### 12. `deleteAllBefore(Node* &head, int position)`
This function deletes all nodes before a specified position in the list.

**Explanation**:
- If the list is empty or the head is the only node, it calls `deleteHeadNode` to delete it.
- It iterates through the list, deleting the head nodes until it reaches the specified position.

**Example**:
```cpp
Node* head = new Node(1);
head->next = new Node(2);
head->next->next = new Node(3);

// Before deletion: 1 -> 2 -> 3
deleteAllBefore(head, 2);
// After deletion: head should point to 2
```

### 13. `totalNodes(Node* head)`
This function counts and prints the total number of nodes in the linked list.

**Explanation**:
- It initializes a counter and iterates through the list, incrementing the counter for each node until the end of the list is reached.
- Finally, it prints the total count.

**Example**:
```cpp
Node* head = new Node(1);
head->next = new Node(2);
head->next->next = new Node(3);

// Count should print 3
totalNodes(head);
```

### 14. `searchNode(Node* head, int target)`
This function searches for a node with a specified target value in the linked list.

**Explanation**:
- It checks if the list is empty. If it is, it returns.
- It iterates through the list until it finds the target or reaches the end.
- If the target is found, it prints the node's value; otherwise, it prints "Node Not Found."

**Example**:
```cpp
Node* head = new Node(1);
head->next = new Node(2);
head->next->next = new Node(3);

// Searching for 2: prints "Node Found: 2"
searchNode(head, 2);
// Searching for 4: prints "Node Not Found!"
searchNode(head, 4);
```

### 15. `main()`
The main function demonstrates the functionality of the linked list by performing a series of operations.

**Explanation**:
- It initializes a linked list with one node (10) and sets head and tail to the same node.
- It performs a series of insertions (at head, tail, specific positions), deletions (at head, tail, specific positions), and searches.
- After each operation, it prints the current state of the list, the head and tail values, and the total number of nodes.

**Example Flow**:
```cpp
Node* sNode = new Node(10);
Node* head = sNode;
Node* tail = sNode;

// Perform various operations
insertAtHead(head, 5); // List: 5 -> 10
insertAtTail(tail, 15); // List: 5 -> 10 -> 15
insertAtanyPosition(tail, head, 2, 25); // List: 5 -> 25 -> 10 -> 15
deleteNodeAtPosition(tail, head, 1); // List: 25 -> 10 -> 15
searchNode(head, 13); // Node Not Found!
deleteAllBefore(head, 3); // List: 15
```

This function suite provides a comprehensive set of operations for managing a singly linked list, ensuring proper memory management and efficient manipulation of the list structure. If you have any questions or need further clarifications, feel free to ask!
