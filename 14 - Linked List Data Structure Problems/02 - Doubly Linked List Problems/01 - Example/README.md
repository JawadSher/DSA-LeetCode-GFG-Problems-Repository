<h1 align='center'>Doubly - Linked - List - Example</h1>

## Problem Statement
This code defines a doubly linked list structure using a `Node` class and various functions for inserting and deleting nodes in the list. Let's break it down step by step with explanations for each function and provide examples for a better understanding.

## Source Code 
```cpp
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }

        cout << "Memory Free for node with data : " << value << endl;
    }
};

void insertAtHead(Node* &head, Node* &tail, int d)
{
    Node *temp = head;

    if (temp == NULL)
    {
        Node *node = new Node(d);
        head = node;
        tail = node;

        return;
    }
    else
    {

        Node *node = new Node(d);
        node->next = temp;
        temp->prev = node;

        head = node;
    }
}

void insertAtTail(Node* &head, Node *&tail, int d)
{
    Node *temp = tail;

    if(temp == NULL){
        Node* node = new Node(d);
        head = node;
        tail = node;
    }

    Node *node = new Node(d);
    temp->next = node;
    node->prev = temp;

    tail = node;
}

void insertAtanyPosition(Node *&tail, Node *&head, int position, int d)
{
    Node *temp = head;
    int count = 1;

    if (position == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }

    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(head, tail, d);
        return;
    }

    Node *node = new Node(d);
    node -> next = temp -> next;
    node -> next -> prev = node;
    temp -> next = node;
    node -> prev = temp;
}

void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAfter(Node *&tail, Node *&head, int target, int d)
{
    Node *temp = head;

    if (temp == NULL)
    {
        Node* node = new Node(d);
        head = node;
        tail = node;
        return;
    }

    while (temp->data != target)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        insertAtTail(head, tail, d);
        return;
    }

    Node *node = new Node(d);
    node -> next = temp -> next;
    node -> next -> prev = node;
    temp -> next = node;
    node -> prev = temp;
}

void insertBefore(Node *&tail, Node *&head, int target, int d)
{
    Node *temp = head;

    if (temp->data == target)
    {
        insertAtHead(head, tail, d);
        return;
    }

    while (temp->next->data != target)
    {
        temp = temp->next;
    }

    if (temp->next == NULL && temp->data == target)
    {
        insertAtTail(head, tail, d);
        return;
    }

    Node *node = new Node(d);
    node -> next = temp -> next;
    node -> next -> prev = node;
    temp -> next = node;
    node -> prev = temp;
}

void deleteHeadNode(Node *&head)
{
    if (head == NULL)
    {
        return;
    }

    Node *temp = head;

    head = head->next;
    temp -> next = NULL;
    delete temp;
}

void deleteTailNode(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        return;
    }

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }

    Node* temp = tail;
    tail = tail -> prev;
    tail -> next = NULL;
    delete temp;
}

void deleteNodeAtPosition(Node *&tail, Node *&head, int position)
{   

    if(position == 1){
        deleteHeadNode(head);
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
        deleteTailNode(head, tail);
        return;
    }

    previous -> next = current -> next;
    current -> next -> prev = previous;

    current -> prev = NULL;
    current -> next = NULL;
    delete current;
}

void deleteAllAfter(Node *&head, Node* &tail, int position)
{

    if (head == NULL)
    {
        return;
    }

    Node *temp = head;
    int count = 1;

    while (count < position && temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        return;
    }

    Node *nodeToDelete = temp->next;
    temp->next = NULL;

    while (nodeToDelete != NULL)
    {
        Node *nextNode = nodeToDelete->next;
        delete nodeToDelete;
        nodeToDelete = nextNode;
    }

    tail = temp;
}

void deleteAllNodes(Node *&head)
{

    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL)
    {
        prev = curr;
        curr = curr->next;

        delete prev;
    }

    head = curr;
}

void deleteAllBefore(Node *&head, int position)
{

    if (head == NULL)
    {
        return;
    }

    if (head->next == NULL)
    {
        deleteHeadNode(head);
    }

    int count = 1;
    while (count < position)
    {
        deleteHeadNode(head);
        count++;
    }
}

void totalNodes(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    cout << "Total Nodes - Length of list : " << count << endl;
}

void searchNode(Node *head, int target)
{

    if (head->next == NULL)
    {
        return;
    }

    while (head->data != target)
    {
        head = head->next;
    }

    if (head->data == target)
    {
        cout << "Node Found : " << head->data << endl;
    }
    else
    {
        cout << "Node Not Found!" << endl;
    }
}

int main()  
{
    Node *dNode = new Node(10);

    Node *head = dNode;
    Node *tail = dNode;

    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;
    totalNodes(head);
    cout << "--------------------------" << endl;

    insertAtHead(head, tail, 5);
    print(head);
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;
    totalNodes(head);
    cout << "-------------------------" << endl;

    insertAtTail(head, tail, 15);
    print(head);
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;
    totalNodes(head);
    cout << "-------------------------" << endl;

    insertAtanyPosition(tail, head, 3, 25);
    print(head);
    cout<< "Head : " << head -> data <<endl;
    cout<< "Tail : " << tail -> data <<endl;
    totalNodes(head);
    cout<< "-------------------------"<<endl;

    insertAfter(tail, head, 25, 13);
    print(head);
    cout<< "Head : " << head -> data <<endl;
    cout<< "Tail : " << tail -> data <<endl;
    totalNodes(head);
    cout<< "-------------------------"<<endl;

    insertBefore(tail, head, 15, 9);
    print(head);
    cout<< "Head : " << head -> data <<endl;
    cout<< "Tail : " << tail -> data <<endl;
    totalNodes(head);
    cout<< "-------------------------"<<endl;

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

    // deleteNodeAtPosition(tail, head, 3);
    // print(head);
    // cout<< "Head : " << head -> data <<endl;
    // cout<< "Tail : " << tail -> data <<endl;
    // totalNodes(head);
    // cout<< "-------------------------"<<endl;

    // deleteAllAfter(head, tail, 2);
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


    // searchNode(head, 13);
    // cout<<"---------------" <<endl;

    // deleteAllBefore(head, 3);
    // print(head);
    // cout<< "Head : " << head -> data <<endl;
    // cout<< "Tail : " << tail -> data <<endl;
    // totalNodes(head);
    // cout<< "-------------------------"<<endl;

    return 0;
}
```

