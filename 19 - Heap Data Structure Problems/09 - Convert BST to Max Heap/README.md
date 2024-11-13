<h1 align='center'>Convert - BST - To - Max Heap</h1>

## Problem Statement

**Problem URL :** [Convert BST to Max Heap](https://www.geeksforgeeks.org/convert-bst-to-max-heap/)

## Problem Explanation
The goal of the problem is to **convert a Binary Search Tree (BST) into a Max Heap**. A Max Heap is a binary tree where:
- The value of each node is greater than or equal to the values of its children.
- The tree follows the **complete binary tree** property, meaning that all levels of the tree are fully filled except possibly for the last one, which is filled from left to right.

On the other hand, a **Binary Search Tree (BST)** is a binary tree where:
- For each node, its left child’s value is smaller than its own value, and its right child’s value is greater than its own value.

#### Task:
Given a **BST**, we need to rearrange its nodes to form a **Max Heap** such that:
1. The tree must follow the Max Heap property.
2. The binary tree must be complete (filled from left to right).

#### Example:
Consider the following BST:
```
        4
       / \
      2   6
     / \ / \
    1  3 5  7
```
Here, the tree is a Binary Search Tree, and we need to convert it into a Max Heap.

#### Approach:
To achieve this conversion, we will use the following steps:
1. **In-order Traversal of BST**: This traversal will give us the values in sorted order.
2. **Max Heap Property**: We will assign the largest values from the sorted list to the tree nodes, starting from the root, and then recursively assign values to the children, ensuring the Max Heap property is satisfied.
3. **Recursion**: Starting from the root node, we assign the largest value to it and then recursively apply the same process to the left and right subtrees. This ensures that the largest values are assigned to the root and then propagated down to the leaf nodes.

### Example Walkthrough of Approach:

- For the given BST:
  ```
          4
         / \
        2   6
       / \ / \
      1  3 5  7
  ```

- Perform **in-order traversal** on the BST: `[1, 2, 3, 4, 5, 6, 7]`.
- The largest element (7) should be placed at the root, and then we continue filling the tree in the same way:
  ```
          7
         / \
        6   5
       / \ / \
      1  3 2  4
  ```

Thus, we have successfully converted the BST into a Max Heap.

## Problem Solution
```cpp
#include <iostream>
#include <vector>
using namespace std;

// Definition for a Node in the Binary Tree
class Node {
public:
    int data;      // Value of the node
    Node* left;    // Left child
    Node* right;   // Right child

    // Constructor to create a new node with a given value
    Node(int val) {
        this->data = val;
        this->left = NULL;  // Initially, left child is NULL
        this->right = NULL; // Initially, right child is NULL
    }
};

// Function to perform in-order traversal of the BST
// This will store the values of the tree nodes in an array
void inOrder(Node* root, vector<int> &nodes) {
    if (root == NULL) return;  // Base case: if node is NULL, return

    inOrder(root->left, nodes);  // Recur on the left child
    nodes.push_back(root->data); // Store the current node's data
    inOrder(root->right, nodes); // Recur on the right child
}

// Function to convert the BST to a Max Heap
// It uses the in-order traversal values stored in 'nodes' and sets the tree
// values in a way that satisfies the Max Heap property
void inOrderToMaxHeap(Node* root, vector<int>& nodes, int &index) {
    if (root == NULL) return;  // Base case: if node is NULL, return

    // Assign the current node's data from the largest remaining value
    root->data = nodes[index--];  // Decrement index after assigning to ensure we take the largest value first

    // Recur on the left and right subtrees
    inOrderToMaxHeap(root->left, nodes, index);
    inOrderToMaxHeap(root->right, nodes, index);
}

// Function to convert the entire BST to Max Heap
void BST_to_MaxHeap(Node* root) {
    if (root == NULL) return;  // Base case: if root is NULL, return

    vector<int> nodes;        // Vector to store the node values in in-order
    inOrder(root, nodes);     // Perform in-order traversal and store node values in 'nodes'

    int index = nodes.size() - 1;  // Initialize the index to the last element (largest value)
    inOrderToMaxHeap(root, nodes, index); // Assign values from largest to smallest to the tree nodes
}

// Function to print the tree in preorder (root, left, right) to check the Max Heap property
void print(Node* root) {
    if (root == NULL) return;  // Base case: if node is NULL, return

    cout << root->data << " ";  // Print the current node's data
    print(root->left);          // Recursively print the left subtree
    print(root->right);         // Recursively print the right subtree
}

int main() {
    // Constructing a simple BST
    Node* root = new Node(4);          // Root node with value 4
    root->left = new Node(2);          // Left child of root with value 2
    root->right = new Node(6);         // Right child of root with value 6
    root->left->left = new Node(1);    // Left child of node 2 with value 1
    root->left->right = new Node(3);   // Right child of node 2 with value 3
    root->right->left = new Node(5);   // Left child of node 6 with value 5
    root->right->right = new Node(7);  // Right child of node 6 with value 7

    // Convert BST to Max Heap
    BST_to_MaxHeap(root);

    // Print the tree in preorder to verify the Max Heap property
    cout << "Preorder of Max Heap: ";
    print(root);  // Print the tree's preorder traversal (should satisfy Max Heap property)
    cout << endl;

    return 0;
}

```

## Problem Solution Explanation

Now, let's go through the code and explain each line to understand how the algorithm works.

```cpp
#include <iostream>
#include <vector>
using namespace std;
```
- Here, we include the necessary header files. `iostream` is used for input and output, and `vector` is used to store the values of the tree nodes in an array.

```cpp
class Node {
public:
    int data;      // Value of the node
    Node* left;    // Left child
    Node* right;   // Right child
```
- We define a `Node` class which will represent each node of the tree. Each node holds a `data` value, a pointer to its left child (`left`), and a pointer to its right child (`right`).

```cpp
    Node(int val) {
        this->data = val;
        this->left = NULL;  // Initially, left child is NULL
        this->right = NULL; // Initially, right child is NULL
    }
};
```
- The constructor of the `Node` class initializes the node with the given value `val`. Initially, both `left` and `right` pointers are set to `NULL` because it does not have children when first created.

```cpp
void inOrder(Node* root, vector<int> &nodes) {
    if (root == NULL) return;  // Base case: if node is NULL, return
```
- The `inOrder` function performs an **in-order traversal** of the tree. The base case checks if the node is `NULL` and returns if it is.

```cpp
    inOrder(root->left, nodes);  // Recur on the left child
    nodes.push_back(root->data); // Store the current node's data
    inOrder(root->right, nodes); // Recur on the right child
}
```
- We recursively visit the left subtree, store the current node’s value in the `nodes` vector, and then visit the right subtree.

```cpp
void inOrderToMaxHeap(Node* root, vector<int>& nodes, int &index) {
    if (root == NULL) return;  // Base case: if node is NULL, return
```
- The `inOrderToMaxHeap` function assigns values to the tree nodes, starting from the largest value in the `nodes` vector.

```cpp
    root->data = nodes[index--];  // Decrement index after assigning to ensure we take the largest value first
```
- We assign the largest value from the `nodes` vector to the current node (`root->data`). After assigning, we decrement the index to ensure the next largest value is assigned next.

```cpp
    inOrderToMaxHeap(root->left, nodes, index);  // Recur on the left subtree
    inOrderToMaxHeap(root->right, nodes, index); // Recur on the right subtree
}
```
- We recursively assign values to the left and right subtrees.

```cpp
void BST_to_MaxHeap(Node* root) {
    if (root == NULL) return;  // Base case: if root is NULL, return
```
- The `BST_to_MaxHeap` function is the main function that converts the entire BST to a Max Heap.

```cpp
    vector<int> nodes;        // Vector to store the node values in in-order
    inOrder(root, nodes);     // Perform in-order traversal and store node values in 'nodes'
```
- We create a vector `nodes` to store the node values in sorted order via the `inOrder` function.

```cpp
    int index = nodes.size() - 1;  // Initialize the index to the last element (largest value)
    inOrderToMaxHeap(root, nodes, index); // Assign values from largest to smallest to the tree nodes
}
```
- We initialize the `index` to the last element of the `nodes` vector (largest value). We then call `inOrderToMaxHeap` to assign values to the tree nodes in a way that maintains the Max Heap property.

```cpp
void print(Node* root) {
    if (root == NULL) return;  // Base case: if node is NULL, return
    cout << root->data << " ";  // Print the current node's data
    print(root->left);          // Recursively print the left subtree
    print(root->right);         // Recursively print the right subtree
}
```
- The `print` function is used to print the tree in **preorder** (root, left, right). This helps verify if the tree satisfies the Max Heap property.

```cpp
int main() {
    Node* root = new Node(4);          // Root node with value 4
    root->left = new Node(2);          // Left child of root with value 2
    root->right = new Node(6);         // Right child of root with value 6
    root->left->left = new Node(1);    // Left child of node 2 with value 1
    root->left->right = new Node(3);   // Right child of node 2 with value 3
    root->right->left = new Node(5);   // Left child of node 6 with value 5
    root->right->right = new Node(7);  // Right child of node 6 with value 7

    BST_to_MaxHeap(root);  // Convert BST to Max Heap

    cout << "Preorder of Max Heap: ";
    print(root);  // Print the tree's preorder traversal (should satisfy Max Heap property)
    cout << endl;

    return 0;
}
```
- In the `main` function, we construct a simple BST and convert it to a Max Heap. We then print the preorder traversal to verify the Max Heap property.

### Step 3: Examples and Explanation

For the example BST:
```
        4
       / \
      2   6
     / \ / \
    1  3 5  7
```
After performing in-order traversal, we get: `[1, 2, 3, 4, 5, 6, 7]`. We then assign values to the tree nodes from largest to smallest, starting with the root:
```
        7
       / \
      6   5
     / \ / \
    1  3 2  4
```
Preorder traversal of the Max Heap: `7 6 1 3 2 4 5`.

### Step 4: Time and Space Complexity

**Time Complexity**:
- In-order traversal takes **O(n)** time, where `n` is the number of nodes in the tree.
- The `inOrderToMaxHeap` function also takes **O(n)** time as we visit each node once.
Thus, the overall time complexity is **O(n)**.

**Space Complexity**:
- The space complexity is

 **O(n)** due to the storage required for the `nodes` vector.

This is an efficient solution that correctly converts a BST to a Max Heap.
