<h1 align='center'>N - Queens</h1>

## Problem Statement

**Problem URL :** [N-Queens](https://leetcode.com/problems/n-queens/)

![image](https://github.com/user-attachments/assets/e8761c6f-261e-4dcd-b8d3-5ead85274f52)

## Problem Explanation

The **N-Queens Problem** is a famous backtracking problem where the goal is to place \(n\) queens on an \(n \times n\) chessboard so that:
1. No two queens threaten each other.
   - A queen threatens another queen if they are in the same **row**, **column**, or **diagonal**.
2. You need to find all possible valid arrangements of \(n\) queens and return them in a specific format:
   - Each solution is represented as a list of strings where:
     - A `Q` represents a queen.
     - A `.` represents an empty space.

#### **Example**
For \(n = 4\), there are two valid solutions:
```plaintext
Solution 1:
[
 "Q...",
 "...Q",
 ".Q..",
 "..Q."
]

Solution 2:
[
 "..Q.",
 "Q...",
 "...Q",
 ".Q.."
]
```

#### **Approach**
To solve this problem, we can use **backtracking**. Backtracking systematically explores all possibilities to build solutions, backtracking (undoing) when a solution violates the constraints. Here's how we can approach this problem step-by-step:



**1. Represent the Chessboard**
- Use a **2D array** (`board`) of size \(n \times n\), where:
  - `1` indicates a queen is placed.
  - `0` indicates an empty spot.
- Initially, the board is filled with `0`.



**2. Solve Column-by-Column**
- Start from the **first column** and attempt to place a queen in any valid row.
- Move to the **next column** only if the queen placement in the current column is valid.



**3. Safety Check**
- For every cell `(row, col)` where we attempt to place a queen, we need to ensure:
  1. **No queen in the same row** to the left of the current column.
  2. **No queen in the upper-left diagonal**.
  3. **No queen in the lower-left diagonal**.



**4. Backtrack if a Solution Fails**
- If no valid row exists for the current column, backtrack:
  - Remove the last queen placed (reset `board[row][col]` to `0`).
  - Try the next row in the previous column.



**5. Store Valid Solutions**
- If queens are successfully placed in all \(n\) columns, convert the `board` to the required string format and save it.



#### **Example Walkthrough**
Let’s consider \(n = 4\).

1. **Start with Column 0**:
   - Try placing a queen at `(0, 0)` (row 0, column 0). It's valid.
   - Move to **column 1**.

2. **Column 1**:
   - Try `(0, 1)` → Invalid (same row as `(0, 0)`).
   - Try `(1, 1)` → Valid. Place the queen and move to **column 2**.

3. **Column 2**:
   - Try `(0, 2)` → Invalid (same row as `(0, 0)`).
   - Try `(1, 2)` → Invalid (same row as `(1, 1)`).
   - Try `(2, 2)` → Valid. Place the queen and move to **column 3**.

4. **Column 3**:
   - Try `(0, 3)` → Invalid.
   - Try `(1, 3)` → Invalid.
   - Try `(2, 3)` → Invalid.
   - Try `(3, 3)` → Valid. This completes one solution!

Backtrack and explore other possibilities until all valid solutions are found.

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

#### **1. Helper Function: `addSolution`**
```cpp
void addSolution(vector<vector<string>>& ans, vector<vector<int>>& board, int n) {
    vector<string> temp;
    for (int i = 0; i < n; i++) {
        string row = "";
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1)
                row += "Q";
            else
                row += ".";
        }
        temp.push_back(row);
    }
    ans.push_back(temp);
}
```
- Converts the `board` into the required string representation and adds it to the `ans` vector.

#### **2. Helper Function: `isSafe`**
```cpp
bool isSafe(int row, int col, vector<vector<int>>& board, int n) {
    int x = row;
    int y = col;

    // Check left side of the row
    while (y >= 0) {
        if (board[x][y] == 1) return false;
        y--;
    }

    // Check upper-left diagonal
    x = row;
    y = col;
    while (x >= 0 && y >= 0) {
        if (board[x][y] == 1) return false;
        x--;
        y--;
    }

    // Check lower-left diagonal
    x = row;
    y = col;
    while (x < n && y >= 0) {
        if (board[x][y] == 1) return false;
        x++;
        y--;
    }

    return true; 
}
```
- Validates whether a queen can be safely placed at `(row, col)`:
  1. Checks all positions in the **left row**.
  2. Checks all positions in the **upper-left diagonal**.
  3. Checks all positions in the **lower-left diagonal**.

#### **3. Recursive Function: `solve`**
```cpp
void solve(int col, vector<vector<string>>& ans, vector<vector<int>>& board, int n) {
    if (col == n) {
        addSolution(ans, board, n);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 1;
            solve(col + 1, ans, board, n);
            board[row][col] = 0; 
        }
    }
}
```
- If \( \text{col} = n \), all queens are placed, so call `addSolution`.
- For each row in the current column:
  1. Check if it's safe to place a queen.
  2. If valid, place the queen, move to the next column, and backtrack if needed.

#### **4. Main Function**
```cpp
vector<vector<string>> solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0)); 
    vector<vector<string>> ans; 
    solve(0, ans, board, n);
    return ans;
}
```
- Initializes the board and calls `solve` starting from column 0.



### **Step 3: Example Walkthrough**
Input: \( n = 4 \)

1. The algorithm explores all possibilities, starting with:
   ```
   Q...
   ...Q
   .Q..
   ..Q.
   ```

2. After finding a solution, it backtracks to explore:
   ```
   ..Q.
   Q...
   ...Q
   .Q..
   ```

Output:
```cpp
[
  ["Q...", "...Q", ".Q..", "..Q."],
  ["..Q.", "Q...", "...Q", ".Q.."]
]
```



### **Step 4: Time and Space Complexity**

#### **Time Complexity**
- **Backtracking** explores all possible queen placements:
  - The total number of recursive calls is roughly \( O(n!) \) since we attempt to place queens column by column.
- Checking safety involves \( O(n) \) operations for each queen.

Overall time complexity: \( O(n! \times n) \).

#### **Space Complexity**
- The `board` requires \( O(n^2) \) space.
- The recursion stack can grow to \( O(n) \).

Total space complexity: \( O(n^2) \).



### **Step 5: Recommendations**
1. **Practice Backtracking**:
   - Try simpler problems like generating all subsets or permutations to strengthen your recursion and backtracking skills.

2. **Optimize Safety Check**:
   - Instead of rechecking the board for threats, consider using hash sets for rows and diagonals to reduce the safety check to \( O(1) \).

3. **Visualize Solutions**:
   - Draw the chessboard for smaller \( n \) values to understand how the queens are placed.


