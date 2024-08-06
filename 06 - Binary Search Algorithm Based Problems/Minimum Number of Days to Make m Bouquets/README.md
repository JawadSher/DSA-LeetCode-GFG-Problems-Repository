# Minimum Number of Days to Make Bouquets

You are given:

- `bloomDay`: A vector where `bloomDay[i]` represents the day on which the `i-th` flower blooms.
- `m`: The number of bouquets you need to make.
- `k`: The number of consecutive flowers needed to make one bouquet.

Your task is to determine the minimum number of days required to make exactly `m` bouquets. Each bouquet requires `k` consecutive flowers, and you can only use flowers that have bloomed by a certain day.

### Approach

To solve this problem, you can use a **binary search** approach combined with a helper function to check if it's possible to make `m` bouquets by a given day.

Here’s how the solution works:

1. **Binary Search Setup:**
   - Define the range of days to search within. The minimum number of days is `0`, and the maximum number of days is the maximum value in `bloomDay` (since a bouquet can't be made before the last flower blooms).

2. **Check Feasibility with Helper Function:**
   - For a given day `mid`, use a helper function to check if it's possible to make `m` bouquets with the flowers that have bloomed by day `mid`.

3. **Adjust Search Range:**
   - If you can make at least `m` bouquets by day `mid`, then try to find a smaller number of days (i.e., adjust the search range to the left).
   - If not, increase the number of days (i.e., adjust the search range to the right).


Certainly! Let’s explain the code line by line for the problem of finding the minimum number of days required to make exactly `m` bouquets, where each bouquet requires `k` consecutive flowers.

### Code Explanation

```cpp
class Solution {
public:
    // Helper function to count how many bouquets can be made by day `mid`
    int make_bouquet(int mid, vector<int>& bloomDay, int m, int k) {
        int bouquet_count = 0; // Number of bouquets made
        int flowers_count = 0; // Number of consecutive flowers that have bloomed

        // Iterate over each flower
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                flowers_count++; // Increment consecutive bloomed flowers
            } else {
                flowers_count = 0; // Reset if flower hasn't bloomed
            }

            // If we have enough consecutive flowers to make a bouquet
            if (flowers_count == k) {
                bouquet_count++; // Make a bouquet
                flowers_count = 0; // Reset for the next bouquet
            }
        }
        return bouquet_count; // Return the number of bouquets made
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int start_day = 0; // Minimum day to start searching
        int end_day = *max_element(bloomDay.begin(), bloomDay.end()); // Maximum day to search up to

        int result = -1; // Initialize result to -1 (indicating no valid day found yet)

        // Binary search to find the minimum number of days
        while (start_day <= end_day) {
            int mid = start_day + (end_day - start_day) / 2; // Calculate the middle day

            // Check if we can make `m` bouquets by day `mid`
            if (make_bouquet(mid, bloomDay, m, k) >= m) {
                result = mid; // Update result if possible
                end_day = mid - 1; // Try for a smaller number of days
            } else {
                start_day = mid + 1; // Increase the number of days
            }
        }

        return result; // Return the minimum number of days found
    }
};
```

### Detailed Line-by-Line Explanation

#### Helper Function: `make_bouquet`

```cpp
int make_bouquet(int mid, vector<int>& bloomDay, int m, int k) {
    int bouquet_count = 0; // Number of bouquets made
    int flowers_count = 0; // Number of consecutive flowers that have bloomed
```
- **`int bouquet_count = 0;`**: Initializes the count of bouquets that can be made by day `mid`.
- **`int flowers_count = 0;`**: Initializes the count of consecutive flowers that have bloomed.

```cpp
    // Iterate over each flower
    for (int i = 0; i < bloomDay.size(); i++) {
        if (bloomDay[i] <= mid) {
            flowers_count++; // Increment consecutive bloomed flowers
        } else {
            flowers_count = 0; // Reset if flower hasn't bloomed
        }
```
- **`for (int i = 0; i < bloomDay.size(); i++)`**: Loops through each flower.
- **`if (bloomDay[i] <= mid)`**: Checks if the flower has bloomed by day `mid`.
  - **`flowers_count++;`**: If the flower has bloomed, increments the count of consecutive bloomed flowers.
  - **`else { flowers_count = 0; }`**: If the flower hasn’t bloomed, resets the count of consecutive flowers.

```cpp
        // If we have enough consecutive flowers to make a bouquet
        if (flowers_count == k) {
            bouquet_count++; // Make a bouquet
            flowers_count = 0; // Reset for the next bouquet
        }
    }
    return bouquet_count; // Return the number of bouquets made
}
```
- **`if (flowers_count == k)`**: Checks if there are enough consecutive flowers to make a bouquet.
  - **`bouquet_count++;`**: Increments the count of bouquets made.
  - **`flowers_count = 0;`**: Resets the count for the next bouquet.
- **`return bouquet_count;`**: Returns the total number of bouquets made by day `mid`.

#### Main Function: `minDays`

```cpp
int minDays(vector<int>& bloomDay, int m, int k) {
    int start_day = 0; // Minimum day to start searching
    int end_day = *max_element(bloomDay.begin(), bloomDay.end()); // Maximum day to search up to
```
- **`int start_day = 0;`**: Initializes the lower bound of the search range (earliest possible day).
- **`int end_day = *max_element(bloomDay.begin(), bloomDay.end());`**: Finds the maximum bloom day from `bloomDay` to set the upper bound of the search range (latest possible day).

```cpp
    int result = -1; // Initialize result to -1 (indicating no valid day found yet)
```
- **`int result = -1;`**: Initializes the result variable, indicating no valid day found yet.

```cpp
    // Binary search to find the minimum number of days
    while (start_day <= end_day) {
        int mid = start_day + (end_day - start_day) / 2; // Calculate the middle day
```
- **`while (start_day <= end_day)`**: Performs binary search while the search range is valid.
- **`int mid = start_day + (end_day - start_day) / 2;`**: Calculates the midpoint of the current search range to avoid overflow.

```cpp
        // Check if we can make `m` bouquets by day `mid`
        if (make_bouquet(mid, bloomDay, m, k) >= m) {
            result = mid; // Update result if possible
            end_day = mid - 1; // Try for a smaller number of days
        } else {
            start_day = mid + 1; // Increase the number of days
        }
    }
```
- **`if (make_bouquet(mid, bloomDay, m, k) >= m)`**: Checks if it's possible to make at least `m` bouquets by day `mid` using the helper function.
  - **`result = mid;`**: Updates the result with the current `mid` if it's possible to make `m` bouquets.
  - **`end_day = mid - 1;`**: Adjusts the search range to check for a smaller number of days.
- **`else { start_day = mid + 1; }`**: If not enough bouquets can be made, increases the number of days.

```cpp
    return result; // Return the minimum number of days found
}
```
- **`return result;`**: Returns the minimum number of days needed to make exactly `m` bouquets.

### Summary

1. **Helper Function (`make_bouquet`)**: Determines the number of bouquets that can be made by a given day using a linear scan of the `bloomDay` array.
2. **Binary Search (`minDays`)**: Uses binary search to efficiently find the minimum day by adjusting the search range based on the feasibility of making `m` bouquets.

### Time Complexity

1. **Binary Search Complexity:** O(log D), where `D` is the maximum number of days.
2. **Bouquet Calculation Complexity:** O(N), where `N` is the number of flowers.

Combining these, the overall time complexity is **O(N log D)**, where `N` is the number of flowers and `D` is the maximum number of days.
