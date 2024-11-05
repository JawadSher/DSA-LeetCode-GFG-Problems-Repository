<h1 align='center'>Lowest - Common - Ancestor - In a - BST</h1>

## Problem Statement

**Problem URL :** [Lowest Common Ancestor in a BST](https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/d410a875-6e59-4cbe-ab1b-3ae0f56713ec)
![image](https://github.com/user-attachments/assets/81d32e3f-3776-4d13-87ff-e6912949bad2)

## Problem Explanation
The **Lowest Common Ancestor (LCA)** in a Binary Search Tree (BST) is defined as the deepest node that is an ancestor to both of the given nodes. In simpler terms, it is the lowest node in the tree that is a parent to both nodes.

#### Understanding the BST
A Binary Search Tree is a special kind of binary tree where:
- The left subtree of a node contains only nodes with values less than the node's value.
- The right subtree of a node contains only nodes with values greater than the node's value.
- The left and right subtree must also be binary search trees.

#### Example:
Consider the following BST:

```
        20
       /  \
      10   30
     / \   / \
    5  15 25 35
```

**Example 1:**
- If we want to find the LCA of nodes `5` and `15`:
  - Start at `20`, both `5` and `15` are in the left subtree, so move to `10`.
  - At `10`, `5` is in the left subtree and `15` is in the right subtree, making `10` the LCA.

**Example 2:**
- If we want to find the LCA of nodes `5` and `30`:
  - Start at `20`, move to the left (5 is in the left subtree) and to the right (30 is in the right subtree).
  - Since `20` is the first node where the paths to `5` and `30` diverge, `20` is the LCA.

#### Why is Finding the LCA Important?
Finding the LCA is crucial in various applications, such as:
- Understanding hierarchical relationships in trees (family trees, organizational structures).
- Efficiently querying relationships between nodes in a tree structure.

## Problem Solution
```cpp
class Solution{
    public:
        Node* LCA(Node *root, int n1, int n2)
        {
            if(root == NULL) return NULL;
            
            while(root != NULL){
                if(root -> data < n1 && root -> data < n2){
                    root = root -> right;
                }
                
                else if(root -> data > n1 && root -> data > n2){
                    root = root -> left;
                }
                
                else return root;
            }
            

        }

};
```

## Problem Solution Explanation
Let's refine the code explanation to make it clearer and more structured, focusing on a simple and straightforward breakdown of each part of the code. 

1. **Class Declaration:**
   ```cpp
   class Solution {
   ```
   - This defines a class named `Solution`, which will contain our function to find the LCA.

2. **Function Declaration:**
   ```cpp
   public:
       Node* LCA(Node *root, int n1, int n2) {
   ```
   - This is the declaration of the `LCA` function. It takes three parameters:
     - `Node *root`: The root of the BST.
     - `int n1`: The value of the first node.
     - `int n2`: The value of the second node.
   - It returns a pointer to the `Node` that is the LCA of `n1` and `n2`.

3. **Check for Empty Tree:**
   ```cpp
   if (root == NULL) return NULL; // Check if the tree is empty
   ```
   - If the `root` is `NULL`, it means the tree is empty, so we return `NULL`.

4. **Traverse the Tree:**
   ```cpp
   while (root != NULL) { // Traverse the tree
   ```
   - We enter a `while` loop that continues until `root` becomes `NULL`.

5. **Both Nodes on the Right:**
   ```cpp
   if (root->data < n1 && root->data < n2) { // Both nodes are on the right
       root = root->right; // Move to the right child
   ```
   - If both `n1` and `n2` are greater than the current `root` value, it means both nodes are located in the right subtree. Therefore, we move `root` to its right child.

6. **Both Nodes on the Left:**
   ```cpp
   else if (root->data > n1 && root->data > n2) { // Both nodes are on the left
       root = root->left; // Move to the left child
   ```
   - If both `n1` and `n2` are less than the current `root` value, both nodes are in the left subtree. We move `root` to its left child.

7. **Found the LCA:**
   ```cpp
   else { // We found the split point
       return root; // This is the LCA
   }
   ```
   - If neither of the above conditions is true, it means we have found the split point where one node is on one side and the other node is on the opposite side. Hence, `root` is the LCA, and we return it.

8. **Return NULL (Not Needed):**
   ```cpp
   return NULL; // In case no LCA is found, though it shouldn't reach here
   ```
   - This line is technically unreachable in the context of a valid BST containing both nodes. It's a safety net but won't be executed.
     
### Step 3: Examples and Their Explanation

**Example 1:**
- **Input:** `n1 = 5`, `n2 = 15`
- **Output:** `10`
- **Explanation:** The algorithm starts at `20`, moves to `10`, finds that `5` is in the left subtree and `15` in the right, so it returns `10`.

**Example 2:**
- **Input:** `n1 = 5`, `n2 = 30`
- **Output:** `20`
- **Explanation:** The algorithm starts at `20`, since `5` is on the left and `30` is on the right, it returns `20`.

**Example 3:**
- **Input:** `n1 = 25`, `n2 = 35`
- **Output:** `30`
- **Explanation:** The algorithm starts at `20`, moves to `30`, and finds that both `25` and `35` are on either side, returning `30` as the LCA.

### Step 4: Time and Space Complexity

**Time Complexity:**
- The time complexity of this approach is **O(h)**, where **h** is the height of the BST. In the worst case (for a skewed tree), this could be **O(n)**, where **n** is the number of nodes in the tree.

**Space Complexity:**
- The space complexity is **O(1)** because we are using a constant amount of space for variables. We are not using any additional data structures like arrays or lists.

**How Complexity is Calculated:**
- **Time Complexity Calculation:**
  - The algorithm traverses down the height of the tree to find the LCA, which directly correlates to the height of the tree.
- **Space Complexity Calculation:**
  - Since there are no recursive calls (it’s an iterative solution) and we are only using a few variables to hold references, the space is constant.

### Step 5: Additional Recommendations

- **Practice:** Encourage students to practice implementing the LCA function on their own with different BSTs to reinforce their understanding.
- **Explore Variants:** Suggest looking into problems that require finding LCA in different types of trees, such as general trees or binary trees without the BST property.
- **Resources:** Recommend using platforms like [GeeksforGeeks](https://www.geeksforgeeks.org/) and [LeetCode](https://leetcode.com/) for more practice problems related to trees.
- **Understanding Edge Cases:** Remind students to consider edge cases, such as when `n1` or `n2` are equal, when both are the same node, or when one of them is the root.
- **Visualize:** Encourage students to draw the BST and trace the algorithm's steps visually to better understand the traversal path.

By following this structured approach, students will not only learn how to find the LCA in a BST but also gain insights into problem-solving strategies that can be applied to other tree-related problems.
