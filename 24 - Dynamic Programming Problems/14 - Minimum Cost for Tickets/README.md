<h1 align="center">Minimum - Cost for - Tickets</h1>

## Problem Statement

**Problem URL :** [Minimum Cost for Tickets](https://leetcode.com/problems/minimum-cost-for-tickets/description/)

![image](https://github.com/user-attachments/assets/56a32138-930b-48a8-8c7f-712d4f666ddf)

### Problem Explanation
The problem you're referring to is **Minimum Cost for Tickets** on LeetCode. Let's break it down in simple terms so that it's easy to understand. Here's a detailed explanation with an example to guide you through the thought process:

You are given two arrays:
1. **days**: This array contains the days you are traveling. For example, `[1, 4, 6, 7, 8, 20]` means you are traveling on the 1st, 4th, 6th, 7th, 8th, and 20th days of the month.
2. **costs**: This array contains the cost of different types of travel passes:
   - `costs[0]`: Cost of a **1-day** pass.
   - `costs[1]`: Cost of a **7-day** pass.
   - `costs[2]`: Cost of a **30-day** pass.

You want to minimize the total cost of your tickets while covering all the days you need to travel.

### **Objective:**
Find the minimum cost to travel on all the days in the `days` array using one or more of the available passes (1-day, 7-day, or 30-day).

### **Pass Description:**
- A **1-day pass** allows you to travel on any single day for a specific cost.
- A **7-day pass** allows you to travel for 7 consecutive days starting from any day, for a specific cost.
- A **30-day pass** allows you to travel for 30 consecutive days starting from any day, for a specific cost.

You are allowed to purchase any number of passes, but you must choose the minimum cost option that covers all your travel days.

### **Approach to Solve:**

1. **Dynamic Programming**: This problem can be solved using dynamic programming (DP) because we want to find the minimum cost to cover all the travel days, considering different combinations of passes. 

2. **Subproblem**: At each day, we can choose:
   - To buy a 1-day pass for that day.
   - To buy a 7-day pass that covers that day.
   - To buy a 30-day pass that covers that day.

3. **State Definition**:
   Let `dp[i]` represent the minimum cost to cover all the days from day 1 to the `i`th day. Our goal is to compute `dp[n]`, where `n` is the last day in the `days` array.

4. **Transition**:
   For each day `i`, we decide which pass to buy. The options are:
   - If we buy a 1-day pass on day `i`, the total cost will be `dp[i-1] + costs[0]`.
   - If we buy a 7-day pass on day `i`, we need to find the first day that is 7 days before `i` and calculate the cost from that day, which will be `dp[first_day_7] + costs[1]`.
   - If we buy a 30-day pass on day `i`, we need to find the first day that is 30 days before `i` and calculate the cost from that day, which will be `dp[first_day_30] + costs[2]`.

5. **Base Case**: 
   - We start with `dp[0] = 0` because no cost is required if we don't travel.
   
6. **Final Result**: 
   The final answer will be stored in `dp[n]`, which is the minimum cost to cover all the travel days.


### **Example to Understand:**

Let’s go through an example to see how this works:

#### Input:
- `days = [1, 4, 6, 7, 8, 20]`
- `costs = [2, 7, 15]`

#### Step-by-Step Calculation:

1. **Initialize DP array**:  
   We will create a DP array `dp` where each index represents the minimum cost to cover up to that day.
   - `dp[i]` will store the minimum cost for covering travel days from `days[0]` to `days[i]`.

   Initially:
   - `dp[0] = 0` (no cost to cover no days).
   - The rest of the `dp` array is filled with large values (infinity).

2. **Start from the first day (Day 1)**:
   We start calculating for each day in the `days` array. For each day, we check the costs for 1-day, 7-day, and 30-day passes and update the DP array accordingly.

   - **Day 1**: We can only buy a 1-day pass because it's the first day.
     - `dp[1] = dp[0] + costs[0] = 0 + 2 = 2`

   - **Day 4**: We can buy a 1-day pass for day 4 or a 7-day pass that covers days 1 to 7.
     - `dp[4] = min(dp[3] + costs[0], dp[0] + costs[1]) = min(2 + 2, 0 + 7) = 7`

   - **Day 6**: We can buy a 1-day pass for day 6, a 7-day pass that covers days 4-6, or a 30-day pass that covers the entire month.
     - `dp[6] = min(dp[5] + costs[0], dp[1] + costs[1], dp[0] + costs[2]) = min(7 + 2, 2 + 7, 0 + 15) = 9`

   - **Day 7**: Same as before, we can buy a 1-day, 7-day, or 30-day pass.
     - `dp[7] = min(dp[6] + costs[0], dp[0] + costs[1], dp[0] + costs[2]) = min(9 + 2, 0 + 7, 0 + 15) = 7`

   - **Day 8**: We continue checking the cost for all passes.
     - `dp[8] = min(dp[7] + costs[0], dp[1] + costs[1], dp[0] + costs[2]) = min(7 + 2, 2 + 7, 0 + 15) = 9`

   - **Day 20**: Again, we check all the possibilities and find the minimum.
     - `dp[20] = min(dp[19] + costs[0], dp[13] + costs[1], dp[0] + costs[2]) = min(18 + 2, 7 + 7, 0 + 15) = 15`

#### Final DP array:
After processing all the days, we find the minimum cost to travel on all the days is stored at the last index of the DP array, which is `dp[n]`.

### **Output:**
For the given example, the minimum cost to cover all the travel days would be **9**.

### **Final Thoughts:**
This problem requires us to think about optimizing the cost of travel over multiple days with overlapping periods of coverage (7-day and 30-day passes). Dynamic programming allows us to efficiently solve this problem by breaking it into subproblems and reusing the results of previous calculations to build the solution incrementally.

---

## Recursive Approach (caused TLE)
The problem you are dealing with is about finding the minimum cost for covering all travel days using 1-day, 7-day, or 30-day passes. The recursive approach tries to solve this problem by considering all possible choices for each day (whether to buy a 1-day, 7-day, or 30-day pass) and recursively calculating the minimum cost.

### **Intuition Behind the Recursive Approach**

1. **Recursive Breakdown**: At each travel day, you have three options:
   - **1-Day Pass**: This covers only the current day, so you calculate the cost for the current day and recursively solve the problem for the remaining days.
   - **7-Day Pass**: This covers 7 days starting from the current day, so you find the first day that is not covered by this 7-day pass and recursively solve the problem from that day.
   - **30-Day Pass**: Similarly, this covers 30 days starting from the current day. You find the first day that is not covered and recursively solve the problem from that day.

2. **Base Case**: When the index goes beyond the last day (i.e., the day you're checking is out of bounds), you return a cost of `0` because there are no more days to travel.

3. **Recursive Formula**: The recursive function tries to evaluate the total cost by considering all three pass options and picks the one with the minimum cost.

### Source Code
```cpp
class Solution {
public:
    // Recursive function to calculate the minimum cost starting from 'index'
    int getMinCost(vector<int>& days, vector<int>& costs, int n, int index) {
        // Base case: if the index is out of bounds, there is no cost
        if (index >= n) 
            return 0;

        // **Cost for a 1-day pass**:
        // Recursively calculate the cost for the next day and add the cost of a 1-day pass
        int cost1 = getMinCost(days, costs, n, index + 1) + costs[0];
        
        // **Cost for a 7-day pass**:
        // Move forward to the first day that is not covered by a 7-day pass
        int i; 
        for (i = index; i < n && days[i] < days[index] + 7; i++);
        // Recursively calculate the cost from that day and add the cost of a 7-day pass
        int cost7 = getMinCost(days, costs, n, i) + costs[1];
        
        // **Cost for a 30-day pass**:
        // Move forward to the first day that is not covered by a 30-day pass
        for (i = index; i < n && days[i] < days[index] + 30; i++);
        // Recursively calculate the cost from that day and add the cost of a 30-day pass
        int cost30 = getMinCost(days, costs, n, i) + costs[2];

        // Return the minimum of the three costs
        return min(cost1, min(cost7, cost30));
    }

    // Main function to calculate the minimum cost of traveling
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // Start the calculation from the first day
        return getMinCost(days, costs, days.size(), 0);
    }
};
```

### Source Code Explanation

Here’s a detailed explanation of the given code.

```cpp
class Solution {
public:
    // Recursive function to calculate the minimum cost starting from 'index'
    int getMinCost(vector<int>& days, vector<int>& costs, int n, int index) {
        // Base case: if the index is out of bounds, there is no cost
        if (index >= n) 
            return 0;
```
- **Base Case**: If `index >= n`, which means you've processed all the days, the cost is `0`. This is the condition for the recursive function to stop.

```cpp
        // **Cost for a 1-day pass**:
        // Recursively calculate the cost for the next day and add the cost of a 1-day pass
        int cost1 = getMinCost(days, costs, n, index + 1) + costs[0];
```
- **Cost for a 1-Day Pass**: For each day `index`, we calculate the cost of purchasing a 1-day pass. The function is called recursively for the next day (`index + 1`), and the cost of a 1-day pass is added.

```cpp
        // **Cost for a 7-day pass**:
        // Move forward to the first day that is not covered by a 7-day pass
        int i; 
        for (i = index; i < n && days[i] < days[index] + 7; i++);
        // Recursively calculate the cost from that day and add the cost of a 7-day pass
        int cost7 = getMinCost(days, costs, n, i) + costs[1];
```
- **Cost for a 7-Day Pass**: Here, we look for the first day `i` that is not covered by a 7-day pass starting from `days[index]`. This is done by iterating through the `days` array until we find a day that is more than 7 days after `days[index]`. The function is then called recursively for the day `i` and the cost of a 7-day pass is added.

```cpp
        // **Cost for a 30-day pass**:
        // Move forward to the first day that is not covered by a 30-day pass
        for (i = index; i < n && days[i] < days[index] + 30; i++);
        // Recursively calculate the cost from that day and add the cost of a 30-day pass
        int cost30 = getMinCost(days, costs, n, i) + costs[2];
```
- **Cost for a 30-Day Pass**: Similarly, for a 30-day pass, we iterate through the `days` array to find the first day that is not covered by the 30-day window. We call the recursive function with the new index `i` and add the cost of the 30-day pass.

```cpp
        // Return the minimum of the three costs
        return min(cost1, min(cost7, cost30));
    }
```
- **Return the Minimum Cost**: Once we have the three possible costs (1-day, 7-day, and 30-day), we return the minimum of the three. This ensures that we always choose the cheapest option for each day.

```cpp
    // Main function to calculate the minimum cost of traveling
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // Start the calculation from the first day
        return getMinCost(days, costs, days.size(), 0);
    }
};
```
- **Main Function**: The `mincostTickets` function is the entry point. It initializes the recursive process by calling `getMinCost` with the starting index `0` (the first day).

### **Example**

Let's walk through an example with `days = [1, 4, 6, 7, 8, 20]` and `costs = [2, 7, 15]`:

#### Step-by-step Breakdown:

1. **Start at day 1**:
   - **1-day pass**: The cost for the 1-day pass is `2`, and we recursively calculate the cost for the next day (index 1).
   - **7-day pass**: The 7-day pass covers days from 1 to 7. We skip the next days until day 8 and calculate the cost for the remaining days starting from day 8.
   - **30-day pass**: The 30-day pass covers all days from day 1 to 30, so we skip all remaining days and calculate the cost for day 20.

2. The recursion continues in this fashion, calculating the costs for the 1-day, 7-day, and 30-day passes at each step.

3. At each step, the function compares the costs of all three passes and chooses the cheapest option.

#### Example Output:

For the input:

```cpp
days = [1, 4, 6, 7, 8, 20]
costs = [2, 7, 15]
```

The function will calculate:

- **Cost for Day 1**: Minimum cost is `2` (1-day pass).
- **Cost for Day 4**: Minimum cost is `7` (7-day pass).
- **Cost for Day 6**: Minimum cost is `9` (combination of 1-day and 7-day pass).
- **Cost for Day 20**: Minimum cost is `15` (30-day pass).

Final minimum cost will be `9`.

### **Time Complexity**

- The **recursive approach** may revisit the same subproblems multiple times, which leads to a high number of calls.
- **Time complexity**: The time complexity of this solution is **O(3^n)**, where `n` is the number of travel days. This is because at each step, the function branches into three recursive calls (for each pass option).

### **Space Complexity**

- **Space complexity**: Since we're using recursion, the depth of the recursion will be proportional to the number of days, leading to **O(n)** space complexity. Additionally, we use extra space for function calls on the recursion stack.

---

## Top-Down Approach (DP)
In the **Top-Down Approach with Memoization**, we use recursion to break down the problem into smaller subproblems. The idea is to solve the problem starting from the first day and recursively decide whether to buy a 1-day, 7-day, or 30-day pass, while keeping track of the solutions to subproblems in a memoization table (i.e., a cache) to avoid redundant calculations.

#### **Intuition Behind the Top-Down Approach with Memoization**

1. **Recursion**: Starting from the first day, the algorithm explores all possible options (buying a 1-day, 7-day, or 30-day pass). It then recursively calculates the minimum cost required for the remaining days.

2. **Memoization**: To optimize the recursion and avoid recomputation of results for the same subproblems, we store the computed minimum costs in an array (`dp`). If a subproblem has already been solved, the solution is directly retrieved from the memoization table, which saves computation time.

3. **Subproblem**: The subproblem is calculating the minimum cost from a specific day (`index`). We solve this by considering:
   - The cost of a 1-day pass.
   - The cost of a 7-day pass (starting from the current day and covering the next 7 days).
   - The cost of a 30-day pass (starting from the current day and covering the next 30 days).

4. **Recursive Formula**: 
   - For a 1-day pass, we solve for the next day and add the cost of a 1-day pass.
   - For a 7-day pass, we find the first day that is not covered by the 7-day pass and solve recursively from that day.
   - For a 30-day pass, we find the first day that is not covered by the 30-day pass and solve recursively from that day.

5. **Base Case**: When the index exceeds the number of travel days (`index >= n`), no more cost is required, so the cost is `0`.

### Source Code
```cpp
class Solution {
public:
    // Recursive function to calculate the minimum cost using memoization
    int solve(vector<int>& days, vector<int>& costs, int n, int index, vector<int>& dp) {
        // Base case: if the index is out of bounds, no cost is required
        if (index >= n) 
            return 0;

        // If the result is already computed for the current index, return it (memoization)
        if (dp[index] != -1) 
            return dp[index];

        // **Cost for a 1-day pass**:
        // Move to the next day and add the cost of a 1-day pass
        int cost1 = solve(days, costs, n, index + 1, dp) + costs[0];
        
        // **Cost for a 7-day pass**:
        // Find the first day not covered by the 7-day pass (days[index] + 7)
        int i; 
        for (i = index; i < n && days[i] < days[index] + 7; i++);
        // Recursively calculate the cost from that day and add the cost of a 7-day pass
        int cost7 = solve(days, costs, n, i, dp) + costs[1];
        
        // **Cost for a 30-day pass**:
        // Find the first day not covered by the 30-day pass (days[index] + 30)
        for (i = index; i < n && days[i] < days[index] + 30; i++);
        // Recursively calculate the cost from that day and add the cost of a 30-day pass
        int cost30 = solve(days, costs, n, i, dp) + costs[2];

        // Store the minimum cost for the current index in the memoization table
        dp[index] = min(cost1, min(cost7, cost30));

        // Return the computed minimum cost for the current index
        return dp[index];
    }

    // Main function to calculate the minimum cost of traveling
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // Create a memoization table initialized to -1
        vector<int> dp(days.size() + 1, -1);
        // Start calculating from the first day
        return solve(days, costs, days.size(), 0, dp);
    }
};
```
### Source Code Explanation

```cpp
class Solution {
public:
    // Recursive function to calculate the minimum cost using memoization
    int solve(vector<int>& days, vector<int>& costs, int n, int index, vector<int>& dp) {
        // Base case: if the index is out of bounds, no cost is required
        if (index >= n) 
            return 0;
```
- **Base Case**: If the `index` exceeds or equals `n` (the total number of travel days), we return `0` because no more travel days are left to cover.

```cpp
        // If the result is already computed for the current index, return it (memoization)
        if (dp[index] != -1) 
            return dp[index];
```
- **Memoization**: If the cost for the current `index` has already been computed (i.e., `dp[index]` is not `-1`), we directly return the stored result, avoiding redundant calculations.

```cpp
        // **Cost for a 1-day pass**:
        // Move to the next day and add the cost of a 1-day pass
        int cost1 = solve(days, costs, n, index + 1, dp) + costs[0];
```
- **1-Day Pass**: We recursively calculate the cost of using a 1-day pass. We move to the next day (`index + 1`) and add the cost of a 1-day pass (`costs[0]`).

```cpp
        // **Cost for a 7-day pass**:
        // Find the first day not covered by the 7-day pass (days[index] + 7)
        int i; 
        for (i = index; i < n && days[i] < days[index] + 7; i++);
        // Recursively calculate the cost from that day and add the cost of a 7-day pass
        int cost7 = solve(days, costs, n, i, dp) + costs[1];
```
- **7-Day Pass**: We find the first day that is not covered by the 7-day pass (i.e., a day after `days[index] + 7`). Then we calculate the cost recursively from that day (`i`), and add the cost of a 7-day pass (`costs[1]`).

```cpp
        // **Cost for a 30-day pass**:
        // Find the first day not covered by the 30-day pass (days[index] + 30)
        for (i = index; i < n && days[i] < days[index] + 30; i++);
        // Recursively calculate the cost from that day and add the cost of a 30-day pass
        int cost30 = solve(days, costs, n, i, dp) + costs[2];
```
- **30-Day Pass**: We find the first day that is not covered by the 30-day pass (i.e., a day after `days[index] + 30`). We then recursively calculate the cost from that day (`i`) and add the cost of a 30-day pass (`costs[2]`).

```cpp
        // Store the minimum cost for the current index in the memoization table
        dp[index] = min(cost1, min(cost7, cost30));
```
- **Store Result**: We store the minimum of the three costs (1-day, 7-day, and 30-day passes) for the current day (`index`) in the memoization table `dp[index]`.

```cpp
        // Return the computed minimum cost for the current index
        return dp[index];
    }

    // Main function to calculate the minimum cost of traveling
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // Create a memoization table initialized to -1
        vector<int> dp(days.size() + 1, -1);
        // Start calculating from the first day
        return solve(days, costs, days.size(), 0, dp);
    }
};
```
- **Main Function**: The main function initializes the memoization table `dp` with `-1` (indicating that no cost has been computed yet). It then calls the `solve` function starting from the first day (`index = 0`) and returns the result.

### **Example**

Let's take the input:

```cpp
days = [1, 4, 6, 7, 8, 20]
costs = [2, 7, 15]
```

#### Step-by-step Breakdown:

1. **Start at day 1**:
   - **1-day pass**: The cost for the 1-day pass is `2`, and we move to the next day (index 1).
   - **7-day pass**: The 7-day pass covers days from 1 to 7. We move to day 8 (index 5) and calculate the cost for the remaining days.
   - **30-day pass**: The 30-day pass covers all days from day 1 to 30, so we move to day 20 (index 6) and calculate the cost for the remaining days.

2. **Memoization**: As we explore the subproblems, we store the computed minimum costs in `dp`. If we revisit the same index, we use the memoized value instead of recomputing the cost.

#### Example Output:

For the input:

```cpp
days = [1, 4, 6, 7, 8, 20]
costs = [2, 7, 15]
```

The recursive calls will evaluate the three options for each day, and the final output will be:

```cpp
9
```

- The optimal solution is to buy a 7-day pass from day 1 to day 7 (`7` units) and then a 1-day pass for day 8 (`2` units), resulting in a total of `7 + 2 = 9` units.

### **Time Complexity**

- In the top-down approach with memoization, we only calculate the cost for each index once.
- Each subproblem (each day) is solved once and stored in the `dp` array. Since we have `n` days, the overall time complexity is **O(n)**.

### **Space Complexity**

- The space complexity is **O(n)** because we store the computed minimum costs for each day in the `dp` array, and the recursion stack depth can go up to `n`.

---

## Bottom-Up Approach (DP)
In the **Bottom-Up Approach**, we iteratively solve the problem starting from the last day of travel, moving toward the first day. Instead of using recursion, we calculate the minimum cost from the back to the front, storing results in a dynamic programming (DP) table to avoid recomputation. 

This approach solves the problem in a more efficient manner compared to the recursive approach, as it avoids recomputing the same subproblems multiple times.

### **Step-by-Step Breakdown of the Bottom-Up Approach:**

#### **1. Problem Understanding:**

The goal of this problem is to determine the minimum cost of buying tickets for a set of travel days, where we have three types of tickets available:
- **1-day pass:** Valid for 1 day.
- **7-day pass:** Valid for 7 consecutive days.
- **30-day pass:** Valid for 30 consecutive days.

You are given a list of days on which you will travel, and the costs for the 1-day, 7-day, and 30-day passes.

#### **2. DP Table Initialization:**
- We create a DP array `dp` where `dp[i]` represents the minimum cost to cover all travel days starting from day `i`.
- The size of the DP table is `n + 1`, where `n` is the number of travel days. We use `dp[n] = 0` as the base case, meaning if we have no more days left to cover, the cost is `0`.

#### **3. Recurrence Relation (Bottom-Up Iteration):**
- **For each day `k`,** we calculate the minimum cost by considering the following three options:
  1. **Cost for a 1-day pass:** Add the cost of the 1-day pass (`costs[0]`) and the result for the next day (`dp[k + 1]`).
  2. **Cost for a 7-day pass:** Find the first day not covered by the 7-day pass (`days[k] + 7`), and calculate the cost for the next day starting from that day (`dp[i]` where `i` is the first day not covered by the 7-day pass).
  3. **Cost for a 30-day pass:** Similarly, calculate the cost for the 30-day pass by finding the first day not covered by it (`days[k] + 30`), and calculate the cost for the next day starting from that day (`dp[i]` where `i` is the first day not covered by the 30-day pass).

#### **4. Transition:**
- For each day `k`, store the minimum of the above three options in `dp[k]`.

#### **5. Return the Result:**
- The minimum cost for covering all the travel days starting from day `0` is stored in `dp[0]`.

### Source Code
```cpp
class Solution {
public:
    // Function to calculate the minimum cost using dynamic programming
    long long solve(vector<int>& days, vector<int>& costs, int n) {
        // Create a DP table to store the minimum cost for each starting day
        // Initialize all values to a very large number (LLONG_MAX)
        vector<long long> dp(n + 1, LLONG_MAX);
        
        // Base case: if there are no more days to cover, the cost is 0
        dp[n] = 0;

        // Traverse the days array from the last travel day to the first
        for (int k = n - 1; k >= 0; k--) {
            // **Cost for a 1-day pass**:
            // Add the cost of a 1-day pass and move to the next day
            long long cost1 = dp[k + 1] + costs[0];
            
            // **Cost for a 7-day pass**:
            // Find the first day not covered by the 7-day pass (days[k] + 7)
            int i;
            for (i = k; i < n && days[i] < days[k] + 7; i++);
            // Add the cost of a 7-day pass and use the precomputed result from dp[i]
            long long cost7 = dp[i] + costs[1];
            
            // **Cost for a 30-day pass**:
            // Find the first day not covered by the 30-day pass (days[k] + 30)
            for (i = k; i < n && days[i] < days[k] + 30; i++);
            // Add the cost of a 30-day pass and use the precomputed result from dp[i]
            long long cost30 = dp[i] + costs[2];

            // Store the minimum cost for day k in the DP table
            dp[k] = min(cost1, min(cost7, cost30));
        }

        // Return the minimum cost starting from the first day
        return dp[0];
    }

    // Main function to calculate the minimum cost of traveling
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // Call the solve function with the days, costs, and number of days
        return solve(days, costs, days.size());
    }
};
```

### Source Code Explanation

1. **Class Definition and Method Declaration:**
   ```cpp
   class Solution {
   public:
   ```
   The class `Solution` contains the method `mincostTickets`, which is used to calculate the minimum cost for traveling on the given days with different ticket options.

2. **solve() Method:**
   ```cpp
   long long solve(vector<int>& days, vector<int>& costs, int n) {
   ```
   The `solve` method is the core of the bottom-up dynamic programming solution. It accepts:
   - `days`: A list of days when the traveler will travel.
   - `costs`: A list of costs corresponding to the 1-day, 7-day, and 30-day passes.
   - `n`: The number of travel days (`days.size()`).

3. **DP Table Initialization:**
   ```cpp
   vector<long long> dp(n + 1, LLONG_MAX);
   ```
   - We initialize the `dp` array of size `n + 1` (where `n` is the number of travel days).
   - We set all values to `LLONG_MAX` (a large number) initially, except for `dp[n]`, which will be updated to `0` later. This is because the cost to cover no days is `0`.

4. **Base Case Initialization:**
   ```cpp
   dp[n] = 0;
   ```
   - The base case is that if there are no more days to cover (i.e., `dp[n]`), the cost is `0`.

5. **Bottom-Up Iteration:**
   ```cpp
   for (int k = n - 1; k >= 0; k--) {
   ```
   - The loop runs from `k = n - 1` (the last travel day) to `k = 0` (the first travel day). The goal is to compute the minimum cost for each day `k`, starting from the last travel day and moving backward.

6. **Cost Calculation for 1-Day Pass:**
   ```cpp
   long long cost1 = dp[k + 1] + costs[0];
   ```
   - For the 1-day pass, the cost is the cost of the 1-day ticket (`costs[0]`) plus the cost for the next day (`dp[k + 1]`), which has already been computed.

7. **Cost Calculation for 7-Day Pass:**
   ```cpp
   int i;
   for (i = k; i < n && days[i] < days[k] + 7; i++);
   long long cost7 = dp[i] + costs[1];
   ```
   - We find the first day that is not covered by the 7-day pass by checking if the days are within 7 days starting from `days[k]`. Once we find this day `i`, we calculate the cost for the 7-day pass as the cost of the 7-day pass (`costs[1]`) plus the precomputed cost from `dp[i]`.

8. **Cost Calculation for 30-Day Pass:**
   ```cpp
   for (i = k; i < n && days[i] < days[k] + 30; i++);
   long long cost30 = dp[i] + costs[2];
   ```
   - Similarly, we find the first day that is not covered by the 30-day pass by checking if the days are within 30 days starting from `days[k]`. We then calculate the cost for the 30-day pass as the cost of the 30-day pass (`costs[2]`) plus the precomputed cost from `dp[i]`.

9. **Store Minimum Cost:**
   ```cpp
   dp[k] = min(cost1, min(cost7, cost30));
   ```
   - We store the minimum of the costs (for the 1-day, 7-day, and 30-day passes) in `dp[k]`.

10. **Return the Final Result:**
   ```cpp
   return dp[0];
   ```
   - The minimum cost for covering all travel days starting from day 0 is stored in `dp[0]`.

11. **Main Method:**
   ```cpp
   int mincostTickets(vector<int>& days, vector<int>& costs) {
       return solve(days, costs, days.size());
   }
   ```
   - The `mincostTickets` method simply calls the `solve` method with the travel days, ticket costs, and the number of travel days.


### **Example with Explanation:**

Let's take an example to see how this works:

#### **Input:**
- `days = [1, 4, 6, 7, 8, 20]` (days when the traveler is traveling)
- `costs = [2, 7, 15]` (costs for the 1-day, 7-day, and 30-day passes)

#### **Steps:**

- **Initialization:**
  - `dp = [LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, LLONG_MAX, 0]` (the last value is `0` since no cost is needed after the last day).

- **First iteration (`k = 5`):**
  - `cost1 = dp[6] + costs[0] = 0 + 2 = 2`
  - `cost7 = dp[6] + costs[1] = 0 + 7 = 7` (7-day pass covers all days from 4 to 10)
  - `cost30 = dp[6] + costs[2] = 0 + 15 = 15`
  - Minimum cost for day `5` is `2`, so `dp[5] = 2`.

- **Second iteration (`k = 4`):**
  - `cost1 = dp[5] + costs[0] = 2 + 2 = 4`
  - `cost7 = dp[5] + costs[1] = 2 + 7 = 9` (7-day pass covers days from 4 to 10)
  - `cost30 = dp[5] + costs[2] = 2 + 15 = 17`
  - Minimum cost for day `4` is `4`, so `dp[4] = 4`.

- Repeat for all days, eventually storing the minimum cost in `dp[0]`.

#### **Final Answer:**
- `dp[0] = 11` (minimum cost to cover all travel days).


### **Time and Space Complexity:**

- **Time Complexity:**
  - The main loop runs for `n` iterations (`n` is the number of travel days).
  - In each iteration, we are checking the 7-day and 30-day conditions, which requires iterating through the days array. In the worst case, this will require `O(n)` time for each of the three passes (1-day, 7-day, 30-day).
  - So, the total time complexity is: **O(n²)**, where `n` is the number of travel days.

- **Space Complexity:**
  - The space complexity is primarily due to the `dp` array, which is of size `n + 1`.
  - Thus, the space complexity is: **O(n)**.

---

## Space Optimization Approach (DP)

The problem asks to find the minimum cost of tickets for travel on certain days, with three types of tickets available:
- **1-day pass**: Can be used for a single day of travel.
- **7-day pass**: Can be used for travel on any 7 consecutive days.
- **30-day pass**: Can be used for travel on any 30 consecutive days.

The approach here uses **dynamic programming** with two **queues** to keep track of the minimum cost for both the 7-day and 30-day passes.

### **Step-by-Step Explanation of the Approach:**

1. **Initialization**:
   - We initialize a variable `ans` to 0 to keep track of the minimum cost so far.
   - We use two queues:
     - **`month` queue**: Keeps track of the minimum cost when we use a 30-day pass.
     - **`week` queue**: Keeps track of the minimum cost when we use a 7-day pass.

2. **Iterating over Travel Days**:
   - We iterate through each travel day in the `days` array.
   - For each travel day, we update the cost by considering three options:
     1. **Buy a 1-day pass for the current day**: The cost for this is the current `ans` (minimum cost so far) + the cost of a 1-day pass (`costs[0]`).
     2. **Use a 7-day pass**: This is tracked in the `week` queue. We pop outdated entries from the `week` queue (entries where the 7-day pass would have expired) and then push the new cost to `week`.
     3. **Use a 30-day pass**: This is tracked in the `month` queue. We pop outdated entries from the `month` queue (entries where the 30-day pass would have expired) and then push the new cost to `month`.

3. **Choosing the Minimum Cost**:
   - After processing each day, the cost for that day is updated by choosing the minimum cost from:
     - The 1-day pass option (`ans + costs[0]`).
     - The cheapest 7-day pass from the `week` queue.
     - The cheapest 30-day pass from the `month` queue.

4. **Final Result**:
   - After processing all the days, the variable `ans` will contain the minimum cost required to cover all the travel days.
     
### Source Code
```cpp
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int ans = 0; // Variable to keep track of the minimum cost so far

        // Queues to track the minimum cost for 7-day and 30-day passes
        queue<pair<int, int>> month; // Stores {day, cost} for the 30-day pass
        queue<pair<int, int>> week;  // Stores {day, cost} for the 7-day pass

        // Iterate through all the travel days
        for (int day : days) {
            // Remove outdated entries from the month queue
            // If the current day is greater than or equal to the day of the oldest entry + 30,
            // it means the 30-day pass for that day is no longer valid
            while (!month.empty() && month.front().first + 30 <= day) {
                month.pop();
            }

            // Remove outdated entries from the week queue
            // If the current day is greater than or equal to the day of the oldest entry + 7,
            // it means the 7-day pass for that day is no longer valid
            while (!week.empty() && week.front().first + 7 <= day) {
                week.pop();
            }

            // Add a new entry for the current day to the week queue
            // This represents the cost of buying a 7-day pass starting today
            week.push(make_pair(day, ans + costs[1]));

            // Add a new entry for the current day to the month queue
            // This represents the cost of buying a 30-day pass starting today
            month.push(make_pair(day, ans + costs[2]));

            // Update the minimum cost (ans) for the current day
            // Consider three options:
            // 1. Buying a 1-day pass for the current day
            // 2. Using the cheapest cost from the week queue
            // 3. Using the cheapest cost from the month queue
            ans = min(ans + costs[0], min(week.front().second, month.front().second));
        }

        // Return the total minimum cost to cover all the travel days
        return ans;
    }
};
```

### Source Code Explanation

```cpp
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int ans = 0; // Variable to keep track of the minimum cost so far
```
- `ans` starts at 0. It will store the total minimum cost for covering the travel days.

```cpp
        queue<pair<int, int>> month; // Stores {day, cost} for the 30-day pass
        queue<pair<int, int>> week;  // Stores {day, cost} for the 7-day pass
```
- Two queues are initialized to track the costs associated with the 7-day and 30-day passes.
- `month` stores pairs of `{day, cost}`, where `day` is the first day of the 30-day pass and `cost` is the cost of that pass.
- `week` stores pairs of `{day, cost}`, where `day` is the first day of the 7-day pass and `cost` is the cost of that pass.

```cpp
        for (int day : days) {
```
- We loop through each `day` in the `days` array, which contains the days the traveler will travel.

```cpp
            while (!month.empty() && month.front().first + 30 <= day) {
                month.pop();
            }
```
- This loop removes the outdated entries from the `month` queue. If the current day `day` is greater than or equal to the day of the oldest entry plus 30, then the 30-day pass for that day is no longer valid, and we pop it from the `month` queue.

```cpp
            while (!week.empty() && week.front().first + 7 <= day) {
                week.pop();
            }
```
- Similarly, we remove outdated entries from the `week` queue. If the current day `day` is greater than or equal to the day of the oldest entry plus 7, then the 7-day pass for that day is no longer valid, and we pop it from the `week` queue.

```cpp
            week.push(make_pair(day, ans + costs[1]));
            month.push(make_pair(day, ans + costs[2]));
```
- We push a new entry into the `week` queue for the current day. This entry represents buying a 7-day pass starting on this day. The cost of this pass is `ans + costs[1]` (current minimum cost plus the cost of a 7-day pass).
- Similarly, we push a new entry into the `month` queue for the current day, representing buying a 30-day pass starting on this day. The cost of this pass is `ans + costs[2]`.

```cpp
            ans = min(ans + costs[0], min(week.front().second, month.front().second));
        }
```
- After processing each day, we update the `ans` variable by considering three options:
  - The cost of buying a 1-day pass today: `ans + costs[0]`.
  - The cost of using the cheapest 7-day pass: `week.front().second`.
  - The cost of using the cheapest 30-day pass: `month.front().second`.
- We take the minimum of these three values and update `ans` accordingly.

```cpp
        return ans;
    }
};
```
- After all the travel days have been processed, `ans` will contain the minimum total cost required to cover all the travel days. We return this value.



### **Example with Explanation:**

#### **Input:**
- `days = [1, 4, 6, 7, 8, 20]`
- `costs = [2, 7, 15]` (1-day pass costs 2, 7-day pass costs 7, 30-day pass costs 15)

#### **Step-by-Step Execution:**

1. **Initialization:**
   - `ans = 0`
   - `week = []` (Empty queue)
   - `month = []` (Empty queue)

2. **Processing the first day (day 1):**
   - We push `{1, 2}` into the `week` queue because buying a 7-day pass starting today costs `0 + 7 = 7`.
   - We push `{1, 15}` into the `month` queue because buying a 30-day pass starting today costs `0 + 15 = 15`.
   - `ans = min(0 + 2, min(7, 15)) = 2`

3. **Processing the second day (day 4):**
   - We push `{4, 9}` into the `week` queue (7-day pass starting on day 4).
   - We push `{4, 15}` into the `month` queue (30-day pass starting on day 4).
   - `ans = min(2 + 2, min(9, 15)) = 4`

4. **Processing the third day (day 6):**
   - We push `{6, 11}` into the `week` queue.
   - We push `{6, 15}` into the `month` queue.
   - `ans = min(4 + 2, min(11, 15)) = 6`

5. **Processing the fourth day (day 7):**
   - We push `{7, 13}` into the `week` queue.
   - We push `{7, 15}` into the `month` queue.
   - `ans = min(6 + 2, min(13, 15)) = 8`

6. **Processing the fifth day (day 8):**
   - We push `{8, 15}` into the `week` queue.
   - We push `{8, 15}` into the `month` queue.
   - `ans = min(8 + 2, min(15, 15)) = 10`

7. **Processing the sixth day (day 20):**
   - We push `{20, 22}` into the `week` queue.
   - We push `{20, 30}` into the `month` queue.
   - `ans = min(10 + 2, min(22, 30)) = 12`

#### **Final Output:**
- `ans = 12`, which is the minimum cost required to cover all travel days.


### **Time and Space Complexity:**

**Time Complexity**:
- **`O(n)`**: We iterate through each day in the `days` array exactly once.
- In each iteration, we may push and pop from the `week` and `month` queues. However, since each day is pushed into the queue only once and popped at most once, the total time complexity is linear with respect to the number of days (`n`).
- Thus, the overall time complexity is **`O(n)`**.

**Space Complexity**:
- We store up to `n` days in the queues `week` and `month`. Therefore, the space complexity is **`O(n)`** due to the queues storing pairs of `{day, cost}`.




