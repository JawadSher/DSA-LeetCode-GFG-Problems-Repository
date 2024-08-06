# Minimum Time to Complete Trips

You are given:

-   An array `time` where `time[i]` represents the time taken by the `i-th` bus to complete one trip.
-   An integer `totalTrips` which is the total number of trips that need to be completed.

Your goal is to find the minimum time required for all buses combined to complete at least `totalTrips` trips.

### Example

Consider `time = [1, 2, 3]` and `totalTrips = 5`.

-   Bus 1 takes 1 unit of time per trip.
-   Bus 2 takes 2 units of time per trip.
-   Bus 3 takes 3 units of time per trip.

The challenge is to find the smallest amount of time `T` such that the sum of the number of trips each bus can complete in `T` time is at least 5.

### Binary Search Approach Explanation

#### Step-by-Step Explanation

1.  **Initialization**:
    
    -   We initialize `start` to 1 because the smallest possible time to consider is 1 unit.
    -   We initialize `end` to the maximum possible time, which is the maximum time a bus takes for one trip multiplied by `totalTrips`. This represents the worst-case scenario where only the slowest bus is running all trips.
        -   `end = max(time) * totalTrips`
2.  **Binary Search Setup**:
    
    -   We use a binary search to efficiently narrow down the minimum time required.
    -   `result` is initialized to `end`, as this is the upper bound of our search space.
3.  **Binary Search Loop**:
    
    -   We loop while `start` is less than or equal to `end`.
    -   For each iteration, we calculate the middle point `mid` as the average of `start` and `end`.
        -   `mid = start + (end - start) / 2`
    -   We then calculate the total number of trips all buses can complete in `mid` time.
        -   For each bus time `t` in `time`, the number of trips that bus can complete in `mid` time is `mid / t`.
        -   We sum these values to get the total number of trips.
4.  **Feasibility Check**:
    
    -   If the total number of trips is greater than or equal to `totalTrips`, it means that `mid` time is sufficient.
        -   We update `result` to `mid` as this is a potential answer.
        -   We then try to find a smaller time by moving the `end` pointer to `mid - 1`.
    -   If the total number of trips is less than `totalTrips`, it means that `mid` time is not sufficient.
        -   We need to look for a larger time, so we move the `start` pointer to `mid + 1`.
5.  **Return Result**:
    
    -   After the loop ends, `result` holds the minimum time required to complete at least `totalTrips` trips.

Here's the code again with detailed comments explaining each part:


```
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        // Initialize the binary search boundaries
        long long start = 1;
        long long end = *max_element(time.begin(), time.end()) * (long long)totalTrips;
        long long result = end;

        // Binary search loop
        while (start <= end) {
            long long mid = start + (end - start) / 2;  // Calculate the mid-point
            long long trips = 0;

            // Calculate the total number of trips that can be completed in 'mid' time
            for (int t : time) {
                trips += mid / t;  // Add the number of trips each bus can complete in 'mid' time
                if (trips >= totalTrips) {  // If we already meet or exceed the required trips, break early
                    break;
                }
            }

            // If the number of trips is sufficient
            if (trips >= totalTrips) {
                result = mid;  // Update the result to the current mid value
                end = mid - 1;  // Try to find a smaller sufficient time
            } else {
                start = mid + 1;  // Increase the time to find a sufficient time
            }
        }

        return result;  // Return the minimum time found
    }
};
``` 

### Detailed Explanation of the Key Points:

1.  **Binary Search Boundaries**:
    
    -   `start` is the minimum possible time (1 unit).
    -   `end` is the maximum possible time, calculated as `max(time) * totalTrips`. This represents the scenario where the slowest bus is doing all the trips.
2.  **Binary Search Loop**:
    
    -   We calculate the middle point `mid` in the current search range.
    -   For each bus, we compute the number of trips it can complete within `mid` time by dividing `mid` by the time for one trip (`mid / t`).
3.  **Feasibility Check**:
    
    -   If the total number of trips is sufficient (`trips >= totalTrips`), it means `mid` time works. So, we update `result` to `mid` and try to find a smaller possible time by moving the `end` pointer.
    -   If the total number of trips is insufficient (`trips < totalTrips`), we need more time, so we move the `start` pointer to `mid + 1`.
4.  **Result**:
    
    -   The `result` variable holds the minimum time required to complete at least `totalTrips` trips by the end of the loop.
