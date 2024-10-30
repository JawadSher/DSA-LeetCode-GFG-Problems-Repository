<h1 align='center'>Lowest - Common - Ancestor - Of a - Binary - Tree</h1>

## Problem Statement

**Problem URL :** [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)

![image](https://github.com/user-attachments/assets/76533e07-6eee-49b5-8e61-bc00b0481ab6)
![image](https://github.com/user-attachments/assets/040cd0a6-73b0-40f6-9462-f92ffb2da5ae)

## Problem Explanation
**Problem:** Given a binary tree, find the lowest common ancestor (LCA) of two given nodes, `p` and `q`. The LCA of two nodes in a binary tree is the lowest node that has both `p` and `q` as descendants (either direct children or via other nodes).

**Constraints:**
- Each node in the tree has a unique value.
- Both nodes `p` and `q` exist in the tree.

**Real-World Analogy:** 
Imagine a family tree where each node represents a person. The lowest common ancestor of two family members is the closest common ancestor, such as a grandparent or great-grandparent. Similarly, in the binary tree, the LCA is the nearest common node that `p` and `q` descend from.

**Edge Cases to Consider:**
1. **Root node is `p` or `q`:** If `root` is one of the two nodes, then it is automatically the LCA.
2. **Nodes in separate subtrees:** `p` and `q` may be located in different subtrees of the root.
3. **Nodes are the same:** If `p` and `q` are the same node, that node is the LCA.

### Step 2: Approach

**High-Level Overview:**
To find the LCA, we can use a recursive depth-first search (DFS) strategy:
1. Traverse from the root to find `p` and `q`.
2. When both `p` and `q` are found in separate subtrees of the same node, that node is the LCA.
3. If `p` or `q` matches the root node, then root is their LCA.
  
**Detailed Steps:**
1. **Base Case:** If the current `root` is `NULL`, return `NULL` since there is no node here.
2. **Check for `p` or `q`:** If `root` is equal to `p` or `q`, return `root`.
3. **Recursive Search:** 
   - Recurse down the left and right subtrees to search for `p` and `q`.
   - If one node is found in each subtree, the current `root` is the LCA.
4. **Return Results:**
   - If both left and right return non-`NULL` values, then `root` is the LCA.
   - If only one subtree returns a node, propagate that node up as the potential LCA.

**Pseudocode:**
```plaintext
function LCA(root, p, q):
    if root is NULL:
        return NULL
    
    if root is p or root is q:
        return root
    
    left = LCA(root.left, p, q)
    right = LCA(root.right, p, q)
    
    if left is not NULL and right is not NULL:
        return root
    
    return left if left is not NULL else right
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

        if(root -> val == p -> val || root -> val == q -> val) return root;

        TreeNode* leftAns = lowestCommonAncestor(root -> left, p, q);
        TreeNode* rightAns = lowestCommonAncestor(root -> right, p, q);

        if(leftAns != NULL && rightAns != NULL) return root;
        else if(leftAns != NULL && rightAns == NULL) return leftAns;
        else if(leftAns == NULL && rightAns != NULL) return rightAns;
        else return NULL;
    }
};
```

## Problem Solution Explanation

Here’s the code with line-by-line explanation:

1. **Function Definition and Parameters**
   ```cpp
   TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
   ```
   - This function is a method of the `Solution` class.
   - It takes three parameters:
     - `root`: A pointer to the current node (starting with the root of the tree).
     - `p`: A pointer to one of the target nodes in the tree.
     - `q`: A pointer to the other target node.
   - The function will return a pointer to the node that is the lowest common ancestor of `p` and `q`.

2. **Line 1: Base Case**
   ```cpp
   if (root == NULL) return NULL;
   ```
   - **Purpose:** This line handles the base case. If `root` is `NULL` (i.e., we’ve reached a leaf node or an empty tree), it returns `NULL`.
   - **Reason:** If `root` is `NULL`, there’s no node here, so it can’t be the ancestor of `p` or `q`.

3. **Line 2: Check if `root` is a Target Node**
   ```cpp
   if (root->val == p->val || root->val == q->val) return root;
   ```
   - **Purpose:** Check if the current node (`root`) is equal to either `p` or `q`.
   - **Explanation:** 
     - If the current `root` node matches the value of `p` or `q`, this node is either `p` or `q`.
     - Since one of our target nodes has been found, we return `root` as a potential candidate for the LCA.
   - **Example:** If `root` is `p`, this means `p` could potentially be the lowest common ancestor if `q` is found further down the tree.

4. **Line 3: Recursive Search in the Left Subtree**
   ```cpp
   TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
   ```
   - **Purpose:** Recursively search for nodes `p` and `q` in the left subtree.
   - **Explanation:** 
     - This line makes a recursive call to `lowestCommonAncestor`, but with `root->left` as the new root node.
     - The result, `leftAns`, will be `NULL` if neither `p` nor `q` is found in the left subtree.
     - Otherwise, it will contain the pointer to `p`, `q`, or their common ancestor found in the left subtree.

5. **Line 4: Recursive Search in the Right Subtree**
   ```cpp
   TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
   ```
   - **Purpose:** Similar to the previous step, this line searches for nodes `p` and `q` in the right subtree.
   - **Explanation:**
     - A recursive call is made with `root->right` as the new root.
     - The result, `rightAns`, will store `NULL` if neither `p` nor `q` is found in the right subtree.
     - Otherwise, it contains the pointer to `p`, `q`, or their LCA within the right subtree.

6. **Line 5: Determine if Current `root` is the LCA**
   ```cpp
   if (leftAns != NULL && rightAns != NULL) return root;
   ```
   - **Purpose:** Check if nodes `p` and `q` were found in different subtrees of the current `root`.
   - **Explanation:**
     - If both `leftAns` and `rightAns` are non-`NULL`, then one target node was found in each subtree.
     - This means that the current node, `root`, is the lowest node that has both `p` and `q` as descendants.
     - Therefore, we return `root` as the lowest common ancestor.

7. **Line 6: Propagate the Left Result Upwards**
   ```cpp
   else if (leftAns != NULL && rightAns == NULL) return leftAns;
   ```
   - **Purpose:** If only `leftAns` is non-`NULL`, return `leftAns` as the LCA candidate.
   - **Explanation:**
     - If only `leftAns` is non-`NULL`, then either `p` or `q` (or their common ancestor) was found in the left subtree, while the right subtree has no relevant nodes.
     - We propagate `leftAns` upwards as a potential LCA since `p` and `q` could still be descendants of the node in `leftAns`.

8. **Line 7: Propagate the Right Result Upwards**
   ```cpp
   else if (leftAns == NULL && rightAns != NULL) return rightAns;
   ```
   - **Purpose:** Similarly, if only `rightAns` is non-`NULL`, return `rightAns`.
   - **Explanation:**
     - This means that either `p` or `q` (or their LCA) was found in the right subtree.
     - Since the left subtree has no relevant nodes, we return `rightAns` as the LCA candidate for the upper levels of recursion.

9. **Line 8: Neither `p` nor `q` Found**
   ```cpp
   else return NULL;
   ```
   - **Purpose:** If both `leftAns` and `rightAns` are `NULL`, return `NULL` as no LCA was found.
   - **Explanation:** 
     - This means that neither `p` nor `q` is present in the current subtree rooted at `root`.
     - Returning `NULL` signifies that `p` and `q` are not in this subtree.


### Step 4: Output Examples

1. **Example 1:**
   - **Input:** Binary tree root = [3,5,1,6,2,0,8,null,null,7,4], `p` = 5, `q` = 1
   - **Output:** 3
   - **Explanation:** Nodes 5 and 1 have the common ancestor 3, which is their LCA.

2. **Example 2:**
   - **Input:** Binary tree root = [3,5,1,6,2,0,8,null,null,7,4], `p` = 5, `q` = 4
   - **Output:** 5
   - **Explanation:** Since node 5 is an ancestor of node 4, 5 itself is the LCA.

3. **Example 3:**
   - **Input:** Binary tree root = [1,2], `p` = 1, `q` = 2
   - **Output:** 1
   - **Explanation:** Node 1 is the root and an ancestor of node 2, so it’s the LCA.

### Step 5: Time and Space Complexity

1. **Time Complexity:** \(O(N)\), where \(N\) is the number of nodes in the tree. In the worst case, each node is visited once to locate `p` and `q`.
  
2. **Space Complexity:** \(O(H)\), where \(H\) is the height of the tree. The recursive call stack could go as deep as the height of the tree in an unbalanced tree, making it \(O(H)\). For a balanced tree, the space complexity would be \(O(\log N)\), but for a skewed tree, it would be \(O(N)\).

**Optimizations:** This recursive solution is already optimal for this problem. For trees that are extremely skewed, an iterative solution using parent pointers could reduce stack usage, but it generally won’t improve the time complexity.
