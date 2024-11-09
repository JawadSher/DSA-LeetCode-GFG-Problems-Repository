<h1 align='center'>Maximum - Sum - BST in - Binary - Tree</h1>

## Problem Statement

**Problem URL :** [Maximum Sum BST in Binary Tree](https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/)

![image](https://github.com/user-attachments/assets/3c49a978-94bc-4619-bda7-adcf6464cf9d)
![image](https://github.com/user-attachments/assets/5291d096-19d8-4076-aceb-6d8b046b2cab)

## Problem Explanation
The problem is to find the **maximum sum** of a **binary search tree (BST)** in a given binary tree. The challenge is to find the largest BST (in terms of the sum of its values) within the binary tree, and return the sum of the values of the largest BST.

#### **Binary Tree and Binary Search Tree (BST):**
- **Binary Tree**: A tree in which each node has at most two children (left and right).
- **Binary Search Tree (BST)**: A binary tree where the value of each node must be greater than the values in its left subtree and smaller than the values in its right subtree.

#### **Goal:**
- You are given a binary tree, and you need to identify all the BSTs in it.
- For each BST found, you will calculate the sum of its node values.
- Return the sum of the largest BST in the binary tree.

### **Approach to Solve the Problem:**
We can approach this problem using **post-order traversal** (visiting left subtree, right subtree, and then the root node), combined with information tracking for each subtree to determine if it is a valid BST and calculate the sum. Here’s how:

1. **Start with the root node**: The root of the tree can be the root of a BST, or it can be part of a larger BST. Our goal is to check every node and determine if it is the root of a valid BST.
2. **Use recursive DFS**: We need to explore the left and right subtrees first, and then combine their results to determine whether the current node and its subtrees form a valid BST.
3. **Track information**:
   - `mini`: The minimum value in the subtree.
   - `maxi`: The maximum value in the subtree.
   - `isBST`: Whether the current subtree is a valid BST.
   - `size`: The number of nodes in the subtree.
   - `sum`: The sum of the values in the subtree.
4. **Conditions to form a valid BST**:
   - The left subtree is a valid BST and its maximum value is less than the root's value.
   - The right subtree is a valid BST and its minimum value is greater than the root's value.
   - The root’s value must lie between the maximum value of the left subtree and the minimum value of the right subtree.
5. **Calculate the maximum sum**: Each time a valid BST is found, we check its sum and update the maximum sum if necessary.

#### **Example:**
Consider the binary tree:

```
       1
      / \
     4   3
    / \   \
   2   4   5
              \
               6
```

- Subtrees that are valid BSTs:
  - The subtree rooted at `4` with nodes `{4, 2, 4}` is a valid BST.
  - The subtree rooted at `3` with nodes `{3, 5, 6}` is a valid BST.

- The largest BST is the subtree rooted at `3`, with nodes `{3, 5, 6}` and sum = `3 + 5 + 6 = 14`.

So, the expected output is `14`.

## Problem Solution
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class nodeInfo{
    public:
        int mini;
        int maxi;
        bool isBST;
        int size;
        int sum;
};
class Solution {
public:
    nodeInfo getLargestBSTSize(TreeNode* root, int &ans){
        if(root == NULL) return nodeInfo{INT_MAX, INT_MIN, true, 0, 0};

        nodeInfo left = getLargestBSTSize(root -> left, ans);
        nodeInfo right = getLargestBSTSize(root -> right, ans);

        nodeInfo currentNode;
        currentNode.size = left.size + right.size + 1;
        currentNode.sum = left.sum + right.sum + root -> val;
        currentNode.mini = min(root -> val, left.mini);
        currentNode.maxi = max(root -> val, right.maxi);

        if(left.isBST && right.isBST && (root -> val > left.maxi && root -> val < right.mini)){
            currentNode.isBST = true;
            ans = max(ans, currentNode.sum);
        }else{
            currentNode.isBST = false;
        }
        
        return currentNode;
    }

    int maxSumBST(TreeNode* root) {
        int max_sum = 0;
        getLargestBSTSize(root, max_sum);
        return max_sum;
    }
};
```

## Problem Solution Explanation

Now, let’s go through the code line by line to understand how it works.

```cpp
class nodeInfo {
public:
    int mini;  // Minimum value in the subtree
    int maxi;  // Maximum value in the subtree
    bool isBST;  // Whether the subtree is a valid BST
    int size;  // Number of nodes in the subtree
    int sum;  // Sum of values in the subtree
};
```
- **`nodeInfo` Class**: This class is used to store the details of each subtree. It stores:
  - `mini`: Minimum value in the subtree.
  - `maxi`: Maximum value in the subtree.
  - `isBST`: Whether the subtree is a valid BST.
  - `size`: Number of nodes in the subtree.
  - `sum`: Sum of values in the subtree.

```cpp
class Solution {
public:
    nodeInfo getLargestBSTSize(TreeNode* root, int &ans) {
        if (root == NULL) return nodeInfo{INT_MAX, INT_MIN, true, 0, 0};
```
- **`getLargestBSTSize` Function**: This function computes the largest BST in the subtree rooted at `root`.
  - If `root == NULL`, it returns an empty subtree with:
    - `mini = INT_MAX` (to ensure any node will be greater).
    - `maxi = INT_MIN` (to ensure any node will be smaller).
    - `isBST = true` because `NULL` is a valid BST.
    - `size = 0` (no nodes).
    - `sum = 0`.

```cpp
        nodeInfo left = getLargestBSTSize(root->left, ans);
        nodeInfo right = getLargestBSTSize(root->right, ans);
```
- The function recursively gets the `nodeInfo` for the left and right subtrees.

```cpp
        nodeInfo currentNode;
        currentNode.size = left.size + right.size + 1;
        currentNode.sum = left.sum + right.sum + root->val;
        currentNode.mini = min(root->val, left.mini);
        currentNode.maxi = max(root->val, right.maxi);
```
- **`currentNode` Information**: This stores the information of the current subtree rooted at `root`.
  - `size`: Total size of the subtree, which is the size of the left subtree, right subtree, and the current node.
  - `sum`: Sum of all node values in the subtree.
  - `mini`: The minimum value in the current subtree (minimum of `root->val` and the left subtree).
  - `maxi`: The maximum value in the current subtree (maximum of `root->val` and the right subtree).

```cpp
        if (left.isBST && right.isBST && (root->val > left.maxi && root->val < right.mini)) {
            currentNode.isBST = true;
            ans = max(ans, currentNode.sum);
        } else {
            currentNode.isBST = false;
        }
```
- **Validating the BST**:
  - If both left and right subtrees are valid BSTs and the current node’s value is greater than the maximum value in the left subtree and smaller than the minimum value in the right subtree, then the current subtree is a valid BST.
  - If it is a valid BST, we update the `ans` variable with the sum of the current BST if it is larger than the previously found BST.

```cpp
        return currentNode;
    }
```
- The function returns the information of the current subtree, which will be used by the parent node in the recursive call.

```cpp
    int maxSumBST(TreeNode* root) {
        int max_sum = 0;
        getLargestBSTSize(root, max_sum);
        return max_sum;
    }
};
```
- **`maxSumBST` Function**: This is the main function. It initializes `max_sum` to 0 and calls the helper function `getLargestBSTSize` to find the largest BST and update the `max_sum`. Finally, it returns the value of `max_sum`.

### Step 3: Examples and Explanation

Let’s go over the examples:

#### Example 1:
**Input**:  
```
       1
      / \
     4   3
    / \   \
   2   4   5
              \
               6
```
- The largest BST is the subtree rooted at `3` with nodes `{3, 5, 6}`.
- Sum = `3 + 5 + 6 = 14`.

**Output**:  
`14`

#### Example 2:
**Input**:  
```
       10
      /  \
     5   15
    / \    \
   1   8    7
```
- The largest BST is the subtree rooted at `5` with nodes `{5, 1, 8}`.
- Sum = `5 + 1 + 8 = 14`.

**Output**:  
`14`

### Step 4: Time and Space Complexity

- **Time Complexity**: O(N), where N is the number of nodes in the binary tree. This is because we visit each node once during the post-order traversal.
- **Space Complexity**: O(H), where H is the height of the tree. This is due to the recursive stack used during the traversal, which can go as deep as the height of the tree. In the worst case (a skewed tree), this can be O(N).

### Step 5: Recommendations for Students

1. **Understand the BST properties**: Make sure you are comfortable with the properties of a binary search tree. This problem is fundamentally about verifying if a subtree is a BST and calculating its sum.
2. **Recursive thinking**: This problem involves recursion, so practice breaking down problems into smaller subproblems (subtrees in this case).
3. **Practice with variations**: Once you're comfortable with this problem, try solving variations, such as finding the largest BST with a given number of nodes or modifying the approach to handle different tree structures.
4. **Edge Cases**: Don’t forget to consider edge cases, such as:
   - An empty tree (null root).
   - Trees where no valid BSTs exist (answer should be 0).
   - Trees with only one node (

valid BST).

