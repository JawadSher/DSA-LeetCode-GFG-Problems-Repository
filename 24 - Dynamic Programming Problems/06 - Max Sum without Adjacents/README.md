<h1 align="center">Max - Sum - Without - Adjacents</h1>

## Problem Statement

**Problem URL :** [Max Sum Without Adjacents](https://www.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1)

![image](https://github.com/user-attachments/assets/d31724dc-3fc8-4c0b-935e-8645cc6a7490)

### Problem Explanation
The problem **"Max Sum Without Adjacent Elements"** asks you to find the maximum sum of elements in an array, **where no two elements that are adjacent in the array are selected together**. In other words, if you select an element, you cannot select its immediate neighbors.

- You are given an array of integers.
- You need to select some elements such that the sum is maximized, but **you cannot select two adjacent elements**.
- Your task is to return the maximum sum possible under this constraint.

### Key Insights:

1. **Adjacent elements cannot be chosen together**: This means that after selecting an element, you must skip at least one element before you can select another.
   
2. **Dynamic Decision Making**: For each element, you have two choices:
   - **Include the element**: If you include the element, you must exclude the immediate previous element.
   - **Exclude the element**: If you exclude the element, you can safely take the maximum sum up to the previous element.

### Step-by-Step Explanation with Examples:

#### Example 1: `[3, 2, 5, 10, 7]`

1. **Start with the first element**:
   - At index `0`, the only choice is to include the first element (since there are no elements before it). So, we take the sum as `3`.
   - Result so far: `3`

2. **Move to the next element**:
   - At index `1`, we have two choices:
     - Include `2` (which means we can't include `3`), so the sum would be `2`.
     - Exclude `2` and keep `3` (sum would be `3`).
   - We choose the maximum of these two options, which is `3`. Hence, we don't select `2`.
   - Result so far: `3`

3. **Move to the next element**:
   - At index `2`, we can:
     - Include `5` (we must skip the element at index `1`, so we add `5` to the sum at index `0` which is `3`, resulting in `3 + 5 = 8`).
     - Exclude `5` and keep the sum from index `1` (which is `3`).
   - We choose the maximum sum, which is `8` (`3 + 5`).
   - Result so far: `8`

4. **Move to the next element**:
   - At index `3`, we can:
     - Include `10` (we must exclude the element at index `2`, so we add `10` to the sum from index `1` which is `3`, resulting in `3 + 10 = 13`).
     - Exclude `10` and keep the sum from index `2` (which is `8`).
   - We choose the maximum sum, which is `13` (`3 + 10`).
   - Result so far: `13`

5. **Move to the next element**:
   - At index `4`, we can:
     - Include `7` (we must exclude the element at index `3`, so we add `7` to the sum from index `2` which is `8`, resulting in `8 + 7 = 15`).
     - Exclude `7` and keep the sum from index `3` (which is `13`).
   - We choose the maximum sum, which is `15` (`8 + 7`).
   - Result: `15`

**Final Result**: The maximum sum without selecting adjacent elements is `15`.

#### Example 2: `[3, 10, 3, 1, 2]`

1. **Start with the first element**:
   - At index `0`, the only choice is to include `3`.
   - Result: `3`

2. **Move to the next element**:
   - At index `1`, we can:
     - Include `10` (sum becomes `3 + 10 = 13`).
     - Exclude `10` and keep `3` (sum remains `3`).
   - We choose the maximum sum, which is `13`.
   - Result: `13`

3. **Move to the next element**:
   - At index `2`, we can:
     - Include `3` (sum becomes `13 + 3 = 16`).
     - Exclude `3` and keep the sum from index `1` which is `13`.
   - We choose the maximum sum, which is `16`.
   - Result: `16`

4. **Move to the next element**:
   - At index `3`, we can:
     - Include `1` (sum becomes `16 + 1 = 17`).
     - Exclude `1` and keep the sum from index `2` which is `16`.
   - We choose the maximum sum, which is `17`.
   - Result: `17`

5. **Move to the next element**:
   - At index `4`, we can:
     - Include `2` (sum becomes `17 + 2 = 19`).
     - Exclude `2` and keep the sum from index `3` which is `17`.
   - We choose the maximum sum, which is `19`.
   - Result: `19`

**Final Result**: The maximum sum without selecting adjacent elements is `19`.

### Key Points to Remember:

1. **Two Choices at Each Step**: For each element, you either:
   - **Include it** (skip the previous element).
   - **Exclude it** (keep the maximum sum up to the previous element).
   
2. **Decision at Every Step**: The decision to include or exclude an element depends on the maximum sum obtained from previous calculations. We keep track of the maximum possible sum as we iterate over the array.

3. **Optimal Substructure**: The problem can be solved using dynamic programming because the solution to the current subproblem depends on the solution to smaller subproblems (i.e., maximum sum up to the previous or earlier elements).

4. **Greedy Choice May Fail**: Simply choosing the largest number at each step will not guarantee the correct solution because adjacent numbers cannot be chosen. Therefore, a greedy approach does not work.

By using dynamic programming (either top-down with recursion or bottom-up with iteration), we can compute the maximum sum efficiently while ensuring that no adjacent elements are selected.

---

## Recursive Approach (caused LTE):
The problem is asking to find the maximum sum of elements from an array such that no two adjacent elements are included in the sum. We need to approach this problem recursively by exploring two options for each element: including or excluding it.

### Steps:

1. **Base Cases**:
   - If the index exceeds the bounds of the array, return `0` since there are no more elements to pick.
   - If the index points to the last element, return its value because it's the only option.
   
2. **Recursive Cases**:
   - **Include the current element**: Skip the next element and move two indices ahead.
   - **Exclude the current element**: Move one index ahead without adding the current element to the sum.

3. **Return the maximum sum**: At each index, we compare the two options (including or excluding the element) and return the maximum value.


### **Approach 1: Left to Right Recursive Approach**
#### Source Code
```cpp
// Approach 1 : Left to Right Approach
class Solution {
  public:
    // Recursive function to solve the problem
    int solve(vector<int>& arr, int i, int n){
        // Base case: If the index exceeds the size of the array, return 0 (no more elements to pick)
        if(i > n) return 0;

        // Base case: If we reach the last element, return its value
        if(i == n) return arr[i];
        
        // Option 1: Include the current element arr[i] and move two steps forward (i+2)
        int include = solve(arr, i+2, n) + arr[i];
        
        // Option 2: Exclude the current element arr[i] and move one step forward (i+1)
        int exclude = solve(arr, i+1, n) + 0; // Adding 0 doesn't affect the result
        
        // Return the maximum sum between including and excluding the current element
        return max(include, exclude);
    }
    
    // Function to find the maximum sum without adjacent elements
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();  // Get the size of the array
        
        // Start the recursive process from index 0
        int sum = solve(arr, 0, n-1);
        
        return sum;  // Return the maximum sum obtained
    }
};
```

#### Code Explanation:

1. **`solve()` function**:
   - **Parameters**:
     - `arr`: The input array containing the elements.
     - `i`: The current index we are considering in the array.
     - `n`: The last index of the array.
   - **Base Case 1** (`if(i > n) return 0`): If the index `i` exceeds the bounds of the array, there are no elements to pick, so return `0`.
   - **Base Case 2** (`if(i == n) return arr[i]`): If `i` points to the last element, return its value since it’s the only option.
   
2. **Recursive Steps**:
   - **Include the current element**: If we include the current element `arr[i]`, the next element we can consider is `arr[i+2]`. So, the recursive call becomes `solve(arr, i+2, n) + arr[i]`.
   - **Exclude the current element**: If we exclude the current element `arr[i]`, the next element we can consider is `arr[i+1]`. So, the recursive call becomes `solve(arr, i+1, n)`.
   
3. **Return the maximum sum**: The function returns the maximum of the two choices — whether to include or exclude the current element.



#### **Approach 2: Right to Left Recursive Approach**
#### Source Code
```cpp
// Approach 2 : Right to Left Approach
class Solution {
  public:
    // Recursive function to solve the problem
    int solve(vector<int>& arr, int n){
        // Base case: If n is negative, we return 0 (no more elements to pick)
        if(n < 0) return 0;

        // Base case: If n is 0, return the first element
        if(n == 0) return arr[0];
        
        // Option 1: Include the current element arr[n] and move two steps back (n-2)
        int include = solve(arr, n-2) + arr[n];
        
        // Option 2: Exclude the current element arr[n] and move one step back (n-1)
        int exclude = solve(arr, n-1) + 0; // Adding 0 doesn't affect the result
        
        // Return the maximum sum between including and excluding the current element
        return max(include, exclude);
    }
    
    // Function to find the maximum sum without adjacent elements
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();  // Get the size of the array
        
        // Start the recursive process from the last index (n-1)
        int sum = solve(arr, n-1);
        
        return sum;  // Return the maximum sum obtained
    }
};
```

#### Code Explanation:

1. **`solve()` function**:
   - **Parameters**:
     - `arr`: The input array containing the elements.
     - `n`: The current index we are considering, starting from the last element (`n-1`).
   - **Base Case 1** (`if(n < 0) return 0`): If `n` is negative, return `0` because there are no elements to pick.
   - **Base Case 2** (`if(n == 0) return arr[0]`): If `n` is `0`, return the first element, as it’s the only available element.
   
2. **Recursive Steps**:
   - **Include the current element**: If we include `arr[n]`, the next element we can consider is `arr[n-2]`. So, the recursive call becomes `solve(arr, n-2) + arr[n]`.
   - **Exclude the current element**: If we exclude `arr[n]`, the next element we can consider is `arr[n-1]`. So, the recursive call becomes `solve(arr, n-1)`.
   
3. **Return the maximum sum**: The function returns the maximum of the two options — including or excluding the current element.

### Example Walkthrough:

For the array **[3, 2, 5, 10, 7]**:

#### **Approach 1: Left to Right**

1. Start at index `0`:
   - **Include `3`**: Call `solve(arr, 2)` and add `3`.
   - **Exclude `3`**: Call `solve(arr, 1)`.

2. At index `2` (recursive call from above):
   - **Include `5`**: Call `solve(arr, 4)` and add `5`.
   - **Exclude `5`**: Call `solve(arr, 3)`.

3. Continue recursively comparing options until reaching the base cases.

- **Final Answer**: The maximum sum is `15` (3 + 10 + 7).

#### **Approach 2: Right to Left**

1. Start at index `4` (the last element):
   - **Include `7`**: Call `solve(arr, 2)` and add `7`.
   - **Exclude `7`**: Call `solve(arr, 3)`.

2. At index `2` (recursive call from above):
   - **Include `5`**: Call `solve(arr, 0)` and add `5`.
   - **Exclude `5`**: Call `solve(arr, 1)`.

3. Continue recursively comparing options until reaching the base cases.

- **Final Answer**: The maximum sum is `15` (3 + 10 + 7).


### Time and Space Complexity:

#### **Time Complexity**:
- **O(2^n)**: The recursion explores two branches at each step, leading to an exponential number of recursive calls, where `n` is the size of the array.

#### **Space Complexity**:
- **O(n)**: Due to the recursion depth, the maximum space used by the recursion stack will be proportional to the size of the array (`n`). Thus, the space complexity is `O(n)`.

This approach can be optimized using **Memoization** (Top-Down Dynamic Programming) or **Tabulation** (Bottom-Up Dynamic Programming).

---

## To-Down Approach (DP)
The goal is to find the maximum sum of non-adjacent elements from a given array. The recursive approach that we previously discussed has overlapping subproblems, meaning that we are recalculating the same subproblems multiple times. To avoid this, we use memoization to store the results of previously computed subproblems, which improves the efficiency of the solution.

### Steps:

1. **Base Cases**:
   - If the index `i` exceeds the bounds of the array (`i >= arr.size()`), return `0` because there are no more elements to pick.
   
2. **Memoization Check**:
   - Before solving a subproblem, check if the result is already stored in the `dp` array. If so, return that value to avoid redundant computations.

3. **Recursive Cases**:
   - **Include the current element**: If we include the element at index `i`, the next element we can consider is `arr[i+2]`, as adjacent elements cannot be selected.
   - **Exclude the current element**: If we exclude the element at index `i`, the next element we can consider is `arr[i+1]`.
   
4. **Return the Maximum Sum**:
   - For each index, calculate the maximum sum by including or excluding the element and store it in the memoization array (`dp`). Finally, return the result stored in `dp[i]`.

### Source Code
```cpp
// User function template for C++
class Solution {
  public:
    // Recursive function to solve the problem with memoization
    int solve(vector<int>& arr, int i, int n, vector<int>& dp){
        // Base case: If the index i is out of bounds, return 0 (no more elements to pick)
        if(i >= arr.size()) return 0;
        
        // If the result for the current index i is already computed, return it from the memoization table
        if(dp[i] != -1) return dp[i];
        
        // Option 1: Include the current element arr[i] in the sum, 
        // then move 2 steps forward (i+2) to ensure no adjacent elements are selected
        int include = solve(arr, i+2, n, dp) + arr[i];
        
        // Option 2: Exclude the current element arr[i] from the sum, 
        // then move 1 step forward (i+1) to check the next element
        int exclude = solve(arr, i+1, n, dp) + 0; // Adding 0 doesn't affect the result
        
        // Store the maximum sum of including or excluding the current element in the dp array
        dp[i] = max(include, exclude);
        
        // Return the computed result for the current index i
        return dp[i];
    }

    // Function to find the maximum sum without adjacent elements
    int findMaxSum(vector<int>& arr) {
        int n = arr.size(); // Get the size of the input array
        
        // Initialize the memoization array dp with -1 to indicate uncomputed results
        // dp[i] will store the maximum sum starting from index i
        vector<int> dp(n+1, -1);
        
        // Start the recursive process from index 0
        int sum = solve(arr, 0, n-1, dp);
        
        // Return the maximum sum obtained
        return sum;
    }
};
```

### Code Explanation:

1. **`solve()` function**:
   - **Parameters**:
     - `arr`: The input array containing the elements.
     - `i`: The current index we are considering in the array.
     - `n`: The size of the array (used in this version to track the bounds of the array).
     - `dp`: The memoization array to store results of previously computed subproblems.
   - **Base Case 1** (`if(i >= arr.size()) return 0`): If `i` exceeds the bounds of the array, return `0` since there are no more elements to pick.
   
2. **Memoization Check** (`if(dp[i] != -1) return dp[i]`):
   - Before solving a subproblem, check if the result is already stored in `dp[i]`. If it is, return the stored value to avoid redundant computations.

3. **Recursive Steps**:
   - **Include the current element**: If we include `arr[i]`, we move two indices ahead to ensure no adjacent elements are selected. Thus, the recursive call becomes `solve(arr, i+2, n, dp) + arr[i]`.
   - **Exclude the current element**: If we exclude `arr[i]`, we move one index ahead. The recursive call becomes `solve(arr, i+1, n, dp)`.

4. **Store the result in `dp[i]`**: After calculating both options (including or excluding), store the maximum of the two options in `dp[i]`.

5. **Return the computed result**: Return the result stored in `dp[i]`.



### Example Walkthrough:

For the array **[3, 2, 5, 10, 7]**:

1. **Start the process from index 0**:
   - Check `dp[0]`. If it is `-1`, compute the result by considering both options (include and exclude).
   
2. **At index 0**:
   - **Include 3**: Move to index 2. Add `3`.
   - **Exclude 3**: Move to index 1. Don't add anything.

3. **At index 2**:
   - **Include 5**: Move to index 4. Add `5`.
   - **Exclude 5**: Move to index 3. Don't add anything.

4. Continue recursively comparing the two options until we reach the base case (`i >= arr.size()`).

- **Final Answer**: The maximum sum is `15` (3 + 10 + 7).


### Time and Space Complexity:

#### **Time Complexity**:
- **O(n)**: Since we use memoization, each subproblem is solved only once, and the result is stored in `dp[i]` for each index `i`. Therefore, the time complexity is linear in terms of the size of the array `n`.

#### **Space Complexity**:
- **O(n)**: We use a `dp` array of size `n` to store the results of the subproblems. Additionally, the recursion stack uses space proportional to the depth of the recursion, which can also be at most `n`. Therefore, the space complexity is `O(n)`.


### Summary:

This approach is a more efficient version of the original recursive approach, where memoization is used to store results of subproblems and avoid redundant calculations. The time complexity improves to **O(n)**, making it much more efficient for larger input arrays.

---

## Bottom-Up Approach (DP)
The goal of this problem is to find the maximum sum of non-adjacent elements from a given array. In the **bottom-up approach**, we start from the base case and iteratively build up the solution by solving smaller subproblems. This avoids recursion and uses an iterative process with a table (`dp`) to store intermediate results.

### Steps:

1. **Base Case**:
   - The first element in the array (`arr[0]`) can be the only element selected initially, so `dp[0] = arr[0]`.

2. **Iterative Computation**:
   - For each element `arr[i]` in the array:
     - **Include** the current element: If we include `arr[i]`, the next element we can consider is `arr[i-2]` (we skip one element).
     - **Exclude** the current element: If we exclude `arr[i]`, we just take the maximum sum up to the previous element `arr[i-1]`.
     
   The `dp[i]` value stores the maximum sum of non-adjacent elements up to index `i`.

3. **Return the Result**:
   - After processing all elements, `dp[n-1]` will contain the result—the maximum sum of non-adjacent elements for the entire array.

### Source code
```cpp
// User function template for C++
class Solution {
  public:
    // Function to find the maximum sum without adjacent elements using bottom-up DP
    int solve(vector<int>& arr){
        int n = arr.size();  // Get the size of the input array
        
        // Initialize the dp array where dp[i] will store the maximum sum up to index i
        vector<int> dp(n, 0);
        
        // Base case: The first element is the only element we can take in the beginning
        dp[0] = arr[0];
        
        // Iterate through the array from the second element to the last element
        for(int i = 1; i < n; i++){
            // Option 1: Include the current element arr[i], 
            // we add arr[i] and the maximum sum excluding the previous element (dp[i-2])
            int include = dp[i-2] + arr[i];
            
            // Option 2: Exclude the current element arr[i], 
            // we just take the maximum sum until the previous element (dp[i-1])
            int exclude = dp[i-1];
            
            // Store the maximum sum at index i
            dp[i] = max(include, exclude);
        }
        
        // The last element in dp stores the maximum sum without adjacent elements
        return dp[n-1];
    }
    
    // Main function to find the maximum sum
    int findMaxSum(vector<int>& arr) {
        
        // Call the solve function and get the result
        int sum = solve(arr);
        
        // Return the maximum sum
        return sum;
    }
};
```

### Code Explanation:

1. **`solve()` function**:
   - **Parameters**:
     - `arr`: The input array of integers.
   - **Initialization**:
     - `n`: The size of the array `arr`.
     - `dp`: A dynamic programming table (array) where `dp[i]` stores the maximum sum we can achieve by considering elements from index `0` to `i`.
   - **Base Case**:
     - `dp[0] = arr[0]`: The first element is the only one available at the start, so the maximum sum is just `arr[0]`.
   - **Loop through the array**:
     - For each element `arr[i]` (starting from index 1):
       - **Option 1**: Include the element `arr[i]` in the sum, then we can add the maximum sum excluding the previous element (`dp[i-2]`).
       - **Option 2**: Exclude the element `arr[i]` from the sum, then we just take the maximum sum up to the previous element (`dp[i-1]`).
       - The result for each index `i` is stored as `dp[i] = max(include, exclude)`.
   - **Return the result**:
     - The final result, the maximum sum without adjacent elements, is stored in `dp[n-1]`.

2. **`findMaxSum()` function**:
   - This is the main function that calls the `solve()` function to calculate the maximum sum of non-adjacent elements and returns the result.



### Example Walkthrough:

For the array **[3, 2, 5, 10, 7]**:

1. **Start the process** with `dp[0] = 3` (the first element).
2. **At index 1**, calculate:
   - **Include 2**: The previous valid element is `dp[0] = 3`, so `dp[1] = max(3, 2) = 3`.
3. **At index 2**, calculate:
   - **Include 5**: The previous valid element is `dp[0] = 3`, so `dp[2] = max(3 + 5, 3) = 8`.
4. **At index 3**, calculate:
   - **Include 10**: The previous valid element is `dp[1] = 3`, so `dp[3] = max(3 + 10, 8) = 13`.
5. **At index 4**, calculate:
   - **Include 7**: The previous valid element is `dp[2] = 8`, so `dp[4] = max(8 + 7, 13) = 15`.

- **Final Answer**: `dp[4] = 15`, which is the maximum sum of non-adjacent elements (3 + 10 + 7).



### Time and Space Complexity:

#### **Time Complexity**:
- **O(n)**: The solution involves a single iteration through the array of size `n`. Each element is processed once, making the time complexity linear in terms of the input size.

#### **Space Complexity**:
- **O(n)**: The space complexity is **O(n)** due to the use of the `dp` array to store intermediate results. The space used by the `dp` array is proportional to the number of elements in the input array.

### Summary:

The **Bottom-Up Dynamic Programming (Tabulation)** approach offers a more efficient and space-optimized solution to the problem of finding the maximum sum of non-adjacent elements in an array. It avoids recursion and uses iteration, filling a `dp` table to compute the result. The time complexity is **O(n)**, and the space complexity can be optimized to **O(1)** using just two variables for storage.

---

## Space Optimized Approach (DP)
The code you provided implements the **space-optimized Dynamic Programming (DP)** approach for the problem of finding the maximum sum of non-adjacent elements in an array. This approach reduces the space complexity from **O(n)** to **O(1)** by using just two variables to store the last two results (`prev1` and `prev2`), instead of maintaining an entire `dp` array.

1. **Initialization**:
   - `prev2` stores the maximum sum up to the element at index `i-2` (or zero if we're at the start).
   - `prev1` stores the maximum sum up to the element at index `i-1` (initially, this will just be `arr[0]`).

2. **Iterative Process**:
   - For each element starting from the second index:
     - **Include** the current element: If we include the element at index `i`, we add it to the maximum sum up to index `i-2` (i.e., `prev2 + arr[i]`).
     - **Exclude** the current element: If we exclude the element, the sum remains the same as the maximum sum up to index `i-1` (i.e., `prev1`).
   - The result for the current index will be the maximum of including or excluding the element.

3. **Update**:
   - After each iteration, we update `prev2` to hold the value of `prev1` (i.e., the maximum sum for the previous element), and `prev1` to hold the result for the current index.

4. **Final Answer**:
   - The final result will be stored in `prev1` because it holds the maximum sum for the last element in the array.

### Space Optimization:

- The space complexity is reduced to **O(1)** because we only use two variables (`prev1` and `prev2`), regardless of the input size.
- The time complexity remains **O(n)** as we still need to iterate through the entire array.

### Source Code

```cpp
// User function template for C++
class Solution {
  public:
    // Function to find the maximum sum without adjacent elements using space-optimized DP
    int solve(vector<int>& arr){
        int n = arr.size();  // Get the size of the input array
        
        // Initialize the two variables to store the previous two results
        int prev2 = 0;  // prev2 stores the maximum sum up to index i-2
        int prev1 = arr[0];  // prev1 stores the maximum sum up to index i-1 (initially, it's the first element)
        
        // Iterate through the array starting from the second element
        for(int i = 1; i < n; i++){
            // Option 1: Include the current element arr[i]
            int include = prev2 + arr[i];
            
            // Option 2: Exclude the current element arr[i]
            int exclude = prev1;  // We just carry forward prev1 as it's the maximum sum up to the previous index
            
            // The result for the current index i is the maximum of include and exclude options
            int ans = max(include, exclude);
            
            // Update prev2 and prev1 for the next iteration
            prev2 = prev1;  // prev2 moves to prev1
            prev1 = ans;    // prev1 stores the maximum sum for the current index
        }
        
        // The final answer is stored in prev1 (which is the maximum sum for the entire array)
        return prev1;
    }
    
    // Main function to find the maximum sum
    int findMaxSum(vector<int>& arr) {
        
        // Call the solve function and get the result
        int sum = solve(arr);
        
        // Return the maximum sum
        return sum;
    }
};
```

### Explanation:

1. **Base Case**:
   - The first element (`arr[0]`) is set as the initial value of `prev1`.
   - `prev2` is initialized to `0`, as there is no previous element before the first one.

2. **Loop**:
   - For each subsequent element (from index 1 to `n-1`):
     - **Include** the current element (`arr[i]`) by adding `prev2` (the sum excluding the previous element).
     - **Exclude** the current element by taking `prev1`, which stores the sum up to the previous element.

3. **Final Answer**:
   - After iterating through all elements, `prev1` will contain the maximum sum without adjacent elements.

### Example Walkthrough:

Given the array `[3, 2, 5, 10, 7]`:

1. Initialize: `prev2 = 0`, `prev1 = 3` (since `arr[0] = 3`).
   
2. Iterate over the array:
   - For `i = 1`: `prev2 = 0`, `prev1 = 3`.
     - `include = 0 + 2 = 2`
     - `exclude = 3`
     - `ans = max(2, 3) = 3`
     - Update: `prev2 = 3`, `prev1 = 3`
   
   - For `i = 2`: `prev2 = 3`, `prev1 = 3`.
     - `include = 3 + 5 = 8`
     - `exclude = 3`
     - `ans = max(8, 3) = 8`
     - Update: `prev2 = 3`, `prev1 = 8`
   
   - For `i = 3`: `prev2 = 3`, `prev1 = 8`.
     - `include = 3 + 10 = 13`
     - `exclude = 8`
     - `ans = max(13, 8) = 13`
     - Update: `prev2 = 8`, `prev1 = 13`
   
   - For `i = 4`: `prev2 = 8`, `prev1 = 13`.
     - `include = 8 + 7 = 15`
     - `exclude = 13`
     - `ans = max(15, 13) = 15`
     - Update: `prev2 = 13`, `prev1 = 15`

3. The final result is `prev1 = 15`, which is the maximum sum of non-adjacent elements (3 + 10 + 7).

### Time and Space Complexity:

#### Time Complexity:
- **O(n)**: We iterate through the array once, and each operation inside the loop takes constant time.

#### Space Complexity:
- **O(1)**: We use only two variables (`prev1` and `prev2`) to store the necessary information, making the space complexity constant.



This space-optimized approach is both time-efficient (linear time complexity) and space-efficient (constant space complexity), making it ideal for handling larger input sizes.
