<h1 align='center'>N - Queens</h1>

## Problem Statement

**Problem URL :** [N-Queens](https://leetcode.com/problems/n-queens/)

![image](https://github.com/user-attachments/assets/e8761c6f-261e-4dcd-b8d3-5ead85274f52)

## Problem Explanation
#### **Problem Statement**
The **N-Queens problem** is about placing `N` queens on an `N x N` chessboard such that:
- No two queens threaten each other.
- Queens threaten in the same row, same column, or along both diagonals.

We need to find all valid configurations for placing these queens and return them in a specific format:
- Each solution is represented by a list of strings, where each string represents a row.
- For example, if `N = 4`, one solution looks like:
  ```
  .Q..
  ...Q
  Q...
  ..Q.
  ```



#### **Understanding the Approach**

To solve this problem, we use **backtracking**, a recursive approach that explores all possible placements of queens column by column. Here’s a breakdown:

1. **Constraints**:
   - Each column must have exactly one queen.
   - A queen's position in the current column must not conflict with queens in the previous columns.

2. **Tracking Validity**:
   - To check if placing a queen at `(row, col)` is valid:
     - **Row**: Check if any queen already occupies this row.
     - **Primary diagonal**: No queen should occupy `(row - col)`.
     - **Secondary diagonal**: No queen should occupy `(row + col)`.

   These checks are implemented efficiently using hash sets.

3. **Recursive Process**:
   - Start placing queens from column `0`.
   - For the current column:
     - Try placing a queen in every row.
     - If valid, mark the row and diagonals as occupied.
     - Recursively move to the next column.
   - If all queens are placed (base case), add the current configuration to the solution.
   - Backtrack by removing the queen and marking the row and diagonals as free.

4. **Output Format**:
   - Store solutions as a vector of strings.


## Problem Solution
```cpp
class Solution {
    public:

        void addSolution(vector<vector<string>>& ans, vector<int>& board, int n){
            vector<string> temp;

            for(int i = 0; i < n; i++){
                string row(n, '.');
                row[board[i]] = 'Q';
                temp.push_back(row);
            }
            ans.push_back(temp);
        }

        void solve(int col, vector<vector<string>>& ans, vector<int>& board, unordered_set<int>& rows, unordered_set<int>& primaryDiag, unordered_set<int>& secondaryDiag, int n){
            if(col == n){
                addSolution(ans, board, n);
                return;
            }

            for(int row = 0; row < n; row++){
                int diag1 = row - col;
                int diag2 = row + col;

                if(rows.find(row) == rows.end() && primaryDiag.find(diag1) == primaryDiag.end() && secondaryDiag.find(diag2) == secondaryDiag.end()){
                    board[col] = row;
                    rows.insert(row);
                    primaryDiag.insert(diag1);
                    secondaryDiag.insert(diag2);

                    solve(col + 1, ans, board, rows, primaryDiag, secondaryDiag, n);

                    board[col] = -1;
                    rows.erase(row);
                    primaryDiag.erase(diag1);
                    secondaryDiag.erase(diag2);
                }
            }
        }
        vector<vector<string>> solveNQueens(int n) {
            vector<int> board(n, -1);
            vector<vector<string>> ans;
            unordered_set<int> rows;
            unordered_set<int> primaryDaig;
            unordered_set<int> secondaryDaig;

            solve(0, ans, board, rows, primaryDaig, secondaryDaig, n);
            return ans;
        }
};

```

## Problem Solution Explanation

#### **Helper Function: `addSolution`**
```cpp
void addSolution(vector<vector<string>>& ans, vector<int>& board, int n){
    vector<string> temp;
    for(int i = 0; i < n; i++){
        string row(n, '.'); // Create a string of size 'n', initialized with '.'
        row[board[i]] = 'Q'; // Place a queen at the column index stored in board[i]
        temp.push_back(row); // Add this row to the solution
    }
    ans.push_back(temp); // Add this configuration to the final answers
}
```
- This function converts the internal `board` representation (queen positions per column) into the required string format.
- **Example**: If `board = [1, 3, 0, 2]` for `N = 4`, this means:
  - Column `0` → Row `1` has a queen → Row: `.Q..`
  - Column `1` → Row `3` has a queen → Row: `...Q`
  - Column `2` → Row `0` has a queen → Row: `Q...`
  - Column `3` → Row `2` has a queen → Row: `..Q.`



#### **Recursive Function: `solve`**
```cpp
void solve(int col, vector<vector<string>>& ans, vector<int>& board, unordered_set<int>& rows, unordered_set<int>& primaryDiag, unordered_set<int>& secondaryDiag, int n){
    if(col == n){
        addSolution(ans, board, n); // If all columns are processed, store the current board configuration
        return;
    }
    for(int row = 0; row < n; row++){ // Try placing a queen in each row of the current column
        int diag1 = row - col; // Primary diagonal value
        int diag2 = row + col; // Secondary diagonal value
        
        // Check if placing a queen is valid
        if(rows.find(row) == rows.end() && primaryDiag.find(diag1) == primaryDiag.end() && secondaryDiag.find(diag2) == secondaryDiag.end()){
            board[col] = row; // Place the queen in the current column
            rows.insert(row); // Mark this row as occupied
            primaryDiag.insert(diag1); // Mark the primary diagonal as occupied
            secondaryDiag.insert(diag2); // Mark the secondary diagonal as occupied
            
            solve(col + 1, ans, board, rows, primaryDiag, secondaryDiag, n); // Recurse to the next column

            // Backtrack: Remove the queen and mark the row/diagonals as free
            board[col] = -1;
            rows.erase(row);
            primaryDiag.erase(diag1);
            secondaryDiag.erase(diag2);
        }
    }
}
```
- **Base Case**: When `col == n`, all queens are placed, and the current configuration is stored using `addSolution`.
- **Recursive Case**: For each column, try placing a queen in every row and check if the position is valid.
- **Backtracking**: Ensures that the algorithm explores all possibilities by undoing changes made for a failed path.



#### **Main Function: `solveNQueens`**
```cpp
vector<vector<string>> solveNQueens(int n) {
    vector<int> board(n, -1); // Tracks queen positions for each column (initially no queens placed)
    vector<vector<string>> ans; // Stores all valid solutions
    unordered_set<int> rows; // Tracks rows that are already occupied
    unordered_set<int> primaryDiag; // Tracks primary diagonals that are occupied
    unordered_set<int> secondaryDiag; // Tracks secondary diagonals that are occupied

    solve(0, ans, board, rows, primaryDiag, secondaryDiag, n); // Start solving from the first column
    return ans; // Return the list of all solutions
}
```
- Initializes all data structures and starts the recursive backtracking process.



### **Step 3: Example Walkthrough**

#### **Example: N = 4**
1. Start from column `0`:
   - Place queen in `(0, 0)`. Mark row `0` and diagonals `(0 - 0)` and `(0 + 0)` as occupied.

2. Move to column `1`:
   - Row `0` is blocked. Try row `1` → Conflicts diagonally.
   - Try row `2` → Valid. Place queen in `(2, 1)`.

3. Move to column `2`:
   - Row `0` is blocked. Row `1` conflicts diagonally.
   - Try row `3` → Valid. Place queen in `(3, 2)`.

4. Move to column `3`:
   - Place queen in `(1, 3)`.
   - **Valid Configuration Found**:
     ```
     .Q..
     ...Q
     Q...
     ..Q.
     ```



### **Step 4: Time and Space Complexity**

#### **Time Complexity**
- There are `N!` permutations for placing queens.
- Validity checks for rows and diagonals take O(1).
- Total time complexity: **O(N!)**

#### **Space Complexity**
- Space for:
  - `board` array: O(N)
  - `rows`, `primaryDiag`, `secondaryDiag` sets: O(N)
  - Recursive stack: O(N)
- Total space complexity: **O(N)**



### **Step 5: Recommendations for Students**
1. **Visualize the Problem**: Draw the chessboard and manually place queens to understand constraints.
2. **Practice Similar Problems**: Try variations like "Sudoku Solver" and "Knight's Tour."
3. **Understand Diagonal Indexing**:
   - `Primary Diagonal`: `row - col`
   - `Secondary Diagonal`: `row + col`
4. **Optimize with Bitmasking**: For larger `N`, bitmasking can reduce space usage for row and diagonal tracking.
