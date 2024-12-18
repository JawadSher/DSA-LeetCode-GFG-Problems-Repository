<h1 align="center">Wildcard - Matching</h1>

## Problem Statement

**Problem URL (leetcode):** [Wildcard Matching](https://leetcode.com/problems/wildcard-matching/description/)

**Problem URL (GFG):** [Wildcard Matching](https://www.geeksforgeeks.org/problems/wildcard-pattern-matching/1)

![image](https://github.com/user-attachments/assets/4b770134-562f-4fd4-8a87-1fd9d0c3e80a)

### Problem Explanation
The **Wildcard Matching** problem on LeetCode asks you to implement a function that checks if a given string matches a given pattern. The pattern can include wildcard characters:

- `?`: Matches any single character.
- `*`: Matches any sequence of characters (including the empty sequence).

### Problem Statement:
You are given two strings:
- `s`: The input string you need to match.
- `p`: The pattern string that may contain the wildcards `?` and `*`.

Your task is to return `true` if the string `s` matches the pattern `p`, and `false` otherwise.

### Key Points:
- The pattern `p` is allowed to contain:
  - `?`: which matches exactly one character.
  - `*`: which can match zero or more characters.
  
### Example 1:
**Input:**
```plaintext
s = "aa"
p = "a*"
```

**Explanation:**
- The pattern `a*` means "one or more 'a' characters".
- The string `aa` matches this pattern because the `*` wildcard can match both 'a' characters in the string.
  
**Output:** `true`


### Example 2:
**Input:**
```plaintext
s = "mississippi"
p = "mis*is*p*."
```

**Explanation:**
- The pattern `mis*is*p*.` means:
  - The string starts with `"mis"`.
  - Then there is a `*` which can match any sequence of characters, including `"ss"`.
  - Then `"is"`, then a `*` again (which can match `"p"`).
  - The final `.` matches any single character (in this case, it matches the last `i` in the string).
  
- The string `"mississippi"` matches this pattern.

**Output:** `true`


### Example 3:
**Input:**
```plaintext
s = "abcd"
p = "d*"
```

**Explanation:**
- The pattern `d*` means:
  - The string starts with the character `d`, followed by zero or more characters.
- However, the string `"abcd"` does not start with `d`, so it does not match the pattern.

**Output:** `false`


### Example 4:
**Input:**
```plaintext
s = "aaa"
p = "a*a"
```

**Explanation:**
- The pattern `a*a` means:
  - The string starts with `a`, followed by zero or more `a` characters, and then ends with `a`.
- The string `"aaa"` matches this pattern because the `*` can match the middle `a` and the pattern still holds.

**Output:** `true`

### Example 5:
**Input:**
```plaintext
s = "aa"
p = "a"
```

**Explanation:**
- The pattern `a` only matches a single character.
- The string `"aa"` has two characters, so it cannot match the pattern `a`.

**Output:** `false`

### Summary:
- `?` matches exactly one character.
- `*` can match zero or more characters, so it’s very flexible.
- The goal is to check if the entire string `s` matches the pattern `p` with the help of these wildcard characters.

---

## Recursive Approach (caused TLE)
The problem asks us to check if the string `s` matches the pattern `p` that contains wildcards:
- `?` matches any single character.
- `*` matches zero or more characters.

The recursive approach works by comparing the characters of the string and the pattern starting from the end of both strings and works its way back toward the beginning, exploring all possibilities recursively.

#### Recursive Function:
1. **Base Case 1:** If both the string (`str`) and the pattern (`ptrn`) are exhausted (i.e., both indices `i` and `j` are less than 0), return `true` because both have been completely matched.
2. **Base Case 2:** If the pattern is exhausted (i.e., `j < 0`) but the string still has characters left (i.e., `i >= 0`), return `false` because the pattern cannot match the remaining characters in the string.
3. **Base Case 3:** If the string is exhausted (i.e., `i < 0`) but the pattern still has characters left, check if all remaining characters in the pattern are `*`. If yes, return `true` (because `*` can match zero characters). Otherwise, return `false` because no other character can match.
4. **Case 1:** If the characters at positions `i` and `j` of the string and pattern match, or if the pattern has a `?` at position `j`, we move both pointers (`i` and `j`) one step back and continue checking.
5. **Case 2:** If the pattern has a `*` at position `j`, we explore two possibilities:
   - Treat `*` as matching the current character in the string (move only the string pointer `i`).
   - Treat `*` as matching zero characters (move only the pattern pointer `j`).
   If either possibility leads to a match, return `true`.
6. **Case 3:** If the characters at positions `i` and `j` of the string and pattern do not match, and it's not a wildcard (`?` or `*`), return `false`.

### Source Code
```cpp
class Solution {
public:
    // Recursive function to check if the pattern matches the string
    int solve(string &str, string &ptrn, int i, int j) {
        // Base case: If both string and pattern are exhausted, return true
        if (i < 0 && j < 0) return true;

        // Base case: If only the pattern is exhausted but the string is not, return false
        if (j < 0) return false;

        // Base case: If only the string is exhausted
        if (i < 0) {
            // Check if the remaining characters in the pattern are all '*'
            for (int k = 0; k <= j; k++) {
                if (ptrn[k] != '*') return false;
            }
            return true;
        }

        // Case 1: If characters match or the pattern has a '?', move both pointers
        if (str[i] == ptrn[j] || ptrn[j] == '?') {
            return solve(str, ptrn, i - 1, j - 1);
        }
        // Case 2: If the pattern has a '*', there are two possibilities:
        // - Treat '*' as matching the current character in the string (move string pointer `i` only)
        // - Treat '*' as matching zero characters (move pattern pointer `j` only)
        else if (ptrn[j] == '*') {
            return solve(str, ptrn, i - 1, j) || solve(str, ptrn, i, j - 1);
        }
        // Case 3: If characters don't match and it's not a wildcard, return false
        else {
            return false;
        }
    }

    // Main function to check if the string matches the pattern
    bool isMatch(string s, string p) {
        // Start the recursive process from the last characters of both string and pattern
        return solve(s, p, s.length() - 1, p.length() - 1);
    }
};
```

### Source Code Explanation
Let's consider the example where `s = "aa"` and `p = "a*"`, and explain each line of the code in detail.

#### Function `solve`:
```cpp
int solve(string &str, string &ptrn, int i, int j) {
    // Base case 1: If both string and pattern are exhausted, return true
    if (i < 0 && j < 0) return true;
```
- Here, if both `i` (index for `str`) and `j` (index for `ptrn`) are negative, meaning both the string and the pattern have been fully processed, return `true`.

```cpp
    // Base case 2: If only the pattern is exhausted but the string is not, return false
    if (j < 0) return false;
```
- If only the pattern is exhausted, but the string is not, it means the pattern hasn't matched all of the string, so return `false`.

```cpp
    // Base case 3: If only the string is exhausted
    if (i < 0) {
        // Check if the remaining characters in the pattern are all '*'
        for (int k = 0; k <= j; k++) {
            if (ptrn[k] != '*') return false;
        }
        return true;
    }
```
- If the string is exhausted (`i < 0`), but the pattern is not, check if the remaining characters in the pattern are all `*`. If they are, return `true` because `*` can match zero characters. If any character in the pattern is not `*`, return `false`.

```cpp
    // Case 1: If characters match or the pattern has a '?', move both pointers
    if (str[i] == ptrn[j] || ptrn[j] == '?') {
        return solve(str, ptrn, i - 1, j - 1);
    }
```
- If the current characters `str[i]` and `ptrn[j]` match, or if the pattern has a `?` (which matches any single character), then move both pointers (`i` and `j`) one step back and recursively call `solve`.

```cpp
    // Case 2: If the pattern has a '*', there are two possibilities:
    // - Treat '*' as matching the current character in the string (move string pointer `i` only)
    // - Treat '*' as matching zero characters (move pattern pointer `j` only)
    else if (ptrn[j] == '*') {
        return solve(str, ptrn, i - 1, j) || solve(str, ptrn, i, j - 1);
    }
```
- If the pattern has a `*`, there are two recursive cases:
  1. Treat `*` as matching the current character in the string (move only `i`).
  2. Treat `*` as matching zero characters (move only `j`).
- If either case leads to a match, return `true`.

```cpp
    // Case 3: If characters don't match and it's not a wildcard, return false
    else {
        return false;
    }
}
```
- If the characters do not match and the pattern does not have a wildcard (`?` or `*`), return `false`.

#### Function `isMatch`:
```cpp
bool isMatch(string s, string p) {
    return solve(s, p, s.length() - 1, p.length() - 1);
}
```
- This function simply calls the `solve` function with the last indices of both the string and the pattern. It starts the recursive matching process from the end of both strings.

### Example Walkthrough:

Let’s walk through an example where `s = "aa"` and `p = "a*"`:

1. We start with `i = 1` (last index of `s`) and `j = 1` (last index of `p`).
2. In the first call, `str[1] == 'a'` and `ptrn[1] == '*'`. Since `*` can match zero or more characters, we recursively check two cases:
   - Case 1: Treat `*` as matching the current character in the string (move `i` to 0).
   - Case 2: Treat `*` as matching zero characters (move `j` to 0).
3. In Case 1, we move `i` to 0, `j` remains 1, and the string becomes `"a"` and the pattern becomes `"*"`.
   - We again check `str[0] == 'a'` and `ptrn[1] == '*'`. We repeat the process.
4. In Case 2, we move `j` to 0 and recursively check the substring `"aa"` with the pattern `"a"`. This leads to a final match.

The output is `true` because the pattern `"a*"` successfully matches the string `"aa"`.

### Time and Space Complexity:

**Time Complexity:**
- In the worst case, the function explores all combinations of indices for the string and the pattern, leading to a time complexity of **O(2^(m+n))** where `m` is the length of the string and `n` is the length of the pattern.
- This is due to the recursive nature of the algorithm with the `*` wildcard, which creates two recursive calls each time.

**Space Complexity:**
- The space complexity is **O(m+n)** due to the recursion stack, where `m` is the length of the string and `n` is the length of the pattern. The recursion depth can go as deep as the sum of these two lengths.

---

## Top-Down Approach (DP)
The top-down approach with memoization optimizes the recursive solution for the wildcard matching problem by storing previously computed results to avoid redundant calculations. The idea is to break the problem into smaller subproblems, solve them recursively, and store the results in a table (a 2D DP array). This ensures that each subproblem is solved only once, reducing the time complexity significantly.

#### Key Steps in the Top-Down Approach:

1. **Recursive Function with Memoization:**  
   A recursive function (`solve`) is used to check if a substring of `s` matches a substring of `p`. The function uses a 2D memoization table (`dp`) to store the results of subproblems.
   
2. **Base Cases:**
   - **Both string and pattern are exhausted:** If both the string (`str[i]`) and the pattern (`ptrn[j]`) are exhausted, we return `true` because an empty string matches an empty pattern.
   - **Only the pattern is exhausted:** If only the pattern is exhausted but the string is not, we return `false` because a non-empty string cannot match an empty pattern.
   - **Only the string is exhausted:** If the string is exhausted but the pattern is not, we check if all remaining characters in the pattern are `*`. If they are, the result is `true` because `*` can match zero characters. Otherwise, return `false`.

3. **Recursive Step:**
   - If the characters `str[i]` and `ptrn[j]` match or if the pattern has `?`, move both pointers one step back and recurse.
   - If the pattern has `*`, we consider two cases:
     - Treat `*` as matching the current character (move only the string pointer `i`).
     - Treat `*` as matching zero characters (move only the pattern pointer `j`).

4. **Memoization:**  
   The result of each subproblem is stored in the 2D `dp` table to avoid recomputation.

### Source Code
```cpp
class Solution {
public:
    // Recursive function to check if the pattern matches the string with memoization
    int solve(string &str, string &ptrn, int i, int j, vector<vector<int>> &dp) {
        // Base case: If both string and pattern are exhausted, return true
        if (i < 0 && j < 0) return true;

        // Base case: If pattern is exhausted but the string is not, return false
        if (j < 0) return false;

        // Base case: If string is exhausted
        if (i < 0) {
            // Check if the remaining characters in the pattern are all '*'
            for (int k = 0; k <= j; k++) {
                if (ptrn[k] != '*') return false;
            }
            return true;
        }

        // Check if the result for this state is already computed
        if (dp[i][j] != -1) return dp[i][j];

        // Case 1: If characters match or the pattern has '?', move both pointers
        if (str[i] == ptrn[j] || ptrn[j] == '?') {
            dp[i][j] = solve(str, ptrn, i - 1, j - 1, dp);
        }
        // Case 2: If the pattern has '*', there are two possibilities:
        // - Treat '*' as matching the current character (move string pointer `i` only)
        // - Treat '*' as matching zero characters (move pattern pointer `j` only)
        else if (ptrn[j] == '*') {
            dp[i][j] = solve(str, ptrn, i - 1, j, dp) || solve(str, ptrn, i, j - 1, dp);
        }
        // Case 3: If characters don't match and it's not a wildcard, return false
        else {
            dp[i][j] = false;
        }

        // Return the computed result for this state
        return dp[i][j];
    }

    // Main function to check if the string matches the pattern
    bool isMatch(string s, string p) {
        int n = s.length(); // Length of the string
        int m = p.length(); // Length of the pattern

        // Initialize a 2D DP array with -1, where dp[i][j] represents the result
        // of matching the first i characters of the string with the first j characters of the pattern
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        // Start the recursive process with memoization
        return solve(s, p, n - 1, m - 1, dp);
    }
};
```

### Source Code Explanation

Let's go through the code line by line:

```cpp
int solve(string &str, string &ptrn, int i, int j, vector<vector<int>> &dp) {
    // Base case: If both string and pattern are exhausted, return true
    if (i < 0 && j < 0) return true;
```
- This checks if both the string and pattern have been completely processed. If so, we return `true` because an empty string matches an empty pattern.

```cpp
    // Base case: If pattern is exhausted but the string is not, return false
    if (j < 0) return false;
```
- If the pattern is exhausted but the string is not, it’s impossible for the pattern to match the remaining characters in the string, so we return `false`.

```cpp
    // Base case: If string is exhausted
    if (i < 0) {
        // Check if the remaining characters in the pattern are all '*'
        for (int k = 0; k <= j; k++) {
            if (ptrn[k] != '*') return false;
        }
        return true;
    }
```
- If the string is exhausted but the pattern is not, we check if all remaining characters in the pattern are `*`. If so, return `true`, because `*` can match zero characters. Otherwise, return `false`.

```cpp
    // Check if the result for this state is already computed
    if (dp[i][j] != -1) return dp[i][j];
```
- This line checks if the result for the current state (`i`, `j`) has already been computed. If it has, return the stored result to avoid redundant calculations.

```cpp
    // Case 1: If characters match or the pattern has '?', move both pointers
    if (str[i] == ptrn[j] || ptrn[j] == '?') {
        dp[i][j] = solve(str, ptrn, i - 1, j - 1, dp);
    }
```
- If the characters at `str[i]` and `ptrn[j]` match or if the pattern has a `?`, we move both pointers one step back (`i - 1`, `j - 1`) and recursively call `solve`.

```cpp
    // Case 2: If the pattern has '*', there are two possibilities:
    // - Treat '*' as matching the current character (move string pointer `i` only)
    // - Treat '*' as matching zero characters (move pattern pointer `j` only)
    else if (ptrn[j] == '*') {
        dp[i][j] = solve(str, ptrn, i - 1, j, dp) || solve(str, ptrn, i, j - 1, dp);
    }
```
- If the pattern has a `*`, we have two choices:
  1. Treat `*` as matching the current character (`str[i]`), so we move only the string pointer (`i - 1`).
  2. Treat `*` as matching zero characters, so we move only the pattern pointer (`j - 1`).
- The result is the logical OR of both recursive calls.

```cpp
    // Case 3: If characters don't match and it's not a wildcard, return false
    else {
        dp[i][j] = false;
    }
```
- If the characters don't match and the pattern is not a wildcard, we set `dp[i][j] = false` because there's no possible match.

```cpp
    // Return the computed result for this state
    return dp[i][j];
}
```
- The result of the current state (`i`, `j`) is stored in `dp[i][j]` and returned.

```cpp
bool isMatch(string s, string p) {
    int n = s.length(); // Length of the string
    int m = p.length(); // Length of the pattern

    // Initialize a 2D DP array with -1, where dp[i][j] represents the result
    // of matching the first i characters of the string with the first j characters of the pattern
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // Start the recursive process with memoization
    return solve(s, p, n - 1, m - 1, dp);
}
```
- The `isMatch` function initializes a 2D memoization table `dp` with dimensions `(n+1) x (m+1)` where `n` is the length of the string and `m` is the length of the pattern. The table is initialized to `-1`, which indicates that no result has been computed for that state.
- The function then calls `solve` with the starting indices (`n-1`, `m-1`), which corresponds to the last characters of the string and pattern.

### Example Walkthrough:

Consider the example `s = "aa"` and `p = "a*"`:

1. `i = 1`, `j = 1` (characters: `s[1] = 'a'`, `p[1] = '*'`)
   - `*` matches zero or more characters. We try two recursive calls:
     1. Treat `*` as matching the current character (`i = 0`, `j = 1`).
     2. Treat `*` as matching zero characters (`i = 1`, `j = 0`).
   
2. **Recursive call 1** (`i = 0`, `j = 1`):
   - `s[0] = 'a'`, `p[1] = '*'`
   - Again, we try two cases:
     1. Treat `*` as matching the current character (`i = -1`, `j = 1`).
     2. Treat `*` as matching zero characters (`i = 0`, `j = 0`).

3. **Recursive call 2** (`i = 0`, `j = 0`):
   - `s[0] = 'a'`, `p[0] = 'a'`: They match, so we move to the next recursion (`i = -1`, `j = -1`), which returns `true`.

4. The result `true` is stored in the memoization table, and `true` is returned.

### Time and Space Complexity:

**Time Complexity:**
- The time complexity is **O(m * n)**, where `m` is the length of the pattern and `n` is the length of the string. This is because each state in the 2D `dp` table is computed once, and there are `m * n` states.

**Space Complexity:**
- The space complexity is **O(m * n)** due to the memoization table (`dp`) storing the results of subproblems. Additionally, the recursion stack contributes an extra space complexity of **O(m + n)**, but the memoization table dominates the space complexity.

---

## Bottom-Up Approach (DP)
The bottom-up approach in dynamic programming solves subproblems first and builds upon them to solve larger problems. This approach avoids recursion and uses an iterative method, which is generally more efficient in terms of space and time for problems like string matching. 

In this approach, we use a dynamic programming table (`dp`) to store whether a certain substring of the string matches a certain prefix of the pattern. The final value in the table represents whether the full string matches the full pattern.

#### Steps:
1. **Initialization:** We initialize a DP table `dp[i][j]` where `i` represents the first `i` characters of the string and `j` represents the first `j` characters of the pattern.
   
2. **Base Case:** An empty string matches an empty pattern, so `dp[0][0] = true`. We then handle cases where the string is empty but the pattern has only `*` characters.

3. **Filling the DP Table:**
   - If a character in the string matches the character in the pattern, or if the pattern has a `?`, we inherit the result from the previous state (`dp[i-1][j-1]`).
   - If the pattern has a `*`, it can either:
     - Match the current character in the string (move the string pointer).
     - Match zero characters (move the pattern pointer).
   - If neither of the above cases is true, we set the current state to false.

4. **Final Result:** After filling the DP table, `dp[n][m]` (where `n` is the length of the string and `m` is the length of the pattern) will contain the result of whether the entire string matches the entire pattern.

#### Example:

Consider `s = "abc"` and `p = "a*c"`:

|   |  | a | * | c |
||||||
| **""** | T | F | T | F |
| **a**  | F | T | T | T |
| **ab** | F | T | T | T |
| **abc** | F | T | T | T |

1. `dp[0][0] = true` (empty string matches empty pattern).
2. `dp[0][1] = false` because pattern has `a` but string is empty.
3. `dp[1][0] = false` because string has `a` but pattern is empty.
4. `dp[1][1] = true` because both string and pattern have `a`.
5. `dp[1][2] = true` because pattern has `*` which can match zero or more characters.
6. Continue filling the table until `dp[3][3] = true`.

### Source Code
```cpp
class Solution {
public:
    // Function to determine if the string matches the pattern using dynamic programming
    int solve(string &str, string &ptrn) {
        int n = str.length(); // Length of the string
        int m = ptrn.length(); // Length of the pattern

        // DP table to store the results of subproblems
        // dp[i][j] represents whether the first `i` characters of the string match the first `j` characters of the pattern
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base case: An empty string matches an empty pattern
        dp[0][0] = true;

        // Handle cases where the string is empty but the pattern has characters
        for (int j = 1; j <= m; j++) {
            bool flag = true; // Check if all characters in the pattern up to `j` are '*'
            for (int k = 1; k <= j; k++) {
                if (ptrn[k - 1] != '*') { // If a non-'*' character is found, stop
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag; // Set `dp[0][j]` to true if all characters are '*', otherwise false
        }

        // Fill the DP table for cases where both string and pattern have characters
        for (int i = 1; i <= n; i++) { // Iterate over the string
            for (int j = 1; j <= m; j++) { // Iterate over the pattern
                // Case 1: Characters match or the pattern has '?'
                if (str[i - 1] == ptrn[j - 1] || ptrn[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                // Case 2: Pattern has '*'
                // - '*' can match the current character in the string (move string pointer `i-1`)
                // - '*' can match zero characters (move pattern pointer `j-1`)
                else if (ptrn[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                // Case 3: Characters do not match and there's no wildcard
                else {
                    dp[i][j] = false;
                }
            }
        }

        // The result for the full string and pattern is stored in `dp[n][m]`
        return dp[n][m];
    }

    // Main function to check if the string matches the pattern
    bool isMatch(string s, string p) {
        return solve(s, p);
    }
};
```

### Source Code Explanation

```cpp
class Solution {
public:
    // Function to determine if the string matches the pattern using dynamic programming
    int solve(string &str, string &ptrn) {
        int n = str.length(); // Length of the string
        int m = ptrn.length(); // Length of the pattern

        // DP table to store the results of subproblems
        // dp[i][j] represents whether the first `i` characters of the string match the first `j` characters of the pattern
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
```
- This function uses dynamic programming to solve the problem. The `dp` table has dimensions `(n+1) x (m+1)` where `n` is the length of the string and `m` is the length of the pattern.
- `dp[i][j]` stores whether the first `i` characters of `str` match the first `j` characters of `ptrn`.

```cpp
        // Base case: An empty string matches an empty pattern
        dp[0][0] = true;
```
- The base case is set here: an empty string matches an empty pattern.

```cpp
        // Handle cases where the string is empty but the pattern has characters
        for (int j = 1; j <= m; j++) {
            bool flag = true; // Check if all characters in the pattern up to `j` are '*'
            for (int k = 1; k <= j; k++) {
                if (ptrn[k - 1] != '*') { // If a non-'*' character is found, stop
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag; // Set `dp[0][j]` to true if all characters are '*', otherwise false
        }
```
- Here, we handle the case where the string is empty, but the pattern may contain characters.
- If the pattern consists only of `*` characters up to index `j`, then `dp[0][j] = true` (empty string matches pattern with only `*`).
- If any non-`*` character is found, `dp[0][j] = false`.

```cpp
        // Fill the DP table for cases where both string and pattern have characters
        for (int i = 1; i <= n; i++) { // Iterate over the string
            for (int j = 1; j <= m; j++) { // Iterate over the pattern
                // Case 1: Characters match or the pattern has '?'
                if (str[i - 1] == ptrn[j - 1] || ptrn[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
```
- If the characters match (i.e., `str[i-1] == ptrn[j-1]`) or the pattern has `?`, then `dp[i][j]` is inherited from `dp[i-1][j-1]`.

```cpp
                // Case 2: Pattern has '*'
                // - '*' can match the current character in the string (move string pointer `i-1`)
                // - '*' can match zero characters (move pattern pointer `j-1`)
                else if (ptrn[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
```
- If the pattern has `*`, then it can match either:
  1. The current character in the string (move the string pointer `i-1`), i.e., `dp[i-1][j]`.
  2. Zero characters (move the pattern pointer `j-1`), i.e., `dp[i][j-1]`.

```cpp
                // Case 3: Characters do not match and there's no wildcard
                else {
                    dp[i][j] = false;
                }
            }
        }
```
- If the characters do not match and there is no wildcard (`*` or `?`), `dp[i][j]` is set to `false`.

```cpp
        // The result for the full string and pattern is stored in `dp[n][m]`
        return dp[n][m];
    }
```
- The final result is stored in `dp[n][m]`, which tells us whether the full string matches the full pattern.

```cpp
    // Main function to check if the string matches the pattern
    bool isMatch(string s, string p) {
        return solve(s, p);
    }
};
```
- The `isMatch` function is the main entry point that calls `solve` with the string and pattern as arguments.

### Example Output Explanation

For `s = "abc"` and `p = "a*c"`, the DP table looks like this:

|   |  | a | * | c |
||||||
| **""** | T | F | T | F |
| **a**  | F | T | T | T |
| **ab** | F | T | T | T |
| **abc** | F | T | T | T |

- The final result is `dp[3][3] = true`, which means that the entire string "abc" matches the pattern "a*c".

### Time and Space Complexities

- **Time Complexity:**
  - The function iterates through each character of the string (`n` characters) and each character of the pattern (`m` characters).
  - Therefore, the time complexity is **O(n * m)**, where `n` is the length of the string and `m` is the length of the pattern.

- **Space Complexity:**
  - The space complexity is determined by the DP table, which has dimensions `(n+1) x (m+1)`.
  - Therefore, the space complexity is **O(n * m)**.

This approach efficiently solves the problem with a clear iterative approach using dynamic programming.

---

## Space Optimization Approach (DP)
The goal of the space-optimized approach is to reduce the space complexity of the original dynamic programming solution. Instead of using a 2D table, we use two 1D arrays (vectors) to store the results for the current and previous rows. This reduces the memory footprint significantly while maintaining the correctness of the algorithm.

#### Space Optimization Steps:

1. **Initial Setup**:
   - The original dynamic programming solution uses a 2D array `dp` of size `(n+1) x (m+1)` where `n` is the length of the string and `m` is the length of the pattern. This is space-inefficient, especially for large inputs.
   - In the space-optimized approach, we use two 1D arrays (`prev` and `curr`), each of size `m+1`. These arrays will store the results for the previous and current rows, respectively, reducing space complexity to `O(m)`.

2. **Base Case**:
   - We initialize `prev[0] = true` because an empty string matches an empty pattern.

3. **Pattern Matching for Empty String**:
   - If the string is empty but the pattern has characters, we set `prev[j]` to `true` for all `j` where the pattern contains only `'*'` characters. This is because `'*'` can match zero characters in the string.

4. **DP Transitions**:
   - For each character in the string (`i` from 1 to `n`), and each character in the pattern (`j` from 1 to `m`), we calculate whether the string matches the pattern at that position:
     - If the characters match or if the pattern has a wildcard `'?'`, we update `curr[j]` based on `prev[j-1]`.
     - If the pattern has `'*'`, it can either match zero characters (i.e., look at `curr[j-1]`) or one or more characters (i.e., look at `prev[j]`).
     - Otherwise, `curr[j]` is set to `false`.

5. **Updating Rows**:
   - After processing each row (`i`), we copy the contents of `curr` to `prev` to "move" to the next row.

6. **Final Result**:
   - The final result, indicating whether the entire string matches the pattern, is stored in `prev[m]` after all iterations.

### Source Code
```cpp
class Solution {
public:
    // Function to determine if the string matches the pattern using space-optimized dynamic programming
    int solve(string &str, string &ptrn) {
        int n = str.length(); // Length of the input string
        int m = ptrn.length(); // Length of the pattern

        // Two 1D vectors for storing the current and previous rows of the DP table
        vector<int> prev(m + 1, 0); // Represents the DP state for the previous row
        vector<int> curr(m + 1, 0); // Represents the DP state for the current row

        // Base case: An empty string matches an empty pattern
        prev[0] = true;

        // Handle cases where the string is empty but the pattern has characters
        for (int j = 1; j <= m; j++) {
            bool flag = true; // Check if all characters in the pattern up to `j` are '*'
            for (int k = 1; k <= j; k++) {
                if (ptrn[k - 1] != '*') { // If a non-'*' character is found, stop
                    flag = false;
                    break;
                }
            }

            // Set `prev[j]` to true if all characters in the pattern are '*', otherwise false
            prev[j] = flag;
        }

        // Iterate over the characters in the string
        for (int i = 1; i <= n; i++) {
            // Iterate over the characters in the pattern
            for (int j = 1; j <= m; j++) {
                // Case 1: Characters match or the pattern has '?'
                if (str[i - 1] == ptrn[j - 1] || ptrn[j - 1] == '?') {
                    curr[j] = prev[j - 1]; // Match depends on the previous diagonal value
                }
                // Case 2: Pattern has '*'
                // '*' can match the current character (`prev[j]`) or match zero characters (`curr[j-1]`)
                else if (ptrn[j - 1] == '*') {
                    curr[j] = prev[j] || curr[j - 1];
                }
                // Case 3: Characters do not match and there's no wildcard
                else {
                    curr[j] = false;
                }
            }

            // After processing the current row, update `prev` to be the same as `curr`
            prev = curr;
        }

        // The result for the full string and pattern is stored in `prev[m]`
        return prev[m];
    }

    // Main function to check if the string matches the pattern
    bool isMatch(string s, string p) {
        return solve(s, p);
    }
};
```

### Source Code Explanation
```cpp
class Solution {
public:
    // Function to determine if the string matches the pattern using space-optimized dynamic programming
    int solve(string &str, string &ptrn) {
        int n = str.length(); // Length of the input string
        int m = ptrn.length(); // Length of the pattern

        // Two 1D vectors for storing the current and previous rows of the DP table
        vector<int> prev(m + 1, 0); // Represents the DP state for the previous row
        vector<int> curr(m + 1, 0); // Represents the DP state for the current row
```

#### Line 1-4:
- The `solve` function is designed to check if the string `str` matches the pattern `ptrn` using dynamic programming with space optimization.
- We get the lengths of the string (`n`) and the pattern (`m`).

#### Line 5-6:
- We create two 1D vectors: `prev` and `curr`. 
  - `prev` stores the results for the previous row of the DP table.
  - `curr` stores the results for the current row.
- Both vectors are initialized with size `m+1` because the pattern can be of length `m`, and we need an extra element to account for the base case (empty pattern matching).



```cpp
        // Base case: An empty string matches an empty pattern
        prev[0] = true;
```

#### Line 7:
- We initialize `prev[0] = true` to indicate that an empty string matches an empty pattern.
- This is the base case: if both the string and the pattern are empty, they match.



```cpp
        // Handle cases where the string is empty but the pattern has characters
        for (int j = 1; j <= m; j++) {
            bool flag = true; // Check if all characters in the pattern up to `j` are '*'
            for (int k = 1; k <= j; k++) {
                if (ptrn[k - 1] != '*') { // If a non-'*' character is found, stop
                    flag = false;
                    break;
                }
            }

            // Set `prev[j]` to true if all characters in the pattern are '*', otherwise false
            prev[j] = flag;
        }
```

#### Lines 8-13:
- This loop handles the case when the string is empty but the pattern has characters.
- If the pattern consists only of `*` characters (because `*` can match zero characters), we set `prev[j]` to `true`.
- Otherwise, if the pattern contains any non-`*` characters, we set `prev[j]` to `false`.

#### Example:
For `str = ""` and `ptrn = "****"`, after this loop, `prev[4] = true` because `*` can match zero characters.


```cpp
        // Iterate over the characters in the string
        for (int i = 1; i <= n; i++) {
            // Iterate over the characters in the pattern
            for (int j = 1; j <= m; j++) {
                // Case 1: Characters match or the pattern has '?'
                if (str[i - 1] == ptrn[j - 1] || ptrn[j - 1] == '?') {
                    curr[j] = prev[j - 1]; // Match depends on the previous diagonal value
                }
```

#### Lines 14-17:
- We begin iterating over each character in the string (`i` from 1 to `n`) and each character in the pattern (`j` from 1 to `m`).
- **Case 1: Characters match or the pattern has `'?'`**:
  - If the current characters of the string (`str[i-1]`) and the pattern (`ptrn[j-1]`) are the same, or if the pattern has a `'?'` (which can match any character), we set `curr[j] = prev[j-1]`.
  - This means that the current position in the string and the pattern match based on the previous diagonal state.

#### Example:
For `str = "abc"` and `ptrn = "a?c"`, when we reach `i = 1` and `j = 1` (matching `'a'` with `'a'`), we update `curr[1] = prev[0]`.



```cpp
                // Case 2: Pattern has '*'
                // '*' can match the current character (`prev[j]`) or match zero characters (`curr[j-1]`)
                else if (ptrn[j - 1] == '*') {
                    curr[j] = prev[j] || curr[j - 1];
                }
```

#### Lines 18-21:
- **Case 2: The pattern has `'*'`**:
  - If the pattern has a `'*'`, it can match:
    1. Zero characters (this is checked by `curr[j-1]`).
    2. One or more characters (this is checked by `prev[j]`).
  - Therefore, we update `curr[j] = prev[j] || curr[j-1]`.

#### Example:
For `str = "abc"` and `ptrn = "a*b*"`, when we reach `i = 3` and `j = 3`, we update `curr[3]` based on the previous states.



```cpp
                // Case 3: Characters do not match and there's no wildcard
                else {
                    curr[j] = false;
                }
            }
```

#### Lines 22-25:
- **Case 3: Characters do not match and there's no wildcard**:
  - If the current characters in the string and pattern don't match, and there is no wildcard (`*` or `?`), we set `curr[j] = false`.



```cpp
            // After processing the current row, update `prev` to be the same as `curr`
            prev = curr;
        }
```

#### Lines 26-27:
- After processing each row of the string, we update `prev` to be equal to `curr`. This moves to the next row in the DP table.

#### Example:
For `str = "abc"` and `ptrn = "a*b?"`, once the current row has been processed, we set `prev = curr`, and we move to the next row.



```cpp
        // The result for the full string and pattern is stored in `prev[m]`
        return prev[m];
    }
```

#### Lines 28-30:
- The final result of the match (whether the entire string matches the entire pattern) is stored in `prev[m]`.
- `prev[m]` indicates whether the entire string `str` matches the entire pattern `ptrn`.



### Explanation of the Example:

Consider the example:

```cpp
string str = "abc";
string ptrn = "a*c";
```

- **Base Case**:
  - `prev[0] = true`, as an empty string matches an empty pattern.
  - `prev[j]` will be updated for patterns like `*`.

- **Loop Iteration**:
  - For `i = 1` and `j = 1`, we match `'a'` with `'a'`, so `curr[1] = prev[0]` (i.e., `true`).
  - For `i = 2` and `j = 2`, we match `'b'` with `'*'`, so `curr[2] = prev[2] || curr[1]`.
  - For `i = 3` and `j = 3`, we match `'c'` with `'c'`, so `curr[3] = prev[2]`.

- **Final Result**:
  - After all iterations, `prev[m]` will be `true`, meaning that the string `abc` matches the pattern `a*c`.



### Time and Space Complexity:

- **Time Complexity**: 
  - We have two nested loops: one for the string (of length `n`) and one for the pattern (of length `m`). Thus, the time complexity is `O(n * m)`.

- **Space Complexity**: 
  - We are using two 1D arrays (`prev` and `curr`), each of size `m+1`. So, the space complexity is `O(m)`, which is a significant improvement over the original `O(n * m)` space complexity for the 2D DP table.



