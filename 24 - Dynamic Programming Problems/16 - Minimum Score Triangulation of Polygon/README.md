<h1 align="center">Minimum - Score - Triangulation of - Polygon</h1>

## Problem Statement

**Problem URL :** [Minimum Score Triangulation of Polygon](https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/)

![image](https://github.com/user-attachments/assets/a3585b56-58cd-4de1-b1a0-5b15834edb01)

### Problem Explanation

The problem "Minimum Score Triangulation of Polygon" involves dividing a convex polygon into triangles such that the sum of the scores of all triangles is minimized. The **score** of a triangle is defined as the product of the vertices of that triangle.

1. **Input**:
   - An integer array `values[]` of size (n), where (n geq 3).
   - Each element in `values[]` represents the value of a vertex of a convex polygon.

2. **Output**:
   - The minimum possible score from triangulating the polygon.

3. **Triangulation**:
   - A triangulation divides the polygon into non-overlapping triangles using diagonals.
   - The vertices of each triangle contribute to its score, calculated as:
     `{Score of Triangle} = {values[i]} * {values[j]} * {values[k]}`
     
   - where (i, j, k) are the vertices of the triangle.

4. **Goal**:
   - Minimize the sum of scores of all triangles.

### Example

#### Example 1
**Input**: `values = [1, 2, 3]`

**Explanation**:
- The polygon has only three vertices, forming a single triangle with vertices ([1, 2, 3]).
- The score of this triangle is:
  `1 * 2 * 3 = 6`
- **Output**: `6`

#### Example 2
**Input**: `values = [3, 7, 4, 5]`

**Explanation**:
1. Possible Triangulations:
   - Divide the polygon into two triangles:
     - Triangle 1: ([3, 7, 4]), Score: (3 * 7 * 4 = 84)
     - Triangle 2: ([3, 4, 5]), Score: (3 * 4 * 5 = 60)
     - Total Score: (84 + 60 = 144)

   - Alternatively:
     - Triangle 1: ([7, 4, 5]), Score: (7 * 4 * 5 = 140)
     - Triangle 2: ([3, 7, 5]), Score: (3 * 7 * 5 = 105)
     - Total Score: (140 + 105 = 245)

2. Minimum Score: (144)

**Output**: `144`

### Steps to Solve the Problem

To solve the problem, we use **dynamic programming (DP)**.

#### **Key Observations**
1. **Divide and Conquer**:
   - To minimize the score for the entire polygon, we should minimize the scores of smaller sub-polygons and combine them.
2. **Subproblems**:
   - For a polygon segment ([i, j]), divide it into two smaller sub-polygons by choosing a middle vertex (k) ((i < k < j)).
   - Calculate the score as:
     `{dp[i][j]} = minleft({dp[i][k]} + {dp[k][j]} + {values[i]} * {values[k]} * {values[j]})`
3. **Base Case**:
   - If a segment has fewer than three vertices ((j - i < 2)), no triangle can be formed, so ({dp[i][j]} = 0).

---

## Recursive Approach (caused TLE)
The problem asks to find the minimum score of triangulating a convex polygon. In triangulation, the polygon is divided into non-overlapping triangles, and the score of each triangle is the product of the values of its three vertices.

**Recursive Approach**:
- The polygon has `n` vertices, and the problem asks to calculate the minimum triangulation score by breaking the polygon into triangles.
- The key idea is to try dividing the polygon into two smaller sub-polygons using a diagonal (which will create two sub-problems), and then recursively calculate the minimum triangulation score for each of those sub-polygons.

Let's break down the recursive process:

1. **Base Case**:
   - If the segment `[i, j]` contains fewer than three vertices, no triangle can be formed. Therefore, the score for this segment is `0`.
   - This means that when `i + 1 == j`, no triangulation can be performed, and we return `0`.

2. **Recursive Case**:
   - We consider all possible ways to select a "middle" vertex `k` between `i` and `j`. This middle vertex divides the polygon into two sub-polygons: `[i, k]` and `[k, j]`.
   - For each possible `k`, calculate the score of the triangle formed by vertices `i`, `k`, and `j`. This score is the product `v[i] * v[k] * v[j]`.
   - Recursively calculate the scores for the sub-polygons `[i, k]` and `[k, j]`.
   - Add the score of the triangle formed by `i`, `k`, and `j` to the sum of the scores of the sub-polygons.
   - The goal is to minimize the total score by considering all possible `k` values.

3. **Return the Minimum**:
   - Out of all possible `k` values, we choose the one that gives the minimum triangulation score.

### Source Code
```cpp
class Solution {
public:
    // Recursive function to calculate the minimum score for triangulating the polygon
    // Parameters:
    // - v: vector containing the values of the vertices
    // - i: starting index of the segment
    // - j: ending index of the segment
    int solve(vector<int>& v, int i, int j) {
        // Base case: If the segment [i, j] has only two vertices, it cannot form a triangle
        if (i + 1 == j) return 0;

        int ans = INT_MAX; // Initialize the answer to the maximum possible value

        // Iterate through all possible middle vertices (k) between i and j
        for (int k = i + 1; k < j; k++) {
            // Calculate the score of forming a triangle with vertices i, k, and j
            // Add the scores of solving the two subproblems [i, k] and [k, j]
            ans = min(ans, v[i] * v[k] * v[j] + solve(v, i, k) + solve(v, k, j));
        }

        return ans; // Return the minimum score for the segment [i, j]
    }

    // Function to calculate the minimum score triangulation of the polygon
    int minScoreTriangulation(vector<int>& values) {
        // Call the recursive helper function on the entire polygon
        return solve(values, 0, values.size() - 1);
    }
};
```
### Source Code Explanation

#### 1. **Recursive Function: `solve()`**
```cpp
int solve(vector<int>& v, int i, int j) {
```
- This function computes the minimum triangulation score for the polygon segment defined by indices `i` and `j`. `v` is the vector containing the values of the vertices.

#### 2. **Base Case:**
```cpp
if (i + 1 == j) return 0;
```
- If the segment `[i, j]` has fewer than three vertices (i.e., `i + 1 == j`), then it cannot form a triangle. Therefore, the score is `0`.

#### 3. **Initialize the Answer to Maximum:**
```cpp
int ans = INT_MAX;
```
- `ans` is initialized to the maximum possible value. This will be used to store the minimum score found while iterating through all possible middle vertices `k`.

#### 4. **Loop Over Possible Middle Vertices (k):**
```cpp
for (int k = i + 1; k < j; k++) {
```
- We iterate over all possible middle vertices `k` between `i` and `j`. The middle vertex `k` divides the polygon segment `[i, j]` into two smaller segments `[i, k]` and `[k, j]`.

#### 5. **Calculate the Score of Forming Triangle (i, k, j):**
```cpp
ans = min(ans, v[i] * v[k] * v[j] + solve(v, i, k) + solve(v, k, j));
```
- For each middle vertex `k`, calculate the score of the triangle formed by `i`, `k`, and `j`. The score of this triangle is `v[i] * v[k] * v[j]`.
- We then recursively calculate the minimum triangulation score for the sub-polygons `[i, k]` and `[k, j]` using `solve(v, i, k)` and `solve(v, k, j)`.
- We update `ans` to be the minimum score found.

#### 6. **Return the Minimum Score for Segment [i, j]:**
```cpp
return ans;
```
- Once the loop completes, we return the minimum score for the segment `[i, j]`.


### **Main Function: `minScoreTriangulation()`**
```cpp
int minScoreTriangulation(vector<int>& values) {
```
- This function is the entry point for solving the problem. It calls the recursive helper function `solve()` on the entire polygon (from index `0` to `n-1`).

```cpp
return solve(values, 0, values.size() - 1);
```
- It calls the `solve()` function on the whole polygon and returns the result.

### **Example Walkthrough**

Let's consider the example `values = [1, 2, 3]`.

1. **Base Case**: 
   - The polygon has only 3 vertices, so we only need to form one triangle: `[1, 2, 3]`.
   - The score of this triangle is:
     `1 * 2 * 3 = 6`
   - The minimum score is `6`, so the function returns `6`.

**Example 2**: `values = [3, 7, 4, 5]`

1. **Recursive Case**:
   - We start with `i = 0` and `j = 3` (the entire polygon).
   - Try different values of `k`:
     - For `k = 1`: Divide into sub-polygons `[0, 1]` and `[1, 3]`.
       - Sub-problem `[0, 1]` (base case, score = 0).
       - Sub-problem `[1, 3]` (score = 140).
       - Total score = `3 * 7 * 5 + 0 + 140 = 245`.
     - For `k = 2`: Divide into sub-polygons `[0, 2]` and `[2, 3]`.
       - Sub-problem `[0, 2]` (score = 84).
       - Sub-problem `[2, 3]` (score = 0).
       - Total score = `3 * 4 * 5 + 84 + 0 = 144`.
   - The minimum score is `144`, so the function returns `144`.

**Output**: `144`.

### **Time and Space Complexities**

#### Time Complexity:
- **Recursive function calls**: The `solve()` function makes a recursive call for every sub-problem formed by a segment `[i, j]`. For a polygon with `n` vertices, there are (O(n^2)) such sub-problems (since we are interested in every pair of vertices `i` and `j`).
- **Loop for `k`**: For each sub-problem, we try all possible middle vertices `k` between `i` and `j`. This means we have to do (O(n)) operations for each sub-problem.
- Therefore, the overall time complexity is (O(n^3)).

#### Space Complexity:
- **Recursive Call Stack**: The depth of the recursion is at most (O(n)), since we're breaking the problem down by choosing sub-polygons, and there are at most (n) vertices.
- **Memoization (if used)**: The space complexity for storing the DP table would be (O(n^2)), but since this solution does not explicitly store the results in a DP table, we rely on the recursion stack.

Thus, the space complexity is (O(n)) due to the recursion depth.

**Conclusion**:
- The time complexity of the recursive approach is (O(n^3)).
- The space complexity is (O(n)) due to recursion.

---

## Top-Down Approach (DP)
The top-down dynamic programming approach is an optimization of the previous recursive solution using memoization. The idea is to avoid recalculating the same subproblems multiple * by storing the results of subproblems in a `dp` table. Here's the breakdown of how the approach works:

1. **Base Case**:
   - As before, if the segment `[i, j]` contains fewer than three vertices, it cannot form a triangle, so the score for this segment is `0`.
   - When `i + 1 == j`, return `0` because no triangle can be formed.

2. **Memoization**:
   - Before performing any recursive calls, we check if the result for a given segment `[i, j]` is already stored in the `dp` table. If it's not `-1`, it means we have already computed it, so we can directly return the stored result.

3. **Recursive Case**:
   - If the result is not already computed, we calculate the score for the segment `[i, j]` by iterating through all possible middle vertices `k` between `i` and `j`.
   - For each `k`, we compute the score of forming a triangle with vertices `i`, `k`, and `j`, and recursively calculate the triangulation scores for the sub-polygons `[i, k]` and `[k, j]`.
   - We then store the result in the `dp` table and return the minimum triangulation score for the segment `[i, j]`.

4. **Final Answer**:
   - The final answer is found by calling the `solve()` function on the entire polygon, from vertex `0` to vertex `n-1`.

### Source Code
```cpp
class Solution {
public:
    // Recursive function with memoization to calculate the minimum score for triangulating the polygon
    // Parameters:
    // - v: vector containing the values of the vertices
    // - i: starting index of the segment
    // - j: ending index of the segment
    // - dp: 2D vector to store previously computed results for subproblems
    int solve(vector<int>& v, int i, int j, vector<vector<int>>& dp) {
        // Base case: If the segment [i, j] has only two vertices, it cannot form a triangle
        if (i + 1 == j) return 0;

        // If the result for this subproblem is already computed, return it
        if (dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX; // Initialize the answer to the maximum possible value

        // Iterate through all possible middle vertices (k) between i and j
        for (int k = i + 1; k < j; k++) {
            // Calculate the score of forming a triangle with vertices i, k, and j
            // Add the scores of solving the two subproblems [i, k] and [k, j]
            ans = min(ans, v[i] * v[k] * v[j] + solve(v, i, k, dp) + solve(v, k, j, dp));
        }

        // Store the computed result for the segment [i, j] in the dp table
        return dp[i][j] = ans;
    }

    // Function to calculate the minimum score triangulation of the polygon
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size(); // Number of vertices in the polygon

        // Initialize a dp table with -1 to indicate uncomputed results
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        // Call the recursive helper function on the entire polygon
        return solve(values, 0, n - 1, dp);
    }
};
```
### Source Code Explanation

#### 1. **Recursive Function with Memoization: `solve()`**
```cpp
int solve(vector<int>& v, int i, int j, vector<vector<int>>& dp) {
```
- This is the recursive function that calculates the minimum triangulation score for the segment `[i, j]` of the polygon. The `dp` table is used to store previously computed results to avoid redundant calculations.

#### 2. **Base Case**:
```cpp
if (i + 1 == j) return 0;
```
- If the segment `[i, j]` contains fewer than three vertices (`i + 1 == j`), no triangle can be formed, so the score is `0`.

#### 3. **Memoization Check**:
```cpp
if (dp[i][j] != -1) return dp[i][j];
```
- Before performing any calculations, we check if the result for the subproblem `[i, j]` has already been computed. If the value is not `-1`, we return the stored result from the `dp` table.

#### 4. **Initialize Answer to Maximum**:
```cpp
int ans = INT_MAX;
```
- We initialize the answer `ans` to the maximum possible value. This will be used to store the minimum triangulation score as we iterate through different possible middle vertices `k`.

#### 5. **Loop Over Possible Middle Vertices (k)**:
```cpp
for (int k = i + 1; k < j; k++) {
```
- We iterate through all possible middle vertices `k` between `i` and `j`. The middle vertex `k` divides the polygon into two smaller sub-polygons: `[i, k]` and `[k, j]`.

#### 6. **Calculate the Score of Forming Triangle (i, k, j)**:
```cpp
ans = min(ans, v[i] * v[k] * v[j] + solve(v, i, k, dp) + solve(v, k, j, dp));
```
- For each middle vertex `k`, we calculate the score of the triangle formed by vertices `i`, `k`, and `j`, which is `v[i] * v[k] * v[j]`.
- We then recursively calculate the minimum triangulation score for the two sub-polygons: `[i, k]` and `[k, j]` using `solve(v, i, k, dp)` and `solve(v, k, j, dp)`.
- We update `ans` with the minimum of the current `ans` and the sum of the triangle score and the two subproblem scores.

#### 7. **Store the Computed Result in the DP Table**:
```cpp
return dp[i][j] = ans;
```
- After iterating through all possible middle vertices `k`, we store the minimum triangulation score for the segment `[i, j]` in the `dp` table and return it.

### **Main Function: `minScoreTriangulation()`**
```cpp
int minScoreTriangulation(vector<int>& values) {
```
- This function is the entry point for solving the problem. It initializes the `dp` table and calls the recursive function `solve()` on the entire polygon (from index `0` to `n-1`).

```cpp
int n = values.size();
```
- We get the number of vertices `n` in the polygon.

```cpp
vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
```
- We initialize the `dp` table, a 2D vector of size `(n+1) x (n+1)`. Each element is initialized to `-1`, which indicates that the result for that subproblem has not been computed yet.

```cpp
return solve(values, 0, n - 1, dp);
```
- We call the `solve()` function on the entire polygon, from vertex `0` to vertex `n-1`, and return the result.

### **Example Walkthrough**

Let's consider the example `values = [1, 2, 3]`.

1. **Base Case**:
   - The polygon has only three vertices, so we only need to form one triangle: `[1, 2, 3]`.
   - The score of this triangle is:
     `1 * 2 * 3 = 6`
   - The minimum score is `6`, so the function returns `6`.

**Example 2**: `values = [3, 7, 4, 5]`

1. **Recursive Case**:
   - We start with `i = 0` and `j = 3` (the entire polygon).
   - Try different values of `k`:
     - For `k = 1`: Divide into sub-polygons `[0, 1]` and `[1, 3]`.
       - Sub-problem `[0, 1]` (base case, score = 0).
       - Sub-problem `[1, 3]` (score = 140).
       - Total score = `3 * 7 * 5 + 0 + 140 = 245`.
     - For `k = 2`: Divide into sub-polygons `[0, 2]` and `[2, 3]`.
       - Sub-problem `[0, 2]` (score = 84).
       - Sub-problem `[2, 3]` (score = 0).
       - Total score = `3 * 4 * 5 + 84 + 0 = 144`.
   - The minimum score is `144`, so the function returns `144`.

**Output**: `144`.

### **Time and Space Complexities**

#### Time Complexity:
- **Memoization**: The `dp` table stores results for each subproblem `[i, j]`. There are (O(n^2)) possible subproblems.
- **Recursive Function Calls**: For each subproblem `[i, j]`, we iterate over all possible middle vertices `k`, which takes (O(n)) operations.
- Therefore, the overall time complexity is (O(n^3)), because for each of the (O(n^2)) subproblems, we do (O(n)) work to find the minimum score.

#### Space Complexity:
- **DP Table**: The `dp` table is a 2D vector of size ((n+1) * (n+1)), which requires (O(n^2)) space to store the results of the subproblems.
- **Recursive Call Stack**: The depth of the recursion is at most (O(n)), as we break down the problem into smaller sub-problems each time.
- Therefore, the overall space complexity is (O(n^2)).


**Conclusion**:
- The time complexity of the top-down dynamic programming approach is (O(n^3)).
- The space complexity is (O(n^2)) due to the `dp` table and recursive call stack.

---

## Bottom-Up Approach (DP)
The bottom-up dynamic programming (DP) approach is an iterative approach that avoids recursion and solves the problem by progressively solving smaller subproblems. The idea is to fill a DP table where each entry represents the minimum triangulation score for a subpolygon, starting from the smallest subpolygons and gradually building up to the entire polygon. Here's the breakdown of how the bottom-up approach works:

1. **DP Table Setup**:
   - We create a 2D DP table `dp[i][j]`, where `dp[i][j]` represents the minimum score for triangulating the polygon formed by the vertices from index `i` to index `j`.
   - The table is initialized with zeros, and the base case of a segment with fewer than three vertices is implicitly handled by the structure of the solution.

2. **Iterative Calculation**:
   - We solve the problem iteratively by solving for smaller subpolygons first and using these results to build up the solution for larger subpolygons.
   - The outer loop iterates over all possible starting indices `i`, and the inner loop iterates over all possible ending indices `j` such that the segment `[i, j]` has more than two vertices.
   - For each segment `[i, j]`, we iterate over all possible middle vertices `k` between `i` and `j`, and for each `k`, we calculate the score of forming a triangle with vertices `i`, `k`, and `j` and combine it with the results of the subproblems `[i, k]` and `[k, j]`.

3. **Final Result**:
   - The final result is stored in `dp[0][n-1]`, which represents the minimum score triangulation for the entire polygon (from vertex `0` to vertex `n-1`).

### Source Code
```cpp
class Solution {
public:
    // Function to calculate the minimum score triangulation of the polygon using bottom-up DP
    int solve(vector<int>& v) {
        int n = v.size(); // Number of vertices in the polygon

        // DP table where dp[i][j] represents the minimum score for triangulating the segment [i, j]
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Iterate over all possible starting indices in reverse (bottom-up DP)
        for (int i = n - 1; i >= 0; i--) {
            // Iterate over all possible ending indices for segments larger than 2 vertices
            for (int j = i + 2; j < n; j++) {
                int ans = INT_MAX; // Initialize the minimum score for the segment [i, j]

                // Try every possible middle vertex k between i and j
                for (int k = i + 1; k < j; k++) {
                    // Calculate the score of forming a triangle (i, k, j) and add subproblem scores
                    ans = min(ans, v[i] * v[j] * v[k] + dp[i][k] + dp[k][j]);
                }

                // Store the minimum score for the segment [i, j]
                dp[i][j] = ans;
            }
        }

        // The final result is stored in dp[0][n-1], which represents the entire polygon
        return dp[0][n - 1];
    }

    // Main function to calculate the minimum score triangulation
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size(); // Number of vertices in the polygon

        // Call the DP function
        return solve(values);
    }
};
```

### Source Code Explanation

#### 1. **Bottom-Up DP Function: `solve()`**
```cpp
int solve(vector<int>& v) {
```
- This function calculates the minimum triangulation score for the polygon. It uses bottom-up dynamic programming to iteratively solve smaller subproblems and build up to the solution for the entire polygon.

#### 2. **Number of Vertices:**
```cpp
int n = v.size();
```
- We store the number of vertices `n` in the polygon.

#### 3. **Initialize DP Table:**
```cpp
vector<vector<int>> dp(n, vector<int>(n, 0));
```
- We create a 2D DP table `dp`, where `dp[i][j]` stores the minimum triangulation score for the segment `[i, j]`. Initially, all values are set to `0` since the base case (segments of fewer than three vertices) is implicitly handled.

#### 4. **Iterate Over All Segments:**
```cpp
for (int i = n - 1; i >= 0; i--) {
```
- We start iterating over all possible starting indices `i` for the segments, going from right to left (`n-1` to `0`). This is the bottom-up approach, where we begin by solving for smaller subsegments.

#### 5. **Iterate Over Possible End Indices:**
```cpp
for (int j = i + 2; j < n; j++) {
```
- For each starting index `i`, we iterate over all possible ending indices `j` for segments of length greater than or equal to three. We ensure that `j` is at least two indices ahead of `i` to form a valid segment that can have a triangle.

#### 6. **Initialize the Minimum Answer:**
```cpp
int ans = INT_MAX;
```
- We initialize the variable `ans` to the maximum possible value (`INT_MAX`). This will store the minimum triangulation score for the segment `[i, j]`.

#### 7. **Iterate Over Possible Middle Vertices (k):**
```cpp
for (int k = i + 1; k < j; k++) {
```
- We iterate over all possible middle vertices `k` between `i` and `j`. The vertex `k` splits the polygon into two smaller subpolygons: `[i, k]` and `[k, j]`.

#### 8. **Calculate the Score of Forming Triangle (i, k, j):**
```cpp
ans = min(ans, v[i] * v[j] * v[k] + dp[i][k] + dp[k][j]);
```
- For each middle vertex `k`, we calculate the score of forming a triangle with vertices `i`, `k`, and `j`, which is `v[i] * v[j] * v[k]`.
- We then add the results of the two subproblems `[i, k]` and `[k, j]`, which are stored in `dp[i][k]` and `dp[k][j]`, respectively.
- We update `ans` to store the minimum triangulation score for the segment `[i, j]`.

#### 9. **Store the Minimum Result in DP Table:**
```cpp
dp[i][j] = ans;
```
- After iterating over all possible middle vertices `k`, we store the minimum triangulation score for the segment `[i, j]` in `dp[i][j]`.

#### 10. **Return Final Result:**
```cpp
return dp[0][n - 1];
```
- After completing the bottom-up DP calculation, the final result is stored in `dp[0][n-1]`, which represents the minimum triangulation score for the entire polygon. We return this value as the result.

### **Main Function: `minScoreTriangulation()`**
```cpp
int minScoreTriangulation(vector<int>& values) {
    int n = values.size();
    return solve(values);
}
```
- This is the main function that serves as an entry point to solve the problem.
- It first retrieves the number of vertices `n` in the polygon and then calls the `solve()` function to calculate the minimum triangulation score for the polygon.

### **Example Walkthrough**

Let's consider the example `values = [1, 2, 3]`.

1. **Base Case**:
   - The polygon has only three vertices, so we only need to form one triangle: `[1, 2, 3]`.
   - The score of this triangle is:
     `1 * 2 * 3 = 6`
   - The minimum score is `6`, so the function returns `6`.

**Example 2**: `values = [3, 7, 4, 5]`

1. **Iterative Calculation**:
   - We solve for smaller segments first and use these results to build up to the solution for the entire polygon.
   - For the segment `[0, 3]`:
     - Try middle vertex `k = 1`: Divide into subsegments `[0, 1]` and `[1, 3]`.
       - Sub-problem `[0, 1]` (score = 0).
       - Sub-problem `[1, 3]` (score = 140).
       - Total score = `3 * 7 * 5 + 0 + 140 = 245`.
     - Try middle vertex `k = 2`: Divide into subsegments `[0, 2]` and `[2, 3]`.
       - Sub-problem `[0, 2]` (score = 84).
       - Sub-problem `[2, 3]` (score = 0).
       - Total score = `3 * 4 * 5 + 84 + 0 = 144`.
   - The minimum score for the segment `[0, 3]` is `144`.

**Output**: `144`.


### **Time and Space Complexities**

#### Time Complexity:
- **DP Table**: The `dp` table stores results for each subproblem `[i, j]`. There are (O(n^2)) possible subproblems.
- **Iterative Calculation**: For each subproblem `[i, j]`, we iterate over all possible middle vertices `k`, which takes (O(n)) operations.
- Therefore, the overall time complexity is (O(n^3)), because for each of the (O(n^2)) subproblems, we do (O(n)) work to find the minimum score.

#### Space Complexity:
- **DP Table**: The `dp` table is a 2D vector of size (n * n), which requires (O(n^2)) space to store the results of the subproblems.
- Therefore, the overall space complexity is (O(n^2)).


**Conclusion**:
- The time complexity of the bottom-up dynamic programming approach is (O(n^3)).
- The space complexity is (O(n^2)) due to the `dp` table used to store the results of subproblems.

---

## Gap Strategy (DP)
The **Gap Strategy** is a dynamic programming (DP) approach that optimizes the solution to the polygon triangulation problem by iterating over the "gap" between the vertices. This approach leverages the fact that to form a valid triangle, the subpolygon formed by the vertices must have at least 3 vertices, which can be efficiently handled using gaps. This strategy focuses on progressively solving subproblems by considering increasing gaps between the vertices and building up to the solution for the entire polygon.

1. **Gap Definition**:
   - The "gap" is the difference in indices between the starting and ending vertices of a polygon segment. The gap defines how many vertices are in between the starting and ending vertices of a polygonal subproblem.
   - For example, for a segment `[i, j]`, if `j = i + 2`, the gap is 2, meaning the segment has 3 vertices (enough to form a triangle).
   - The outer loop iterates over increasing gaps, solving for segments with smaller gaps first and gradually moving to larger segments.

2. **DP Table Setup**:
   - We create a 2D DP table `dp[i][j]`, where `dp[i][j]` stores the minimum score for triangulating the polygon formed by vertices from index `i` to `j`.
   - Initially, `dp[i][j]` is set to 0 for all pairs where `i + 1 == j`, as these segments cannot form a valid triangle (they are just edges).

3. **Iterative Calculation**:
   - The outer loop iterates over all possible gap values starting from 2 (since a gap of 2 is the minimum gap to form a triangle) up to `n-1` (where `n` is the number of vertices).
   - The inner loop iterates over all possible starting indices `i` for a given gap. For each gap and starting index `i`, we compute the corresponding ending index `j = i + gap`.
   - For each segment `[i, j]`, the middle vertex `k` is iterated from `i + 1` to `j - 1`. For each middle vertex `k`, we calculate the score of forming a triangle with vertices `i`, `k`, and `j` and combine it with the subproblems `[i, k]` and `[k, j]`.

4. **Final Result**:
   - The final result is stored in `dp[0][n-1]`, which represents the minimum triangulation score for the entire polygon (from vertex 0 to vertex `n-1`).

### Source Code
```cpp
class Solution {
public:
    // Gap Strategy Implementation for Minimum Score Triangulation
    int solve(vector<int>& v) {
        int n = v.size(); // Number of vertices in the polygon

        // DP table where dp[i][j] represents the minimum score for triangulating the segment [i, j]
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Outer loop controls the gap between i and j
        // Gap of 2 means the segment [i, j] has at least 3 vertices, enough to form a triangle
        for (int gap = 2; gap < n; gap++) {
            // Inner loop iterates over all valid starting indices i for a given gap
            for (int i = 0; i + gap < n; i++) {
                int j = i + gap; // Calculate the ending index j based on the gap

                dp[i][j] = INT_MAX; // Initialize dp[i][j] to the maximum value

                // Iterate over all possible middle vertices (k) between i and j
                for (int k = i + 1; k < j; k++) {
                    // Calculate the score of forming a triangle (i, k, j)
                    // Add the scores of solving the two subproblems [i, k] and [k, j]
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + v[i] * v[k] * v[j]);
                }
            }
        }

        // The final result is stored in dp[0][n-1], which represents the entire polygon
        return dp[0][n - 1];
    }

    // Main function to calculate the minimum score triangulation
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size(); // Number of vertices in the polygon
        return solve(values); // Call the gap strategy function
    }
};

```
### Source Code Explanation

#### 1. **Gap Strategy Function: `solve()`**
```cpp
int solve(vector<int>& v) {
```
- This function calculates the minimum triangulation score for the polygon using the gap strategy.

#### 2. **Number of Vertices:**
```cpp
int n = v.size();
```
- We store the number of vertices `n` in the polygon.

#### 3. **Initialize DP Table:**
```cpp
vector<vector<int>> dp(n, vector<int>(n, 0));
```
- We create a 2D DP table `dp`, where `dp[i][j]` stores the minimum triangulation score for the segment `[i, j]`. Initially, all values are set to `0`.

#### 4. **Outer Loop Over Gaps:**
```cpp
for (int gap = 2; gap < n; gap++) {
```
- The outer loop controls the gap between `i` and `j`. The loop starts from `gap = 2`, which is the smallest gap that can form a triangle (a segment of 3 vertices), and goes up to `n - 1`.

#### 5. **Inner Loop Over Starting Indices (i):**
```cpp
for (int i = 0; i + gap < n; i++) {
```
- The inner loop iterates over all possible starting indices `i` for a given gap. For each gap, the loop ensures that `i + gap` (the end index `j`) is within the bounds of the polygon.

#### 6. **Calculate Ending Index (j):**
```cpp
int j = i + gap;
```
- For each starting index `i` and gap, we calculate the corresponding ending index `j = i + gap`.

#### 7. **Initialize Minimum Score for Segment `[i, j]`:**
```cpp
dp[i][j] = INT_MAX;
```
- We initialize `dp[i][j]` to the maximum possible value (`INT_MAX`) to find the minimum triangulation score for the segment `[i, j]`.

#### 8. **Iterate Over Possible Middle Vertices (k):**
```cpp
for (int k = i + 1; k < j; k++) {
```
- We iterate over all possible middle vertices `k` between `i` and `j`. These vertices divide the polygon into two smaller subproblems: `[i, k]` and `[k, j]`.

#### 9. **Calculate the Score for Triangle (i, k, j):**
```cpp
dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + v[i] * v[k] * v[j]);
```
- For each middle vertex `k`, we calculate the score of forming a triangle with vertices `i`, `k`, and `j`, which is `v[i] * v[k] * v[j]`.
- We then add the results of solving the two subproblems `[i, k]` and `[k, j]`, which are stored in `dp[i][k]` and `dp[k][j]`, respectively.
- We update `dp[i][j]` to store the minimum score for triangulating the segment `[i, j]`.

#### 10. **Return Final Result:**
```cpp
return dp[0][n - 1];
```
- After completing the gap strategy calculation, the final result is stored in `dp[0][n-1]`, which represents the minimum triangulation score for the entire polygon. We return this value as the result.

### **Main Function: `minScoreTriangulation()`**
```cpp
int minScoreTriangulation(vector<int>& values) {
    int n = values.size();
    return solve(values);
}
```
- This is the main function that serves as an entry point to solve the problem.
- It first retrieves the number of vertices `n` in the polygon and then calls the `solve()` function to calculate the minimum triangulation score for the polygon.

### **Example Walkthrough**

Let's consider the example `values = [1, 2, 3]`.

1. **Base Case**:
   - The polygon has only three vertices, so we only need to form one triangle: `[1, 2, 3]`.
   - The score of this triangle is:
     `1 * 2 * 3 = 6`
   - The minimum score is `6`, so the function returns `6`.

**Example 2**: `values = [3, 7, 4, 5]`

1. **Iterative Calculation**:
   - The outer loop begins with `gap = 2`, which means we are solving for segments of 3 vertices.
   - For the segment `[0, 2]`:
     - We try middle vertex `k = 1`: The score of forming a triangle is `3 * 7 * 4 = 84`.
     - For the subproblems `[0, 1]` and `[1, 2]`, both are just edges, so their scores are `0`.
     - The total score for segment `[0, 2]` is `84`.
   - The outer loop continues with larger gaps, calculating triangulation scores for bigger segments until it reaches the entire polygon `[0, 3]`.

**Output**: The final triangulation score for the polygon `[3, 7, 4, 5]` is calculated and returned as `144`.

### **Time and Space Complexities**

#### Time Complexity:
- **Outer Loop Over Gaps**: The outer loop iterates over gaps from 2 to (n - 1), so it runs (O(n)) *.
- **Inner Loop Over Starting Indices**: For each gap, the inner loop iterates over possible starting indices `i`, which takes (O(n)) time.
- **Middle Loop Over Vertices `k`**: For each segment `[i, j]`, we iterate over all possible middle vertices `k`, which takes (O(n)) time.
- Therefore, the overall time complexity is (O(n^3)), since for each gap (O(n)), we check all possible starting indices (O(n)), and for each pair `[i, j]`, we check all middle vertices (O(n)).

#### Space Complexity:
- **DP Table**: The `dp` table is a 2D vector of size (n * n), which requires (O(n^2)) space to store the results of the subproblems.
- Therefore, the overall space complexity is (O(n^2)).

**Conclusion**:
- The time complexity of the gap strategy approach is (O(n^3)).
- The space complexity is (O(n^2)) due to the `dp` table used to store the results of subproblems.

## Space Optimization (Not Possible)
Space optimization is often a crucial concern when solving dynamic programming (DP) problems. For some problems, we can reduce the space complexity by observing that we do not need to store the results for all subproblems simultaneously. However, in the case of **minimum score triangulation**, space optimization is not easily achievable due to the nature of the problem and the dependencies between subproblems.

Let's break down why space optimization is difficult for this problem using a step-by-step approach and an example.

### **Why Space Optimization is Challenging**

1. **Full DP Table Dependency**:
   In the gap strategy, the 2D DP table (`dp[i][j]`) stores the minimum score for triangulating the polygon formed by the vertices from index `i` to index `j`. Each subproblem depends on two smaller subproblems: `[i, k]` and `[k, j]`, where `k` is a middle vertex that lies between `i` and `j`.

2. **Overlap of Subproblems**:
   - When solving for `dp[i][j]`, the solution relies on the previous subproblems like `dp[i][k]` and `dp[k][j]`. These subproblems might overlap, but they are not easily reducible because every subproblem contributes to solving a different range of segments.
   - Unlike problems where we can use results from only the current or previous row/column (like in the Fibonacci sequence), here each result depends on multiple previous results, making it hard to optimize space.

3. **No Simple Reduction**:
   - The current solution is based on the fact that we need to solve each subproblem for every possible segment `[i, j]`. The value of `dp[i][j]` is calculated by iterating over all middle vertices `k` between `i` and `j`.
   - If we tried to reduce the space by keeping only one or two rows/columns (as in some DP problems), we'd lose essential information for other subproblems. For example, to compute `dp[i][j]`, we need results from all possible `k` values, and for those `k` values, we need results for both `[i, k]` and `[k, j]`.


### **Example to Illustrate the Space Dependency**

Let's consider a polygon with 4 vertices: `values = [3, 7, 4, 5]`.

#### Step-by-Step Computation:
1. **Base Case**:
   - For `dp[i][j]` where `j = i + 1`, there are no valid triangles, so `dp[i][j] = 0`.

2. **For Gap = 2** (3 vertices):
   - The segment `[0, 2]` has vertices `3, 7, 4`. We need to compute the score for triangulating this segment.
   - The only valid triangle is formed by vertices `(0, 1, 2)`, with score `3 * 7 * 4 = 84`.
   - Thus, `dp[0][2] = 84`.

3. **For Gap = 3** (4 vertices):
   - Now we want to compute `dp[0][3]` (the entire polygon).
   - We need to compute `dp[0][3]` using middle vertex `k = 1` and `k = 2`.
     - For `k = 1`: We calculate the subproblems `dp[0][1]` and `dp[1][3]`, both of which are already computed or can be derived.
     - For `k = 2`: We calculate the subproblems `dp[0][2]` and `dp[2][3]`.

In each case, the results from previous subproblems are used to calculate the new subproblem. This "cumulative" nature of DP, where each value depends on multiple smaller subproblems, means we cannot easily discard older values (like we might do in simpler problems where the DP table only depends on the previous row/column).

### **Why We Can't Optimize Space Easily**
1. **Multiple Dependencies**:
   - For `dp[i][j]`, we need results from both subproblems `[i, k]` and `[k, j]`. The middle vertex `k` is different for every possible pair `(i, j)`, and each combination may depend on previous values that are not easily reducible to a smaller table.

2. **No Clear Row/Column Reusability**:
   - In problems like Fibonacci, the value at `dp[i][j]` only depends on the previous value (e.g., `dp[i-1]`), so we can optimize the space by keeping only the current and previous rows. 
   - But in triangulation, each `dp[i][j]` depends on a combination of previous values from different parts of the DP table, making it impossible to reduce the space without losing critical information.

### **Conclusion**

For the **minimum score triangulation** problem, space optimization is not possible because:
- The solution to each subproblem depends on many different parts of the DP table (not just the previous row/column).
- Reducing the space by keeping only a subset of results would prevent us from accessing the necessary subproblem solutions.
- The complexity of calculating each `dp[i][j]` requires information from a variety of previous subproblems that cannot be condensed into a smaller structure without compromising the solution.

Thus, we need the full DP table to store all intermediate results and ensure the correct triangulation scores are computed.
