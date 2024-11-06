<h1 align='center'>Normal - BST - to - Balanced - BST</h1>

## Problem Statement

**Problem URL :** [Normal BST to Balanced BST](https://www.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1)

![image](https://github.com/user-attachments/assets/4aa769d6-7a88-42bc-b94a-56d4d97239d2)
![image](https://github.com/user-attachments/assets/a22011cd-dfb8-4315-a246-3321e949a0a6)

## Problem Explanation
Given a Binary Search Tree (BST) that may not be balanced, the task is to convert it into a **balanced** BST while keeping the same values. A balanced BST has a structure where the height difference between the left and right subtrees of any node is no more than 1. This ensures that search operations remain efficient in terms of time complexity.

#### Approach to Solve the Problem

1. **Perform an In-Order Traversal**:
   - In-order traversal of a BST visits nodes in ascending order, resulting in a sorted sequence of values.
   - By storing this sequence in an array or vector, we obtain the sorted values of the BST nodes.

2. **Rebuild the Tree Using the Sorted Array**:
   - Once we have a sorted array of nodes, we can recursively build a balanced BST.
   - By choosing the middle element of the array (or subarray) as the root in each recursive step, we ensure a balanced structure. This divides the array into two halves around the middle element, creating left and right subtrees recursively.

#### Example

Consider a skewed BST like this:
```
    10
      \
       20
         \
          30
            \
             40
```

In-order traversal of this BST gives: `[10, 20, 30, 40]`.

If we build a balanced BST from this sorted array:
```
       20
      /  \
    10    30
            \
             40
```

This balanced structure has a more even height, improving search efficiency.

## Problem Solution
```cpp
class Solution{
    
    public:
    void inOrder(Node* root, vector<Node*> &in_nodes){
        if(root == NULL) return;
        
        inOrder(root -> left, in_nodes);
        in_nodes.push_back(root);
        inOrder(root -> right, in_nodes);
    }
    
    Node* inOrderToBST(int start, int end, vector<Node*> &in_nodes){
        if(start > end) return NULL;
        
        int mid = start + (end - start) / 2;
        Node* root = in_nodes[mid];
        
        root -> left = inOrderToBST(start, mid-1, in_nodes);
        root -> right = inOrderToBST(mid+1, end, in_nodes);
        
        return root;
    }
    
    
    
    Node* buildBalancedTree(Node* root)
    {
    	vector<Node*> in_nodes;
    	inOrder(root, in_nodes);
    	return inOrderToBST(0, in_nodes.size()-1, in_nodes);
    }
};

```

## Problem Solution Explanation

```cpp
class Solution{
    
    public:
```
- Defines the `Solution` class with public member functions.

```cpp
    void inOrder(Node* root, vector<Node*> &in_nodes){
        if(root == NULL) return;
```
- `inOrder` is a helper function to perform an in-order traversal of the BST.
- If `root` is `NULL`, it means there is no node to process, so it returns immediately.

```cpp
        inOrder(root -> left, in_nodes);
        in_nodes.push_back(root);
        inOrder(root -> right, in_nodes);
    }
```
- This function recursively traverses the left subtree, adds the current node (`root`) to the `in_nodes` vector, and then traverses the right subtree.
- The result is a sorted vector `in_nodes` containing all nodes of the BST in ascending order.

```cpp
    Node* inOrderToBST(int start, int end, vector<Node*> &in_nodes){
        if(start > end) return NULL;
```
- `inOrderToBST` is a recursive function that builds a balanced BST from the sorted nodes stored in `in_nodes`.
- If `start > end`, it means there are no nodes to form a subtree, so it returns `NULL`.

```cpp
        int mid = start + (end - start) / 2;
        Node* root = in_nodes[mid];
```
- Calculates the `mid` index of the current range, which represents the middle element of the array.
- This middle element becomes the root of the current subtree, ensuring balance in the resulting BST.

```cpp
        root -> left = inOrderToBST(start, mid-1, in_nodes);
        root -> right = inOrderToBST(mid+1, end, in_nodes);
```
- Recursively sets the `left` child to a balanced subtree built from elements to the left of `mid`.
- Recursively sets the `right` child to a balanced subtree built from elements to the right of `mid`.

```cpp
        return root;
    }
```
- Returns the `root` of the subtree, which will be linked to the main balanced BST.

```cpp
    Node* buildBalancedTree(Node* root)
    {
        vector<Node*> in_nodes;
        inOrder(root, in_nodes);
        return inOrderToBST(0, in_nodes.size()-1, in_nodes);
    }
};
```
- `buildBalancedTree` is the main function that creates the balanced BST.
- First, it performs an in-order traversal using `inOrder` to populate `in_nodes` with nodes in sorted order.
- Then, it calls `inOrderToBST` to construct the balanced BST from `in_nodes` and returns the root of the balanced BST.

### Step 3: Example Walkthrough

Consider a skewed BST:
```
    10
      \
       20
         \
          30
            \
             40
```

1. **In-Order Traversal**:
   - The `inOrder` function will fill `in_nodes` with `[10, 20, 30, 40]`.

2. **Rebuilding as Balanced BST**:
   - `inOrderToBST` with `start = 0` and `end = 3`:
     - **Root Node**: `in_nodes[1]` (20) becomes the root.
     - **Left Subtree**:
       - `inOrderToBST(0, 0)` creates a subtree rooted at `10`.
     - **Right Subtree**:
       - `inOrderToBST(2, 3)` creates a subtree rooted at `30`, with `40` as its right child.
   
   The resulting balanced BST is:
   ```
       20
      /  \
    10    30
            \
             40
   ```

### Step 4: Time and Space Complexity

1. **Time Complexity**:
   - **In-Order Traversal**: \( O(n) \) for traversing the tree and storing nodes in `in_nodes`.
   - **Balanced Tree Construction**: \( O(n) \), as each node is processed once in `inOrderToBST`.
   - **Total Time Complexity**: \( O(n) \).

2. **Space Complexity**:
   - **Auxiliary Space for Vector**: \( O(n) \), to store the nodes.
   - **Recursive Call Stack**: \( O(\log n) \) for a balanced tree, up to \( O(n) \) for a skewed tree.
   - **Total Space Complexity**: \( O(n) \).

### Step 5: Recommendations for Students

- **Understand In-Order Traversal**: This traversal is fundamental in working with BSTs. Practice it to solidify your understanding.
- **Recursive Tree Construction**: Building trees recursively from a sorted list is a powerful concept. It helps in constructing balanced structures for efficient search operations.
- **Time and Space Complexity Analysis**: Knowing how to calculate and understand complexities is essential for optimizing your code, especially with larger inputs.
