<h1 align="center">Maximum - Money</h1>

## Problem Statement

**Problem URL :** [Maximum Money](https://www.geeksforgeeks.org/problems/maximum-money2855/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/55dceb14-e646-42b2-ac1d-686a05cccfa0)

### Problem Explanation
The problem involves a **thief** who wants to rob money from a row of houses. Each house contains a fixed amount of money, denoted as `K`. However, the thief has a constraint: **he cannot rob two adjacent houses**. The task is to find the **maximum amount of money** the thief can rob while adhering to this rule.

### Input

- `N`: The number of houses.
- `K`: The amount of money present in each house.

### Output

- The maximum amount of money the thief can rob, following the rule that no two adjacent houses can be robbed.

### Constraints

- `1 ≤ N, K ≤ 1000`

### Example 1

**Input**:
```
N = 5, K = 10
```

**Explanation**:
- There are 5 houses, and each house contains 10 units of money.
- Since the thief cannot rob two adjacent houses, the best strategy is to rob every alternate house.
- The possible houses the thief can rob are:
  - Rob house 1 (house 1 contains 10 money).
  - Skip house 2.
  - Rob house 3 (house 3 contains 10 money).
  - Skip house 4.
  - Rob house 5 (house 5 contains 10 money).

Thus, the maximum amount of money the thief can rob is:
```
10 + 10 + 10 = 30
```

**Output**:
```
30
```

### Example 2

**Input**:
```
N = 2, K = 12
```

**Explanation**:
- There are 2 houses, and each house contains 12 units of money.
- Since the thief cannot rob two adjacent houses, he can only rob one of the two houses.
- The possible choices are:
  - Rob house 1 (house 1 contains 12 money).
  - Or rob house 2 (house 2 contains 12 money).

Thus, the maximum amount of money the thief can rob is:
```
12
```

**Output**:
```
12
```

### Example 3

**Input**:
```
N = 6, K = 7
```

**Explanation**:
- There are 6 houses, each containing 7 units of money.
- The best strategy would be for the thief to rob every alternate house to maximize the money.
- The possible houses the thief can rob are:
  - Rob house 1 (7 money).
  - Skip house 2.
  - Rob house 3 (7 money).
  - Skip house 4.
  - Rob house 5 (7 money).
  - Skip house 6.

Thus, the maximum amount of money the thief can rob is:
```
7 + 7 + 7 = 21
```

**Output**:
```
21
```


### Detailed Explanation

1. **Key Insight**:
   - The problem essentially asks how many houses the thief can rob if he is constrained from robbing two adjacent houses.
   - The optimal strategy is to **rob every alternate house**, starting from either the first or the second house, depending on which gives the best result.

2. **Mathematical Insight**:
   - The problem can be boiled down to **maximizing the number of non-adjacent houses** the thief can rob. This is simply **`ceil(N / 2)`**, because the thief can rob every alternate house.
   - If `N` is odd, the thief can rob `(N + 1) / 2` houses. If `N` is even, the thief can rob `N / 2` houses.
   
   - This can be expressed as:
     ```
     max_money = ceil(N / 2) * K
     ```
     where `K` is the money in each house.


## Problem Solution
```cpp
class Solution {
  public:
    // Function to calculate the maximum money the thief can rob
    int maximizeMoney(int N , int K) {
        // If there are no houses, the thief cannot rob any money
        if (N == 0) return 0;

        // If there is only one house, the maximum money is the amount in that house
        if (N == 1) return K;

        // For more than one house, calculate the maximum money the thief can rob
        // The thief can rob every alternate house, so the number of houses he can rob is ceil(N / 2)
        return (N + 1) / 2 * K;  // This is equivalent to ceil(N / 2) * K
    }
};

```

## Problem Solution Explanation

1. **`class Solution {`**
   - This defines the class `Solution`. The class encapsulates the method `maximizeMoney` that solves the problem. In C++, we define functions within a class to solve specific problems.

2. **`public:`**
   - The `public` keyword indicates that the methods and variables following it are accessible from outside the class. The function `maximizeMoney` is public, so it can be called on an instance of the `Solution` class.

3. **`int maximizeMoney(int N, int K) {`**
   - This is the definition of the function `maximizeMoney` which takes two integer arguments:
     - `N`: The number of houses.
     - `K`: The amount of money in each house.
   - The function returns an integer, which is the maximum amount of money the thief can rob.

4. **`if (N == 0) return 0;`**
   - This is a base case check. If there are no houses (`N == 0`), then the maximum amount of money the thief can rob is `0`. In this case, the function immediately returns `0`.
   
   **Example**:
   - Input: `N = 0, K = 10`
   - Since there are no houses (`N == 0`), the thief can't rob anything, so the output is `0`.

5. **`if (N == 1) return K;`**
   - This is another base case check. If there is only one house (`N == 1`), the thief has no choice but to rob that house, so the maximum money he can rob is `K`, which is the money in that house.
   
   **Example**:
   - Input: `N = 1, K = 10`
   - Since there is only one house, the thief robs it, and the maximum money he can rob is `10`.

6. **`return (N + 1) / 2 * K;`**
   - This is the general case when `N` is greater than `1`. Here, the logic is based on the observation that the thief can rob every alternate house to maximize the money, as he can't rob two adjacent houses.
   - **Key idea**: If the number of houses is `N`, the number of houses the thief can rob is `ceil(N / 2)`. This is because the thief can rob the 1st, 3rd, 5th, and so on houses.
   
   - **Why `(N + 1) / 2`?**:
     - This is an integer division that calculates the ceiling of `N / 2` (i.e., the number of houses the thief can rob).
     - If `N` is even, `N / 2` gives the correct number of houses the thief can rob.
     - If `N` is odd, `(N + 1) / 2` ensures that the thief can rob the extra house in the sequence.
   
   - Finally, we multiply this result by `K`, as each house contains `K` money.

   **Example 1**:
   - Input: `N = 5, K = 10`
   - The thief can rob every alternate house (house 1, 3, 5). So the number of houses robbed is `ceil(5 / 2) = 3`.
   - The maximum money robbed is `3 * 10 = 30`.

   **Example 2**:
   - Input: `N = 2, K = 12`
   - The thief can only rob one of the two houses. Thus, the number of houses robbed is `ceil(2 / 2) = 1`.
   - The maximum money robbed is `1 * 12 = 12`.

   **Example 3**:
   - Input: `N = 6, K = 7`
   - The thief can rob alternate houses (houses 1, 3, 5). Thus, the number of houses robbed is `ceil(6 / 2) = 3`.
   - The maximum money robbed is `3 * 7 = 21`.

### Example Walkthrough

Let's go through a specific example to further explain the code.

**Example**: 
```
Input: N = 5, K = 10
```

- **Step 1**: The first condition checks if `N == 0`, but `N = 5`, so it moves to the next condition.
- **Step 2**: The second condition checks if `N == 1`, but `N = 5`, so it moves to the main calculation.
- **Step 3**: The expression `(N + 1) / 2` calculates the number of houses the thief can rob:
  - `(5 + 1) / 2 = 6 / 2 = 3`
- **Step 4**: The thief can rob 3 houses, and each house contains 10 money.
- **Step 5**: Multiply the number of houses by the money in each house: `3 * 10 = 30`.

Thus, the function returns `30`.



### Summary of Code Logic:

- **Base cases**:
  - If there are no houses (`N == 0`), return `0`.
  - If there is only one house (`N == 1`), return the money in that house (`K`).
  
- **General case**:
  - The thief can rob every alternate house. The number of houses the thief can rob is `ceil(N / 2)`.
  - The total money robbed is calculated by multiplying the number of houses by the money in each house (`K`).

### Time and Space Complexity:

- **Time Complexity**: 
  - The code consists of simple arithmetic operations, so the time complexity is **O(1)** (constant time).

- **Space Complexity**: 
  - The space complexity is **O(1)** because the code only uses a constant amount of space (a few variables).

This solution efficiently solves the problem in constant time and space.
