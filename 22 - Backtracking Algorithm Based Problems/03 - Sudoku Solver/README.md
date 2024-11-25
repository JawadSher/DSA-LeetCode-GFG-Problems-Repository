<h1 align='center'>Sudoku - Solver</h1>

## Problem Statement

**Problem URL :** [Sudoku Solver](https://leetcode.com/problems/sudoku-solver/)

![image](https://github.com/user-attachments/assets/d58b51a3-0f21-4cb6-bbf0-7eee744e6588)
![image](https://github.com/user-attachments/assets/f616c1f1-1d94-48f1-9e72-623f24e14940)

## Problem Explanation
#### **Problem Statement**
We need to solve a partially completed Sudoku board represented as a `9x9` grid:
- Empty cells are represented as `'.'`.
- Digits `1-9` are filled in some cells.

The solution must satisfy these constraints:
1. Each digit appears exactly once in each row.
2. Each digit appears exactly once in each column.
3. Each digit appears exactly once in each `3x3` subgrid.

#### **Approach**
This problem is solved using **backtracking**, which involves:
1. Iteratively checking each cell of the board.
2. Trying all possible digits (`1` to `9`) in empty cells.
3. Validating if placing a digit is safe based on the Sudoku rules.
4. If a valid placement is found, move to the next cell recursively.
5. If no valid placement is possible, backtrack by removing the digit and trying another.

## Problem Solution
```cpp
class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board, int value){
        char ch = value + '0';

        for(int i = 0; i < board[0].size(); i++){
            if(board[row][i] == ch) return false;
            if(board[i][col] == ch) return false;
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == ch) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        int n = board[0].size();

        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(board[row][col] == '.'){
                    for(int val = 1; val <= 9; val++){
                        if(isSafe(row, col, board, val)){
                            char ch = val + '0';
                            board[row][col] = ch;
                            if(solve(board)) return true;
                            board[row][col] = '.';
                        }

                    }

                    return false;
                }
            }
        }

        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
```

## Problem Solution Explanation

#### Function: `isSafe`

```cpp
bool isSafe(int row, int col, vector<vector<char>>& board, int value) {
    char ch = value + '0';
    for (int i = 0; i < board[0].size(); i++) {
        if (board[row][i] == ch) return false;
        if (board[i][col] == ch) return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch) return false;
    }
    return true;
}
```

- **Purpose**: Validates if placing the given value in the cell `(row, col)` is valid.
- **Steps**:
  - Converts the value to its character equivalent (e.g., `1 → '1'`).
  - Checks the entire row to see if the digit already exists.
  - Checks the entire column for conflicts.
  - Maps the `(row, col)` to its respective `3x3` subgrid and scans for conflicts.



#### Function: `solve`

```cpp
bool solve(vector<vector<char>>& board) {
    int n = board[0].size();
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (board[row][col] == '.') {
                for (int val = 1; val <= 9; val++) {
                    if (isSafe(row, col, board, val)) {
                        board[row][col] = val + '0';
                        if (solve(board)) return true;
                        board[row][col] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
```

- **Purpose**: Recursively solves the Sudoku board using backtracking.
- **Steps**:
  - Iterates through all cells of the board.
  - Identifies empty cells (`'.'`).
  - Tries placing digits from `1` to `9`.
  - Checks if the placement is valid using `isSafe`.
  - If valid, places the digit and recurses to solve the next cell.
  - If no valid digit works, backtracks by resetting the cell and trying another digit.
  - Returns `true` if the board is solved, or `false` if no solution is possible.



#### Function: `solveSudoku`

```cpp
void solveSudoku(vector<vector<char>>& board) {
    solve(board);
}
```

- **Purpose**: Initiates the solving process by calling the recursive `solve` function.



### **Step 3: Example Walkthrough**

#### Input Board
```
[
 ['5', '3', '.', '.', '7', '.', '.', '.', '.'],
 ['6', '.', '.', '1', '9', '5', '.', '.', '.'],
 ['.', '9', '8', '.', '.', '.', '.', '6', '.'],
 ['8', '.', '.', '.', '6', '.', '.', '.', '3'],
 ['4', '.', '.', '8', '.', '3', '.', '.', '1'],
 ['7', '.', '.', '.', '2', '.', '.', '.', '6'],
 ['.', '6', '.', '.', '.', '.', '2', '8', '.'],
 ['.', '.', '.', '4', '1', '9', '.', '.', '5'],
 ['.', '.', '.', '.', '8', '.', '.', '7', '9']
]
```

#### Execution Steps
1. Start at `(0, 2)`:
   - Try placing `1`. **Fails row check**.
   - Try placing `2`. **Fails subgrid check**.
   - Try placing `4`. **Valid**. Place `4` and proceed to `(0, 3)`.

2. At `(0, 3)`:
   - Try placing `1`. **Valid**. Place `1` and move forward.

3. Continue filling valid digits in empty cells.

4. Backtrack if stuck until a solution is found.

#### Output Board
```
[
 ['5', '3', '4', '6', '7', '8', '9', '1', '2'],
 ['6', '7', '2', '1', '9', '5', '3', '4', '8'],
 ['1', '9', '8', '3', '4', '2', '5', '6', '7'],
 ['8', '5', '9', '7', '6', '1', '4', '2', '3'],
 ['4', '2', '6', '8', '5', '3', '7', '9', '1'],
 ['7', '1', '3', '9', '2', '4', '8', '5', '6'],
 ['9', '6', '1', '5', '3', '7', '2', '8', '4'],
 ['2', '8', '7', '4', '1', '9', '6', '3', '5'],
 ['3', '4', '5', '2', '8', '6', '1', '7', '9']
]
```



### **Step 4: Time and Space Complexity**

#### **Time Complexity**
- In the worst case, each of the `81` cells is empty, and we try placing all `9` digits in each cell.
- Complexity: **O(9^(81))** (theoretical upper bound).

#### **Space Complexity**
- Recursive stack: **O(81)** in the worst case (depth of recursion for all cells).



### **Step 5: Additional Recommendations**
1. **Optimizations**:
   - Use arrays or bitmasks for faster row, column, and subgrid checks instead of repeatedly scanning the board.
2. **Debugging**:
   - Print the board state during recursion to visualize progress.
3. **Practicing**:
   - Try manually solving Sudoku puzzles to understand the constraints better.
