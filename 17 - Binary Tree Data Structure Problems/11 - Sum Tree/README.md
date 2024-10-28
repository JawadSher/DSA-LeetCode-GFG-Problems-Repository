<h1 align='center'>Sum - Tree</h1>

## Problem Statement

**Problem URL :** [Sum Tree](https://www.geeksforgeeks.org/problems/sum-tree/1)

![image](https://github.com/user-attachments/assets/f7b5db2f-4414-47fc-bfd8-dbd8b721ec17)
![image](https://github.com/user-attachments/assets/e6f215ea-3b7f-431b-859a-ad3ddb48ec24)

## Problem Explanation
The problem requires us to determine whether a given binary tree is a **Sum Tree**. A binary tree is defined as a Sum Tree if, for every node in the tree, the value of the node is equal to the sum of the values of its left and right children. Additionally, leaf nodes are also considered Sum Trees as their children are `NULL` (which sum to zero).

#### Examples:

1. **Example 1**:
   - **Input Tree**:
   ```
        26
       /  \
      10   3
     / \    \
    4   6    3
   ```
   - **Output**: `true` (Each node's value is the sum of its children's values)

2. **Example 2**:
   - **Input Tree**:
   ```
        10
       /  \
      5    5
   ```
   - **Output**: `false` (The root's value is not equal to the sum of its children)

3. **Example 3**:
   - **Input Tree**:
   ```
        5
       / \
      3   2
   ```
   - **Output**: `false` (The root's value is not equal to the sum of its children)

### Step 2: Approach to Solve the Problem

To determine if a binary tree is a Sum Tree, we can use a recursive approach:

1. **Base Cases**:
   - If the current node is `NULL`, it contributes `0` to the sum.
   - If the node is a leaf (both children are `NULL`), it is a Sum Tree, and its value is returned as it is.

2. **Recursive Calculation**:
   - Recursively calculate the sum for the left and right subtrees.
   - Check if the current node's value equals the sum of the left and right children's values.

3. **Return Value**:
   - Return a pair containing a boolean indicating if the subtree is a Sum Tree and the total sum of the subtree rooted at the current node.
   - 
## Problem Solution
```cpp
class Solution {
  private:
    pair<int, int> fastSumTree(Node* root){
        if(root == NULL) return {true, 0};
        if(root -> left == NULL && root -> right == NULL) return {true, root->data};
        
        
        pair<bool, int> leftAns = fastSumTree(root -> left);
        pair<bool, int> rightAns = fastSumTree(root -> right);
        
        bool left = leftAns.first;
        bool right = rightAns.first;
        
        bool condition = root -> data == leftAns.second + rightAns.second;
        
        pair<int, int> ans;
        if(left && right && condition){
            ans.first = true;
            ans.second = 2 * root -> data;
        }else{
            ans.first = false;
        }
        
        
        return ans;
    }
  public:
    bool isSumTree(Node* root) {
        return fastSumTree(root).first;
    }
};
```

## Problem Solution Explanation

Here’s the code with detailed explanations:

```cpp
class Solution {
  private:
    pair<int, int> fastSumTree(Node* root) {
```
- **Explanation**: This begins the definition of the `fastSumTree` function, which takes a `Node*` as input and returns a pair containing a boolean and an integer.

```cpp
        if(root == NULL) return {true, 0};
```
- **Explanation**: If the current node is `NULL`, it is considered a Sum Tree with a sum of `0`. Return a pair `{true, 0}`.

```cpp
        if(root -> left == NULL && root -> right == NULL) return {true, root->data};
```
- **Explanation**: If the current node is a leaf node (both children are `NULL`), it is a Sum Tree, and its value is returned. Return `{true, root->data}`.

```cpp
        pair<bool, int> leftAns = fastSumTree(root -> left);
        pair<bool, int> rightAns = fastSumTree(root -> right);
```
- **Explanation**: Recursively call `fastSumTree` on the left and right children, storing the results in `leftAns` and `rightAns`.

```cpp
        bool left = leftAns.first;
        bool right = rightAns.first;
```
- **Explanation**: Extract the boolean values from `leftAns` and `rightAns`, which indicate whether the left and right subtrees are Sum Trees.

```cpp
        bool condition = root -> data == leftAns.second + rightAns.second;
```
- **Explanation**: Check if the current node's value is equal to the sum of the values of its left and right children (i.e., `leftAns.second` and `rightAns.second`).

```cpp
        pair<int, int> ans;
```
- **Explanation**: Declare a pair `ans` to store the result for the current node.

```cpp
        if(left && right && condition) {
            ans.first = true;
            ans.second = 2 * root -> data;
        } else {
            ans.first = false;
        }
```
- **Explanation**: 
   - If both subtrees are Sum Trees and the condition holds, set `ans.first` to `true`, indicating the current subtree is a Sum Tree, and calculate the sum to return as `2 * root->data` (since the node's value is counted as twice in the sum tree condition).
   - Otherwise, set `ans.first` to `false`.

```cpp
        return ans;
    }
```
- **Explanation**: Return the result for the current node, which contains whether it is a Sum Tree and the sum of the values.

```cpp
  public:
    bool isSumTree(Node* root) {
        return fastSumTree(root).first;
    }
};
```
- **Explanation**: The `isSumTree` function is a public method that initiates the check for the whole tree by calling `fastSumTree` and returning the boolean value indicating whether the tree is a Sum Tree.

### Step-by-Step Example Walkthrough

Consider the following tree:

- **Input Tree**:
```
    26
   /  \
  10   3
 / \    \
4   6    3
```

1. **Start at Root (Node 26)**:
   - Call `fastSumTree(26)`.

2. **Left Subtree (Node 10)**:
   - Call `fastSumTree(10)`.
   - Further, call `fastSumTree(4)` (left child).
     - Returns `{true, 4}` (leaf node).
   - Call `fastSumTree(6)` (right child).
     - Returns `{true, 6}` (leaf node).
   - Now check if `10 == 4 + 6` (true).
   - Return `{true, 20}` for Node 10.

3. **Right Subtree (Node 3)**:
   - Call `fastSumTree(3)`.
   - Call `fastSumTree(NULL)` (left child).
     - Returns `{true, 0}` (NULL).
   - Call `fastSumTree(3)` (right child).
     - Returns `{true, 3}` (leaf node).
   - Now check if `3 == 0 + 3` (true).
   - Return `{true, 6}` for Node 3.

4. **Final Check at Root**:
   - Now check if `26 == 20 + 6` (true).
   - Return `{true, 52}` for Node 26.

The output is `true`, confirming that the tree is a Sum Tree.

### Step 4: Time and Space Complexity

1. **Time Complexity**: **O(N)**, where `N` is the number of nodes in the binary tree.
   - Each node is visited exactly once to check if the tree is a Sum Tree.

2. **Space Complexity**: **O(H)**, where `H` is the height of the tree.
   - The space complexity is primarily due to the recursive call stack. In the worst case (skewed tree), it could be `O(N)`, while for balanced trees, it would be `O(log N)`.

Overall, this approach efficiently determines whether a binary tree is a Sum Tree using recursion.
