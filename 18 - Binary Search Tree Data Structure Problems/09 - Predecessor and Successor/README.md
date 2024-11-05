<h1 align='center'>Predecessor - And - Successor</h1>

## Problem Statement

**Problem URL :** [Predecessor And Successor](https://www.geeksforgeeks.org/problems/predecessor-and-successor/1)

![image](https://github.com/user-attachments/assets/b0586a77-cf07-4f1a-bacb-0d200665a113)
![image](https://github.com/user-attachments/assets/9067abd4-1b45-4c55-a84a-c6e96d7f6813)

## Problem Explanation
**Problem:**  
Given a Binary Search Tree (BST) and a key, find the in-order predecessor and successor of the node containing the given key.

- **Predecessor**: The node with the largest value that is smaller than the key.
- **Successor**: The node with the smallest value that is larger than the key.

If either the predecessor or successor does not exist, return `NULL` for that value.

**Example:**
Consider the following BST:

```
         20
       /    \
     8       22
   /   \
  4     12
       /   \
     10    14
```

For `key = 10`:
- **Predecessor** = 8
- **Successor** = 12

**Edge Cases:**
1. Key is the minimum or maximum node in the tree.
2. Key is not found in the BST.
3. The tree has only one node.

---

### Step 2: Approach

**High-Level Overview**:  
This approach involves two main steps:
1. **Locate the Node**: Traverse the tree to locate the node with the given key.
2. **Find Predecessor and Successor**:
   - For **predecessor**: Find the largest node in the left subtree.
   - For **successor**: Find the smallest node in the right subtree.

**Step-by-Step Breakdown**:
1. Traverse the tree from the root.
2. As we traverse, keep track of potential predecessors and successors based on BST properties.
3. Once the key is found, explore its left subtree for the predecessor and right subtree for the successor.

**Pseudocode**:
```plaintext
Initialize `predecessor` and `successor` to NULL.
Set `temp` to the root.

While temp is not NULL:
    - If `temp.key` equals the given key, break.
    - If `temp.key` is greater than the key:
        - Set successor to `temp`.
        - Move left.
    - Else:
        - Set predecessor to `temp`.
        - Move right.

If `temp` is NULL, return (predecessor, successor).

In the left subtree of temp:
    - Find the rightmost node and set it as predecessor.

In the right subtree of temp:
    - Find the leftmost node and set it as successor.

Return (predecessor, successor).
```

## Problem Solution
```cpp
class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {   
        pre = NULL;
        suc = NULL;
        
        // find key
        Node* temp = root;
        while(temp != NULL){
            if(temp -> key == key) break;
            
            if(temp -> key > key){
                suc = temp;
                temp = temp -> left;
            }else{
                pre = temp;
                temp = temp -> right;
            }
        }
        
        if(temp == NULL) return;
        
        Node* leftTree = temp -> left;
        while(leftTree != NULL){
            pre = leftTree;
            leftTree = leftTree -> right;
        }
        
        Node* rightTree = temp -> right;
        while(rightTree != NULL){
            suc = rightTree;
            rightTree = rightTree -> left;
        }
        
    }
};
```

## Problem Solution Explanation
Here’s the given code with a line-by-line breakdown.

Let's break down the provided code for finding the predecessor and successor of a given key in a Binary Search Tree (BST) in a detailed and structured manner. 

### Class and Method Declaration

```cpp
class Solution {
public:
```

- **Class Declaration**: We define a class named `Solution`, which encapsulates our method for finding the predecessor and successor.
- **Access Modifier**: `public` means that the following methods can be accessed from outside the class.

### Method Definition

```cpp
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
```

- **Method Signature**: The method `findPreSuc` takes four parameters:
  - `Node* root`: A pointer to the root of the BST.
  - `Node*& pre`: A reference to a pointer that will store the predecessor node.
  - `Node*& suc`: A reference to a pointer that will store the successor node.
  - `int key`: The key for which we want to find the predecessor and successor.

### Step 1: Initialize Predecessor and Successor

```cpp
pre = NULL;
suc = NULL;
```

- **Initialization**: Both `pre` and `suc` are initialized to `NULL`, indicating that we have not found any predecessor or successor yet.

### Step 2: Find the Key in the BST

```cpp
Node* temp = root;
while(temp != NULL) {
    if(temp->key == key) break;
    
    if(temp->key > key) {
        suc = temp;
        temp = temp->left;
    } else {
        pre = temp;
        temp = temp->right;
    }
}
```

- **Node Traversal**: A temporary pointer `temp` is initialized to `root`, and we enter a loop that continues until `temp` is `NULL`.
- **Key Check**: 
  - **If `temp->key == key`**: If the current node’s key matches the given key, we break the loop since we found the node.
- **Determine Predecessor and Successor**:
  - **If `temp->key > key`**: If the current node's key is greater than the key we are looking for, it could be a potential successor. We set `suc` to `temp` and move left to find a smaller key (which might be closer to the target key).
  - **If `temp->key < key`**: If the current node's key is less than the key, it could be a potential predecessor. We set `pre` to `temp` and move right to find a larger key.

**Example**:  
Suppose we have a BST like this:
```
       20
      /  \
     10   30
    / \    \
   5  15   40
```
- If we are looking for `15`, the traversal goes:
  - Start at `20`: `20 > 15`, set `suc` to `20`, go left to `10`.
  - At `10`: `10 < 15`, set `pre` to `10`, go right to `15`.
  - At `15`: Found the key. Break the loop.

### Step 3: Return if Key Not Found

```cpp
if(temp == NULL) return;
```

- **Check for Existence**: If `temp` is `NULL` after the loop, it means the key does not exist in the BST, so we exit the function.

### Step 4: Find the Predecessor in the Left Subtree

```cpp
Node* leftTree = temp->left;
while(leftTree != NULL) {
    pre = leftTree;
    leftTree = leftTree->right;
}
```

- **Find Predecessor**: If the key was found, we look for the predecessor:
  - We initialize `leftTree` to the left child of `temp`.
  - We then find the rightmost node in the left subtree, which is the predecessor.
  
**Example**: Continuing from the previous example:
- For `temp` being `15`, its left child is `10`. We go to `10` and find its right child (`NULL`), hence `pre` remains `10`.

### Step 5: Find the Successor in the Right Subtree

```cpp
Node* rightTree = temp->right;
while(rightTree != NULL) {
    suc = rightTree;
    rightTree = rightTree->left;
}
```

- **Find Successor**: Similar to predecessor, but we look for the leftmost node in the right subtree:
  - Initialize `rightTree` to the right child of `temp`.
  - Find the leftmost node in the right subtree, which will be the successor.

**Example**: Continuing from our previous example:
- For `temp` being `15`, its right child is `NULL`, so `suc` will point to `20`, which was set when we found the key.
Let's go through a few examples of the `findPreSuc` function and explain the expected output in detail. We will consider different scenarios for the predecessor and successor based on the structure of the Binary Search Tree (BST).

### Example 1: Basic Example

**BST Structure:**
```
       20
      /  \
     10   30
    / \    \
   5  15   40
```

**Test Case 1: Key = 15**
- **Predecessor**: The largest node in the left subtree of `15` is `10`.
- **Successor**: The smallest node in the right subtree of `15` is `20`.

**Output:**
- `Predecessor = 10`
- `Successor = 20`

**Test Case 2: Key = 30**
- **Predecessor**: The largest node in the left subtree of `30` is `20`.
- **Successor**: There is no right subtree for `30`, so `Successor = NULL`.

**Output:**
- `Predecessor = 20`
- `Successor = NULL`

**Test Case 3: Key = 5**
- **Predecessor**: There is no left subtree for `5`, so `Predecessor = NULL`.
- **Successor**: The smallest node in the right subtree of `5` is `10`.

**Output:**
- `Predecessor = NULL`
- `Successor = 10`

### Example 2: Key Not Present

**BST Structure:**
```
       20
      /  \
     10   30
    / \    \
   5  15   40
```

**Test Case 4: Key = 25** (not present in the BST)
- The algorithm would navigate the tree and find that `25` is not present.
- **Predecessor**: The closest smaller key found would be `20` (since `20 < 25`).
- **Successor**: The closest larger key found would be `30` (since `30 > 25`).

**Output:**
- `Predecessor = 20`
- `Successor = 30`

### Example 3: Edge Cases

**BST Structure:**
```
       50
      /  \
     30   70
    / \    \
   20 40   80
```

**Test Case 5: Key = 50** (the root itself)
- **Predecessor**: The largest node in the left subtree of `50` is `40`.
- **Successor**: The smallest node in the right subtree of `50` is `70`.

**Output:**
- `Predecessor = 40`
- `Successor = 70`

**Test Case 6: Key = 20** (smallest key)
- **Predecessor**: There is no left subtree for `20`, so `Predecessor = NULL`.
- **Successor**: The smallest node in the right subtree of `20` is `30`.

**Output:**
- `Predecessor = NULL`
- `Successor = 30`

**Test Case 7: Key = 80** (largest key)
- **Predecessor**: The largest node in the left subtree of `80` is `70`.
- **Successor**: There is no right subtree for `80`, so `Successor = NULL`.

**Output:**
- `Predecessor = 70`
- `Successor = NULL`

### Summary of Outputs

Here’s a summary of the outputs for all the test cases:

| **Key** | **Predecessor** | **Successor** |
|---------|------------------|----------------|
| 15      | 10               | 20             |
| 30      | 20               | NULL           |
| 5       | NULL             | 10             |
| 25      | 20               | 30             |
| 50      | 40               | 70             |
| 20      | NULL             | 30             |
| 80      | 70               | NULL           |

These outputs illustrate how the `findPreSuc` function identifies the predecessor and successor nodes based on the properties of the BST for various keys, including edge cases and keys that may not be present in the tree.

### Step 5: Time and Space Complexity

- **Time Complexity**: \(O(h)\), where \(h\) is the height of the tree. In a balanced BST, this is \(O(\log n)\), but in the worst case (unbalanced tree), it could be \(O(n)\).
- **Space Complexity**: \(O(1)\), as we are using only a constant amount of extra space (excluding the recursive stack).


**Additional Tips:**
- **Edge Cases**: Consider if the key is not present, or if the key is at the extreme (minimum or maximum).
- **Interactive Examples**: Try running the code on a few examples to see the flow of predecessor and successor updates.