## Source Code Explanation

### 1. **Node Class Definition**

The `Node` class represents each element (node) in the doubly linked list. Each node contains:
- An integer `data`, which stores the value.
- Two pointers: `next` (points to the next node) and `prev` (points to the previous node).

```cpp
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int d)  // Constructor to initialize node data and set next and prev pointers to NULL
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node()  // Destructor to clean up memory and print which node is being deleted
    {
        int value = this->data;
        if (this->next != NULL)  // If there's a next node, delete it to avoid memory leaks
        {
            delete next;
            this->next = NULL;
        }

        cout << "Memory Free for node with data : " << value << endl;
    }
};
```

**Key Points:**
- The constructor initializes the node with `data`, setting `next` and `prev` to `NULL` to indicate it's a standalone node initially.
- The destructor ensures that when a node is deleted, it also deletes the next node to prevent memory leaks and prints a message indicating that memory for the node with a specific value has been freed.

**Example:**
```cpp
Node* node = new Node(10);  // Create a new node with data 10
```

### 2. **Insert at Head**

This function inserts a new node with the given data `d` at the beginning (head) of the list.

```cpp
void insertAtHead(Node* &head, Node* &tail, int d)
{
    Node *temp = head;

    if (temp == NULL)  // If list is empty
    {
        Node *node = new Node(d);  // Create a new node
        head = node;
        tail = node;  // Since it's the only node, both head and tail point to it
        return;
    }
    else
    {
        Node *node = new Node(d);  // Create a new node with data d
        node->next = temp;  // Point the new node's next to current head
        temp->prev = node;  // Update current head's previous pointer to the new node
        head = node;  // Move head to the new node
    }
}
```

**Key Points:**
- If the list is empty (`head == NULL`), a new node is created, and both the `head` and `tail` point to this node.
- If the list is not empty, the new node becomes the head by adjusting the `next` and `prev` pointers of the new node and the old head.

**Example:**
```cpp
Node* head = NULL;
Node* tail = NULL;

insertAtHead(head, tail, 5);  // Insert 5 at head: List -> 5
insertAtHead(head, tail, 10); // Insert 10 at head: List -> 10 -> 5
```

**Output:**
```
10 5
```

### 3. **Insert at Tail**

This function inserts a new node with the given data `d` at the end (tail) of the list.

```cpp
void insertAtTail(Node* &head, Node *&tail, int d)
{
    Node *temp = tail;

    if(temp == NULL){  // If the list is empty
        Node* node = new Node(d);
        head = node;
        tail = node;
    }

    Node *node = new Node(d);  // Create a new node
    temp->next = node;  // Link the current tail's next to the new node
    node->prev = temp;  // Set the new node's previous to the current tail
    tail = node;  // Move the tail to the new node
}
```

**Key Points:**
- If the list is empty, it behaves like `insertAtHead` (setting both `head` and `tail` to the new node).
- If the list is not empty, it links the new node to the current tail and updates the `tail` pointer.

