<h1 align='center'>Maximum - Sum of - Non-adjacent - Nodes</h1>

## Problem Statement

**Problem URL :** [Maximum Sum of Non-adjacent Nodes](https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1)

![image](https://github.com/user-attachments/assets/e498815b-a36e-4f91-b5cf-8db2347e0b45)
![image](https://github.com/user-attachments/assets/e581af15-1ea6-454f-a871-a4f9c1c0b56b)

## Problem Explanation

### Problem Description
The task is to find the maximum sum of non-adjacent nodes in a binary tree. Nodes are considered non-adjacent if they are not direct children of each other. 

### Constraints
1. Each node in the tree contains an integer value.
2. The tree can have both positive and negative values.
3. The structure of the tree can vary; it may be balanced or skewed.
4. The maximum number of nodes is not specified but is usually within reasonable limits for typical binary trees.

### Real-World Analogy
Imagine a situation where each node represents a house, and the value of the node is the amount of money in each house. You can only rob houses that are not directly next to each other (i.e., no two adjacent houses can be robbed). The goal is to maximize the total amount of money stolen without alerting the police (which happens if you rob adjacent houses).

### Edge Cases
1. An empty tree should return 0.
2. A tree with only one node should return the value of that node.
3. A tree with all negative values should still return the maximum (least negative) node value.

## Step 2: Approach

### High-Level Overview
The problem can be solved using a recursive approach with dynamic programming principles, where we compute two values at each node:
1. The maximum sum including the node itself.
2. The maximum sum excluding the node.

The maximum sum at any node is then determined by taking the maximum of these two values.

### Step-by-Step Breakdown
1. **Recursive Function**: Create a recursive function that returns a pair of integers for each node: 
   - The first integer represents the maximum sum when including that node.
   - The second integer represents the maximum sum when excluding that node.
2. **Base Case**: If the current node is NULL, return (0, 0) since there are no nodes to consider.
3. **Recursive Case**: For each node:
   - Calculate the results from the left and right children recursively.
   - The result for the current node when included is its value plus the sums from the children when excluded.
   - The result for the current node when excluded is the maximum sums from both children, regardless of whether they are included or excluded.
4. **Combine Results**: Return the calculated pair for the current node.

### Pseudocode
```plaintext
function solve(node):
    if node is NULL:
        return (0, 0)

    left = solve(node.left)
    right = solve(node.right)

    include_current = node.value + left.second + right.second
    exclude_current = max(left.first, left.second) + max(right.first, right.second)

    return (include_current, exclude_current)

function getMaxSum(root):
    ans = solve(root)
    return max(ans.first, ans.second)
```

## Problem Solution
```cpp
class Solution{
  public:
    pair<int, int> solve(Node* root){
        if(root == NULL) {
            pair<int, int> p = make_pair(0, 0);
            return p;
        };
        
        
        pair<int, int> left = solve(root -> left);
        pair<int, int> right = solve(root -> right);
        
        pair<int, int> res;
        res.first = root -> data + left.second + right.second;
        res.second = max(left.first, left.second) + max(right.first, right.second);
        
        
        return res;
        
    }
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
        
    }
};
```

## Problem Solution Explanation

Let's go through the code line by line:

#### Class Definition
```cpp
class Solution {
public:
```
- This line defines a class named `Solution`. All the methods inside this class will be related to solving the problem.

#### Recursive Function: `solve`
```cpp
pair<int, int> solve(Node* root) {
```
- This function takes a pointer to the root of a binary tree (`Node* root`) and returns a pair of integers (`pair<int, int>`). The pair consists of:
  - `first`: The maximum sum of non-adjacent nodes including the current node.
  - `second`: The maximum sum of non-adjacent nodes excluding the current node.

##### Base Case
```cpp
if (root == NULL) {
    pair<int, int> p = make_pair(0, 0);
    return p;
}
```
- **Explanation**: If the current node (`root`) is `NULL`, it means we've reached the end of a branch in the tree. 
- We return a pair `(0, 0)`, indicating that there are no nodes to consider in this path.
- **Example**: If we call `solve` on a leaf node's child (which is `NULL`), it returns `(0, 0)`.

##### Recursive Calls
```cpp
pair<int, int> left = solve(root->left);
pair<int, int> right = solve(root->right);
```
- **Explanation**: We make two recursive calls to solve the left and right subtrees of the current node:
  - `left` will hold the result from the left child.
  - `right` will hold the result from the right child.
- Each recursive call will return a pair containing the sums for its respective subtree.

**Example**:
For a tree like:
```
        10
       /  \
      1    2
     / \    \
    3   4    5
```
- Calling `solve(10)` will call `solve(1)` and `solve(2)`.

##### Result Calculation
```cpp
pair<int, int> res;
```
- **Explanation**: We create a new pair `res` to store the results for the current node.

```cpp
res.first = root->data + left.second + right.second;
```
- **Explanation**: This calculates the maximum sum when including the current node (`root`):
  - `root->data`: Value of the current node.
  - `left.second`: The maximum sum of non-adjacent nodes from the left child when it's excluded.
  - `right.second`: The maximum sum of non-adjacent nodes from the right child when it's excluded.
- The logic here is that if we include the current node, we cannot include its immediate children, hence we add the `second` values from both children.

**Example**:
If `root->data` is `10`, `left.second` is `4` (sum excluding node `1`), and `right.second` is `5` (sum excluding node `2`), then:
- `res.first = 10 + 4 + 5 = 19`.

```cpp
res.second = max(left.first, left.second) + max(right.first, right.second);
```
- **Explanation**: This calculates the maximum sum when excluding the current node:
  - `max(left.first, left.second)`: Choose the maximum sum from the left child, whether we include it or not.
  - `max(right.first, right.second)`: Choose the maximum sum from the right child, whether we include it or not.
- The idea here is that if we exclude the current node, we can freely choose to include or exclude its children based on which gives a higher sum.

**Example**:
Continuing from our previous example, if:
- `left.first = 7` (including node `1`),
- `left.second = 4` (excluding node `1`),
- `right.first = 5` (including node `2`),
- `right.second = 5` (excluding node `2`),
Then:
- `res.second = max(7, 4) + max(5, 5) = 7 + 5 = 12`.

##### Return Result
```cpp
return res;
```
- **Explanation**: This returns the computed pair `res` for the current subtree.
- The function will eventually return results all the way back up to the root.

#### Main Function: `getMaxSum`
```cpp
int getMaxSum(Node *root) {
```
- This function is called to get the maximum sum of non-adjacent nodes in the entire binary tree.

```cpp
pair<int, int> ans = solve(root);
```
- **Explanation**: Calls the `solve` function with the root node and stores the result in `ans`.

```cpp
return max(ans.first, ans.second);
```
- **Explanation**: Returns the maximum of the two sums computed from `solve(root)`.
- This gives the overall maximum sum of non-adjacent nodes in the tree.

### Example Execution Flow
Let's trace the execution for the tree:
```
        10
       /  \
      1    2
     / \    \
    3   4    5
```

1. **Start at the root (10)**:
   - Call `solve(10)`.
2. **Move to the left child (1)**:
   - Call `solve(1)`.
3. **Move to the left child (3)**:
   - Call `solve(3)`.
   - Both children of 3 are NULL, so it returns `(3, 0)`.
4. **Return to (1)** and process the right child (4):
   - Call `solve(4)`.
   - Both children of 4 are NULL, so it returns `(4, 0)`.
5. **Now for node (1)**:
   - `res.first = 1 + 0 + 0 = 1` (including 1)
   - `res.second = max(3, 0) + max(4, 0) = 3 + 4 = 7` (excluding 1)
   - Returns `(1, 7)` for node (1).
6. **Return to the root (10)** and process the right child (2):
   - Call `solve(2)`.
7. **Move to the right child (5)**:
   - Call `solve(5)`.
   - Both children of 5 are NULL, so it returns `(5, 0)`.
8. **Now for node (2)**:
   - Left child is NULL, so `left = (0, 0)`.
   - `res.first = 2 + 0 + 0 = 2`.
   - `res.second = max(0, 0) + max(5, 0) = 0 + 5 = 5`.
   - Returns `(2, 5)` for node (2).
9. **Finally for the root (10)**:
   - `res.first = 10 + 7 + 5 = 22`.
   - `res.second = max(1, 7) + max(2, 5) = 7 + 5 = 12`.
   - Returns `(22, 12)`.

The final answer from `getMaxSum(root)` is `max(22, 12)`, which is `22`.

Let's consider the following binary tree:
```
        10
       /  \
      1    2
     / \    \
    3   4    5
```

### Example 1
**Input**: The tree above.

- **Expected Output**: The maximum sum of non-adjacent nodes is `10 + 4 + 5 = 19`.

### Example 2
**Input**: An empty tree.

- **Expected Output**: `0`, since there are no nodes.

### Example 3
**Input**: A tree with all negative values.
```
        -1
       /  \
      -2   -3
     / \    \
    -4  -5   -6
```

- **Expected Output**: The maximum (least negative) node value is `-1`.

### Example 4
**Input**: A single-node tree.
```
        7
```

- **Expected Output**: `7`, as it's the only node.

### Explanation of Outputs
- The maximum sum is calculated by selecting nodes that are non-adjacent while maximizing their total value. In each example, we carefully select which nodes to include based on their position in the tree.

## Step 5: Time and Space Complexity

### Time Complexity
- **Recursive Calls**: Each node in the binary tree is visited once. Therefore, the time complexity is **O(N)**, where N is the number of nodes in the tree.

### Space Complexity
- **Recursive Stack Space**: The space complexity due to the recursion stack can go up to **O(H)**, where H is the height of the tree. In the worst case (for example, a skewed tree), this can be **O(N)**. For balanced trees, it is **O(log N)**.

### Summary
- The solution is efficient for typical binary trees, visiting each node once and storing results in pairs. It effectively handles various tree structures while maximizing the sum of non-adjacent nodes.

With this detailed breakdown, you should have a clear understanding of the problem, the approach taken, the code implementation, and the complexities involved. If you have any further questions or need clarifications, feel free to ask!
