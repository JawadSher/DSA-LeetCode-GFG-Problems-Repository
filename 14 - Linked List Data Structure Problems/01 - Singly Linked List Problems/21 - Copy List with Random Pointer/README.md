<h1 align='center'>Copy - List - With - Random - Pointer</h1>

## Problem Statement

**Problem URL :** [Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/)

![image](https://github.com/user-attachments/assets/9287f812-7c14-44c4-8c39-5a27a5f0cb28)
![image](https://github.com/user-attachments/assets/c1e943de-33db-432e-9da5-1097175fe9c6)
![image](https://github.com/user-attachments/assets/fb8de8b5-f790-411c-9175-2aa1a0ac88a2)

## Problem Explanation

You are given a linked list where each node has two pointers:
1. **Next pointer**: Points to the next node in the linked list.
2. **Random pointer**: Points to any random node in the list (or `NULL`).

The task is to create a **deep copy** (clone) of this list. A deep copy means the cloned list should have nodes with the same values and structure, including both `next` and `random` pointers, but the cloned list should not share any memory with the original list.

### Approach for Beginners

1. **Break the problem into steps**:
   - First, copy the nodes using only the `next` pointers.
   - Then, handle the `random` pointers.
   - Finally, separate the mixed list into two independent lists.

2. **Use interleaving**:
   - By inserting the clone nodes between the original nodes, you can easily copy the `random` pointers without needing extra space (like a hash map).

3. **Visualize the process**:
   - Draw the original and cloned lists step by step to understand how the `random` pointers and interleaving work.

By breaking it down into simple steps, beginners can understand and implement this problem effectively.

## Problem Solution
```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    void insertAtTail(Node* &head, Node* &tail, int d){
        Node* newNode = new Node(d);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }

        tail -> next = newNode;
        tail = newNode;
    }
public:
    Node* copyRandomList(Node* head) {
        // step1 : create a clone list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;
        while(temp != NULL){
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp -> next;
        }

        // step2 : cloneNodes add in between original list
        Node* originalNode = head;
        Node* cloneNode = cloneHead;

        while(originalNode != NULL && cloneNode != NULL){
            Node* next = originalNode -> next;
            originalNode -> next = cloneNode;
            originalNode = next;

            next = cloneNode -> next;
            cloneNode -> next = originalNode;
            cloneNode = next;
        }
        
        // step3 : random pointer copy
        temp = head;
        while(temp != NULL){
            if(temp -> next != NULL){
                temp -> next -> random = temp -> random ? temp -> random -> next : temp -> random;
            }
            temp = temp -> next -> next;
        }

        // step4 : reverse changes done in step 2
        originalNode = head;
        cloneNode = cloneHead;

        while(originalNode != NULL && cloneNode != NULL){
            originalNode -> next = cloneNode -> next;
            originalNode = originalNode -> next;

            if(originalNode != NULL){
                cloneNode -> next = originalNode -> next;
            }
            cloneNode = cloneNode -> next;
        }

        // step5 : return ans
        return cloneHead;
    }
};
```

## Problem Solution Explanation

#### 1. **Helper Function: `insertAtTail`**

```cpp
private:
    void insertAtTail(Node* &head, Node* &tail, int d){
        Node* newNode = new Node(d);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }

        tail -> next = newNode;
        tail = newNode;
    }
```

This helper function inserts a new node at the tail of the list. It takes three arguments:
- `head`: Reference to the head of the list.
- `tail`: Reference to the tail of the list.
- `d`: The data value of the new node.

- If the list is empty (`head == NULL`), the new node becomes both the head and the tail of the list.
- Otherwise, it appends the new node to the end of the list and updates the `tail`.

**Example**:
- If you start with an empty list and call `insertAtTail` with `d = 5`, the list will become: `5`.
- If the list is `1 -> 2 -> 3` and you call `insertAtTail` with `d = 4`, the list becomes: `1 -> 2 -> 3 -> 4`.

---

#### 2. **Main Function: `copyRandomList`**

```cpp
public:
    Node* copyRandomList(Node* head) {
```

This is the main function to clone the linked list. It returns the head of the cloned list.

---

#### Step 1: **Create a Clone List**

```cpp
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;
        while(temp != NULL){
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp -> next;
        }
```

- **Objective**: Create a new list that clones the original list but only with the `next` pointers (ignoring the `random` pointers for now).
- We traverse the original list (`temp`) and create new nodes using the `insertAtTail` function, which appends them to the `cloneHead` list.

**Example**:
- Original list: `1 -> 2 -> 3`
- After this step, the clone list will look like: `1 -> 2 -> 3` (only `next` pointers are set).

---

#### Step 2: **Insert Clone Nodes Between Original Nodes**

```cpp
        Node* originalNode = head;
        Node* cloneNode = cloneHead;

        while(originalNode != NULL && cloneNode != NULL){
            Node* next = originalNode -> next;
            originalNode -> next = cloneNode;
            originalNode = next;

            next = cloneNode -> next;
            cloneNode -> next = originalNode;
            cloneNode = next;
        }
```

- **Objective**: Interleave the cloned nodes between the original nodes. This means we place each clone node immediately after its corresponding original node.
  
  **Example Before Step 2**:
  - Original list: `1 -> 2 -> 3`
  - Clone list: `1' -> 2' -> 3'` (just `next` pointers).

  **Example After Step 2**:
  - Mixed list: `1 -> 1' -> 2 -> 2' -> 3 -> 3'`

- How this works:
  - For each node in the original list, we set its `next` to point to its clone, and then move forward in both the original and clone lists.

---

#### Step 3: **Copy the Random Pointers**

```cpp
        temp = head;
        while(temp != NULL){
            if(temp -> next != NULL){
                temp -> next -> random = temp -> random ? temp -> random -> next : temp -> random;
            }
            temp = temp -> next -> next;
        }
```

- **Objective**: Set the `random` pointers for the clone nodes.
- `temp -> next` refers to the clone node corresponding to the original node `temp`. For each node in the original list (`temp`):
  - If the original node (`temp -> random`) has a `random` pointer, set the corresponding clone node's `random` pointer to point to the clone node of `temp -> random`.
  - If the `random` pointer is `NULL`, set the clone's `random` pointer to `NULL`.

- **Example**:
  - Original list random pointers: `1 -> 3`, `2 -> 1`, `3 -> 2`
  - After this step, the mixed list will look like:
    ```
    1 -> 1' -> 2 -> 2' -> 3 -> 3'
    |     |     |     |     |
    v     v     v     v     v
    3     3'    1     1'    2
    ```

---

#### Step 4: **Restore the Original List and Separate the Clone List**

```cpp
        originalNode = head;
        cloneNode = cloneHead;

        while(originalNode != NULL && cloneNode != NULL){
            originalNode -> next = cloneNode -> next;
            originalNode = originalNode -> next;

            if(originalNode != NULL){
                cloneNode -> next = originalNode -> next;
            }
            cloneNode = cloneNode -> next;
        }
```

- **Objective**: Unweave the mixed list to restore the original list and separate the clone list.
- The original nodes and clone nodes are currently interleaved (`1 -> 1' -> 2 -> 2' -> 3 -> 3'`). This step restores the original list and separates out the cloned list.

  - We restore the original list by setting `originalNode -> next` to point to the next original node.
  - Similarly, we adjust the `next` pointers in the clone list to make it independent of the original list.

- **Example**:
  - After this step, the original list is restored: `1 -> 2 -> 3`
  - The clone list is separated: `1' -> 2' -> 3'` with correct `next` and `random` pointers.

---

#### Step 5: **Return the Cloned List**

```cpp
        return cloneHead;
    }
};
```

- Finally, the function returns the head of the cloned list (`cloneHead`), which is a deep copy of the original list.

---

### Example Walkthrough

Let’s take an example of a linked list with three nodes:

Original list:

```
1 -> 2 -> 3
|    |    |
v    v    v
3    1    2
```

Here, the `random` pointers are:
- Node 1’s `random` pointer points to Node 3.
- Node 2’s `random` pointer points to Node 1.
- Node 3’s `random` pointer points to Node 2.

**Step-by-Step Cloning**:

1. **Create Clone List**:
   - Clone list: `1' -> 2' -> 3'` (just `next` pointers).

2. **Interleave Original and Clone Nodes**:
   - Mixed list: `1 -> 1' -> 2 -> 2' -> 3 -> 3'`.

3. **Copy `random` Pointers**:
   - For the clone list: `1' -> 3'`, `2' -> 1'`, `3' -> 2'`.

4. **Restore the Original List and Separate Clone List**:
   - Original list: `1 -> 2 -> 3`
   - Clone list: `1' -> 2' -> 3'`.

