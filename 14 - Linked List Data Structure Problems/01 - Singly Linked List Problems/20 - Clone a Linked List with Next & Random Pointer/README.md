<h1 align='center'>Clone - a Linked - List with - Next - & - Random - Pointer</h1>

## Problem Statement

**Problem URL :** [Clone a Linked List with Next & Random Pointer](https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/327b6caa-2ad5-4c3d-b694-f38bb6184192)
![image](https://github.com/user-attachments/assets/3776a03c-d133-4a5b-8fe0-a6dd20e490b7)

## Problem Explanation
You are given a linked list where each node has two pointers:
1. **Next pointer**: Points to the next node in the linked list.
2. **Random pointer**: Points to any random node in the list (or `NULL`).

Your task is to create **a deep copy of this list**. A deep copy means that the new list should not share any node with the original list, and the copied nodes should have the same structure, including the `next` and `random` pointers.

---

### Approach to Solve the Problem

Before diving into the code explanation, let’s think about the problem step by step:

1. **Understanding the `Next` pointer**:
   - Cloning the list based on the `next` pointer is straightforward. You can simply traverse the original list and create new nodes with the same values, linking them using the `next` pointer.

2. **Understanding the `Random` pointer**:
   - The tricky part is copying the `random` pointer, which can point to any node in the list. 
   - You need to ensure that the newly created clone list also has the correct random pointers without any cross-references to the original list.

3. **Plan**:
   - First, create a clone list by copying the values of each node and linking them with `next`.
   - Then, use a **hash map** to track the mapping between the original and clone nodes.
   - Finally, set the `random` pointers in the cloned list by referring to the hash map.
     
## Problem Solution
```cpp
class Solution {
  private:
    void insertAtTail(Node* &head, Node* &tail, int d){
        Node* temp = new Node(d);
        if(head == NULL){
            head = temp;
            tail = temp;
        
            return;
        }
        
        tail -> next = temp;
        tail = temp;
        
    }
  public:
    Node *copyList(Node *head) {
        // step 1: create a clone list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
    
        Node* temp = head;
        
        while(temp != NULL){
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp -> next;
        }
        
        // step 2: Create a map
        unordered_map<Node*, Node*> mapping;
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL){
            mapping[originalNode] = cloneNode;
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }
        
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode != NULL){
            cloneNode -> random = mapping[originalNode -> random];
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }
        
        return cloneHead;
    }
};
```

## Problem Solution Explanation

Now, let’s explain the code line by line using multiple examples.

```cpp
class Solution {
  private:
    void insertAtTail(Node* &head, Node* &tail, int d){
```

- This function helps insert a new node at the tail of a linked list. It takes three arguments:
  1. `head`: Reference to the head of the list.
  2. `tail`: Reference to the tail of the list.
  3. `d`: The data value of the new node.

- **Example**: If you want to insert `5` at the tail of a list with nodes `1 -> 2 -> 3`, the result will be `1 -> 2 -> 3 -> 5`.

---

```cpp
        Node* temp = new Node(d);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
```

- A new node is created with value `d`. If the list is currently empty (`head == NULL`), the new node becomes both the head and the tail of the list.
  
- **Example**: If the list is empty and you insert `5`, the list becomes `5`.

---

```cpp
        tail -> next = temp;
        tail = temp;
    }
```

- If the list is not empty, the new node (`temp`) is linked at the end of the list using `tail -> next = temp`. Then, the tail pointer is updated to point to the new node.
  
- **Example**: If the current list is `1 -> 2 -> 3` and you insert `5`, it becomes `1 -> 2 -> 3 -> 5`.

---

```cpp
  public:
    Node *copyList(Node *head) {
```

- This is the main function to clone the linked list. It takes the head of the original list as input and returns the head of the cloned list.

---

```cpp
        // step 1: create a clone list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
    
        Node* temp = head;
        
        while(temp != NULL){
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp -> next;
        }
```

- **Step 1: Create a clone list using only the `next` pointer.**
  - The loop goes through the original list (`temp` traverses the list), and for each node, it inserts a new node with the same data into the clone list using the `insertAtTail` function.

- **Example**: 
  - Original list: `1 -> 2 -> 3`
  - After this step, clone list: `1 -> 2 -> 3` (but no `random` pointers yet).

---

```cpp
        // step 2: Create a map
        unordered_map<Node*, Node*> mapping;
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL){
            mapping[originalNode] = cloneNode;
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }
```

- **Step 2: Create a map to store the mapping between original and cloned nodes.**
  - An unordered map is used to map each node in the original list (`originalNode`) to its corresponding node in the clone list (`cloneNode`).
  
- **Example**:
  - Original list: `1 -> 2 -> 3`
  - Clone list: `1 -> 2 -> 3`
  - Mapping: `{Original Node 1 -> Clone Node 1, Original Node 2 -> Clone Node 2, Original Node 3 -> Clone Node 3}`

---

```cpp
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode != NULL){
            cloneNode -> random = mapping[originalNode -> random];
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }
```

- **Step 3: Set the `random` pointers in the clone list.**
  - This loop goes through the original list again. For each node in the original list, it sets the `random` pointer of the corresponding node in the clone list by using the map (`mapping`).
  - The `random` pointer of `cloneNode` is set to the clone node corresponding to `originalNode -> random`.
  
- **Example**:
  - Original list: `1 -> 2 -> 3`
  - Assume `random` pointers are: `1 -> 3`, `2 -> 1`, `3 -> 2`.
  - After this step, the clone list will have the same structure: `1 -> 3`, `2 -> 1`, `3 -> 2`.

---

```cpp
        return cloneHead;
    }
};
```

- Finally, the function returns the head of the cloned list (`cloneHead`), which is a deep copy of the original list, with both `next` and `random` pointers correctly set.

---

### Example Walkthrough

Let’s take an example of a list with 3 nodes:

Original list:

```
1 -> 2 -> 3
|    |    |
v    v    v
3    1    2
```

Here, the `random` pointers are:
- Node 1's random pointer points to Node 3.
- Node 2's random pointer points to Node 1.
- Node 3's random pointer points to Node 2.

Steps:
1. **Clone the list based on `next` pointer**:
   - Clone list: `1 -> 2 -> 3` (without `random` pointers).

2. **Create a map**:
   - Mapping:
     - `Original Node 1 -> Clone Node 1`
     - `Original Node 2 -> Clone Node 2`
     - `Original Node 3 -> Clone Node 3`

3. **Assign `random` pointers in the clone list**:
   - Clone list with random pointers:
   ```
   1 -> 2 -> 3
   |    |    |
   v    v    v
   3    1    2
   ```

---

### Approach for Beginners

1. **Break the problem into smaller parts**:
   - First, focus on copying the `next` pointer, which is simpler.
   - Then, handle the `random` pointers.

2. **Use a HashMap**:
   - By using a hash map, you can easily keep track of the original nodes and their corresponding clones. This helps in correctly assigning the `random` pointers.

3. **Think Step by Step**:
   - First, create the clone list.
   - Then, map the original nodes to the clone nodes.
   - Finally, assign the random pointers using the map.

By breaking down the problem, a beginner can gradually understand the steps and arrive at the solution.
