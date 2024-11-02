<h1 align='center'>Morris - Traversal - for - Binary Trees - In-order Traversal</h1>

Morris Traversal is a method for traversing binary trees without using extra space, like recursion stacks or auxiliary stacks, by temporarily modifying the tree's structure. It allows for an **in-order traversal** (left-root-right) with **O(1) space complexity**. Let's break down Morris Traversal in detail and examine each part of the approach, the code, and its efficiency.

### 1. Detailed Explanation of Morris Traversal

The Morris Traversal algorithm leverages a key insight: we can create temporary links in the tree to remember the path back up. Specifically, for any node, we connect its **in-order predecessor** (the rightmost node in its left subtree) back to the node itself. This link lets us return to the node without needing a stack.

Here are the essential steps of Morris Traversal:

1. **Start at the Root**: Begin traversal from the root node and use a pointer `current` to navigate the tree.

2. **Process Each Node**:
   - While `current` is not null:
     - **If the Left Child is Null**:
       - If `current` has no left child, there is no left subtree to explore, so we simply process `current` (print it or add it to our result list) and move to the right child.
       
     - **If the Left Child is Not Null**:
       - If `current` has a left child, find its in-order predecessor in the left subtree:
         - The **in-order predecessor** is the rightmost node in the left subtree, meaning the node with the largest value in the left subtree of `current`.
       - **Create or Remove Link**:
         - **If the predecessor’s right pointer is null**, create a temporary link from the predecessor back to `current`. This link allows us to return to `current` after finishing the left subtree. Then, move `current` to its left child to continue traversing the left subtree.
         - **If the predecessor’s right pointer is already pointing to `current`**, it means we have finished processing the left subtree. In this case, remove the link by setting the predecessor's right pointer to null, process `current`, and move to the right child.

3. **End of Traversal**: Repeat the process until `current` becomes null, indicating that the entire tree has been visited.

### 2. Approach of Morris Traversal

1. **Initialization**:
   - Start with a pointer `current` at the root of the tree.

2. **Handling Left Subtrees**:
   - If the node has a left child, find the node’s in-order predecessor and set up a temporary link back to the node.

3. **Traversal and Link Removal**:
   - Once the left subtree is fully traversed, remove the temporary link and proceed to the right subtree.

4. **Completion**:
   - Continue this until every node is visited exactly once, resulting in an in-order traversal.

### 3. Code for Morris In-Order Traversal in C++

Here’s how Morris Traversal is implemented for in-order traversal in C++:

```cpp
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void morrisInorderTraversal(TreeNode* root) {
    TreeNode* current = root;
    
    while (current != nullptr) {
        if (current->left == nullptr) {
            // If no left child, visit current and move to the right
            cout << current->val << " ";
            current = current->right;
        } else {
            // Find the in-order predecessor of current
            TreeNode* predecessor = current->left;
            while (predecessor->right != nullptr && predecessor->right != current) {
                predecessor = predecessor->right;
            }
            
            if (predecessor->right == nullptr) {
                // Establish temporary link from predecessor's right to current
                predecessor->right = current;
                current = current->left;
            } else {
                // Remove temporary link and visit current
                predecessor->right = nullptr;
                cout << current->val << " ";
                current = current->right;
            }
        }
    }
}

int main() {
    // Example tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Morris In-order Traversal: ";
    morrisInorderTraversal(root);  // Expected Output: 4 2 5 1 3
    return 0;
}
```


### 4. Explanation of Code

- **TreeNode Structure**:
  - Defines a binary tree node with an integer value (`val`) and pointers to the left and right children.
  
- **morrisInorderTraversal Function**:
  - **Loop through the Tree**: Starts at the root and continues until all nodes are visited.
  - **Check Left Child**:
    - If `current->left` is null, print `current->val` (since there’s no left subtree) and move to `current->right`.
    - If `current->left` exists, find `current`’s predecessor (rightmost node in `current->left` subtree).
  - **Create/Remove Links**:
    - If `predecessor->right` is null, establish a link to `current` and move `current` to the left child.
    - If `predecessor->right` is `current` (link exists), remove it (set `predecessor->right` to null), print `current->val`, and move `current` to the right child.
  
- **Output**:
  - This code traverses the tree in in-order (left-root-right) and prints the values of each node.


### 5. Time and Space Complexity Analysis

- **Time Complexity**:
  - The time complexity is **O(n)**, where \( n \) is the number of nodes in the tree. Although each node is visited multiple times while finding predecessors and establishing/removing links, each link is created and removed exactly once. This makes the overall time complexity linear, as each operation is limited to a constant number of steps.

- **Space Complexity**:
  - The Morris Traversal algorithm has **O(1) space complexity** because it doesn’t use any additional data structures. Instead, it modifies the tree temporarily by creating links to the predecessor nodes, which are later removed, ensuring no additional space is used apart from the few pointers required by the function itself.
