<h1 align="center">Minimum - Sideway - Jumps</h1>

## Problem Statement

**Problem URL :** [Minimum Sideway Jumps](https://leetcode.com/problems/minimum-sideway-jumps/description/)

![image](https://github.com/user-attachments/assets/2218fe70-a5e4-4470-b0aa-3edf47bd35ef)

### Problem Explanation
The problem **"Minimum Sideway Jumps"** on LeetCode asks us to find the minimum number of sideway jumps needed to travel from the start to the end of a road, where there are obstacles that block our movement. You are given a `n`-length array called `obstacles` where each element represents the lane at each position, and you need to figure out the minimum jumps required to reach the end without hitting any obstacles.

- You have a 3-lane road.
- You start at position `0` and need to move to the last position `n-1`.
- You can only move forward, but at any given position, if a lane is blocked (i.e., an obstacle is in that lane), you may need to move to a different lane.
- You need to determine the minimum number of sideway jumps (i.e., jumps to a different lane) to reach the last position.

#### Steps to Solve:
1. **Initial Setup**:
   - The array `obstacles` represents the state of the road. If an element is `0`, the lane is empty; otherwise, the element represents the lane number where there is an obstacle at that position.
   - You are allowed to move in three lanes: lane 1, lane 2, and lane 3.

2. **Goal**:
   - Your goal is to move from position `0` to position `n-1` while avoiding obstacles and minimizing the number of lane changes (side jumps).

3. **Approach**:
   - The problem can be solved using **Dynamic Programming** (DP).
   - For each position, we need to track the minimum number of sideway jumps required to reach that position in each lane.
   - The main challenge is to decide if we need to jump to a different lane at each position and how to minimize the number of jumps.


#### Detailed Step-by-Step Explanation with Example:

Consider the following example:

**Input:**

`obstacles = [0,1,2,2,1,0]`

This means:
- At position `0`, all lanes are free.
- At position `1`, lane `1` is blocked.
- At position `2`, lane `2` is blocked.
- At position `3`, lane `2` is blocked.
- At position `4`, lane `1` is blocked.
- At position `5`, all lanes are free again.

#### Step 1: **Initialization**:
We need to initialize the DP table to keep track of the minimum number of jumps required to reach each position from any lane. We will use three arrays (or vectors), one for each lane:
- `dp[1][pos]`: minimum jumps to reach position `pos` on lane `1`.
- `dp[2][pos]`: minimum jumps to reach position `pos` on lane `2`.
- `dp[3][pos]`: minimum jumps to reach position `pos` on lane `3`.

Each of these values will initially be set to a large number (`INT_MAX`) to represent infinity, except at the start (position `0`) where no jump is needed.

#### Step 2: **Forward Pass**:
We start at the beginning of the road (`pos = 0`) and work our way to the end (`pos = n-1`). For each position, we check the following:
- If the lane is not blocked by an obstacle, we can stay in the current lane and move forward.
- If the lane is blocked, we consider moving to the next available lane.

At each position:
- **If the next position in the current lane is not blocked**, we continue forward.
- **If the next position in the current lane is blocked**, we check if we can jump to any other lane.

#### Example Walkthrough:

Let’s walk through the process with the given `obstacles = [0,1,2,2,1,0]`.

##### Initialization:
- `dp[1][0] = 0` (No jump needed at position 0 on lane 1)
- `dp[2][0] = 0` (No jump needed at position 0 on lane 2)
- `dp[3][0] = 0` (No jump needed at position 0 on lane 3)

##### Position 1 (`obstacle[1] = 1`):
- Lane 1 is blocked at position 1, so we can’t stay in lane 1.
- We need to jump to either lane 2 or lane 3.
  - **Jump to lane 2**: `dp[2][1] = dp[3][0] + 1 = 1` (1 jump from lane 3 at position 0)
  - **Jump to lane 3**: `dp[3][1] = dp[2][0] + 1 = 1` (1 jump from lane 2 at position 0)

##### Position 2 (`obstacle[2] = 2`):
- Lane 2 is blocked at position 2, so we can’t stay in lane 2.
- We need to jump to either lane 1 or lane 3.
  - **Jump to lane 1**: `dp[1][2] = dp[3][1] + 1 = 2` (2 jumps from lane 3 at position 1)
  - **Jump to lane 3**: `dp[3][2] = dp[1][1] + 1 = 2` (2 jumps from lane 1 at position 1)

##### Position 3 (`obstacle[3] = 2`):
- Lane 2 is blocked at position 3, so we can’t stay in lane 2.
- We need to jump to either lane 1 or lane 3.
  - **Jump to lane 1**: `dp[1][3] = dp[3][2] + 1 = 3` (3 jumps from lane 3 at position 2)
  - **Jump to lane 3**: `dp[3][3] = dp[1][2] + 1 = 3` (3 jumps from lane 1 at position 2)

##### Position 4 (`obstacle[4] = 1`):
- Lane 1 is blocked at position 4, so we can’t stay in lane 1.
- We need to jump to either lane 2 or lane 3.
  - **Jump to lane 2**: `dp[2][4] = dp[3][3] + 1 = 4` (4 jumps from lane 3 at position 3)
  - **Jump to lane 3**: `dp[3][4] = dp[2][3] + 1 = 4` (4 jumps from lane 2 at position 3)

##### Position 5 (`obstacle[5] = 0`):
- All lanes are free at position 5.
- We can move forward on any lane. Since we want to minimize the jumps, we choose the minimum number of jumps from the previous position.

#### Final Calculation:
At the last position (position 5), we calculate the minimum jumps required to reach this position on any lane:
- We choose the minimum of `dp[1][5]`, `dp[2][5]`, or `dp[3][5]`.
- The minimum number of jumps will give the final result.

#### Answer:
- The minimum number of sideway jumps required to reach the last position is the answer to the problem.

---

## Recurisve Approach (caused TLE)
In this problem, we are tasked with determining the minimum number of sideway jumps required to go from the start to the end of the road, while avoiding obstacles in three lanes. The problem uses a recursive approach to simulate each decision point where the car may either stay in its current lane (if not blocked by an obstacle) or jump to another lane.

### Recursive Function Explanation

The recursive function `solve(vector<int>& obstacles, int currlane, int currpos)` is used to calculate the minimum sideway jumps needed at a given position (`currpos`) on a specific lane (`currlane`).

#### Key Recursive Steps:
1. **Base Case**:
   - If we reach the last position (`currpos == n`), we return `0` because no more jumps are needed.

2. **Move Forward Without Jump**:
   - If the next position (`currpos + 1`) is not blocked by an obstacle in the current lane (`obstacles[currpos + 1] != currlane`), we can move forward without jumping, so we make a recursive call to `solve(obstacles, currlane, currpos + 1)`.

3. **Blocked Lane, Need a Side Jump**:
   - If the next position is blocked in the current lane (`obstacles[currpos + 1] == currlane`), we must find the best lane to jump to. We try all three possible lanes (`1, 2, 3`) and check:
     - If the lane is not the current lane (`currlane != i`).
     - If the next position in the new lane is not blocked (`obstacles[currpos] != i`).
   - For each valid lane jump, we make a recursive call and add `1` to represent the jump.

4. **Return the Minimum Jumps**:
   - After checking all valid lane options, we return the minimum number of jumps (including the current jump).

### Example Walkthrough

Consider the following example input:

`obstacles = [0, 1, 2, 2, 1, 0]`

Here:
- `0` represents an empty lane (no obstacle).
- `1`, `2` represent obstacles in lanes 1 and 2, respectively.

We are trying to move from position 0 to position 5, and we start from lane 2 (`currlane = 2`).

**Step-by-step Execution**:
1. **Position 0, Lane 2**:
   - We check if lane 2 is blocked at position 1 (`obstacles[1] = 1`), but it's not blocked in lane 2, so we move to the next position without a jump.
   - Call `solve(obstacles, 2, 1)`.

2. **Position 1, Lane 2**:
   - Lane 2 is blocked at position 2 (`obstacles[2] = 2`), so we need to jump to another lane.
   - Try jumping to lane 1 or lane 3. Lane 1 is blocked at position 1, so we can only jump to lane 3.
   - Call `solve(obstacles, 3, 2)`.

3. **Position 2, Lane 3**:
   - Lane 3 is blocked at position 3 (`obstacles[3] = 2`), so we need to jump again.
   - Try jumping to lane 1 or lane 2. Both are possible, but we choose to jump to lane 1 (this choice leads to fewer jumps).
   - Call `solve(obstacles, 1, 3)`.

4. **Position 3, Lane 1**:
   - Lane 1 is blocked at position 4 (`obstacles[4] = 1`), so we need to jump again.
   - We can jump to lane 2 or lane 3, and lane 2 is free, so we jump to lane 2.
   - Call `solve(obstacles, 2, 4)`.

5. **Position 4, Lane 2**:
   - Lane 2 is free at position 5, so we move forward without jumping.
   - Call `solve(obstacles, 2, 5)`.

6. **Position 5, Lane 2**:
   - We have reached the last position, so no more jumps are needed.
   - Return `0`.

Thus, the minimum number of side jumps required to reach the end is `3`.

### Source Code
```cpp
class Solution {
public:
    // Recursive function to solve the problem with dynamic programming
    int solve(vector<int>& obstacles, int currlane, int currpos) {
        int n = obstacles.size() - 1; // The last position in the obstacles array
        // If we have reached the last position, no more jumps are needed
        if(currpos == n) return 0;

        // If the next position is not blocked by the current lane
        if(obstacles[currpos + 1] != currlane) {
            return solve(obstacles, currlane, currpos + 1); // Move to the next position without jumping
        } else {
            int ans = INT_MAX; // Initialize the answer to a large value (to minimize later)
            // Try all 3 lanes (1, 2, 3) to check for the minimum jumps
            for(int i = 1; i <= 3; i++) {
                // If the current lane is not the one we're trying, and the next lane is not blocked
                if(currlane != i && obstacles[currpos] != i) {
                    // Recursively solve the problem, with one additional jump (1 +)
                    ans = min(ans, 1 + solve(obstacles, i, currpos));
                }
            }
            return ans; // Return the minimum number of jumps found
        }
    }

    // Main function to return the minimum number of side jumps
    int minSideJumps(vector<int>& obstacles) {
        return solve(obstacles, 2, 0); // Start from lane 2 and position 0 (the first obstacle)
    }
};
```

### Source Code Explanation


```cpp
class Solution {
public:
    // Recursive function to solve the problem with dynamic programming
    int solve(vector<int>& obstacles, int currlane, int currpos) {
        int n = obstacles.size() - 1; // The last position in the obstacles array
```
- Here, `n` represents the total number of positions on the road. The obstacle array `obstacles` has a size of `n + 1`, so we subtract 1 to get the last position.

```cpp
        // If we have reached the last position, no more jumps are needed
        if(currpos == n) return 0;
```
- This is the base case: if we have reached the last position (`currpos == n`), no more jumps are needed, so we return `0`.

```cpp
        // If the next position is not blocked by the current lane
        if(obstacles[currpos + 1] != currlane) {
            return solve(obstacles, currlane, currpos + 1); // Move to the next position without jumping
        } else {
```
- If the next position (`currpos + 1`) is not blocked by an obstacle in the current lane (`obstacles[currpos + 1] != currlane`), we continue moving forward without jumping.

```cpp
            int ans = INT_MAX; // Initialize the answer to a large value (to minimize later)
            // Try all 3 lanes (1, 2, 3) to check for the minimum jumps
            for(int i = 1; i <= 3; i++) {
                // If the current lane is not the one we're trying, and the next lane is not blocked
                if(currlane != i && obstacles[currpos] != i) {
                    // Recursively solve the problem, with one additional jump (1 +)
                    ans = min(ans, 1 + solve(obstacles, i, currpos));
                }
            }
            return ans; // Return the minimum number of jumps found
        }
    }
```
- If the current lane is blocked at the next position, we try all three possible lanes (`1`, `2`, `3`). For each valid lane (i.e., if it’s not the same as the current lane and there is no obstacle), we make a recursive call and add `1` to account for the jump.
- We return the minimum number of jumps (`ans`).

```cpp
    // Main function to return the minimum number of side jumps
    int minSideJumps(vector<int>& obstacles) {
        return solve(obstacles, 2, 0); // Start from lane 2 and position 0 (the first obstacle)
    }
};
```
- The `minSideJumps` function is the entry point. We start from position `0` and lane `2` (a common strategy is to start from lane `2` as it gives more options to maneuver).

### Example Output Explanation

For the input `obstacles = [0, 1, 2, 2, 1, 0]`, the output is `3` because it takes 3 side jumps to reach the end.

1. Move from position 0 to position 1 (stay in lane 2).
2. Jump from lane 2 to lane 3 at position 1 (due to obstacle).
3. Jump from lane 3 to lane 1 at position 2.
4. Jump from lane 1 to lane 2 at position 3 (due to obstacle).
5. Move from position 4 to position 5 in lane 2 (no jump needed).

Thus, 3 jumps are required.

### Time and Space Complexities

**Time Complexity**:
- In the worst case, for each position, we check all three lanes, and each recursive call explores further subproblems. This leads to an exponential number of recursive calls, so the time complexity is `O(3^n)` where `n` is the length of the obstacles array.

**Space Complexity**:
- The space complexity is `O(n)` due to the recursion stack. In the worst case, the recursion depth can go as deep as `n`.

---

## Top-Down Approach (DP)
In this approach, we use **recursive calls** with **memoization** (also called **top-down dynamic programming**) to solve the problem. The idea is to recursively calculate the minimum jumps needed to reach the last position, while avoiding obstacles in the lanes. The key difference between this approach and the previous one is the use of a **memoization table (dp)** to store intermediate results and avoid redundant calculations, improving efficiency.

### Explanation of the Recursive Function with Memoization

The function `solve(vector<int>& obstacles, int currlane, int currpos, vector<vector<int>>& dp)` calculates the minimum number of jumps needed from position `currpos` on lane `currlane`. If the result for a given state (current lane and position) is already computed and stored in the `dp` table, it returns the cached value.

#### Key Concepts:

1. **Base Case**:
   - If `currpos == n`, it means we have reached the last position, and no more jumps are needed. We return `0`.

2. **Memoization**:
   - Before doing any further computation, we check if the result for the current state (lane and position) has already been computed and stored in the `dp` table. If it is not `-1`, we return the stored result to avoid recomputation.

3. **Recursive Logic**:
   - If the next position (`currpos + 1`) is not blocked by an obstacle in the current lane (`obstacles[currpos + 1] != currlane`), we can move to the next position without a jump. This is handled by making a recursive call.
   - If the current lane is blocked, we must find the best lane to jump to (either lane 1, 2, or 3). We try all possible lane choices and compute the jumps recursively for each valid lane, choosing the minimum result.

4. **Memoize the Result**:
   - After calculating the result for the current state, we store it in the `dp` table (`dp[currlane][currpos] = ans`) and return the result.

### Example Walkthrough

Let's use the same example to walk through this approach:

`obstacles = [0, 1, 2, 2, 1, 0]`

Here:
- `0` represents an empty lane.
- `1`, `2` represent obstacles in lanes 1 and 2, respectively.

We start at position 0, in lane 2, and try to move to the last position.

**Step-by-step Execution**:
1. **Position 0, Lane 2**:
   - The next position (1) is not blocked in lane 2 (`obstacles[1] = 1`), so we move to the next position without jumping.
   - Call `solve(obstacles, 2, 1, dp)`.

2. **Position 1, Lane 2**:
   - The next position (2) is blocked in lane 2 (`obstacles[2] = 2`), so we must jump to another lane.
   - Try jumping to lane 1 (blocked), so jump to lane 3.
   - Call `solve(obstacles, 3, 2, dp)`.

3. **Position 2, Lane 3**:
   - The next position (3) is blocked in lane 3 (`obstacles[3] = 2`), so we must jump again.
   - Try jumping to lane 1 or lane 2. Jump to lane 1.
   - Call `solve(obstacles, 1, 3, dp)`.

4. **Position 3, Lane 1**:
   - The next position (4) is blocked in lane 1 (`obstacles[4] = 1`), so we must jump again.
   - We can jump to lane 2.
   - Call `solve(obstacles, 2, 4, dp)`.

5. **Position 4, Lane 2**:
   - The next position (5) is free in lane 2, so we move forward without jumping.
   - Call `solve(obstacles, 2, 5, dp)`.

6. **Position 5, Lane 2**:
   - We have reached the last position, so no more jumps are needed.
   - Return `0`.

The minimum number of side jumps required to reach the last position is `3`.

### Source Code
```cpp
class Solution {
public:
    // Recursive function with memoization to solve the problem
    int solve(vector<int>& obstacles, int currlane, int currpos, vector<vector<int>>& dp) {
        int n = obstacles.size() - 1; // Last position in the obstacles array
        
        // Base case: If we have reached the last position, no more jumps are needed
        if(currpos == n) return 0;

        // If this state has already been computed, return the cached result from dp table
        if(dp[currlane][currpos] != -1) return dp[currlane][currpos];

        // If the next position is not blocked by the current lane, move to the next position without jumping
        if(obstacles[currpos + 1] != currlane) {
            return solve(obstacles, currlane, currpos + 1, dp);
        } else {
            int ans = INT_MAX; // Initialize the answer to a large value (for minimization)

            // Try all 3 possible lanes (1, 2, 3) and find the minimum side jump
            for(int i = 1; i <= 3; i++) {
                // If the current lane is not the lane we're trying to move to, and the next lane is not blocked
                if(currlane != i && obstacles[currpos] != i) {
                    // Recursively calculate the number of jumps, adding 1 for the jump
                    ans = min(ans, 1 + solve(obstacles, i, currpos, dp));
                }
            }

            // Store the result in the dp table to avoid recomputation and return the answer
            return dp[currlane][currpos] = ans;
        }
    }

    // Main function to return the minimum number of side jumps
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size(); // Get the size of the obstacles array
        
        // Initialize the dp table with -1 (indicating uncomputed states)
        // dp[i][j] represents the minimum jumps needed from lane i at position j
        vector<vector<int>> dp(4, vector<int>(n - 1, -1)); 

        // Start from lane 2 and position 0, then call the recursive solve function
        return solve(obstacles, 2, 0, dp);
    }
};

```

### Source Code Explanation

```cpp
class Solution {
public:
    // Recursive function with memoization to solve the problem
    int solve(vector<int>& obstacles, int currlane, int currpos, vector<vector<int>>& dp) {
        int n = obstacles.size() - 1; // Last position in the obstacles array
```
- `n` represents the total number of positions on the road (size of the obstacle array minus one).

```cpp
        // Base case: If we have reached the last position, no more jumps are needed
        if(currpos == n) return 0;
```
- This is the base case: if we reach the last position (`currpos == n`), no more jumps are needed, so we return `0`.

```cpp
        // If this state has already been computed, return the cached result from dp table
        if(dp[currlane][currpos] != -1) return dp[currlane][currpos];
```
- Here, we check if the result for the current state (current lane and position) has already been computed and stored in the `dp` table. If the value is not `-1`, we return the cached result to avoid recomputation.

```cpp
        // If the next position is not blocked by the current lane, move to the next position without jumping
        if(obstacles[currpos + 1] != currlane) {
            return solve(obstacles, currlane, currpos + 1, dp);
        } else {
```
- If the next position is not blocked by an obstacle in the current lane (`obstacles[currpos + 1] != currlane`), we can move forward without jumping.

```cpp
            int ans = INT_MAX; // Initialize the answer to a large value (for minimization)

            // Try all 3 possible lanes (1, 2, 3) and find the minimum side jump
            for(int i = 1; i <= 3; i++) {
                // If the current lane is not the lane we're trying to move to, and the next lane is not blocked
                if(currlane != i && obstacles[currpos] != i) {
                    // Recursively calculate the number of jumps, adding 1 for the jump
                    ans = min(ans, 1 + solve(obstacles, i, currpos, dp));
                }
            }
```
- If the current lane is blocked at the next position, we must try all possible lane jumps (lanes 1, 2, and 3). For each valid lane, we make a recursive call, adding `1` for the jump.

```cpp
            // Store the result in the dp table to avoid recomputation and return the answer
            return dp[currlane][currpos] = ans;
        }
    }
```
- After calculating the result for the current state (minimum number of jumps), we store it in the `dp` table (`dp[currlane][currpos] = ans`) and return the result.

```cpp
    // Main function to return the minimum number of side jumps
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size(); // Get the size of the obstacles array
        
        // Initialize the dp table with -1 (indicating uncomputed states)
        // dp[i][j] represents the minimum jumps needed from lane i at position j
        vector<vector<int>> dp(4, vector<int>(n - 1, -1)); 

        // Start from lane 2 and position 0, then call the recursive solve function
        return solve(obstacles, 2, 0, dp);
    }
};
```
- In the `minSideJumps` function:
  - We initialize a `dp` table of size `4 x (n-1)` to store the minimum number of jumps from each lane at each position.
  - We start from lane 2 and position 0 and call the `solve` function to calculate the minimum side jumps.

### Example Output Explanation

For the input `obstacles = [0, 1, 2, 2, 1, 0]`, the output is `3` because it takes 3 side jumps to reach the end.

1. Move from position 0 to position 1 (stay in lane 2).
2. Jump from lane 2 to lane 3 at position 1 (due to obstacle).
3. Jump from lane 3 to lane 1 at position 2.
4. Jump from lane 1 to lane 2 at position 3 (due to obstacle).
5. Move from position 4 to position 5 in lane 2 (no jump needed).

Thus, 3 jumps are required.

### Time and Space Complexities

**Time Complexity**:
- Each position and lane pair is computed only once due to memoization. The total number of possible states is `3 * (n - 1)` (3 lanes and `n - 1` positions), so the time complexity is `O(n)`.

**Space Complexity**:
- The space complexity is `O(3 * n)` for the `dp` table, which stores the minimum number of jumps for each lane and position. Thus, the space complexity is `O(n)`.


---

## Bottom-Up Approach (DP)
In the **Bottom-Up Approach**, we solve the problem iteratively starting from the last position (`n`) and work our way towards the first position (`0`). The approach ensures that we build the solution step-by-step, storing the minimum jumps required for each position and lane in a `dp` table. This helps avoid redundant calculations by using previously computed values to make decisions at each step.

### **Problem Understanding**
We are given an array `obstacles[]` where each element in the array represents the lane number at that position (`1`, `2`, or `3`), and `0` means the lane is free of obstacles. Our goal is to find the minimum number of side jumps required to reach the end of the array from the starting position.

The **Bottom-Up Approach** involves solving a problem iteratively, starting from the smallest or simplest subproblem and working upwards to solve the entire problem. This approach is commonly used with dynamic programming (DP) problems.

In the context of the **minimum side jumps problem**, we aim to compute the minimum number of side jumps required to avoid obstacles in a lane. Let’s break down the steps of the bottom-up approach and illustrate them with an example.

### **Problem Recap**

Given an array `obstacles[]` where:
- `obstacles[i] = 0`: Lane is free of obstacles at position `i`.
- `obstacles[i] = 1`, `2`, or `3`: Lane `1`, `2`, or `3` is blocked at position `i`.

We start at position `0` in lane `2`, and we need to find the minimum number of side jumps to reach the end (`n-1`) in any lane.

### **Example**

Consider the following `obstacles[]` array:
```cpp
obstacles = {0, 1, 2, 3, 0}
```

Here:
- Position 0: No obstacle in any lane (0).
- Position 1: Lane 1 is blocked.
- Position 2: Lane 2 is blocked.
- Position 3: Lane 3 is blocked.
- Position 4: No obstacle in any lane.

### **Step-by-Step Bottom-Up Approach**

1. **Initialization:**
   - We create a DP table `dp` where each cell `dp[lane][pos]` represents the minimum number of jumps needed to reach the end (`n-1`) from position `pos` in `lane`.
   - Set all values in `dp` to a large number (`1e9`), representing an impossible state, except the last position (`n-1`) where no jumps are needed.

2. **Base Case (At the last position):**
   - Since we are already at the end (`n-1`), we initialize the DP table for the last position. At position `n-1`, no more jumps are required, so all lanes have 0 jumps.

   ```
   dp = [
     [1e9, 1e9, 1e9, 0],
     [1e9, 1e9, 1e9, 0],
     [1e9, 1e9, 1e9, 0],
     [1e9, 1e9, 1e9, 0]
   ]
   ```

3. **Iterate Backwards:**
   - We start iterating from the second-last position (`n-2`) and move to the first position (`0`).
### Source Code
```cpp
class Solution {
public:
    // Function to solve the problem using dynamic programming
    int solve(vector<int>& obstacles) {
        int n = obstacles.size() - 1; // Get the last position in the obstacles array
        // Initialize the dp table with large values (1e9), where dp[lane][pos] represents the minimum jumps required
        // to reach the end from position 'pos' in 'lane'.
        vector<vector<int>> dp(4, vector<int>(n + 1, 1e9));

        // Base case: at the last position (n), no more jumps are needed, hence 0 jumps for all lanes
        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        // Iterate from the second-last position to the start of the array
        for(int pos = n - 1; pos >= 0; pos--) {
            // Try all 3 lanes (1, 2, 3) for each position
            for(int lane = 1; lane <= 3; lane++) {

                // If the next position is not blocked by the current lane, no jump is needed
                if(obstacles[pos + 1] != lane) {
                    dp[lane][pos] = dp[lane][pos + 1]; // Carry over the result from the next position
                } else {
                    // If the next position is blocked, we need to jump to a different lane
                    int ans = 1e9; // Initialize the answer to a large value (to minimize later)

                    // Try all 3 possible lanes (1, 2, 3) to find the best jump option
                    for(int i = 1; i <= 3; i++) {
                        // If the current lane is not the lane we're trying to jump to, and the lane is not blocked
                        if(lane != i && obstacles[pos] != i) {
                            // Add 1 for the jump and update the answer with the minimum jumps required
                            ans = min(ans, 1 + dp[i][pos + 1]);
                        }
                    }
                    dp[lane][pos] = ans; // Store the result for this position and lane
                }
            }
        }

        // Return the minimum jumps required starting from position 0 with lane 2.
        // We also consider the case where we might need one jump to lane 1 or lane 3.
        return min({dp[2][0], dp[1][0] + 1, dp[3][0] + 1});
    }

    // Main function to return the minimum number of side jumps
    int minSideJumps(vector<int>& obstacles) {
        return solve(obstacles); // Call the solve function to get the result
    }
};
```

### Source Code Explanation

#### **1. Function Declaration**
```cpp
int solve(vector<int>& obstacles) {
```
- The function `solve` takes in a vector `obstacles[]` representing the obstacles in the lanes at different positions. This vector will help us determine which lanes are blocked or open.

#### **2. Get the Last Position**
```cpp
int n = obstacles.size() - 1; // Get the last position in the obstacles array
```
- We get the last position in the array (`n`), because the array is 0-indexed. This position will be used to set up base cases for the DP table.

#### **3. Initialize DP Table**
```cpp
vector<vector<int>> dp(4, vector<int>(n + 1, 1e9));
```
- We create a 2D DP table `dp` with 4 rows (representing 3 lanes plus an extra lane to make indexing easier). Each column represents a position from `0` to `n`.
- We initialize all values to a very large number (`1e9`), representing the worst-case scenario, where we assume initially that we cannot reach the end from any position and lane.

#### **4. Base Case Setup**
```cpp
dp[0][n] = 0;
dp[1][n] = 0;
dp[2][n] = 0;
dp[3][n] = 0;
```
- These are the base cases where we reach the last position (`n`), which means no more jumps are required. For every lane at the last position, we set the value to `0` (since we are already at the destination).

#### **5. Iterating Over Positions**
```cpp
for (int pos = n - 1; pos >= 0; pos--) {
```
- We iterate backwards over each position from `n - 1` to `0`. This is because we need to compute the minimum jumps to reach the end starting from each position, and this approach ensures that we always have the results for future positions when needed.

#### **6. Iterating Over Lanes**
```cpp
for (int lane = 1; lane <= 3; lane++) {
```
- For each position, we check each of the 3 lanes (`1`, `2`, `3`). We try to compute the minimum number of jumps for every lane at each position.

#### **7. Check if the Lane is Blocked**
```cpp
if (obstacles[pos + 1] != lane) {
    dp[lane][pos] = dp[lane][pos + 1]; // Carry over the result from the next position
}
```
- If the lane is not blocked at the next position (`obstacles[pos + 1] != lane`), then we don’t need to jump. We can carry forward the value from the next position without any extra jumps.

#### **8. If the Lane is Blocked**
```cpp
else {
    int ans = 1e9; // Initialize the answer to a large value (to minimize later)

    // Try all 3 possible lanes (1, 2, 3) to find the best jump option
    for (int i = 1; i <= 3; i++) {
        if (lane != i && obstacles[pos] != i) {
            ans = min(ans, 1 + dp[i][pos + 1]);
        }
    }
    dp[lane][pos] = ans; // Store the result for this position and lane
}
```
- If the lane is blocked, we need to jump to another lane. For each of the 3 lanes (`1`, `2`, and `3`), we check if the lane is not blocked at the current position and calculate the minimum number of jumps required by trying each of these lanes.
- We store the result in the `dp[lane][pos]` cell.

#### **9. Return the Minimum Jumps**
```cpp
return min({dp[2][0], dp[1][0] + 1, dp[3][0] + 1});
```
- Finally, we return the minimum number of jumps needed to reach the end starting from position `0`. We check for the three lanes (lane `2` is the initial starting lane, while lanes `1` and `3` might require one extra jump to reach lane `2`).

### **Step-by-Step Example Walkthrough:**

For the given `obstacles[] = {0, 1, 2, 3, 0}`, let’s break down the steps from position 3 to position 0.

#### At position 3:
- **Lane 1**: 
  - `obstacles[4] = 0`, so lane 1 is not blocked at position 4.
  - We can move to lane 1, so `dp[1][3] = dp[1][4] = 0` (no jumps needed).
- **Lane 2**:
  - `obstacles[4] = 0`, so lane 2 is not blocked at position 4.
  - We can move to lane 2, so `dp[2][3] = dp[2][4] = 0`.
- **Lane 3**:
  - `obstacles[4] = 0`, so lane 3 is not blocked at position 4.
  - We can move to lane 3, so `dp[3][3] = dp[3][4] = 0`.

At this point, the DP table is:
```cpp
dp = [
  [1e9, 1e9, 1e9, 0],
  [1e9, 1e9, 1e9, 0],
  [1e9, 1e9, 1e9, 0],
  [1e9, 1e9, 1e9, 0]
]
```

#### At position 2:
- **Lane 1**:
  - Lane 1 is blocked (`obstacles[3] = 3`), so we need to jump to either lane 2 or lane 3.
  - We check both possibilities:
    - Jump to lane 2: `dp[2][3] = 0`, so `dp[1][2] = 1 + dp[2][3] = 1`.
    - Jump to lane 3: `dp[3][3] = 0`, so `dp[1][2] = 1 + dp[3][3] = 1`.
  - We choose the minimum of these options: `dp[1][2] = 1`.

- **Lane 2**:
  - Lane 2 is blocked (`obstacles[3] = 3`), so we need to jump to lane 1 or lane 3.
  - We check both possibilities:
    - Jump to lane 1: `dp[1][3] = 0`, so `dp[2][2] = 1 + dp[1][3] = 1`.
    - Jump to lane 3: `dp[3][3] = 0`, so `dp[2][2] = 1 + dp[3][3] = 1`.
  - We choose the minimum of these options: `dp[2][2] = 1`.

- **Lane 3**:
  - Lane 3 is blocked (`obstacles[3] = 3`), so we need to jump to either lane 1 or lane 2.
  - We check both possibilities:
    - Jump to lane 1: `dp[1][3] = 0`, so `dp[3][2] = 1 + dp[1][3] = 1`.
    - Jump to lane 2: `dp[2][3] = 0`, so `dp[3][2] = 1 + dp[2][3] = 1`.
  - We choose the minimum of these options: `dp[3][2] = 1`.

At this point, the DP table is:
```cpp
dp = [
  [1e9, 1e9, 1e9, 0],
  [1e9, 1e9, 1, 0],
  [1e9, 1e9, 1, 0],
  [1e9, 1e9, 1, 0]
]
```

#### At position 1:
- **Lane 1**:
  - Lane 1 is blocked (`obstacles[2] = 2`), so we need to jump to either lane 2 or lane 3.
  - We check both possibilities:
    - Jump to lane 2: `dp[2][2] = 1`, so `dp[1][1] = 1 + dp[2][2] = 2`.
    - Jump to lane 3: `dp[3][2] = 1`, so `dp[1][1] = 1 + dp[3][2] = 2`.
  - We choose the minimum of these options: `dp[1][1] = 2`.

- **Lane 2**:
  - Lane 2 is blocked (`obstacles[2] = 2`), so we need to jump to either lane 1 or lane 3.
  - We check both possibilities:
    - Jump to lane 1: `dp[1][2] = 1`, so `dp[2][1] = 1 + dp[1][2] = 2`.
    - Jump to lane 3: `dp[3][2] = 1`, so `dp[2][1] = 1 + dp[3][2] = 2`.
  - We choose the minimum of these options: `dp[2][1] = 2`.

- **Lane 3**:
  - Lane 3 is blocked (`obstacles[2] = 2`), so we need to jump to either lane 1 or lane 2.
  - We check both possibilities:
    - Jump to lane 1: `dp[1][2] = 1`, so `dp[3][1] = 1 + dp[1][2] = 2`.
    - Jump to lane 2: `dp[2][2] = 1`, so `dp[3][1] = 1 + dp[2][2] = 2`.
  - We choose the minimum of these options: `dp[3][1] = 2`.

At this point, the DP table is:
```cpp
dp = [
  [1e9, 1e9, 1e9, 0],
  [1e9, 2, 1, 0],
  [1e9, 2, 1, 0],
  [1e9, 2, 1, 0]
]
```

#### At position 0 (Final Step):
- **Lane 1**:
  - Lane 1 is free (`obstacles[1] = 1`), so we can move to lane 1.
  - `dp[1][0] = dp[1][1] = 2`.

- **Lane 2**:
  - Lane 2 is free (`obstacles[1] = 1`), so we can move to lane 2.
  - `dp[2][0] = dp[2][1] = 2`.

- **Lane 3**:
  - Lane 3 is free (`obstacles[1] = 1`), so we can move to lane 3.
  - `dp[3][0] = dp[3][1] = 2`.

### **Final Output**

The final DP table will look like this:
```cpp
dp = [
  [1e9, 1e9, 1e9, 0],
  [1e9, 2, 1, 0],
  [1e9, 2, 1, 0],
  [1e9, 2, 1, 0]
]
```

The minimum number of jumps to reach the last position from position 0 is `dp[2][0] = 2`. Therefore, the output is **2**.

### **Time and Space Complexity**

#### **Time Complexity:**
- We iterate over each position (`n` positions), and for each position, we check all 3 lanes. For each lane, we check the next possible lanes (3 possibilities).
- Therefore, the time complexity is `O(3 * n) = O(n)`.

#### **Space Complexity:**
- We use a `dp` table of size `4 x (n + 1)`. Thus, the space complexity is `O(4 * (n + 1)) = O(n)`.

### **Summary**

- The bottom-up approach solves the problem by filling in a DP table starting from the last position.
- At each position and lane, we calculate the minimum number of jumps by considering the next possible steps.


---

## Space Optimized Approach (DP)

The **space optimization** approach in dynamic programming involves reducing the amount of memory required to store intermediate results. Normally, in dynamic programming, we might use a table or matrix to store results for all subproblems, but in many cases, it's possible to only store the current state and the next state, eliminating the need for the full table.

In this problem, we are concerned with finding the minimum number of side jumps needed to move from the start (position 0) to the end (position n-1) while avoiding obstacles. At each position, we can either stay in the same lane or jump to another lane. Using dynamic programming, we store the minimum side jumps required to reach the end from any given position and lane.

### Key Idea of Space Optimization:
- Instead of storing the entire DP table, which might be large, we only store the current state (`curr`) and the next state (`next`) for each lane (lane 1, 2, and 3).
- By only storing the necessary data for the current and next position, we optimize space usage and keep it constant, reducing the space complexity to O(1).

### Example Walkthrough of Space Optimization:

Consider the `obstacles = [0, 1, 2, 3, 0]` array.

#### Problem:
We need to calculate the minimum number of side jumps needed to reach the last position while avoiding blocked lanes. 
- `0` means no lane is blocked at that position.
- `1`, `2`, or `3` means that lane is blocked at that position.

#### Explanation of Space Optimization with Example:

1. **Initialization**:
   - We initialize two arrays: `curr` and `next`. Both arrays have 4 elements because there are 3 lanes and 1 unused element (index 0).
   - `next` array is initialized to `[0, 0, 0, 0]` because at the last position (n-1), no jumps are needed, so all lanes have a value of 0.

2. **Iterating from position n-1 to 0**:
   - For each position from n-1 to 0, we calculate the minimum jumps required for each lane.
   - At each position, we check if the next position is blocked for a lane, and if it is, we calculate the minimum jumps needed by trying different possible lanes.

3. **Updating Current State**:
   - After processing the lanes for each position, we copy the `curr` array to the `next` array to update the state for the next iteration.
   - This way, we only store the information for the current and next positions.

4. **Final Answer**:
   - After iterating through the entire array, we return the minimum number of jumps from `curr[1]`, `curr[2]`, and `curr[3]` (the three lanes).

### Source Code
```cpp
class Solution {
public:
    // Function to solve the problem using dynamic programming with space optimization
    int solve(vector<int>& obstacles) {
        int n = obstacles.size() - 1; // Get the last position in the obstacles array

        // Create two vectors to represent the current and next state of the dp table
        // curr[lane] represents the minimum jumps required from the current position in the lane.
        // next[lane] represents the minimum jumps required from the next position in the lane.
        vector<int> curr(4, INT_MAX); // Initialize the current state with large values (INT_MAX).
        vector<int> next(4, INT_MAX); // Initialize the next state with large values (INT_MAX).

        // At the last position (n), no jumps are needed, so we set all lanes to 0
        next[0] = 0;
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;

        // Iterate from the second-last position to the start of the array
        for (int pos = n - 1; pos >= 0; pos--) {
            // Try all 3 lanes (1, 2, 3) for each position
            for (int lane = 1; lane <= 3; lane++) {

                // If the next position is not blocked by the current lane, no jump is needed
                if (obstacles[pos + 1] != lane) {
                    curr[lane] = next[lane]; // Carry over the result from the next position
                } else {
                    // If the next position is blocked, we need to jump to a different lane
                    int ans = INT_MAX; // Initialize the answer to a large value (to minimize later)

                    // Try all 3 possible lanes (1, 2, 3) to find the best jump option
                    for (int i = 1; i <= 3; i++) {
                        // If the current lane is not the lane we're trying to jump to, and the lane is not blocked
                        if (lane != i && obstacles[pos] != i) {
                            // Add 1 for the jump and update the answer with the minimum jumps required
                            ans = min(ans, 1 + next[i]);
                        }
                    }

                    // Store the minimum jumps required for this position and lane in the curr array
                    curr[lane] = ans;
                }
            }

            // After processing all lanes for this position, move the next state to curr
            next = curr;
        }

        // Return the minimum side jumps required starting from position 0 with lane 2.
        // We also consider the case where we might need one jump to lane 1 or lane 3.
        return min({curr[2], curr[1] + 1, curr[3] + 1});
    }

    // Main function to return the minimum number of side jumps
    int minSideJumps(vector<int>& obstacles) {
        return solve(obstacles); // Call the solve function to get the result
    }
};
```

### Source Code Explanation

```cpp
class Solution {
public:
    // Function to solve the problem using dynamic programming with space optimization
    int solve(vector<int>& obstacles) {
```
- **Purpose**: This is the start of the `Solution` class. The `solve` function will contain the logic to compute the minimum number of side jumps needed to avoid obstacles.
- **Example**: We pass an array `obstacles = [0, 1, 2, 3, 0]` which represents the lanes blocked at each position.


```cpp
        int n = obstacles.size() - 1; // Get the last position in the obstacles array
```
- **Purpose**: We determine `n`, the last index of the obstacles array. Since we start from the second-to-last position and move backwards, `n` will help define the bounds of our iterations.
- **Example**: `n = obstacles.size() - 1 = 4`. So, the last position (index 4) is at the 5th element of the array.


```cpp
        // Create two vectors to represent the current and next state of the dp table
        vector<int> curr(4, INT_MAX); // Initialize the current state with large values (INT_MAX).
        vector<int> next(4, INT_MAX); // Initialize the next state with large values (INT_MAX).
```
- **Purpose**: We create two vectors `curr` and `next`, each of size 4 (for lanes 1, 2, and 3, plus an unused entry at index 0).
  - `curr`: stores the minimum jumps required for the current position and lane.
  - `next`: stores the minimum jumps required for the next position and lane.
- **Example**: Both `curr` and `next` are initially set to `[INT_MAX, INT_MAX, INT_MAX, INT_MAX]` (indicating no valid paths have been calculated yet).

```cpp
        // At the last position (n), no jumps are needed, so we set all lanes to 0
        next[0] = 0;
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;
```
- **Purpose**: Since at the last position (position `n`), no jumps are needed to continue, we set `next[1]`, `next[2]`, and `next[3]` to 0. This is the base case for the dynamic programming approach.
- **Example**: `next = [0, 0, 0, 0]`, which means at the last position, no further side jumps are needed.


```cpp
        // Iterate from the second-last position to the start of the array
        for (int pos = n - 1; pos >= 0; pos--) {
```
- **Purpose**: We start iterating backward from position `n-1` down to position 0. The reason for iterating backward is that we want to calculate the minimum number of jumps to the end, which means calculating it starting from the end and moving backward.
- **Example**: `pos = 3, 2, 1, 0` are the positions we will check.


```cpp
            // Try all 3 lanes (1, 2, 3) for each position
            for (int lane = 1; lane <= 3; lane++) {
```
- **Purpose**: For each position, we will try all 3 possible lanes (1, 2, and 3) and calculate the minimum number of side jumps required to move from that position in that lane to the end.
- **Example**: At `pos = 3`, we will check lane 1, lane 2, and lane 3.

```cpp
                // If the next position is not blocked by the current lane, no jump is needed
                if (obstacles[pos + 1] != lane) {
                    curr[lane] = next[lane]; // Carry over the result from the next position
                }
```
- **Purpose**: If the lane at the next position is not blocked by an obstacle, no side jump is needed, so we carry over the result from the `next` array.
  - If `obstacles[pos + 1] != lane`, the next position in the lane is not blocked, so we can simply carry the value from `next[lane]` to `curr[lane]`.
- **Example**: If `pos = 3` and `lane = 2`, and `obstacles[4] != 2`, we would carry the value of `next[2]` (which is 0) to `curr[2]`.


```cpp
                else {
                    // If the next position is blocked, we need to jump to a different lane
                    int ans = INT_MAX; // Initialize the answer to a large value (to minimize later)
```
- **Purpose**: If the lane at the next position is blocked by an obstacle, we need to jump to a different lane. We initialize `ans` to a very large value (INT_MAX) so that we can later minimize it.
- **Example**: If `obstacles[pos + 1] == 2`, we will try jumping to a different lane, and `ans` will be used to store the minimum number of jumps required.


```cpp
                    // Try all 3 possible lanes (1, 2, 3) to find the best jump option
                    for (int i = 1; i <= 3; i++) {
                        // If the current lane is not the lane we're trying to jump to, and the lane is not blocked
                        if (lane != i && obstacles[pos] != i) {
                            // Add 1 for the jump and update the answer with the minimum jumps required
                            ans = min(ans, 1 + next[i]);
                        }
                    }
```
- **Purpose**: This inner loop checks all 3 lanes to find the best jump option.
  - We are trying to jump to a lane `i` that is not the current lane (`lane != i`), and the lane `i` should not be blocked at the current position (`obstacles[pos] != i`).
  - For each valid jump, we add 1 to the `next[i]` (because we need to count the jump), and update `ans` with the minimum number of jumps found.
- **Example**: If we are at `pos = 3` in lane 1, and lane 2 is blocked, we will try jumping to lane 3 or lane 1, and select the best option.


```cpp
                    // Store the minimum jumps required for this position and lane in the curr array
                    curr[lane] = ans;
                }
            }
```
- **Purpose**: After processing all possible lane jumps for the current position, we store the minimum number of side jumps required for each lane in `curr[lane]`.
- **Example**: After checking all lanes, `curr` will contain the minimum jumps required to get to the end from the current position.


```cpp
            // After processing all lanes for this position, move the next state to curr
            next = curr;
        }
```
- **Purpose**: After processing all positions for the current iteration, we move the current state `curr` to the `next` array, so it will be used for the next iteration.
- **Example**: After processing position 3, `curr` is moved to `next` to be used for position 2.

```cpp
        // Return the minimum side jumps required starting from position 0 with lane 2.
        // We also consider the case where we might need one jump to lane 1 or lane 3.
        return min({curr[2], curr[1] + 1, curr[3] + 1});
    }
```
- **Purpose**: Finally, we return the minimum number of side jumps required starting from position 0.
  - We start from lane 2 (because lane 2 is the most direct path) and check if a jump is needed to lane 1 or lane 3.
- **Example**: At the end, `curr[2]`, `curr[1] + 1`, and `curr[3] + 1` represent the best possible side jumps for position 0, starting in lanes 2, 1, and 3, respectively.


### Example Input and Output

#### Example:
Input:
```cpp
obstacles = [0, 1, 2, 3, 0]
```

#### Walkthrough:
1. At position 4 (last position), no jumps are needed.
2. At position 3, lane 3 is blocked, so we jump to lane 2 or lane 1.
3. At position 2, lane 2 is blocked, so we jump to lanes 1 or 3.
4. At position 1, lane 1 is blocked, so we jump to lanes 2 or 3.
5. At position 0, we choose the minimum of lane 2, lane 1 + 1, or lane 3 + 1.

#### Output:
```cpp
minSideJumps(obstacles) = 2
```

### Time Complexity:
- **O(n)**: We iterate over the `obstacles` array once, and for each position, we check all 3 lanes, resulting in O(n) time complexity.

### Space Complexity:
- **O(1)**: Since we are using a fixed-size array of length 4 for `curr` and `next`, the space complexity is constant.