**Example:**
```cpp
insertAtTail(head, tail, 15);  // Insert 15 at tail: List -> 10 -> 5 -> 15
```

**Output:**
```
10 5 15
```

### 4. **Insert at Any Position**

This function inserts a new node at any specified position in the list.

```cpp
void insertAtanyPosition(Node *&tail, Node *&head, int position, int d)
{
    Node *temp = head;
    int count = 1;

    if (position == 1)  // If the position is at the head
    {
        insertAtHead(head, tail, d);
        return;
    }

    while (count < position - 1)  // Traverse to the node just before the target position
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)  // If inserting at the tail
    {
        insertAtTail(head, tail, d);
        return;
    }

    Node *node = new Node(d);  // Create a new node
    node -> next = temp -> next;  // Adjust the next and prev pointers
    node -> next -> prev = node;
    temp -> next = node;
    node -> prev = temp;
}
```

**Key Points:**
- If the position is 1, it uses `insertAtHead`.
- If the position is after the last element, it uses `insertAtTail`.
- Otherwise, it inserts the new node between two nodes by adjusting the `next` and `prev` pointers.

**Example:**
```cpp
insertAtanyPosition(tail, head, 2, 12);  // Insert 12 at position 2: List -> 10 -> 12 -> 5 -> 15
```

**Output:**
```
10 12 5 15
```

### 5. **Insert After**

This function inserts a new node after a node with the specified target value.

```cpp
void insertAfter(Node *&tail, Node *&head, int target, int d)
{
    Node *temp = head;

    if (temp == NULL)  // If list is empty, insert at head
    {
        Node* node = new Node(d);
        head = node;
        tail = node;
        return;
    }

    while (temp->data != target)  // Find the node with the target value
    {
        temp = temp->next;
    }

    if (temp->next == NULL)  // If target is the tail node, insert at tail
    {
        insertAtTail(head, tail, d);
        return;
    }

    Node *node = new Node(d);  // Insert new node after the target node
    node -> next = temp -> next;
    node -> next -> prev = node;
    temp -> next = node;
    node -> prev = temp;
}
```

**Key Points:**
- Finds the node with the `target` value and inserts the new node after it.
- If the target node is the tail, it uses `insertAtTail`.

**Example:**
```cpp
insertAfter(tail, head, 5, 20);  // Insert 20 after 5: List -> 10 -> 12 -> 5 -> 20 -> 15
```

**Output:**
```
10 12 5 20 15
```

### 6. **Insert Before**

This function inserts a new node before a node with the specified target value.

```cpp
void insertBefore(Node *&tail, Node *&head, int target, int d)
{
    Node *temp = head;

    if (temp->data == target)  // If target is at head
    {
        insertAtHead(head, tail, d);
        return;
    }

    while (temp->next->data != target)  // Find the node before the target node
    {
        temp = temp->next;
    }

    if (temp->next == NULL && temp->data == target)  // If target is the tail, insert at tail
    {
        insertAtTail(head, tail, d);
        return;
    }

    Node *node = new Node(d);  // Insert new node before the target node
    node -> next = temp -> next;
    node -> next -> prev = node;
    temp -> next = node;
    node -> prev = temp;
}
```

**Key Points:**
- Finds the node before the target value and inserts the new node before it.
- If the target node is the head, it uses `insertAtHead`.

**Example:**
```cpp
insertBefore(tail, head, 5, 18);  // Insert 18 before 5: List -> 10 -> 12 -> 18 -> 5 -> 20 -> 15
```

**Output:**
```
10 12 18 5 20 15
```

### 7. **Print Function**

This function prints the entire list from head to tail.

```cpp
void print(Node *head

)
{
    Node *temp = head;

    while (temp != NULL)  // Traverse the list and print data of each node
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}
```

**Example:**
```cpp
print(head);  // Outputs: 10 12 18 5 20 15
```
### 8. **Insert a Node Before a Target Node**

#### Code:
```cpp
void insertBefore(Node *&tail, Node *&head, int target, int d)
{
    Node *temp = head;

    if (temp->data == target)  // If the target is the head node
    {
        insertAtHead(head, tail, d);  // Insert at head
        return;
    }

    while (temp->next != NULL && temp->next->data != target)
    {
        temp = temp->next;
    }

    // If target is found or at the tail
    Node *node = new Node(d);
    node->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = node;
    }
    temp->next = node;
    node->prev = temp;
}
```

#### Example:
Let’s say we have a doubly linked list:  
**`10 <-> 20 <-> 30 <-> 40`**  
We want to insert `25` before `30`.

#### Steps:
1. Traverse through the list to find the node that has `30`.
2. Insert `25` before `30`.

