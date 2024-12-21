<h1 align="center">Shop - in Candy - Store</h1>

## Problem Statement

**Problem URL :** [Shop in Candy Store](https://www.geeksforgeeks.org/problems/shop-in-candy-store1145/1)

![image](https://github.com/user-attachments/assets/5f322607-11ee-4e1b-af6b-abbabc75d10e)

### Problem Explanation
The problem revolves around buying candies from a store where there is a special offer:
- For every candy you buy, ( K ) candies can be chosen for free.
- The objective is to calculate:
  1. **Minimum cost**: The least amount you would spend if you try to minimize your cost.
  2. **Maximum cost**: The most amount you would spend if you maximize your spending.

The approach involves sorting the candy prices and strategically selecting which candies to buy and which to get for free.

#### Example:
- **Input**:  
  `candies[] = {3, 2, 1, 4}` (cost of candies)  
  `N = 4` (total candies)  
  `K = 2` (for every candy bought, 2 are free)  
- **Output**:  
  `Minimum Cost = 3`, `Maximum Cost = 7`


### Greedy Algorithm Approach:

#### Step-by-Step Explanation:
1. **Sort the Candies Array**:
   - Sorting ensures that candies are arranged from cheapest to most expensive. This simplifies minimizing and maximizing costs.
   - Example: After sorting, `candies[] = {1, 2, 3, 4}`.

2. **Calculate Minimum Cost**:
   - Start buying the cheapest candies first.
   - Each time you buy a candy, ( K ) of the most expensive remaining candies are considered "free."
   - Example:
     - Buy candy ( 1 ) (cost = 1), get candies ( 4 ) and ( 3 ) free.
     - Buy candy ( 2 ) (cost = 2).
     - Total minimum cost = ( 1 + 2 = 3 ).

3. **Calculate Maximum Cost**:
   - Start buying the most expensive candies first.
   - Each time you buy a candy, ( K ) of the cheapest remaining candies are considered "free."
   - Example:
     - Buy candy ( 4 ) (cost = 4), get candies ( 1 ) and ( 2 ) free.
     - Buy candy ( 3 ) (cost = 3).
     - Total maximum cost = ( 4 + 3 = 7 ).

4. **Return Results**:
   - Combine the results into a single vector, `[Minimum Cost, Maximum Cost]`.

## Problem Solution
```cpp
class Solution {
public:
    vector<int> candyStore(int candies[], int N, int K) {
        // Sort the candies array in ascending order to find minimum cost easily
        sort(candies, candies + N);

        // Variables for calculating minimum cost
        int mini = 0;  // Stores the minimum cost
        int free = N - 1; // Points to the most expensive candy available
        int buy = 0; // Points to the least expensive candy to buy

        // Calculate the minimum cost of buying candies
        while (buy <= free) {
            mini += candies[buy]; // Add the cost of the current candy being bought
            buy++;                // Move to the next candy to buy
            free -= K;            // Reduce the free candies available (K candies become free per purchase)
        }

        // Variables for calculating maximum cost
        int maxi = 0; // Stores the maximum cost
        free = 0;     // Points to the least expensive candy available
        buy = N - 1;  // Points to the most expensive candy to buy

        // Calculate the maximum cost of buying candies
        while (buy >= free) {
            maxi += candies[buy]; // Add the cost of the current candy being bought
            buy--;                // Move to the next candy to buy (from most expensive to least expensive)
            free += K;            // Increase the number of free candies available (from cheapest candies)
        }

        // Return the minimum and maximum costs as a vector
        return {mini, maxi};
    }
};
```

## Problem Solution Explanation

```cpp
class Solution {
public:
    vector<int> candyStore(int candies[], int N, int K) {
```
- **Function Definition**: This defines the function `candyStore` which takes three arguments:
  - `candies[]`: an array of integers representing the price of each candy.
  - `N`: the number of candies.
  - `K`: the number of free candies you get for every candy you buy.
  
  **Example**:  
  `candies[] = {3, 2, 1, 4}`  
  `N = 4` (there are 4 candies)  
  `K = 2` (for each candy bought, 2 candies are free)


### Sorting the Candies Array
```cpp
    sort(candies, candies + N);
```
- **Purpose**: This line sorts the `candies` array in ascending order to make it easier to calculate the minimum and maximum cost.
- **Example**:
  - Before sorting: `candies[] = {3, 2, 1, 4}`
  - After sorting: `candies[] = {1, 2, 3, 4}`


### Initializing Variables for Minimum Cost Calculation
```cpp
    int mini = 0;  // Initialize variable to store the minimum cost
    int free = N - 1; // Pointer to the most expensive candy (start from the last element)
    int buy = 0; // Pointer to the cheapest candy (start from the first element)
```
- **Purpose**: These variables are initialized for the minimum cost calculation:
  - `mini`: To keep track of the total cost when buying candies.
  - `free`: Points to the most expensive candy available (used to simulate receiving free candies).
  - `buy`: Points to the least expensive candy available (used to simulate purchasing candies).


### Calculating Minimum Cost
```cpp
    while (buy <= free) {
        mini += candies[buy]; // Add the price of the candy being bought
        buy++;                // Move to the next cheapest candy to buy
        free -= K;            // Reduce the free candies available (K candies become free)
    }
```
- **Purpose**: This loop simulates buying candies in the most cost-efficient way:
  - Buy the cheapest candy (`candies[buy]`), and after each purchase, you get ( K ) free candies.
  - The loop continues as long as there are candies to buy (`buy <= free`).

- **Example**:
  - `candies[] = {1, 2, 3, 4}` (after sorting)
  - Initially, `buy = 0`, `free = 3`
  - First iteration: Buy candy 1 (cost = 1), update `mini = 1`, `buy = 1`, `free = 1` (2 candies are free now)
  - Second iteration: Buy candy 2 (cost = 2), update `mini = 3`, `buy = 2`, `free = -1` (no more free candies)


### Initializing Variables for Maximum Cost Calculation
```cpp
    int maxi = 0; // Initialize variable to store the maximum cost
    free = 0;     // Pointer to the least expensive candy available
    buy = N - 1;  // Pointer to the most expensive candy (start from the last element)
```
- **Purpose**: These variables are initialized for the maximum cost calculation:
  - `maxi`: To keep track of the total cost when maximizing the number of candies bought.
  - `free`: Points to the least expensive candy available (used to simulate receiving free candies).
  - `buy`: Points to the most expensive candy available (used to simulate purchasing candies).


### Calculating Maximum Cost
```cpp
    while (buy >= free) {
        maxi += candies[buy]; // Add the price of the candy being bought
        buy--;                // Move to the next most expensive candy to buy
        free += K;            // Increase the number of free candies available (from cheapest candies)
    }
```
- **Purpose**: This loop simulates buying candies in the most expensive way:
  - Buy the most expensive candy (`candies[buy]`), and after each purchase, you get ( K ) free candies.
  - The loop continues as long as there are candies to buy (`buy >= free`).

- **Example**:
  - `candies[] = {1, 2, 3, 4}` (after sorting)
  - Initially, `buy = 3`, `free = 0`
  - First iteration: Buy candy 4 (cost = 4), update `maxi = 4`, `buy = 2`, `free = 2` (2 candies are free now)
  - Second iteration: Buy candy 3 (cost = 3), update `maxi = 7`, `buy = 1`, `free = 4` (4 candies are free now)


### Returning Results
```cpp
    return {mini, maxi}; // Return the minimum and maximum costs as a vector
}
```
- **Purpose**: After calculating both minimum and maximum costs, the function returns these values as a vector.
- **Example**:
  - After the calculations:
    - `mini = 3`
    - `maxi = 7`
  - The return value is `{3, 7}`.


### Example:

#### Input:
- `candies[] = {3, 2, 1, 4}`
- `N = 4` (total number of candies)
- `K = 2` (for every candy bought, 2 candies are free)

#### Execution:

1. **Sorting**:  
   - Sorted candies array: `candies[] = {1, 2, 3, 4}`.

2. **Calculating Minimum Cost**:  
   - Initially, `buy = 0` (cheapest candy), `free = 3` (most expensive candy).
   - First iteration: Buy candy ( 1 ), cost = 1, update `mini = 1`, `buy = 1`, `free = 1` (2 free candies).
   - Second iteration: Buy candy ( 2 ), cost = 2, update `mini = 3`, `buy = 2`, `free = -1`.
   - **Total minimum cost** = `3`.

3. **Calculating Maximum Cost**:  
   - Initially, `buy = 3` (most expensive candy), `free = 0` (cheapest candy).
   - First iteration: Buy candy ( 4 ), cost = 4, update `maxi = 4`, `buy = 2`, `free = 2` (2 free candies).
   - Second iteration: Buy candy ( 3 ), cost = 3, update `maxi = 7`, `buy = 1`, `free = 4`.
   - **Total maximum cost** = `7`.

#### Output:
- The final output is the vector `[3, 7]`, where `3` is the minimum cost and `7` is the maximum cost.


### Time and Space Complexity:

1. **Time Complexity**:
   - Sorting the array: ( O(N log N) ), where ( N ) is the number of candies.
   - The loops for calculating minimum and maximum cost: ( O(N) ), since each loop runs for at most ( N ) iterations.
   - **Overall Time Complexity** = ( O(N log N) ).

2. **Space Complexity**:
   - The function uses a constant amount of extra space apart from the input array. No additional data structures are used beyond a few variables.
   - **Overall Space Complexity** = ( O(1) ).

