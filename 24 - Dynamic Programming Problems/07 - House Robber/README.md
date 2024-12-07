<h1 align="center">House - Robber</h1>

## Problem Statement

**Problem URL :** [House Robber](https://leetcode.com/problems/house-robber/description/)

![image](https://github.com/user-attachments/assets/60e42faa-5ecb-42b9-9c63-e2aa5f10b1c8)

### Problem Explanation
The **House Robber** problem is a classic dynamic programming problem often encountered in algorithmic challenges, such as LeetCode.

You are a robber who wants to rob houses along a street. Each house has a certain amount of money, but you have a restriction: **you cannot rob two adjacent houses**. If you rob two adjacent houses, the police will be alerted, and you will be caught.

You are given a list of integers `nums`, where each integer represents the amount of money stored in a particular house. The goal is to determine the maximum amount of money you can rob without alerting the police (i.e., without robbing two adjacent houses).

### Constraints:
- You are given an integer array `nums`, where `nums[i]` represents the amount of money at house `i`.
- The length of `nums` is `n`, and `1 <= n <= 100`.
- `0 <= nums[i] <= 400`.

### Key Insights:
1. **Adjacency Constraint**: The most important constraint is that you **cannot rob two adjacent houses**. This implies that you must choose between robbing the current house and skipping the previous one or skipping the current house and considering the previous one.
  
2. **Optimization Objective**: You need to maximize the total money you can rob. The challenge is determining the optimal combination of houses to rob while obeying the adjacency restriction.

### Approach:
The problem can be solved using a **dynamic programming approach**. The idea is to break the problem down into smaller subproblems and solve them in a bottom-up manner.

#### Dynamic Programming Approach:
- **State Representation**: Let `dp[i]` represent the maximum amount of money you can rob from the first `i` houses.
- **Recurrence Relation**:
  - For each house `i`, you have two choices:
    1. **Include house `i`**: This means you rob house `i` and add its value to the result from robbing up to house `i-2` (because you must skip house `i-1`).
    2. **Exclude house `i`**: This means you skip house `i` and keep the result from robbing up to house `i-1`.
  - Therefore, the recurrence relation is:
    
    `dp[i] = max(dp[i-1], nums[i] + dp[i-2])`
  
  - Base Cases:
    - `dp[0] = nums[0]` (If there's only one house, you can rob it).
    - `dp[1] = max(nums[0], nums[1])` (If there are two houses, you can rob the one with the maximum value).

#### Example Walkthrough:

Consider the following example:

```plaintext
nums = [2, 7, 9, 3, 1]
```

- `nums[0] = 2`: If there's only one house, rob it. So, `dp[0] = 2`.
- `nums[1] = 7`: With two houses, rob the one with the maximum value, which is `7`. So, `dp[1] = 7`.
  
For the remaining houses, we follow the recurrence relation:

- `dp[2] = max(dp[1], nums[2] + dp[0]) = max(7, 9 + 2) = 11`
  - If we rob house 2 (value 9), we must skip house 1 and add the result of robbing up to house 0 (`dp[0] = 2`).
  - So, robbing houses 0 and 2 gives a total of `9 + 2 = 11`.

- `dp[3] = max(dp[2], nums[3] + dp[1]) = max(11, 3 + 7) = 11`
  - Robbing house 3 would mean skipping house 2, but `dp[2]` already gives a higher value (11).
  
- `dp[4] = max(dp[3], nums[4] + dp[2]) = max(11, 1 + 11) = 12`
  - If we rob house 4 (value 1), we must skip house 3. Adding `dp[2] = 11` gives `1 + 11 = 12`.

At the end of this process, `dp[4] = 12` gives the maximum amount of money that can be robbed without alerting the police.

Thus, the optimal solution is to rob houses at indices 0, 2, and 4, yielding a total of `2 + 9 + 1 = 12`.

### Visual Representation:

```
House indices:   0   1   2   3   4
Money:          [2,  7,  9,  3,  1]

dp array:      [2,  7,  11, 11, 12]

At each house, the DP array keeps track of the maximum money that can be robbed up to that point.
```

### Time Complexity:
- The time complexity is **O(n)**, where `n` is the number of houses. We iterate through the list once, calculating the maximum money that can be robbed at each house.

### Space Complexity:
- The space complexity is **O(n)** if we use a DP array of size `n` to store the intermediate results. However, this can be optimized to **O(1)** if we only store the last two values (`prev1` and `prev2`).

### Edge Cases:
1. **Empty List**: If `nums` is empty (`[]`), the result should be `0` because there are no houses to rob.
2. **One House**: If `nums` has only one house, the result should be the value of that house.
3. **Two Houses**: If there are two houses, rob the one with the maximum value.

### Summary:
The House Robber problem is a dynamic programming problem that requires maximizing the total money you can rob from a list of houses, given that you cannot rob two adjacent houses. The solution involves keeping track of the maximum money that can be robbed up to each house, considering both robbing and skipping each house. The recurrence relation helps build the solution incrementally and efficiently.

---

## Recursive Approach (caused LTE)

The recursive approach for the **House Robber** problem involves trying to solve the problem by making decisions at each house: whether to rob the current house or skip it. At each step, we will be considering two possible options:

1. **Robbing the current house**: If we rob the current house, we cannot rob the next one (because of the adjacency constraint). We then move two steps ahead.
2. **Skipping the current house**: If we skip the current house, we move one step ahead and evaluate the next house.

By recursively solving the problem for each house (starting from the first or last house), we compute the maximum money that can be robbed.

### Approach 1: Recursion with Index Tracking

```cpp
// Approach 1: Recursion with Index Tracking
class Solution {
public:
    // Function to solve the problem recursively by tracking the current index `i` and total number of houses `n`
    int solve(vector<int>& money, int i, int n) {
        // Base cases: if we exceed the house index range, return 0 (no money left to rob)
        if (i > n) return 0;
        
        // If we reach the last house, return the money at the current index
        if (i == n) return money[i];

        // Option 1: Rob this house and skip the next one (i+2)
        int include = solve(money, i + 2, n) + money[i];

        // Option 2: Skip this house and move to the next one (i+1)
        int exclude = solve(money, i + 1, n) + 0;

        // Return the maximum of both choices (rob this house or skip it)
        return max(include, exclude);
    }

    // Main function to initiate the recursion and find the maximum money that can be robbed
    int rob(vector<int>& nums) {
        int n = nums.size();

        // Call the helper function starting from the first house (index 0)
        int maxMoney = solve(nums, 0, n - 1);

        // Return the maximum money that can be robbed
        return maxMoney;
    }
};

```
### Source Code Explanation
1. **Function Declaration:**
   ```cpp
   int solve(vector<int>& money, int i, int n)
   ```
   - This function is the core recursive function. It takes two arguments:
     - `money`: The list of money at each house.
     - `i`: The current house index we're considering.
     - `n`: The last house index.

2. **Base Case:**
   ```cpp
   if (i > n) return 0;
   ```
   - If the index exceeds the number of houses (i.e., `i > n`), it means we have no more houses to rob, so we return 0.

3. **Base Case (Last House):**
   ```cpp
   if (i == n) return money[i];
   ```
   - If we reach the last house (i.e., `i == n`), we return the amount of money at this house because it's the only one left to rob.

4. **Option 1: Rob the Current House:**
   ```cpp
   int include = solve(money, i + 2, n) + money[i];
   ```
   - If we rob the current house (`i`), we cannot rob the next house, so we recursively calculate the total money by moving to house `i + 2`. We then add the money at house `i` to this result.

5. **Option 2: Skip the Current House:**
   ```cpp
   int exclude = solve(money, i + 1, n) + 0;
   ```
   - If we skip the current house, we recursively calculate the total money by moving to house `i + 1`. We don't add any money for this house since we're skipping it.

6. **Return the Maximum Money:**
   ```cpp
   return max(include, exclude);
   ```
   - The function returns the maximum of the two options (rob the current house or skip it), which ensures that we are maximizing the total money robbed.

7. **Main Function (Initiating the Recursion):**
   ```cpp
   int rob(vector<int>& nums) {
       int n = nums.size();
       int maxMoney = solve(nums, 0, n - 1);
       return maxMoney;
   }
   ```
   - The `rob` function starts the recursion from the first house (`index 0`), passing the size of the `nums` array as `n - 1` (the last index).
   - It returns the maximum money that can be robbed by calling the helper function `solve`.


#### Example Walkthrough:

Consider the following example:

```plaintext
nums = [2, 7, 9, 3, 1]
```

- We start from house `0` (index 0) and make decisions at each house:
  
1. **Rob House 0 (Index 0):**
   - If we rob house `0` (money = 2), we skip house `1` and move to house `2`.
   - We then calculate the maximum money robbed from house `2` onwards.

2. **Skip House 0 (Index 0):**
   - If we skip house `0`, we move to house `1`.
   - We calculate the maximum money robbed from house `1` onwards.

3. This process continues recursively, and the maximum value between robbing or skipping each house is computed.

#### Example Recursion Steps:

- Starting at house `0` (index `0`), we recursively solve the problem for each house.
- For `i = 0`, we calculate the max value between robbing house `0` (then considering house `2` onward) or skipping it (and considering house `1` onward).
- This continues until all houses are evaluated.

### Output Example:

For the input `nums = [2, 7, 9, 3, 1]`, the recursion works as follows:

```plaintext
Max Money Robbed = 12
```

### Approach 2: Recursion with Index Backtracking
```cpp
// Approach 2: Recursion with Index Backtracking
class Solution {
public:
    // Function to solve the problem recursively by considering houses starting from the last index `n`
    int solve(vector<int>& money, int n) {
        // Base cases: if index `n` is out of bounds, return 0
        if (n < 0) return 0;
        
        // If we are at the first house, return the amount of money in the first house
        if (n == 0) return money[0];

        // Option 1: Rob this house and skip the next one (n-2)
        int include = solve(money, n - 2) + money[n];

        // Option 2: Skip this house and move to the previous one (n-1)
        int exclude = solve(money, n - 1) + 0;

        // Return the maximum of both choices (rob this house or skip it)
        return max(include, exclude);
    }

    // Main function to initiate the recursion and find the maximum money that can be robbed
    int rob(vector<int>& nums) {
        int n = nums.size();

        // Call the helper function starting from the last house (index n-1)
        int maxMoney = solve(nums, n - 1);

        // Return the maximum money that can be robbed
        return maxMoney;
    }
};
```

### Source Code Explanation
1. **Function Declaration:**
   ```cpp
   int solve(vector<int>& money, int n)
   ```
   - This is similar to the first approach, but here we start from the last house (`n`) and move backward.

2. **Base Case:**
   ```cpp
   if (n < 0) return 0;
   ```
   - If the index is less than 0, return 0 (no more houses to rob).

3. **Base Case (First House):**
   ```cpp
   if (n == 0) return money[0];
   ```
   - If we're at the first house, return the money at that house.

4. **Option 1: Rob the Current House:**
   ```cpp
   int include = solve(money, n - 2) + money[n];
   ```
   - If we rob the current house, we skip the previous house (`n-1`) and move two steps back to `n-2`.

5. **Option 2: Skip the Current House:**
   ```cpp
   int exclude = solve(money, n - 1);
   ```
   - If we skip the current house, we move to the previous house (`n-1`).

6. **Return the Maximum Money:**
   ```cpp
   return max(include, exclude);
   ```
   - We return the maximum of robbing the current house or skipping it.

7. **Main Function (Initiating the Recursion):**
   ```cpp
   int rob(vector<int>& nums) {
       int n = nums.size();
       return solve(nums, n - 1);
   }
   ```

#### Example Walkthrough:

For the input `nums = [2, 7, 9, 3, 1]`, starting from the last house:

1. **Rob House 4 (Index 4):** If we rob house 4 (money = 1), we skip house 3 and consider house 2.
2. **Skip House 4 (Index 4):** If we skip house 4, we move to house 3.
   
The process continues recursively, and the maximum money robbed is computed.

### Output Example:

For the input `nums = [2, 7, 9, 3, 1]`, the output is:

```plaintext
Max Money Robbed = 12
```

### Time and Space Complexity:

#### Time Complexity:
- Similar to the first approach, the time complexity is **O(2^n)** because we explore two choices at each level recursively.

#### Space Complexity:
- The space complexity is **O(n)** because the recursion depth can go up to `n`, where `n` is the number of houses.

### Summary:

- **Recursive Approach**: The problem can be solved recursively by deciding at each house whether to rob it or not. This solution, while simple, has exponential time complexity due to the large number of redundant subproblems.

---

## Top-Down Approach (DP)
The **Top-Down Approach with Memoization** optimizes recursion by storing intermediate results in a memoization array. Here's how it works:

### **Steps**

1. **Break the Problem into Subproblems:**
   - At each house (index `n`), decide whether to:
     - **Rob the house**: Add its value to the result and skip the next house (`n-2`).
     - **Skip the house**: Proceed to the next house (`n-1`).
   - Take the maximum of these two choices.

2. **Define Base Cases:**
   - If the index `n` is out of bounds (`n < 0`), there are no houses left to rob, so return `0`.
   - If at the first house (`n == 0`), return the money in that house (`money[0]`).

3. **Use Memoization to Avoid Redundant Calculations:**
   - Use a `dp` array where `dp[i]` stores the maximum money that can be robbed from house `0` to house `i`.
   - Before calculating for a house `n`, check if `dp[n]` is already computed. If yes, return it directly.

4. **Recursion with Memoization:**
   - For each house `n`, compute:
     - **Include the House**: `solve(n-2) + money[n]`
     - **Exclude the House**: `solve(n-1)`
   - Store the maximum of these two values in `dp[n]` to avoid recalculations.

5. **Final Step:**
   - Start solving from the last house (`n-1`) to compute the maximum money that can be robbed for the entire array.

### Source Code
```cpp
class Solution {
public:
    // Function to solve the problem recursively with memoization
    // `money`: vector of amounts of money in each house
    // `n`: the current house index
    // `dp`: memoization array to store the maximum money for each house index
    int solve(vector<int>& money, int n, vector<int>& dp) {
        // Base case: if the index `n` is less than 0, return 0 (no money left to rob)
        if (n < 0) return 0;

        // Base case: if we are at the first house (index 0), return the money at this house
        if (n == 0) return money[0];

        // If the result for this index `n` has already been calculated, return it from the `dp` array
        if (dp[n] != -1) return dp[n];

        // Option 1: Rob this house, so skip the next one (move to house `n-2`)
        int include = solve(money, n - 2, dp) + money[n];

        // Option 2: Skip this house, so move to the next house (house `n-1`)
        int exclude = solve(money, n - 1, dp) + 0;

        // Store the maximum of both choices in the memoization array `dp[n]`
        dp[n] = max(include, exclude);

        // Return the maximum money that can be robbed up to house `n`
        return dp[n];
    }

    // Main function to calculate the maximum money that can be robbed
    int rob(vector<int>& nums) {
        int n = nums.size(); // Get the number of houses

        // Initialize the dp array with -1 (indicating uncalculated values)
        // dp[i] will store the maximum money that can be robbed from house 0 to house i
        vector<int> dp(n + 1, -1);

        // Call the helper function starting from the last house (index n-1)
        int maxMoney = solve(nums, n - 1, dp);

        // Return the maximum money that can be robbed
        return maxMoney;
    }
};
```
### Source code Explanation

```cpp
class Solution {
public:
    // Helper function to solve the problem recursively with memoization
    int solve(vector<int>& money, int n, vector<int>& dp) {
        // Base case: If index `n` is out of bounds, return 0
        if (n < 0) return 0;
```
- **Line 1-5:** 
  - Define the recursive function `solve`.
  - Base case 1: If `n < 0` (no houses left to rob), return `0`.



```cpp
        // Base case: If we are at the first house (index 0), return its value
        if (n == 0) return money[0];
```
- **Base case 2:** If `n == 0`, only one house is available, so return its value.



```cpp
        // If the result for house `n` is already calculated, return it
        if (dp[n] != -1) return dp[n];
```
- Check if the result for `n` is already in the memoization array `dp`. If yes, return it to save computation.



```cpp
        // Option 1: Rob this house and skip the next one
        int include = solve(money, n - 2, dp) + money[n];
```
- If we **rob this house**, add its value to the maximum money robbed up to house `n-2`.



```cpp
        // Option 2: Skip this house and move to the previous one
        int exclude = solve(money, n - 1, dp) + 0;
```
- If we **skip this house**, the result is the maximum money robbed up to house `n-1`.



```cpp
        // Store the maximum of both choices in dp array
        dp[n] = max(include, exclude);
```
- Take the maximum of the two choices (`include` and `exclude`) and store it in `dp[n]`.



```cpp
        // Return the result for house `n`
        return dp[n];
    }
```
- Return the maximum money that can be robbed up to house `n`.



```cpp
    // Main function to calculate the maximum money that can be robbed
    int rob(vector<int>& nums) {
        int n = nums.size(); // Get the total number of houses
```
- Define the main function `rob`.
- Get the number of houses `n`.



```cpp
        // Initialize a memoization array with -1
        vector<int> dp(n + 1, -1);
```
- Initialize a `dp` array of size `n+1` with `-1` to indicate uncalculated results.



```cpp
        // Start the recursion from the last house (index `n-1`)
        int maxMoney = solve(nums, n - 1, dp);
```
- Call the `solve` function starting from the last house (`n-1`).



```cpp
        // Return the maximum money that can be robbed
        return maxMoney;
    }
};
```
- Return the result, which is the maximum money that can be robbed.



### **Example Output**

#### Input:
```cpp
nums = {2, 7, 9, 3, 1};
```

#### Execution Steps:
1. Start from `n = 4` (last house):
   - Include: `money[4] + solve(2)` = `1 + 11 = 12`
   - Exclude: `solve(3)` = `11`
   - `dp[4] = max(12, 11) = 12`

2. Solve for `n = 3`:
   - Include: `money[3] + solve(1)` = `3 + 7 = 10`
   - Exclude: `solve(2)` = `11`
   - `dp[3] = max(10, 11) = 11`

3. Solve for `n = 2`:
   - Include: `money[2] + solve(0)` = `9 + 2 = 11`
   - Exclude: `solve(1)` = `7`
   - `dp[2] = max(11, 7) = 11`

4. Solve for `n = 1`:
   - Include: `money[1] + solve(-1)` = `7 + 0 = 7`
   - Exclude: `solve(0)` = `2`
   - `dp[1] = max(7, 2) = 7`

5. Solve for `n = 0`:
   - `dp[0] = 2`

#### Final `dp` Array:
```cpp
dp = {2, 7, 11, 11, 12};
```

#### Output:
```plaintext
Input: nums = [2, 7, 9, 3, 1]
Output: 12
```

### **Time and Space Complexity**

#### Time Complexity:
- Each house is visited once, and each calculation is \( O(1) \).
- Overall: \( O(n) \), where \( n \) is the number of houses.

#### Space Complexity:
- **Memoization Array (`dp`)**: \( O(n) \).
- **Recursive Stack Depth**: \( O(n) \).
- Overall: \( O(n) \).

---

## Bottom-Up Approach (DP)
The **Bottom-Up Approach** with **Dynamic Programming** builds the solution iteratively from smaller subproblems. Unlike the top-down approach, it eliminates recursion and calculates results iteratively.

### **Steps**

1. **Initialize Base Cases:**
   - If there are no houses (`n == 0`), the result is `0`.
   - If there is only one house (`n == 1`), the maximum money robbed is the amount in that house.

2. **Define the DP Array:**
   - Use a `dp` array where `dp[i]` stores the maximum money that can be robbed from house `0` to house `i`.

3. **Transition Relation:**
   - For each house `i`, calculate:
     - **Include the House**: Rob house `i` and add the money from house `i-2`.
     - **Exclude the House**: Skip house `i` and take the maximum money robbed up to house `i-1`.
   - Store the maximum of these two options in `dp[i]`.

4. **Iterate Over the Houses:**
   - Start from house `2` (third house) and compute `dp[i]` iteratively for all houses.

5. **Final Step:**
   - Return `dp[n-1]`, which represents the maximum money that can be robbed up to the last house.

### Source Code
```cpp
class Solution {
public:
    // Function to solve the problem using dynamic programming (bottom-up approach)
    // `money`: vector containing the amounts of money in each house
    // `n`: the number of houses
    int solve(vector<int>& money, int n) {
        // If there are no houses, return 0 (no money can be robbed)
        if (n == 0) return 0;
        
        // Create a DP array to store the maximum money that can be robbed up to each house
        // dp[i] will store the maximum money that can be robbed from house 0 to house i
        vector<int> dp(n, 0);

        // Base case: Only one house, so rob it
        dp[0] = money[0];

        // If there are at least two houses, calculate the maximum money from the first two houses
        if (n > 1) dp[1] = max(money[0], money[1]);

        // Loop through the remaining houses starting from the third house
        for (int i = 2; i < n; i++) {
            // Option 1: Rob this house (house i), and add the money from the house two steps before (dp[i-2])
            int include = dp[i - 2] + money[i];

            // Option 2: Skip this house (house i), and take the maximum money robbed from the previous house (dp[i-1])
            int exclude = dp[i - 1] + 0;

            // Store the maximum of the two options in dp[i]
            dp[i] = max(include, exclude);
        }

        // Return the maximum money that can be robbed up to the last house (dp[n-1])
        return dp[n - 1];
    }

    // Main function to start solving the problem
    int rob(vector<int>& nums) {
        int n = nums.size(); // Get the number of houses
        
        // Call the helper function to calculate the maximum money that can be robbed
        int maxMoney = solve(nums, n);

        // Return the result
        return maxMoney;
    }
};
```

### Source Code Explanation

```cpp
class Solution {
public:
    // Function to solve the problem using dynamic programming (bottom-up approach)
    int solve(vector<int>& money, int n) {
        // If there are no houses, return 0
        if (n == 0) return 0;
```
- **Line 1-4:**
  - Define the function `solve`.
  - Handle the base case where there are no houses (`n == 0`), returning `0`.



```cpp
        // Create a DP array to store the maximum money that can be robbed
        vector<int> dp(n, 0);
```
- Initialize the `dp` array of size `n` with `0`. Each element will store the maximum money robbed up to house `i`.



```cpp
        // Base case: Only one house, so rob it
        dp[0] = money[0];
```
- If there is only one house, rob it. Store its value in `dp[0]`.



```cpp
        // If there are at least two houses, calculate the max money from the first two houses
        if (n > 1) dp[1] = max(money[0], money[1]);
```
- If there are two houses, the maximum money robbed is the greater of the two amounts (`money[0]` or `money[1]`).



```cpp
        // Loop through the remaining houses starting from the third house
        for (int i = 2; i < n; i++) {
            // Option 1: Rob this house and add the money from house two steps before
            int include = dp[i - 2] + money[i];
            
            // Option 2: Skip this house and take the maximum money robbed so far
            int exclude = dp[i - 1] + 0;

            // Store the maximum of the two options
            dp[i] = max(include, exclude);
        }
```
- For houses `2` to `n-1`, calculate the maximum money robbed:
  - **Include the House:** Add `money[i]` to `dp[i-2]`.
  - **Exclude the House:** Use the result from `dp[i-1]`.
  - Store the greater of these two in `dp[i]`.



```cpp
        // Return the maximum money that can be robbed up to the last house
        return dp[n - 1];
    }
```
- Return `dp[n-1]`, which holds the maximum money robbed up to the last house.



```cpp
    // Main function to start solving the problem
    int rob(vector<int>& nums) {
        int n = nums.size(); // Get the number of houses
        
        // Call the helper function to calculate the maximum money
        int maxMoney = solve(nums, n);

        // Return the result
        return maxMoney;
    }
};
```
- The `rob` function:
  - Calls the `solve` function.
  - Returns the result, which is the maximum money robbed.



### **Example Output**

#### Input:
```cpp
nums = {2, 7, 9, 3, 1};
```

#### Execution Steps:
1. Initialize `dp`:
   ```plaintext
   dp = [0, 0, 0, 0, 0];
   ```

2. Base cases:
   - `dp[0] = 2`
   - `dp[1] = max(2, 7) = 7`
   ```plaintext
   dp = [2, 7, 0, 0, 0];
   ```

3. Compute `dp[2]`:
   - Include: `dp[0] + money[2] = 2 + 9 = 11`
   - Exclude: `dp[1] = 7`
   - `dp[2] = max(11, 7) = 11`
   ```plaintext
   dp = [2, 7, 11, 0, 0];
   ```

4. Compute `dp[3]`:
   - Include: `dp[1] + money[3] = 7 + 3 = 10`
   - Exclude: `dp[2] = 11`
   - `dp[3] = max(10, 11) = 11`
   ```plaintext
   dp = [2, 7, 11, 11, 0];
   ```

5. Compute `dp[4]`:
   - Include: `dp[2] + money[4] = 11 + 1 = 12`
   - Exclude: `dp[3] = 11`
   - `dp[4] = max(12, 11) = 12`
   ```plaintext
   dp = [2, 7, 11, 11, 12];
   ```

6. Final Output:
   ```plaintext
   dp[n-1] = dp[4] = 12
   ```

#### Output:
```plaintext
Input: nums = [2, 7, 9, 3, 1]
Output: 12
```

### **Time and Space Complexity**

#### Time Complexity:
- Iterates through all houses once, so \( O(n) \).

#### Space Complexity:
- Uses a `dp` array of size \( n \), so \( O(n) \).

---

## Space Optimized Approach (DP)
The **Space-Optimized Approach** further improves the bottom-up DP solution by removing the need for a DP array. Instead, it keeps track of the maximum money robbed using two variables: `prev2` (result up to house `i-2`) and `prev1` (result up to house `i-1`).

### **Steps**

1. **Base Cases:**
   - If there are no houses (`n == 0`), return `0`.
   - If there is only one house (`n == 1`), return the value of that house.

2. **Initialize Variables:**
   - `prev2`: Represents the maximum money robbed up to house `0`.
   - `prev1`: Represents the maximum money robbed up to house `1`.

3. **Iterate Over the Houses:**
   - Start from the third house (`i = 2`) and calculate the maximum money robbed for each house:
     - **Include the House:** Add the current house's money to `prev2` (money robbed up to house `i-2`).
     - **Exclude the House:** Use `prev1` (money robbed up to house `i-1`).
   - Store the maximum of the two options as `current`.

4. **Update Variables:**
   - Shift `prev1` to `prev2` for the next iteration.
   - Update `prev1` to the current result (`current`).

5. **Final Step:**
   - Return `prev1`, which holds the maximum money robbed after iterating through all houses.
     
### Source Code
```cpp
class Solution {
public:
    // Function to solve the problem using dynamic programming (optimized space approach)
    // `money`: vector containing the amounts of money in each house
    // `n`: the number of houses
    int solve(vector<int>& money, int n) {
        // Base cases:
        // prev2 represents the maximum money robbed from houses up to index 0
        // prev1 represents the maximum money robbed from houses up to index 1
        int prev2 = money[0];  // Only one house, so rob it
        int prev1 = max(money[0], money[1]);  // Take the maximum of robbing the first or second house

        // Iterate through the remaining houses starting from index 2
        for (int i = 2; i < n; i++) {
            // Option 1: Rob the current house (house i), and add money from house i to the result of robbing house i-2 (prev2)
            int include = prev2 + money[i];

            // Option 2: Skip the current house (house i), and keep the maximum from the previous house (prev1)
            int exclude = prev1 + 0;

            // Calculate the maximum money we can rob up to house i by choosing either to include or exclude house i
            int current = max(include, exclude);

            // Update prev2 and prev1 for the next iteration
            prev2 = prev1;  // Move prev1 to prev2 (we are shifting one step to the right)
            prev1 = current;  // Update prev1 to be the maximum of robbing up to house i
        }

        // After iterating through all houses, prev1 will hold the maximum money that can be robbed
        return prev1;
    }

    // Main function to start solving the problem
    int rob(vector<int>& nums) {
        int n = nums.size(); // Get the number of houses

        // Handle edge cases where there are no houses or only one house
        if (n == 0) return 0; // No houses to rob
        if (n == 1) return nums[0]; // Only one house to rob, return its value

        // Call the helper function to calculate the maximum money that can be robbed
        return solve(nums, n);
    }
};
```

### Source Code Explanation

```cpp
class Solution {
public:
    // Function to solve the problem using dynamic programming (optimized space approach)
    int solve(vector<int>& money, int n) {
        // Base cases:
        int prev2 = money[0];  // Robbing the first house
        int prev1 = max(money[0], money[1]);  // Robbing either the first or second house
```
- **Line 1-5:** 
  - Define the `solve` function.
  - Handle the base cases using two variables:
    - `prev2` is initialized to the value of the first house.
    - `prev1` stores the maximum of robbing either the first or second house.



```cpp
        // Iterate through the remaining houses starting from index 2
        for (int i = 2; i < n; i++) {
            // Option 1: Rob this house (add its money to prev2)
            int include = prev2 + money[i];

            // Option 2: Skip this house (take prev1)
            int exclude = prev1 + 0;

            // Store the maximum of the two options
            int current = max(include, exclude);
```
- **Line 6-15:** 
  - For each house starting from the third, calculate:
    - **Include the House:** Add the current house's money to `prev2`.
    - **Exclude the House:** Keep the value in `prev1`.
  - Store the maximum of these two options in `current`.



```cpp
            // Update prev2 and prev1 for the next iteration
            prev2 = prev1;  // Shift prev1 to prev2
            prev1 = current;  // Update prev1 with the current maximum
        }
```
- **Line 16-19:** 
  - Update `prev2` and `prev1` for the next iteration:
    - Shift `prev1` to `prev2`.
    - Assign the result of the current house (`current`) to `prev1`.



```cpp
        // Return the maximum money that can be robbed
        return prev1;
    }
```
- **Line 20-21:**
  - Return `prev1`, which holds the final result after iterating through all houses.



```cpp
    // Main function to start solving the problem
    int rob(vector<int>& nums) {
        int n = nums.size(); // Get the number of houses

        // Handle edge cases
        if (n == 0) return 0; // No houses
        if (n == 1) return nums[0]; // One house, return its value

        // Call the solve function
        return solve(nums, n);
    }
};
```
- **Line 22-31:**
  - Handle special cases:
    - No houses → return `0`.
    - One house → return its value.
  - Otherwise, call the `solve` function to calculate the maximum money.



### **Example Output**

#### Input:
```cpp
nums = {2, 7, 9, 3, 1};
```

#### Execution Steps:
1. Initialize variables:
   ```plaintext
   prev2 = 2
   prev1 = max(2, 7) = 7
   ```

2. Calculate for house `2`:
   - Include: `prev2 + nums[2] = 2 + 9 = 11`
   - Exclude: `prev1 = 7`
   - `current = max(11, 7) = 11`
   - Update:
     ```plaintext
     prev2 = 7
     prev1 = 11
     ```

3. Calculate for house `3`:
   - Include: `prev2 + nums[3] = 7 + 3 = 10`
   - Exclude: `prev1 = 11`
   - `current = max(10, 11) = 11`
   - Update:
     ```plaintext
     prev2 = 11
     prev1 = 11
     ```

4. Calculate for house `4`:
   - Include: `prev2 + nums[4] = 11 + 1 = 12`
   - Exclude: `prev1 = 11`
   - `current = max(12, 11) = 12`
   - Update:
     ```plaintext
     prev2 = 11
     prev1 = 12
     ```

5. Final result:
   ```plaintext
   prev1 = 12
   ```

#### Output:
```plaintext
Input: nums = [2, 7, 9, 3, 1]
Output: 12
```



### **Time and Space Complexity**

#### Time Complexity:
- The algorithm iterates through all houses once, so \( O(n) \).

#### Space Complexity:
- Only two variables (`prev1` and `prev2`) are used, so \( O(1) \).

 

This optimized solution is highly efficient for large inputs.