The list becomes:  
**`10 <-> 20 <-> 25 <-> 30 <-> 40`**

---

### 9. **Delete the Head Node**

#### Code:
```cpp
void deleteHeadNode(Node *&head)
{
    if (head == NULL)
    {
        return;  // Empty list
    }

    Node *temp = head;
    head = head->next;  // Move head to next
    if (head != NULL) {
        head->prev = NULL;  // Remove backward reference
    }
    delete temp;  // Delete old head
}
```

#### Example:
Given the list:  
**`10 <-> 20 <-> 30`**  
If we delete the head node (`10`), the new list will be:  
**`20 <-> 30`**

---

### 10. **Delete the Tail Node**

#### Code:
```cpp
void deleteTailNode(Node *&tail)
{
    if (tail == NULL)
    {
        return;  // Empty list
    }

    Node* temp = tail;
    tail = tail->prev;  // Move tail to the previous node
    if (tail != NULL) {
        tail->next = NULL;  // Remove forward reference
    }
    delete temp;  // Delete old tail
}
```

#### Example:
Starting with the list:  
**`10 <-> 20 <-> 30`**  
If we delete the tail (`30`), the updated list will be:  
**`10 <-> 20`**

---

### 11 . **Delete a Node at a Given Position**

#### Code:
```cpp
void deleteNodeAtPosition(Node *&tail, Node *&head, int position)
{
    if (position == 1) {
        deleteHeadNode(head);  // Delete head node if position is 1
        return;
    }

    Node* current = head;
    int count = 1;

    while (count < position && current != NULL) {
        current = current->next;
        count++;
    }

    if (current == NULL) return;  // If position is out of bounds

    if (current->next == NULL) {
        deleteTailNode(tail);  // Delete tail node if it's at the last position
        return;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
}
```

#### Example:
Given the list:  
**`10 <-> 20 <-> 30 <-> 40`**  
If we delete the node at position `2` (which is `20`), the new list will be:  
**`10 <-> 30 <-> 40`**

---

### 12. **Delete All Nodes After a Given Position**

#### Code:
```cpp
void deleteAllAfter(Node *&tail, Node *&head, int position)
{
    Node *temp = head;
    int count = 1;

    while (count < position && temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)  // No nodes after position
    {
        return;
    }

    Node *nodeToDelete = temp->next;
    temp->next = NULL;

    while (nodeToDelete != NULL)
    {
        Node *nextNode = nodeToDelete->next;
        delete nodeToDelete;
        nodeToDelete = nextNode;
    }

    tail = temp;  // Update tail to the last valid node
}
```

#### Example:
For the list:  
**`10 <-> 20 <-> 30 <-> 40 <-> 50`**  
If we delete all nodes after position `2` (`after 20`), the list will become:  
**`10 <-> 20`**

---

### 13. **Delete All Nodes Before a Given Position**

#### Code:
```cpp
void deleteAllBefore(Node *&head, int position)
{
    while (position > 1) {
        deleteHeadNode(head);  // Delete nodes until we reach the desired position
        position--;
    }
}
```

#### Example:
Given the list:  
**`10 <-> 20 <-> 30 <-> 40`**  
If we delete all nodes before position `3`, the new list will be:  
**`30 <-> 40`**

---

### 14. **Count the Total Nodes**

#### Code:
```cpp
void totalNodes(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    cout << "Total Nodes - Length of list: " << count << endl;
}
```

#### Example:
For a list:  
**`10 <-> 20 <-> 30`**  
This function will output:  
`Total Nodes - Length of list: 3`

---

### 15. **Search for a Node**

#### Code:
```cpp
void searchNode(Node *head, int target)
{
    while (head != NULL)
    {
        if (head->data == target) {
            cout << "Node Found: " << head->data << endl;
            return;
        }
        head = head->next;
    }

    cout << "Node Not Found!" << endl;
}
```

#### Example:
For the list:  
**`10 <-> 20 <-> 30`**  
If we search for the node with data `20`, the function will output:  
`Node Found: 20`

If the target is not found, like searching for `40`, it will output:  
`Node Not Found!`

---

### Example `main` Function:

```cpp
int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    // Example inserts
    insertAtHead(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);

    // Print the list
    printList(head);  // Output: 10 20 30 40

    // Insert 25 before 30
    insertBefore(tail, head, 30, 25);
    printList(head);  // Output: 10 20 25 30 40

    // Delete the head node
    deleteHeadNode(head);
    printList(head);  // Output: 20 25 30 40

    // Delete the node at position 2
    deleteNodeAtPosition(tail, head, 2);
    printList(head);  // Output: 20 30 40

    return 0;
}
```

This example covers inserting nodes, deleting nodes, and printing the list at each step, which helps in tracking how the list is modified.
