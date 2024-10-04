<h1 align='center'>Circular - Singly - Linked - List - Example</h1>

A **circular linked list** is a variation of the singly linked list, where the last node's `next` pointer points back to the **first node** (head), instead of pointing to `NULL`. This forms a continuous loop, allowing traversal to restart from the beginning after reaching the last node.

### Structure of a Circular Linked List Node:
Each node in a circular linked list contains:
1. **Data**: The value stored in the node.
2. **Next pointer**: A reference to the next node in the list, with the last node pointing back to the first node to form a circle.

### Example of a Circular Linked List:

Consider a circular linked list with three nodes: `10`, `20`, and `30`. The structure would look like this:

```
[10] -> [20] -> [30] -> [10] (back to the first node)
```

- **Head Node**: The first node (`10`).
- **Tail Node**: The last node (`30`) whose `next` points back to the head node (`10`).

### Operations:
1. **Traversal**: 
   - Traversal in a circular linked list can be continuous without stopping at the last node, since the `next` pointer of the last node brings us back to the head.
   - Example: Starting from `10`, you move to `20`, then `30`, and then back to `10` again.

2. **Insertion**:
   - A new node can be inserted at any position, similar to a singly linked list, but special care must be taken when inserting at the tail to maintain the circular link.
   - Example: Inserting `15` between `10` and `20` would result in:
     ```
     [10] -> [15] -> [20] -> [30] -> [10]
     ```

3. **Deletion**:
   - A node can be deleted, and the circular structure is maintained by updating the `next` pointer of the previous node.
   - Example: Deleting `30` from the list:
     ```
     [10] -> [20] -> [10]
     ```

### Advantages of a Circular Linked List:
- **Efficient cycling**: Since the last node points back to the first node, circular linked lists are useful for applications where continuous looping through the list is required.
- **No `NULL` terminator**: The absence of a `NULL` pointer makes traversals seamless in a looping scenario.

### Disadvantages:
- **Complexity in insertion/deletion**: Maintaining the circular structure requires additional care during insertion and deletion operations.
- **No natural stopping point**: Without careful control, traversals can continue infinitely due to the circular nature.

### Common Uses:
- **Round-robin scheduling**: Circular linked lists are ideal for implementing round-robin scheduling in operating systems, where processes are cycled through repeatedly.
- **Music or video playlists**: Circular linked lists are often used for continuous looping playlists where, after the last item, it loops back to the first.
- **Buffer management**: Circular buffers use circular linked lists for managing a fixed-size buffer that overwrites old data as new data is added.


A **circular singly linked list** is a variation of the singly linked list where the last node points back to the first node, forming a loop. In a standard singly linked list, each node points to the next node in the sequence, and the last node points to `NULL`. However, in a circular singly linked list, the last node's `next` pointer is directed back to the first node, creating a circular chain.

### Key Points of a Circular Singly Linked List:
1. **Circular Nature**: The last node's `next` pointer points to the first node, making it circular.
2. **No `NULL` at the end**: Unlike normal singly linked lists, circular linked lists don't end with a `NULL` pointer.
3. **Traversal**: You can traverse through the list in a loop until you reach the same node you started with.

## Source code 
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
        if(this -> next == NULL){
            delete next;
            next = NULL;
        }

        cout << "Memory free for node with data : " << value << endl;
    }
};

void insertNode(Node* &tail, int target, int d){
    if(tail == NULL){
        Node* node = new Node(d);
        tail = node;
        node -> next = node;
        return;
    }

    Node* current = tail;
    do {
        if (current->data == target) {
            break;  // Target found
        }
        current = current->next;
    } while (current != tail);

    Node* node = new Node(d);
    node -> next = current -> next;
    current -> next = node;

    if(current == tail){
        tail = node;
    }
}

void print(Node* tail){
    Node* temp = tail;

    if(tail == NULL){
        cout << "List is empyt" <<endl;
        return;
    }

    do{
        cout << tail -> data <<" ";
        tail = tail -> next;
    }while(tail != temp);
    cout << endl;
}

void deleteNode(Node* &tail, int target){
    if(tail == NULL){
        cout << "Empty List" <<endl;
        return;
    }

    Node* previous = tail;
    Node* current = previous -> next;
    
    while(current -> data != target){
        previous = current;
        current = current -> next;
    }

    previous -> next = current -> next;
    if(current == previous){
        tail = previous;
    }else if(tail == current){
        tail = previous;
    }

    current -> next = NULL;
    delete current;
}

int main(){
    Node* tail = NULL;

    insertNode(tail, 1, 10);
    print(tail);

    insertNode(tail, 2, 20);
    print(tail);

    insertNode(tail, 3, 30);
    print(tail);

    deleteNode(tail, 10);
    print(tail);


    return 0;
}
```

## Source Code Explanation 
#### Class Definition: `Node`

```cpp
class Node{
    public:
        int data;         // Stores the data of the node
        Node* next;       // Pointer to the next node

    // Constructor
    Node(int d){
        this -> data = d; // Assigns data to the node
        this -> next = NULL; // Initially, the next pointer is NULL
    }

