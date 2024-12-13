<h1 align="center">Partition - Equal - Subset - Sum</h1>

## Problem Statement

**Problem URL (leetcode):** [Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/description/)

**Problem URL (GFG):** [Partition Equal Subset Sum](https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1)

![image](https://github.com/user-attachments/assets/c1a356bb-d27c-4bc2-aaad-05c4f8872fd6)

### Problem Explanation
You are given a non-empty array of integers `nums`. The task is to determine whether it's possible to partition this array into **two subsets** such that the sum of the elements in both subsets is **equal**.

### Key Points:

1. **Partitioning the Array**: 
   - You need to split the array `nums` into two groups or subsets, say `subset1` and `subset2`.
   - The sum of the elements in both subsets must be equal, meaning:
     - `sum(subset1) = sum(subset2)`

2. **Even or Odd Sum**:
   - First, you need to check if the total sum of all elements in `nums` is **even** or **odd**.
     - If the total sum is **odd**, it's **impossible** to split it into two equal subsets because half of an odd number is not an integer.
     - If the total sum is **even**, you can attempt to find a subset with a sum equal to `total_sum / 2`. If you can find such a subset, then the remaining elements will automatically form the other subset with the same sum.

### Example 1:

**Input**: `nums = [1, 5, 11, 5]`

1. **Total Sum**: 
   - The total sum of the array is `1 + 5 + 11 + 5 = 22`.
   - Since 22 is even, it's possible to split it into two equal subsets.

2. **Target**:
   - We want to find a subset with a sum of `22 / 2 = 11`.

3. **Possible Subsets**:
   - One valid way to partition this array is:
     - `subset1 = [1, 5, 5]` with sum `11`
     - `subset2 = [11]` with sum `11`

4. **Output**: `true` (The array can be partitioned into two subsets with equal sum).

### Example 2:

**Input**: `nums = [1, 2, 3, 5]`

1. **Total Sum**: 
   - The total sum of the array is `1 + 2 + 3 + 5 = 11`.
   - Since 11 is odd, it's **impossible** to partition this array into two subsets with equal sum.

2. **Output**: `false` (The array cannot be partitioned into two subsets with equal sum).

### Example 3:

**Input**: `nums = [2, 2, 3, 5]`

1. **Total Sum**: 
   - The total sum of the array is `2 + 2 + 3 + 5 = 12`.
   - Since 12 is even, we can try to find a subset with sum `12 / 2 = 6`.

2. **Possible Subsets**:
   - One valid way to partition this array is:
     - `subset1 = [2, 3]` with sum `6`
     - `subset2 = [2, 5]` with sum `6`

3. **Output**: `true` (The array can be partitioned into two subsets with equal sum).

### Conclusion:
The problem is about checking whether an array can be divided into two subsets such that both subsets have the same sum. If the total sum of the array is even, we check if there exists a subset whose sum is half of the total sum. If such a subset exists, the remaining elements will form the other subset, and both subsets will have equal sum. If the total sum is odd, it’s impossible to split the array into two subsets with equal sum.

---

## Recursive Approach (caused TLE)
#### **Problem Restatement:**
We need to determine if an array can be partitioned into two subsets such that the sum of the elements in each subset is equal.

#### **Recursive Approach:**
1. **Initial Thoughts**:
   - First, we compute the total sum of the array.
   - If the total sum is **odd**, it's impossible to divide the array into two equal sum subsets, so we return `false`.
   - If the total sum is **even**, we proceed to check if it's possible to find a subset with a sum equal to half of the total sum (because the remaining part will automatically form the other subset).

2. **Recursive Function**:
   The recursive function will try to find a subset of the array that sums to a target value (which is half of the total sum). Here's how:
   
   - **Base Case 1**: If the index exceeds the array size (i.e., we've looked at all elements), then there are no elements left to add, and we cannot form a valid subset, so return `0` (false).
   - **Base Case 2**: If the target becomes negative, it's not possible to reach the target sum, so return `0`.
   - **Base Case 3**: If the target becomes zero, it means we've successfully found a subset with the required sum, so return `1` (true).
   
   We then have two choices for each element:
   
   - **Option 1 (Include the current element)**: We subtract the current element from the target and recurse with the next element.
   - **Option 2 (Exclude the current element)**: We simply skip the current element and try to find a valid partition with the remaining elements, without changing the target.
   
   If either of these options leads to a valid partition, we return `1`. Otherwise, we return `0`.

#### **Example Walkthrough**:

Let's take the array `nums = [1, 5, 11, 5]` as an example.

1. **Calculate the total sum**:
   - `total = 1 + 5 + 11 + 5 = 22`.
   - Since `22` is even, we proceed to find a subset with sum `22 / 2 = 11`.

2. **Recursive Function**:
   Start by calling the recursive function with `index = 0`, `target = 11`, and `nums = [1, 5, 11, 5]`.
   
   **Step 1**: At index `0`, the current element is `1`. We have two options:
   - **Option 1 (Include `1`)**: Target becomes `11 - 1 = 10`. We move to the next index with target `10`.
   - **Option 2 (Exclude `1`)**: Target remains `11`. We move to the next index with target `11`.
   
   **Step 2**: Continue this process recursively for all elements until we reach the base case. In this example, we'll find that including the elements `1, 5, 5` will sum to `11`, which is the target.

3. **Return `true`**:
   Since we found a valid partition (e.g., `subset1 = [1, 5, 5]` and `subset2 = [11]`), the function returns `true`.

### Source Code
```cpp
class Solution {
public:
    // Recursive helper function to check if we can partition the array into two subsets
    int solve(vector<int>& nums, int index, int n, int target) {
        // Base case: If the index exceeds the array size, return 0 (no valid partition)
        if(index >= n) return 0;
        
        // If the target becomes negative, return 0 (not possible to partition)
        if(target < 0) return 0;
        
        // If the target becomes zero, it means we've found a valid partition (return 1)
        if(target == 0) return 1;

        // Option 1: Include the current element and try to partition with the reduced target
        int include = solve(nums, index+1, n, target - nums[index]);
        
        // Option 2: Exclude the current element and try to partition without changing the target
        int exclude = solve(nums, index+1, n, target - 0);

        // Return true if either including or excluding the current element leads to a valid partition
        return include or exclude;
    }

    // Main function to check if we can partition the array into two subsets with equal sum
    bool canPartition(vector<int>& nums) {
        int total = 0;

        // Calculate the total sum of the elements in the array
        for(auto & num : nums) total += num;

        // If the total sum is odd, we cannot partition it into two equal subsets
        if(total & 1) return 0;

        // Set the target as half of the total sum
        int target = total / 2;

        // Call the solve function to check if we can find a subset that sums to 'target'
        return solve(nums, 0, nums.size(), target);
    }
};
```

### Source Code Explanation
```cpp
class Solution {
public:
    // Recursive helper function to check if we can partition the array into two subsets
    int solve(vector<int>& nums, int index, int n, int target) {
```
- The `solve` function is a recursive helper that tries to find a subset with the given `target` sum, starting at the `index` position in the array `nums` with total size `n`.

```cpp
        // Base case: If the index exceeds the array size, return 0 (no valid partition)
        if(index >= n) return 0;
```
- If the `index` goes beyond the size of the array, it means we've checked all elements, and no valid subset can be formed, so return `0`.

```cpp
        // If the target becomes negative, return 0 (not possible to partition)
        if(target < 0) return 0;
```
- If the target becomes negative, it means we've gone over the target and can't partition the array, so return `0`.

```cpp
        // If the target becomes zero, it means we've found a valid partition (return 1)
        if(target == 0) return 1;
```
- If the target becomes zero, it means we've successfully found a subset that sums to the target. So, we return `1` to indicate success.

```cpp
        // Option 1: Include the current element and try to partition with the reduced target
        int include = solve(nums, index+1, n, target - nums[index]);
```
- If we include the current element (`nums[index]`), we subtract its value from the target and recursively call the function for the next index.

```cpp
        // Option 2: Exclude the current element and try to partition without changing the target
        int exclude = solve(nums, index+1, n, target - 0);
```
- If we exclude the current element, we simply call the function with the same target but move to the next index.

```cpp
        // Return true if either including or excluding the current element leads to a valid partition
        return include or exclude;
```
- If either including or excluding the current element leads to a valid partition, we return `1`. Otherwise, return `0`.

```cpp
    }

    // Main function to check if we can partition the array into two subsets with equal sum
    bool canPartition(vector<int>& nums) {
```
- The `canPartition` function is the main function that is called. It will calculate the total sum of the array and call the recursive helper function.

```cpp
        int total = 0;
        // Calculate the total sum of the elements in the array
        for(auto & num : nums) total += num;
```
- We calculate the sum of all elements in the array.

```cpp
        // If the total sum is odd, we cannot partition it into two equal subsets
        if(total & 1) return 0;
```
- If the total sum is odd (`total % 2 != 0`), it's impossible to partition it into two equal subsets, so we return `false`.

```cpp
        // Set the target as half of the total sum
        int target = total / 2;
```
- The target sum is set to half of the total sum, as we are trying to find a subset with this sum.

```cpp
        // Call the solve function to check if we can find a subset that sums to 'target'
        return solve(nums, 0, nums.size(), target);
    }
};
```
- Finally, we call the `solve` function starting from index `0` with the target sum and return the result.

#### **Example Output Explanation**:

**Input**: `nums = [1, 5, 11, 5]`

- The total sum is `22`, which is even. The target sum is `11`.
- The recursive function successfully finds a subset with sum `11` (e.g., `[1, 5, 5]`).
- Therefore, the function returns `true`, indicating that the array can be partitioned into two subsets with equal sum.

#### **Time and Space Complexity**:

- **Time Complexity**:  
   The time complexity is `O(2^n)` in the worst case due to the recursive calls, where `n` is the size of the array. This is because for each element, we have two choices: include it or exclude it, leading to `2^n` possible subsets.
  
- **Space Complexity**:  
   The space complexity is `O(n)` due to the recursive stack space. In the worst case, the maximum depth of the recursion will be `n`, where `n` is the size of the array.

---

## Top-Down Approach (DP)
#### **Problem Restatement:**
We are given a set of integers, and we need to determine if it is possible to partition this set into two subsets such that the sum of elements in each subset is equal.

#### **Top-Down Approach (with Memoization):**
In the Top-Down Approach, we use recursion along with memoization to avoid recomputing the same subproblems multiple times. The process is as follows:

1. **Check if the total sum is even**:
   - First, we calculate the total sum of the elements in the array. If the sum is **odd**, it's impossible to partition it into two equal subsets, and we return `false`.
   - If the sum is **even**, we set the target sum as half of the total sum (because we need to find one subset with this sum).

2. **Recursive Function**:
   We recursively check if we can find a subset whose sum equals the target. At each step, we have two choices:
   - **Include the current element**: Subtract the value of the current element from the target and recursively check if the remaining sum can be achieved with the remaining elements.
   - **Exclude the current element**: Move to the next element and try to achieve the same target with the remaining elements.

   **Memoization**: To avoid recalculating the same subproblems, we store the result for each index and target combination in a 2D `dp` table. If a subproblem has already been computed, we simply return the stored result.

#### **Recursive Function**:

```cpp
int solve(vector<int>& nums, int index, int n, int target, vector<vector<int>>& dp)
```
- This function tries to find a subset starting from `index` and tries to reach a subset sum equal to `target`. We use a `dp` table to store the results of subproblems.
- **Base Case 1**: If we've processed all elements (`index >= n`) and haven't reached the target sum, we return `0`.
- **Base Case 2**: If the `target` becomes negative, we return `0` because it's not possible to achieve a negative sum.
- **Base Case 3**: If the `target` becomes zero, it means we've found a subset whose sum equals the target, so we return `1`.
- **Memoization**: If we've already computed the result for a particular `index` and `target`, we directly return the stored result (`dp[index][target]`).

#### **Choice**:
- **Include the current element**: We reduce the `target` by the value of `nums[index]` and call the function recursively for the next index (`index + 1`).
- **Exclude the current element**: We keep the target the same and recursively call the function for the next index (`index + 1`).

If either choice leads to a valid subset, we return `1`, otherwise, we return `0`. The result is then stored in the `dp` table for future use.

#### **Example Walkthrough**:

Let's take the array `nums = [1, 5, 11, 5]` as an example.

1. **Calculate the total sum**:
   - `total = 1 + 5 + 11 + 5 = 22`.
   - Since `22` is even, we proceed with a target sum of `22 / 2 = 11`.

2. **Recursive Function Call**:
   - We call the `solve` function with the parameters: `index = 0`, `target = 11`, and `nums = [1, 5, 11, 5]`.
   - For each element at `index 0`, `index 1`, etc., we will try both including and excluding the element to check if we can form a subset that sums to `11`.

   **Step-by-Step Execution**:
   - Start at `index 0` with `target 11`. We have two choices:
     - **Include `1`**: New target becomes `11 - 1 = 10`. Recursively check for target `10` with remaining elements.
     - **Exclude `1`**: Keep target `11`, check if we can form `11` with the remaining elements.

   - Continue this recursively until either we find a valid subset (sum equals `11`), or we reach the base cases. In this example, the subset `[1, 5, 5]` sums to `11`, and the function returns `true`.

3. **Return `true`**:
   - Since a valid partition is found (e.g., `[1, 5, 5]` and `[11]`), the function returns `true`, indicating the array can be partitioned into two subsets with equal sum.

### Source Code
```cpp
class Solution {
public:
    // Recursive function with memoization to check if a subset sum equals the target
    int solve(vector<int>& nums, int index, int n, int target, vector<vector<int>> &dp) {
        // Base case: If we've processed all elements and haven't reached the target, return 0
        if(index >= n) return 0;
        
        // If the target becomes negative, return 0 (we can't have a negative sum)
        if(target < 0) return 0;
        
        // If the target becomes zero, it means we've found a subset whose sum equals the target
        if(target == 0) return 1;

        // Check if the result for this subproblem has already been computed
        if(dp[index][target] != -1) return dp[index][target];

        // Option 1: Include the current element (nums[index]) in the subset and reduce the target
        int include = solve(nums, index + 1, n, target - nums[index], dp);
        
        // Option 2: Exclude the current element and try the next index with the same target
        int exclude = solve(nums, index + 1, n, target, dp);

        // Memoize the result for the current index and target
        return dp[index][target] = include or exclude;  // Use logical OR to check if either option works
    }

    // Main function to check if we can partition the array into two subsets with equal sum
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;

        // Calculate the total sum of the elements in the array
        for(auto & num : nums) total += num;

        // If the total sum is odd, return false because it can't be partitioned into two equal subsets
        if(total & 1) return 0;

        // Set the target as half of the total sum
        int target = total / 2;

        // Create a memoization table to store results for subproblems
        // dp[i][j] will store whether it's possible to form sum 'j' using the first 'i' elements
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        // Call the recursive function to check if a subset sum equal to 'target' exists
        return solve(nums, 0, n, target, dp);
    }
};
```

### Source Code Explanation

```cpp
class Solution {
public:
    // Recursive function with memoization to check if a subset sum equals the target
    int solve(vector<int>& nums, int index, int n, int target, vector<vector<int>>& dp) {
```
- This is the recursive helper function that takes the `nums` array, the `index` of the current element being considered, the size of the array (`n`), the remaining `target` sum, and the `dp` table for memoization.

```cpp
        // Base case: If we've processed all elements and haven't reached the target, return 0
        if(index >= n) return 0;
```
- If we have processed all elements (`index >= n`) and still haven't found a subset with the required sum, return `0`.

```cpp
        // If the target becomes negative, return 0 (we can't have a negative sum)
        if(target < 0) return 0;
```
- If the target becomes negative, we return `0` because it's impossible to achieve a negative sum.

```cpp
        // If the target becomes zero, it means we've found a subset whose sum equals the target
        if(target == 0) return 1;
```
- If the target becomes zero, it means we've found a subset that sums up to the target, so we return `1`.

```cpp
        // Check if the result for this subproblem has already been computed
        if(dp[index][target] != -1) return dp[index][target];
```
- If we have already computed the result for this subproblem (`dp[index][target] != -1`), we return the stored result to avoid redundant calculations.

```cpp
        // Option 1: Include the current element (nums[index]) in the subset and reduce the target
        int include = solve(nums, index + 1, n, target - nums[index], dp);
```
- We include the current element (`nums[index]`), reduce the target by `nums[index]`, and recursively call the function for the next index (`index + 1`).

```cpp
        // Option 2: Exclude the current element and try the next index with the same target
        int exclude = solve(nums, index + 1, n, target, dp);
```
- We exclude the current element and recursively check if we can achieve the same target with the remaining elements.

```cpp
        // Memoize the result for the current index and target
        return dp[index][target] = include or exclude;  // Use logical OR to check if either option works
```
- Store the result in the `dp` table: `dp[index][target] = include or exclude`. If either option works, return `1`; otherwise, return `0`.

```cpp
    }

    // Main function to check if we can partition the array into two subsets with equal sum
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;

        // Calculate the total sum of the elements in the array
        for(auto & num : nums) total += num;
```
- The `canPartition` function calculates the total sum of the array. If the sum is odd, return `false` (we cannot partition it into two equal subsets).

```cpp
        // If the total sum is odd, return false because it can't be partitioned into two equal subsets
        if(total & 1) return 0;
```
- If the total sum is odd, return `false`.

```cpp
        // Set the target as half of the total sum
        int target = total / 2;

        // Create a memoization table to store results for subproblems
        // dp[i][j] will store whether it's possible to form sum 'j' using the first 'i' elements
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
```
- Set the target sum as half of the total sum and initialize a `dp` table to store the results of subproblems. The table is initialized with `-1` (indicating that a result has not yet been computed).

```cpp
        // Call the recursive function to check if a subset sum equal to 'target' exists
        return solve(nums, 0, n, target, dp);
    }
};
```
- Finally, we call the `solve` function with the initial index `0`, target `target`, and the memoization table `dp` and return the result.

#### **Example Output Explanation**:

**Input**: `nums = [1, 5, 11, 5]`

- The total sum is `22`, which is even. The target sum is `11`.
- The recursive function, with memoization, finds a valid subset (`[1, 5, 5]`) that sums to `11`.
- Therefore, the function returns `true`, indicating that the array can be partitioned into two subsets with equal sum.

#### **Time and Space Complexity**:

- **Time Complexity**:  
  The time complexity is `O(n * target)` where `n` is the number of elements in the array and `target` is the target sum (half of the total sum).
  This is because we explore all possible indices (`n`) and all possible target values (from `0` to `target`).

- **Space Complexity**:  
  The space complexity is `O(n * target)` due to the memoization table (`dp`).

---

## Bottom-Up Approach (DP)
The Bottom-Up approach solves the subset-sum problem using a **dynamic programming (DP)** technique. In this approach, we build the solution iteratively by starting from the base case (small subproblems) and gradually working our way up to the target sum.

#### **Problem Restatement**:
Given an array `nums`, the goal is to check if it is possible to partition the array into two subsets with equal sum. This can be reduced to finding a subset that sums to `total / 2`, where `total` is the sum of all elements in the array.

#### **Steps to Solve Using the Bottom-Up Approach**:

1. **Calculate the Total Sum**:
   - First, calculate the sum of all elements in the array.
   - If the total sum is **odd**, it is impossible to divide the array into two equal subsets, so we immediately return `false`.

2. **Set the Target**:
   - If the total sum is **even**, we set the `target` as `total / 2`.

3. **Dynamic Programming Table (`dp`)**:
   - We use a 2D DP table, where `dp[i][j]` indicates whether it's possible to form a subset with sum `j` using the first `i` elements of the array.
   - The dimensions of the DP table are `(n+1) x (target+1)`, where `n` is the number of elements in `nums` and `target` is the target sum.

4. **Base Case**:
   - A sum of `0` can always be formed using the empty subset. Therefore, we set `dp[i][0] = 1` for all `i`, indicating that it’s always possible to form a subset with sum `0`.

5. **Filling the DP Table**:
   - For each element in the array, we iterate through all possible target sums from `1` to `target`.
   - For each element `nums[i]`, we check if the current target sum `t` can be formed:
     - **Include the element**: If `t - nums[i] >= 0`, we check if we can form a sum of `t - nums[i]` using the previous elements. This value is stored in `dp[i-1][t - nums[i]]`.
     - **Exclude the element**: We check if the current sum `t` can be formed without including the current element. This value is stored in `dp[i-1][t]`.

6. **Final Result**:
   - The value of `dp[n][target]` (the last cell in the DP table) tells us whether it is possible to form a subset with sum equal to `target`. If it's `1`, we return `true`; otherwise, `false`.
   - 
### Source Code
```cpp
class Solution {
public:
    // Function to check if a subset sum equal to 'target' exists using dynamic programming
    int solve(vector<int>& nums, int n, int target) {
        // dp[i][j] will store whether it's possible to form sum 'j' using the first 'i' elements
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));

        // Base case: sum of 0 can always be formed (empty subset)
        for(int i = 0; i <= n; i++) dp[i][0] = 1;

        // Fill the dp table in bottom-up manner
        // Iterate over all indices of nums in reverse (from n-1 to 0)
        for(int index = n-1; index >= 0; index--) {
            // Iterate over all possible target sums from 1 to the desired target sum
            for(int t = 1; t <= target; t++) {
                int include = 0;
                // If the current number can be included (i.e., target - nums[index] >= 0)
                if(t - nums[index] >= 0) include = dp[index+1][t - nums[index]];
                
                // Exclude the current element (i.e., use the result from the next index with the same target)
                int exclude = dp[index+1][t];

                // The result for dp[index][t] is the logical OR of including or excluding the element
                dp[index][t] = include or exclude;
            }
        }

        // The final result is stored at dp[0][target], which tells if the target sum can be achieved
        return dp[0][target];
    }

    // Main function to check if we can partition the array into two subsets with equal sum
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;

        // Calculate the total sum of the elements in the array
        for(auto & num : nums) total += num;

        // If the total sum is odd, it can't be partitioned into two equal subsets
        if(total & 1) return 0;

        // Set the target as half of the total sum
        int target = total / 2;

        // Call the solve function to check if a subset with sum equal to 'target' exists
        return solve(nums, n, target);
    }
};
```
### Source Code Explanation

#### **`solve` Function**:
1. **Initialize the DP Table**:
   ```cpp
   vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
   ```
   - We initialize a 2D DP table where each cell `dp[i][j]` will store whether it is possible to form a sum `j` using the first `i` elements.

2. **Base Case Initialization**:
   ```cpp
   for(int i = 0; i <= n; i++) dp[i][0] = 1;
   ```
   - A sum of `0` can always be formed by using an empty subset, so we initialize all `dp[i][0] = 1`.

3. **Iterating through the Array**:
   ```cpp
   for(int index = 0; index < n; index++) {
       for(int t = 1; t <= target; t++) {
   ```
   - We iterate over all elements in the array (from `index = 0` to `index = n-1`) and check all possible target sums (`t = 1` to `target`).

4. **Include/Exclude the Current Element**:
   ```cpp
   int include = 0;
   if(t - nums[index] >= 0) include = dp[index][t - nums[index]];

   int exclude = dp[index][t];
   ```
   - **Include**: If we can include the current element (`nums[index]`), we check if a subset sum `t - nums[index]` can be formed using previous elements.
   - **Exclude**: If we exclude the current element, we check if a subset sum `t` can be formed using the previous elements.

5. **Update the DP Table**:
   ```cpp
   dp[index+1][t] = include or exclude;
   ```
   - The result for `dp[index+1][t]` is the logical OR of including or excluding the current element.

6. **Return the Result**:
   ```cpp
   return dp[n][target];
   ```
   - Finally, `dp[n][target]` tells us if it's possible to form a subset with sum `target`.

#### **`canPartition` Function**:
1. **Calculate the Total Sum**:
   ```cpp
   int total = 0;
   for(auto & num : nums) total += num;
   ```
   - Calculate the sum of all elements in `nums`.

2. **Check for Even Sum**:
   ```cpp
   if(total & 1) return 0;
   ```
   - If the total sum is odd, return `false` because it's impossible to divide it into two equal subsets.

3. **Set the Target**:
   ```cpp
   int target = total / 2;
   ```
   - Set the target sum to half of the total sum.

4. **Call the DP Function**:
   ```cpp
   return solve(nums, n, target);
   ```
   - Call the `solve` function to check if a subset sum equal to `target` exists.



### **Example Walkthrough**:

**Input**: `nums = [1, 5, 11, 5]`

1. **Calculate the Total Sum**:
   - `total = 1 + 5 + 11 + 5 = 22`. Since the sum is even, we proceed.

2. **Set the Target**:
   - The target sum is `22 / 2 = 11`.

3. **Dynamic Programming Table**:
   - We initialize the DP table and start filling it iteratively.
   - For each element, we check all possible target sums from `1` to `11`.

4. **Result**:
   - After filling the DP table, we check `dp[n][target]` (i.e., `dp[4][11]`). If it's `1`, return `true`; otherwise, `false`.
   - In this case, a valid subset (`[1, 5, 5]`) sums to `11`, so the result is `true`.



### **Time and Space Complexity**:

- **Time Complexity**:  
  The time complexity is `O(n * target)`, where `n` is the number of elements in `nums` and `target` is the target sum (half of the total sum).
  
- **Space Complexity**:  
  The space complexity is `O(n * target)` due to the DP table used to store the results of subproblems.

---

## Space Optimization Approach (DP)
In dynamic programming problems, especially those involving subset sums, it is common to use a table to store the results of subproblems. Typically, a 2D table is used where each cell `dp[i][j]` stores whether it's possible to achieve a sum `j` using the first `i` elements of the array.

However, we can optimize the space by recognizing that, for a given index `i`, we only need information from the previous index `i-1`. Therefore, instead of keeping an entire 2D table, we can maintain just two 1D arrays: one for the current index and one for the previous index. This reduces the space complexity significantly.

#### Example to Understand the Space Optimization:
Consider the problem of determining if a subset of an array sums up to a target value. Let's walk through an example.

**Example:**
- **Array:** `nums = [1, 2, 3, 4]`
- **Target:** `6`

We want to know if there is a subset of `nums` that sums up to `6`. We'll use dynamic programming to build a solution.

### Step-by-Step Explanation:

1. **Initialization (Base Case):**
   - We start by initializing two arrays `curr` and `next` of size `target + 1` (7 in this case, for sums from `0` to `6`). Both arrays are initially filled with zeros.
   - We know that a sum of `0` is always achievable with an empty subset. So, we set `curr[0] = 1` and `next[0] = 1`.

2. **Transition for Each Element:**
   - For each element in the array, we attempt to update the `curr` array based on the previous element's results stored in `next`.
   - We iterate over the target values from `1` to `6`. For each value `t`, we check two possibilities:
     - **Include the current element:** If `t - nums[index] >= 0`, we can include the current element in the subset. The value is taken from `next[t - nums[index]]`.
     - **Exclude the current element:** We also check the result from `next[t]`, which is the result of the previous index without including the current element.

3. **Switching Arrays:**
   - Once we process an index, we switch the `curr` array to `next` so that we can use the updated values for the next iteration.

4. **Final Result:**
   - The final result is stored in `next[target]`, which tells us whether it's possible to achieve the target sum.

#### Example Walkthrough:

- **First iteration (`nums[0] = 1`):**
   - We initialize `curr = [1, 0, 0, 0, 0, 0, 0]` and `next = [1, 0, 0, 0, 0, 0, 0]`.
   - We iterate over each target from `1` to `6`:
     - For `t = 1`: We can include `1` (since `t - 1 >= 0`), so `curr[1] = 1`.
     - For `t = 2, 3, 4, 5, 6`: We can't form these sums, so `curr[t] = 0`.
   - After the iteration, we update `next = curr`.

- **Second iteration (`nums[1] = 2`):**
   - Now `nums[1] = 2`. We process similarly.
   - We update `curr` based on whether we include or exclude `2` from the subset.
   - After this, we update `next = curr`.

- **Continue for all elements in `nums`:**
   - Repeat the above steps for all elements in the array, adjusting `curr` and `next`.

### Source Code
```cpp
class Solution {
public:
    // Function to check if a subset sum equal to 'target' exists using dynamic programming with space optimization
    int solve(vector<int>& nums, int n, int target) {
        // Arrays to store the current and next row of the dp table
        vector<int> curr(target+1, 0);   // To store the result for the current index
        vector<int> next(target+1, 0);   // To store the result for the next index (used in the transition)

        // Base case: sum of 0 can always be formed (empty subset)
        curr[0] = 1;
        next[0] = 1;

        // Iterate over all indices of nums in reverse (from n-1 to 0)
        for(int index = n-1; index >= 0; index--) {
            // Iterate over all possible target sums from 1 to the desired target sum
            for(int t = 1; t <= target; t++) {
                int include = 0;
                // If the current number can be included (i.e., target - nums[index] >= 0)
                if(t - nums[index] >= 0) include = next[t - nums[index]];

                // Exclude the current element (i.e., use the result from the next index with the same target)
                int exclude = next[t];

                // The result for curr[t] is the logical OR of including or excluding the element
                curr[t] = include or exclude;
            }

            // Move the current row to the next row for the next iteration
            next = curr;
        }

        // The final result is stored in next[target], which tells if the target sum can be achieved
        return next[target];
    }

    // Main function to check if we can partition the array into two subsets with equal sum
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;

        // Calculate the total sum of the elements in the array
        for(auto & num : nums) total += num;

        // If the total sum is odd, it can't be partitioned into two equal subsets
        if(total & 1) return 0;

        // Set the target as half of the total sum
        int target = total / 2;

        // Call the solve function to check if a subset with sum equal to 'target' exists
        return solve(nums, n, target);
    }
};
```

### Source Code Explanation

#### 1. Class Declaration
```cpp
class Solution {
```
- **Explanation:** This is the start of the class `Solution` which contains all the logic for solving the problem of partitioning an array into two subsets with equal sum.



#### 2-3. `solve` Function Definition
```cpp
int solve(vector<int>& nums, int n, int target) {
```
- **Explanation:** 
   - This function attempts to determine if a subset of `nums` exists that adds up to a given `target`.
   - `nums`: The input array containing integers.
   - `n`: The number of elements in `nums`.
   - `target`: The sum we want to achieve with some subset of `nums`.



#### 4-5. Initialize the DP Arrays
```cpp
vector<int> curr(target + 1, 0);   // To store the result for the current index
vector<int> next(target + 1, 0);   // To store the result for the next index (used in the transition)
```
- **Explanation:**
   - `curr` and `next` are two 1D arrays of size `target + 1`. They store whether a specific sum can be achieved using the numbers considered so far.
   - `curr` stores the results for the current index of `nums`, while `next` stores results for the next index.
   - Initially, all values are set to `0`, meaning no sums are possible.



#### 6-7. Base Case Initialization
```cpp
curr[0] = 1;  // An empty subset always gives a sum of 0
next[0] = 1;  // Similarly for the next row
```
- **Explanation:** 
   - **Base Case:** The sum of `0` can always be achieved by using the empty subset.
   - Both `curr[0]` and `next[0]` are set to `1` because it's always true that a sum of `0` can be formed (by taking no elements from the array).



#### 8-9. Iteration Over All Elements in Reverse
```cpp
for(int index = n - 1; index >= 0; index--) {
```
- **Explanation:**
   - The outer loop starts from the last index of `nums` (`n - 1`) and goes backward to `0`.
   - This backward iteration ensures that we use the results of the previous index (stored in `next`) when updating the current index (`curr`).



#### 10-11. Iterating Over All Possible Target Sums
```cpp
for(int t = 1; t <= target; t++) {
```
- **Explanation:**
   - This loop iterates over all possible sums `t` from `1` to `target`.
   - For each target `t`, we need to decide whether to include the current element (`nums[index]`) in the subset or not.



#### 12. Determine Whether to Include the Current Element
```cpp
int include = 0;
if(t - nums[index] >= 0) include = next[t - nums[index]];
```
- **Explanation:**
   - `include`: This variable will hold the result if we **include** `nums[index]` in the subset.
   - If `t - nums[index] >= 0`, it means that the current element `nums[index]` can potentially contribute to the sum `t`. 
   - In that case, we check if the sum `t - nums[index]` is achievable using the previous elements (stored in `next[t - nums[index]]`).



#### 13. Exclude the Current Element
```cpp
int exclude = next[t];
```
- **Explanation:**
   - `exclude`: This variable holds the result if we **exclude** `nums[index]` from the subset.
   - The value of `next[t]` indicates whether the sum `t` was achievable with the previous elements (before considering `nums[index]`).



#### 14. Update the Current Array with OR Logic
```cpp
curr[t] = include or exclude;
```
- **Explanation:**
   - This line determines whether sum `t` can be achieved using the current element (`nums[index]`).
   - The result for `curr[t]` is the logical OR of `include` and `exclude`:
     - If either including or excluding the current element results in a valid subset sum, `curr[t]` is set to `1` (true).
     - Otherwise, `curr[t]` remains `0`.



#### 15. Move `curr` to `next`
```cpp
next = curr;
```
- **Explanation:**
   - After processing all sums for the current index, we update `next` to be the same as `curr`. This allows us to use `next` in the next iteration.
   - The `curr` array is overwritten in the next iteration, so we need to store the current results in `next`.



#### 16. Return the Final Result
```cpp
return next[target];
```
- **Explanation:**
   - The final result is stored in `next[target]`, which tells us whether it's possible to achieve the target sum using the elements of `nums`.
   - If `next[target] == 1`, it means the target sum can be formed. Otherwise, it can't.



#### 17-18. Main Function (`canPartition`)
```cpp
bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int total = 0;
    for(auto & num : nums) total += num;
    if(total & 1) return 0;
    int target = total / 2;
    return solve(nums, n, target);
}
```
- **Explanation:**
   - **Step 1:** Calculate the total sum of elements in the array `nums`.
   - **Step 2:** If the total sum is **odd**, it's not possible to partition the array into two subsets with equal sum, so return `false` (`total & 1` checks if the sum is odd).
   - **Step 3:** Set the target as half of the total sum (`total / 2`).
   - **Step 4:** Call the `solve` function to check if there's a subset of `nums` that sums to `target`. If yes, return `true`; otherwise, return `false`.



### Example Output

**Example 1:**
```cpp
nums = [1, 5, 11, 5]
```

- **Total sum:** `1 + 5 + 11 + 5 = 22`, which is even.
- **Target sum:** `22 / 2 = 11`.
- The `solve` function will check if it's possible to form a subset that sums to `11`.
- The result will be `true` because a subset `{5, 5, 1}` sums to `11`.

**Example 2:**
```cpp
nums = [1, 2, 3, 5]
```

- **Total sum:** `1 + 2 + 3 + 5 = 11`, which is odd.
- Since the total sum is odd, the function will immediately return `false` without further computation.



### Time and Space Complexities

#### Time Complexity:
- **Time Complexity:** `O(n * target)`, where `n` is the number of elements in the array `nums`, and `target` is the sum we're checking for.
  - The outer loop iterates over all elements (`n` times).
  - The inner loop iterates over all possible sums (`target` times).
  
#### Space Complexity:
- **Space Complexity:** `O(target)`, because we only maintain two 1D arrays (`curr` and `next`) of size `target + 1` to store the results of subproblems.
  - The space is reduced compared to the full 2D DP approach (`O(n * target)`) due to space optimization.

This makes the approach space-efficient while maintaining the same time complexity.
