<h1 align='center'>Rat - In a - Maze</h1>

## Problem Statement

**Problem URL :** [Rat in a Maze](https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1)

![image](https://github.com/user-attachments/assets/5799b065-7757-4a17-ab05-bb8ba81e8b2d)
![image](https://github.com/user-attachments/assets/d99b4b49-54e5-4b0b-9dd6-c0978cf0e949)

## Problem Explanation
#### **Problem Statement:**
The problem is called **"Rat in a Maze"** and is about finding all possible paths for a rat to travel from the top-left corner `(0, 0)` of a square matrix to the bottom-right corner `(n-1, n-1)`. The matrix is a grid where:
- `1` represents a cell the rat can move to.
- `0` represents a cell that is blocked.

The rat can move in four directions:
1. **Down ('D')**
2. **Left ('L')**
3. **Right ('R')**
4. **Up ('U')**

The goal is to return all the paths that the rat can take to reach the destination. If no path exists, return an empty list.



#### **Example:**
**Input:**
```plaintext
n = 4
maze = [
    [1, 0, 0, 0],
    [1, 1, 0, 1],
    [1, 1, 0, 0],
    [0, 1, 1, 1]
]
```

**Output:**
```plaintext
["DDRDRR", "DRDDRR"]
```

**Explanation:**
- The rat starts at `(0, 0)` and needs to reach `(3, 3)`. The valid paths are:
  - `DDRDRR`: Down → Down → Right → Down → Right → Right
  - `DRDDRR`: Down → Right → Down → Down → Right → Right



#### **Approach:**
To solve this problem, we use **backtracking**, which allows us to explore all possible paths and backtrack when a path is invalid. Here's the step-by-step approach:

1. **Check if a Move is Valid:**
   Use the `isSafe` function to check:
   - The new position `(newX, newY)` is within bounds.
   - The cell `(newX, newY)` is not already visited.
   - The cell `(newX, newY)` is `1` (open for movement).

2. **Recursive Exploration:**
   - Start from `(0, 0)` and mark the cell as visited.
   - Try moving in all four possible directions (`D`, `L`, `R`, `U`) one by one.
   - Append the corresponding character to the current path string.

3. **Base Case:**
   - If the rat reaches the destination `(n-1, n-1)`, store the path in the result.

4. **Backtracking:**
   - After exploring all possible directions from a cell, reset the visited status of the cell (backtrack) to explore other paths.

5. **Return Results:**
   - If there are no paths, return an empty list. Otherwise, return all valid paths.


## Problem Solution
```cpp
class Solution {
  public:
    bool isSafe(int newX, int newY, vector<vector<bool>>& vis,  vector<vector<int>>& arr, int n){
        
        if((newX >= 0 && newX < n) && (newY >= 0 && newY < n) && vis[newX][newY] != 1 && arr [newX][newY] == 1) return true;
        
        return false;
    }
    
    void solve(int x, int y, vector<vector<int>>& arr, int n, vector<string>& ans, vector<vector<bool>>& vis, string path){
        
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return;
        }
        
        vis[x][y] = 1;
        
        if(isSafe(x+1, y, vis, arr, n)){
            solve(x+1, y, arr, n, ans, vis, path + 'D');
        }
        
        if(isSafe(x, y-1, vis, arr, n)){
            solve(x, y-1, arr, n, ans, vis, path + 'L');

        }
        
        if(isSafe(x, y+1, vis, arr, n)){
            solve(x, y+1, arr, n, ans, vis, path + 'R');
        }
        
        if(isSafe(x-1, y, vis, arr, n)){
            solve(x-1, y, arr, n, ans, vis, path + 'U');
        }
        
        vis[x][y] = 0;
        
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string> ans;
        vector<vector<bool>> visited(mat.size(), vector<bool>(mat.size(), 0));
        
        string path = "";
        
        solve(0, 0, mat, mat.size(), ans, visited, path);
        
        return ans;
    }
};
```


## Problem Solution Explanation

```cpp
class Solution {
  public:
    // Function to check if moving to (newX, newY) is valid
    bool isSafe(int newX, int newY, vector<vector<bool>>& vis, vector<vector<int>>& arr, int n){
        if((newX >= 0 && newX < n) && (newY >= 0 && newY < n) && vis[newX][newY] != 1 && arr[newX][newY] == 1) return true;
        return false;
    }
```
- **`isSafe`:** This function ensures the rat doesn't go out of bounds, visit an already visited cell, or step into a blocked cell (`0`).



```cpp
    void solve(int x, int y, vector<vector<int>>& arr, int n, vector<string>& ans, vector<vector<bool>>& vis, string path){
        if(x == n-1 && y == n-1){ // Base case: reached destination
            ans.push_back(path); // Add the path to the result
            return;
        }
        vis[x][y] = 1; // Mark the current cell as visited
```
- **Base Case:** When `(x, y)` is the destination `(n-1, n-1)`, save the current path in `ans`.
- **Mark as Visited:** The cell `(x, y)` is marked to avoid revisiting during this recursion path.



```cpp
        if(isSafe(x+1, y, vis, arr, n)){ // Move Down
            solve(x+1, y, arr, n, ans, vis, path + 'D');
        }
        
        if(isSafe(x, y-1, vis, arr, n)){ // Move Left
            solve(x, y-1, arr, n, ans, vis, path + 'L');
        }
        
        if(isSafe(x, y+1, vis, arr, n)){ // Move Right
            solve(x, y+1, arr, n, ans, vis, path + 'R');
        }
        
        if(isSafe(x-1, y, vis, arr, n)){ // Move Up
            solve(x-1, y, arr, n, ans, vis, path + 'U');
        }
```
- **Directional Moves:** Check all four directions (`D`, `L`, `R`, `U`) using `isSafe`. For each valid move, append the corresponding direction to the `path` string and recursively call `solve`.



```cpp
        vis[x][y] = 0; // Backtrack by unmarking the current cell
    }
```
- **Backtracking:** Reset the cell `(x, y)` to unvisited so other paths can use it.



```cpp
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string> ans;
        vector<vector<bool>> visited(mat.size(), vector<bool>(mat.size(), 0)); // Visited matrix
        string path = "";
        solve(0, 0, mat, mat.size(), ans, visited, path); // Start solving from (0, 0)
        return ans; // Return all possible paths
    }
};
```
- **`findPath`:** Initializes the visited matrix and starts the recursive `solve` function from `(0, 0)`.



### **Step 3: Examples**

#### **Example 1:**
Input:
```plaintext
n = 4
maze = [
    [1, 0, 0, 0],
    [1, 1, 0, 1],
    [1, 1, 0, 0],
    [0, 1, 1, 1]
]
```
Output:
```plaintext
["DDRDRR", "DRDDRR"]
```



#### **Example 2:**
Input:
```plaintext
n = 3
maze = [
    [1, 0, 0],
    [1, 1, 0],
    [1, 1, 1]
]
```
Output:
```plaintext
["DDR", "DRD"]
```


### **Step 4: Time and Space Complexity**

#### **Time Complexity:**
- There are **4 possible directions** from each cell.
- In the worst case, we might explore every cell in the grid. This results in **O(4^(n\*n))**.
- However, pruning due to `isSafe` reduces redundant paths, so the complexity is less than the worst case.

#### **Space Complexity:**
- **O(n\*n):** For the visited matrix.
- **O(n):** For the recursion stack (depth of the recursion tree).



### **Step 5: Recommendations**
1. **Practice Backtracking:** Solve similar problems like N-Queens, Word Search, and Rat in a Maze variations to strengthen understanding.
2. **Optimize Pruning:** Learn to prune invalid paths earlier to improve efficiency.
3. **Understand Base Cases:** Ensure base cases are well-defined to avoid infinite recursion.

By mastering backtracking, you'll handle complex problems efficiently!
