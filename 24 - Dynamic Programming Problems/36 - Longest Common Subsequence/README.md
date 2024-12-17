<h1 align="center">Longest - Common - Subsequence</h1>

## Problem Statement

**Problem URL :** [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/description/)

![image](https://github.com/user-attachments/assets/10750347-2b53-4638-a907-d9e89802e31b)

### Problem Explanation
The **Longest Common Subsequence** problem is a classic dynamic programming problem. Here’s a detailed explanation:

Given two strings `text1` and `text2`, return the **length** of their longest common subsequence.

A **subsequence** of a string is a sequence of characters that appears in the same order as the original string but not necessarily consecutively. For example:
- "abc" is a subsequence of "ahbgdc".
- "axc" is not a subsequence of "ahbgdc".

A **common subsequence** is a subsequence that appears in both strings.

The task is to find the **longest** subsequence common to both strings.

### **Constraints**
1. The length of `text1` and `text2` can be up to 1000.
2. The strings consist only of lowercase English letters.

### **Example 1**

#### Input:
```plaintext
text1 = "abcde"
text2 = "ace"
```

#### Output:
```plaintext
3
```

#### Explanation:
The **longest common subsequence** is "ace", which has a length of 3.  
Subsequences "a", "c", and "e" appear in both strings in the same relative order, even though they're not consecutive in `text1`.

### **Example 2**

#### Input:
```plaintext
text1 = "abc"
text2 = "def"
```

#### Output:
```plaintext
0
```

#### Explanation:
There is no common subsequence between "abc" and "def".  
Thus, the length of the longest common subsequence is `0`.



### **Example 3**

#### Input:
```plaintext
text1 = "bl"
text2 = "yby"
```

#### Output:
```plaintext
1
```

#### Explanation:
The **longest common subsequence** is "b", which appears in both strings.  
The length is `1`.

### **How to Solve the Problem**
1. **Recursive Approach**:
   - Compare the current characters of the strings.
   - If the characters match, the subsequence length increases by 1.
   - If they don't match, explore two possibilities:
     - Skip the current character of `text1`.
     - Skip the current character of `text2`.
   - Use the maximum of the two possibilities.

2. **Dynamic Programming Approach**:
   - Use a 2D table where `dp[i][j]` represents the length of the longest common subsequence for `text1[0...i]` and `text2[0...j]`.
   - Fill the table bottom-up based on whether characters match or not.

### **Why is This Problem Important?**
The Longest Common Subsequence (LCS) problem has many practical applications:
- **Version Control Systems**: To find differences between file versions.
- **Bioinformatics**: To compare DNA or protein sequences.
- **Spell Checkers and Text Similarity**: To measure how similar two texts are.

Let me know if you'd like further details about solving this problem!

---

## Recursive Approach (caused TLE)
The recursive approach to solving the **Longest Common Subsequence (LCS)** problem works as follows:

1. **Problem Breakdown**:
   - Compare the characters at the current indices (`i` in `text1` and `j` in `text2`).
   - If the characters match:
     - Include them in the LCS and move to the next indices (`i+1` and `j+1`).
   - If the characters do not match:
     - Explore two possibilities:
       - Skip the character from `text1` and keep the character from `text2`.
       - Skip the character from `text2` and keep the character from `text1`.
     - Take the maximum LCS length of the two possibilities.

2. **Base Case**:
   - If either string is fully traversed (`i >= length of text1` or `j >= length of text2`), return 0 because no subsequence is possible.

3. **Recursive Formula**:
   - If `text1[i] == text2[j]`:  
     `LCS(i, j) = 1 + LCS(i+1, j+1)`
     
   - If `text1[i] != text2[j]`:  
     `LCS(i, j) = max(LCS(i+1, j), LCS(i, j+1))`



### **Example Walkthrough**

#### Input:
```plaintext
text1 = "abcde"
text2 = "ace"
```

#### Steps:
1. Compare `text1[0]` ('a') with `text2[0]` ('a'):
   - They match, so include 'a' in the LCS and solve for the remaining strings:
     `LCS("abcde", "ace") = 1 + LCS("bcde", "ce")`

2. Compare `text1[1]` ('b') with `text2[1]` ('c'):
   - They don’t match, so explore two options:
     - Skip 'b' in `text1`:
       ` LCS("bcde", "ce") = LCS("cde", "ce")`
       
     - Skip 'c' in `text2`:
      `LCS("bcde", "ce") = LCS("bcde", "e")`

     - Take the maximum of these two.

3. Continue recursively until the strings are fully traversed.

#### Output:
The LCS is "ace", and its length is 3.

### Source Code
```cpp
class Solution {
public:
    // Helper function to recursively find the length of the longest common subsequence
    int solve(string &text1, string &text2, int i, int j) {
        // Base case: if either string is exhausted, no subsequence is possible
        if (i >= text1.length() || j >= text2.length()) return 0;
        
        int ans = 0; // Initialize the answer for the current state

        // Case 1: Characters match, include them in the subsequence
        if (text1[i] == text2[j]) 
            return 1 + solve(text1, text2, i + 1, j + 1);
        else {
            // Case 2: Characters don't match, explore two possibilities:
            // a) Skip the current character of text1
            // b) Skip the current character of text2
            // Take the maximum of these two possibilities
            ans = max(solve(text1, text2, i + 1, j), solve(text1, text2, i, j + 1));
        }
        
        return ans; // Return the result for the current state
    }

    // Main function to compute the longest common subsequence
    int longestCommonSubsequence(string text1, string text2) {
        // Start the recursive computation from the beginning of both strings
        return solve(text1, text2, 0, 0);
    }
};
```

### Source Code Explanation

```cpp
class Solution {
public:
    // Helper function to recursively find the length of the longest common subsequence
    int solve(string &text1, string &text2, int i, int j) {
        // Base case: if either string is exhausted, no subsequence is possible
        if (i >= text1.length() || j >= text2.length()) return 0;
```
- **Line 1**: Define a helper function `solve` that takes references to `text1` and `text2` and indices `i` and `j`.
- **Line 2-3**: If either string is completely traversed, return 0 (no subsequence is possible).

```cpp
        int ans = 0; // Initialize the answer for the current state
```
- **Line 4**: Initialize a variable `ans` to store the result for the current state.

```cpp
        // Case 1: Characters match, include them in the subsequence
        if (text1[i] == text2[j]) 
            return 1 + solve(text1, text2, i + 1, j + 1);
```
- **Line 5-6**: If `text1[i]` and `text2[j]` match, add 1 to the LCS and recursively call `solve` for the next indices (`i+1` and `j+1`).

```cpp
        else {
            // Case 2: Characters don't match, explore two possibilities:
            // a) Skip the current character of text1
            // b) Skip the current character of text2
            // Take the maximum of these two possibilities
            ans = max(solve(text1, text2, i + 1, j), solve(text1, text2, i, j + 1));
        }
```
- **Line 8-12**: If the characters do not match:
  - Explore skipping the current character of `text1` (call `solve(i+1, j)`).
  - Explore skipping the current character of `text2` (call `solve(i, j+1)`).
  - Take the maximum LCS length between the two.

```cpp
        return ans; // Return the result for the current state
    }
```
- **Line 14**: Return the computed result for the current indices.

```cpp
    // Main function to compute the longest common subsequence
    int longestCommonSubsequence(string text1, string text2) {
        // Start the recursive computation from the beginning of both strings
        return solve(text1, text2, 0, 0);
    }
};
```
- **Line 16-18**: Start solving the problem from the first characters of both strings (`i=0`, `j=0`) and return the result.

### **Example Output**

For `text1 = "abcde"` and `text2 = "ace"`:
1. Start with `solve("abcde", "ace", 0, 0)`:
   - Characters match: `1 + solve("bcde", "ce", 1, 1)`.
2. Continue with `solve("bcde", "ce", 1, 1)`:
   - Characters don’t match:
     - Explore skipping 'b': `solve("cde", "ce", 2, 1)`.
     - Explore skipping 'c': `solve("bcde", "e", 1, 2)`.
   - Take the maximum of these two.
3. Proceed recursively until both strings are traversed.

Final LCS = 3.


### **Time Complexity**
- Each recursive call explores two possibilities, leading to (O(2^{text{max}(n, m)})) in the **worst case** (without memoization).
- With memoization, it becomes (O(n times m)), where:
  - (n) = length of `text1`.
  - (m) = length of `text2`.

### **Space Complexity**
- Without memoization: (O(max(n, m))) (recursion stack depth).
- With memoization: (O(n times m)) (for the DP table).

---

## Dop-Down Approach (DP)
The top-down approach is an enhancement of the plain recursive method. It uses **memoization** to store the results of subproblems that have already been solved, avoiding redundant computations. This significantly improves performance.

#### Key Points:
1. **Memoization Table**:
   - A 2D table (`dp`) is used to store the results of subproblems.
   - `dp[i][j]` represents the length of the longest common subsequence for `text1` starting at index `i` and `text2` starting at index `j`.

2. **Steps**:
   - **Base Case**:
     - If either string is exhausted (`i >= text1.length()` or `j >= text2.length()`), return 0 because no subsequence is possible.
   - **Memoization Check**:
     - Before computing `solve(i, j)`, check if the result is already stored in `dp[i][j]`.
   - **Recursive Cases**:
     - If `text1[i] == text2[j]`, include the character in the LCS and move to the next indices:
       `dp[i][j] = 1 + solve(i+1, j+1)`
       
     - If `text1[i] != text2[j]`, explore two possibilities:
       - Skip the character of `text1`.
       - Skip the character of `text2`.
       - Take the maximum of the two:
         `dp[i][j] = max(solve(i+1, j), solve(i, j+1))`


### **Example Walkthrough**

#### Input:
```plaintext
text1 = "abcde"
text2 = "ace"
```

#### Steps:
1. Initialize a 2D table `dp` of size `(5+1) x (3+1)` with all values set to -1.
2. Start solving from `solve(0, 0)`:
   - Compare `text1[0]` ('a') with `text2[0]` ('a'):
     - Characters match, so include 'a' and compute:
       `
       dp[0][0] = 1 + solve(1, 1)
       `
   - Move to `solve(1, 1)`:
     - Compare `text1[1]` ('b') with `text2[1]` ('c'):
       - Characters don’t match. Compute:
         `
         dp[1][1] = max(solve(2, 1), solve(1, 2))
         `
   - Continue recursively for all possible cases, storing intermediate results in `dp`.
3. Retrieve the final result from `dp[0][0]`.

### Source code
```cpp
class Solution {
public:
    // Helper function to recursively find the length of the longest common subsequence with memoization
    int solve(string &text1, string &text2, int i, int j, vector<vector<int>>& dp) {
        // Base case: if either string is exhausted, no subsequence is possible
        if (i >= text1.length() || j >= text2.length()) return 0;

        // Check if the result for this state has already been computed
        if (dp[i][j] != -1) return dp[i][j];

        int ans = 0; // Initialize the answer for the current state

        // Case 1: Characters match, include them in the subsequence
        if (text1[i] == text2[j]) 
            return dp[i][j] = 1 + solve(text1, text2, i + 1, j + 1, dp);
        else {
            // Case 2: Characters don't match, explore two possibilities:
            // a) Skip the current character of text1
            // b) Skip the current character of text2
            // Take the maximum of these two possibilities
            ans = max(solve(text1, text2, i + 1, j, dp), solve(text1, text2, i, j + 1, dp));
        }

        // Store the computed result in the memoization table
        return dp[i][j] = ans;
    }

    // Main function to compute the longest common subsequence
    int longestCommonSubsequence(string text1, string text2) {
        // Create a 2D vector for memoization initialized with -1
        // dp[i][j] stores the result of solve for indices i and j
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, -1));
        
        // Start the recursive computation from the beginning of both strings
        return solve(text1, text2, 0, 0, dp);
    }
};
```

### Source Code Explanation

#### Helper Function
```cpp
int solve(string &text1, string &text2, int i, int j, vector<vector<int>>& dp) {
    // Base case: if either string is exhausted, no subsequence is possible
    if (i >= text1.length() || j >= text2.length()) return 0;
```
- **Base Case**:
  - If either `i` or `j` exceeds the length of their respective strings, return 0 as there are no more characters to consider.

```cpp
    // Check if the result for this state has already been computed
    if (dp[i][j] != -1) return dp[i][j];
```
- **Memoization Check**:
  - If `dp[i][j]` is not -1, return the stored result to avoid redundant computations.

```cpp
    int ans = 0; // Initialize the answer for the current state
```
- **Initialize `ans`**:
  - This variable will hold the LCS length for the current indices `i` and `j`.

```cpp
    // Case 1: Characters match, include them in the subsequence
    if (text1[i] == text2[j]) 
        return dp[i][j] = 1 + solve(text1, text2, i + 1, j + 1, dp);
```
- **If Characters Match**:
  - Add 1 to the LCS and recursively call `solve` for the next indices (`i+1`, `j+1`).
  - Store the result in `dp[i][j]`.

```cpp
    else {
        // Case 2: Characters don't match, explore two possibilities:
        ans = max(solve(text1, text2, i + 1, j, dp), solve(text1, text2, i, j + 1, dp));
    }
```
- **If Characters Don’t Match**:
  - Explore two cases:
    1. Skip the character of `text1` (`solve(i+1, j, dp)`).
    2. Skip the character of `text2` (`solve(i, j+1, dp)`).
  - Take the maximum of the two results and store it in `ans`.

```cpp
    return dp[i][j] = ans; // Store the computed result in the memoization table
}
```
- **Store the Result**:
  - Save the computed result for indices `i` and `j` in `dp[i][j]`.

#### Main Function
```cpp
int longestCommonSubsequence(string text1, string text2) {
    // Create a 2D vector for memoization initialized with -1
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, -1));
```
- **Create Memoization Table**:
  - A 2D vector `dp` of size `(text1.size()+1) x (text2.size()+1)` is initialized with -1.

```cpp
    // Start the recursive computation from the beginning of both strings
    return solve(text1, text2, 0, 0, dp);
}
```
- **Start Computation**:
  - Call `solve` for the initial indices `0, 0` and return the result.


### **Example Output in Detail**

#### For `text1 = "abcde"` and `text2 = "ace"`:

| i  j |  0   |  1   |  2   |  3   |
|-------|-------|-------|-------|-------|
| 0     |   3   |   2   |   1   |   0   |
| 1     |   2   |   2   |   1   |   0   |
| 2     |   2   |   2   |   1   |   0   |
| 3     |   1   |   1   |   1   |   0   |
| 4     |   1   |   1   |   1   |   0   |
| 5     |   0   |   0   |   0   |   0   |

- Result stored at `dp[0][0]` = 3.
- LCS: "ace".


### **Time Complexity**
- Each state `(i, j)` is computed only once due to memoization.
- There are (O(n times m)) states, where (n = text{text1.length()}) and (m = text{text2.length()}).
- **Time Complexity**: (O(n times m)).

### **Space Complexity**
- **Space for Memoization Table**: (O(n times m)).
- **Recursion Stack Depth**: (O(min(n, m))) (due to recursion).
- **Total Space Complexity**: (O(n times m)).

---

## Bottom-Up Approach (DP)
The **bottom-up approach** uses **iterative dynamic programming (DP)** to solve the problem. It builds the solution iteratively by solving smaller subproblems first and combining their results to solve larger problems. Here’s how it works for the **Longest Common Subsequence (LCS)** problem:

### **1. Problem Description**
Given two strings `text1` and `text2`, find the length of the longest subsequence that is common to both strings. A subsequence is a sequence derived by deleting some (or no) characters from a string without changing the order of the remaining characters.

#### **Example Input**:
- `text1 = "abcde"`
- `text2 = "ace"`

#### **Expected Output**:
- Length of LCS = 3 (`"ace"` is the LCS).

### **2. Approach Explanation**
- Use a **2D DP table** `dp[i][j]` to represent the length of the LCS between:
  - The suffix of `text1` starting at index `i`.
  - The suffix of `text2` starting at index `j`.
  
#### **Base Cases**:
- If either string is empty, the LCS length is 0.
- Initialize `dp[n][j] = 0` and `dp[i][m] = 0` for all `j` and `i`, where `n` and `m` are the lengths of `text1` and `text2`.

#### **Transition Formula**:
- If `text1[i] == text2[j]`:  
  `dp[i][j] = 1 + dp[i+1][j+1]`  
  Include the matching character in the LCS.
  
- Otherwise:  
  `dp[i][j] = max(dp[i+1][j], dp[i][j+1])`  
  Skip one character from either string and take the best result.

#### **Final Result**:
- The value at `dp[0][0]` gives the length of the LCS for the entire strings.

### **3. Example Execution**

#### Strings:
- `text1 = "abcde"`
- `text2 = "ace"`

#### DP Table Initialization:
A table of size `(n+1) x (m+1)` is created (6x4 in this case). Initially, it is filled with 0s:

```
    ""   a   c   e
""  [0,  0,  0,  0]
 a  [0,  0,  0,  0]
 b  [0,  0,  0,  0]
 c  [0,  0,  0,  0]
 d  [0,  0,  0,  0]
 e  [0,  0,  0,  0]
```

#### Iterative Computation:
We fill the DP table from bottom-right to top-left:

1. **Bottom Row & Right Column:**  
   Already initialized to 0 because the LCS with an empty string is 0.

2. **Processing Last Characters (`e`):**
   - Match: `text1[4] == text2[2]` (`'e'`), so:  
     `dp[4][2] = 1 + dp[5][3] = 1`.
   - Update table:
     ```
         ""   a   c   e
     ""  [0,  0,  0,  0]
      a  [0,  0,  0,  0]
      b  [0,  0,  0,  0]
      c  [0,  0,  0,  0]
      d  [0,  0,  0,  0]
      e  [0,  0,  1,  0]
     ```

3. **Processing Remaining Characters:**
   - Continue filling in reverse order, following the transition rules.
   - Final DP table:
     ```
         ""   a   c   e
     ""  [3,  2,  1,  0]
      a  [2,  2,  1,  0]
      b  [2,  2,  1,  0]
      c  [2,  2,  1,  0]
      d  [1,  1,  1,  0]
      e  [1,  0,  0,  0]
     ```

4. **Final Answer:**
   `dp[0][0] = 3`.

### Source Code
```cpp
class Solution {
public:
    // Helper function to compute the longest common subsequence using bottom-up dynamic programming
    int solve(string &text1, string &text2) {
        int n = text1.length(); // Length of the first string
        int m = text2.length(); // Length of the second string

        // Create a 2D DP table initialized with 0
        // dp[i][j] represents the length of the LCS of text1[i..n-1] and text2[j..m-1]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Iterate over the strings in reverse order to fill the DP table
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int ans = 0; // Variable to store the result for the current state
                
                // Case 1: Characters match, include them in the LCS
                if (text1[i] == text2[j]) 
                    ans = 1 + dp[i + 1][j + 1];
                else
                    // Case 2: Characters don't match, take the maximum:
                    // a) Skip the current character of text1
                    // b) Skip the current character of text2
                    ans = max(dp[i + 1][j], dp[i][j + 1]);
                
                // Store the result in the DP table
                dp[i][j] = ans;
            }
        }

        // The final answer (LCS of the entire strings) is stored in dp[0][0]
        return dp[0][0];
    }

    // Main function to compute the longest common subsequence
    int longestCommonSubsequence(string text1, string text2) {
        // Call the helper function and return the result
        return solve(text1, text2);
    }
};
```

### Source Code Explanation

#### **Function `solve`:**
```cpp
int solve(string &text1, string &text2) {
    int n = text1.length(); // Length of text1
    int m = text2.length(); // Length of text2

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // Initialize DP table
```
- `n` and `m` store the lengths of the strings.
- `dp` is a 2D table initialized with zeros.

#### **Fill DP Table:**
```cpp
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int ans = 0; // Temporary variable for the current state
```
- Process strings in reverse order to use already computed values.

```cpp
            if (text1[i] == text2[j]) 
                ans = 1 + dp[i + 1][j + 1]; // Characters match
            else
                ans = max(dp[i + 1][j], dp[i][j + 1]); // Characters don't match
```
- Match: Add 1 to the LCS of the remaining substrings.
- No match: Skip one character from either string and take the maximum.

```cpp
            dp[i][j] = ans; // Store the result in DP table
        }
    }
```
- Store the computed result in the DP table.


#### **Return Result:**
```cpp
    return dp[0][0]; // Final answer is at dp[0][0]
}
```
- Return the LCS of the entire strings.

### **Example Output Explanation**

Input:
```cpp
string text1 = "abcde";
string text2 = "ace";
```

- Final DP Table:
  ```
      ""   a   c   e
  ""  [3,  2,  1,  0]
   a  [2,  2,  1,  0]
   b  [2,  2,  1,  0]
   c  [2,  2,  1,  0]
   d  [1,  1,  1,  0]
   e  [1,  0,  0,  0]
  ```

Output:
```cpp
3 // Length of LCS is 3
```

Explanation:
- LCS is `"ace"`, which has a length of 3.

### **Time and Space Complexities**

#### **Time Complexity:**
- Filling the DP table requires two nested loops:
  - Outer loop: `O(n)`
  - Inner loop: `O(m)`
- Total complexity: **`O(n * m)`**

#### **Space Complexity:**
- A 2D DP table of size `(n+1) x (m+1)` is used:
  - Space: **`O(n * m)`**

To optimize space, a 1D array can be used instead of a 2D array, reducing space complexity to **`O(min(n, m))`**.

---

## Space Optimization Approach (DP)
In the **space-optimized** approach for solving the Longest Common Subsequence (LCS), we reduce the space complexity from ( O(n times m) ) to ( O(m) ), where ( n ) and ( m ) are the lengths of the two input strings, `text1` and `text2`. Instead of maintaining a full 2D table, we use two 1D arrays (`curr` and `next`) to store only the necessary rows of the DP table.

#### Key Idea
1. In the bottom-up DP approach, to calculate `dp[i][j]`, we need only the values from:
   - The same row (`dp[i][j+1]`).
   - The next row (`dp[i+1][j]` and `dp[i+1][j+1]`).
2. By iterating in reverse order, we can calculate the current row (`curr`) while keeping track of the previous row (`next`).
3. At the end of processing each row, we update `next` to `curr`.

#### Example
Consider:
- `text1 = "abcde"`
- `text2 = "ace"`

The 2D DP table would look like this:
```
   ""  a  c  e
""  0  0  0  0
 a  0  1  1  1
 b  0  1  1  1
 c  0  1  2  2
 d  0  1  2  2
 e  0  1  2  3
```

In the space-optimized approach:
1. We compute the values row by row, but only store one row (`curr`) at a time while keeping the previous row (`next`).

### Source Code
```cpp
class Solution {
public:
    // Helper function to compute the longest common subsequence using optimized space
    int solve(string &text1, string &text2) {
        int n = text1.length(); // Length of the first string
        int m = text2.length(); // Length of the second string

        // Create two 1D arrays for the current and next rows in the DP table
        // This reduces the space complexity to O(m) instead of O(n*m)
        vector<int> curr(m + 1, 0); // Current row being processed
        vector<int> next(m + 1, 0); // Next row (from the previous iteration)

        // Iterate over the strings in reverse order
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int ans = 0; // Variable to store the result for the current state
                
                // Case 1: Characters match, include them in the LCS
                if (text1[i] == text2[j]) 
                    ans = 1 + next[j + 1];
                else
                    // Case 2: Characters don't match, take the maximum:
                    // a) Skip the current character of text1
                    // b) Skip the current character of text2
                    ans = max(next[j], curr[j + 1]);
                
                // Store the result in the current row
                curr[j] = ans;
            }

            // Update the next row to the current row for the next iteration
            next = curr;
        }

        // The final answer (LCS of the entire strings) is stored in curr[0]
        return curr[0];
    }

    // Main function to compute the longest common subsequence
    int longestCommonSubsequence(string text1, string text2) {
        // Call the helper function and return the result
        return solve(text1, text2);
    }
};
```

### Source Code Explanation

```cpp
int solve(string &text1, string &text2) {
    int n = text1.length(); // Length of the first string
    int m = text2.length(); // Length of the second string
```
- Determine the lengths of the input strings `text1` and `text2`.

```cpp
    vector<int> curr(m + 1, 0); // Current row being processed
    vector<int> next(m + 1, 0); // Next row (from the previous iteration)
```
- Initialize two 1D arrays `curr` and `next` of size `m+1` with all elements set to `0`.
- `curr[j]` represents the current row's state at column `j`, and `next[j]` represents the state from the next row during the previous iteration.

```cpp
    for (int i = n - 1; i >= 0; i--) {
```
- Iterate through `text1` in reverse order, starting from the last character.

```cpp
        for (int j = m - 1; j >= 0; j--) {
            int ans = 0; // Variable to store the result for the current state
```
- Iterate through `text2` in reverse order, starting from the last character.
- Initialize `ans` to store the result of the LCS for the current indices.

```cpp
            if (text1[i] == text2[j]) 
                ans = 1 + next[j + 1];
```
- **Case 1:** If the characters `text1[i]` and `text2[j]` match:
  - Add `1` to the LCS of the next indices (`next[j+1]`).

```cpp
            else
                ans = max(next[j], curr[j + 1]);
```
- **Case 2:** If the characters don’t match:
  - Take the maximum between:
    - Skipping the current character in `text1` (`next[j]`).
    - Skipping the current character in `text2` (`curr[j+1]`).

```cpp
            curr[j] = ans;
```
- Store the result for the current state in the `curr` array.

```cpp
        }
        next = curr;
```
- At the end of the inner loop (after processing all columns for a row `i`):
  - Update the `next` array to the current row (`curr`).

```cpp
    }
    return curr[0];
```
- The final LCS value is stored in `curr[0]`, which represents the LCS of the full strings.


### Example Output Explanation
#### Input
```text1 = "abcde", text2 = "ace"```

#### Iteration Details:
1. **Initialization:**
   - `curr = [0, 0, 0, 0]`
   - `next = [0, 0, 0, 0]`

2. **Processing Row `e` (i = 4):**
   - Match at `j = 2`: `text1[4] = e`, `text2[2] = e`.
     - `curr[2] = 1 + next[3] = 1`
   - `curr = [0, 0, 1, 0]`

3. **Processing Row `d` (i = 3):**
   - No match: `curr[2] = max(next[2], curr[3]) = 1`
   - `curr = [0, 0, 1, 0]`

4. **Processing Row `c` (i = 2):**
   - Match at `j = 1`: `text1[2] = c`, `text2[1] = c`.
     - `curr[1] = 1 + next[2] = 2`
   - `curr = [0, 2, 1, 0]`

5. **Processing Row `b` (i = 1):**
   - No match: `curr[1] = max(next[1], curr[2]) = 2`
   - `curr = [0, 2, 1, 0]`

6. **Processing Row `a` (i = 0):**
   - Match at `j = 0`: `text1[0] = a`, `text2[0] = a`.
     - `curr[0] = 1 + next[1] = 3`
   - `curr = [3, 2, 1, 0]`

#### Final Output:
The LCS length is `3`.

### Time and Space Complexities
#### Time Complexity:
- ( O(n times m) ): Two nested loops iterate over both strings.

#### Space Complexity:
- ( O(m) ): Only two 1D arrays (`curr` and `next`) of size ( m+1 ) are used.
