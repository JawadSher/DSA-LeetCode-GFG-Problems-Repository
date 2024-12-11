<h1 align="center">Reducing - Dishes</h1>

## Problem Statement

**Problem URL :** [Reducing Dishes](https://leetcode.com/problems/reducing-dishes/description/)

![image](https://github.com/user-attachments/assets/297f33fb-f888-42b7-b776-ecddb5847a61)

### Problem Explanation
You are given an array **`satisfaction`** of integers where:
- Each element represents the satisfaction level of a dish.
- Positive values indicate the dish increases satisfaction, and negative values indicate dissatisfaction.

You can choose to prepare some or all of the dishes in any order. However:
1. You must decide which dishes to prepare.
2. For each prepared dish, you will assign a "like-time coefficient" based on the time it is prepared.

#### Like-Time Coefficient:
For the (i)-th prepared dish, the like-time coefficient is calculated as:
`{like-time coefficient} = {satisfaction}[i] * ({time prepared})`
- The time starts at 1 for the first dish prepared, 2 for the second dish, and so on.

The goal is to maximize the sum of all like-time coefficients by:
- Selecting which dishes to prepare.
- Arranging them in an optimal order.

If no dishes are prepared, the total satisfaction is (0).

### Example 1:
#### Input:
```plain
satisfaction = [-1, -8, 0, 5, -9]
```

#### Explanation:
1. First, sort the array:
   ```plain
   [-9, -8, -1, 0, 5]
   ```
2. Choose the optimal dishes:
   - Start from the most satisfying dishes and work backward.
   - Preparing only ( [5] ): ( 5 * 1 = 5 )
   - Preparing ( [5, 0] ): ( (5 * 1) + (0 * 2) = 5 )
   - Preparing ( [5, 0, -1] ): ( (5 * 1) + (0 * 2) + (-1 * 3) = 2 ) (less than 5)
   - Best result: Preparing ( [5] ) gives (5).
3. **Output:**
   ```plain
   14
   ```

### Example 2:
#### Input:
```plain
satisfaction = [4, 3, 2]
```

#### Explanation:
1. Sort the array:
   ```plain
   [2, 3, 4]
   ```
2. Prepare all dishes:
   - Like-time coefficients:
     - ( 2 * 1 = 2 )
     - ( 3 * 2 = 6 )
     - ( 4 * 3 = 12 )
   - Total: ( 2 + 6 + 12 = 20 )
3. **Output:**
   ```plain
   20
   ```

### Example 3:
#### Input:
```plain
satisfaction = [-1, -4, -5]
```

#### Explanation:
1. Sort the array:
   ```plain
   [-5, -4, -1]
   ```
2. No dishes should be prepared because all contribute negative satisfaction.
   - Total: ( 0 )
3. **Output:**
   ```plain
   0
   ```

### Problem Expectations:
1. **Optimization Goal:** Maximize the sum of like-time coefficients.
2. **Constraints:** 
   - Prepare dishes in any order, but you must calculate coefficients sequentially (time starts at 1).
3. **Approach:** Solve efficiently by:
   - Sorting the array.
   - Iteratively calculating the cumulative sum and deciding which dishes to include or exclude.

The problem tests the ability to:
- Optimize using greedy or dynamic programming approaches.
- Handle edge cases (all negative values, all positive values, or mixed values).

---

## Recursive Approach (caused TLE)

#### Problem Overview:
We need to maximize the "like-time coefficient" for dishes by selectively including or excluding dishes in an optimal order. The recursive approach involves:
1. Deciding whether to include the current dish in the sequence.
2. Moving to the next dish with updated conditions (time multiplier).
3. Exploring all possible combinations to find the maximum total satisfaction.


#### Steps in the Recursive Approach:
1. **Sort the Array**: Sorting ensures that we handle the least satisfying dishes first. This allows us to potentially skip negative satisfaction values for optimal results.
2. **Base Case**: If we have processed all dishes (`index == n`), return (0) as no further dishes can contribute to the satisfaction.
3. **Recursive Decisions**:
   - **Include the Current Dish**:
     - Add the "like-time coefficient" for the current dish: `satisfaction[index] * time`.
     - Move to the next dish (`index + 1`) with the next time multiplier (`time + 1`).
   - **Exclude the Current Dish**:
     - Skip the current dish and move to the next dish, keeping the same `time`.
4. **Combine Results**: Return the maximum value between including and excluding the current dish.

### Example Walkthrough:
#### Input:
```plain
satisfaction = [-1, -8, 0, 5, -9]
```

#### Steps:
1. **Sort the Array**:
   ```plain
   satisfaction = [-9, -8, -1, 0, 5]
   ```

2. Start at `index = 0` and `time = 1`.
   - Include `-9`: ((-9 * 1)) + Recursively calculate for next index with `time = 2`.
   - Exclude `-9`: Recursively calculate for the next index with the same `time = 1`.

3. For each recursive call, explore both "include" and "exclude" options, calculating the total satisfaction recursively until all dishes are processed.


### Source Code
```cpp
class Solution {
public:
    // Recursive function to solve the problem
    // satisfaction: vector containing satisfaction values
    // index: current index in the satisfaction array
    // time: current time multiplier for calculating the "like-time coefficient"
    int solve(vector<int>& satisfaction, int index, int time) {
        int n = satisfaction.size();

        // Base case: if we've processed all dishes, return 0
        if (index == n) return 0;

        // Option 1: Include the current dish
        // Add the "like-time coefficient" for the current dish and move to the next dish
        int include = satisfaction[index] * time + solve(satisfaction, index + 1, time + 1);

        // Option 2: Exclude the current dish
        // Skip the current dish and keep the same time multiplier
        int exclude = 0 + solve(satisfaction, index + 1, time);

        // Return the maximum of the two options
        return max(include, exclude);
    }

    // Main function to calculate the maximum "like-time coefficient"
    int maxSatisfaction(vector<int>& satisfaction) {
        // Step 1: Sort the satisfaction array in ascending order
        // This ensures we process the least satisfying dishes first, enabling us to skip them if needed
        sort(satisfaction.begin(), satisfaction.end());

        // Step 2: Call the recursive function starting with index 0 and time 1
        return solve(satisfaction, 0, 1);
    }
};
```
### Source Code Explanation

Here's the detailed breakdown of the provided code:

```cpp
class Solution {
public:
```

- **Purpose**: Defines a `Solution` class, a common practice in LeetCode for encapsulating the solution functions.



```cpp
    int solve(vector<int>& satisfaction, int index, int time) {
```

- **Function Declaration**: This is a recursive helper function.
  - **`satisfaction`**: A vector containing the satisfaction values of the dishes.
  - **`index`**: The current dish index being processed.
  - **`time`**: Represents the time multiplier for the "like-time coefficient."
  - **Goal**: To calculate the maximum possible "like-time coefficient" starting from the given `index` and `time`.



```cpp
        int n = satisfaction.size();
```

- **Purpose**: Stores the size of the satisfaction array in a variable `n` for easier reference. For example, if `satisfaction = [-1, -8, 0, 5, -9]`, `n = 5`.



```cpp
        if (index == n) return 0;
```

- **Base Case**: If all dishes have been processed (i.e., `index` equals the size of the array), return (0).  
  - **Example**: If `index = 5` and `n = 5`, it means there are no more dishes to process, so the contribution to the satisfaction score is (0).



```cpp
        int include = satisfaction[index] * time + solve(satisfaction, index + 1, time + 1);
```

- **Option 1: Include the Current Dish**:
  1. Calculate the "like-time coefficient" for the current dish: `satisfaction[index] * time`.
  2. Recursively call the function for the next dish (`index + 1`) and increment the time multiplier (`time + 1`).
  - **Example**: For `satisfaction = [-9, -8, -1, 0, 5]`, `index = 0`, `time = 1`:
    - Include `-9`: ((-9 * 1) = -9).
    - Move to the next dish: Call `solve(satisfaction, 1, 2)`.



```cpp
        int exclude = 0 + solve(satisfaction, index + 1, time);
```

- **Option 2: Exclude the Current Dish**:
  1. Skip the current dish by not adding its satisfaction score.
  2. Call the function recursively for the next dish (`index + 1`), keeping the same `time`.
  - **Example**: For `satisfaction = [-9, -8, -1, 0, 5]`, `index = 0`, `time = 1`:
    - Exclude `-9`: Contribution is (0).
    - Move to the next dish: Call `solve(satisfaction, 1, 1)`.


```cpp
        return max(include, exclude);
```

- **Choose the Best Option**: Return the maximum between the two options:
  - Including the current dish.
  - Excluding the current dish.
  - **Example**: If including the current dish results in a score of (-9) and excluding it gives (0), return (0).


```cpp
    }
```

- **End of the `solve` Function**.


```cpp
    int maxSatisfaction(vector<int>& satisfaction) {
```

- **Function Declaration**: This is the main function to calculate the maximum "like-time coefficient."
  - It uses the recursive helper function `solve` to perform the calculations.


```cpp
        sort(satisfaction.begin(), satisfaction.end());
```

- **Step 1: Sort the Array**: Sorts the satisfaction values in ascending order to process the least satisfying dishes first.
  - **Example**: If `satisfaction = [-1, -8, 0, 5, -9]`, after sorting:  
    `satisfaction = [-9, -8, -1, 0, 5]`


```cpp
        return solve(satisfaction, 0, 1);
```

- **Step 2: Start Recursion**: Calls the recursive function `solve` starting from the first dish (`index = 0`) and an initial time multiplier of (1).
  - **Example**: With `satisfaction = [-9, -8, -1, 0, 5]`, it begins exploring all possible combinations of including or excluding dishes to maximize the satisfaction.


```cpp
    }
};
```

- **End of the Class**: Closes the `Solution` class.


### Example Walkthrough:

#### Input:
```cpp
satisfaction = [-1, -8, 0, 5, -9]
```

#### Steps:
1. **Sort the Array**:  
   `satisfaction = [-9, -8, -1, 0, 5]`

2. Start recursion from `index = 0` and `time = 1`.

3. Recursive calls explore all combinations:
   - Include `-9`: Add ((-9 * 1) = -9) and recurse.
   - Exclude `-9`: Skip it and recurse.
   - Continue for other dishes.

#### Optimal Preparation:
Select `[5, 0, -1]` for the sequence, skipping `-9` and `-8`.

#### Output:
```cpp
Maximum Like-Time Coefficient: 14
```

### Time and Space Complexity:

#### Time Complexity:
- **Recursive Function**: (O(2^n)), where (n) is the number of dishes, since every dish can either be included or excluded.
- **Sorting**: (O(n log n)).
- **Total**: (O(2^n + n log n)).

#### Space Complexity:
- **Recursion Depth**: (O(n)), due to the recursive stack.
- **Total**: (O(n)).

---

## Top-Down Approach (DP)
The top-down approach for solving this problem uses recursion combined with memoization. Here's a step-by-step breakdown of how this approach works:

1. **Recursive Nature**:
   - The problem asks to maximize the "like-time coefficient" by either including or excluding each dish in the final preparation.
   - The function recursively explores both choices: including the dish (which increases the time multiplier) or excluding it (which keeps the time multiplier the same).
   
2. **Base Case**:
   - When all dishes have been considered, the function returns 0, indicating no further contribution to the satisfaction.

3. **Memoization**:
   - To avoid redundant calculations, we use a `dp` table (memoization) to store intermediate results. The `dp` table stores the maximum satisfaction for each combination of `index` (the current dish) and `time` (the current time multiplier).
   
4. **Recursive Calls**:
   - For each dish at `index`, we have two choices:
     - **Include the dish**: Add the dish’s satisfaction to the total by multiplying it with the current `time` and move to the next dish, increasing the `time`.
     - **Exclude the dish**: Skip this dish and move to the next dish, keeping the `time` the same.
   - The maximum of these two choices is stored in the `dp` table to be reused later.

### Example Walkthrough:

#### Input:
```cpp
satisfaction = [-1, -8, 0, 5, -9]
```

#### Step-by-Step Process:

1. **Sort the satisfaction values**:  
   `satisfaction = [-9, -8, -1, 0, 5]` This step ensures that the least satisfying dishes are considered first, allowing us to skip them if needed.

2. **Start the recursion**:
   - We start at `index = 0` and `time = 1` (since the first dish is considered at time 1).
   
3. **Recursive Calls**:
   - For each dish at `index`, we have two options: include or exclude the dish.
   
   - **For `index = 0`, `time = 1`** (dish `-9`):
     - Include the dish: `-9 * 1 = -9` and recurse with `index = 1`, `time = 2`.
     - Exclude the dish: Skip `-9` and recurse with `index = 1`, `time = 1`.
   
   - After considering both options for each dish, the function calculates the maximum "like-time coefficient" and stores it in the `dp` table.

4. **Memoization**:
   - As the recursion proceeds, previously computed results are reused. For example, once `solve(1, 2)` is computed, it is stored in `dp[1][2]` and can be reused if needed.

#### Final Calculation:

- After considering all dishes, the function returns the maximum possible satisfaction score.

#### Output:
```cpp
Maximum Like-Time Coefficient: 14
```

### Source Code
```cpp
class Solution {
public:
    // Recursive function to calculate the maximum "like-time coefficient"
    // satisfaction: vector containing satisfaction values
    // index: current index in the satisfaction array
    // time: current time multiplier for calculating the "like-time coefficient"
    // dp: memoization table to store intermediate results
    int solve(vector<int>& satisfaction, int index, int time, vector<vector<int>>& dp) {
        int n = satisfaction.size();

        // Base case: If all dishes have been considered, return 0
        if (index == n) return 0;

        // Check if the result for this state is already computed
        if (dp[index][time] != -1) return dp[index][time];

        // Option 1: Include the current dish in the calculation
        // Add its contribution and move to the next dish with incremented time
        int include = satisfaction[index] * time + solve(satisfaction, index + 1, time + 1, dp);

        // Option 2: Exclude the current dish from the calculation
        // Move to the next dish without incrementing the time
        int exclude = 0 + solve(satisfaction, index + 1, time, dp);

        // Store the maximum result in the memoization table
        dp[index][time] = max(include, exclude);

        // Return the result for the current state
        return dp[index][time];
    }

    // Main function to calculate the maximum "like-time coefficient"
    int maxSatisfaction(vector<int>& satisfaction) {
        // Step 1: Sort the satisfaction array in ascending order
        // Sorting helps to efficiently decide whether to include or exclude
        sort(satisfaction.begin(), satisfaction.end());

        int n = satisfaction.size();

        // Step 2: Create a memoization table initialized to -1
        // dp[i][j] represents the maximum "like-time coefficient" starting from index i with time j
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        // Step 3: Call the recursive function starting with index 0 and time 1
        return solve(satisfaction, 0, 1, dp);
    }
};
```
### Source Code Explanation

#### Class Definition:
```cpp
class Solution {
public:
```
- Defines the `Solution` class, which contains the methods to solve the problem.



#### Recursive Helper Function (`solve`):
```cpp
    int solve(vector<int>& satisfaction, int index, int time, vector<vector<int>>& dp) {
```
- **Function Declaration**: The `solve` function is defined to recursively calculate the maximum "like-time coefficient".
  - **`satisfaction`**: Vector of satisfaction values for each dish.
  - **`index`**: The current index of the dish being considered.
  - **`time`**: The current time multiplier.
  - **`dp`**: Memoization table to store previously computed results.



```cpp
        int n = satisfaction.size();
```
- **Get the size of the satisfaction array**. For example, if `satisfaction = [-9, -8, -1, 0, 5]`, then `n = 5`.



```cpp
        if (index == n) return 0;
```
- **Base Case**: If we have processed all dishes (`index == n`), return 0 because there are no more dishes to include.



```cpp
        if (dp[index][time] != -1) return dp[index][time];
```
- **Memoization Check**: Before calculating the result for the current `index` and `time`, check if it has already been computed. If yes, return the cached result from `dp[index][time]`.



```cpp
        int include = satisfaction[index] * time + solve(satisfaction, index + 1, time + 1, dp);
```
- **Option 1: Include the current dish**:
  - Add the contribution of the current dish: `satisfaction[index] * time`.
  - Move to the next dish (`index + 1`) and increment the time (`time + 1`).
  - Recurse to calculate the rest of the satisfaction.



```cpp
        int exclude = 0 + solve(satisfaction, index + 1, time, dp);
```
- **Option 2: Exclude the current dish**:
  - Skip the current dish (no satisfaction added).
  - Move to the next dish without changing the time.



```cpp
        dp[index][time] = max(include, exclude);
```
- **Store the Maximum Result**: Store the maximum of the two options (include or exclude) in the `dp` table for the current state (`index`, `time`).



```cpp
        return dp[index][time];
```
- **Return the Result**: Return the maximum satisfaction from the current state.



#### Main Function (`maxSatisfaction`):
```cpp
    int maxSatisfaction(vector<int>& satisfaction) {
```
- **Function Declaration**: The main function to calculate the maximum "like-time coefficient".



```cpp
        sort(satisfaction.begin(), satisfaction.end());
```
- **Sort the Satisfaction Array**: Sorting helps us to process the least satisfying dishes first, which is important for skipping dishes when necessary.



```cpp
        int n = satisfaction.size();
```
- **Get the size of the satisfaction array**.



```cpp
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
```
- **Create the Memoization Table**: A 2D vector `dp` of size `(n+1) x (n+1)` is initialized to `-1` to represent uncomputed states. Here, `dp[i][j]` will store the maximum satisfaction when starting from the `i`-th dish with a time multiplier of `j`.



```cpp
        return solve(satisfaction, 0, 1, dp);
```
- **Start the Recursive Call**: Call the `solve` function starting from the first dish (`index = 0`) and time `1`.



#### End of Class:
```cpp
    }
};
```

### Example Output

#### Input:
```cpp
satisfaction = [-1, -8, 0, 5, -9]
```

#### Steps:
1. **Sort the Array**:  
   `satisfaction = [-9, -8, -1, 0, 5]`

2. Start recursion with `index = 0` and `time = 1`.

3. **Recursive Calls**:
   - For each dish, we either include or exclude it, calculating the "like-time coefficient" as we go.

4. **Memoization**:
   - Results for each combination of `index` and `time` are stored in `dp` to avoid redundant calculations.

5. **Final Output**:
   The function returns the maximum possible satisfaction score.

#### Output:
```cpp
Maximum Like-Time Coefficient: 14
```

### Time Complexity:
- **Recursion with Memoization**: Each state is computed only once, and there are (O(n^2)) possible states (since `index` can range from 0 to `n-1` and `time` can range from 1 to `n`).
- **Sorting**: Sorting the satisfaction array takes (O(n log n)).
- **Total Time Complexity**: (O(n^2 + n log n) = O(n^2)).

### Space Complexity:
- **Memoization Table**: The `dp` table requires (O(n^2)) space.
- **Recursion Stack**: The maximum recursion depth is (O(n)), so the space for the recursion stack is (O(n)).
- **Total Space Complexity**: (O(n^2)).

---

## Bottom-Up Approach (DP)
The **Bottom-Up Approach** is an iterative method that solves the problem by gradually solving smaller subproblems and building up to the overall solution. Unlike the **Top-Down Approach** (which uses recursion and memoization), the Bottom-Up Approach iteratively computes results from the smallest subproblem to the largest, avoiding recursion and using a dynamic programming table.

#### Step-by-Step Explanation:

1. **DP Table Initialization**:
   - We create a 2D DP table, `dp[i][j]`, where `i` represents the index of the dish in the `satisfaction` array, and `j` represents the time multiplier (starting from 1).
   - The table is initialized to 0, and the goal is to fill this table with the maximum possible "like-time coefficient" for each combination of `i` (dish index) and `j` (time multiplier).

2. **Filling the DP Table**:
   - We iterate through the `satisfaction` array in reverse order (`satis` starts from `n-1` and goes to `0`), ensuring that we compute results for each dish starting from the last dish and moving towards the first.
   - For each dish at `satis`, we iterate through all possible time values from `satis` down to `0`, since we can't have more time multipliers than dishes.
   - For each combination of `satis` and `time`, we calculate:
     - **Include the current dish**: Add the satisfaction of the dish at `satis` multiplied by the current time (`time + 1`) to the result from the next dish (`dp[satis + 1][time + 1]`).
     - **Exclude the current dish**: Skip the dish and just take the result from the next dish (`dp[satis + 1][time]`).

3. **Final Result**:
   - After filling the DP table, the result for the maximum possible satisfaction is stored in `dp[0][0]`, which represents starting from the first dish (`index = 0`) with a time multiplier of 1.

### Example Walkthrough:

#### Input:
```cpp
satisfaction = [-1, -8, 0, 5, -9]
```

#### Step-by-Step Process:

1. **Sort the Satisfaction Array**:
   `satisfaction = [-9, -8, -1, 0, 5]`
   
   - Sorting ensures that we process less satisfying dishes first. This helps decide whether to include or exclude them early on.

3. **Initialize the DP Table**:
   - The DP table will be of size `(n+1) x (n+1)` where `n` is the number of dishes (5 in this case).
   - Initialize all elements to 0.

4. **Iterate Over the Array**:
   - We iterate over the array in reverse order, filling in the DP table by considering both including and excluding each dish.

5. **Calculate Maximum Satisfaction**:
   - After filling the DP table, the function will return `dp[0][0]`, which contains the maximum "like-time coefficient."

#### Output:
```cpp
Maximum Like-Time Coefficient: 14
```

### Source Code
```cpp
class Solution {
public:
    // Function to solve the problem using bottom-up dynamic programming
    // satisfaction: vector containing satisfaction values of dishes
    int solve(vector<int>& satisfaction) {
        int n = satisfaction.size();

        // Create a DP table to store the maximum "like-time coefficient" values
        // dp[i][j] represents the maximum value achievable starting from index i with time j
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Iterate over the satisfaction array in reverse order
        // satis represents the current index in the satisfaction array
        for (int satis = n - 1; satis >= 0; satis--) {
            // Iterate over the possible time values in reverse order
            for (int time = satis; time >= 0; time--) {
                // Option 1: Include the current dish
                // Add its contribution to the result, and increment the time multiplier
                int include = satisfaction[satis] * (time + 1) + dp[satis + 1][time + 1];

                // Option 2: Exclude the current dish
                // Skip the current dish, keeping the same time multiplier
                int exclude = 0 + dp[satis + 1][time];

                // Store the maximum of the two options in the DP table
                dp[satis][time] = max(include, exclude);
            }
        }

        // Return the maximum value starting from index 0 with time multiplier 1
        return dp[0][0];
    }

    // Main function to calculate the maximum "like-time coefficient"
    int maxSatisfaction(vector<int>& satisfaction) {
        // Step 1: Sort the satisfaction array in ascending order
        // Sorting ensures we process less satisfying dishes first
        sort(satisfaction.begin(), satisfaction.end());

        // Step 2: Use the solve function to compute the result
        return solve(satisfaction);
    }
};
```
### Source Code Explanation

#### Class Definition:
```cpp
class Solution {
public:
```
- Defines the `Solution` class, which contains the methods to solve the problem.



#### Solve Function (`solve`):
```cpp
    int solve(vector<int>& satisfaction) {
```
- **Function Declaration**: The `solve` function calculates the maximum "like-time coefficient" using dynamic programming.
  - **`satisfaction`**: The vector that stores the satisfaction values of dishes.



```cpp
        int n = satisfaction.size();
```
- **Get the Size of Satisfaction Array**: `n` is the number of dishes in the `satisfaction` array. For example, if `satisfaction = [-9, -8, -1, 0, 5]`, then `n = 5`.



```cpp
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
```
- **Initialize DP Table**: 
  - We create a 2D DP table of size `(n+1) x (n+1)` initialized to `0`. 
  - `dp[i][j]` will store the maximum "like-time coefficient" we can achieve starting from dish `i` with a time multiplier of `j`.



```cpp
        for (int satis = n - 1; satis >= 0; satis--) {
```
- **Reverse Iteration Over Dishes**: We iterate over the `satisfaction` array from the last dish to the first, processing each dish starting from `n-1` to `0`.



```cpp
            for (int time = satis; time >= 0; time--) {
```
- **Reverse Iteration Over Time**: For each dish, we consider all possible time multipliers from `satis` (the current index) down to `0`. This ensures we don't exceed the time multiplier limit based on the number of dishes left.



```cpp
                int include = satisfaction[satis] * (time + 1) + dp[satis + 1][time + 1];
```
- **Option 1: Include the Current Dish**:
  - If we include the current dish, we multiply the satisfaction of the current dish by `time + 1` (the time multiplier).
  - We then add the result from the next dish (`dp[satis + 1][time + 1]`), which considers the next dish with the incremented time multiplier.



```cpp
                int exclude = 0 + dp[satis + 1][time];
```
- **Option 2: Exclude the Current Dish**:
  - If we exclude the current dish, we simply take the result from the next dish (`dp[satis + 1][time]`), keeping the same time multiplier.



```cpp
                dp[satis][time] = max(include, exclude);
```
- **Store the Maximum Result**: We store the maximum of the two options (include or exclude) in the DP table for the current dish (`satis`) and time (`time`).



```cpp
            }
        }
```
- **End of Loop**: Close the inner and outer loops.



```cpp
        return dp[0][0];
```
- **Return the Final Result**: After filling the DP table, return the maximum satisfaction starting from the first dish (`index = 0`) and time multiplier `1` (`dp[0][0]`).



#### Main Function (`maxSatisfaction`):
```cpp
    int maxSatisfaction(vector<int>& satisfaction) {
```
- **Function Declaration**: The main function to calculate the maximum "like-time coefficient".



```cpp
        sort(satisfaction.begin(), satisfaction.end());
```
- **Sort the Satisfaction Array**: Sort the satisfaction array in ascending order to process less satisfying dishes first.



```cpp
        return solve(satisfaction);
```
- **Call the Solve Function**: After sorting, we call the `solve` function to compute and return the result.



#### End of Class:
```cpp
    }
};
```

### Example Output

#### Input:
```cpp
satisfaction = [-1, -8, 0, 5, -9]
```

#### Steps:
1. **Sort the Array**:  
  `satisfaction = [-9, -8, -1, 0, 5]`

2. **Initialize the DP Table**:  
   A 2D DP table of size 6x6 is initialized to 0.

3. **Iterate Over the Array**:
   - For each dish, we compute the maximum "like-time coefficient" by including or excluding the dish.

4. **Final Output**:
   The function returns `dp[0][0]`, the maximum possible satisfaction.

#### Output:
```cpp
Maximum Like-Time Coefficient: 14
```

### Time Complexity:
- **Filling the DP Table**: We iterate over the satisfaction array and time values, which results in `O(n^2)` operations.
- **Sorting the Satisfaction Array**: Sorting takes (O(n log n)).
- **Total Time Complexity**: (O(n^2 + n log n) = O(n^2)).

### Space Complexity:
- **DP Table**: The DP table requires (O(n^2)) space, where `n` is the number of dishes.
- **Total Space Complexity**: (O(n^2)).

---

## 1) Space Optimization Approach (DP)
The **Space Optimization Approach** is a refinement of the previous Bottom-Up Dynamic Programming approach, where we use only two 1D arrays instead of a 2D table to reduce space complexity. This is done by leveraging the observation that, at any given step, we only need the current and the next states of the DP table.

#### Key Ideas:
- In the Bottom-Up Dynamic Programming solution, we used a 2D table `dp[i][j]` where `i` represents the dish index, and `j` represents the time multiplier.
- However, the value of `dp[satis][time]` only depends on `dp[satis + 1][time + 1]` (the next dish with the next time multiplier) and `dp[satis + 1][time]` (the next dish with the same time multiplier).
- Thus, we can reduce the space complexity by using just two 1D arrays (`curr` and `next`), alternating between them to store the results of the current and next iterations.

### Step-by-Step Explanation:

1. **DP Arrays Initialization**:
   - We create two 1D arrays, `curr` and `next`, both of size `n + 1` (where `n` is the number of dishes). These arrays are initialized to zero.
   - `curr` holds the results of the current iteration, and `next` holds the results of the previous iteration.

2. **Iterate Over the Satisfaction Array**:
   - We iterate through the `satisfaction` array in reverse order (from the last dish to the first), updating the `curr` array based on the results of the previous iteration stored in the `next` array.
   - For each dish at index `satis`, we iterate over the time multipliers, from `satis` down to 0, to calculate two possible outcomes for each time:
     - **Include the Current Dish**: Add the satisfaction of the current dish multiplied by the current time multiplier, and add the result from the next dish with an incremented time multiplier.
     - **Exclude the Current Dish**: Skip the current dish and take the result from the next dish with the same time multiplier.

3. **Update the State**:
   - After processing all time multipliers for the current dish, we move the `curr` array to the `next` array, so it can be used in the next iteration for the subsequent dish.

4. **Return the Result**:
   - After the loop ends, the maximum satisfaction is stored in `curr[0]`, which represents the best result starting from the first dish with a time multiplier of 1.

### Example Walkthrough:

#### Input:
```cpp
satisfaction = [-1, -8, 0, 5, -9]
```

#### Step-by-Step Process:

1. **Sort the Satisfaction Array**:
   `satisfaction = [-9, -8, -1, 0, 5]` Sorting ensures that less satisfying dishes are processed first, making it easier to decide whether to include or exclude them.

2. **Initialize the DP Arrays**:
   - Two 1D arrays `curr` and `next` are initialized with size `n+1`, all set to zero.

3. **Iterate Over the Array**:
   - We iterate over the dishes from the last one (`satis = 4`) to the first one (`satis = 0`), and for each dish, we compute the maximum satisfaction by either including or excluding it.

4. **Final Output**:
   - The result will be stored in `curr[0]`, which gives the maximum "like-time coefficient" starting from the first dish and the first time multiplier.

#### Output:
```cpp
Maximum Like-Time Coefficient: 14
```
### Source Code
```cpp
class Solution {
public:
    // Function to calculate the maximum "like-time coefficient"
    // satisfaction: vector containing satisfaction values of dishes
    int solve(vector<int>& satisfaction) {
        int n = satisfaction.size();

        // Create two 1D DP arrays to store results of the current and next iterations
        // We use two arrays instead of a 2D table to optimize space
        vector<int> curr(n + 1, 0); // Current state
        vector<int> next(n + 1, 0); // Next state

        // Iterate over the satisfaction array in reverse order
        // satis represents the current index in the satisfaction array
        for (int satis = n - 1; satis >= 0; satis--) {
            // Iterate over possible time multipliers in reverse order
            for (int time = satis; time >= 0; time--) {
                // Option 1: Include the current dish
                // Add its contribution to the result, and increment the time multiplier
                int include = satisfaction[satis] * (time + 1) + next[time + 1];

                // Option 2: Exclude the current dish
                // Skip the current dish, keeping the same time multiplier
                int exclude = 0 + next[time];

                // Store the maximum of the two options in the current DP array
                curr[time] = max(include, exclude);
            }

            // Move the current state to the next state for the next iteration
            next = curr;
        }

        // Return the maximum value starting from index 0 with time multiplier 1
        return curr[0];
    }

    // Main function to calculate the maximum "like-time coefficient"
    int maxSatisfaction(vector<int>& satisfaction) {
        // Step 1: Sort the satisfaction array in ascending order
        // Sorting ensures that we process less satisfying dishes first
        sort(satisfaction.begin(), satisfaction.end());

        // Step 2: Use the solve function to compute the result
        return solve(satisfaction);
    }
};
```
### Source Code Explanation

#### Class Definition:
```cpp
class Solution {
public:
```
- Defines the `Solution` class, which contains the methods to solve the problem.



#### Solve Function (`solve`):
```cpp
    int solve(vector<int>& satisfaction) {
```
- **Function Declaration**: The `solve` function computes the maximum "like-time coefficient" using space optimization with two 1D arrays (`curr` and `next`).
  - **`satisfaction`**: The vector containing the satisfaction values of dishes.



```cpp
        int n = satisfaction.size();
```
- **Get the Size of Satisfaction Array**: `n` is the number of dishes in the `satisfaction` array. If `satisfaction = [-9, -8, -1, 0, 5]`, then `n = 5`.



```cpp
        vector<int> curr(n + 1, 0); // Current state
        vector<int> next(n + 1, 0); // Next state
```
- **Initialize DP Arrays**: Two 1D arrays `curr` and `next` of size `n + 1` are created and initialized to 0. 
  - `curr` will store the results of the current iteration.
  - `next` will store the results of the previous iteration.



```cpp
        for (int satis = n - 1; satis >= 0; satis--) {
```
- **Reverse Iteration Over Dishes**: We iterate over the `satisfaction` array from the last dish to the first (`satis` from `n-1` to `0`).



```cpp
            for (int time = satis; time >= 0; time--) {
```
- **Reverse Iteration Over Time Multipliers**: For each dish, we iterate over all possible time multipliers from `satis` down to `0`, ensuring we don't exceed the maximum number of dishes.



```cpp
                int include = satisfaction[satis] * (time + 1) + next[time + 1];
```
- **Option 1: Include the Current Dish**:
  - If we include the current dish, we multiply its satisfaction by `(time + 1)`, and add the result from the next dish with the incremented time multiplier (`next[time + 1]`).



```cpp
                int exclude = 0 + next[time];
```
- **Option 2: Exclude the Current Dish**:
  - If we exclude the current dish, we simply take the result from the next dish with the same time multiplier (`next[time]`).



```cpp
                curr[time] = max(include, exclude);
```
- **Store the Maximum Result**: We store the maximum of the two options (include or exclude) in the `curr` array for the current dish (`satis`) and time (`time`).



```cpp
            }
```
- **End of Time Loop**: Close the inner loop for time multipliers.



```cpp
            next = curr;
```
- **Update the State**: After processing all time multipliers for the current dish, we move the `curr` array to the `next` array, so it can be used in the next iteration.



```cpp
        }
```
- **End of Dish Loop**: Close the outer loop for dishes.



```cpp
        return curr[0];
```
- **Return the Final Result**: After filling the arrays, return `curr[0]`, which contains the maximum satisfaction starting from the first dish (`index = 0`) and the first time multiplier.



#### Main Function (`maxSatisfaction`):
```cpp
    int maxSatisfaction(vector<int>& satisfaction) {
```
- **Function Declaration**: The main function to calculate the maximum "like-time coefficient".



```cpp
        sort(satisfaction.begin(), satisfaction.end());
```
- **Sort the Satisfaction Array**: Sort the satisfaction array in ascending order to process the less satisfying dishes first.



```cpp
        return solve(satisfaction);
```
- **Call the Solve Function**: After sorting the satisfaction array, we call the `solve` function to compute and return the result.



#### End of Class:
```cpp
    }
};
```

### Example Output

#### Input:
```cpp
satisfaction = [-1, -8, 0, 5, -9]
```

#### Steps:
1. **Sort the Array**:  
   `satisfaction = [-9, -8, -1, 0, 5]`

2. **Initialize the DP Arrays**:  
   Two 1D arrays `curr` and `next` of size `6` are initialized to 0.

3. **Iterate Over the Array**:
   - We process each dish in reverse order, considering whether to include or exclude each dish.

4. **Final Output**:
   The function returns `curr[0]`, the maximum possible satisfaction.

#### Output:
```cpp
Maximum Like-Time Coefficient: 14
```

### Time Complexity:
- **Filling the DP Arrays**: We iterate over the satisfaction array and time values, which results in `O(n^2)` operations.
- **Sorting the Satisfaction Array**: Sorting takes (O(n log n)).
- **Total Time Complexity**: (O(n^2 + n log n) = O(n^2)).

### Space Complexity:
- **DP Arrays**: The space complexity is reduced to (O(n)), as we only use two 1D arrays (`curr` and `next`).
- **Total Space Complexity**: (O(n)).

---

## 2) Space Optimization Approach (DP)
The **Space Optimization Approach** aims to compute the maximum "like-time coefficient" by reducing the space complexity to constant space. This is achieved by iterating over the sorted satisfaction array in reverse order, maintaining just a few variables to track the maximum satisfaction and running totals instead of using any auxiliary data structures like arrays or matrices.

#### Key Ideas:
- In this approach, we eliminate the need for dynamic programming tables or arrays, and instead, we focus on using a few variables (`maxSatisfaction`, `cumulativeSum`, and `runningTotal`) to compute the result in a single pass.
- The idea is to first sort the `satisfaction` array, and then traverse it from the last dish to the first, adding satisfaction values progressively and updating the running total, which is the sum of satisfaction values weighted by the time multiplier.

### Step-by-Step Explanation:

1. **Sort the Satisfaction Array**:
   - Sorting the `satisfaction` array in ascending order allows us to consider less satisfying dishes first. This is important because if a dish has a negative satisfaction value, including it last in the sequence could lead to a better total when it gets multiplied by the higher time multipliers.

2. **Variables Initialization**:
   - `maxSatisfaction`: This variable stores the maximum "like-time coefficient" found so far.
   - `cumulativeSum`: This variable keeps a running sum of satisfaction values as we iterate over the array.
   - `runningTotal`: This variable accumulates the sum of the cumulative satisfaction values weighted by their respective time multipliers (the running "like-time coefficient").

3. **Traverse the Array in Reverse**:
   - By traversing the satisfaction array from the last dish to the first, we accumulate the satisfaction values and calculate the "like-time coefficient" as we go.
   - After each dish, we check if including that dish improves the "like-time coefficient". If including the dish reduces the result, we break the loop early as including further dishes would only decrease the total.

4. **Return the Result**:
   - The result, `maxSatisfaction`, will contain the highest "like-time coefficient" found during the iteration.

### Example Walkthrough:

#### Input:
```cpp
satisfaction = [-1, -8, 0, 5, -9]
```

#### Step-by-Step Process:

1. **Sort the Satisfaction Array**:
   `satisfaction = [-9, -8, -1, 0, 5]` Sorting ensures that less satisfying dishes are processed first.

2. **Initialize Variables**:
   - `maxSatisfaction = 0` (initial maximum satisfaction is 0)
   - `cumulativeSum = 0` (initial running sum of satisfaction values)
   - `runningTotal = 0` (initial "like-time coefficient")

3. **Iterate Over the Satisfaction Array**:
   - For each dish in reverse order, we calculate the cumulative sum and the running total, and update `maxSatisfaction` accordingly.

4. **Final Output**:
   - After processing all dishes, the maximum satisfaction is stored in `maxSatisfaction`.

#### Output:
```cpp
Maximum Like-Time Coefficient: 14
```
### Source Code
```cpp
class Solution {
public:
    // Function to calculate the maximum "like-time coefficient"
    // satisfaction: vector containing satisfaction values of dishes
    int solve(vector<int>& satisfaction) {
        int n = satisfaction.size();

        // Variables to keep track of the results
        int maxSatisfaction = 0;  // Maximum satisfaction achieved so far
        int cumulativeSum = 0;    // Running sum of satisfaction values
        int runningTotal = 0;     // Current "like-time coefficient"

        // Traverse the satisfaction array in reverse order
        // This ensures we consider the most satisfying dishes last
        for (int i = n - 1; i >= 0; i--) {
            cumulativeSum += satisfaction[i];  // Add current satisfaction value to the cumulative sum
            runningTotal += cumulativeSum;     // Update the running total with the new cumulative sum

            // Update the maximum satisfaction if the current running total is greater
            if (runningTotal > maxSatisfaction) 
                maxSatisfaction = runningTotal;
            else 
                break;  // Stop processing if adding more dishes reduces the total
        }

        // Return the maximum satisfaction found
        return maxSatisfaction;
    }

    // Main function to calculate the maximum "like-time coefficient"
    int maxSatisfaction(vector<int>& satisfaction) {
        // Step 1: Sort the satisfaction array in ascending order
        // Sorting ensures we can efficiently process from least to most satisfying
        sort(satisfaction.begin(), satisfaction.end());

        // Step 2: Use the solve function to compute the result
        return solve(satisfaction);
    }
};
```
### Source Code Explanation

#### Class Definition:
```cpp
class Solution {
public:
```
- Defines the `Solution` class, which contains the methods to solve the problem.



#### Solve Function (`solve`):
```cpp
    int solve(vector<int>& satisfaction) {
```
- **Function Declaration**: The `solve` function computes the maximum "like-time coefficient" using space optimization.



```cpp
        int n = satisfaction.size();
```
- **Get the Size of Satisfaction Array**: `n` is the number of dishes in the `satisfaction` array. If `satisfaction = [-9, -8, -1, 0, 5]`, then `n = 5`.



```cpp
        int maxSatisfaction = 0;  // Maximum satisfaction achieved so far
        int cumulativeSum = 0;    // Running sum of satisfaction values
        int runningTotal = 0;     // Current "like-time coefficient"
```
- **Initialize Variables**:
  - `maxSatisfaction` keeps track of the maximum satisfaction encountered.
  - `cumulativeSum` is the sum of satisfaction values processed so far.
  - `runningTotal` is the running "like-time coefficient" which accumulates satisfaction values weighted by the time multipliers.



```cpp
        for (int i = n - 1; i >= 0; i--) {
```
- **Iterate in Reverse**: We process the satisfaction array from the last dish to the first (`i` from `n-1` to `0`).



```cpp
            cumulativeSum += satisfaction[i];  // Add current satisfaction value to cumulative sum
            runningTotal += cumulativeSum;     // Update the running total with the new cumulative sum
```
- **Update Cumulative Sum and Running Total**:
  - We add the current dish's satisfaction to the cumulative sum (`cumulativeSum += satisfaction[i]`).
  - We then update the running total, which is the sum of satisfaction values weighted by their respective time multipliers.



```cpp
            if (runningTotal > maxSatisfaction) 
                maxSatisfaction = runningTotal;
            else 
                break;  // Stop processing if adding more dishes reduces the total
```
- **Check for Maximum Satisfaction**:
  - If the current running total exceeds the maximum satisfaction so far, we update `maxSatisfaction`.
  - If including the current dish reduces the running total (i.e., it is no longer beneficial to include this dish), we break the loop early. This is possible because all dishes with lower satisfaction will only reduce the total.



```cpp
        }
```
- **End of Loop**: We finish processing the satisfaction array.



```cpp
        return maxSatisfaction;
```
- **Return the Maximum Satisfaction**: After the loop ends, the `maxSatisfaction` variable holds the highest "like-time coefficient" found during the iteration.



#### Main Function (`maxSatisfaction`):
```cpp
    int maxSatisfaction(vector<int>& satisfaction) {
```
- **Function Declaration**: The main function to calculate the maximum "like-time coefficient".



```cpp
        sort(satisfaction.begin(), satisfaction.end());
```
- **Sort the Satisfaction Array**: We sort the satisfaction array in ascending order to process less satisfying dishes first.



```cpp
        return solve(satisfaction);
```
- **Call the Solve Function**: After sorting the satisfaction array, we call the `solve` function to compute and return the result.



#### End of Class:
```cpp
    }
};
```

### Example Output

#### Input:
```cpp
satisfaction = [-1, -8, 0, 5, -9]
```

#### Steps:
1. **Sort the Array**:  
   `satisfaction = [-9, -8, -1, 0, 5]`

2. **Initialize Variables**:  
   - `maxSatisfaction = 0`
   - `cumulativeSum = 0`
   - `runningTotal = 0`

3. **Iterate Over the Array**:
   - Process each dish, calculate the cumulative sum, and update the running total and the maximum satisfaction.

4. **Final Output**:
   The function returns `maxSatisfaction`, the maximum possible satisfaction.

#### Output:
```cpp
Maximum Like-Time Coefficient: 14
```

### Time Complexity:
- **Sorting the Satisfaction Array**: Sorting takes (O(n log n)).
- **Traversing the Array**: The iteration over the satisfaction array takes (O(n)).
- **Total Time Complexity**: (O(n log n)).

### Space Complexity:
- **Space Optimization**: We only use a constant amount of space for the variables `maxSatisfaction`, `cumulativeSum`, and `runningTotal`.
- **Total Space Complexity**: (O(1)).