    // Destructor
    ~Node(){
        int value = this -> data;
        if(this -> next == NULL){
            delete next; // This part is problematic and unnecessary, explained later.
            next = NULL;
        }
        cout << "Memory free for node with data : " << value << endl;
    }
};
```

1. **Node class**: Each node in the linked list contains:
   - An integer `data` (for storing the value of the node).
   - A pointer `next` that points to the next node in the list.
   
2. **Constructor**: Initializes a new node with the provided data (`d`) and sets the `next` pointer to `NULL`.

3. **Destructor**: This function runs when a node is deleted. It prints a message indicating the node's memory is being freed. There's a problematic condition where it checks if `next == NULL` and tries to delete it, but that condition will never happen in a circular linked list because there’s no `NULL` pointer in the chain. You can safely remove that check.

---

#### Function: `insertNode`

```cpp
void insertNode(Node* &tail, int target, int d){
    if(tail == NULL){
        // Case 1: Empty list
        Node* node = new Node(d);
        tail = node;
        node -> next = node; // Points to itself to create a circular list
        return;
    }

    Node* current = tail;
    do {
        if (current->data == target) {
            break;  // Target found
        }
        current = current->next;
    } while (current != tail);  // Search for the target node until we come back to the tail

    // Case 2: Insert new node after the target node
    Node* node = new Node(d);
    node -> next = current -> next;  // New node points to the next node of the target
    current -> next = node;  // Target node points to the new node

    if(current == tail){
        tail = node;  // If inserting after tail, update tail to new node
    }
}
```

- **Purpose**: This function inserts a new node with data `d` after the node containing `target` in the circular linked list.
  
- **How it works**:
  1. **Empty list case**: 
     - If the list is empty (i.e., `tail == NULL`), we create the first node and make it point to itself to form the circular structure. This node becomes both the head and tail of the list.
  
  2. **Non-empty list**: 
     - The code traverses the list starting from `tail`, looking for the node that contains the `target` value.
     - Once the target node is found, a new node is created, and it’s inserted after the target node. 
     - If the target node is the tail, we update the `tail` pointer to the newly inserted node.

---

#### Function: `print`

```cpp
void print(Node* tail){
    Node* temp = tail;

    if(tail == NULL){
        cout << "List is empty" <<endl;
        return;
    }

    do{
        cout << tail -> data <<" ";  // Print current node's data
        tail = tail -> next;  // Move to the next node
    } while(tail != temp);  // Stop when we come back to the starting node
    cout << endl;
}
```

- **Purpose**: This function prints the entire circular linked list starting from `tail`.
  
- **How it works**:
  1. It checks if the list is empty (`tail == NULL`). If so, it prints "List is empty".
  2. Otherwise, it prints the data of each node by traversing the list. The traversal is done in a loop using a `do-while` structure, which ensures the loop runs at least once.
  3. The loop terminates when we reach the node we started from (`tail == temp`), indicating a full cycle through the circular list.

---

#### Function: `deleteNode`

```cpp
void deleteNode(Node* &tail, int target){
    if(tail == NULL){
        cout << "Empty List" <<endl;
        return;
    }

    Node* previous = tail;
    Node* current = previous -> next;
    
    while(current -> data != target){
        previous = current;  // Move to the next node
        current = current -> next;
    }

    previous -> next = current -> next;  // Unlink the target node
    if(current == previous){
        tail = previous;  // If the target is the only node, update the tail
    }else if(tail == current){
        tail = previous;  // If deleting the tail node, update the tail pointer
    }

    current -> next = NULL;
    delete current;  // Delete the target node
}
```

- **Purpose**: This function deletes a node with the `target` value from the circular linked list.

- **How it works**:
  1. It first checks if the list is empty. If it is, it prints "Empty List".
  2. The function uses two pointers, `previous` and `current`, to traverse the list. It searches for the node with the `target` value.
  3. Once the target node is found, it unlinks the node by making the `previous` node point to `current->next`.
  4. If the target node is the `tail`, the `tail` pointer is updated to the `previous` node.
  5. Finally, the target node is deleted from memory.

---

#### Main Function

```cpp
int main(){
    Node* tail = NULL;

    // Insert the first node (10), creating the list
    insertNode(tail, 1, 10);
    print(tail);  // Output: 10

    // Insert a second node (20) after the node with data 10
    insertNode(tail, 2, 20);  // The list contains: 10 -> 20 -> 10 (circular)
    print(tail);  // Output: 10 20

    // Insert a third node (30) after the node with data 20
    insertNode(tail, 3, 30);  // The list contains: 10 -> 20 -> 30 -> 10 (circular)
    print(tail);  // Output: 10 20 30

    // Delete the node with data 10
    deleteNode(tail, 10);  // The list becomes: 20 -> 30 -> 20 (circular)
    print(tail);  // Output: 20 30

    return 0;
}
```

### Step-by-Step:
1. **Inserting the first node (10)**: Since the list is initially empty, this node becomes the tail and forms a self-loop (`10 -> 10`).
2. **Inserting the second node (20)**: The second node is inserted after the node with data `10`. Now, the list looks like `10 -> 20 -> 10`.
3. **Inserting the third node (30)**: The third node is inserted after the node with data `20`, forming `10 -> 20 -> 30 -> 10`.
4. **Deleting the node with data 10**: The node with data `10` is removed, and the list now becomes `20 -> 30 -> 20`.

---

### Summary:
This code implements a **circular singly linked list** where you can insert nodes after a target value and delete nodes with a specific value. The circular nature allows continuous traversal without hitting a `NULL` value, and the list can grow and shrink dynamically.
