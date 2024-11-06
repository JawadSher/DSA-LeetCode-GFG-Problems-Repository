<h1 align='center'>Two - Sum IV - Input is - BST</h1>

## Problem Statement

**Problem URL :** [Two Sum IV - Input is BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)

![image](https://github.com/user-attachments/assets/67f32811-46be-49b9-af41-2a42cbdcd045)
![image](https://github.com/user-attachments/assets/43893d24-b382-454f-b88e-d7da3ee3b663)

## Problem Explanation
**Problem:**  
The problem "Two Sum IV - Input is a BST" asks us to determine if there are two nodes in a given Binary Search Tree (BST) whose values add up to a specific target integer \( k \). 

**Example:**
Let's say we have the following BST:
```
       5
      / \
     3   6
    / \   \
   2   4   7
```
If \( k = 9 \), there are two nodes, 2 and 7, which sum to 9. Therefore, the function should return `true`. However, if \( k = 28 \), no such pair of nodes exists, so it should return `false`.

**Understanding the Problem:**
- We are given a BST and an integer \( k \).
- Our task is to check if there are two values in the tree that add up to \( k \).
- Since it's a BST, an in-order traversal will give us the values in sorted order, which we can then use with a two-pointer technique to find the pair.

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
class Solution {
public:
    void inOrder(TreeNode* root, vector<int> &inOrderVal){
        if(root == NULL) return;

        inOrder(root -> left, inOrderVal);
        inOrderVal.push_back(root -> val);
        inOrder(root -> right, inOrderVal);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inOrderVal;   
        
        inOrder(root, inOrderVal);

        int i = 0;
        int j = inOrderVal.size() -1;

        while(i < j){
            int sum = inOrderVal[i] + inOrderVal[j];

            if(sum == k) return true;
            else if(sum > k) j--;
            else i++;
        } 

        return false;
    }
};
```

## Problem Solution Explanation

Let's go through the code step-by-step.

```cpp
class Solution {
public:
```
- This defines a `Solution` class with public member functions.
- The public keyword means all functions and variables following it are accessible from outside the class.

### In-Order Traversal Helper Function

```cpp
    void inOrder(TreeNode* root, vector<int> &inOrderVal) {
```
- `inOrder` is a helper function that takes two arguments:
  - A pointer `root` to the current node in the BST.
  - A reference to `vector<int> inOrderVal`, which will store the values of the nodes in sorted order.
  
- This function will be used to traverse the BST in in-order (left, root, right), resulting in a sorted list of node values in the `inOrderVal` vector.

```cpp
        if(root == NULL) return;
```
- **Explanation:** If the `root` is `NULL`, it means we’ve reached a leaf node or the tree is empty, so we simply return without doing anything.
  
- **Example:** For a BST like this:
  ```
      5
     / \
    3   6
  ```
  When `inOrder` is called with `root = NULL`, it will just return.

```cpp
        inOrder(root -> left, inOrderVal);
```
- **Explanation:** This line makes a recursive call to traverse the left subtree of the current node.
- **Example:** In the example BST:
  ```
      5
     / \
    3   6
  ```
  When `inOrder` is first called with `root` pointing to 5, it will call itself with `root->left` (node 3).

```cpp
        inOrderVal.push_back(root -> val);
```
- **Explanation:** This line adds the value of the current node to the `inOrderVal` vector. Since we’re doing an in-order traversal, this line will be reached after the left subtree has been traversed.
- **Example:** In our example:
  - When the traversal reaches node 3, `inOrderVal.push_back(3)` adds 3 to the vector.
  - Similarly, when node 5 is reached, 5 is added, and so on.

```cpp
        inOrder(root -> right, inOrderVal);
```
- **Explanation:** This line makes a recursive call to traverse the right subtree of the current node.
- **Example:** Continuing with the example:
  - After node 5 is added, the function will recursively traverse the right subtree (node 6).
  
- **Final Result of Traversal:** For a BST with nodes 5, 3, and 6, the vector `inOrderVal` will end up as `[3, 5, 6]`.

### Main Function to Find the Target Sum

```cpp
    bool findTarget(TreeNode* root, int k) {
```
- **Explanation:** This is the main function that will return `true` if there are two distinct values in the BST that add up to `k`, and `false` otherwise.
- **Parameters:**
  - `TreeNode* root` is the root node of the BST.
  - `int k` is the target sum we’re looking for.

```cpp
        vector<int> inOrderVal;
```
- **Explanation:** This initializes an empty vector `inOrderVal` to store the sorted values of the BST nodes after in-order traversal.
  
```cpp
        inOrder(root, inOrderVal);
```
- **Explanation:** Calls the `inOrder` function to fill the `inOrderVal` vector with the sorted values of the nodes.

```cpp
        int i = 0;
        int j = inOrderVal.size() - 1;
```
- **Explanation:** Initializes two pointers:
  - `i` starts at the beginning of `inOrderVal` (smallest value).
  - `j` starts at the end of `inOrderVal` (largest value).
  
- **Example:** If `inOrderVal` is `[2, 3, 4, 5, 6, 7]`, `i` points to 2, and `j` points to 7 initially.

### Two-Pointer Technique for Finding Sum

```cpp
        while(i < j) {
```
- **Explanation:** Starts a `while` loop that will continue as long as `i` is less than `j`. This loop checks pairs of values to see if their sum matches \( k \).

```cpp
            int sum = inOrderVal[i] + inOrderVal[j];
```
- **Explanation:** Calculates the sum of the values at indices `i` and `j`.
  
- **Example:** If `inOrderVal` is `[2, 3, 4, 5, 6, 7]` and `k = 9`:
  - Initially, `sum = 2 + 7 = 9`.

```cpp
            if(sum == k) return true;
```
- **Explanation:** If the sum is equal to \( k \), it means we’ve found two numbers in the BST that add up to \( k \), so the function returns `true`.
  
- **Example:** If `sum = 9` (our target), the function will return `true`.

```cpp
            else if(sum > k) j--;
```
- **Explanation:** If the sum is greater than \( k \), we decrease the `j` pointer by 1 to check the next smaller value. This is because the values in `inOrderVal` are sorted, so moving `j` to the left decreases the sum.

- **Example:** If `sum = 10` and `k = 9`, `j` moves from 5 to 4.

```cpp
            else i++;
```
- **Explanation:** If the sum is less than \( k \), we increase the `i` pointer by 1 to check the next larger value. This increases the sum since we are moving towards larger values in the sorted list.

- **Example:** If `sum = 8` and `k = 9`, `i` moves from 0 to 1.

```cpp
        } 
```
- **Explanation:** This closes the `while` loop. If we exit the loop, it means no pair of values in the BST adds up to \( k \).

```cpp
        return false;
    }
};
```
- **Explanation:** If no matching sum was found, the function returns `false`.


### Example Walkthrough

**Example:**  
BST:
```
      5
     / \
    3   6
   / \   \
  2   4   7
```
- **Target Sum:** \( k = 9 \)
  
- **In-Order Traversal:**  
  - `inOrderVal = [2, 3, 4, 5, 6, 7]`
  
- **Two-Pointer Technique:**  
  - Initialize `i = 0`, `j = 5`.
  - Calculate `sum = inOrderVal[i] + inOrderVal[j] = 2 + 7 = 9`.
  - Since `sum == k`, the function returns `true`.


### Step 4: Time and Space Complexity

1. **Time Complexity:**
   - The in-order traversal of a BST takes **O(n)** time, where \( n \) is the number of nodes.
   - The two-pointer search also takes **O(n)** time.
   - Thus, the overall time complexity is **O(n)**.

2. **Space Complexity:**
   - The vector `inOrderVal` takes **O(n)** space to store the in-order values of all nodes.
   - The recursive stack for `inOrder` traversal could also take **O(h)** space, where \( h \) is the height of the tree.
   - Therefore, the total space complexity is **O(n)**.

### Step 5: Additional Recommendations

- **Edge Cases to Consider:**
  - If the BST has only one node, there’s no pair to check, so return `false`.
  - If \( k \) is smaller than the smallest value or larger than the sum of the two largest values in the tree, return `false` early.

- **Alternative Approach:**  
  - If memory usage is a concern, consider an in-place solution using a stack for in-order traversal without storing values in an extra vector.

This approach should give students a strong foundation for solving similar problems with sorted arrays and BSTs efficiently.
