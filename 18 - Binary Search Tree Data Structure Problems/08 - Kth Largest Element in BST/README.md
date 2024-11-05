<h1 align='center'>Kth - Largest - Element - In - BST</h1>

## Problem Statement

**Problem URL :** [Kth Largest Element in BST](https://www.geeksforgeeks.org/problems/kth-largest-element-in-bst/1)

![image](https://github.com/user-attachments/assets/97529606-60fc-447d-a478-ad7079263270)
![image](https://github.com/user-attachments/assets/ee4ddcc6-25e9-47a6-a207-95a283695f51)

## Problem Explanation
**Problem**: Given a Binary Search Tree (BST) and an integer `k`, we want to find the `k`th largest element in the BST. 

**Constraints**:
- We need to find the element by traversing the BST in such a way that we efficiently locate the `k`th largest element.
- BST property: In a BST, for each node, all values in the left subtree are smaller, and all values in the right subtree are larger.

**Example**:
For a BST like this:

```
      5
     / \
    3   8
   / \   \
  2   4   10
```

If `k = 2`, the `2`nd largest element is `8`.  
If `k = 3`, the `3`rd largest element is `5`.

**Real-world Analogy**:
Imagine a leaderboard in a game where players are ranked by scores. Finding the `k`th largest score is like finding the `k`th highest scorer in a BST.

**Edge Cases**:
1. **Small BST**: A tree with only one node, where `k = 1`.
2. **`k` Larger Than Node Count**: If `k` is greater than the number of nodes in the BST, the function should return an error or a sentinel value (like `-1`) to indicate this.
3. **`k = 0` or Negative `k`**: This is an invalid input, and the function should handle it appropriately.

---

### Step 2: Approach

#### High-Level Overview
The task requires finding the `k`th largest element, which suggests an in-order traversal but in reverse order (right-root-left) since we want descending values.

#### Step-by-Step Breakdown
1. **Reverse In-order Traversal**: In a BST, a reverse in-order traversal (right-root-left) will give us nodes in descending order.
2. **Count Nodes**: While traversing in reverse order, keep a count of nodes visited so far.
3. **Find `k`th Node**: Stop the traversal as soon as the count matches `k`; this is our answer.

**Example Walkthrough**:
Using the same tree:
```
      5
     / \
    3   8
   / \   \
  2   4   10
```

Let's find the `2`nd largest element:
1. Start at the root (5) and go to the right subtree (8).
2. Go further right to 10 (largest element). `Count = 1`.
3. Return to 8. Now, `Count = 2` (matches `k`). So, `8` is the answer.

#### Pseudocode
```pseudo
function kthLargest(root, k):
    initialize count = 0
    perform reverseInOrderTraversal(root)
    
    function reverseInOrderTraversal(node):
        if node is null:
            return
        reverseInOrderTraversal(node.right)
        count++
        if count == k:
            result = node.data
            return
        reverseInOrderTraversal(node.left)
```

## Problem Solution
```cpp
class Solution {
  public:
     int solve(Node* root, int &i, int k){
        if(root == NULL) return -1;

        int right = solve(root -> right, i, k);
        if(right != -1) return right;

        i++;
        if(i == k) return root -> data;

        return solve(root -> left, i, k);
    }
    
    int kthLargest(Node *root, int k) {
        int i = 0;
        int ans = solve(root, i, k);

        return ans;
    }
};
```

## Problem Solution Explanation

Here's the given C++ code with a detailed line-by-line explanation.

```cpp
class Solution {
  public:
     int solve(Node* root, int &i, int k){
```

- **Line 1-3**: We define a class `Solution` with a method `solve`. This helper function uses recursion to perform the reverse in-order traversal (right-root-left).
- **Parameters**:
  - `root`: The root node of the current subtree.
  - `i`: A reference to a counter that tracks how many nodes we’ve visited.
  - `k`: The `k`th position we’re trying to find.


```cpp
        if(root == NULL) return -1;
```

- **Line 5**: If `root` is `NULL`, it means we’ve reached the end of a branch, so we return `-1` as a sentinel value indicating that we haven’t found the `k`th largest element yet.


```cpp
        int right = solve(root->right, i, k);
```

- **Line 6**: We perform a recursive call on the right subtree. This traversal starts from the largest values (rightmost nodes) in the BST.
- **Store Result**: We store the result of the recursive call in `right` to check if the `k`th largest element has been found.


```cpp
        if(right != -1) return right;
```

- **Line 7**: If `right` is not `-1`, it means we have already found the `k`th largest element in the right subtree. We return `right` up the recursive call stack to finish the function early.


```cpp
        i++;
        if(i == k) return root->data;
```

- **Line 9-10**: If we haven’t found the `k`th largest element yet, we increment the counter `i`.
  - If `i` equals `k`, then `root->data` is the `k`th largest element in the BST, so we return `root->data`.


```cpp
        return solve(root->left, i, k);
    }
```

- **Line 12**: If `i` is still not equal to `k`, we continue the traversal by exploring the left subtree.
- **Purpose**: This ensures that we move to smaller values only after checking the larger values.

```cpp
    int kthLargest(Node *root, int k) {
        int i = 0;
        int ans = solve(root, i, k);

        return ans;
    }
};
```

- **Line 15-20**: The `kthLargest` function initializes the counter `i` to `0` and calls `solve` with `root`, `i`, and `k`.
- The result from `solve` is stored in `ans`, which we then return as the final answer.

### Step 4: Output Examples

**Example 1**: For the given tree:
```
      5
     / \
    3   8
   / \   \
  2   4   10
```
- **Input**: `k = 2`
- **Output**: `8`

**Example 2**: For `k = 4`:
- **Input**: `k = 4`
- **Output**: `5`

**Explanation**:
- We start from the largest values in descending order. When `k = 4`, the nodes visited are `10 -> 8 -> 5`, so the 4th largest is `5`.


### Step 5: Time and Space Complexity

**Time Complexity**: `O(H + k)`
- **Explanation**: We only visit nodes until we find the `k`th largest element. In the worst case, we visit `H + k` nodes, where `H` is the height of the tree, since we traverse down the right side first.
- In a balanced BST, `H = log N`, making the time complexity close to `O(log N + k)`.

**Space Complexity**: `O(H)`
- **Explanation**: The space complexity is `O(H)` because of the recursion stack during traversal. This is the maximum depth of recursive calls we’ll have, which is proportional to the height of the BST.


This approach is efficient because it leverages the BST properties and only traverses the necessary nodes to find the `k`th largest element without requiring extra space for storing elements.
