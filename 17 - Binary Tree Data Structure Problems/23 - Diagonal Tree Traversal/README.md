<h1 align='center'>Diagonal - Tree - Traversal</h1>

## Problem Statement

**Problem URL :** [Diagonal Tree Traversal](https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1)

![image](https://github.com/user-attachments/assets/e5b3885e-a9cf-4eb7-93c6-b3fb04852fcb)
![image](https://github.com/user-attachments/assets/67d329f7-55da-4dba-aeee-980ce629c5ea)
![image](https://github.com/user-attachments/assets/be62b727-6911-4403-a911-cf805bbee0fb)

## Problem Explanation

In a **Diagonal Tree Traversal**, we need to print all nodes of a binary tree diagonal-wise. Nodes are considered to be on the same diagonal if they are either at the same level or shifted rightward.

The diagonal traversal of a binary tree is represented by grouping nodes that share the same diagonal number. Starting from the root, all right nodes are considered to be on the same diagonal, while left children increment the diagonal by 1.

#### Example:
For the following binary tree:
```
        8
       / \
      3   10
     / \    \
    1   6    14
       / \   /
      4   7 13 
```

The diagonal traversal would yield the output: `[8, 10, 14, 3, 6, 7, 13, 1, 4]`

#### Real-world Analogy:
Imagine rows of seating in a movie theater where people in the same row are on the same diagonal and each step down a row increases the diagonal level.

#### Edge Cases:
- An empty tree should return an empty list.
- Trees with only left or only right children would have each node in a new or the same diagonal, respectively.

---

### Step 2: Approach

#### High-Level Overview:
To traverse diagonally:
1. Use a map to store the nodes grouped by their diagonal levels.
2. Traverse the tree recursively, increasing the diagonal level for left children and maintaining the same level for right children.
3. Finally, concatenate all values from each diagonal into a single list.

#### Step-by-Step Breakdown:
1. Start from the root node with diagonal `0`.
2. Add the node’s data to the corresponding diagonal level in the map.
3. Recur to the left child with `d+1` (increment diagonal level).
4. Recur to the right child with the same diagonal level `d`.
5. After the traversal, read the map diagonally from left to right and append all elements to the result list.

## Problem Solution
```cpp
void solve(Node* root, int d, map<int, vector<int>> & diagonalMap){
    if(root == NULL) return;
    
    diagonalMap[d].push_back(root -> data);
    
    solve(root -> left, d + 1, diagonalMap);
    solve(root -> right, d, diagonalMap);
}
vector<int> diagonal(Node *root)
{
   map<int, vector<int>> diagonalMap;
   vector<int> result;
   
   solve(root, 0, diagonalMap);
   
   
   for(auto i : diagonalMap){
       result.insert(result.end(), i.second.begin(), i.second.end());
   }
   
   
   return result;
}
```

## Problem Solution Explanation

```cpp
void solve(Node* root, int d, map<int, vector<int>> &diagonalMap){
    if(root == NULL) return;
    
    diagonalMap[d].push_back(root -> data);
    
    solve(root -> left, d + 1, diagonalMap);
    solve(root -> right, d, diagonalMap);
}
```
- **Function Definition**: `solve` is a helper function that performs the diagonal traversal recursively.
- **Parameters**:
  - `Node* root`: The current node in the traversal.
  - `int d`: The diagonal level.
  - `map<int, vector<int>> &diagonalMap`: A map that keeps track of each diagonal level.
- **Null Check**: If the current node is `NULL`, return.
- **Add Node Data to Map**: Insert the node’s data in the map at the key corresponding to the current diagonal level `d`.
- **Recursive Calls**:
  - `solve(root -> left, d + 1, diagonalMap)`: Traverse the left child, increasing the diagonal level.
  - `solve(root -> right, d, diagonalMap)`: Traverse the right child, keeping the diagonal level the same.

```cpp
vector<int> diagonal(Node *root) {
   map<int, vector<int>> diagonalMap;
   vector<int> result;
   
   solve(root, 0, diagonalMap);
```
- **Initialization**:
  - `diagonalMap`: Stores nodes at each diagonal level.
  - `result`: Final output vector.
- **Recursive Call**: Starts the traversal from the root at diagonal `0`.

```cpp
   for(auto i : diagonalMap){
       result.insert(result.end(), i.second.begin(), i.second.end());
   }
   
   return result;
}
```
- **Concatenate Diagonals**:
  - For each diagonal level in the map (sorted by keys), add all node values to the `result` vector.
  - `result.insert` appends each vector from `diagonalMap` into `result`.

---

### Step 4: Output Examples with Explanation

#### Example 1:
Given Tree:
```
        8
       / \
      3   10
     / \    \
    1   6    14
       / \   /
      4   7 13 
```

Diagonal Traversal:
- **Diagonal 0**: `[8, 10, 14]`
- **Diagonal 1**: `[3, 6, 7, 13]`
- **Diagonal 2**: `[1, 4]`

Final Output: `[8, 10, 14, 3, 6, 7, 13, 1, 4]`

#### Example 2:
Given Tree:
```
     1
    / \
   2   3
```

Diagonal Traversal:
- **Diagonal 0**: `[1, 3]`
- **Diagonal 1**: `[2]`

Final Output: `[1, 3, 2]`

---

### Step 5: Time and Space Complexity

#### Time Complexity:
- **O(N)**: Each node is visited once during the traversal, where **N** is the number of nodes.

#### Space Complexity:
- **O(N)**: Requires a map to store nodes by diagonal level, which may take up to **O(N)** space in the worst case (e.g., skewed tree). The result vector also uses **O(N)** space to store the final output.
