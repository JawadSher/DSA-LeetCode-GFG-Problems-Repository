<h1 align="center">Edit - Distance</h1>

## Problem Statement

**Problem URL :** [Edit Distance](https://leetcode.com/problems/edit-distance/description/)

![image](https://github.com/user-attachments/assets/f75357fc-d434-4ea7-9d43-59e9b1f9f369)

### Problem Explanation
The **Edit Distance** problem, also known as **Levenshtein Distance**, is a well-known problem in computer science. The task is to determine the minimum number of operations needed to transform one string (`word1`) into another (`word2`). The allowed operations are:

1. **Insertion**: Inserting a character into the first string.
2. **Deletion**: Removing a character from the first string.
3. **Replacement**: Replacing a character in the first string with a character from the second string.

Each of these operations has a cost of 1, and the goal is to find the minimum cost required to transform one string into the other.



### **Problem Definition:**

Given two strings `word1` and `word2`, the objective is to calculate the **minimum number of operations** required to convert `word1` into `word2` using the allowed operations.

### **Example 1:**

#### **Input:**
```plaintext
word1 = "horse"
word2 = "ros"
```

#### **Operations:**
We want to transform `"horse"` into `"ros"`. The minimum number of operations to achieve this would be:

1. **Replace** 'h' with 'r': `"horse"` → `"rorse"`
2. **Delete** 'r' from `"rorse"`: `"rorse"` → `"rose"`
3. **Delete** 'e' from `"rose"`: `"rose"` → `"ros"`

So, the minimum number of operations required is **3**.

#### **Output:**
```plaintext
3
```



### **Example 2:**

#### **Input:**
```plaintext
word1 = "intention"
word2 = "execution"
```

#### **Operations:**
We want to transform `"intention"` into `"execution"`. The minimum number of operations to achieve this would be:

1. **Replace** 'i' with 'e': `"intention"` → `"extention"`
2. **Replace** 'n' with 'c': `"extention"` → `"excetion"`
3. **Replace** 't' with 'u': `"excetion"` → `"execuion"`
4. **Replace** 'e' with 't': `"execuion"` → `"executin"`
5. **Replace** 'i' with 'o': `"executin"` → `"execution"`

So, the minimum number of operations required is **5**.

#### **Output:**
```plaintext
5
```



### **Example 3:**

#### **Input:**
```plaintext
word1 = "kitten"
word2 = "sitting"
```

#### **Operations:**
We want to transform `"kitten"` into `"sitting"`. The minimum number of operations to achieve this would be:

1. **Replace** 'k' with 's': `"kitten"` → `"sitten"`
2. **Insert** 'i' at the end: `"sitten"` → `"sitting"`

So, the minimum number of operations required is **3**.

#### **Output:**
```plaintext
3
```



### **Example 4:**

#### **Input:**
```plaintext
word1 = "flaw"
word2 = "lawn"
```

#### **Operations:**
We want to transform `"flaw"` into `"lawn"`. The minimum number of operations to achieve this would be:

1. **Replace** 'f' with 'l': `"flaw"` → `"law"`
2. **Insert** 'n' at the end: `"law"` → `"lawn"`

So, the minimum number of operations required is **2**.

#### **Output:**
```plaintext
2
```


### **Summary:**

The Edit Distance problem involves transforming one string into another by applying a series of operations (insertion, deletion, or replacement) to minimize the number of operations. The problem can be solved by finding the most efficient sequence of operations to transform the first string into the second string. 

The main objective is to calculate the **minimum number of operations** required to convert one string into another, as demonstrated through various examples like `"horse"` to `"ros"`, `"intention"` to `"execution"`, etc.

---

## Recursive Approach (caused TLE)
The problem is to compute the **edit distance** between two strings, where the allowed operations are insertion, deletion, and replacement. The recursive approach solves this problem by breaking it down into smaller subproblems.

Let’s go through the recursive approach step by step using an example.

### **Recursive Approach with Example:**

**Given Strings:**
- `word1 = "horse"`
- `word2 = "ros"`

We will calculate the minimum edit distance (or the number of operations) to convert `word1` into `word2`.

#### **Step 1: Compare the Characters**

We start by comparing the characters at the current positions of both strings:
- `word1[i] = "h"`
- `word2[j] = "r"`

Since these characters are not the same, we need to perform one of the three operations: **insertion**, **deletion**, or **replacement**.

#### **Step 2: Recursively Apply Operations**

For each of the three operations, we calculate the new distance recursively:

1. **Insert Operation**: We insert the current character from `word2[j]` into `word1`. This corresponds to moving to the next character in `word2` and staying at the current position in `word1`. The recursion would look like `solve(word1, word2, i, j+1)`, where `i = 0` and `j = 1`.

2. **Delete Operation**: We delete the current character from `word1[i]`. This corresponds to moving to the next character in `word1` and staying at the current position in `word2`. The recursion would look like `solve(word1, word2, i+1, j)`, where `i = 1` and `j = 0`.

3. **Replace Operation**: We replace the current character of `word1[i]` with the current character of `word2[j]`. This corresponds to moving to the next character in both `word1` and `word2`. The recursion would look like `solve(word1, word2, i+1, j+1)`, where `i = 1` and `j = 1`.

#### **Step 3: Base Case**

If we have reached the end of one of the strings:
- If `i >= n` (i.e., `word1` is fully processed), the remaining distance is the length of the remaining characters in `word2` (i.e., `m - j` insertions are needed).
- If `j >= m` (i.e., `word2` is fully processed), the remaining distance is the length of the remaining characters in `word1` (i.e., `n - i` deletions are needed).

#### **Step 4: Choose the Minimum Operation**

The solution for this subproblem is the minimum of the three options (insert, delete, replace).

### Source Code
```cpp
class Solution {
public:
    // Helper function to calculate the minimum distance (edit distance) recursively
    int solve(string word1, string word2, int i, int j) {
        int n = word1.length(); // Length of the first string
        int m = word2.length(); // Length of the second string

        // Base cases: If one string is fully traversed, the remaining length of the other string is the answer
        if (i >= n) return m - j;  // If word1 is fully traversed, we need to insert remaining characters of word2
        if (j >= m) return n - i;  // If word2 is fully traversed, we need to delete remaining characters of word1
        
        int ans = 0;

        // If characters at the current positions match, move to the next character in both strings
        if (word1[i] == word2[j]) return solve(word1, word2, i + 1, j + 1);
        else {
            // If characters do not match, consider the three possible operations:
            // 1. Insert a character into word1 (move j ahead in word2)
            int insertAns = 1 + solve(word1, word2, i, j + 1);

            // 2. Delete a character from word1 (move i ahead in word1)
            int deleteAns = 1 + solve(word1, word2, i + 1, j);

            // 3. Replace a character in word1 (move both i and j ahead)
            int replaceAns = 1 + solve(word1, word2, i + 1, j + 1);

            // The minimum of these three options gives the optimal edit distance at this step
            ans = min({insertAns, deleteAns, replaceAns});
        }

        // Return the minimum edit distance
        return ans;
    }

    // Main function that calculates the minimum distance between word1 and word2
    int minDistance(string word1, string word2) {
        return solve(word1, word2, 0, 0);  // Start the recursion from the beginning of both strings
    }
};
```

### Source Code Explanation

```cpp
int solve(string word1, string word2, int i, int j) {
    int n = word1.length(); // Length of the first string
    int m = word2.length(); // Length of the second string
```
- The function `solve` takes the two strings and the current indices `i` and `j` for `word1` and `word2`, respectively.
- `n` and `m` represent the lengths of `word1` and `word2`.

```cpp
    // Base cases: If one string is fully traversed, the remaining length of the other string is the answer
    if (i >= n) return m - j;  // If word1 is fully traversed, we need to insert remaining characters of word2
    if (j >= m) return n - i;  // If word2 is fully traversed, we need to delete remaining characters of word1
```
- These are the base cases:
  - If `i` reaches the end of `word1`, then we need to insert the remaining characters of `word2`, which is `m - j`.
  - If `j` reaches the end of `word2`, then we need to delete the remaining characters of `word1`, which is `n - i`.

```cpp
    int ans = 0;
```
- This variable will store the minimum number of operations required to transform the strings from index `i` and `j` onward.

```cpp
    // If characters at the current positions match, move to the next character in both strings
    if (word1[i] == word2[j]) return solve(word1, word2, i + 1, j + 1);
```
- If the characters at the current positions match (`word1[i] == word2[j]`), then we simply move to the next characters in both strings by calling `solve(word1, word2, i + 1, j + 1)`.

```cpp
    else {
        // If characters do not match, consider the three possible operations:
        // 1. Insert a character into word1 (move j ahead in word2)
        int insertAns = 1 + solve(word1, word2, i, j + 1);

        // 2. Delete a character from word1 (move i ahead in word1)
        int deleteAns = 1 + solve(word1, word2, i + 1, j);

        // 3. Replace a character in word1 (move both i and j ahead)
        int replaceAns = 1 + solve(word1, word2, i + 1, j + 1);

        // The minimum of these three options gives the optimal edit distance at this step
        ans = min({insertAns, deleteAns, replaceAns});
    }
```
- If the characters at the current positions do not match, we compute the results for the three operations (insert, delete, replace) and add 1 to the results (since each operation has a cost of 1).
- We then take the minimum of these three options (`insertAns`, `deleteAns`, and `replaceAns`) to get the optimal number of operations.

```cpp
    // Return the minimum edit distance
    return ans;
}
```
- Finally, the function returns the computed minimum edit distance for the given subproblem.

```cpp
int minDistance(string word1, string word2) {
    return solve(word1, word2, 0, 0);  // Start the recursion from the beginning of both strings
}
```
- The `minDistance` function simply calls the `solve` function with initial indices (`i = 0`, `j = 0`), which starts the recursive process of computing the edit distance.



### **Example Output Explanation**

Let’s walk through the example:

**Example:**
```plaintext
word1 = "horse"
word2 = "ros"
```

- Starting at `word1[0] = "h"` and `word2[0] = "r"`, we see that the characters are different, so we calculate the three possible operations:
  1. **Insert**: `"horse"` → `"horse"` (insert 'r') → move to `word1[0]`, `word2[1]`.
  2. **Delete**: `"horse"` → `"orse"` (delete 'h') → move to `word1[1]`, `word2[0]`.
  3. **Replace**: `"horse"` → `"rorse"` (replace 'h' with 'r') → move to `word1[1]`, `word2[1]`.

Through recursive calls, the function determines that 3 operations are required in total, resulting in the minimum number of operations.

#### **Output:**
```plaintext
3
```



### **Time and Space Complexity**

#### **Time Complexity:**

- In the recursive approach, the function explores all possible subproblems of the two strings. For each pair of indices `(i, j)`, there are 3 choices (insert, delete, replace).
- In the worst case, the number of subproblems is proportional to the product of the lengths of `word1` and `word2`, i.e., `O(n * m)`, where `n` and `m` are the lengths of the two strings.
- Each subproblem is solved recursively with overlapping subproblems, leading to exponential time complexity without memoization.

**Time Complexity: `O(3^(min(n, m)))` in the naive recursive approach.**

#### **Space Complexity:**

- The space complexity of this recursive approach is `O(n + m)` due to the recursion depth (the call stack).

**Space Complexity: `O(n + m)` for the recursion stack.**

---

## Top-down Approach (DP)
The top-down approach uses recursion and memoization to calculate the minimum edit distance between two strings. The idea is to break down the problem into smaller subproblems and store the results of each subproblem to avoid redundant calculations (memoization).

#### Key Concepts:
1. **Recursive Structure**: The problem is broken down into smaller subproblems where the minimum distance between two substrings is calculated using three possible operations: insertion, deletion, and replacement.
2. **Memoization**: The results of subproblems are stored in a memoization table (`dp`), so each subproblem is only solved once.

#### Recursive Strategy:
1. **Base Case**: If one of the strings is fully traversed, we calculate the number of operations required to transform the remaining characters of the other string. This would either be insertions or deletions.
   - If `i` (index of `word1`) exceeds `n` (length of `word1`), return the remaining length of `word2` (`m - j`).
   - If `j` (index of `word2`) exceeds `m` (length of `word2`), return the remaining length of `word1` (`n - i`).
2. **Recursion**: If the characters at the current indices match (`word1[i] == word2[j]`), we move to the next pair of characters (`i+1, j+1`).
3. If the characters do not match, three operations are considered:
   - **Insert**: Insert a character into `word1` (increment `j`).
   - **Delete**: Delete a character from `word1` (increment `i`).
   - **Replace**: Replace the character in `word1` with the character from `word2` (increment both `i` and `j`).
4. The minimum of these three operations will be the optimal edit distance for the current subproblem.

### Source Code
```cpp
class Solution {
public:
    // Helper function to calculate the minimum distance (edit distance) using recursion and memoization
    int solve(string word1, string word2, int i, int j, vector<vector<int>> &dp) {
        int n = word1.length(); // Length of the first string
        int m = word2.length(); // Length of the second string

        // Base cases: If one string is fully traversed, the remaining length of the other string is the answer
        if (i >= n) return m - j;  // If word1 is fully traversed, we need to insert remaining characters of word2
        if (j >= m) return n - i;  // If word2 is fully traversed, we need to delete remaining characters of word1

        // If the result for this subproblem is already computed (cached in dp table), return it
        if (dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;

        // If characters at the current positions match, move to the next character in both strings
        if (word1[i] == word2[j]) return solve(word1, word2, i + 1, j + 1, dp);
        else {
            // If characters do not match, consider the three possible operations:
            // 1. Insert a character into word1 (move j ahead in word2)
            int insertAns = 1 + solve(word1, word2, i, j + 1, dp);

            // 2. Delete a character from word1 (move i ahead in word1)
            int deleteAns = 1 + solve(word1, word2, i + 1, j, dp);

            // 3. Replace a character in word1 (move both i and j ahead)
            int replaceAns = 1 + solve(word1, word2, i + 1, j + 1, dp);

            // The minimum of these three options gives the optimal edit distance at this step
            ans = min({insertAns, deleteAns, replaceAns});
        }

        // Store the computed result in the dp table and return it
        return dp[i][j] = ans;
    }

    // Main function that calculates the minimum distance between word1 and word2
    int minDistance(string word1, string word2) {
        // Create a dp table initialized to -1 (indicating that no subproblem has been solved yet)
        // dp[i][j] represents the minimum edit distance between word1[0..i-1] and word2[0..j-1]
        vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, -1));

        // Call the solve function starting from the beginning of both strings
        return solve(word1, word2, 0, 0, dp);
    }
};
```

### Source Code Explanation
```cpp
class Solution {
public:
    // Helper function to calculate the minimum distance (edit distance) using recursion and memoization
    int solve(string word1, string word2, int i, int j, vector<vector<int>> &dp) {
```
- **Explanation**: We define a class `Solution` and inside it, a helper function `solve` to calculate the edit distance. 
- The parameters of `solve` are:
  - `word1` and `word2` are the two strings we are comparing.
  - `i` and `j` are the indices of the current characters in `word1` and `word2`.
  - `dp` is a 2D array (memoization table) used to store the results of subproblems.



```cpp
        int n = word1.length(); // Length of the first string
        int m = word2.length(); // Length of the second string
```
- **Explanation**: 
  - `n` stores the length of `word1` and `m` stores the length of `word2`.
  - These will help in checking when the strings are fully traversed.



```cpp
        // Base cases: If one string is fully traversed, the remaining length of the other string is the answer
        if (i >= n) return m - j;  // If word1 is fully traversed, we need to insert remaining characters of word2
        if (j >= m) return n - i;  // If word2 is fully traversed, we need to delete remaining characters of word1
```
- **Explanation**:
  - **Base Case 1**: If `i` (index of `word1`) is greater than or equal to `n` (length of `word1`), it means we have exhausted `word1` but still have characters in `word2`. So, we return `m - j` (the number of remaining characters in `word2`).
  - **Base Case 2**: If `j` (index of `word2`) is greater than or equal to `m` (length of `word2`), it means we have exhausted `word2` but still have characters in `word1`. So, we return `n - i` (the number of remaining characters in `word1`).



```cpp
        // If the result for this subproblem is already computed (cached in dp table), return it
        if (dp[i][j] != -1) return dp[i][j];
```
- **Explanation**: 
  - **Memoization**: If `dp[i][j]` is not `-1`, it means we have already computed the minimum edit distance for the substring `word1[0..i-1]` and `word2[0..j-1]`. So, we simply return the stored value.



```cpp
        int ans = 0;
```
- **Explanation**: We initialize a variable `ans` to store the minimum edit distance for the current subproblem.



```cpp
        // If characters at the current positions match, move to the next character in both strings
        if (word1[i] == word2[j]) return solve(word1, word2, i + 1, j + 1, dp);
```
- **Explanation**:
  - If `word1[i] == word2[j]`, it means the characters at positions `i` and `j` are the same. So, no operation is needed for these characters, and we simply move to the next characters in both strings by calling `solve(word1, word2, i + 1, j + 1, dp)`.



```cpp
        else {
```
- **Explanation**: 
  - If `word1[i] != word2[j]`, we need to perform one of three operations: insertion, deletion, or replacement. 



```cpp
            // If characters do not match, consider the three possible operations:
            // 1. Insert a character into word1 (move j ahead in word2)
            int insertAns = 1 + solve(word1, word2, i, j + 1, dp);
```
- **Explanation**:
  - **Insertion**: If we insert a character into `word1` (i.e., we consider the next character in `word2`), the cost is `1` (one insertion). We call `solve(word1, word2, i, j + 1, dp)` to check the cost of this operation.



```cpp
            // 2. Delete a character from word1 (move i ahead in word1)
            int deleteAns = 1 + solve(word1, word2, i + 1, j, dp);
```
- **Explanation**:
  - **Deletion**: If we delete a character from `word1` (i.e., we move to the next character in `word1`), the cost is also `1` (one deletion). We call `solve(word1, word2, i + 1, j, dp)` to check the cost of this operation.



```cpp
            // 3. Replace a character in word1 (move both i and j ahead)
            int replaceAns = 1 + solve(word1, word2, i + 1, j + 1, dp);
```
- **Explanation**:
  - **Replacement**: If we replace the character in `word1` with the character from `word2`, the cost is `1` (one replacement). We call `solve(word1, word2, i + 1, j + 1, dp)` to check the cost of this operation.



```cpp
            // The minimum of these three options gives the optimal edit distance at this step
            ans = min({insertAns, deleteAns, replaceAns});
```
- **Explanation**:
  - We calculate the minimum of the three options (insert, delete, replace) and store it in `ans`. This gives the optimal edit distance for the current subproblem.



```cpp
        }
```
- **Explanation**: This closes the `else` block where we handle the three possible operations.



```cpp
        // Store the computed result in the dp table and return it
        return dp[i][j] = ans;
```
- **Explanation**:
  - We store the computed result (`ans`) in `dp[i][j]` to avoid redundant calculations in the future. Then, we return `ans`.



```cpp
    }
```
- **Explanation**: This closes the helper function `solve`.



```cpp
    // Main function that calculates the minimum distance between word1 and word2
    int minDistance(string word1, string word2) {
```
- **Explanation**: This is the main function `minDistance`, which calls the helper function `solve` to calculate the minimum edit distance between `word1` and `word2`.



```cpp
        // Create a dp table initialized to -1 (indicating that no subproblem has been solved yet)
        // dp[i][j] represents the minimum edit distance between word1[0..i-1] and word2[0..j-1]
        vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, -1));
```
- **Explanation**:
  - We create a 2D vector `dp` to store the memoization table. The table has dimensions `(word1.length() + 1) x (word2.length() + 1)`. 
  - The table is initialized with `-1` to indicate that no subproblem has been solved yet.



```cpp
        // Call the solve function starting from the beginning of both strings
        return solve(word1, word2, 0, 0, dp);
```
- **Explanation**:
  - We call the `solve` function starting with the first characters of both strings (`i = 0` and `j = 0`), and pass the `dp` table to store the results of subproblems. The final result is returned by `solve`.



### Example Walkthrough

Let's take the example: `word1 = "horse"` and `word2 = "ros"`.

1. `i = 0, j = 0`:
   - The characters `'h'` and `'r'` do not match, so we compute three possibilities:
     - Insert: `1 + solve("horse", "ros", 0, 1)`, which results in further recursive calls.
     - Delete: `1 + solve("horse", "ros", 1, 0)`.
     - Replace: `1 + solve("horse", "ros", 1, 1)`.

2. These recursive calls continue until base cases are reached, and results are cached in `dp`.

3. The final result will be stored in `dp[0][0]`, which will be the minimum number of operations needed to convert `"horse"` into `"ros"`.



### Time and Space Complexities

#### Time Complexity:
- **Time Complexity**: `O(n * m)`, where `n` and `m` are the lengths of `word1` and `word2`. 
  - We need to solve `n * m` subproblems (each pair of indices `i` and `j`), and each subproblem is solved in constant time due to memoization.

#### Space Complexity:
- **Space Complexity**: `O(n * m)`, where `n` and `m` are the lengths of `word1` and `word2`.
  - The space complexity is dominated by the memoization table (`dp`), which has size `(n + 1) x (m + 1)`.


---

## Bottom-Up Approach (DP)
Let's break down the **Bottom-Up Dynamic Programming** approach step by step and explain the code in detail with examples. Afterward, we'll discuss the example output and analyze the time and space complexities.

### **Bottom-Up Dynamic Programming Approach**

The **Bottom-Up approach** builds the solution starting from the simplest subproblems (i.e., smallest prefixes of the two strings) and works its way up to the final problem. This is opposite to the **Top-Down** approach where recursion starts with the full problem and breaks it down into smaller subproblems.

In this case, the problem is **calculating the minimum number of operations (insertions, deletions, or replacements) required to convert one string into another**, which is known as the **Edit Distance** or **Levenshtein Distance**.

#### **Steps in Bottom-Up Approach**:

1. **Initialize the DP Table**:
   - Create a 2D DP table `dp` where `dp[i][j]` stores the minimum edit distance between the first `i` characters of `word1` and the first `j` characters of `word2`.
   - The table's size will be `(n+1) x (m+1)`, where `n` is the length of `word1` and `m` is the length of `word2`. The extra row and column represent the cases when one of the strings is empty.

2. **Base Cases**:
   - If `word1` is empty (`i == 0`), it takes `j` insertions to convert `word2[0..j-1]` to an empty string.
   - If `word2` is empty (`j == 0`), it takes `i` deletions to convert `word1[0..i-1]` to an empty string.

3. **Filling the DP Table**:
   - Iterate over the table from bottom-right to top-left.
   - For each cell `dp[i][j]`, determine the minimum cost based on three possible operations:
     1. **Insertion**: Insert the character `word2[j-1]` into `word1`, and thus move `j` forward while keeping `i` the same.
     2. **Deletion**: Delete the character `word1[i-1]` and thus move `i` forward while keeping `j` the same.
     3. **Replacement**: Replace the character `word1[i-1]` with `word2[j-1]`.

4. **Final Result**:
   - The final answer, which is the minimum edit distance to convert `word1` into `word2`, is stored in `dp[0][0]`.

### Source Code
```cpp
class Solution {
public:
    // Helper function to calculate the minimum edit distance using dynamic programming
    int solve(string word1, string word2) {
        int n = word1.length(); // Length of the first string
        int m = word2.length(); // Length of the second string

        // Create a dp table with dimensions (n+1) x (m+1), initialized to 0
        // dp[i][j] represents the minimum edit distance between word1[0..i-1] and word2[0..j-1]
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // Initialize the base cases for the last row and last column of the dp table
        for (int j = 0; j < m; j++) dp[n][j] = m - j;  // If word1 is empty, we need to insert all characters from word2
        for (int i = 0; i < n; i++) dp[i][m] = n - i;  // If word2 is empty, we need to delete all characters from word1
        
        // Fill the dp table by processing the strings from bottom-right to top-left
        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                int ans = 0;

                // If characters at current positions match, no operation is needed, take the result from the next diagonal cell
                if (word1[i] == word2[j]) {
                    ans = dp[i+1][j+1];
                }
                else {
                    // Otherwise, calculate the costs for insertion, deletion, and replacement:
                    int insertAns = 1 + dp[i][j+1];    // Insert a character from word2 into word1 (move j ahead)
                    int deleteAns = 1 + dp[i+1][j];    // Delete a character from word1 (move i ahead)
                    int replaceAns = 1 + dp[i+1][j+1]; // Replace a character in word1 (move both i and j ahead)

                    // The minimum of these three options gives the optimal edit distance at this cell
                    ans = min({insertAns, deleteAns, replaceAns});
                }
                
                // Store the result in the dp table
                dp[i][j] = ans;
            }
        }

        // The final result is stored in dp[0][0], which represents the minimum edit distance between word1 and word2
        return dp[0][0];
    }

    // Main function that calculates the minimum distance between word1 and word2
    int minDistance(string word1, string word2) {
        return solve(word1, word2);  // Call the solve function to compute the result
    }
};
```

### Source Code Explanation

```cpp
class Solution {
public:
    // Helper function to calculate the minimum edit distance using dynamic programming
    int solve(string word1, string word2) {
        int n = word1.length(); // Length of the first string
        int m = word2.length(); // Length of the second string
```
- **Explanation**:
  - We get the lengths of `word1` and `word2` and store them in `n` and `m` respectively. These lengths will be used to define the size of the DP table.

```cpp
        // Create a dp table with dimensions (n+1) x (m+1), initialized to 0
        // dp[i][j] represents the minimum edit distance between word1[0..i-1] and word2[0..j-1]
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
```
- **Explanation**:
  - We create a 2D DP table `dp` of size `(n+1) x (m+1)`. Initially, all values are set to `0`. This table will store the minimum edit distances for all prefixes of `word1` and `word2`.

```cpp
        // Initialize the base cases for the last row and last column of the dp table
        for (int j = 0; j < m; j++) dp[n][j] = m - j;  // If word1 is empty, we need to insert all characters from word2
        for (int i = 0; i < n; i++) dp[i][m] = n - i;  // If word2 is empty, we need to delete all characters from word1
```
- **Explanation**:
  - **Base Case Initialization**:
    - If `word1` is empty (`i = 0`), we need to insert all characters from `word2` to make the strings match. Thus, for each `j`, `dp[n][j]` stores the number of insertions required (which is `m - j`).
    - If `word2` is empty (`j = 0`), we need to delete all characters from `word1` to make the strings match. Thus, for each `i`, `dp[i][m]` stores the number of deletions required (which is `n - i`).

```cpp
        // Fill the dp table by processing the strings from bottom-right to top-left
        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                int ans = 0;
```
- **Explanation**:
  - We start filling the DP table from the bottom-right (`dp[n][m]`) and move upwards to `dp[0][0]`.
  - The variable `ans` will store the minimum edit distance for the current pair of substrings `word1[0..i-1]` and `word2[0..j-1]`.

```cpp
                // If characters at current positions match, no operation is needed, take the result from the next diagonal cell
                if (word1[i] == word2[j]) {
                    ans = dp[i+1][j+1];
                }
```
- **Explanation**:
  - If the characters at positions `i` and `j` in `word1` and `word2` match (`word1[i] == word2[j]`), no operation is required. Therefore, we simply take the value from the next diagonal cell (`dp[i+1][j+1]`), which already contains the minimum edit distance for the remaining substrings.

```cpp
                else {
                    // Otherwise, calculate the costs for insertion, deletion, and replacement:
                    int insertAns = 1 + dp[i][j+1];    // Insert a character from word2 into word1 (move j ahead)
                    int deleteAns = 1 + dp[i+1][j];    // Delete a character from word1 (move i ahead)
                    int replaceAns = 1 + dp[i+1][j+1]; // Replace a character in word1 (move both i and j ahead)

                    // The minimum of these three options gives the optimal edit distance at this cell
                    ans = min({insertAns, deleteAns, replaceAns});
                }
```
- **Explanation**:
  - If the characters at positions `i` and `j` in `word1` and `word2` do not match, we calculate the costs for three operations:
    1. **Insertion**: Insert the character from `word2` into `word1`, which costs `1 + dp[i][j+1]`.
    2. **Deletion**: Delete a character from `word1`, which costs `1 + dp[i+1][j]`.
    3. **Replacement**: Replace a character in `word1` with `word2`, which costs `1 + dp[i+1][j+1]`.
  - We choose the minimum of these three costs and store it in `ans`.

```cpp
                // Store the result in the dp table
                dp[i][j] = ans;
            }
        }
```
- **Explanation**:
  - We store the calculated `ans` in `dp[i][j]`.

```cpp
        // The final result is stored in dp[0][0], which represents the minimum edit distance between word1 and word2
        return dp[0][0];
    }
```
- **Explanation**:
  - After filling the entire DP table, the minimum edit distance between `word1` and `word2` is stored in `dp[0][0]`, which we return as the final result.

```cpp
    // Main function that calculates the minimum distance between word1 and word2
    int minDistance(string word1, string word2) {
        return solve(word1, word2);  // Call the solve function to compute the result
    }
};
```
- **Explanation**:
  - The `minDistance` function calls the `solve` function to calculate and return the result.



### **Example Walkthrough**

Let’s take the example where `word1 = "horse"` and `word2 = "ros"`.

1. **Initialization**:
   - `n = 5` (length of `word1 = "horse"`)
   - `m = 3` (length of `word2 = "ros"`)
   - The DP table `dp` will be of size `(6 x 4)` (since we also account for the empty string).

2. **Base Case Initialization**:
   - For the last row (`dp[5][j]`), we initialize the required insertions: `dp[5][0] = 3`, `dp[5][1] = 2`, `dp[5][2] = 1`, `dp[5][3] = 0`.
   - For the last column (`dp[i][3]`), we initialize the required deletions: `dp[0][3] = 3`, `dp[1][3] = 2`, `dp[2][3] = 1`, `dp[3][3] = 0`.

3. **Filling the DP Table**:
   - We iterate through the DP table from bottom-right to top-left, calculating the minimum edit distance at each step. After filling the table, `dp[0][0] = 3` represents the minimum number of

 operations needed to convert `"horse"` to `"ros"`. The operations would be:
     - Replace 'h' with 'r' → `"orse"`
     - Delete 'o' → `"rse"`
     - Delete 's' → `"re"`



### **Time and Space Complexity**

- **Time Complexity**:
  - We are filling a DP table of size `(n+1) x (m+1)`. For each cell, we perform a constant amount of work (3 comparisons for insertion, deletion, and replacement). Hence, the time complexity is:
    `
    O(n times m)
    `

- **Space Complexity**:
  - The space complexity is determined by the DP table, which has `(n+1) x (m+1)` cells, resulting in a space complexity of:
    `
    O(n times m)
    `

Thus, the **time complexity** and **space complexity** of this approach are both ( O(n times m) ).

---

## Space Optimization Approach (DP)
Let's break down the **space optimization approach** for the minimum edit distance problem step by step.

### **Problem Overview**

We need to calculate the **minimum edit distance** between two strings, `word1` and `word2`. This distance is the minimum number of operations (insertions, deletions, or replacements) needed to transform one string into the other.

### **Space Optimization Approach Explanation**

The space complexity of a normal dynamic programming (DP) approach is `O(n * m)`, where `n` is the length of `word1` and `m` is the length of `word2`. However, we can reduce the space complexity to `O(m)` by using only two 1D arrays (instead of a 2D DP table). 

#### **Why can we optimize the space?**
1. The edit distance between `word1[0..i]` and `word2[0..j]` only depends on:
   - The previous row (`dp[i-1][...]`)
   - The previous column (`dp[...][j-1]`), and
   - The current character comparison `word1[i]` and `word2[j]`.

2. Therefore, we can maintain only two rows (current and next), instead of the entire 2D DP table.

### Source Code
```cpp
class Solution {
public:
    // Helper function to calculate the minimum edit distance using dynamic programming
    int solve(string word1, string word2) {
        int n = word1.length(); // Length of the first string
        int m = word2.length(); // Length of the second string

        // Create two 1D arrays to store the current and next row values of the dp table
        vector<int> curr(m+1, 0); // Current row (for the current i-th character in word1)
        vector<int> next(m+1, 0); // Next row (for the next i+1-th character in word1)

        // Initialize the next row for the case when word1 is empty
        for(int j = 0; j < m; j++) next[j] = m - j;

        // Iterate over word1 from bottom to top (i = n-1 to i = 0)
        for(int i = n-1; i >= 0; i--) {
            // Iterate over word2 from right to left (j = m-1 to j = 0)
            for(int j = m-1; j >= 0; j--) {
                // Set the base case for when word2 is empty (fill in the current row's last column)
                curr[m] = n - i;

                int ans = 0;
                // If characters match, take the result from the next row's next column
                if(word1[i] == word2[j]) ans = next[j+1];
                else {
                    // Otherwise, calculate the costs of insertion, deletion, and replacement:
                    int insertAns = 1 + curr[j+1];    // Insert a character from word2 into word1
                    int deleteAns = 1 + next[j];      // Delete a character from word1
                    int replaceAns = 1 + next[j+1];  // Replace a character in word1 with word2

                    // Take the minimum of these three options
                    ans = min({insertAns, deleteAns, replaceAns});
                }

                // Store the result for the current cell in the current row
                curr[j] = ans;
            }
            // Update the next row to be the current row after finishing one iteration
            next = curr;
        }

        // The final result is stored in curr[0], which represents the minimum edit distance
        return curr[0];
    }

    // Main function to calculate the minimum edit distance between word1 and word2
    int minDistance(string word1, string word2) {
        // Edge case: if one of the strings is empty, the result is the length of the other string
        if(word1.length() == 0) return word2.length();
        if(word2.length() == 0) return word1.length();
        
        // Call the solve function to compute the result
        return solve(word1, word2);
    }
};
```

### Source Code Explanation
Let's go through the code step-by-step:

```cpp
int solve(string word1, string word2) {
    int n = word1.length(); // Length of word1
    int m = word2.length(); // Length of word2
```

- **`n`** and **`m`** are the lengths of `word1` and `word2`, respectively. These variables will help in controlling the loops and dimensions of our arrays.

```cpp
    vector<int> curr(m+1, 0); // Current row for dp table
    vector<int> next(m+1, 0); // Next row for dp table
```

- We declare two 1D vectors (`curr` and `next`), both of size `m + 1`. These arrays store the current row and the next row values of the DP table.
- The initial value of each element in these arrays is set to 0.
- **`curr[j]`** will store the edit distance for the current row of the DP table.
- **`next[j]`** will store the edit distance for the next row in the DP table.

```cpp
    // Initialize the next row for the case when word1 is empty
    for(int j = 0; j < m; j++) next[j] = m - j;
```

- This loop initializes the `next` row for the base case where `word1` is empty. If `word1` is empty, we need to insert all characters of `word2` into `word1`.
  - For example, if `word2 = "ros"`, we will need 3 insertions to form the entire word from an empty string, 2 insertions to form "ro", and so on.

```cpp
    // Iterate over word1 from bottom to top
    for(int i = n-1; i >= 0; i--) {
```

- We iterate over the characters of `word1` from the last character (`n-1`) to the first character (0). This ensures that we build the DP table bottom-up.

```cpp
        // Iterate over word2 from right to left
        for(int j = m-1; j >= 0; j--) {
```

- We iterate over the characters of `word2` from the last character (`m-1`) to the first character (0).

```cpp
            // Set the base case for when word2 is empty
            curr[m] = n - i;
```

- We set the last column of the current row (`curr[m]`) to `n - i`, which represents the number of deletions needed to reduce `word1[0..i]` to an empty string.

```cpp
            int ans = 0;
```

- We initialize the variable `ans`, which will store the minimum edit distance for the current `i, j` position.

```cpp
            // If characters match, no operation is needed
            if(word1[i] == word2[j]) ans = next[j+1];
```

- If the characters at the current positions `word1[i]` and `word2[j]` are the same, no operation is needed. Thus, the value for `ans` is taken from `next[j+1]`, which corresponds to the diagonal value in the DP table.

```cpp
            else {
                // Calculate the costs for insertion, deletion, and replacement
                int insertAns = 1 + curr[j+1];    // Insert a character from word2 into word1
                int deleteAns = 1 + next[j];      // Delete a character from word1
                int replaceAns = 1 + next[j+1];  // Replace a character in word1

                // Take the minimum of these three options
                ans = min({insertAns, deleteAns, replaceAns});
            }
```

- If the characters don't match, we calculate the three possible operations:
  - **Insert**: Insert a character from `word2` into `word1` (cost: 1 + `curr[j+1]`).
  - **Delete**: Delete a character from `word1` (cost: 1 + `next[j]`).
  - **Replace**: Replace a character in `word1` with `word2[j]` (cost: 1 + `next[j+1]`).

- The minimum of these three costs is stored in `ans`.

```cpp
            // Store the result for the current cell in the current row
            curr[j] = ans;
        }
```

- We store the result of the current `i, j` cell in `curr[j]`.

```cpp
        // After processing the current row, update the next row to be the current row
        next = curr;
    }
```

- After processing all `j` values for a given `i`, we update `next` to be `curr`. This makes the current row the "next" row for the subsequent iteration.

```cpp
    // The final result is stored in curr[0], which represents the minimum edit distance
    return curr[0];
}
```

- After the loops are done, the final result (minimum edit distance) is stored in `curr[0]`, which corresponds to the minimum edit distance between `word1` and `word2`.

### **Main Function**

```cpp
int minDistance(string word1, string word2) {
    // Edge case: if one of the strings is empty, the result is the length of the other string
    if(word1.length() == 0) return word2.length();
    if(word2.length() == 0) return word1.length();
    
    // Call the solve function to compute the result
    return solve(word1, word2);
}
```

- In this main function, we check for edge cases where one of the strings is empty. If either string is empty, the minimum edit distance is simply the length of the other string.
- We then call the `solve` function to calculate the minimum edit distance between `word1` and `word2`.

### **Example Explanation**

Consider the following example:

```cpp
word1 = "horse"
word2 = "ros"
```

The solution will compute the minimum edit distance as follows:
1. **Insertions**: Insert `r`, `o`, `s` into `word1` at the correct positions.
2. **Deletions**: Remove characters from `word1` to match `word2`.
3. **Replacements**: Replace characters if necessary.

After processing, the minimum number of operations to transform "horse" into "ros" is 3:
- "horse" → "rorse" (replace `h` with `r`)
- "rorse" → "rose" (delete `r`)
- "rose" → "ros" (delete `e`)

So, the output will be `3`.

### **Time Complexity**

- **Time Complexity**: `O(n * m)`, where `n` is the length of `word1` and `m` is the length of `word2`. We are iterating over both strings in a nested loop.
  
- **Space Complexity**: `O(m)`, since we are using two 1D arrays of size `m+1` to store the current and next rows of the DP table.

Thus, the solution is optimized in terms of space without sacrificing the time complexity.


