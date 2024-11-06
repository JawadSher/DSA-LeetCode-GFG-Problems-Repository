<h1 align='center'>Flatten - BST - to - Sorted - List</h1>

## Problem Statement

**Problem URL :** [Flatten BST to Sorted List](https://www.geeksforgeeks.org/problems/flatten-bst-to-sorted-list--111950/0)

![image](https://github.com/user-attachments/assets/d1407faf-b1ff-484a-a4fd-cc52cc199310)
![image](https://github.com/user-attachments/assets/76c864cf-4db8-40e9-b88b-c9d1d65cc684)
![image](https://github.com/user-attachments/assets/d4724782-33c2-448d-be5c-f4deb9259421)

## Problem Explanation
Given a Binary Search Tree (BST), the goal is to "flatten" it into a sorted, linked list structure. Specifically:
- Transform the BST so that each node points to the next node in in-order traversal (left to right, smallest to largest).
- The "left" pointers should be set to `NULL`, and each "right" pointer should link to the next node in sorted order.

#### Approach to Solve the Problem

1. **In-Order Traversal**:
   - Since an in-order traversal of a BST results in a sorted sequence, we can use it to collect nodes in sorted order.
2. **Rearrange Nodes**:
   - Once we have all nodes in a sorted sequence, we can rearrange their pointers to form a linked list structure.

#### Example

Consider the following BST:
```
        5
       / \
      3   7
     / \   \
    2   4   8
```

In-order traversal of this BST gives: `[2, 3, 4, 5, 7, 8]`.

The flattened list will look like:
```
2 -> 3 -> 4 -> 5 -> 7 -> 8 -> NULL
```
## Problem Solution
```cpp
class Solution
{
public:
    void inOrder(Node* root, vector<Node*> &nodes){
        if(root == NULL) return;
        
        inOrder(root -> left, nodes);
        nodes.push_back(root);
        inOrder(root -> right, nodes);
    }
    Node *flattenBST(Node *root)
    {
        if(root == NULL) return NULL;
        
        vector<Node*> nodes;
        inOrder(root, nodes);
        
        Node* newRoot = nodes[0];
        Node* current = newRoot;
        
        for(int i = 1; i < nodes.size(); i++){
            current -> left = NULL;
            current -> right = nodes[i];
            current = nodes[i];
        }
        
        current -> left = NULL;
        current -> right = NULL;
        
        return newRoot;
    }
};
```

## Problem Solution Explanation

```cpp
class Solution
{
public:
```
- Defines a `Solution` class with public member functions.

```cpp
    void inOrder(Node* root, vector<Node*> &nodes){
        if(root == NULL) return;
```
- `inOrder` is a helper function that performs an in-order traversal of the BST.
- If the current `root` is `NULL`, the function exits since there's no node to process.

```cpp
        inOrder(root -> left, nodes);
        nodes.push_back(root);
        inOrder(root -> right, nodes);
    }
```
- The function recursively traverses the left subtree, adds the current node (`root`) to the `nodes` vector, and then traverses the right subtree.
- This process ensures that nodes are added in sorted order.

```cpp
    Node *flattenBST(Node *root)
    {
        if(root == NULL) return NULL;
```
- `flattenBST` is the main function that initiates the process of flattening the BST.
- If `root` is `NULL`, it returns `NULL` immediately as there's nothing to flatten.

```cpp
        vector<Node*> nodes;
        inOrder(root, nodes);
```
- Creates an empty vector `nodes` to store BST nodes in sorted order.
- Calls the `inOrder` function to fill `nodes` with the nodes of the BST in sorted order.

```cpp
        Node* newRoot = nodes[0];
        Node* current = newRoot;
```
- Sets `newRoot` to the first node in `nodes` (smallest value in the BST) to be the new root of the flattened list.
- `current` is a pointer that will help to link each node in the list.

```cpp
        for(int i = 1; i < nodes.size(); i++){
            current -> left = NULL;
            current -> right = nodes[i];
            current = nodes[i];
        }
```
- Iterates through the remaining nodes in `nodes`.
- For each node:
  - Sets the `left` pointer to `NULL` (since we want a single linked list).
  - Sets the `right` pointer of `current` to point to the next node in `nodes`.
  - Updates `current` to point to the next node.

```cpp
        current -> left = NULL;
        current -> right = NULL;
```
- Ensures that the last node in the list points to `NULL` for both `left` and `right` pointers.

```cpp
        return newRoot;
    }
};
```
- Returns `newRoot`, which is the head of the flattened list.

### Step 3: Example Walkthrough

Let's apply the code to the BST:
```
        5
       / \
      3   7
     / \   \
    2   4   8
```

1. **In-Order Traversal**: The `inOrder` function produces a sorted list of nodes in `nodes` as `[2, 3, 4, 5, 7, 8]`.
  
2. **Flattening Process**:
   - `newRoot` is set to `nodes[0]`, which is node `2`.
   - The `for` loop iterates through the `nodes` vector, setting up the linked list:
     ```
     2 -> 3 -> 4 -> 5 -> 7 -> 8 -> NULL
     ```
   - The flattened list is returned, starting from `newRoot`, which points to `2`.

### Step 4: Time and Space Complexity

1. **Time Complexity**:
   - **In-Order Traversal**: \( O(n) \), where \( n \) is the number of nodes in the BST.
   - **Flattening Process**: \( O(n) \) for linking nodes in the sorted order.
   - **Total Time Complexity**: \( O(n) + O(n) = O(n) \).

2. **Space Complexity**:
   - **Auxiliary Space for Vector**: \( O(n) \) for storing nodes in `nodes`.
   - **Recursive Call Stack**: \( O(h) \), where \( h \) is the height of the tree (up to \( O(\log n) \) for balanced BSTs, \( O(n) \) for skewed trees).
   - **Total Space Complexity**: \( O(n) \).

### Step 5: Recommendations for Students

- **Practice Recursive Tree Traversals**: Understanding in-order traversal is essential for this solution. Practice it on other trees to get comfortable.
- **Learn About Linked Lists**: Since the output is a linked list, knowing how to manipulate pointers (left and right pointers) will help.
- **Dry-Run the Code on Examples**: Take a small BST, manually run through the code, and verify each step aligns with the explanation.
- **Understand Complexity Analysis**: Being able to calculate time and space complexity is crucial for efficiency in tree problems, especially as trees grow larger.
