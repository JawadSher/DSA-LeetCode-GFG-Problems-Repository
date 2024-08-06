# Koko Eating Bananas

The problem "Koko Eating Bananas" requires finding the minimum integer speed `K` such that Koko can eat all the bananas within `H` hours.

### `can_eat_all` Function:

```
int can_eat_all(vector<int>& piles, int mid, int h) {
    int actual_hours = 0;
    for (int p : piles) {
        actual_hours += p / mid;  // Calculate total hours for current speed

        if (p % mid != 0) {
            actual_hours++;  // Add an additional hour if there's a remainder
        }
    }
    return actual_hours <= h;  // Return true if Koko can eat all within h hours
}
``` 

#### Explanation:

1.  **Parameters**:
    
    -   `piles`: A reference to a vector of integers representing the number of bananas in each pile.
    -   `mid`: The current speed at which Koko is eating bananas per hour.
    -   `h`: The maximum number of hours within which Koko needs to finish all bananas.
2.  **Initialization**:
    
    -   `actual_hours` is initialized to `0` to keep track of the total hours needed for Koko to finish eating all piles at the given speed `mid`.
3.  **Calculation of `actual_hours`**:
    
    -   **Division**: For each pile `p`, `p / mid` calculates how many full hours are needed to eat that pile at speed `mid`.
    -   **Modulo Operation**: If there's a remainder (`p % mid != 0`), it means Koko needs an additional hour to finish eating that pile, so `actual_hours` is incremented by `1`.
4.  **Comparison**:
    
    -   The function returns `true` if `actual_hours` is less than or equal to `h`, indicating that Koko can eat all bananas within `h` hours at speed `mid`.
    -   It returns `false` otherwise, indicating that Koko cannot eat all bananas within `h` hours at speed `mid`.

### `minEatingSpeed` Function:


```
int minEatingSpeed(vector<int>& piles, int h) {
    int start = 1;
    int end = *max_element(piles.begin(), piles.end());

    while (start < end) {
        int mid = start + (end - start) / 2;

        if (can_eat_all(piles, mid, h)) {
            end = mid;  // Search in the lower half
        } else {
            start = mid + 1;  // Search in the upper half
        }
    }

    return start;  // Minimum speed that allows Koko to eat all bananas within h hours
}
``` 

#### Explanation:

1.  **Initialization**:
    
    -   `start` is initialized to `1`, representing the minimum possible eating speed.
    -   `end` is initialized to the maximum value in `piles`, found using `*max_element(piles.begin(), piles.end())`, setting an upper boundary for the binary search.
2.  **Binary Search**:
    
    -   The `while` loop continues as long as `start` is less than `end`, indicating there's a range of speeds to search.
3.  **Midpoint Calculation**:
    
    -   `mid` is calculated as `start + (end - start) / 2`, ensuring no integer overflow and getting the midpoint of the current range of speeds.
4.  **Call to `can_eat_all`**:
    
    -   `can_eat_all(piles, mid, h)` checks if Koko can eat all bananas within `h` hours at speed `mid`.
    -   If true (`can_eat_all` returns `true`), it means `mid` is a valid speed, and we adjust `end = mid` to potentially find a smaller valid speed.
    -   If false (`can_eat_all` returns `false`), it means `mid` is too slow, and we adjust `start = mid + 1` to search for faster speeds.
5.  **Conclusion**:
    
    -   Once the `while` loop concludes (`start >= end`), `start` represents the minimum eating speed `mid` at which Koko can eat all bananas within `h` hours.

### Example:

Let's use an example with `piles = {3, 6, 7, 11}` and `h = 8` to illustrate:

1.  **Initialization**:
    
    -   `start = 1`
    -   `end = 11`
2.  **First Iteration**:
    
    -   `mid = 6`
    -   `can_eat_all(piles, 6, 8)` returns `false` (actual hours required exceed `h`)
    -   `start` remains `1`, `end` becomes `6`
3.  **Second Iteration**:
    
    -   `mid = 3`
    -   `can_eat_all(piles, 3, 8)` returns `true` (actual hours required <= `h`)
    -   `start` becomes `3`, `end` remains `6`
4.  **Third Iteration**:
    
    -   `mid = 4`
    -   `can_eat_all(piles, 4, 8)` returns `false` (actual hours required exceed `h`)
    -   `start` remains `3`, `end` becomes `4`
5.  **Fourth Iteration**:
    
    -   `mid = 3`
    -   `can_eat_all(piles, 3, 8)` returns `true` (actual hours required <= `h`)
    -   `start` remains `3`, `end` becomes `3`
6.  **Conclusion**:
    
    -   `start = 3` is the minimum speed at which Koko can eat all bananas within `8` hours.

This approach effectively uses a binary search strategy to efficiently find the minimum eating speed required by Koko without directly iterating through all possible speeds, ensuring optimal performance for large inputs.
