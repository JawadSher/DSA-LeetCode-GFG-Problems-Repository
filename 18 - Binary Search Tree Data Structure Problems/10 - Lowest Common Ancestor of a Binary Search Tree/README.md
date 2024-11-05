<h1 align='center'>Lowest - Common - Ancestor - Of a - Binary - Search - Tree</h1>

## Problem Statement

**Problem URL :** [Lowest Common Ancestor Of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)

![image](https://github.com/user-attachments/assets/3a7046fd-0d26-4289-9e70-3194b0e19217)
![image](https://github.com/user-attachments/assets/39ecd959-89dc-4aae-8456-e5cb5cc14f0f)

## Problem Explanation
Given a binary search tree (BST) and two nodes `p` and `q`, the task is to find their lowest common ancestor (LCA). The LCA is the lowest node in the tree that has both `p` and `q` as descendants. The definition also implies that both `p` and `q` will be present in the tree.

- **Constraints:**
  - Each node has a unique integer value.
  - The tree does not contain duplicate values.
  - Both `p` and `q` will exist in the tree.

**Expected Output Format:**
The output should be the node that represents the LCA of `p` and `q`.

**Real-World Analogy:**
Think of the BST as an organizational chart. The LCA can be seen as the first common manager above two employees in this hierarchy.

**Edge Cases:**
1. If either `p` or `q` is the root of the tree, then the root is the LCA.
2. If `p` and `q` are the same node, the LCA is that node itself.

#### Step 2: Approach

**High-Level Overview:**
The approach leverages the properties of a binary search tree, where the left subtree contains values less than the root, and the right subtree contains values greater than the root. This allows us to traverse the tree efficiently to find the LCA.

**Step-by-Step Breakdown:**
1. Start at the root of the tree.
2. Compare the values of the root, `p`, and `q`.
3. If both values are greater than the root's value, move to the right child (since both nodes must be in the right subtree).
4. If both values are less than the root's value, move to the left child (since both nodes must be in the left subtree).
5. If one value is on the left and the other on the right (or one is equal to the root), then the root is the LCA.

**Visual Aids:**
A diagram could represent a BST, highlighting the path taken based on comparisons with `p` and `q`.

**Pseudocode:**
```plaintext
function lowestCommonAncestor(root, p, q):
    if root is NULL:
        return NULL

    if root.val < p.val and root.val < q.val:
        return lowestCommonAncestor(root.right, p, q)
    
    if root.val > p.val and root.val > q.val:
        return lowestCommonAncestor(root.left, p, q)
    
    return root
```

## Problem Solution
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;

        if(root -> val < p -> val && root -> val < q -> val) {
            return lowestCommonAncestor(root -> right, p, q);
        }

        if(root -> val > p -> val && root -> val > q -> val){
            return lowestCommonAncestor(root -> left, p, q);
        }

        return root;
    }
};
```

## Problem Solution Explanation
```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL; // If the root is NULL, return NULL

        // If both p and q are greater than root, then LCA lies in the right subtree
        if(root -> val < p -> val && root -> val < q -> val) {
            return lowestCommonAncestor(root -> right, p, q);
        }

        // If both p and q are less than root, then LCA lies in the left subtree
        if(root -> val > p -> val && root -> val > q -> val){
            return lowestCommonAncestor(root -> left, p, q);
        }

        // We have found the split point, i.e., either p or q is on one side and the other is on the other side
        return root; // This root is the LCA of p and q
    }
};
```

**Detailed Code Walkthrough:**
- **Line 1-2:** Defines the `Solution` class and its member function `lowestCommonAncestor`, which takes the root of the BST and two nodes, `p` and `q`.
- **Line 3:** Checks if the `root` is `NULL`. If it is, it means we've reached the end of a path without finding the LCA, so return `NULL`.
- **Line 5:** If both `p` and `q` have values greater than `root->val`, it means both nodes are located in the right subtree. So we make a recursive call on the right child.
- **Line 8:** Similarly, if both nodes have values less than `root->val`, they are in the left subtree, and we make a recursive call on the left child.
- **Line 11:** If neither of the above conditions holds true, it indicates that we've found the point of divergence, meaning `root` is the LCA of `p` and `q`, and we return it.

#### Step 4: Output Examples

**Example 1:**
- **Input:**
  ```
        6
       / \
      2   8
     / \ / \
    0  4 7  9
      / \
     3   5
  ```
  Let `p = 2` and `q = 8`.
- **Output:** `6`
- **Explanation:** The root node `6` is the LCA since `2` is in the left subtree and `8` is in the right subtree.

**Example 2:**
- **Input:**
  ```
        6
       / \
      2   8
     / \ / \
    0  4 7  9
      / \
     3   5
  ```
  Let `p = 2` and `q = 4`.
- **Output:** `2`
- **Explanation:** The node `2` is the LCA since `4` is in its right subtree.

**Example 3:**
- **Input:**
  ```
        6
       / \
      2   8
     / \ / \
    0  4 7  9
      / \
     3   5
  ```
  Let `p = 3` and `q = 5`.
- **Output:** `4`
- **Explanation:** The node `4` is the LCA since `3` is in its left subtree and `5` is in its right subtree.

#### Step 5: Time and Space Complexity

**Time Complexity:** 
- The time complexity of the solution is **O(h)**, where **h** is the height of the tree. In the worst case (for a skewed tree), this could be **O(n)**, where **n** is the number of nodes.

**Space Complexity:** 
- The space complexity is also **O(h)** due to the recursion stack. In the worst case, this can also be **O(n)** for a skewed tree, but for a balanced tree, it will be **O(log n)**.

**Optimization Opportunities:**
- Since the algorithm is already efficient with a time complexity of O(h), there's limited scope for further optimization. However, if you need to optimize for space, you could consider an iterative approach that avoids recursion, although this would typically involve using a stack or queue to maintain state.

### Additional Considerations
- **Target Audience:** Ensure explanations are accessible to beginners by avoiding overly technical jargon and providing clear examples.
- **Interactive Learning:** Recommend platforms like LeetCode or HackerRank where users can practice similar problems interactively.
- **Error Handling:** While not specifically applicable in this context, always consider edge cases and validate inputs when implementing similar solutions.
- **Best Practices:** Use meaningful variable names, comment code effectively, and structure code to enhance readability and maintainability.
