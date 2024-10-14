<h1 align='center'>Flattening - a Linked - List</h1>

## Problem Statement

**Problem URL :** [Flattening a Linked List](https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1)

![image](https://github.com/user-attachments/assets/5efa6535-7a17-4b59-9f4a-5dfc4038f81e)
![image](https://github.com/user-attachments/assets/dce09e17-cc20-472e-b086-58e292ff36a6)

## Problem Explanation
You are given a linked list where each node has two pointers:
1. **`next`**: It points to the next node in the main list.
2. **`bottom`**: It points to a linked list where each node is smaller than the next node in the bottom chain.

Your task is to flatten the entire linked list into a **single list** where all nodes follow a bottom-down hierarchy, and the list is sorted in ascending order.

#### Input:
- A linked list with nodes that have two pointers: `next` (for horizontal connections) and `bottom` (for vertical connections).

#### Output:
- A single flattened linked list where all nodes are sorted based on their values and only the `bottom` pointer is used.

---

### Approach:

1. The problem involves multiple linked lists connected via two kinds of pointers (`next` and `bottom`).
2. We want to:
   - **Recursively** traverse the `next` pointer (horizontal list).
   - **Merge** each linked list in the `bottom` chain using a two-way merge (like merging two sorted linked lists).
   
3. The key is to flatten the entire structure step-by-step, merging two lists at a time until we get a single sorted list that uses only the `bottom` pointers.


## Problem Solution
```cpp
class Solution {
  private:
    Node* mergeTwoLists(Node* a, Node* b){
        if(a == NULL) return b;
        if(b == NULL) return a;
        
        Node* result;
        
        if(a -> data < b -> data){
            result = a;
            result -> bottom = mergeTwoLists(a->bottom, b);
        }else{
            result = b;
            result -> bottom = mergeTwoLists(a, b->bottom);
        }
        
        return result;
    }
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        if(root == NULL || root -> next == NULL) return root;
        
        return mergeTwoLists(root, flatten(root->next));
        
    }
};
```

## Problem Solution Explanation

Let’s go through the code step-by-step.

### 1. **Function 1: `mergeTwoLists` - Merging Two Bottom Linked Lists**

```cpp
Node* mergeTwoLists(Node* a, Node* b) {
    if(a == NULL) return b;
    if(b == NULL) return a;
    
    Node* result;
    
    if(a -> data < b -> data) {
        result = a;
        result -> bottom = mergeTwoLists(a->bottom, b);
    } else {
        result = b;
        result -> bottom = mergeTwoLists(a, b->bottom);
    }
    
    return result;
}
```

#### Explanation:
- **Purpose**: This function merges two sorted linked lists (`a` and `b`), where each list uses the `bottom` pointer to link the next node.
- **Base Case**: 
  - If one list is `NULL`, return the other list (since nothing is left to merge).
- **Recursive Step**:
  - Compare the `data` values of the current nodes in `a` and `b`.
  - If `a->data` is smaller, set the result as `a` and recursively merge `a->bottom` with `b`.
  - Otherwise, set the result as `b` and recursively merge `a` with `b->bottom`.
  
#### Example:

Merging two lists:
```
a: 1 -> 3 -> 5
b: 2 -> 4 -> 6
```
Steps:
1. Compare `1` and `2`: `1 < 2`, so add `1` to the result list, then merge `3 -> 5` with `2 -> 4 -> 6`.
2. Compare `3` and `2`: `2 < 3`, so add `2` to the result list, then merge `3 -> 5` with `4 -> 6`.
3. Continue merging until both lists are exhausted, resulting in:
   ```
   1 -> 2 -> 3 -> 4 -> 5 -> 6
   ```

---

### 2. **Function 2: `flatten` - Recursively Flattening the Linked List**

```cpp
Node* flatten(Node* root) {
    if (root == NULL || root -> next == NULL) return root;
    
    return mergeTwoLists(root, flatten(root->next));
}
```

#### Explanation:
- **Base Case**: If the `root` is `NULL` (empty list) or if `root->next` is `NULL` (only one sublist), return `root` since it's already flattened.
  
- **Recursive Step**:
  1. **Recursive Call**: First, recursively flatten the rest of the list (`root->next`).
  2. **Merge**: Once the `next` list is flattened, merge the current sublist (`root`) with the already flattened `next` list using the `mergeTwoLists` function.
  
#### Example:

Consider the following linked list:
```
1 -> 3 -> 5
|    |    |
2    4    6
```

1. Start at `root` (`1 -> 2`).
2. **Recursive Call**: Flatten the list starting at `3 -> 4`:
   - Flatten the list starting at `5 -> 6`.
   - The flattened list from `5 -> 6` is already `5 -> 6`.
3. **Merge**:
   - Merge the lists `3 -> 4` and `5 -> 6` to get `3 -> 4 -> 5 -> 6`.
4. Finally, merge the lists `1 -> 2` and `3 -> 4 -> 5 -> 6` to get the fully flattened list:
   ```
   1 -> 2 -> 3 -> 4 -> 5 -> 6
   ```

---

### Conclusion:

The solution uses **recursion** to flatten the list one step at a time and then merges the smaller lists using a helper function `mergeTwoLists`. This ensures that at each recursive step, we are dealing with smaller and smaller lists, making the solution efficient.
