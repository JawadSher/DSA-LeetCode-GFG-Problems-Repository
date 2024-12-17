<h1 align="center">Longest - Palindromic - Subsequence</h1>

## Problem Statement

**Problem URL :** [Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/description/)

![image](https://github.com/user-attachments/assets/8aef3c17-e1a0-4ce3-9aa4-f4340789efc1)

### Problem Explanation
The problem asks us to find the **length of the longest palindromic subsequence** in a given string. 

#### **Definitions**
1. A **subsequence** is a sequence derived by deleting some or no characters from the string without changing the order of the remaining characters.
   - Example: For `s = "abcde"`, the subsequences include `"ace"`, `"abc"`, `"e"`, etc.

2. A **palindrome** is a sequence that reads the same backward as forward.
   - Example: `"abba"`, `"racecar"`, and `"aaa"` are palindromes.

3. A **palindromic subsequence** is a subsequence that is also a palindrome.


### **Objective**
Given a string `s`, determine the length of the longest subsequence of `s` that is a palindrome.


### **Steps to Solve**
1. **Reverse the String:**
   - To find the longest palindromic subsequence, compare the original string `s` with its reversed string `rev_s`.

2. **Find the Longest Common Subsequence (LCS):**
   - The problem reduces to finding the **LCS** between `s` and `rev_s` because:
     - The LCS ensures that the characters are in the same order as in the original string.
     - The palindrome property is satisfied since the characters are compared with the reversed string.


### **Example 1**

**Input:** `s = "bbbab"`

#### Step 1: Reverse the string  
Reversed string = `"babbb"`

#### Step 2: Solve for the LCS between `s` and `rev_s`

- Compare characters of `s` = `"bbbab"` and `rev_s` = `"babbb"`:
  
  | `s` | `rev_s` | Explanation                      |
  |-----|---------|----------------------------------|
  | `'b'` | `'b'`   | Match! Add `1` to LCS.            |
  | `'b'` | `'a'`   | No match. Skip `'b'` or `'a'`.    |
  | `'b'` | `'b'`   | Match! Add `1` to LCS.            |
  | `'a'` | `'b'`   | No match. Skip `'a'` or `'b'`.    |
  | `'b'` | `'b'`   | Match! Add `1` to LCS.            |

The LCS between `"bbbab"` and `"babbb"` is `"bbbb"`.

#### Step 3: Result
The length of the longest palindromic subsequence is `4`.

**Output:** `4`


### **Example 2**

**Input:** `s = "cbbd"`

#### Step 1: Reverse the string  
Reversed string = `"dbbc"`

#### Step 2: Solve for the LCS between `s` and `rev_s`

- Compare characters of `s` = `"cbbd"` and `rev_s` = `"dbbc"`:
  
  | `s` | `rev_s` | Explanation                      |
  |-----|---------|----------------------------------|
  | `'c'` | `'d'`   | No match. Skip `'c'` or `'d'`.    |
  | `'b'` | `'b'`   | Match! Add `1` to LCS.            |
  | `'b'` | `'b'`   | Match! Add `1` to LCS.            |
  | `'d'` | `'c'`   | No match. Skip `'d'` or `'c'`.    |

The LCS between `"cbbd"` and `"dbbc"` is `"bb"`.

#### Step 3: Result
The length of the longest palindromic subsequence is `2`.

**Output:** `2`


### **Algorithm Summary**
1. Reverse the string.
2. Find the LCS between the original string and its reversed version.
3. The length of the LCS is the length of the longest palindromic subsequence.


### **Key Observations**
- The LCS ensures that the subsequence is in order.
- Comparing with the reversed string ensures the palindrome property.

### **Edge Cases**
1. **Single-character string:**
   - Input: `s = "a"`
   - Output: `1` (The single character is the palindrome.)
   
2. **All characters are the same:**
   - Input: `s = "aaaa"`
   - Output: `4` (The entire string is the palindrome.)
   
3. **No palindromic subsequence other than single characters:**
   - Input: `s = "abcd"`
   - Output: `1` (Only single characters like `"a"`, `"b"`, `"c"`, or `"d"` are palindromic subsequences.)

This approach is efficient and works for all cases.

---

## Recursive Approach (caused TLE)
To find the **Longest Palindromic Subsequence** (LPS) using recursion, the problem is solved by comparing the original string and its reversed version. Let’s break it down:

#### **Step 1: Problem Insight**
A **palindromic subsequence** is a sequence that reads the same forward and backward and can be derived by deleting some characters (without rearranging) from the original string.

For example, in the string `str = "bbbab"`, the LPS is `"bbbb"`.

#### **Step 2: Approach**
1. Reverse the string `str` to form `revStr`.
2. Use a recursive function to find the **longest common subsequence (LCS)** between `str` and `revStr`. 
   - If two characters match, they are part of the palindromic subsequence.
   - If they do not match, explore both possibilities: skipping the current character in `str` or `revStr`.
3. The LCS between `str` and `revStr` gives the LPS of `str`.

#### **Step 3: Recursive Relation**
1. **Base Case**:
   - If either string is fully traversed (i.e., index `i` or `j` goes out of bounds), return `0` because no further subsequences can be formed.

2. **Recursive Transition**:
   - If `str[i] == revStr[j]`: Add `1` to the LPS length and move to the next indices of both strings:  
     `solve(str, revStr, i + 1, j + 1)`
   - If `str[i] != revStr[j]`: Take the maximum LPS by skipping either the current character in `str` or `revStr`:
     `max(solve(str, revStr, i + 1, j), solve(str, revStr, i, j + 1))`

### Example Walkthrough
Consider `str = "bbbab"`:
1. Reverse `str`: `revStr = "babbb"`.
2. Solve for the LCS between `str` and `revStr`.

#### Recursive Tree
1. Start comparing `str[0]` (`'b'`) and `revStr[0]` (`'b'`).
   - Match! Add `1` and move to `solve("bbbab", "babbb", 1, 1)`.
2. Compare `str[1]` (`'b'`) and `revStr[1]` (`'a'`).
   - No match. Recursively solve:
     - Skip in `str`: `solve("bbbab", "babbb", 2, 1)`
     - Skip in `revStr`: `solve("bbbab", "babbb", 1, 2)`
3. Continue until the base case is reached.

The recursion explores all possible subsequences and returns the maximum LPS length.

### Source Code
```cpp
class Solution {
public:
    // Recursive helper function to solve the problem
    // Parameters:
    // - str: the original string
    // - revStr: the reversed string
    // - i: current index in the original string
    // - j: current index in the reversed string
    int solve(string str, string revStr, int i, int j) {
        // Base case: if either index goes out of bounds, return 0
        if (i >= str.length() || j >= revStr.length()) 
            return 0;
        
        // Initialize the answer variable
        int ans = 0;

        // If the characters match, add 1 to the result and move to the next indices
        if (str[i] == revStr[j]) 
            return 1 + solve(str, revStr, i + 1, j + 1);
        else {
            // If the characters do not match, find the maximum result by:
            // 1. Skipping the current character in the original string
            // 2. Skipping the current character in the reversed string
            ans = max(solve(str, revStr, i + 1, j), solve(str, revStr, i, j + 1));
        }

        // Return the computed answer
        return ans;
    }

    // Function to calculate the longest palindromic subsequence
    int longestPalindromeSubseq(string str) {
        // Create a reversed version of the input string
        string revStr = str;
        reverse(revStr.begin(), revStr.end());

        // Start solving from the first indices of both strings
        return solve(str, revStr, 0, 0);
    }
};
```

### Source Code Explanation

#### **1. `solve()` Function**
```cpp
int solve(string str, string revStr, int i, int j) {
```
- A helper function that calculates the LPS length recursively.
- Parameters:
  - `str`: Original string.
  - `revStr`: Reversed version of `str`.
  - `i`, `j`: Current indices in `str` and `revStr`.

```cpp
if (i >= str.length() || j >= revStr.length()) 
    return 0;
```
- Base case: If either index is out of bounds, return `0`.

```cpp
int ans = 0;
```
- Initialize the variable to store the current LPS length.

```cpp
if (str[i] == revStr[j]) 
    return 1 + solve(str, revStr, i + 1, j + 1);
```
- If characters match, include them in the LPS and move to the next indices.

```cpp
else {
    ans = max(solve(str, revStr, i + 1, j), solve(str, revStr, i, j + 1));
}
```
- If characters don’t match, recursively calculate the LPS for both possibilities:
  1. Skip the character in `str`.
  2. Skip the character in `revStr`.
- Take the maximum result.

```cpp
return ans;
```
- Return the LPS length computed for the current indices.



#### **2. `longestPalindromeSubseq()` Function**
```cpp
string revStr = str;
reverse(revStr.begin(), revStr.end());
```
- Create a reversed copy of the input string.

```cpp
return solve(str, revStr, 0, 0);
```
- Start solving from the first indices (`i = 0`, `j = 0`).



### Example Output Explanation
Input: `str = "bbbab"`  
- Reversed string: `revStr = "babbb"`.  
- LPS length is calculated as follows:
  1. Compare `str[0]` = `'b'` and `revStr[0]` = `'b'` → Match, add `1`.
  2. Continue matching `'b'` from both strings.
  3. The longest palindromic subsequence found is `"bbbb"`, with a length of `4`.

Output: `4`.

### Time and Space Complexities

#### **Time Complexity**
- The recursion explores all possible subsequences.
- Since each subsequence is defined by indices `i` and `j`, the total number of recursive calls is (O(2^{(n+m)})), where (n) and (m) are the lengths of `str` and `revStr`.
- However, by recognizing that (n = m) and both indices grow linearly, the time complexity simplifies to (O(2^n)).

#### **Space Complexity**
- The recursive calls consume space proportional to the depth of the recursion tree.
- The depth of the tree is at most (O(n)), leading to a space complexity of (O(n)).

---

## Top-Down Approach (DP)
This approach solves the **Longest Palindromic Subsequence** problem using recursion with memoization. Below is a detailed breakdown of the solution.

### **Step-by-Step Explanation**

#### **Step 1: Problem Restatement**
The goal is to find the longest subsequence in the given string that is a palindrome. A **subsequence** allows skipping characters, but the order of remaining characters must stay the same.  
For example:
- Input: `"bbbab"`
- Output: `4` (The subsequence `"bbbb"` is a palindrome of length `4`.)

#### **Step 2: Key Observation**
If the input string `str` is compared with its reverse, finding the **Longest Palindromic Subsequence (LPS)** becomes equivalent to finding the **Longest Common Subsequence (LCS)** between the original string `str` and its reversed string `revStr`.

For example:
- Original string: `"bbbab"`
- Reversed string: `"babb"`
- LCS: `"bbbb"`

#### **Step 3: Recursive Approach**
To compute the LCS between `str` and `revStr`, we define a recursive function `solve(i, j)`:
1. If `str[i] == revStr[j]`, add `1` to the LCS and recursively compute for the next indices `i + 1` and `j + 1`.
2. If `str[i] != revStr[j]`, compute the maximum of:
   - Skipping the current character in `str` (`solve(i + 1, j)`).
   - Skipping the current character in `revStr` (`solve(i, j + 1)`).

#### **Step 4: Memoization**
To avoid redundant calculations, we use a `dp` table where `dp[i][j]` stores the result of `solve(i, j)`.

### Source Code
```cpp
class Solution {
public:
    // Recursive function with memoization to find the longest palindromic subsequence
    // Parameters:
    // - str: the original string
    // - revStr: the reversed string
    // - i: current index in the original string
    // - j: current index in the reversed string
    // - dp: 2D vector for memoization to store intermediate results
    int solve(string str, string revStr, int i, int j, vector<vector<int>>& dp) {
        // Base case: if either index exceeds the string length, return 0
        if (i >= str.length() || j >= revStr.length()) 
            return 0;

        // If the result for this state is already computed, return it
        if (dp[i][j] != -1) 
            return dp[i][j];

        // If characters at the current indices match, move to the next indices in both strings
        if (str[i] == revStr[j]) 
            return dp[i][j] = 1 + solve(str, revStr, i + 1, j + 1, dp);
        else {
            // Otherwise, take the maximum result by advancing one index at a time in either string
            int ans = max(solve(str, revStr, i + 1, j, dp), solve(str, revStr, i, j + 1, dp));
            return dp[i][j] = ans; // Store the result in the dp table
        }
    }

    // Main function to calculate the longest palindromic subsequence
    int longestPalindromeSubseq(string str) {
        // Create a reversed copy of the original string
        string revStr = str;
        reverse(revStr.begin(), revStr.end());

        // Initialize a 2D dp table with -1 for memoization
        vector<vector<int>> dp(str.length() + 1, vector<int>(revStr.length() + 1, -1));

        // Start the recursive function with initial indices 0 and 0
        return solve(str, revStr, 0, 0, dp);
    }
};
```

### Source Code Explanation

#### **Recursive Function**

```cpp
int solve(string str, string revStr, int i, int j, vector<vector<int>>& dp) {
    // Base case: If either index exceeds the length of the string, return 0
    if (i >= str.length() || j >= revStr.length()) 
        return 0;

    // Memoization: If already computed, return the stored result
    if (dp[i][j] != -1) 
        return dp[i][j];

    // Case 1: Characters match
    if (str[i] == revStr[j]) 
        return dp[i][j] = 1 + solve(str, revStr, i + 1, j + 1, dp);

    // Case 2: Characters do not match
    int ans = max(solve(str, revStr, i + 1, j, dp), solve(str, revStr, i, j + 1, dp));

    // Store the result in dp table
    return dp[i][j] = ans;
}
```

**Explanation of Logic:**
1. **Base Case:** If either `i` or `j` goes beyond the length of the strings, there are no subsequences left to compare, so return `0`.
2. **Memoization Check:** If the value for `solve(i, j)` has already been calculated, return it to save time.
3. **Character Match:** If `str[i] == revStr[j]`, this character contributes to the LCS, so we add `1` and solve for the next indices.
4. **Character Mismatch:** If the characters don't match, consider skipping the current character in either `str` or `revStr` and take the maximum result.


#### **Main Function**

```cpp
int longestPalindromeSubseq(string str) {
    // Reverse the string to create the reversed version
    string revStr = str;
    reverse(revStr.begin(), revStr.end());

    // Create a dp table initialized to -1
    vector<vector<int>> dp(str.length() + 1, vector<int>(revStr.length() + 1, -1));

    // Call the recursive function starting from indices 0, 0
    return solve(str, revStr, 0, 0, dp);
}
```

**Explanation of Logic:**
1. Reverse the input string `str` to create `revStr`.
2. Initialize a `dp` table with dimensions `(n+1) x (n+1)` filled with `-1`.
3. Call the recursive function `solve(0, 0)` with the initial indices.


### **Example Walkthrough**

#### Example Input:
```text
str = "bbbab"
revStr = "babb"
```

#### Step-by-Step Computation:
1. **Initial Call:** `solve(0, 0)` compares `str[0] = 'b'` with `revStr[0] = 'b'`. They match, so:
   ```text
   dp[0][0] = 1 + solve(1, 1)
   ```
2. **Next Call:** `solve(1, 1)` compares `str[1] = 'b'` with `revStr[1] = 'a'`. They don't match, so:
   ```text
   dp[1][1] = max(solve(2, 1), solve(1, 2))
   ```
3. **Further Calls:** The function continues splitting into subproblems, solving smaller cases recursively, and storing results in `dp`.

#### Final DP Table:
```text
dp:
4 4 3 2 1
3 3 3 2 1
2 2 2 2 1
1 1 1 1 1
0 0 0 0 0
```

#### Output:
```text
Longest Palindromic Subsequence Length = dp[0][0] = 4
```


### **Time and Space Complexity**

#### **Time Complexity**
- Each recursive state is defined by indices `i` and `j`, forming a grid of size `n x n` for a string of length `n`.
- Each state is computed once, leading to a time complexity of:
  ```text
  O(n^2)
  ```

#### **Space Complexity**
- The `dp` table requires `O(n^2)` space.
- The recursive stack depth is `O(n)` in the worst case.

Overall space complexity:
```text
O(n^2)
```

---

## Bottom-Up Approach (DP)
The **bottom-up dynamic programming approach** solves the problem iteratively by filling a `dp` table. This method avoids recursion and ensures that smaller subproblems are solved first, storing their results in the table for reuse when solving larger subproblems.

#### **Step 1: Problem Restatement**
The task is to find the **Longest Palindromic Subsequence (LPS)** of a given string.  
A subsequence allows skipping characters but maintains the order of the remaining characters.

Example:
- Input: `"bbbab"`
- Output: `4` (The subsequence `"bbbb"` is the longest palindromic subsequence.)

#### **Step 2: Key Idea**
Finding the LPS can be reduced to finding the **Longest Common Subsequence (LCS)** between the string `str` and its reverse `revStr`.  

For example:
- Input: `"bbbab"`
- Reversed string: `"babb"`

The LCS of these two strings gives the length of the LPS.

#### **Step 3: DP Table Definition**
Let `dp[i][j]` represent the length of the LCS between `str[i..n-1]` and `revStr[j..m-1]`.  
- **Base Case:** If either `i == n` or `j == m`, `dp[i][j] = 0` because one of the strings is exhausted.
- **Recurrence Relation:**
  - If `str[i] == revStr[j]`, then `dp[i][j] = 1 + dp[i + 1][j + 1]` (diagonal move).
  - Otherwise, `dp[i][j] = max(dp[i + 1][j], dp[i][j + 1])` (horizontal or vertical move).

#### **Step 4: Iterative Filling**
- Start from the end of both strings (bottom-right corner of the table).
- Gradually work up to the beginning (top-left corner), solving smaller subproblems first.

### Source Code
```cpp
class Solution {
public:
    // Helper function to calculate the longest palindromic subsequence using dynamic programming
    // Parameters:
    // - str: the original string
    // - revStr: the reversed string
    // - i: current index in the original string
    // - j: current index in the reversed string
    int solve(string str, string revStr, int i, int j) {
        int n = str.length();  // Length of the original string
        int m = revStr.length();  // Length of the reversed string

        // 2D dp table to store the length of the longest palindromic subsequence
        // dp[i][j] represents the longest common subsequence between str[i..n-1] and revStr[j..m-1]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));  // Initialize with 0

        // Bottom-up dynamic programming approach: start from the end of both strings
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int ans = 0;  // Variable to store the current result

                // If characters match, add 1 to the result and check the next characters in both strings
                if (str[i] == revStr[j]) {
                    ans = 1 + dp[i + 1][j + 1];  // Move diagonally (i+1, j+1)
                }
                // If characters do not match, take the maximum of two possible options
                // - Move forward in the original string (i+1, j)
                // - Move forward in the reversed string (i, j+1)
                else {
                    ans = max(dp[i + 1][j], dp[i][j + 1]);
                }

                // Store the computed result in the dp table
                dp[i][j] = ans;
            }
        }

        // Return the result stored at dp[0][0], which represents the length of the longest palindromic subsequence
        return dp[0][0];
    }

    // Main function to calculate the longest palindromic subsequence
    int longestPalindromeSubseq(string str) {
        // Create the reversed version of the input string
        string revStr = str;
        reverse(revStr.begin(), revStr.end());  // Reverse the string

        // Call the helper function to calculate the longest palindromic subsequence
        return solve(str, revStr, 0, 0);
    }
};
```

### Source Code Explanation

```cpp
int solve(string str, string revStr, int i, int j) {
    int n = str.length();  // Length of the original string
    int m = revStr.length();  // Length of the reversed string
```
1. The lengths of the strings `str` and `revStr` are stored in variables `n` and `m`.
2. Since `revStr` is the reverse of `str`, both have the same length, so `n == m`.


```cpp
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));  // Initialize with 0
```
3. A 2D `dp` table of size `(n+1) x (m+1)` is initialized with `0`.
   - `dp[i][j]` will store the length of the LCS between `str[i..n-1]` and `revStr[j..m-1]`.
   - Adding 1 to the dimensions ensures that base cases where `i == n` or `j == m` can be handled.


```cpp
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
```
4. **Outer loop:** Iterate backward through `str` from the last character to the first (`i = n-1` to `0`).
5. **Inner loop:** Iterate backward through `revStr` from the last character to the first (`j = m-1` to `0`).


```cpp
            int ans = 0;  // Variable to store the current result
```
6. Initialize a variable `ans` to store the result for the current cell `dp[i][j]`.


```cpp
            if (str[i] == revStr[j]) {
                ans = 1 + dp[i + 1][j + 1];  // Move diagonally (i+1, j+1)
            } else {
                ans = max(dp[i + 1][j], dp[i][j + 1]);  // Take max of right and below
            }
```
7. **Character Match:**  
   - If `str[i] == revStr[j]`, add `1` to the LCS and use the result from the diagonal cell `dp[i+1][j+1]`.

8. **Character Mismatch:**  
   - Take the maximum result of skipping one character in either `str` (`dp[i+1][j]`) or `revStr` (`dp[i][j+1]`).


```cpp
            dp[i][j] = ans;  // Store the computed result in the dp table
```
9. Store the result in the current cell `dp[i][j]`.


```cpp
    return dp[0][0];  // Return the final result at dp[0][0]
}
```
10. The final result is stored in `dp[0][0]`, which represents the LCS of the entire strings.


```cpp
int longestPalindromeSubseq(string str) {
    string revStr = str;  // Reverse the string
    reverse(revStr.begin(), revStr.end());

    return solve(str, revStr, 0, 0);  // Call the helper function
}
```
11. The input string `str` is reversed to create `revStr`.
12. The `solve` function is called to calculate the LPS length.


### **Example Walkthrough**

#### Example Input:
```text
str = "bbbab"
revStr = "babb"
```

#### Step-by-Step DP Table Filling:

| i/j   |  b  |  a  |  b  |  b  |    |
|-------|-----|-----|-----|-----|----|
| **b** |  4  |  3  |  3  |  2  |  0 |
| **b** |  3  |  2  |  2  |  1  |  0 |
| **b** |  3  |  2  |  2  |  1  |  0 |
| **a** |  2  |  1  |  1  |  0  |  0 |
|       |  0  |  0  |  0  |  0  |    |

1. Start filling from the bottom-right corner.
2. At `dp[0][0]`, the longest palindromic subsequence length is `4`.


### **Example Output**
```text
Input: "bbbab"
Output: 4
Explanation: The longest palindromic subsequence is "bbbb".
```

### **Time and Space Complexities**

#### **Time Complexity**
- Two nested loops over the `n x n` DP table, where `n` is the length of the string.
- Total time complexity:  
  ```text
  O(n^2)
  ```

#### **Space Complexity**
- The `dp` table requires `O(n^2)` space.
- No recursion stack is used.

Total space complexity:
```text
O(n^2)
```

---

## Space Optimization Approach (DP)
This approach optimizes the space complexity of calculating the **Longest Palindromic Subsequence** (LPS) using dynamic programming. Instead of maintaining a full 2D DP table, it reduces space usage by storing only two rows at a time.

#### **Key Idea**
1. **Reduced Storage**: Use two 1D arrays (`curr` and `next`) instead of a full 2D DP table.
   - `curr[j]` represents the DP value of the current row.
   - `next[j]` stores the DP values of the next row.
2. **Traversal**: Process the DP table from the bottom-right to the top-left.
3. **Reversed String**: Compare the original string with its reversed version to find the longest common subsequence (LCS), which corresponds to the LPS.


### Example Input: `"bbbab"`

#### 1. Original String: `str = "bbbab"`  
#### 2. Reversed String: `revStr = "babbb"`

#### **Calculation**
The goal is to compute the LCS of `str` and `revStr`:
- Characters in `str` and `revStr` are compared, and the result is stored iteratively in `curr` and `next`.

### Source Code
```cpp
class Solution {
public:
    // Helper function to calculate the longest palindromic subsequence using space optimization
    // Parameters:
    // - str: the original string
    // - revStr: the reversed string
    int solve(string str, string revStr) {
        int n = str.length();  // Length of the original string
        int m = revStr.length();  // Length of the reversed string

        // Two 1D arrays to represent the current and next rows of the dp table
        // `curr[j]`: Represents dp[i][j] for the current row
        // `next[j]`: Represents dp[i+1][j] for the next row
        vector<int> curr(m + 1, 0);  // Initialize the current row with 0
        vector<int> next(m + 1, 0);  // Initialize the next row with 0
        
        // Traverse the dp table from bottom-right to top-left
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int ans = 0;  // Variable to store the result for dp[i][j]

                // If the characters match, add 1 to the result from the diagonal (next[j+1])
                if (str[i] == revStr[j]) {
                    ans = 1 + next[j + 1];  // Move diagonally (i+1, j+1)
                } else {
                    // If the characters do not match, take the maximum of:
                    // - The value from the row below (next[j]) representing dp[i+1][j]
                    // - The value from the column to the right in the current row (curr[j+1])
                    ans = max(next[j], curr[j + 1]);
                }

                // Store the computed result in the current row
                curr[j] = ans;
            }

            // Update the `next` row to become the current row for the next iteration
            next = curr;
        }

        // The result is stored in `curr[0]`, which represents dp[0][0]
        return curr[0];
    }

    // Main function to calculate the longest palindromic subsequence
    int longestPalindromeSubseq(string str) {
        // Create a reversed copy of the original string
        string revStr = str;
        reverse(revStr.begin(), revStr.end());

        // Call the helper function to calculate the result
        return solve(str, revStr);
    }
};
```

### Source Code Explanation

#### **Main Function**
```cpp
int longestPalindromeSubseq(string str) {
    string revStr = str;
    reverse(revStr.begin(), revStr.end()); // Create the reversed string.
    return solve(str, revStr); // Call the helper function.
}
```
1. **Reverse the Input String**: Creates `revStr` by reversing `str`.
2. **Call the Helper Function**: `solve(str, revStr)` calculates the LPS using the space-optimized DP approach.


#### **Helper Function**
```cpp
int solve(string str, string revStr) {
    int n = str.length();
    int m = revStr.length();
    vector<int> curr(m + 1, 0); // Represents dp[i][j]
    vector<int> next(m + 1, 0); // Represents dp[i+1][j]
```
1. **Length Variables**: `n` is the length of the original string, `m` is the length of the reversed string.
2. **1D Arrays**: 
   - `curr`: Current row of the DP table.
   - `next`: Next row of the DP table.

```cpp
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int ans = 0;
            if (str[i] == revStr[j]) {
                ans = 1 + next[j + 1]; // Characters match, move diagonally.
            } else {
                ans = max(next[j], curr[j + 1]); // Take the maximum from two options.
            }
            curr[j] = ans; // Store result in current row.
        }
        next = curr; // Move to the next row.
    }
```
3. **Outer Loop**: Iterates over rows of the DP table from `i = n - 1` to `i = 0`.
4. **Inner Loop**: Iterates over columns from `j = m - 1` to `j = 0`.
5. **Match Check**: If `str[i] == revStr[j]`, include the character in the LCS by adding 1 to the diagonal value.
6. **Mismatch**: Otherwise, take the maximum of:
   - Value in the next row (`next[j]`), which represents moving forward in `str`.
   - Value in the current row (`curr[j + 1]`), which represents moving forward in `revStr`.
7. **Update Current Row**: Store the result in `curr[j]`.
8. **Swap Rows**: At the end of the row, assign `curr` to `next`.

```cpp
    return curr[0];
```
9. **Final Result**: The LPS length is stored in `curr[0]`, which represents `dp[0][0]`.


### Example Output: `"bbbab"`

#### 1. Initialize:
- `curr = [0, 0, 0, 0, 0, 0]`  
- `next = [0, 0, 0, 0, 0, 0]`

#### 2. Table Traversal:
| `i` | `j` | Match? | `next[j+1]` | `next[j]` | `curr[j+1]` | `curr[j]` |
|-----|-----|--------|-------------|-----------|-------------|-----------|
| 4   | 4   | Yes    | 0           | 0         | 0           | 1         |
| 4   | 3   | Yes    | 1           | 0         | 0           | 1         |
| 3   | 4   | Yes    | 0           | 0         | 1           | 1         |
| ... | ... | ...    | ...         | ...       | ...         | ...       |

#### Final `curr`:
- `curr = [4, 3, 2, 1, 1, 0]`

#### Output:
- The value at `curr[0]` is **4**, representing the length of `"bbbb"`.

### Time Complexity
- **Outer Loop (`i`)**: Iterates `n` times.
- **Inner Loop (`j`)**: Iterates `m` times.
- **Total**: \( O(n \cdot m) \).

### Space Complexity
- Two 1D arrays of size `m + 1`: \( O(m) \).
