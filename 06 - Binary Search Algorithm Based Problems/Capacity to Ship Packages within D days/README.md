# Capacity to Ship Packages Within D Days Problem

**Problem Statement:**

You are given an array `weights` of integers, where `weights[i]` represents the weight of the iii-th package. You are also given an integer `D`, representing the number of days you have to ship all the packages. You need to find the minimum capacity of a ship such that all the packages can be shipped within `D` days.

**Example:**

-   Input: `weights = [1,2,3,4,5,6,7,8,9,10]`, `D = 5`
-   Output: `15`

**Explanation:** One way to ship the packages in 5 days with minimum capacity 15 is:

-   Day 1: 1, 2, 3, 4, 5
-   Day 2: 6, 7
-   Day 3: 8
-   Day 4: 9
-   Day 5: 10

### Approach to Solve the Problem

This problem can be approached using Binary Search. Here’s a step-by-step guide:

1.  **Understanding the Problem:**
    
    -   We need to determine the minimum ship capacity to ship all packages within `D` days.
    -   The capacity must be sufficient to carry the packages in contiguous groups without exceeding the limit `D` days.
2.  **Determine the Search Space:**
    
    -   The minimum capacity of the ship must be at least the weight of the heaviest package (let's call it `maxWeight`).
    -   The maximum capacity of the ship can be the sum of all package weights (let's call it `sumWeight`).
3.  **Binary Search on Capacity:**
    
    -   Initialize `low` to `maxWeight` and `high` to `sumWeight`.
    -   Perform binary search:
        -   Calculate `mid = (low + high) / 2`.
        -   Check if it’s possible to ship all packages within `D` days with ship capacity `mid`:
            -   Use a helper function `canShip(weights, D, mid)` to determine this.
        -   If it’s possible, move `high` to `mid`.
        -   If it’s not possible, move `low` to `mid + 1`.
4.  **Helper Function:**
    
    -   The helper function `canShip(weights, D, capacity)` checks if we can ship all packages within `D` days with the given `capacity`:
        -   Initialize `days` to 1 (the first day) and `currentLoad` to 0.
        -   Iterate through `weights` and add each weight to `currentLoad`.
        -   If `currentLoad` exceeds `capacity`, increment `days` and reset `currentLoad` to the current weight.
        -   If `days` exceeds `D`, return `False`.
        -   If the loop completes, return `True`.
     
## Explanation of the Code


```
#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;
``` 

-   **Include Statements**:
    -   `#include<iostream>`: Allows input and output operations.
    -   `#include<algorithm>`: Provides functions like `max_element` for finding the maximum element in an array.
    -   `#include<numeric>`: Provides functions like `accumulate` for calculating the sum of elements in an array.
    -   `using namespace std;`: Allows the use of standard library functions and objects without explicitly qualifying them with `std::`.



```
bool can_ship(int weights[], int n, int t_days, int mid) {
    int days = 1;
    int current_load = 0;
    
    for (int i = 0; i < n; i++) {
        if (current_load + weights[i] > mid) {
            days++;
            current_load = 0;
            
            if (days > t_days) {
                return false;
            }
        }
        current_load += weights[i];
    }
    return true;
}
``` 

-   **`can_ship` Function**:
    -   **Parameters**:
        -   `weights[]`: An array of integers representing weights of packages.
        -   `n`: Number of elements in the `weights` array.
        -   `t_days`: Total days allowed to ship all packages.
        -   `mid`: Current capacity being checked.
    -   **Purpose**: Determines if all packages can be shipped within `t_days` using the current `mid` capacity.
    -   **Logic**:
        -   Initializes `days` to 1 (start counting from day 1).
        -   Iterates through the `weights` array.
        -   Checks if adding the current weight to `current_load` would exceed `mid`.
        -   If it does, increments `days` (indicating a new shipping day) and resets `current_load` to 0.
        -   If `days` exceeds `t_days`, returns `false` (indicating it's not possible to ship within the allowed days).
        -   If the loop completes, returns `true` (indicating all packages can be shipped within `t_days`).



```
int ship_with_days(int weights[], int n, int days) {
    int max_weight = *max_element(weights, weights + n);
    int sum_weight = accumulate(weights, weights + n, 0);
    
    int start = max_weight;
    int end = sum_weight;
    
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (can_ship(weights, n, days, mid)) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    return start;
}
``` 

-   **`ship_with_days` Function**:
    -   **Parameters**:
        -   `weights[]`: An array of integers representing weights of packages.
        -   `n`: Number of elements in the `weights` array.
        -   `days`: Total days allowed to ship all packages.
    -   **Purpose**: Finds the minimum capacity required to ship all packages within `days`.
    -   **Logic**:
        -   Finds the maximum weight (`max_weight`) and the sum of all weights (`sum_weight`) in the `weights` array.
        -   Initializes `start` to `max_weight` (minimum capacity required must be at least the weight of the heaviest package).
        -   Initializes `end` to `sum_weight` (maximum possible capacity, sum of all weights).
        -   Uses binary search to efficiently find the minimum capacity:
            -   Calculates `mid` as the middle point between `start` and `end`.
            -   Calls `can_ship` to check if all packages can be shipped within `days` using `mid` capacity.
            -   Adjusts the search range (`start` to `mid` or `mid + 1` to `end`) based on whether the current `mid` capacity is sufficient.


```
int main() {
    int weights[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    
    int w_length = sizeof(weights) / sizeof(weights[0]);
    int minimum_capacity = ship_with_days(weights, w_length, days);
    
    cout << "Minimum Capacity with " << days << " Days: " << minimum_capacity << endl;
    
    return 0;
}
``` 

-   **`main` Function**:
    -   **Purpose**: Entry point of the program.
    -   **Logic**:
        -   Defines an array `weights` containing package weights.
        -   Defines `days` as the total days allowed to ship all packages.
        -   Computes `w_length` as the number of elements in the `weights` array.
        -   Calls `ship_with_days` to find the minimum capacity required to ship all packages within `days`.
        -   Prints the result (`minimum_capacity`) to the console.

### Summary

This C++ program uses binary search combined with a helper function (`can_ship`) to solve the "Capacity To Ship Packages Within D Days" problem efficiently. It determines the minimum capacity required to ship all packages within a specified number of days (`days`) using the weights provided in the `weights` array. The binary search narrows down the capacity range until it finds the minimum capacity that satisfies the shipping requirements.
