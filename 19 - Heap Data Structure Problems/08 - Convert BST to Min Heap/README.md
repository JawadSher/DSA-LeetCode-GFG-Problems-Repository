<h1 align='center'>Convert - BST - To - Min Heap</h1>

## Problem Statement

**Problem URL :** [Convert BST to Min Heap](https://www.geeksforgeeks.org/convert-bst-min-heap/)

**Problem Statement**:
You are given a **Binary Search Tree (BST)**, and you need to convert it into a **Min Heap**. 

- **Binary Search Tree (BST)**:
  - A BST is a binary tree where for each node:
    - All values in the left subtree are smaller than the node's value.
    - All values in the right subtree are greater than the node's value.
  
- **Min Heap**:
  - A Min Heap is a binary tree that satisfies the **heap property**:
    - The value of each node is **smaller** than the values of its children.
    - It’s a complete binary tree (i.e., all levels are filled except possibly the last level, which is filled from left to right).
  
**Objective**:
Convert the given **BST** into a **Min Heap**, but you must maintain the **heap property**.

**Approach**:
To solve this, you can use the following steps:
1. **Extract All Elements from the BST in Sorted Order**:
   - Perform an **inorder traversal** on the BST. This traversal gives you the elements in **ascending order**.
  
2. **Transform the BST into a Min Heap**:
   - After collecting the elements, you will use **preorder traversal** to assign values to the nodes. The **preorder traversal** ensures that you fill the tree in a top-to-bottom, left-to-right manner, which is necessary for a **Min Heap**.
   - The smallest elements from the sorted list will be assigned to the nodes, respecting the heap property.

**Example**:
- **Input BST**:
  ```
           4
         /   \
        2     6
       / \   / \
      1   3 5   7
  ```

- **Inorder Traversal of BST**: `[1, 2, 3, 4, 5, 6, 7]`

- **Resulting Min Heap** (after transforming the BST into a Min Heap):
  ```
           1
         /   \
        2     3
       / \   / \
      4   5 6   7
  ```




## Problem Solution
```cpp
#include <iostream>
#include <vector>
using namespace std;

// Definition for a Node in the Binary Tree
class Node {
public:
    int data;
    Node* left;
    Node* right;
  
    // Constructor to create a new node with given value
    Node(int val) {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to perform inorder traversal on the BST
// This collects all node values in sorted order
void inOrder(Node* root, vector<int>& nodes) {
    if (root == NULL) return; // Base case for recursion

    inOrder(root->left, nodes);      // Traverse left subtree
    nodes.push_back(root->data);     // Visit node and add its value to the vector
    inOrder(root->right, nodes);     // Traverse right subtree
}

// Function to transform the BST to a Min Heap using preorder traversal
// It assigns values from the sorted list to each node
void inOrderToMinHeap(Node* root, vector<int>& nodes, int& index) {
    if (root == NULL) return; // Base case for recursion

    // Assign the current node with the next value in sorted order
    root->data = nodes[index++];

    // Continue assigning values to left and right children
    inOrderToMinHeap(root->left, nodes, index);
    inOrderToMinHeap(root->right, nodes, index);
}

// Main function to convert BST to Min Heap
void BST_to_MinHeap(Node* root) {
    if (root == NULL) { // Check for an empty tree
        cout << "Empty Tree" << endl;
        return;
    }

    vector<int> nodes; // Vector to store nodes in sorted order

    // Step 1: Store elements of BST in sorted order
    inOrder(root, nodes);

    int index = 0;
    // Step 2: Assign values from sorted list to nodes in preorder traversal
    inOrderToMinHeap(root, nodes, index);
}

// Function to print the tree in preorder to check Min Heap property
void print(Node* root) {
    if (root == NULL) return; // Base case for recursion

    cout << root->data << " "; // Print current node
    print(root->left);         // Print left subtree
    print(root->right);        // Print right subtree
}

int main() {
    // Constructing a simple BST
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    // Convert BST to Min Heap
    BST_to_MinHeap(root);
    
    // Print the tree in preorder to verify Min Heap property
    cout << "Preorder of Min Heap : ";
    print(root);
    cout << endl;
    
    return 0;
}

```

## Problem Solution Explanation
```cpp
#include <iostream>
#include <vector>
using namespace std;

// Definition for a Node in the Binary Tree
class Node {
public:
    int data;
    Node* left;
    Node* right;
  
    // Constructor to create a new node with given value
    Node(int val) {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};
```
- **Node Class**:
  - The `Node` class is defined for the binary tree nodes. Each node contains:
    - `data`: The value of the node.
    - `left`: Pointer to the left child node.
    - `right`: Pointer to the right child node.
  - The constructor initializes these values for each node.

```cpp
// Function to perform inorder traversal on the BST
// This collects all node values in sorted order
void inOrder(Node* root, vector<int>& nodes) {
    if (root == NULL) return; // Base case for recursion

    inOrder(root->left, nodes);      // Traverse left subtree
    nodes.push_back(root->data);     // Visit node and add its value to the vector
    inOrder(root->right, nodes);     // Traverse right subtree
}
```
- **`inOrder` function**:
  - This is a standard recursive **inorder traversal** of a binary tree.
  - It collects the values of the nodes in **sorted order** in the `nodes` vector.

```cpp
// Function to transform the BST to a Min Heap using preorder traversal
// It assigns values from the sorted list to each node
void inOrderToMinHeap(Node* root, vector<int>& nodes, int& index) {
    if (root == NULL) return; // Base case for recursion

    // Assign the current node with the next value in sorted order
    root->data = nodes[index++];

    // Continue assigning values to left and right children
    inOrderToMinHeap(root->left, nodes, index);
    inOrderToMinHeap(root->right, nodes, index);
}
```
- **`inOrderToMinHeap` function**:
  - This function is used to convert the BST to a Min Heap.
  - It uses **preorder traversal** and assigns values to the nodes starting from the root. The sorted list of node values is used to assign values to the nodes.
  - The variable `index` tracks the current position in the sorted list of values.

```cpp
// Main function to convert BST to Min Heap
void BST_to_MinHeap(Node* root) {
    if (root == NULL) { // Check for an empty tree
        cout << "Empty Tree" << endl;
        return;
    }

    vector<int> nodes; // Vector to store nodes in sorted order

    // Step 1: Store elements of BST in sorted order
    inOrder(root, nodes);

    int index = 0;
    // Step 2: Assign values from sorted list to nodes in preorder traversal
    inOrderToMinHeap(root, nodes, index);
}
```
- **`BST_to_MinHeap` function**:
  - This is the main function where the process begins.
  - First, it checks if the tree is empty and prints a message if true.
  - It calls the `inOrder` function to collect the nodes in sorted order.
  - Then, it calls `inOrderToMinHeap` to convert the tree into a Min Heap using the sorted values.

```cpp
// Function to print the tree in preorder to check Min Heap property
void print(Node* root) {
    if (root == NULL) return; // Base case for recursion

    cout << root->data << " "; // Print current node
    print(root->left);         // Print left subtree
    print(root->right);        // Print right subtree
}
```
- **`print` function**:
  - This is a **preorder traversal** function used to print the tree after transformation. This helps verify the Min Heap property.
  - It prints the current node, then recursively prints the left and right children.

```cpp
int main() {
    // Constructing a simple BST
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    // Convert BST to Min Heap
    BST_to_MinHeap(root);
    
    // Print the tree in preorder to verify Min Heap property
    cout << "Preorder of Min Heap : ";
    print(root);
    cout << endl;
    
    return 0;
}
```
- **Main Function**:
  - A simple **BST** is constructed manually using `Node` objects.
  - The `BST_to_MinHeap` function is called to convert the BST into a Min Heap.
  - The `print` function is used to print the tree in preorder to verify the Min Heap property.

### Step 3: Example Walkthrough

#### Example 1:

**Input BST**:
```
         4
       /   \
      2     6
     / \   / \
    1   3 5   7
```

**Inorder Traversal**: `[1, 2, 3, 4, 5, 6, 7]`

After converting to a Min Heap:

**Min Heap**:
```
         1
       /   \
      2     3
     / \   / \
    4   5 6   7
```

**Preorder of Min Heap**: `1 2 4 5 3 6 7`

#### Example 2:

For an empty tree, the output will be:
```
Empty Tree
```

### Step 4: Time and Space Complexity

- **Time Complexity**:
  - **Inorder Traversal (`inOrder`)**: This takes **O(n)** time, where `n` is the number of nodes in the tree.
  - **Preorder Traversal (`inOrderToMinHeap`)**: This also takes **O(n)** time as it visits each node once.
  - **Overall Time Complexity**: **O(n)**, where `n` is the number of nodes in the BST.

- **Space Complexity**:
  - **Auxiliary Space**:
    - The `nodes` vector stores `n` elements, so it requires **O(n)** space.
    - The recursion stack also takes **O(h)** space, where `h` is the height of the tree.
    - **Overall Space Complexity**: **O(n)**, considering the storage for the nodes and recursion stack.

### Step 5: Additional Recommendations for Students

- **Understanding Recursion**: Recursion is key to both the inorder and preorder traversals. Understanding how recursion works will help in other tree-based problems as well.
- **Practice with Other Tree Transformations**: Try solving similar problems, such as converting a **BST to a max-heap** or **flattening a binary tree** into a linked list.
- **Edge Cases**: Always test edge cases, such as an empty tree or a tree with only one node, to ensure your solution works in all scenarios.
