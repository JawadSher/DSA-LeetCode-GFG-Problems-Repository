# Maximum Running Time of N Computers

You are given a list of battery capacities and the number of computers that need to run simultaneously. The goal is to determine the maximum amount of time that all the computers can run simultaneously given the battery capacities.

## Approach

1.  **Sum of Battery Capacities**: Calculate the total power available from all batteries.
2.  **Binary Search Initialization**: Set the initial search range for the possible running time (`left` and `right`).
3.  **Binary Search Loop**:
    -   Calculate the middle point `mid`.
    -   Check if running the computers for `mid` minutes is feasible.
    -   Adjust the search range based on the feasibility check.
4.  **Return Result**: The maximum running time found during the binary search.


## Detailed Explanation

### `canRun` Method

```
bool canRun(vector<int>& batteries, int n, long long mid_minutes) {
    long long target_min = n * mid_minutes;
   ``` 

-   **Objective**: Check if `n` computers can run for `mid_minutes` using the given batteries.
-   **target_min**: Calculate the total running time needed: n \times \text{mid_minutes}.


 ```
 long long sum = 0;
    for(int i = 0; i < batteries.size(); i++) {
        sum += min((long long)batteries[i], mid_minutes);
    }
   ``` 

-   **sum**: Accumulate the total available power for `mid_minutes`.
-   **Loop**: For each battery, add the smaller of the battery capacity or `mid_minutes` to `sum`. This ensures no battery contributes more than `mid_minutes`.


 ```
 if(sum >= target_min) {
        return true;
    }
    return false;
}
``` 

-   **Check Feasibility**: If the accumulated power `sum` is greater than or equal to `target_min`, it is feasible to run the computers for `mid_minutes`. Otherwise, it is not feasible.

### `maxRunTime` Method



```
long long maxRunTime(int n, vector<int>& batteries) {
    long long total_minutes = 0;
    long long max_minutes = 0;
   ``` 

-   **total_minutes**: To store the sum of all battery capacities.
-   **max_minutes**: To store the maximum running time found.

 ```
 for(int i = 0; i < batteries.size(); i++) {
        total_minutes += batteries[i];
    }
   ``` 

-   **Calculate Total Minutes**: Loop through each battery and add its capacity to `total_minutes`.


 ```
long long left = *min_element(batteries.begin(), batteries.end());
    long long right = total_minutes / n;
``` 

-   **left**: Initialize to the smallest battery capacity to ensure a valid starting point.
-   **right**: Initialize to the average running time if the total power is evenly distributed.


 ```
 while(left <= right) {
        long long mid = left + (right - left) / 2;
   ``` 

-   **Binary Search Loop**: Run a loop while `left` is less than or equal to `right`.
-   **mid**: Calculate the middle point of `left` and `right`.


 ```
 if(canRun(batteries, n, mid)) {
            max_minutes = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
   ``` 

-   **Feasibility Check**: Use `canRun` to check if it's feasible to run `n` computers for `mid` minutes.
-   **Update Search Range**:
    -   If feasible, update `max_minutes` to `mid` and move `left` to `mid + 1` to search for a potentially larger feasible time.
    -   If not feasible, move `right` to `mid - 1` to search for a smaller feasible time.


 ```
 return max_minutes;
}
``` 

-   **Return Result**: After exiting the loop, `max_minutes` contains the maximum feasible running time for `n` computers.




## Why This Approach?

-   **Efficiency**: Binary search reduces the number of checks needed, making it faster than a linear search.
-   **Feasibility Check**: The `canRun` method ensures that only valid running times are considered by checking the total available power against the required power.
-   **Optimal Solution**: By iteratively adjusting the search range, the approach finds the maximum feasible running time efficiently.

This detailed breakdown should help you understand how the code works line by line, the approach used, and the problem statement it solves.
