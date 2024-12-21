<h1 align="center">Check - If It is - Possible to - Servive on - Island</h1>

## Problem Statement

**Problem URL :** [Check If it is Possible to Servive on Island](https://www.geeksforgeeks.org/problems/check-if-it-is-possible-to-survive-on-island4922/0)

![image](https://github.com/user-attachments/assets/dd16fce4-e34d-46d8-9714-f47ef5f39bd0)

### Problem Explanation
The task is to determine the minimum number of days required to prepare a certain amount of food for `S` days, where:
- `N` is the number of food items that can be produced per day.
- `M` is the number of food items needed per day.

However, there are constraints:
1. A week has 7 days, but only 6 days are available for food preparation (because 1 day is for rest).
2. If the number of items required (`M`) per day exceeds the number of items produced per day (`N`), then it is impossible to fulfill the requirement.

You need to compute the number of days it will take to produce the necessary food. If it's impossible, return `-1`.

### Examples:

#### Example 1:
- **Input:** `S = 10, N = 5, M = 3`
- **Explanation:**  
  We need food for 10 days. Each day, we need 3 items, so the total food required is:
  `
  text{totalFood} = 10 times 3 = 30
  `
  Each day, the production is 5 items. To calculate the days required:
  `
  text{days} = frac{30}{5} = 6 , text{(exact)}
  `
  So, it will take exactly 6 days to produce the required food.

- **Output:** `6`

#### Example 2:
- **Input:** `S = 7, N = 3, M = 5`
- **Explanation:**  
  The total food required is:
  `
  text{totalFood} = 7 times 5 = 35
  `
  Each day, we can produce 3 items. To calculate the days required:
  `
  text{days} = frac{35}{3} approx 11.67
  `
  Since we cannot have a fraction of a day, we round up:
  `
  text{days} = 12
  `
  So, it will take 12 days to produce 35 items.

- **Output:** `12`

#### Example 3:
- **Input:** `S = 6, N = 5, M = 6`
- **Explanation:**  
  In this case, each day we need 6 items but we can only produce 5 items per day. Since we need more items than we can produce, it is impossible to fulfill the requirement.

- **Output:** `-1`


### Greedy Algorithm Approach:

The problem can be solved using a greedy approach where:
1. **Sort out impossible situations:** 
   - If the number of items required per day (`M`) exceeds the number of items produced per day (`N`), then it is impossible to satisfy the requirements, so we return `-1`.
   - If the number of items required per day (`M`) is feasible, but the total food required exceeds the production capacity over the number of days (`7 * M > 6 * N`), we also return `-1`.

2. **Find the minimum number of days:** 
   - Once it's confirmed that it's feasible to fulfill the food requirement, calculate the total food required for `S` days (`totalFood = S * M`).
   - Divide the total food by the daily production (`N`), if the result is exact, return that number of days.
   - If not, round up the result to ensure enough food is produced.

## Problem Solution
```cpp
class Solution {
public:
    // Function to find the minimum number of days to prepare food
    int minimumDays(int S, int N, int M) {
        // Total food required for S days
        int totalFood = S * M;
        
        // Check if it is impossible to prepare food
        // Case 1: If the total food required exceeds the food production capacity (7 * M > 6 * N and S > 6)
        // Case 2: If the food required per day (M) exceeds the total food production capacity per day (N)
        if ((7 * M > 6 * N && S > 6) || M > N) return -1;
        
        // If the total food is divisible by N, return the exact number of days
        if (totalFood % N == 0) return totalFood / N;
        
        // If not, return the number of days needed, rounded up (totalFood / N + 1)
        else return totalFood / N + 1;
    }
};
```

## Problem Solution Explanation

1. **Total Food Calculation:**
   ```cpp
   int totalFood = S * M;
   ```
   - We calculate the total number of food items required for `S` days, each requiring `M` food items.

2. **Impossible Condition Check:**
   ```cpp
   if ((7 * M > 6 * N && S > 6) || M > N) return -1;
   ```
   - We check if it's impossible to prepare the food:
     - If the total food required exceeds the food production capacity over the days (`7 * M > 6 * N`), or
     - If the food required per day (`M`) exceeds the food produced per day (`N`).
   - If either condition is true, we return `-1`, indicating that it is impossible to meet the requirement.

3. **Exact Division of Total Food by Daily Production:**
   ```cpp
   if (totalFood % N == 0) return totalFood / N;
   ```
   - If the total food required is perfectly divisible by the daily production (`N`), we return the exact number of days required (`totalFood / N`).

4. **Round-up Division:**
   ```cpp
   else return totalFood / N + 1;
   ```
   - If the total food is not perfectly divisible by `N`, we round up the division result to account for the remainder. This is done by adding 1 to the result of `totalFood / N`.

### Example Walkthrough:

#### Example 1: `S = 10, N = 5, M = 3`
- **Total food required:** `10 * 3 = 30`
- **Check for impossibility:** 
  - `7 * M > 6 * N` is `7 * 3 > 6 * 5`, which is `21 > 30` (false).
  - `M > N` is `3 > 5` (false).
- **Exact division:** `30 % 5 == 0`, so return `30 / 5 = 6`.

#### Example 2: `S = 7, N = 3, M = 5`
- **Total food required:** `7 * 5 = 35`
- **Check for impossibility:**
  - `7 * M > 6 * N` is `7 * 5 > 6 * 3`, which is `35 > 18` (false).
  - `M > N` is `5 > 3` (false).
- **Round-up division:** `35 % 3 != 0`, so `35 / 3 = 11.67` which rounds up to `12`.

#### Example 3: `S = 6, N = 5, M = 6`
- **Total food required:** `6 * 6 = 36`
- **Check for impossibility:** 
  - `7 * M > 6 * N` is `7 * 6 > 6 * 5`, which is `42 > 30` (true).
  - So, we return `-1` indicating that it's impossible to prepare the required food.

### Time and Space Complexities:

#### Time Complexity:
- **Sorting:** The sorting operation takes `O(S log S)`, where `S` is the number of days (or the size of the input).
- **Other operations:** The rest of the operations (such as simple arithmetic and comparisons) take constant time, `O(1)`.

So, the total time complexity is:
`
O(S log S)
`

#### Space Complexity:

- The space complexity is `O(1)` because no additional space is required, apart from the input parameters and a few integer variables.

### Final Thoughts:
This solution efficiently checks for impossible scenarios first and uses greedy logic to calculate the minimum number of days required. The sorting operation ensures that we handle the food production and requirement efficiently.
