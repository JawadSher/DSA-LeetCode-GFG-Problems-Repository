<h1 align="center">Combination - Sum IV</h1>

## Problem Statement

**Problem URL (leetcode):** [Combination Sum IV](https://leetcode.com/problems/combination-sum-iv/description/)

**Problem URL (GFG):** [Combination Sum IV](https://www.geeksforgeeks.org/problems/4-combination-sum/1)

![image](https://github.com/user-attachments/assets/8a2f4220-fb2f-4acc-88fe-939ef00512b3)

### Problem Explanation
The **Combination Sum IV** problem requires finding how many possible combinations of numbers from a given array `nums` can sum up to a target value. Each number in the array can be used multiple times, and the order in which numbers are arranged matters.

### **Problem Details**

1. **Input**:
   - `nums`: An array of distinct positive integers.
   - `target`: A positive integer.

2. **Output**:
   - An integer representing the number of possible combinations of numbers from `nums` that sum up to `target`.

3. **Key Constraints**:
   - Numbers in `nums` can be used **repeatedly**.
   - **Order matters**, meaning `[1, 2]` and `[2, 1]` are treated as different combinations.

### **Examples**

#### **Example 1**
**Input**:  
nums = [1, 2, 3], target = 4  

**Explanation**:  
The combinations that add up to `4` are:  
1. [1, 1, 1, 1]  
2. [1, 1, 2]  
3. [1, 2, 1]  
4. [2, 1, 1]  
5. [2, 2]  
6. [1, 3]  
7. [3, 1]  

**Output**:  
7  

#### **Example 2**
**Input**:  
nums = [9], target = 3  

**Explanation**:  
No combination can add up to `3` using only the number `9`.  

**Output**:  
0  

### **Objective**
The goal is to count all the unique combinations of numbers in `nums` (considering order) that sum up to the `target`.

---

## Recursive Approach (caused TLE)

### **Step-by-Step Explanation of the Recursive Approach**

The recursive approach breaks down the problem into smaller subproblems. The goal is to count all combinations of numbers in `nums` that sum up to the `target`.



#### **Steps of the Recursive Approach**
1. **Base Cases**:
   - If `target < 0`: No combination can sum up to a negative number, so return `0`.
   - If `target == 0`: A valid combination is found (no further numbers are needed), so return `1`.

2. **Recursive Calls**:
   - For each number in `nums`, reduce the `target` by that number and make a recursive call to calculate the number of ways to achieve the reduced target.
   - Accumulate the results of all recursive calls to compute the total number of combinations.

3. **Return Value**:
   - Return the accumulated count of valid combinations for the given `target`.



### **Example**

#### Input:
nums = [1, 2, 3], target = 4  

#### Recursive Breakdown:
1. Start with `target = 4`.  
   - Try `1`: Recursively call for `target = 4 - 1 = 3`.
   - Try `2`: Recursively call for `target = 4 - 2 = 2`.
   - Try `3`: Recursively call for `target = 4 - 3 = 1`.

2. Continue breaking down:
   - For `target = 3`, try each number:
     - `1 → target = 2`
     - `2 → target = 1`
     - `3 → target = 0` (base case: return `1`).
   - Repeat for `target = 2` and `target = 1`.

3. Accumulate results:
   - For `target = 4`, sum up all valid combinations from the recursive calls for `target = 3`, `target = 2`, and `target = 1`.

### Source code
```cpp
class Solution {
public:
    // Recursive function to calculate the number of combinations
    int solve(vector<int>& nums, int target) {
        // Base case: If the target becomes negative, no valid combination is possible
        if(target < 0) return 0;

        // Base case: If the target becomes zero, one valid combination is found
        if(target == 0) return 1;

        // Initialize a variable to store the number of valid combinations
        int ans = 0;

        // Iterate through each number in the array
        for(int i = 0; i < nums.size(); i++) {
            // Recursively reduce the target by the current number and add the result
            ans += solve(nums, target - nums[i]);
        }

        // Return the total number of valid combinations for the current target
        return ans;
    }

    // Main function to calculate the number of combinations for a given target
    int combinationSum4(vector<int>& nums, int target) {
        // Call the recursive function to solve the problem
        return solve(nums, target);
    }
};
```

### Source Code Explanation

```cpp
class Solution {
public:
    // Recursive function to calculate the number of combinations
    int solve(vector<int>& nums, int target) {
        // Base case: If the target becomes negative, no valid combination is possible
        if(target < 0) return 0;
```
- **Logic**: A negative target means the current path exceeded the sum, so no further numbers should be added. Return `0` to indicate failure for this path.

```cpp
        // Base case: If the target becomes zero, one valid combination is found
        if(target == 0) return 1;
```
- **Logic**: A target of `0` means the numbers chosen so far form a valid combination. Return `1` to indicate success for this path.

```cpp
        // Initialize a variable to store the number of valid combinations
        int ans = 0;
```
- **Logic**: `ans` keeps track of the total number of combinations for the current `target`.

```cpp
        // Iterate through each number in the array
        for(int i = 0; i < nums.size(); i++) {
            // Recursively reduce the target by the current number and add the result
            ans += solve(nums, target - nums[i]);
        }
```
- **Logic**:
  - Iterate through the `nums` array.
  - Subtract the current number from `target` and recursively calculate the number of combinations for the reduced `target`.
  - Add the result to `ans`.

```cpp
        // Return the total number of valid combinations for the current target
        return ans;
    }
```
- **Logic**: Return the accumulated count of valid combinations for the current `target`.

```cpp
    // Main function to calculate the number of combinations for a given target
    int combinationSum4(vector<int>& nums, int target) {
        // Call the recursive function to solve the problem
        return solve(nums, target);
    }
};
```
- **Logic**: The `combinationSum4` function initializes the recursive process by calling `solve(nums, target)`.



### **Detailed Example**

#### Input:
nums = [1, 2, 3], target = 4  

#### Recursive Calls:
- `solve(nums, 4)`  
  - `solve(nums, 3)`  
    - `solve(nums, 2)`  
      - `solve(nums, 1)`  
        - `solve(nums, 0)` → return 1 (base case)  
        - `solve(nums, -1)` → return 0 (base case)  
        - `solve(nums, -2)` → return 0 (base case)  
      - Result for `target = 1` = 1.  
    - Result for `target = 2` = 2.  
  - Result for `target = 3` = 4.  
- Result for `target = 4` = 7.  



### **Time and Space Complexity**

1. **Time Complexity**:
   - In the worst case, there are `target` recursive calls for each number in `nums`, leading to an exponential time complexity of (O(n^{{target}})), where (n) is the size of the array.

2. **Space Complexity**:
   - The recursion stack can grow up to the depth of `target`, leading to a space complexity of (O({target})).

---

## Top-Down Approach (DP)

The **top-down approach** uses recursion with memoization or a dynamic programming (DP) table to count all possible combinations of numbers in the array `nums` that sum up to the `target`. The method iteratively builds solutions for smaller subproblems and combines them to solve the overall problem.

### **Step-by-Step Explanation of the Approach**

#### **Logic**
1. Define a DP array `dp`, where `dp[i]` represents the number of ways to sum up to the value `i` using numbers from `nums`.
2. Start with the base case:
   - `dp[0] = 1` because there's only one way to form the sum 0, which is to pick nothing.
3. Iterate over all target sums from 1 to `target` and calculate the number of ways for each target sum.
4. For each target, iterate over all numbers in `nums` and check if they can contribute to the current target:
   - If the current number can contribute, add the ways to form the reduced target to `dp[currentTarget]`.
   - Handle integer overflow by checking if adding values would exceed `INT_MAX`.

5. The result is stored in `dp[target]`.



### **Example**

#### Input:
nums = [1, 2, 3], target = 4  

#### Steps:
1. Initialize `dp` as:
   - `dp = [1, 0, 0, 0, 0]` (initial state, where `dp[0] = 1`).
2. Process `currentTarget` from 1 to 4:
   - For `currentTarget = 1`:  
     - Use `1`: Add `dp[1-1] = dp[0]` → `dp[1] = 1`.  
     - Use `2` and `3`: Not possible since `1 - nums[i] < 0`.
     - Result: `dp = [1, 1, 0, 0, 0]`.

   - For `currentTarget = 2`:  
     - Use `1`: Add `dp[2-1] = dp[1]` → `dp[2] = 1`.  
     - Use `2`: Add `dp[2-2] = dp[0]` → `dp[2] = 2`.  
     - Use `3`: Not possible since `2 - nums[i] < 0`.
     - Result: `dp = [1, 1, 2, 0, 0]`.

   - For `currentTarget = 3`:  
     - Use `1`: Add `dp[3-1] = dp[2]` → `dp[3] = 2`.  
     - Use `2`: Add `dp[3-2] = dp[1]` → `dp[3] = 3`.  
     - Use `3`: Add `dp[3-3] = dp[0]` → `dp[3] = 4`.  
     - Result: `dp = [1, 1, 2, 4, 0]`.

   - For `currentTarget = 4`:  
     - Use `1`: Add `dp[4-1] = dp[3]` → `dp[4] = 4`.  
     - Use `2`: Add `dp[4-2] = dp[2]` → `dp[4] = 6`.  
     - Use `3`: Add `dp[4-3] = dp[1]` → `dp[4] = 7`.  
     - Result: `dp = [1, 1, 2, 4, 7]`.

3. The final answer is `dp[4] = 7`.

### Source Code
```cpp
class Solution {
public:
    // Function to calculate the number of combinations using dynamic programming
    int solve(vector<int>& nums, int target) {
        // Edge case: If the target is negative or the input array is empty, return 0
        if(target < 0 || nums.empty()) return 0;

        // Create a DP array to store the number of ways to achieve each target sum
        vector<int> dp(target + 1, 0);

        // Base case: There's only one way to make a sum of 0 (choose nothing)
        dp[0] = 1;

        // Iterate over all possible target values from 1 to the given target
        for(int currentTarget = 1; currentTarget <= target; currentTarget++) {
            // Iterate through each number in the input array
            for(int numIndex = 0; numIndex < nums.size(); numIndex++) {
                // Check if the current number can contribute to the current target
                if(currentTarget - nums[numIndex] >= 0) {
                    // Handle potential integer overflow
                    if (dp[currentTarget] > INT_MAX - dp[currentTarget - nums[numIndex]]) {
                        dp[currentTarget] = INT_MAX; // Set to INT_MAX if overflow occurs
                    } else {
                        // Update dp[currentTarget] by adding the ways to achieve the reduced target
                        dp[currentTarget] += dp[currentTarget - nums[numIndex]];
                    }
                }
            }
        }

        // Return the number of combinations to make the target sum
        return dp[target];
    }

    // Main function to calculate the number of combinations
    int combinationSum4(vector<int>& nums, int target) {
        // Call the DP-based solve function
        return solve(nums, target);
    }
};
```

### Source Code Explanation

```cpp
class Solution {
public:
    // Function to calculate the number of combinations using dynamic programming
    int solve(vector<int>& nums, int target) {
        // Edge case: If the target is negative or the input array is empty, return 0
        if(target < 0 || nums.empty()) return 0;
```
- **Logic**:
  - Check if the target is invalid or `nums` is empty. If so, return `0` since no combinations are possible.

```cpp
        // Create a DP array to store the number of ways to achieve each target sum
        vector<int> dp(target + 1, 0);
```
- **Logic**:
  - Create a DP array of size `target + 1` initialized to `0`. Each index represents the number of ways to achieve the target sum equal to the index.

```cpp
        // Base case: There's only one way to make a sum of 0 (choose nothing)
        dp[0] = 1;
```
- **Logic**:
  - The sum `0` can only be achieved by picking no numbers, so `dp[0] = 1`.

```cpp
        // Iterate over all possible target values from 1 to the given target
        for(int currentTarget = 1; currentTarget <= target; currentTarget++) {
```
- **Logic**:
  - Iterate through all possible targets, starting from 1 up to the desired `target`.

```cpp
            // Iterate through each number in the input array
            for(int numIndex = 0; numIndex < nums.size(); numIndex++) {
```
- **Logic**:
  - For each `currentTarget`, consider each number in the `nums` array.

```cpp
                // Check if the current number can contribute to the current target
                if(currentTarget - nums[numIndex] >= 0) {
```
- **Logic**:
  - Check if the current number can contribute to the current target (i.e., `currentTarget - nums[numIndex] >= 0`).

```cpp
                    // Handle potential integer overflow
                    if (dp[currentTarget] > INT_MAX - dp[currentTarget - nums[numIndex]]) {
                        dp[currentTarget] = INT_MAX; // Set to INT_MAX if overflow occurs
                    } else {
                        // Update dp[currentTarget] by adding the ways to achieve the reduced target
                        dp[currentTarget] += dp[currentTarget - nums[numIndex]];
                    }
```
- **Logic**:
  - If adding `dp[currentTarget - nums[numIndex]]` would overflow, set `dp[currentTarget]` to `INT_MAX`.
  - Otherwise, update `dp[currentTarget]` by adding the number of ways to form the reduced target.

```cpp
                }
            }
        }
```
- **Logic**:
  - Iterate through all numbers in `nums` for each target and update `dp[currentTarget]`.

```cpp
        // Return the number of combinations to make the target sum
        return dp[target];
    }
```
- **Logic**:
  - Return the value of `dp[target]`, which holds the total number of combinations.

```cpp
    // Main function to calculate the number of combinations
    int combinationSum4(vector<int>& nums, int target) {
        // Call the DP-based solve function
        return solve(nums, target);
    }
};
```
- **Logic**:
  - The `combinationSum4` function initializes the process by calling the `solve` function.



### **Detailed Example**

#### Input:
nums = [1, 2, 3], target = 4  

#### DP Table Updates:
- `dp = [1, 0, 0, 0, 0]` (initial state)  
- `dp = [1, 1, 0, 0, 0]` (after `currentTarget = 1`)  
- `dp = [1, 1, 2, 0, 0]` (after `currentTarget = 2`)  
- `dp = [1, 1, 2, 4, 0]` (after `currentTarget = 3`)  
- `dp = [1, 1, 2, 4, 7]` (after `currentTarget = 4`).  

Final Answer: `dp[4] = 7`.



### **Time and Space Complexity**

1. **Time Complexity**:
   - The outer loop runs (O({target})).
   - The inner loop iterates over (O(n)) numbers in `nums`.
   - Total: (O(n times {target})).

2. **Space Complexity**:
   - The DP array uses (O({target})) space.
   - Total: (O({target})).

---

## Bottom-Up Approach (DP)
In the **Bottom-Up Approach**, we solve the problem iteratively by building solutions to smaller subproblems first and then combining them to find the final solution. This approach avoids recursion and uses dynamic programming to iteratively calculate the number of combinations for each possible target value from `0` to the given `target`.

### **Step-by-Step Explanation of Bottom-Up Approach**

1. **Initialization:**
   - We initialize a dynamic programming array `dp` where `dp[i]` represents the number of ways to make the sum `i` using the numbers in `nums`.
   - We set `dp[0] = 1` because there is exactly one way to make the sum `0`, which is by choosing nothing.

2. **Iterate over Target Values:**
   - We iterate from `1` to `target` and for each target value, we try each number in `nums` to see if we can use that number to make the target.
   - If `target - num >= 0`, we add `dp[target - num]` to `dp[target]`, meaning we can form the current target by adding the current number to a previously computed solution.

3. **Final Result:**
   - After iterating through all possible target values, `dp[target]` will contain the number of ways to make the given target using the numbers in `nums`.



### **Example Walkthrough**

Let's take the following example:

#### **Example Input:**
- `nums = [1, 2, 3]`
- `target = 4`

We will fill up the `dp` array to calculate the number of ways to form the target `4` using the numbers `[1, 2, 3]`.



#### **Initialization:**
- Initialize `dp` array of size `target + 1` (i.e., `5`), with all values set to `0`, except `dp[0] = 1`:
  ```cpp
  dp = [1, 0, 0, 0, 0]
  ```



#### **Iterate Over Each Target Value:**

- **For target = 1**:
  - We check each number in `nums`.
  - `1 - 1 >= 0`, so we add `dp[1 - 1] = dp[0]` to `dp[1]`. Now `dp[1] = 1`.
  - `dp = [1, 1, 0, 0, 0]`.

- **For target = 2**:
  - We check each number in `nums`.
  - `2 - 1 >= 0`, so we add `dp[2 - 1] = dp[1]` to `dp[2]`. Now `dp[2] = 1`.
  - `2 - 2 >= 0`, so we add `dp[2 - 2] = dp[0]` to `dp[2]`. Now `dp[2] = 2`.
  - `dp = [1, 1, 2, 0, 0]`.

- **For target = 3**:
  - We check each number in `nums`.
  - `3 - 1 >= 0`, so we add `dp[3 - 1] = dp[2]` to `dp[3]`. Now `dp[3] = 2`.
  - `3 - 2 >= 0`, so we add `dp[3 - 2] = dp[1]` to `dp[3]`. Now `dp[3] = 3`.
  - `3 - 3 >= 0`, so we add `dp[3 - 3] = dp[0]` to `dp[3]`. Now `dp[3] = 4`.
  - `dp = [1, 1, 2, 4, 0]`.

- **For target = 4**:
  - We check each number in `nums`.
  - `4 - 1 >= 0`, so we add `dp[4 - 1] = dp[3]` to `dp[4]`. Now `dp[4] = 4`.
  - `4 - 2 >= 0`, so we add `dp[4 - 2] = dp[2]` to `dp[4]`. Now `dp[4] = 6`.
  - `4 - 3 >= 0`, so we add `dp[4 - 3] = dp[1]` to `dp[4]`. Now `dp[4] = 7`.
  - `dp = [1, 1, 2, 4, 7]`.



#### **Final Result:**
- After processing all target values, `dp[4] = 7`, which is the number of ways to make the sum `4` using the numbers `[1, 2, 3]`.

#### **Combinations to Form Target = 4:**
1. `1 + 1 + 1 + 1`
2. `1 + 1 + 2`
3. `1 + 2 + 1`
4. `1 + 3`
5. `2 + 2`
6. `2 + 1 + 1`
7. `3 + 1`

Thus, there are 7 ways to make the sum `4` using the numbers `[1, 2, 3]`.



### **Summary:**

In the **Bottom-Up Approach**, we start from the smallest subproblem (making a sum of `0`), and build up to the target sum. The dynamic programming array `dp` helps us store the number of ways to make each target sum, avoiding redundant calculations and ensuring an efficient solution.

### Source Code
```cpp
class Solution {
public:
    // Recursive function to calculate the number of combinations with memoization
    int solve(vector<int>& nums, int target, vector<int>& dp) {
        // Base case: If the target becomes negative, no valid combination is possible
        if(target < 0) return 0;

        // Base case: If the target becomes zero, one valid combination is found
        if(target == 0) return 1;

        // If the result for the current target has already been calculated, return it
        if(dp[target] != -1) return dp[target];

        // Initialize a variable to store the number of valid combinations for the current target
        int ans = 0;

        // Iterate through each number in the array
        for(int i = 0; i < nums.size(); i++) {
            // Recursively calculate combinations for the reduced target
            ans += solve(nums, target - nums[i], dp);
        }

        // Store the calculated result in the memoization table
        dp[target] = ans;

        // Return the result for the current target
        return dp[target];
    }

    // Main function to calculate the number of combinations for a given target
    int combinationSum4(vector<int>& nums, int target) {
        // Initialize a memoization table with -1 (uncomputed state)
        vector<int> dp(target + 1, -1);

        // Call the recursive function to solve the problem with memoization
        return solve(nums, target, dp);
    }
};
```

### Source Code Explanation

#### **1. solve Function**

The `solve` function implements the recursive solution with memoization. Let's break it down:

```cpp
int solve(vector<int>& nums, int target, vector<int>& dp) {
```

- **Parameters**:
    - `nums`: The array containing the allowed numbers.
    - `target`: The current target value for which we need to find the number of combinations.
    - `dp`: The memoization array that stores the number of ways to form each possible target value.

```cpp
    if(target < 0) return 0;
```

- **Base case**: If the target becomes negative, it means we've chosen a combination that exceeds the target, so there are `0` ways to achieve this.

```cpp
    if(target == 0) return 1;
```

- **Base case**: If the target is `0`, we've found a valid combination (choosing nothing results in a sum of `0`), so we return `1`.

```cpp
    if(dp[target] != -1) return dp[target];
```

- **Memoization**: If the result for the current target has already been computed (stored in `dp[target]`), return it to avoid redundant calculations. Initially, all values in `dp` are set to `-1` to signify that no targets have been computed yet.

```cpp
    int ans = 0;
```

- **Variable Initialization**: This will hold the total number of combinations for the current target.

```cpp
    for(int i = 0; i < nums.size(); i++) {
```

- **Loop over the numbers**: Iterate through all the numbers in the `nums` array.

```cpp
        ans += solve(nums, target - nums[i], dp);
```

- **Recursive Call**: For each number in `nums`, reduce the target by the current number and recursively calculate the number of ways to achieve the reduced target (`target - nums[i]`).
- Add the result to `ans`.

```cpp
    dp[target] = ans;
```

- **Memoization**: Store the computed result for the current target in the `dp` array to avoid recalculating it.

```cpp
    return dp[target];
```

- **Return the computed result**: Finally, return the number of valid combinations for the current target.



#### **2. combinationSum4 Function**

```cpp
int combinationSum4(vector<int>& nums, int target) {
```

- **Function Signature**: This is the main function that calls `solve` to compute the number of combinations for a given target.

```cpp
    vector<int> dp(target + 1, -1);
```

- **Initialize Memoization Table**: Create a `dp` array of size `target + 1` and initialize all values to `-1` to signify that no targets have been computed yet.

```cpp
    return solve(nums, target, dp);
```

- **Call the Recursive Function**: Call `solve` with the initialized `dp` array to calculate the number of combinations for the given target.



### **Example Walkthrough**

Let’s take an example to see how the algorithm works step by step.

#### **Example Input:**
- `nums = [1, 2, 3]`
- `target = 4`

#### **Step-by-Step Execution:**

1. **Base Case:**
   - Initially, `target = 4`. The recursive function checks if the target is `0` (no), and not negative (no). The result is not memoized yet, so it proceeds to calculate the result.

2. **Recursive Call:**
   - For `target = 4`, we try each number from `nums`.
     - First, try `1`: 
       - Subproblem: `solve(nums, 4-1)` → `solve(nums, 3)`
     - Now, for `target = 3`, try each number from `nums` again.
       - First, try `1`: 
         - Subproblem: `solve(nums, 3-1)` → `solve(nums, 2)`
       - For `target = 2`, continue reducing using numbers from `nums`.
       - Finally, when we reach `target = 0`, return `1` because it is a valid combination.
     - Store the results in `dp` to avoid redundant calculations.

3. **Memoization:**
   - As we calculate each subproblem, we store the result in the `dp` array to make sure we don’t repeat the same calculations. For example, after calculating `solve(nums, 2)`, the result will be stored in `dp[2]`.

4. **Final Result:**
   - The result for `solve(nums, 4)` will eventually be computed by adding all valid combinations for each number in `nums`. For this input, the final result will be `7`, as there are 7 ways to form `4` using `nums = [1, 2, 3]`.



### **Time Complexity**

- **Time Complexity**: 
  - Each subproblem (`target`) is solved once, and each subproblem is visited once for each number in `nums`.
  - There are `target + 1` subproblems (from `0` to `target`), and for each subproblem, we loop through the `nums` array of size `n`.
  - Hence, the time complexity is `O(target * n)`, where `n` is the number of elements in `nums` and `target` is the given target value.

- **Space Complexity**:
  - We use a `dp` array of size `target + 1`, and the recursive function uses the call stack.
  - The space complexity is `O(target)` due to the `dp` array and the recursion stack (which can go as deep as `target`).

---

## Space Optimization (Not Possible)
In the **Bottom-Up Approach** with dynamic programming, we typically use an array `dp[]` where `dp[i]` represents the number of ways to make the sum `i` using the available numbers in `nums`. While it is often possible to reduce the space complexity by optimizing how we store intermediate results (like using a single array instead of a 2D array), space optimization isn't feasible in this particular problem for a few key reasons.

### **Explanation**

For the **Combination Sum IV** problem, each `dp[i]` value depends on all the previous values `dp[i - num]` where `num` is any number in the `nums` array. This dependency on all previous states makes it difficult to optimize the space used by the DP array.

### **Why Space Optimization Isn't Possible:**

1. **Dependencies on Multiple Previous States:**
   - At each step, `dp[currentTarget]` depends on values from earlier steps, specifically from `dp[currentTarget - num]` for each `num` in `nums`.
   - If we reduce the space to just a few variables, we lose access to the necessary past values of `dp[]` required to compute the current state.

2. **Example for Illustration:**

Let's take the example:

- **nums = [1, 2, 3]**
- **target = 4**

#### **dp Array:**
- We initialize the `dp[]` array:  
  `dp = [1, 0, 0, 0, 0]`  
  (Base case: `dp[0] = 1`, since there's one way to make sum `0`, which is to choose nothing.)

#### **Filling up the dp[] array:**

- **For target = 1**:  
  - We calculate `dp[1]` using the previous values (`dp[0]`), so `dp[1] = dp[0] = 1`.
  
- **For target = 2**:  
  - We calculate `dp[2]` using values from `dp[1]` and `dp[0]`, so `dp[2] = dp[1] + dp[0] = 1 + 1 = 2`.

- **For target = 3**:  
  - We calculate `dp[3]` using values from `dp[2]`, `dp[1]`, and `dp[0]`, so `dp[3] = dp[2] + dp[1] + dp[0] = 2 + 1 + 1 = 4`.

- **For target = 4**:  
  - We calculate `dp[4]` using values from `dp[3]`, `dp[2]`, `dp[1]`, and `dp[0]`, so `dp[4] = dp[3] + dp[2] + dp[1] + dp[0] = 4 + 2 + 1 + 1 = 7`.

At each step, the value of `dp[currentTarget]` depends on values that are several indices before it, requiring access to the entire `dp[]` array. **Thus, we cannot simply optimize space** by reducing the size of the array or keeping just a few variables since the computation at `dp[i]` requires information from `dp[0]` to `dp[i-1]`.


### **Why You Can't Use Just Constant Space:**
- In problems like this, where each `dp[i]` depends on the sum of previous states, **space optimization isn't possible** without losing the necessary information needed to calculate future states.
- **There’s no direct relationship between `dp[i]` and just the previous state** that would allow us to discard the entire array and rely on only a few variables (as you might do in problems with linear dependencies or ones that only depend on the previous state).

### **Conclusion:**
In summary, **space optimization isn't possible** in the **Combination Sum IV** problem because each value in the `dp[]` array depends on multiple previous states (not just one), which prevents us from reducing the space complexity to a constant amount without losing essential information for future calculations.
