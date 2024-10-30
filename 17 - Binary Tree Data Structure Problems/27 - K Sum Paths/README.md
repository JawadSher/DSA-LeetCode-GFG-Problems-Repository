<h1 align='center'>K - Sum - Paths</h1>

## Problem Statement

**Problem URL :** [K Sum Paths](https://www.geeksforgeeks.org/problems/k-sum-paths/1)

![image](https://github.com/user-attachments/assets/c08e276a-48f1-40f4-9fe4-9a423a3a5e50)
![image](https://github.com/user-attachments/assets/41375ba2-a1ec-4f9d-833f-d334ae1598b8)

## Problem Explanation
**Problem:** In a binary tree, find the number of paths that sum up to a given integer \( k \). These paths:
- Do not need to start at the root or end at a leaf, but they must move downwards through parent-child connections.

**Real-World Analogy:** Imagine a tree where each node has a value representing the weight of packages. We need to find all paths of packages that add up to a certain weight. These paths don't need to start at the beginning of a branch or end at the leaf but must follow a continuous path downwards.

**Constraints:**
- A path may start and end anywhere in the tree, but must follow a downward direction.
- Paths can overlap partially or be entirely contained within larger paths.

**Example:**
If we have the following binary tree:
```
         1
       /   \
      3     -1
     / \   /  \
    2   1 4    5
       /  \      \
      1    2      6
```
and we’re given \( k = 5 \), the paths that sum up to 5 are:
- Path `3 -> 2`
- Path `3 -> 1 -> 1`
- Path `1 -> 4`
- Path `-1 -> 5 -> 1`

The output here should be 4.

### Step 2: Approach

To solve this problem efficiently:
1. **Traverse Each Node:** Start from each node in the tree and check if any downward paths (starting from that node) sum to \( k \).
2. **Backtracking and Path Storage:** For each node visited, add its value to a list (representing the current path from root to the node).
3. **Check All Possible Sums:** Starting from the current node, check the sum of each possible path ending at the current node to see if it equals \( k \).
4. **Count Paths that Match:** For every match of the sum with \( k \), increment a counter.
## Problem Solution
```cpp
class Solution {
  public:
    void solve(Node* root, int k, vector<int> path, int &count){
        if(root == NULL) return;
        
        path.push_back(root -> data);
        
        solve(root -> left, k, path, count);
        solve(root -> right, k, path, count);
        
        int size = path.size();
        int sum = 0;
        for(int i = size -1; i >= 0; i--){
            sum += path[i];
            
            if(sum == k) count++;
        }
        
        path.pop_back();
    }
    int sumK(Node *root, int k) {
        vector<int> path;
        int count = 0;
        
        solve(root, k, path, count);
        
        return count;
    }
};
```

## Problem Solution Explanation

1. **`void solve(Node* root, int k, vector<int> path, int &count)`**  
   - This is a recursive helper function used to traverse the tree and count paths that sum to \( k \).
   - **Parameters:**
     - `root`: Current node in the traversal.
     - `k`: Target sum.
     - `path`: A vector that stores the current path from the root to the current node.
     - `count`: Reference to the count of paths summing to \( k \).

2. **Base Case: `if (root == NULL) return;`**
   - If `root` is `NULL`, the function returns without doing anything, which ends recursion for branches reaching a leaf’s end.

3. **Add Current Node’s Value to `path`: `path.push_back(root->data);`**
   - Adds the current node’s value to the `path` vector. This stores values from the root to the current node, so we can calculate all possible path sums ending at this node.

4. **Recursive Calls on Left and Right Subtrees**
   - `solve(root->left, k, path, count);`
   - `solve(root->right, k, path, count);`
   - These lines initiate recursive calls on the left and right child nodes, continuing the path.

5. **Loop to Calculate Sums for All Paths Ending at the Current Node**
   ```cpp
   int size = path.size();
   int sum = 0;
   for (int i = size - 1; i >= 0; i--) {
       sum += path[i];
       if (sum == k) count++;
   }
   ```
   - **Explanation:**
     - Starting from the end of `path`, which is the current node, it accumulates values backward towards the root.
     - If any accumulated sum equals \( k \), the `count` variable is incremented.
     - This approach ensures that all paths ending at the current node are checked for a sum of \( k \).

6. **Backtracking: `path.pop_back();`**
   - After all calculations for the current node are done, remove its value from `path` to backtrack. This prepares the `path` for the next sibling or ancestor node in the recursive stack.

7. **Main Function `int sumK(Node *root, int k)`**
   - Initializes `path` and `count` and calls the helper function `solve`.
   - After traversal, it returns the final count of paths that sum to \( k \).

### Step 4: Output Examples

- **Example 1:**
  ```
  Input Tree:       1
                  /   \
                 3     -1
                / \   /  \
               2   1 4    5
              /    / \      \
             1    1   2      6
  Target Sum (k): 5
  
  Output: 4
  Explanation: Four paths sum to 5: 
               - 3 -> 2
               - 3 -> 1 -> 1
               - 1 -> 4
               - -1 -> 5 -> 1
  ```

- **Example 2:**
  ```
  Input Tree:      10
                   /
                 -5
                /   \
              3     8
             /
            2
  Target Sum (k): 8
  
  Output: 2
  Explanation: Two paths sum to 8:
               - 10 -> -5 -> 3
               - 8
  ```

### Step 5: Time and Space Complexity

- **Time Complexity:** \(O(N^2)\)
  - The complexity is \(O(N^2)\) in the worst case because for each node, we check all paths leading to it, which can take up to \(N\) operations (for nodes closer to the root in a skewed tree).

- **Space Complexity:** \(O(N)\)
  - The `path` vector stores up to \(N\) nodes in the worst case, where \(N\) is the number of nodes in the binary tree. Additionally, recursion uses \(O(H)\) space, where \(H\) is the tree height.

### Summary
This solution is efficient for moderately sized binary trees and demonstrates how to approach path-related problems with recursion and backtracking, calculating possible path sums at each step to determine if they match the target.
