<h1 align='center'>Rat - In a - Maze</h1>

## Problem Statement

**Problem URL :** [Rat in a Maze](https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1)

![image](https://github.com/user-attachments/assets/5799b065-7757-4a17-ab05-bb8ba81e8b2d)
![image](https://github.com/user-attachments/assets/d99b4b49-54e5-4b0b-9dd6-c0978cf0e949)

The "Rat in a Maze" problem is a classic backtracking problem where a rat is placed at the top-left corner (0, 0) of a maze represented by a matrix. The goal is to find all possible paths from the starting point to the bottom-right corner (n-1, m-1). The rat can move in four possible directions: **Down (D), Left (L), Right (R), and Up (U)**. The rat can only move on cells that contain a `1` (open path), and it cannot move on cells with a `0` (blocked path).

The task is to find all possible paths that the rat can take to reach the destination and return these paths in lexicographical order.

### Approach to Solve the Problem

The problem can be solved using **backtracking**. The key idea is to explore all possible paths from the starting point to the destination while marking visited cells to avoid revisiting them. If the rat reaches the destination, we save the path, and if it encounters a dead-end, we backtrack to try a different path.

#### Steps to Solve:

1. **Start from the initial cell (0, 0)**.
2. **Try all possible moves (D, L, R, U)** from the current cell.
   - Check if the next move is within bounds, leads to an unvisited cell, and is a valid path (value 1).
3. **Mark the current cell as visited**.
4. **If the rat reaches the destination (n-1, m-1)**, store the current path.
5. **Backtrack** by unmarking the visited cell to explore other paths.
6. **Sort all the valid paths** lexicographically.

### Pseudocode:

```text
function findPaths(matrix):
    n = matrix.size()     // Get number of rows
    m = matrix[0].size()  // Get number of columns
    visited = initialize 2D array of size n x m with all 0s
    answer = empty list
    
    if matrix[0][0] == 0:
        return answer    // No paths possible if the start is blocked
    
    path = empty string
    solve(matrix, n, m, 0, 0, visited, path, answer)
    sort(answer)          // Sort paths lexicographically
    return answer

function solve(matrix, n, m, x, y, visited, path, answer):
    if x == n-1 and y == m-1:  // Destination reached
        add path to answer
        return
    
    visited[x][y] = 1           // Mark current cell as visited
    
    // Try moving in all four directions (D, L, R, U)
    
    // Move Down (D)
    if isSafe(x+1, y, n, m, visited, matrix):
        append 'D' to path
        solve(matrix, n, m, x+1, y, visited, path, answer)
        remove last character from path  // Backtrack
    
    // Move Left (L)
    if isSafe(x, y-1, n, m, visited, matrix):
        append 'L' to path
        solve(matrix, n, m, x, y-1, visited, path, answer)
        remove last character from path  // Backtrack
    
    // Move Right (R)
    if isSafe(x, y+1, n, m, visited, matrix):
        append 'R' to path
        solve(matrix, n, m, x, y+1, visited, path, answer)
        remove last character from path  // Backtrack
    
    // Move Up (U)
    if isSafe(x-1, y, n, m, visited, matrix):
        append 'U' to path
        solve(matrix, n, m, x-1, y, visited, path, answer)
        remove last character from path  // Backtrack
    
    visited[x][y] = 0          // Unmark the cell for other paths

function isSafe(x, y, n, m, visited, matrix):
    return x is in bounds (0 <= x < n) and y is in bounds (0 <= y < m) 
           and visited[x][y] == 0 and matrix[x][y] == 1
```


## Problem Solution
```cpp
class Solution {
  private:
    bool isSafe(int x, int y , int n, int m, vector<vector<int>> &visited, vector<vector<int>> &mat){
        if((x >= 0 && x < n) && (y >= 0 && y < m) && visited[x][y] == 0 && mat[x][y] == 1){
            return true;
        }
        
        
        return false;
    }
    void solve(vector<vector<int>> &mat, int n, int m, int x, int y, vector<vector<int>> visited, string path, vector<string> &answer){
        
        // base case
        if(x == n-1 && y == m-1){
            answer.push_back(path);
            
            return;
        }
        
        visited[x][y] = 1;
        
        // down
        int newx = x+1;
        int newy = y;
        
        if(isSafe(newx, newy, n, m, visited, mat)){
            path.push_back('D');
            solve(mat, n, m, newx, newy, visited, path, answer);
            path.pop_back();
        }
        
        
        // left
        newx = x;
        newy = y-1;
        
         if(isSafe(newx, newy, n, m, visited, mat)){
            path.push_back('L');
            solve(mat, n, m, newx, newy, visited, path, answer);
            path.pop_back();
        }
        
        // right
        newx = x;
        newy = y+1;
        
         if(isSafe(newx, newy, n, m, visited, mat)){
            path.push_back('R');
            solve(mat, n, m, newx, newy, visited, path, answer);
            path.pop_back();
        }
        
        // Up
        newx = x-1;
        newy = y;
        
         if(isSafe(newx, newy, n, m, visited, mat)){
            path.push_back('U');
            solve(mat, n, m, newx, newy, visited, path, answer);
            path.pop_back();
        }
        
        visited[x][y] = 0;
    }
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string> answer;
        
        if(mat[0][0] == 0) return answer;
        
        int srcx = 0;
        int srcy = 0;
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        
        string path = "";
        solve(mat, n, m, srcx, srcy, visited, path, answer);
        sort(answer.begin(), answer.end());
        
        return answer;
    }
};
```

## Problem Solution Explanation

#### Class Declaration and Helper Functions
```cpp
class Solution {
```
- This is the declaration of the `Solution` class, which will contain the solution to the problem.

```cpp
private:
```
- Marks the section for internal/private helper functions, which will not be accessible outside the class.

#### `isSafe` Function: Checks if a Move is Valid
```cpp
bool isSafe(int x, int y, int n, int m, vector<vector<int>> &visited, vector<vector<int>> &mat){
    if((x >= 0 && x < n) && (y >= 0 && y < m) && visited[x][y] == 0 && mat[x][y] == 1){
        return true;
    }
    return false;
}
```
- **Purpose**: This function checks whether the next move to cell `(x, y)` is valid and safe. It returns `true` if:
  - `(x, y)` is within the matrix boundaries.
  - The cell has not been visited yet (`visited[x][y] == 0`).
  - The cell is open (`mat[x][y] == 1`, indicating it's a valid path).
- **Parameters**:
  - `x, y`: Coordinates of the next cell.
  - `n, m`: Dimensions of the matrix.
  - `visited`: A matrix tracking which cells have been visited.
  - `mat`: The input matrix representing the maze.

#### `solve` Function: Backtracking to Explore Paths
```cpp
void solve(vector<vector<int>> &mat, int n, int m, int x, int y, vector<vector<int>> visited, string path, vector<string> &answer){
```
- **Purpose**: This is the main recursive function that explores all possible paths from the current position `(x, y)` to the destination `(n-1, m-1)` using backtracking.
- **Parameters**:
  - `mat`: The matrix representing the maze.
  - `n, m`: Dimensions of the matrix.
  - `x, y`: Current coordinates of the rat.
  - `visited`: A matrix tracking visited cells.
  - `path`: A string representing the current path taken by the rat.
  - `answer`: A vector storing all valid paths.

```cpp
// Base case: If destination is reached
if(x == n-1 && y == m-1){
    answer.push_back(path);  // Add the current path to the answer
    return;
}
```
- **Base Case**: If the rat reaches the destination `(n-1, m-1)`, the current `path` is added to the `answer` and the function returns, ending the current recursive branch.

```cpp
visited[x][y] = 1;  // Mark the current cell as visited
```
- Mark the current cell `(x, y)` as visited to avoid revisiting it during this recursive call.

#### Moving in Different Directions
The function now tries to move in four possible directions: **Down (D), Left (L), Right (R), and Up (U)**. For each direction, it checks if the move is safe using the `isSafe` function, adds the corresponding move to the path, and recursively calls `solve` to explore further.

1. **Moving Down (`D`)**:
   ```cpp
   int newx = x+1;
   int newy = y;
   if(isSafe(newx, newy, n, m, visited, mat)){
       path.push_back('D');  // Add 'D' to the path
       solve(mat, n, m, newx, newy, visited, path, answer);  // Recursively explore the new cell
       path.pop_back();  // Backtrack: Remove 'D' from the path after exploring
   }
   ```
   - The rat attempts to move down by increasing the x-coordinate. If the new position is valid, `'D'` is added to the `path`, and the function recursively explores from the new position. After returning from the recursion, the last move is removed (backtracking).

2. **Moving Left (`L`)**:
   ```cpp
   newx = x;
   newy = y-1;
   if(isSafe(newx, newy, n, m, visited, mat)){
       path.push_back('L');
       solve(mat, n, m, newx, newy, visited, path, answer);
       path.pop_back();
   }
   ```
   - The rat moves left by decreasing the y-coordinate. The same recursive exploration and backtracking process is followed.

3. **Moving Right (`R`)**:
   ```cpp
   newx = x;
   newy = y+1;
   if(isSafe(newx, newy, n, m, visited, mat)){
       path.push_back('R');
       solve(mat, n, m, newx, newy, visited, path, answer);
       path.pop_back();
   }
   ```
   - The rat moves right by increasing the y-coordinate, and again, recursion and backtracking are used.

4. **Moving Up (`U`)**:
   ```cpp
   newx = x-1;
   newy = y;
   if(isSafe(newx, newy, n, m, visited, mat)){
       path.push_back('U');
       solve(mat, n, m, newx, newy, visited, path, answer);
       path.pop_back();
   }
   ```
   - The rat moves up by decreasing the x-coordinate. The function checks if it's safe, adds `'U'` to the path, and recursively explores the maze.

#### Backtracking
```cpp
visited[x][y] = 0;  // Unmark the

 current cell for future paths
```
- After all possible directions are explored, the current cell `(x, y)` is unmarked (backtracking) so it can be used in future recursive calls.

#### `findPath` Function: Main Entry Point
```cpp
public:
vector<string> findPath(vector<vector<int>> &mat) {
```
- **Purpose**: This is the main function that initiates the process of finding all paths in the maze.
- **Parameters**:
  - `mat`: The matrix representing the maze.

```cpp
vector<string> answer;  // To store all possible paths
```
- **answer**: A vector to store all valid paths from the start to the destination.

```cpp
if(mat[0][0] == 0) return answer;  // If starting point is blocked, return empty
```
- If the starting cell is blocked (i.e., `mat[0][0] == 0`), return an empty `answer`.

```cpp
int srcx = 0, srcy = 0;  // Start coordinates
int n = mat.size();      // Number of rows
int m = mat[0].size();   // Number of columns
vector<vector<int>> visited(n, vector<int>(m, 0));  // Initialize visited matrix with zeros
string path = "";  // Start with an empty path
solve(mat, n, m, srcx, srcy, visited, path, answer);  // Call solve to start the exploration
```
- Initializes starting coordinates, matrix dimensions, and the `visited` matrix. Calls the `solve` function to begin exploring the maze from the top-left corner `(0, 0)`.

```cpp
sort(answer.begin(), answer.end());  // Sort the paths in lexicographical order
```
- Sorts all the found paths lexicographically.

```cpp
return answer;  // Return all found paths
```
- Returns the sorted list of paths.
  
### Example Walkthrough:

Let's walk through the code using an example matrix:

```cpp
Input:
4
1 0 0 0
1 1 0 1
1 1 0 0
0 1 1 1

Expected Output: 
DDRDRR
DRDDRR
```

1. **Initial Matrix:**

   ```
   1 0 0 0
   1 1 0 1
   1 1 0 0
   0 1 1 1
   ```

2. **Start at `(0, 0)`**:
   - Move down: `D`, current position: `(1, 0)`
   - Move down: `D`, current position: `(2, 0)`
   - Move right: `R`, current position: `(2, 1)`
   - Move down: `D`, current position: `(3, 1)`
   - Move right: `R`, current position: `(3, 2)`
   - Move right: `R`, current position: `(3, 3)` (destination reached)

   The path is `DDRDRR`.

3. The recursive function backtracks and explores another valid path: `DRDDRR`.

4. The two paths are lexicographically sorted, and the output is:
   ```
   DDRDRR
   DRDDRR
   ```
