<h1 align='center'>Check If - Circular - Linked - List</h1>

## Problem Statement

**Problem URL :** [Check if Circular Linked List](https://www.geeksforgeeks.org/problems/circular-linked-list/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/53783737-3e33-4193-bb74-3039a0a09f25)
![image](https://github.com/user-attachments/assets/eb8c76cd-dba8-468e-9f8e-56c73b68efcb)

## Problem Explanation
The problem "Check If Circular Linked List" on GeeksforGeeks (GFG) asks you to determine whether a given linked list is circular or not. A circular linked list is one in which the last node points back to one of the previous nodes, forming a loop. In contrast, a linear linked list has its last node pointing to `NULL`.

**Key Points:**
- A circular linked list has at least one node, and if you keep traversing, you will eventually loop back to the starting node.
- A linear linked list ends with a node pointing to `NULL`.

### Example:
- For a circular linked list:
```
1 -> 2 -> 3 -> 4
     ^         |
     |_________|
```
The output should be `true` because there is a cycle.

- For a linear linked list:
```
1 -> 2 -> 3 -> 4 -> NULL
```
The output should be `false` because it terminates at `NULL`.

### Approach to Solve the Problem

1. **Check for Empty List:** If the list is empty (i.e., the head node is `NULL`), it can be considered circular by definition, so return `true`.

2. **Traverse the List:** Start from the head node and traverse the list using a pointer.
   - Keep moving to the next node until you reach the end of the list (`temp` becomes `NULL`) or find that you have reached back to the head node.
   
3. **Determine Circularity:** 
   - If during traversal you encounter the head node again, return `true` (indicating the list is circular).
   - If you reach a node with a `NULL` pointer, return `false` (indicating the list is linear).

## Problem Solution
```cpp
class Solution {
  public:
    bool isCircular(Node *head) {
        if(head == NULL) return true;
        
        Node* temp = head -> next;
        
        while(temp != NULL){
            if(temp == head) return true;
            
            temp = temp -> next;
        }
        
        
        return false;
    }
};
```

## Problem Solution Explanation
Here is the provided code with a detailed line-by-line explanation:

```cpp
class Solution {
  public:
    bool isCircular(Node *head) {
```
- **Class Declaration:** This defines a class `Solution` which contains the method `isCircular`.
- **Method Signature:** The method takes one parameter: a pointer `head` to the starting node of the linked list.

```cpp
        if(head == NULL) return true;
```
- **Check for Empty List:** If the head of the linked list is `NULL`, the function returns `true`, treating an empty list as circular.

### Example Walkthrough
For an empty linked list (head = `NULL`):
- The function will return `true` immediately.

```cpp
        Node* temp = head -> next;
```
- **Initialize Temp Pointer:** A pointer `temp` is initialized to point to the node next to the head.

```cpp
        while(temp != NULL){
            if(temp == head) return true;
            
            temp = temp -> next;
        }
```
- **Traverse the List:**
  - A while loop checks if `temp` is not `NULL`. This loop continues until the end of the list is reached.
  - Inside the loop, it checks if `temp` points back to the `head`. If it does, the function returns `true` (indicating the list is circular).
  - If not, the pointer `temp` is moved to the next node in the list.

### Example Walkthrough
Consider a circular linked list:
```
1 -> 2 -> 3 -> 4
     ^         |
     |_________|
```
1. The `head` is `1`. 
2. `temp` points to `2`.
3. The loop continues, checking:
   - `temp == head` (is `2 == 1?`): **No**
   - Move `temp` to `3`.
   - `temp == head` (is `3 == 1?`): **No**
   - Move `temp` to `4`.
   - `temp == head` (is `4 == 1?`): **No**
   - Move `temp` back to `2` (the next node of `4`).
   - `temp == head` (is `2 == 1?`): **No**
4. The traversal continues until eventually:
   - `temp` points to `1` again, confirming a circular reference. Thus, it returns `true`.

```cpp
        return false;
    }
};
```
- **Return Statement:** If the while loop completes without finding a circular reference, it means the linked list is linear, so the function returns `false`.

### Complete Example
For a linear linked list:
```
1 -> 2 -> 3 -> 4 -> NULL
```
1. The `head` is `1`.
2. `temp` points to `2`.
3. The loop continues checking:
   - `temp == head` (is `2 == 1?`): **No**
   - Move `temp` to `3`.
   - `temp == head` (is `3 == 1?`): **No**
   - Move `temp` to `4`.
   - `temp == head` (is `4 == 1?`): **No**
   - Move `temp` to `NULL`.
4. The loop exits as `temp` is `NULL`, and the function returns `false`.

### Conclusion
The `isCircular` method efficiently checks whether a linked list is circular by traversing it and looking for a cycle. By understanding each part of the code and the process, beginners can grasp how to detect cycles in linked lists using a straightforward iterative approach.
