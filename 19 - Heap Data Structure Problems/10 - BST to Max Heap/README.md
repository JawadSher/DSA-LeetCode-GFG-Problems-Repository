<h1 align='center'>BST - To - Max - Heap</h1>

## Problem Statement

**Problem URL :** [BST to Max Heap](https://www.geeksforgeeks.org/problems/bst-to-max-heap/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/4f1bd61f-eafd-4735-b17d-0701ca51da07)
![image](https://github.com/user-attachments/assets/cc9b7ba1-d1ae-419b-8848-01583744cc82)

## Problem Explanation

The problem requires us to **convert a Binary Search Tree (BST)** into a **Max Heap** while maintaining the property that in the resulting Max Heap:
1. The value of each parent node must be greater than or equal to the values of its children (Max Heap Property).
2. The values in the left subtree must be less than those in the right subtree for every node in the tree.

**Explanation:**
- A **Binary Search Tree (BST)** is a binary tree where for every node:
  - The left child is smaller than the parent node.
  - The right child is greater than the parent node.
  
- A **Max Heap** is a binary tree where the value of each node is greater than or equal to the values of its children, and the tree is complete (i.e., all levels are filled except possibly the last one, which is filled from left to right).

The task is to take a given BST and convert it into a Max Heap while satisfying the special condition that all values in the left subtree of a node should be less than all values in the right subtree. After converting the tree to a Max Heap, we need to perform a post-order traversal of the tree and return the result.

**Example:**

Given the following BST:

```
        4
       / \
      2   6
     / \ / \
    1  3 5  7
```

We need to transform it into a Max Heap where the largest element goes to the root, and the tree is arranged such that:
1. All left child nodes are less than the right child nodes.
2. The Max Heap property is maintained.

After conversion, the tree will look like this:

```
        7
       / \
      3   6
     / \ / \
    1  2 4  5
```

The post-order traversal of this tree is: **1 2 3 4 5 6 7**.

## Problem Solution
```cpp
class Solution{
  public:
    void inOrder(Node* root, vector<int> &nodes){
        if(root == NULL) return;
        
        inOrder(root -> left, nodes);
        nodes.push_back(root -> data);
        inOrder(root -> right, nodes);
    }
    
    void inOrderToHeap(Node* root, vector<int> &nodes, int & index){
        if(root == NULL) return;
        
        inOrderToHeap(root -> left, nodes, index);
        inOrderToHeap(root -> right, nodes, index);
        
        root -> data = nodes[index++];
    }
    
    void convertToMaxHeapUtil(Node* root)
    {
        vector<int> nodes;
        inOrder(root, nodes);
        
        int index = 0;
        inOrderToHeap(root, nodes, index);
    }    
};
```

## Problem Solution Explanation

```cpp
class Solution{
public:
    // Step 1: In-order traversal to collect node values
    void inOrder(Node* root, vector<int> &nodes){
        if(root == NULL) return;  // Base case: if the node is null, return
        
        inOrder(root -> left, nodes);  // Recurse on the left subtree
        nodes.push_back(root -> data);  // Store the current node's value
        inOrder(root -> right, nodes);  // Recurse on the right subtree
    }
```

#### Explanation:

1. **Function Definition (`inOrder`)**:
   - The function `inOrder(Node* root, vector<int> &nodes)` performs an **in-order traversal** of the binary tree (BST) starting at the root.
   - It takes the `root` node of the tree and a reference to a vector `nodes` which will store the values of the tree in ascending order.
   
2. **Base Case (`if(root == NULL) return;`)**:
   - If the current node is `NULL`, this means we've reached the end of a branch, and there’s no further processing required. So, the function returns.

3. **Recursion (`inOrder(root -> left, nodes);`)**:
   - The function first recursively processes the **left subtree**. This ensures that we visit all the nodes in the left subtree first, which is characteristic of in-order traversal.
   
4. **Storing Node Value (`nodes.push_back(root -> data);`)**:
   - After visiting the left child, the current node's data is added to the `nodes` vector.
   - This will collect the node values in ascending order because in a BST, the left child is always smaller than the parent, and the right child is always larger.

5. **Recursion (`inOrder(root -> right, nodes);`)**:
   - Finally, the function recursively processes the **right subtree** of the current node.
   - The in-order traversal ensures that nodes are processed in the correct order.

**Example Walkthrough:**
Let’s assume we have the following BST:

```
        4
       / \
      2   6
     / \ / \
    1  3 5  7
```

The `inOrder` function would collect the values in the following order:
1. Start at `4`, go to the left child `2`, go to the left child `1` (add `1` to the vector).
2. Visit node `2` (add `2` to the vector).
3. Visit node `3` (add `3` to the vector).
4. Visit node `4` (add `4` to the vector).
5. Visit node `5` (add `5` to the vector).
6. Visit node `6` (add `6` to the vector).
7. Visit node `7` (add `7` to the vector).

After in-order traversal, the `nodes` vector will contain the sorted values: `[1, 2, 3, 4, 5, 6, 7]`.



```cpp
    // Step 2: Postorder traversal to replace node values with those from the sorted list
    void inOrderToHeap(Node* root, vector<int> &nodes, int &index){
        if(root == NULL) return;  // Base case: if the node is null, return
        
        // Recurse on the left and right subtrees first (postorder traversal)
        inOrderToHeap(root -> left, nodes, index);
        inOrderToHeap(root -> right, nodes, index);
        
        // Replace the current node's value with the largest remaining value from the sorted list
        root -> data = nodes[index++];  // Assign value from the vector to the node
    }
```

#### Explanation:

1. **Function Definition (`inOrderToHeap`)**:
   - The function `inOrderToHeap(Node* root, vector<int> &nodes, int &index)` performs a **postorder traversal** of the binary tree (BST) starting at the root.
   - It takes the current `root` node, the `nodes` vector containing the sorted values, and an `index` reference that helps track which value from the `nodes` vector should be assigned to the current node.

2. **Base Case (`if(root == NULL) return;`)**:
   - If the current node is `NULL`, the function returns because there’s no node to process.

3. **Recursion (`inOrderToHeap(root -> left, nodes, index);`)**:
   - The function first recursively processes the **left subtree** in postorder fashion, ensuring the left children are visited before the parent.

4. **Recursion (`inOrderToHeap(root -> right, nodes, index);`)**:
   - After processing the left subtree, the function processes the **right subtree**, again in postorder fashion.

5. **Assigning Sorted Values (`root -> data = nodes[index++];`)**:
   - After both left and right subtrees have been processed, the function assigns the next value from the `nodes` vector (sorted list) to the current node.
   - The value is assigned from the end of the `nodes` vector (`index++`), which ensures that the largest values are assigned to the root and parent nodes first, preserving the Max Heap property.
   
**Example Walkthrough:**
After collecting the sorted values `[1, 2, 3, 4, 5, 6, 7]` in the `nodes` vector, we process the tree in postorder:
1. We first visit the leftmost child (`1`) and assign the largest value from `nodes` to it. The largest value is `7`, so `1` is replaced with `7`.
2. Then, we visit node `2`, and the next largest value (`6`) from the `nodes` vector is assigned to it.
3. This process continues recursively for the entire tree.

After all recursive calls are done, the tree will look like this:

```
        7
       / \
      3   6
     / \ / \
    1  2 4  5
```

```cpp
    // Step 3: Main function to convert BST to Max Heap
    void convertToMaxHeapUtil(Node* root) {
        vector<int> nodes;  // Create a vector to store the in-order traversal of the BST
        
        // Perform in-order traversal to collect nodes' values
        inOrder(root, nodes);
        
        int index = 0;  // Initialize index to 0 (start from the first element in the sorted vector)
        
        // Convert BST to Max Heap using postorder traversal and the sorted node values
        inOrderToHeap(root, nodes, index);
    }    
};
```

#### Explanation:

1. **Function Definition (`convertToMaxHeapUtil`)**:
   - This is the main function that converts the BST to a Max Heap.
   - It first collects the sorted values from the BST using the `inOrder` function and stores them in the `nodes` vector.
   - Then, it uses the `inOrderToHeap` function to assign these values back to the tree nodes in postorder fashion.

2. **In-order Traversal (`inOrder(root, nodes);`)**:
   - It calls the `inOrder` function to collect the sorted values of the BST.

3. **Index Initialization (`int index = 0;`)**:
   - We initialize the `index` to `0` to start assigning values from the smallest to the largest in the `nodes` vector.

4. **Convert to Max Heap (`inOrderToHeap(root, nodes, index);`)**:
   - Finally, the function calls `inOrderToHeap` to convert the BST into a Max Heap by assigning the values from the `nodes` vector to the tree nodes.

### Example Walkthrough

**Input BST:**
```
        4
       / \
      2   6
     / \ / \
    1  3 5  7
```

- **Step 1 (In-order Traversal):**
  The in-order traversal of the tree will give the sorted node values: `[1, 2, 3, 4, 5, 6, 7]`.

- **Step 2 (Postorder Traversal):**
  In postorder traversal, we assign the values from the `nodes` vector to the tree nodes in the following order:
  1. Start from the leftmost child, assign `7` to `1`.
  2. Then assign `6` to `2`.
  3. Continue until the root is assigned `7` and all other nodes get their correct values.

**Output Max Heap:**
```
        7
       / \
      3   6
     / \ / \
    1  2 4  5
```

**Postorder Traversal of Max Heap:** `1 2 3 4 5 6 7`.

### Step 4: Time and Space Complexity

- **Time Complexity**:
  - **In-order traversal (`inOrder`)**: The time complexity of traversing the entire tree is **O(n)**, where `n` is the number of nodes in the tree.
  - **Postorder traversal (`inOrderToHeap`)**: Similarly, replacing the node values using postorder traversal is also **O(n)**.
  - Thus, the overall time complexity is **O(n)**.

- **Space Complexity**:
  - We are using an additional vector (`nodes`) to store the node values. The space complexity for this vector is **O(n)**.
  - The recursion stack used for traversal also takes **O(h)** space, where `h` is the height of the tree. In the worst case (if the tree is skewed), `h` can be `O(n)`, so the total space complexity is **O(n)**.

### Step 5: Additional Recommendations

1. **Edge Cases**:
   - **Empty Tree**: Ensure to handle the case where the root is `NULL`. The code already handles this, but it's worth noting that an empty BST will result in an empty Max Heap.
   - **Single Node Tree**: If the tree has only one node, the tree remains unchanged, but it's important to test this case.

2. **Practice**:
   - Try testing this solution with different tree structures, including balanced trees and skewed trees, to ensure the solution works for all types of input.
   - Understanding tree traversal techniques (in-order, postorder) and how they relate to tree structure manipulation is crucial for solving similar problems in data structures.

3. **Time Complexity Considerations**:
   - The solution is **O(n)** in terms of both time and space, which is optimal for this problem, as every node in the tree needs to be processed at least once.

By understanding these key concepts and applying them, you can effectively approach similar problems involving tree transformations and heap conversions.
