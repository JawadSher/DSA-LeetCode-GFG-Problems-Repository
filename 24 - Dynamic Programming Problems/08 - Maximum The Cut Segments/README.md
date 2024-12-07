<h1 align="center">Maximum - The Cut - Segments</h1>


## Problem Statement

**Problem URL :** [Maximum The Cut Segments](https://www.geeksforgeeks.org/problems/cutted-segments1642/1)

![image](https://github.com/user-attachments/assets/0fc065a5-4167-4aac-9dd8-31e1298cc0d0)

### Problem Explanation

The problem asks you to determine the **maximum number of segments** you can cut from a rod of length `n`, where you are allowed to cut the rod into pieces of fixed lengths `x`, `y`, and `z`. 

If it is impossible to cut the rod using the given lengths, the output should be `0`.

### Key Points:
1. **Rod Length (`n`)**:
   - You are given a rod of length `n`.
   - Your goal is to divide this rod into as many pieces (segments) as possible.

2. **Allowed Segment Lengths (`x`, `y`, `z`)**:
   - You can only cut the rod into segments of lengths `x`, `y`, and `z`.
   - Each cut must exactly match one of these lengths.

3. **Maximum Segments**:
   - The objective is to maximize the number of segments the rod is divided into.
   - If there’s no way to cut the rod into the given lengths, return `0`.

4. **Constraints**:
   - A segment of length exactly equal to `x`, `y`, or `z` can only be created.
   - The rod cannot be partially cut; leftover lengths that don’t match `x`, `y`, or `z` are not allowed.



### Input:
- An integer `n` (length of the rod).
- Three integers `x`, `y`, `z` (the allowed segment lengths).

### Output:
- The maximum number of segments the rod can be divided into.



### Examples:

#### Example 1:
**Input**:  
`n = 7`, `x = 2`, `y = 1`, `z = 3`

**Explanation**:
- Rod length is `7`.
- Allowed cuts are of lengths `2`, `1`, and `3`.
- You can make cuts of these lengths to maximize the number of segments.

**Possible Cutting Options**:
1. Cut `7 = 2 + 2 + 3` → Segments: 3 (Lengths: `2, 2, 3`).
2. Cut `7 = 1 + 1 + 1 + 1 + 1 + 1 + 1` → Segments: 7 (Lengths: `1, 1, 1, 1, 1, 1, 1`).
3. Cut `7 = 3 + 3 + 1` → Segments: 3 (Lengths: `3, 3, 1`).

**Maximum Segments**:
- The best option is `7 segments` (each of length `1`).

**Output**: `7`.



#### Example 2:
**Input**:  
`n = 5`, `x = 5`, `y = 2`, `z = 1`

**Explanation**:
- Rod length is `5`.
- Allowed cuts are of lengths `5`, `2`, and `1`.

**Possible Cutting Options**:
1. Cut `5 = 5` → Segments: 1 (Length: `5`).
2. Cut `5 = 2 + 2 + 1` → Segments: 3 (Lengths: `2, 2, 1`).
3. Cut `5 = 1 + 1 + 1 + 1 + 1` → Segments: 5 (Lengths: `1, 1, 1, 1, 1`).

**Maximum Segments**:
- The best option is `5 segments` (each of length `1`).

**Output**: `5`.



#### Example 3:
**Input**:  
`n = 9`, `x = 2`, `y = 2`, `z = 2`

**Explanation**:
- Rod length is `9`.
- Allowed cuts are of lengths `2`, `2`, and `2`.

**Possible Cutting Options**:
1. The only way to cut is by using length `2` repeatedly.
2. However, `9` cannot be perfectly divided by `2` (remainder is `1`).

**Output**: `0` (No valid way to divide the rod).



### Constraints:
- `1 <= n, x, y, z <= 10^4`
- Segment lengths are integers, and no fractional cuts are allowed.



### Challenges in the Problem:
1. **Exact Cutting**:
   - The rod must be perfectly divided; leftover pieces are not allowed.
2. **Maximizing Segments**:
   - Among all possible ways of cutting, you must maximize the number of segments.
3. **Impossible Cases**:
   - If the rod cannot be divided using the given segment lengths, the result is `0`.

---

## Recursive Approach (caused TLE)
This problem uses a **recursive approach** to determine the maximum number of cuts that can be made on a rod of length `n` using segments of lengths `x`, `y`, and `z`. The main idea is to try making cuts of each length (`x`, `y`, `z`) and recursively determine how many more cuts can be made with the remaining length of the rod.

#### Step-by-Step Explanation of the Recursive Approach:

1. **Base Case - Length is 0**:  
   If the length of the rod becomes `0`, we don't need any more cuts. This means we have successfully divided the rod, so the number of cuts is `0`.

2. **Base Case - Length becomes negative**:  
   If the length of the rod becomes negative (i.e., we try to make a cut that exceeds the available length), this means it's not a valid way of cutting the rod, and we return `INT_MIN` (a value representing an invalid solution).

3. **Recursive Case - Try Cutting with Segment `x`**:  
   We try cutting the rod with a segment of length `x`. If `n` is greater than or equal to `x`, we subtract `x` from `n` (this represents the remaining length of the rod) and recursively calculate the maximum cuts possible for the remaining length (`n - x`).

4. **Recursive Case - Try Cutting with Segment `y`**:  
   Similarly, we try cutting the rod with a segment of length `y`. If `n` is greater than or equal to `y`, we subtract `y` from `n` and recursively calculate the maximum cuts possible for the remaining length (`n - y`).

5. **Recursive Case - Try Cutting with Segment `z`**:  
   Finally, we try cutting the rod with a segment of length `z`. If `n` is greater than or equal to `z`, we subtract `z` from `n` and recursively calculate the maximum cuts possible for the remaining length (`n - z`).

6. **Choose the Best Option**:  
   We calculate the maximum of the three recursive calls (one for each segment length `x`, `y`, `z`) and add `1` to it, since we have made one more cut. This gives us the maximum number of cuts possible for the current rod length `n`.

### Source Code
```cpp
class Solution
{
    public:
    // Recursive function to calculate the maximum number of cuts possible
    int solve(int n, int x, int y, int z){
        // Base case: If the length is exactly 0, no further cuts are needed
        if(n == 0) return 0;
        // Base case: If the length becomes negative, this is an invalid case
        if(n < 0) return INT_MIN;

        // Try cutting a segment of length x and recursively calculate the cuts
        int a = solve(n-x, x, y, z) + 1;
        // Try cutting a segment of length y and recursively calculate the cuts
        int b = solve(n-y, x, y, z) + 1;
        // Try cutting a segment of length z and recursively calculate the cuts
        int c = solve(n-z, x, y, z) + 1;

        // Return the maximum of the three possible cuts
        return max(a, max(b, c));
    }

    // Function to find the maximum number of cuts that can be made
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // Call the recursive function to calculate the maximum cuts
        int maxCuts = solve(n, x, y, z);
        // If the result is negative, it means no valid cuts are possible
        if(maxCuts < 0) return 0;

        // Return the maximum number of valid cuts
        return maxCuts;
    }
};
```

### Source Code Explanation

```cpp
class Solution
{
    public:
    // Recursive function to calculate the maximum number of cuts possible
    int solve(int n, int x, int y, int z){
```
- **Function Definition**: This defines the recursive function `solve` that will calculate the maximum number of cuts possible. The function takes `n` (the current length of the rod), and `x`, `y`, and `z` (the available segment lengths).

```cpp
        // Base case: If the length is exactly 0, no further cuts are needed
        if(n == 0) return 0;
```
- **Base Case 1**: If the length of the rod is `0`, we don’t need to make any cuts. So, the function returns `0`.

```cpp
        // Base case: If the length becomes negative, this is an invalid case
        if(n < 0) return INT_MIN;
```
- **Base Case 2**: If the length of the rod becomes negative, we return `INT_MIN`, indicating that it's an invalid state, and we shouldn't proceed with this path.

```cpp
        // Try cutting a segment of length x and recursively calculate the cuts
        int a = solve(n-x, x, y, z) + 1;
```
- **Recursive Case 1**: We try cutting the rod by using a segment of length `x`. If the rod length is greater than or equal to `x`, we subtract `x` from `n` and recursively calculate the maximum cuts possible for the remaining length. After the recursive call, we add `1` to account for the current cut.

```cpp
        // Try cutting a segment of length y and recursively calculate the cuts
        int b = solve(n-y, x, y, z) + 1;
```
- **Recursive Case 2**: Similarly, we try cutting the rod by using a segment of length `y` and add `1` to the result of the recursive call for the remaining rod length.

```cpp
        // Try cutting a segment of length z and recursively calculate the cuts
        int c = solve(n-z, x, y, z) + 1;
```
- **Recursive Case 3**: We also try cutting the rod by using a segment of length `z` and add `1` to the result of the recursive call for the remaining rod length.

```cpp
        // Return the maximum of the three possible cuts
        return max(a, max(b, c));
    }
```
- **Choose the Best Option**: We return the maximum of the three options (`a`, `b`, and `c`), which represent the possible outcomes for using segment lengths `x`, `y`, and `z`. We return this maximum value because it represents the best number of cuts possible.

```cpp
    // Function to find the maximum number of cuts that can be made
    int maximizeTheCuts(int n, int x, int y, int z)
    {
```
- **Main Function**: The `maximizeTheCuts` function is the main function that calls the `solve` function with the initial rod length `n` and segment lengths `x`, `y`, and `z`.

```cpp
        // Call the recursive function to calculate the maximum cuts
        int maxCuts = solve(n, x, y, z);
```
- **Calling the Recursive Function**: We call the recursive `solve` function with the initial rod length `n` and segment lengths `x`, `y`, and `z`. The result is stored in `maxCuts`.

```cpp
        // If the result is negative, it means no valid cuts are possible
        if(maxCuts < 0) return 0;
```
- **Check for Invalid Cuts**: If `maxCuts` is negative (i.e., no valid way of cutting the rod was found), we return `0`.

```cpp
        // Return the maximum number of valid cuts
        return maxCuts;
    }
};
```
- **Returning the Result**: Finally, we return the maximum number of cuts found by the recursive function.


### Example Walkthrough:

#### Example 1:
**Input**: `n = 7`, `x = 2`, `y = 1`, `z = 3`

- Initially, we have a rod of length `7`. The allowed cuts are `x = 2`, `y = 1`, and `z = 3`.
- We recursively try cutting the rod using segments of length `2`, `1`, and `3` and calculate the remaining rod length.
- Eventually, we find that the maximum number of segments we can get is `7` (by using segments of length `1` repeatedly).

**Output**: `7`


### Time Complexity:

- **Time Complexity**:  
  The time complexity of this recursive approach is exponential (`O(3^n)`) due to the recursive calls. This is because at each step, there are three choices (`x`, `y`, and `z`), and for each choice, we make a recursive call.

- **Optimizations**:  
  This approach can be optimized using **dynamic programming** (e.g., memoization or bottom-up DP) to avoid recalculating the results for the same sub-problems multiple times.


### Space Complexity:

- **Space Complexity**:  
  The space complexity is determined by the maximum depth of the recursion stack, which can be up to `O(n)` in the worst case. Hence, the space complexity is `O(n)` due to recursion depth.

---

## Top-Down Approach (DP)
In this approach, we combine recursion with **memoization** to improve the efficiency of the problem-solving process. The idea is to store the results of sub-problems (intermediate results) in a data structure (here, `dp` array), so that we can reuse them when needed instead of recalculating them multiple times. This significantly reduces the time complexity compared to a purely recursive solution.

#### Step-by-Step Explanation:

1. **Recursive Function with Memoization**:  
   The function `solve(n, x, y, z, dp)` is a recursive function that calculates the maximum number of cuts that can be made from a rod of length `n`, using segments of lengths `x`, `y`, and `z`.  
   - We use the `dp` array to store the maximum number of cuts for each rod length `n`.
   - If we have already computed the result for a particular length, we return that stored result, avoiding redundant calculations.

2. **Base Case - Length is 0**:  
   If the length of the rod becomes `0`, it means no further cuts are needed, so we return `0`.

3. **Base Case - Length becomes negative**:  
   If the length of the rod becomes negative, it means that this path of cutting is invalid (we attempted to cut more than the available length), so we return `INT_MIN` to indicate an invalid solution.

4. **Memoization**:  
   Before performing the recursive calls, we check whether the result for the current rod length `n` has already been computed. If it has, we return the value from the `dp` array to avoid recalculating it.

5. **Recursive Case**:  
   If the result is not already stored, we try three possibilities:
   - Cutting a segment of length `x`: This reduces the problem to a sub-problem of length `n - x`.
   - Cutting a segment of length `y`: This reduces the problem to a sub-problem of length `n - y`.
   - Cutting a segment of length `z`: This reduces the problem to a sub-problem of length `n - z`.
   For each of these cases, we recursively calculate the maximum number of cuts and add `1` for the current cut. The maximum of the three values will give the result for the current length `n`.

6. **Store Result in `dp` Array**:  
   After computing the result for the current length `n`, we store it in the `dp` array to avoid recalculating it in the future.

7. **Return the Result**:  
   Finally, the function returns the result for the current rod length `n`.

### Source Code
```cpp
class Solution
{
    public:
    // Recursive function with memoization to calculate the maximum number of cuts
    int solve(int n, int x, int y, int z, vector<int>& dp){
        // Base case: If the length is exactly 0, no further cuts are needed
        if(n == 0) return 0;
        // Base case: If the length becomes negative, this is an invalid case
        if(n < 0) return INT_MIN;

        // If the result for the current length `n` is already computed, return it
        if(dp[n] != -1) return dp[n];

        // Try cutting a segment of length x and recursively calculate the cuts
        int a = solve(n-x, x, y, z, dp) + 1;
        // Try cutting a segment of length y and recursively calculate the cuts
        int b = solve(n-y, x, y, z, dp) + 1;
        // Try cutting a segment of length z and recursively calculate the cuts
        int c = solve(n-z, x, y, z, dp) + 1;

        // Store the result in the dp array for future use
        dp[n] = max(a, max(b, c));

        // Return the computed result for the current length `n`
        return dp[n];
    }

    // Function to find the maximum number of cuts that can be made
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // Create a dp array initialized with -1 to indicate uncomputed states
        vector<int> dp(n+1, -1);

        // Call the recursive function with memoization to calculate the maximum cuts
        int maxCuts = solve(n, x, y, z, dp);

        // If the result is negative, it means no valid cuts are possible
        if(maxCuts < 0) return 0;

        // Return the maximum number of valid cuts
        return maxCuts;
    }
};
```

### Source Code Explanation

```cpp
class Solution
{
    public:
    // Recursive function with memoization to calculate the maximum number of cuts
    int solve(int n, int x, int y, int z, vector<int>& dp){
```
- **Function Definition**: This defines the recursive function `solve` that calculates the maximum number of cuts for a rod of length `n` with allowed segment lengths `x`, `y`, and `z`. The `dp` array stores the results of sub-problems.

```cpp
        // Base case: If the length is exactly 0, no further cuts are needed
        if(n == 0) return 0;
```
- **Base Case 1**: If the rod length is `0`, no cuts are needed, so we return `0`.

```cpp
        // Base case: If the length becomes negative, this is an invalid case
        if(n < 0) return INT_MIN;
```
- **Base Case 2**: If the rod length becomes negative, it means this is an invalid case (we can't cut more than the remaining rod length), so we return `INT_MIN`.

```cpp
        // If the result for the current length `n` is already computed, return it
        if(dp[n] != -1) return dp[n];
```
- **Memoization Check**: Before making any recursive calls, we check if the result for the current rod length `n` is already computed and stored in the `dp` array. If so, we return the stored value to avoid redundant calculations.

```cpp
        // Try cutting a segment of length x and recursively calculate the cuts
        int a = solve(n-x, x, y, z, dp) + 1;
```
- **Recursive Call 1**: We try cutting a segment of length `x` from the rod. The remaining length is `n - x`, and we recursively calculate the maximum number of cuts for the remaining rod length. We add `1` to account for the current cut.

```cpp
        // Try cutting a segment of length y and recursively calculate the cuts
        int b = solve(n-y, x, y, z, dp) + 1;
```
- **Recursive Call 2**: Similarly, we try cutting a segment of length `y` and recursively calculate the maximum number of cuts for the remaining rod length.

```cpp
        // Try cutting a segment of length z and recursively calculate the cuts
        int c = solve(n-z, x, y, z, dp) + 1;
```
- **Recursive Call 3**: Similarly, we try cutting a segment of length `z` and recursively calculate the maximum number of cuts for the remaining rod length.

```cpp
        // Store the result in the dp array for future use
        dp[n] = max(a, max(b, c));
```
- **Store the Result**: After calculating the results for all three possible cuts (`a`, `b`, and `c`), we store the maximum result in the `dp[n]` array. This ensures that if we encounter the same problem (i.e., a rod of length `n`), we don't recalculate the result.

```cpp
        // Return the computed result for the current length `n`
        return dp[n];
    }
```
- **Return the Result**: We return the computed result for the current rod length `n` from the `dp` array.

```cpp
    // Function to find the maximum number of cuts that can be made
    int maximizeTheCuts(int n, int x, int y, int z)
    {
```
- **Main Function**: The `maximizeTheCuts` function is the main function that calls the `solve` function with the initial rod length `n` and segment lengths `x`, `y`, and `z`.

```cpp
        // Create a dp array initialized with -1 to indicate uncomputed states
        vector<int> dp(n+1, -1);
```
- **DP Array Initialization**: We create a `dp` array of size `n+1`, where each element is initialized to `-1`, indicating that no sub-problems have been solved yet.

```cpp
        // Call the recursive function with memoization to calculate the maximum cuts
        int maxCuts = solve(n, x, y, z, dp);
```
- **Calling the Recursive Function**: We call the `solve` function with the initial rod length `n` and segment lengths `x`, `y`, and `z`. The result is stored in `maxCuts`.

```cpp
        // If the result is negative, it means no valid cuts are possible
        if(maxCuts < 0) return 0;
```
- **Check for Invalid Cuts**: If the result is negative, it means no valid way to cut the rod was found. Therefore, we return `0`.

```cpp
        // Return the maximum number of valid cuts
        return maxCuts;
    }
};
```
- **Return the Result**: Finally, we return the maximum number of cuts found.



### Example Walkthrough:

#### Example 1:
**Input**: `n = 7`, `x = 2`, `y = 1`, `z = 3`

- The rod length is `7`, and the allowed cut lengths are `2`, `1`, and `3`.
- The recursive function will try cutting the rod using each segment length and calculate the remaining length recursively. Using memoization, previously computed results are reused, which helps avoid redundant computations.
- The maximum number of cuts found is `7` (by using segment length `1` repeatedly).

**Output**: `7`



### Time Complexity:

- **Time Complexity**:  
  The time complexity of the approach is `O(n)`, where `n` is the length of the rod. This is because we calculate the result for each length from `1` to `n` only once. Memoization ensures that each sub-problem is solved only once.

- **Optimizations**:  
  Memoization significantly reduces the time complexity compared to the pure recursive solution, where the time complexity was exponential (`O(3^n)`).



### Space Complexity:

- **Space Complexity**:  
  The space complexity is `O(n)` due to the `dp` array and the recursion stack. The `dp` array stores the maximum number of cuts for each rod length, and the recursion stack can have a maximum depth of `n` in the worst case.

---

## Bottom-Up Approach (DP)
In the **bottom-up approach**, we solve the problem iteratively using dynamic programming. This method builds the solution step by step from smaller sub-problems (for smaller rod lengths) and combines them to solve the problem for larger rod lengths. It avoids recursion and uses a simple loop to iteratively fill out a DP table.

#### Key Steps:
1. **DP Array**: We define an array `dp[]` where `dp[i]` will store the maximum number of cuts that can be made for a rod of length `i`.
2. **Initialization**: Start by setting `dp[0] = 0` because no cuts are needed for a rod of length `0`. All other values in `dp[]` are initially set to `INT_MIN` to indicate that no valid cuts are possible for those lengths.
3. **State Transitions**: For each rod length `i`, we check if a cut of length `x`, `y`, or `z` is possible, and update the `dp[]` array accordingly.
4. **Result**: After processing all rod lengths from `1` to `n`, `dp[n]` will contain the maximum number of cuts for a rod of length `n`. If no valid cuts were possible, `dp[n]` will remain `INT_MIN`.

### Source Code
```cpp
class Solution
{
    public:
    // Function to calculate the maximum number of cuts using an iterative approach
    int solve(int n, int x, int y, int z){
        // Initialize a dp array with size (n+1) and set all values to INT_MIN
        // INT_MIN is used to indicate invalid states where no cuts are possible
        vector<int> dp(n+1, INT_MIN);

        // Base case: If the length is 0, no cuts are needed
        dp[0] = 0;

        // Iterate through all lengths from 1 to n
        for(int i = 1; i <= n; i++){
            // If a cut of length x is possible, update dp[i]
            if(i-x >= 0) dp[i] = max(dp[i], dp[i-x] + 1);

            // If a cut of length y is possible, update dp[i]
            if(i-y >= 0) dp[i] = max(dp[i], dp[i-y] + 1);

            // If a cut of length z is possible, update dp[i]
            if(i-z >= 0) dp[i] = max(dp[i], dp[i-z] + 1);
        }

        // Return the maximum number of cuts for length n
        // If no valid cuts are possible, dp[n] will still be INT_MIN
        return dp[n];
    }
    
    // Function to calculate the maximum number of cuts that can be made
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // Call the solve function to calculate the maximum cuts
        int maxCuts = solve(n, x, y, z);

        // If the result is negative, it means no valid cuts are possible
        if(maxCuts < 0) return 0;

        // Return the maximum number of valid cuts
        return maxCuts;
    }
};
```

### Source Code Explanation

1. **`vector<int> dp(n+1, INT_MIN);`**:
   - We initialize a DP array `dp[]` of size `n+1`. All elements are initially set to `INT_MIN` to represent invalid states (where no cuts are possible).
   
2. **`dp[0] = 0;`**:
   - We set `dp[0] = 0`, because when the rod length is `0`, no cuts are needed, so the maximum cuts are `0`.

3. **`for(int i = 1; i <= n; i++)`**:
   - We iterate over all possible rod lengths from `1` to `n`, and for each length `i`, we try to cut the rod with the available segment lengths `x`, `y`, and `z`.

4. **`if(i-x >= 0) dp[i] = max(dp[i], dp[i-x] + 1);`**:
   - For each rod length `i`, we check if it's possible to make a cut of length `x`. If `i - x >= 0` (i.e., the remaining length after cutting `x` is non-negative), we update `dp[i]` to the maximum value between its current value and `dp[i-x] + 1`. This is because `dp[i-x] + 1` represents the maximum cuts we can make for length `i-x` plus one additional cut of length `x`.

5. **`if(i-y >= 0) dp[i] = max(dp[i], dp[i-y] + 1);`**:
   - Similarly, we check if it's possible to make a cut of length `y` and update `dp[i]` accordingly.

6. **`if(i-z >= 0) dp[i] = max(dp[i], dp[i-z] + 1);`**:
   - We repeat the same for a cut of length `z`.

7. **`return dp[n];`**:
   - Once the loop completes, `dp[n]` will contain the maximum number of cuts for a rod of length `n`. If no valid cuts are possible, `dp[n]` will still be `INT_MIN`.

8. **`if(maxCuts < 0) return 0;`**:
   - If the result stored in `dp[n]` is negative (indicating no valid cuts were possible), we return `0`.

9. **`return maxCuts;`**:
   - Otherwise, we return the maximum number of cuts found.

### Example

**Input**:  
`n = 7`, `x = 2`, `y = 1`, `z = 3`

**Execution**:
- Initially, the DP array `dp[]` is:  
  `[0, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN]`
- The loop runs for each rod length from `1` to `7`, and updates the `dp[]` array as follows:
  - For `i = 1`: `dp[1] = 1` (cut of length `1`).
  - For `i = 2`: `dp[2] = 1` (cut of length `2`).
  - For `i = 3`: `dp[3] = 2` (cut of length `1` twice or one cut of length `3`).
  - For `i = 4`: `dp[4] = 2` (cut of length `2` twice).
  - For `i = 5`: `dp[5] = 3` (cut of length `2` and `3`).
  - For `i = 6`: `dp[6] = 3` (cut of length `2` three times).
  - For `i = 7`: `dp[7] = 4` (cut of length `2` and `3`).

**Output**:  
`4`

### Time and Space Complexity:

- **Time Complexity**:  
  The time complexity is `O(n)`, where `n` is the length of the rod. We iterate over all lengths from `1` to `n` and perform constant-time operations for each length.

- **Space Complexity**:  
  The space complexity is `O(n)` because we use an array `dp[]` of size `n+1` to store the results for each length.

This makes the bottom-up approach efficient and suitable for larger values of `n`, avoiding the overhead of recursion in the top-down approach.

---

## Space Optimization (Not Possible)
In dynamic programming problems, **space optimization** is often possible if we can reduce the storage requirements of the DP array by observing certain patterns. For many problems, we can reduce the space complexity from `O(n)` to `O(1)` by using only a few variables to store previous results instead of an entire array.

### Why Space Optimization is Not Possible in This Case:

In this problem, the goal is to maximize the number of cuts from a rod of length `n` using cuts of length `x`, `y`, and `z`. We use a DP table where `dp[i]` represents the maximum number of cuts possible for a rod of length `i`. The main reason space optimization is not possible here lies in the way the state transitions are defined and the dependence on previous values.

#### 1. **Non-local Dependencies**:
   - The value of `dp[i]` depends on the values of `dp[i-x]`, `dp[i-y]`, and `dp[i-z]`, i.e., the maximum cuts possible for the rod lengths that are smaller than `i`.
   - To compute the value of `dp[i]`, we need to keep track of all previous values, specifically the results for `dp[i-x]`, `dp[i-y]`, and `dp[i-z]`. This dependency requires storing results for all lengths up to `i`, meaning we cannot simply discard earlier values without losing necessary information for subsequent computations.

#### 2. **Multiple Transitions**:
   - In this problem, we are performing multiple transitions (one for each possible cut size: `x`, `y`, and `z`) for every `i` from `1` to `n`. The result for each `i` depends on the results for all previous lengths, so we cannot use only the last few values.
   - Unlike problems where we can track only the immediate previous state (like in problems where we are building solutions based on a sequence), here we need to keep track of a broader range of previous states (`dp[i-x]`, `dp[i-y]`, `dp[i-z]`).

#### 3. **Multiple States Required**:
   - To maintain the correctness of the DP approach, we need the entire history of results for lengths from `1` to `n`. If we attempt to reduce the space by only storing a small portion of the array, we would lose access to crucial earlier states that influence the calculation of later states.
   - For example, to compute `dp[7]`, we need `dp[4]`, `dp[5]`, and `dp[6]` (as we check `dp[i-x]`, `dp[i-y]`, and `dp[i-z]`), and each of these values comes from earlier computations. Discarding values too early would lead to incorrect results.

#### 4. **Impossible to Roll Back the States**:
   - While some dynamic programming problems can be optimized by maintaining only a limited subset of previous states (like only the previous row in a 2D DP table), this problem does not allow such optimization because we need to keep track of all results for every possible rod length up to `n`. 
   - Since the cuts are of different lengths (`x`, `y`, and `z`), there's no simple way to reduce the state space while still ensuring the correctness of the results for every length.

### Example: Illustrating the Problem with Space Optimization

Consider a rod of length `7` with possible cuts of lengths `2`, `3`, and `5`. Here's how the table might look:

| Length `i` | Possible Cuts | Transitions (dp) | `dp[i]` |
|------------|---------------|------------------|---------|
| 0          | None          | Base Case        | 0       |
| 1          | None          | -                | -       |
| 2          | 2             | dp[2-2] + 1 = 1  | 1       |
| 3          | 3             | dp[3-3] + 1 = 1  | 1       |
| 4          | 2, 3          | dp[4-2] + 1 = 2  | 2       |
| 5          | 2, 3          | dp[5-2] + 1 = 2  | 2       |
| 6          | 2, 3          | dp[6-2] + 1 = 3  | 3       |
| 7          | 2, 3, 5       | dp[7-2] + 1 = 4  | 4       |

- Notice that to calculate `dp[7]`, we rely on the results of `dp[5]`, `dp[4]`, and `dp[2]`. Thus, each rod length depends on values that came earlier.
- If we were to only store the last three values in an attempt to optimize space, we'd lose access to earlier values like `dp[4]` or `dp[5]` when computing `dp[7]`. This would make it impossible to compute the correct result for `dp[7]`.

### Conclusion

Due to the **non-local dependencies** (each value depends on previous values), **multiple transitions** (checking multiple cut sizes), and the **need for all previous states** (to ensure correctness), space optimization is not possible in this problem. You must store all the DP states to correctly compute the result for larger lengths.

Hence, reducing the space complexity to `O(1)` or using a rolling array is not feasible for this problem. The current space complexity of `O(n)` is required to store the results for all rod lengths up to `n`.
