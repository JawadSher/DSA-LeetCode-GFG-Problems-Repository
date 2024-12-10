<h1 align="center">Largest - Sqaure - Formed in - A Matrix</h1>

## Problem Statement

**Problem URL (GFG):** [Largest Sqaure Formed in A Matrix](https://www.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1)

![image](https://github.com/user-attachments/assets/091097b3-2fa0-4226-9381-ac78c20a6f36)

### Problem Explanation
You are given a binary matrix (a matrix consisting of only `0`s and `1`s). Your task is to find the size of the largest square submatrix that contains only `1`s.

#### **Example Input and Output**

**Example 1:**
```
Input:
Matrix: 
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output:
3
Explanation:
The largest square submatrix of 1s has a side length of 3:
1 1 1
1 1 1
1 1 1
```

**Example 2:**
```
Input:
Matrix:
0 1 0 0
1 1 1 0
0 1 1 0
0 0 0 0

Output:
2
Explanation:
The largest square submatrix of 1s has a side length of 2:
1 1
1 1
```



### **How to Solve the Problem**
To solve this problem efficiently, we can use a **Dynamic Programming (DP)** approach. The key idea is to break the problem into smaller overlapping subproblems and use their solutions to find the solution to the main problem.

### **Algorithm and Intuition**

#### Step 1: **Define the DP Array**
Let (dp[i][j]) represent the size of the largest square submatrix ending at cell ((i, j)).

- If (matrix[i][j] = 0): (dp[i][j] = 0), as a square cannot end here.
- If (matrix[i][j] = 1): (dp[i][j]) is determined by the **minimum size of squares** ending at its **top, left, and top-left diagonal cells**, plus 1.

The transition equation is:
`dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1 quad {if } matrix[i][j] = 1`

#### Step 2: **Initialize the DP Array**
- For the first row and first column, (dp[i][j]) is the same as (matrix[i][j]), as no squares larger than 1 can exist there.

#### Step 3: **Compute the Largest Square**
- Traverse the matrix, compute (dp[i][j]) for each cell, and maintain a variable ({maxSize}) to store the maximum value in the (dp) array.

#### Step 4: **Return the Result**
- The largest square has an area equal to ({maxSize}^2).

### **Step-by-Step Example**

#### Input:
Matrix:
```
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
```

1. **Initialization**:
   - Create a (dp) array of the same size as the input matrix:
     ```
     dp:
     0 0 0 0 0
     0 0 0 0 0
     0 0 0 0 0
     0 0 0 0 0
     ```

2. **Fill the DP Table**:
   - Start filling (dp) based on the rules:

     For ((0, 0)): Matrix value is 1, so (dp[0][0] = 1).

     For ((0, 1)): Matrix value is 0, so (dp[0][1] = 0).

     Continue for the first row and first column:
     ```
     dp:
     1 0 1 0 0
     1 0 0 0 0
     1 0 0 0 0
     1 0 0 0 0
     ```

   - For ((1, 2)): Matrix value is 1.
     - Check top ((dp[0][2])), left ((dp[1][1])), and diagonal ((dp[0][1])).
     - Take (min(1, 0, 0) + 1 = 1). Update (dp[1][2] = 1).

   - For ((2, 2)): Matrix value is 1.
     - Check top ((dp[1][2])), left ((dp[2][1])), and diagonal ((dp[1][1])).
     - Take (min(1, 1, 0) + 1 = 2). Update (dp[2][2] = 2).

   Continue filling the table:
     ```
     dp:
     1 0 1 0 0
     1 0 1 1 1
     1 1 2 2 2
     1 0 0 1 0
     ```

3. **Find the Maximum Value**:
   - The largest value in (dp) is (2). This is the side length of the largest square.



### **Optimizations**

#### Space Optimization
Instead of maintaining a 2D (dp) array, use two 1D arrays (`curr` and `prev`) to store the current and previous row of the (dp) table. This reduces space complexity from (O(n * m)) to (O(m)).

### **Complexity Analysis**

- **Time Complexity**: (O(n * m))
  - Each cell is processed once.
- **Space Complexity**: (O(n * m)) (can be reduced to (O(m)) using space optimization).

### **Key Takeaways**
1. **Understanding the Transition**: The DP transition ensures that (dp[i][j]) considers the largest possible square ending at ((i, j)).
2. **Base Cases**: Handle the first row and column separately.
3. **Optimization**: Use in-place modification or space-optimized DP for large inputs.

---

## Recursive Approach (caused TLE)

The problem is to find the size of the largest square submatrix consisting entirely of 1s. A **recursive approach** solves this by exploring all possible squares in the matrix.

#### Key Idea:
For a given cell ((i, j)):
- If (mat[i][j] = 1), the largest square ending at ((i, j)) depends on:
  1. **Right**: The size of the largest square ending at ((i, j+1)).
  2. **Diagonal**: The size of the largest square ending at ((i+1, j+1)).
  3. **Down**: The size of the largest square ending at ((i+1, j)).

The size of the square ending at ((i, j)) is:

`1 + min({right}, {diagonal}, {down})`

If (mat[i][j] = 0), the size of the square is (0) because it cannot form part of a square.



### **Example Walkthrough**

#### Input Matrix:
```
1 0 1 0
1 1 1 0
1 1 1 0
```

1. Start from the top-left corner ((0, 0)):
   - Recursive call to ((0, 1)), ((1, 0)), and ((1, 1)).
   - Compute (min({right}, {diagonal}, {down}) + 1).

2. For ((1, 1)):
   - Recursive call to ((1, 2)), ((2, 1)), and ((2, 2)).
   - Compute the size of the square ending at ((1, 1)).

3. Repeat the process for all cells, updating the maximum size whenever a larger square is found.


### Source Code
```cpp
// User function Template for C++
class Solution {
  public:
    // Recursive function to find the size of the largest square ending at (i, j)
    int solve(vector<vector<int>>& mat, int i, int j, int &maxi) {
        // Base condition: If out of bounds, return 0
        if (i >= mat.size() || j >= mat[0].size()) return 0;

        // Recursive calls to calculate the size of squares in three directions:
        int right = solve(mat, i, j + 1, maxi);       // Square ending to the right
        int diagnol = solve(mat, i + 1, j + 1, maxi); // Square ending diagonally
        int down = solve(mat, i + 1, j, maxi);        // Square ending below

        // If the current cell contains 1
        if (mat[i][j] == 1) {
            // Calculate the size of the square ending at (i, j)
            int ans = 1 + min(right, min(diagnol, down));
            
            // Update the maximum square size
            maxi = max(maxi, ans);
            return ans; // Return the size of the square at (i, j)
        }

        // If the current cell contains 0, it cannot form a square
        return 0;
    }

    // Main function to find the largest square submatrix with all 1s
    int maxSquare(vector<vector<int>>& mat) {
        int maxi = 0; // Variable to store the maximum square size
        solve(mat, 0, 0, maxi); // Start solving from the top-left corner
        return maxi; // Return the maximum square size
    }
};
```
### Source Code Explanation

#### **Recursive Function**
```cpp
int solve(vector<vector<int>>& mat, int i, int j, int &maxi) {
    // Base condition: If out of bounds, return 0
    if (i >= mat.size() || j >= mat[0].size()) return 0;
```
- **Purpose**: If the cell is outside the matrix bounds, return 0 because it cannot contribute to a square.

```cpp
    // Recursive calls to calculate the size of squares in three directions:
    int right = solve(mat, i, j + 1, maxi);       // Square ending to the right
    int diagnol = solve(mat, i + 1, j + 1, maxi); // Square ending diagonally
    int down = solve(mat, i + 1, j, maxi);        // Square ending below
```
- Recursively calculate the sizes of squares ending:
  - To the **right** of ((i, j)): ((i, j+1)).
  - To the **diagonal** of ((i, j)): ((i+1, j+1)).
  - **Below** ((i, j)): ((i+1, j)).

```cpp
    // If the current cell contains 1
    if (mat[i][j] == 1) {
        // Calculate the size of the square ending at (i, j)
        int ans = 1 + min(right, min(diagnol, down));
```
- If the current cell ((i, j)) contains 1, calculate the largest square ending here using the three recursive results.

```cpp
        // Update the maximum square size
        maxi = max(maxi, ans);
        return ans; // Return the size of the square at (i, j)
    }
```
- Update the global maximum square size if the square at ((i, j)) is larger than the previous maximum.

```cpp
    // If the current cell contains 0, it cannot form a square
    return 0;
```
- If the cell contains 0, it cannot form part of a square, so return 0.

#### **Driver Function**
```cpp
int maxSquare(vector<vector<int>>& mat) {
    int maxi = 0; // Variable to store the maximum square size
    solve(mat, 0, 0, maxi); // Start solving from the top-left corner
    return maxi; // Return the maximum square size
}
```
- Initialize (maxi = 0).
- Call the recursive function starting from the top-left corner.
- Return the maximum size of the square.



### **Example Execution**

#### Input Matrix:
```
1 0 1 0
1 1 1 0
1 1 1 0
```

#### Execution Steps:
1. Start at ((0, 0)), call ((0, 1), (1, 0), (1, 1)).
2. ((1, 1)) calls ((1, 2), (2, 1), (2, 2)).
3. Base case triggers when reaching out-of-bounds cells.
4. Update (maxi) whenever a larger square is found.

#### Output:
The largest square size is **2**.



### **Complexity Analysis**

#### **Time Complexity**
- The recursive approach explores all possible subproblems.
- Without memoization, it computes overlapping subproblems multiple *.
- **Worst-case complexity**: (O(3^{n * m})), where (n) is the number of rows and (m) is the number of columns.

#### **Space Complexity**
- The recursion depth depends on the matrix size.
- **Space complexity**: (O(n + m)) (stack space for recursion).



### **Optimizations**
- To optimize, use **memoization** to store the results of overlapping subproblems, reducing the time complexity to (O(n * m)).

---

## Top-Down Approach (DP)
This version optimizes the recursive solution by using **memoization** to avoid recomputing overlapping subproblems. It stores the results of previously computed states in a `dp` table, significantly reducing redundant calculations.



### **Key Idea**
1. Use a 2D `dp` table where:
   - `dp[i][j]` represents the size of the largest square submatrix ending at cell ((i, j)).

2. Transition:
   - If (mat[i][j] = 1):
     `dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1])
`
     - (dp[i][j-1]): Largest square ending **to the left**.
     - (dp[i-1][j]): Largest square ending **above**.
     - (dp[i-1][j-1]): Largest square ending **diagonally above-left**.
   - If (mat[i][j] = 0), (dp[i][j] = 0).

3. **Base Case**:
   - If the cell ((i, j)) is out of bounds, return (0).
   - If (mat[i][j] = 0), the square size is (0).

4. Use a global variable `maxi` to keep track of the largest square size during recursive calls.



### **Example Walkthrough**

#### Input Matrix:
```
1 0 1 0
1 1 1 0
1 1 1 0
```

#### Step-by-Step Calculation:
1. **Recursive calls** start from each cell ((i, j)):
   - Compute the largest square ending at each cell.
   - Memoize the results in `dp`.

2. For cell ((2, 2)):
   - Check (dp[2, 1], dp[1, 2], dp[1, 1]):
     `dp[2][2] = 1 + min(dp[2, 1], dp[1, 2], dp[1, 1]) = 2
`

3. For cell ((1, 1)):
   - Check (dp[1, 0], dp[0, 1], dp[0, 0]):
     `dp[1][1] = 1 + min(dp[1, 0], dp[0, 1], dp[0, 0]) = 1
`

4. The `maxi` value is updated during each call:
   - Final `maxi = 2`.

#### Final DP Table:
```
1 0 1 0
1 1 1 0
1 2 2 0
```

#### Output:
The largest square size is **2**.


  
### Source Code
```cpp
// User function Template for C++
class Solution {
  public:
    // Recursive function with memoization to find the size of the largest square ending at (i, j)
    int solve(vector<vector<int>>& mat, int i, int j, vector<vector<int>>& dp) {
        // Base condition: If out of bounds, return 0
        if (i >= mat.size() || j >= mat[0].size()) return 0;

        // If the value is already computed, return it
        if (dp[i][j] != -1) return dp[i][j];
        
        // If the current cell contains 0, it cannot form a square
        if (mat[i][j] == 0) return dp[i][j] = 0;

        // Recursive calls to calculate the size of squares in three directions:
        int right = solve(mat, i, j - 1, dp);         // Square ending to the left
        int diagnol = solve(mat, i - 1, j, dp);       // Square ending diagonally
        int down = solve(mat, i - 1, j - 1, dp);      // Square ending above

        // Store the size of the square ending at (i, j) in the dp table
        return dp[i][j] = 1 + min({right, diagnol, down});
    }

    // Main function to find the largest square submatrix with all 1s
    int maxSquare(vector<vector<int>>& mat) {
        int maxi = 0; // Variable to store the maximum square size
        int n = mat.size();
        int m = mat[0].size();

        // Create a memoization table and initialize it with -1
        vector<vector<int>> dp(n, vector<int>(m, -1));

        // Iterate through the matrix and calculate the largest square ending at each cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maxi = max(maxi, solve(mat, i, j, dp)); // Update the maximum square size
            }
        }

        return maxi; // Return the maximum square size
    }
};
```
### Source Code Explanation

#### **Recursive Function**
```cpp
int solve(vector<vector<int>>& mat, int i, int j, vector<vector<int>>& dp) {
    // Base condition: If out of bounds, return 0
    if (i >= mat.size() || j >= mat[0].size()) return 0;
```
- If the cell is outside the matrix bounds, return (0).

```cpp
    // If the value is already computed, return it
    if (dp[i][j] != -1) return dp[i][j];
```
- Check if (dp[i][j]) is already computed. If yes, return the stored value to avoid recomputation.

```cpp
    // If the current cell contains 0, it cannot form a square
    if (mat[i][j] == 0) return dp[i][j] = 0;
```
- If (mat[i][j] = 0), the square size at ((i, j)) is (0).

```cpp
    // Recursive calls to calculate the size of squares in three directions:
    int right = solve(mat, i, j - 1, dp);         // Square ending to the left
    int diagnol = solve(mat, i - 1, j, dp);       // Square ending diagonally
    int down = solve(mat, i - 1, j - 1, dp);      // Square ending above
```
- Recursively compute the sizes of squares ending in three directions:
  - **Left**.
  - **Diagonal**.
  - **Above**.

```cpp
    // Store the size of the square ending at (i, j) in the dp table
    return dp[i][j] = 1 + min({right, diagnol, down});
```
- Compute (dp[i][j]) using the formula (1 + min({right}, {diagonal}, {down})).

#### **Driver Function**
```cpp
int maxSquare(vector<vector<int>>& mat) {
    int maxi = 0; // Variable to store the maximum square size
    int n = mat.size();
    int m = mat[0].size();

    // Create a memoization table and initialize it with -1
    vector<vector<int>> dp(n, vector<int>(m, -1));
```
- Initialize (dp[i][j] = -1) to indicate uncomputed states.

```cpp
    // Iterate through the matrix and calculate the largest square ending at each cell
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            maxi = max(maxi, solve(mat, i, j, dp)); // Update the maximum square size
        }
    }
```
- Iterate over each cell in the matrix.
- Call the `solve` function for each cell and update (maxi).

```cpp
    return maxi; // Return the maximum square size
}
```
- Return the maximum square size.



### **Example Execution**

#### Input Matrix:
```
1 0 1 0
1 1 1 0
1 1 1 0
```

#### Output:
- Largest square size = **2**.



### **Complexity Analysis**

#### **Time Complexity**
- Each cell ((i, j)) is visited once and calculated only once due to memoization.
- Total complexity: (O(n * m)), where (n) and (m) are the number of rows and columns.

#### **Space Complexity**
- Space for the `dp` table: (O(n * m)).
- Space for recursion stack: (O(n + m)).
- Total space complexity: (O(n * m)).



### **Advantages of Memoization**
1. Avoids redundant calculations by storing previously computed values.
2. Converts the exponential recursive approach into an efficient (O(n * m)) solution.

---

## Bottom-Up Approach (DP)
The bottom-up dynamic programming (DP) approach builds a solution iteratively by filling a DP table. Unlike recursion, this method avoids stack overhead and processes the matrix in a systematic manner, typically from bottom-right to top-left.


### **Key Idea**

1. Use a **2D DP table** (`dp`) where:
   - `dp[i][j]` represents the size of the largest square submatrix with all 1s ending at cell ((i, j)).

2. Transition:
   - If (mat[i][j] = 1):
     `dp[i][j] = 1 + min(dp[i][j+1], dp[i+1][j+1], dp[i+1][j])
`
     - (dp[i][j+1]): Size of the square ending **to the right**.
     - (dp[i+1][j+1]): Size of the square ending **diagonally**.
     - (dp[i+1][j]): Size of the square ending **below**.
   - If (mat[i][j] = 0), (dp[i][j] = 0).

3. Maintain a variable `maxi` to track the largest square size during the iteration.

4. **Edge Case**:
   - If the input matrix is empty, return (0).



### **Example Walkthrough**

#### Input Matrix:
```
1 0 1 0
1 1 1 0
1 1 1 0
```

### Source Code
```cpp
// User function Template for C++
class Solution {
  public:
    // Function to solve the problem using the bottom-up DP approach
    int solve(vector<vector<int>>& mat, int& maxi) {
        // Edge case: If the input matrix is empty, return 0
        if (mat.empty()) return 0;
        
        // Dimensions of the matrix
        int n = mat.size();
        int m = mat[0].size();
        
        // DP table to store the size of the largest square ending at each cell
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // Extra row and column for boundary conditions
        
        // Iterate through the matrix in reverse (bottom to top, right to left)
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                // Get values from adjacent cells in the DP table
                int right = dp[i][j + 1];       // Cell to the right
                int diagnol = dp[i + 1][j + 1]; // Diagonal cell
                int down = dp[i + 1][j];        // Cell below

                // If the current cell contains 1, calculate the size of the square ending here
                if (mat[i][j] == 1) {
                    dp[i][j] = 1 + min({right, diagnol, down}); // Add 1 to the smallest adjacent square
                    maxi = max(maxi, dp[i][j]);                // Update the maximum square size
                } else {
                    dp[i][j] = 0; // If the cell contains 0, it cannot form a square
                }
            }
        }
        
        return dp[0][0]; // This value is not used but returned for compatibility
    }

    // Main function to find the size of the largest square submatrix with all 1s
    int maxSquare(vector<vector<int>>& mat) {
        int maxi = 0; // Variable to store the maximum square size
        solve(mat, maxi); // Compute the largest square using the solve function
        return maxi; // Return the maximum square size
    }
};
```

### Source Code Explanation

1. **Matrix Dimensions**:
   - (n = 3), (m = 4).

2. Initialize a DP table with extra rows and columns for boundary conditions:
   - Initial DP Table:
     ```
     0 0 0 0 0
     0 0 0 0 0
     0 0 0 0 0
     0 0 0 0 0
     ```

3. Start filling the DP table from bottom-right to top-left:

   - Cell ((2, 2)):
     - (dp[2][2] = 1 + min(dp[2][3], dp[3][3], dp[3][2]) = 1).
     - Update `maxi = 1`.

   - Cell ((2, 1)):
     - (dp[2][1] = 1 + min(dp[2][2], dp[3][2], dp[3][1]) = 2).
     - Update `maxi = 2`.

   - Continue filling for all cells...

4. Final DP Table:
   ```
   1 0 1 0 0
   1 1 1 0 0
   1 2 2 0 0
   0 0 0 0 0
   ```

5. The largest square size is `maxi = 2`.



### **Code Explanation (Line by Line)**

#### **DP Initialization**
```cpp
// DP table to store the size of the largest square ending at each cell
vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // Extra row and column for boundary conditions
```
- A DP table with dimensions ((n+1) * (m+1)) is created.
- The extra row and column simplify boundary checks during calculations.

#### **Matrix Traversal**
```cpp
for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
```
- Traverse the matrix starting from the bottom-right cell to the top-left cell.

#### **Calculate Square Size**
```cpp
// Get values from adjacent cells in the DP table
int right = dp[i][j + 1];       // Cell to the right
int diagnol = dp[i + 1][j + 1]; // Diagonal cell
int down = dp[i + 1][j];        // Cell below

// If the current cell contains 1, calculate the size of the square ending here
if (mat[i][j] == 1) {
    dp[i][j] = 1 + min({right, diagnol, down}); // Add 1 to the smallest adjacent square
    maxi = max(maxi, dp[i][j]);                // Update the maximum square size
} else {
    dp[i][j] = 0; // If the cell contains 0, it cannot form a square
}
```
- If (mat[i][j] = 1), compute the size of the square ending at ((i, j)).
- Use the `min` function to find the smallest of the three adjacent cells and add (1).
- If (mat[i][j] = 0), set (dp[i][j] = 0).

#### **Return the Maximum Size**
```cpp
int maxSquare(vector<vector<int>>& mat) {
    int maxi = 0; // Variable to store the maximum square size
    solve(mat, maxi); // Compute the largest square using the solve function
    return maxi; // Return the maximum square size
}
```
- Return the largest square size stored in `maxi`.



### **Complexity Analysis**

#### **Time Complexity**
- Each cell ((i, j)) is processed once.
- Total complexity: (O(n * m)), where (n) and (m) are the number of rows and columns.

#### **Space Complexity**
- Space for the DP table: (O(n * m)).
- Total space complexity: (O(n * m)).



### **Advantages of Bottom-Up DP**
1. Avoids recursion stack overhead.
2. Processes cells in a systematic manner, ensuring all dependencies are resolved beforehand.
3. Efficient and easy to implement for problems with overlapping subproblems like this one.



### **Example Execution**

#### Input Matrix:
```
1 0 1 0
1 1 1 0
1 1 1 0
```

#### Output:
- Largest square size = **2**.



### **Comparison with Other Approaches**

| Approach              | Time Complexity | Space Complexity | Comments                                       |
|---|---|---|---|
| Recursive (Naive)     | Exponential    | (O(n+m))     | Redundant computations, impractical for large inputs. |
| Recursive + Memoization | (O(n * m)) | (O(n * m)) | Avoids recomputation using memoization.       |
| Bottom-Up DP          | (O(n * m)) | (O(n * m)) | Systematic and avoids recursion overhead.     |


---

## 1) Space Optimized Approach (DP)
The space optimization approach uses **two 1D arrays** instead of a full 2D DP table, thereby reducing the space complexity. This method is particularly useful for large matrices where memory is a constraint.

### **Key Idea**

1. Use **two 1D arrays**:
   - `curr` to store the current row of computations.
   - `next` to store the results of the next row for the transition.

2. Transition:
   - If (mat[i][j] = 1):
     `curr[j] = 1 + min(curr[j+1], next[j+1], next[j])
`
     - (curr[j+1]): Size of the square ending **to the right**.
     - (next[j+1]): Size of the square ending **diagonally**.
     - (next[j]): Size of the square ending **below**.
   - If (mat[i][j] = 0), (curr[j] = 0).

3. Maintain a variable `maxi` to track the largest square size during the iteration.

4. After processing a row, **swap `curr` and `next`** for the next iteration.



### **Example Walkthrough**

#### Input Matrix:
```
1 0 1 0
1 1 1 0
1 1 1 0
```

#### Step-by-Step Calculation:

1. **Matrix Dimensions**:
   - (n = 3), (m = 4).

2. Initialize `curr` and `next` with size (m+1) filled with (0):
   ```
   curr = [0, 0, 0, 0, 0]
   next = [0, 0, 0, 0, 0]
   ```

3. Start filling the arrays from bottom-right to top-left:

   - Row (i = 2):
     - (j = 3): (mat[2][3] = 0), so (curr[3] = 0).
     - (j = 2): (mat[2][2] = 1), so:
       `  curr[2] = 1 + min(curr[3], next[3], next[2]) = 1
  `
     - (j = 1): (mat[2][1] = 1), so:
       `  curr[1] = 1 + min(curr[2], next[2], next[1]) = 1
  `
     - (j = 0): (mat[2][0] = 1), so:
       `  curr[0] = 1 + min(curr[1], next[1], next[0]) = 1
  `

     Update `maxi = 1`. Swap `curr` and `next`.

   - Row (i = 1):
     - Continue similarly...

   - Row (i = 0):
     - Continue similarly...

4. After all rows are processed, `maxi` contains the size of the largest square submatrix.

### Source Code
```cpp
// User function Template for C++
class Solution {
  public:
    // Function to compute the largest square submatrix with all 1s using space optimization
    int solve(vector<vector<int>>& mat, int& maxi) {
        // Edge case: If the matrix is empty, return 0
        if (mat.empty()) return 0;
        
        // Dimensions of the matrix
        int n = mat.size();
        int m = mat[0].size();
        
        // Two 1D vectors to store the current and next rows of the DP table
        vector<int> curr(m + 1, 0); // Current row
        vector<int> next(m + 1, 0); // Next row
        
        // Iterate through the matrix in reverse (bottom to top, right to left)
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                // Fetch values from the next row and the current row (for right, diagonal, and down)
                int right = curr[j + 1];       // Cell to the right
                int diagnol = next[j + 1];    // Diagonal cell
                int down = next[j];           // Cell below
                
                // If the current cell contains 1, calculate the size of the square ending here
                if (mat[i][j] == 1) {
                    curr[j] = 1 + min({right, diagnol, down}); // Add 1 to the smallest adjacent square
                    maxi = max(maxi, curr[j]);                // Update the maximum square size
                } else {
                    curr[j] = 0; // If the cell contains 0, it cannot form a square
                }
            }
            
            // Update the `next` row to the current row for the next iteration
            next = curr;
        }
        
        return next[0]; // This value is not used but returned for compatibility
    }

    // Main function to find the size of the largest square submatrix with all 1s
    int maxSquare(vector<vector<int>>& mat) {
        int maxi = 0; // Variable to store the maximum square size
        solve(mat, maxi); // Compute the largest square using the solve function
        return maxi; // Return the maximum square size
    }
};
```

### Source Code Explanation

#### **Row Initialization**
```cpp
vector<int> curr(m + 1, 0); // Current row
vector<int> next(m + 1, 0); // Next row
```
- Two 1D arrays are used instead of a 2D DP table.
- Extra column is added for boundary conditions.

#### **Matrix Traversal**
```cpp
for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
```
- Traverse the matrix starting from the bottom-right cell to the top-left cell.

#### **Calculate Square Size**
```cpp
// Fetch values from the next row and the current row
int right = curr[j + 1];       // Cell to the right
int diagnol = next[j + 1];    // Diagonal cell
int down = next[j];           // Cell below

// If the current cell contains 1, calculate the size of the square ending here
if (mat[i][j] == 1) {
    curr[j] = 1 + min({right, diagnol, down}); // Add 1 to the smallest adjacent square
    maxi = max(maxi, curr[j]);                // Update the maximum square size
} else {
    curr[j] = 0; // If the cell contains 0, it cannot form a square
}
```
- Compute the size of the square ending at ((i, j)) using values from `curr` and `next`.
- Update `maxi` with the largest square size encountered.

#### **Row Swap**
```cpp
next = curr; // Update the `next` row to the current row
```
- The current row becomes the next row for the next iteration.

#### **Return the Maximum Size**
```cpp
int maxSquare(vector<vector<int>>& mat) {
    int maxi = 0; // Variable to store the maximum square size
    solve(mat, maxi); // Compute the largest square using the solve function
    return maxi; // Return the maximum square size
}
```
- Return the largest square size stored in `maxi`.



### **Complexity Analysis**

#### **Time Complexity**
- Each cell ((i, j)) is processed once.
- Total complexity: (O(n * m)), where (n) and (m) are the number of rows and columns.

#### **Space Complexity**
- Two 1D arrays of size (m+1): (O(m)).
- Total space complexity: (O(m)).



### **Advantages of Space Optimization**
1. Reduces space usage significantly compared to a full 2D DP table.
2. Suitable for large matrices where memory constraints are critical.



### **Example Execution**

#### Input Matrix:
```
1 0 1 0
1 1 1 0
1 1 1 0
```

#### Output:
- Largest square size = **2**.



### **Comparison with Other Approaches**

| Approach              | Time Complexity | Space Complexity | Comments                                       |
|--|---|---|---|
| Bottom-Up DP          | (O(n * m)) | (O(n * m)) | Straightforward but uses a full DP table.     |
| Space Optimization    | (O(n * m)) | (O(m))         | Efficient in both time and space.             |

---
## 2) Space Optimized Approach (DP)
The **in-place modification approach** modifies the input matrix directly to save space. Instead of using additional space for a DP table or arrays, the input matrix itself is updated to store intermediate results.

### **Key Idea**

1. Modify the **input matrix** to act as the DP table:
   - If (mat[i][j] = 1), compute the largest square submatrix ending at ((i, j)) using the values in adjacent cells:
     `mat[i][j] = 1 + min(mat[i+1][j], mat[i][j+1], mat[i+1][j+1])`
     
     - (mat[i+1][j]): Size of the square ending **below**.
     - (mat[i][j+1]): Size of the square ending **to the right**.
     - (mat[i+1][j+1]): Size of the square ending **diagonally**.

2. Cells in the **last row or last column**:
   - They are not updated since they cannot form a square larger than themselves.

3. Maintain a variable `maxi` to track the size of the largest square.

4. Traverse the matrix **from bottom-right to top-left**:
   - Ensures that the necessary values for computation are available when needed.

### Source Code
```cpp
// User function Template for C++
class Solution {
  public:
    // Function to compute the largest square submatrix with all 1s using in-place modification
    int solve(vector<vector<int>>& mat) {
        // Edge case: If the matrix is empty, return 0
        if (mat.empty()) return 0;

        // Dimensions of the matrix
        int n = mat.size();
        int m = mat[0].size();

        // Variable to store the size of the largest square
        int maxi = 0;

        // Traverse the matrix from bottom-right to top-left
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                // If the cell is in the last row or last column, no need to modify its value
                if (i == n - 1 || j == m - 1) {
                    maxi = max(maxi, mat[i][j]); // Update `maxi` if the cell contains `1`
                } else if (mat[i][j] == 1) {
                    // If the current cell contains `1`, calculate the size of the square
                    mat[i][j] = 1 + min({mat[i + 1][j], mat[i][j + 1], mat[i + 1][j + 1]});
                    maxi = max(maxi, mat[i][j]); // Update `maxi` if the square size increases
                }
            }
        }

        return maxi; // Return the size of the largest square
    }

    // Main function to find the size of the largest square submatrix with all 1s
    int maxSquare(vector<vector<int>>& mat) {
        return solve(mat); // Call the solve function
    }
};
```

### Source Code Explanation

#### **Matrix Initialization**
```cpp
int n = mat.size();
int m = mat[0].size();
int maxi = 0; // Variable to track the size of the largest square
```
- (n): Number of rows in the matrix.
- (m): Number of columns in the matrix.
- `maxi`: Tracks the maximum square size encountered.

#### **Matrix Traversal**
```cpp
for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
```
- Traverse the matrix from the bottom-right corner to the top-left.

#### **Update Matrix**
```cpp
if (i == n - 1 || j == m - 1) {
    maxi = max(maxi, mat[i][j]); // Update `maxi` if the cell contains `1`
} else if (mat[i][j] == 1) {
    mat[i][j] = 1 + min({mat[i + 1][j], mat[i][j + 1], mat[i + 1][j + 1]});
    maxi = max(maxi, mat[i][j]); // Update `maxi` if the square size increases
}
```
- **Edge Cases**: For the last row and last column, (mat[i][j]) remains unchanged.
- **Update Rule**: For other cells, compute the largest square submatrix using the three adjacent cells and update `maxi`.

#### **Return Result**
```cpp
return maxi;
```
- Return the largest square size stored in `maxi`.



### **Example Walkthrough**

#### Input Matrix:
```
1 0 1 0
1 1 1 0
1 1 1 0
```

#### Step-by-Step Calculation:

1. **Matrix Dimensions**:
   - (n = 3), (m = 4).

2. Traverse the matrix **from bottom-right to top-left**.

   - (i = 2, j = 3): (mat[2][3] = 0), no change.
   - (i = 2, j = 2): (mat[2][2] = 1), no change (last row).
   - (i = 2, j = 1): (mat[2][1] = 1), no change (last row).
   - (i = 2, j = 0): (mat[2][0] = 1), no change (last row).

   Update `maxi = 1`.

   - (i = 1, j = 3): (mat[1][3] = 0), no change.
   - (i = 1, j = 2): (mat[1][2] = 1), compute:
     `mat[1][2] = 1 + min(mat[2][2], mat[2][3], mat[1][3]) = 1`
   - (i = 1, j = 1): (mat[1][1] = 1), compute:
     `mat[1][1] = 1 + min(mat[2][1], mat[2][2], mat[1][2]) = 2`
   - (i = 1, j = 0): (mat[1][0] = 1), compute:
     `mat[1][0] = 1 + min(mat[2][0], mat[2][1], mat[1][1]) = 2`

   Update `maxi = 2`.

   - (i = 0, j = 3): (mat[0][3] = 0), no change.
   - (i = 0, j = 2): (mat[0][2] = 1), compute:
     `mat[0][2] = 1 + min(mat[1][2], mat[1][3], mat[0][3]) = 1`
   - (i = 0, j = 1): (mat[0][1] = 0), no change.
   - (i = 0, j = 0): (mat[0][0] = 1), compute:
     `mat[0][0] = 1 + min(mat[1][0], mat[1][1], mat[0][1]) = 1`

3. Final `maxi = 2`.

### **Complexity Analysis**

#### **Time Complexity**
- Each cell ((i, j)) is visited once.
- Total complexity: (O(n * m)), where (n) is the number of rows and (m) is the number of columns.

#### **Space Complexity**
- No additional space is used; the input matrix is modified in place.
- Total complexity: (O(1)).



### **Comparison with Space Optimization**

| Approach              | Time Complexity | Space Complexity | Comments                                       |
|---|---|---|---|
| Space Optimization    | (O(n * m)) | (O(m))         | Uses two 1D arrays for computation.           |
| In-Place Modification | (O(n * m)) | (O(1))         | Modifies the input matrix directly.           |



### **Advantages of In-Place Modification**
1. **Minimal Space Usage**:
   - Does not require additional memory, making it ideal for memory-constrained environments.

2. **Simple Implementation**:
   - Reuses the input matrix for storing results.

3. **Efficient for Large Matrices**:
   - Both time and space efficiency are maintained.



### **Final Output**

#### Input Matrix:
```
1 0 1 0
1 1 1 0
1 1 1 0
```

#### Output:
- Largest square size = **2**.
