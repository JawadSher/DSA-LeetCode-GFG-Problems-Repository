<h1 align='center'>Identical - Trees</h1>

## Problem Statement

**Problem URL :** [Identical Trees](https://www.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1)

![image](https://github.com/user-attachments/assets/cca3e903-d369-4d16-acec-06869f7cd6d7)
![image](https://github.com/user-attachments/assets/ccac42f6-8bc5-4080-8437-d12c7380d354)

## Problem Explanation

The problem requires checking whether two binary trees are identical. Two trees are considered identical if they have the same structure and node values at each corresponding position.

#### Examples:

1. **Example 1**:
   - **Tree 1**:
   ```
        1
       / \
      2   3
   ```
   - **Tree 2**:
   ```
        1
       / \
      2   3
   ```
   - **Output**: `True` (The trees are identical)

2. **Example 2**:
   - **Tree 1**:
   ```
        1
       / \
      2   3
   ```
   - **Tree 2**:
   ```
        1
       / \
      2   4
   ```
   - **Output**: `False` (The trees are not identical because the values of the right children differ)

3. **Example 3**:
   - **Tree 1**:
   ```
        1
       / \
      2   3
   ```
   - **Tree 2**:
   ```
        1
       /
      2
   ```
   - **Output**: `False` (The structure of the trees is different)

### Step 2: Approach to Solve the Problem

To determine if two binary trees are identical, we can use a recursive approach:

1. **Base Case**:
   - If both nodes are `NULL`, they are identical.
   - If one node is `NULL` and the other is not, they are not identical.

2. **Value Comparison**:
   - Compare the values of the current nodes of both trees. If they differ, the trees are not identical.

3. **Recursive Comparison**:
   - Recursively check the left subtrees and right subtrees of both trees.
   - If both the left and right subtree checks return `true`, the trees are identical.

## Problem Solution
```cpp
class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        
        if(r1 == NULL && r2 == NULL) return true;
        if(r1 == NULL && r2 != NULL) return false;
        if(r1 != NULL && r2 == NULL) return false;
        
        bool left = isIdentical(r1 -> left, r2 -> left);
        bool right = isIdentical(r1 -> right, r2 -> right);
        
        bool value = r1 -> data == r2 -> data;
        
        if(left && right && value) return true;
        
        return false;
    }
};
```

## Problem Solution Explanation
Here’s the code with detailed explanations:

```cpp
class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
```
- **Explanation**: This begins the definition of the `isIdentical` function, which takes two nodes (`r1` and `r2`) as input.

```cpp
        if(r1 == NULL && r2 == NULL) return true;
```
- **Explanation**: If both nodes are `NULL`, it means we have reached the end of both trees simultaneously, so they are identical up to this point. Return `true`.

```cpp
        if(r1 == NULL && r2 != NULL) return false;
        if(r1 != NULL && r2 == NULL) return false;
```
- **Explanation**: 
   - If one node is `NULL` and the other is not, the trees cannot be identical. Hence, return `false` for both conditions.

```cpp
        bool left = isIdentical(r1 -> left, r2 -> left);
        bool right = isIdentical(r1 -> right, r2 -> right);
```
- **Explanation**: 
   - Recursively check the left children of both trees and store the result in `left`.
   - Recursively check the right children of both trees and store the result in `right`.

```cpp
        bool value = r1 -> data == r2 -> data;
```
- **Explanation**: Compare the values of the current nodes. This checks if the data stored in `r1` and `r2` are the same.

```cpp
        if(left && right && value) return true;
```
- **Explanation**: If both the left subtree and right subtree are identical, and the current nodes' values are the same, return `true`.

```cpp
        return false;
    }
};
```
- **Explanation**: If any of the above conditions fail, return `false`, indicating the trees are not identical.

### Step-by-Step Example Walkthrough

Consider the following trees:

- **Tree 1**:
```
    1
   / \
  2   3
```

- **Tree 2**:
```
    1
   / \
  2   3
```

1. **Compare Node 1**:
   - Both values are `1`, proceed to compare left and right subtrees.

2. **Compare Node 2 (Left Subtree)**:
   - Both are `2`, proceed to compare their children (both `NULL`).

3. **Compare Node 3 (Right Subtree)**:
   - Both are `3`, proceed to compare their children (both `NULL`).

4. All comparisons return `true`, thus the function returns `true` for the trees being identical.

### Step 4: Time and Space Complexity

1. **Time Complexity**: **O(N)**, where `N` is the number of nodes in the trees.
   - We traverse each node in both trees exactly once to check for equality.

2. **Space Complexity**: **O(H)**, where `H` is the height of the trees.
   - The space complexity is due to the recursive function calls on the stack. In the worst case (skewed tree), it could be `O(N)`, while for balanced trees, it would be `O(log N)`.

Overall, this approach effectively checks for the structural and value equivalence of two binary trees using recursion.
