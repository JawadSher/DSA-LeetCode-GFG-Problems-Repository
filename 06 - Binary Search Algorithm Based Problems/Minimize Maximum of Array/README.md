# Minimize Maximum of Array

You are given an array of non-negative integers. The goal is to minimize the maximum value of the array after performing any number of allowed operations. The allowed operation is:

-   Choose an integer `i` such that `1 <= i < n` and `nums[i] > 0`.
-   Decrease `nums[i]` by 1 and increase `nums[i-1]` by 1.

The task is to find the minimum possible value of the maximum integer in the array after performing the allowed operations any number of times.

### Approach Explanation

We can use a binary search to find this minimum possible value. Here’s a step-by-step explanation:

1.  **Binary Search Setup**:
    
    -   Initialize `max_s` (start) to `0` and `max_e` (end) to the maximum value in the array.
    -   The reason for this is that the minimum possible value of the maximum integer can't be less than `0` or more than the maximum element in the array.
2.  **Greedy Validation Function (`isValid`)**:
    
    -   Create a helper function `isValid` to check if it's possible to reduce the array such that no element exceeds `exp_mid` (expected maximum value).
    -   Start from the end of the array and move backward. If an element `arr[i]` exceeds `exp_mid`, reduce it to `exp_mid` and transfer the excess to the previous element `arr[i-1]`.
3.  **Binary Search Execution**:
    
    -   Perform binary search within the range defined by `max_s` and `max_e`.
    -   For each middle value `max_mid`, use the `isValid` function to check if this value can be the maximum value of the array.
    -   Adjust the search range based on the result of `isValid`.

### Code Explanation

Now let's explain the code step by step:

```
class Solution {
public:
    // Helper function to check if it is possible to make all elements <= exp_mid
    bool isValid(vector<int>& nums, int exp_mid, int n) {
        // Create a copy of nums with long long type to handle large values
        vector<long long> arr(nums.begin(), nums.end());

        // Start from the end and move backward
        for (int i = n - 1; i > 0; i--) {
            // If current element is greater than exp_mid
            if (arr[i] > exp_mid) {
                // Calculate the excess
                long long buffer = arr[i] - exp_mid;
                // Set current element to exp_mid
                arr[i] = exp_mid;
                // Transfer the excess to the previous element
                arr[i - 1] += buffer;
            }
        }

        // Check if the first element is within the limit
        return arr[0] <= exp_mid;
    }

    // Function to find the minimum possible value of the maximum integer in the array
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();

        // Initialize binary search range
        int max_s = 0;
        int max_e = *max_element(nums.begin(), nums.end());

        int result = 0;

        // Perform binary search
        while (max_s <= max_e) {
            int max_mid = max_s + (max_e - max_s) / 2;

            // Check if max_mid can be the maximum value
            if (isValid(nums, max_mid, n)) {
                result = max_mid;
                max_e = max_mid - 1; // Try for a smaller value
            } else {
                max_s = max_mid + 1; // Try for a larger value
            }
        }

        return result;
    }
};
``` 

### Step-by-Step Execution

1.  **Initialize the Binary Search Range**:
    
    -   `max_s = 0`
    -   `max_e = *max_element(nums.begin(), nums.end())`
2.  **Binary Search Loop**:
    
    -   Calculate `max_mid` as the midpoint of the current search range.
    -   Call `isValid(nums, max_mid, n)` to check if `max_mid` can be the maximum value of the array.
3.  **Validation in `isValid` Function**:
    
    -   Create a copy of `nums` to `arr` with type `long long` to avoid overflow.
    -   Traverse the array from the end to the beginning.
    -   If an element `arr[i]` exceeds `exp_mid`, transfer the excess to `arr[i-1]`.
4.  **Adjust Binary Search Range**:
    
    -   If `isValid` returns `true`, update `result` to `max_mid` and move the end of the range (`max_e`) to `mid - 1`.
    -   If `isValid` returns `false`, move the start of the range (`max_s`) to `mid + 1`.
5.  **Return the Result**:
    
    -   After the binary search loop, `result` contains the minimum possible value of the maximum integer in the array.

### Example 1: `{3, 7, 1, 6}`

#### Initial Setup

-   `max_s = 0`
-   `max_e = 7` (maximum value in the array)
-   `result = 0`

#### Binary Search Iterations

1.  **First Iteration**:
    
    -   `max_mid = (0 + 7) / 2 = 3`
    -   Call `isValid(nums, 3, 4)`:
        -   Check from end to start:
            -   `arr[3] (6) > 3`: Reduce `arr[3]` to `3`, transfer `3` to `arr[2]`: `arr = {3, 7, 4, 3}`
            -   `arr[2] (4) > 3`: Reduce `arr[2]` to `3`, transfer `1` to `arr[1]`: `arr = {3, 8, 3, 3}`
            -   `arr[1] (8) > 3`: Reduce `arr[1]` to `3`, transfer `5` to `arr[0]`: `arr = {8, 3, 3, 3}`
        -   `arr[0] (8) > 3`: Invalid
    -   `isValid` returns `false`, so update `max_s = 4`.
2.  **Second Iteration**:
    
    -   `max_mid = (4 + 7) / 2 = 5`
    -   Call `isValid(nums, 5, 4)`:
        -   Check from end to start:
            -   `arr[3] (6) > 5`: Reduce `arr[3]` to `5`, transfer `1` to `arr[2]`: `arr = {3, 7, 2, 5}`
            -   `arr[2] (2) <= 5`: No change
            -   `arr[1] (7) > 5`: Reduce `arr[1]` to `5`, transfer `2` to `arr[0]`: `arr = {5, 5, 2, 5}`
        -   `arr[0] (5) <= 5`: Valid
    -   `isValid` returns `true`, so update `result = 5` and `max_e = 4`.
3.  **Third Iteration**:
    
    -   `max_mid = (4 + 4) / 2 = 4`
    -   Call `isValid(nums, 4, 4)`:
        -   Check from end to start:
            -   `arr[3] (6) > 4`: Reduce `arr[3]` to `4`, transfer `2` to `arr[2]`: `arr = {3, 7, 3, 4}`
            -   `arr[2] (3) <= 4`: No change
            -   `arr[1] (7) > 4`: Reduce `arr[1]` to `4`, transfer `3` to `arr[0]`: `arr = {6, 4, 3, 4}`
        -   `arr[0] (6) > 4`: Invalid
    -   `isValid` returns `false`, so update `max_s = 5`.

#### End of Binary Search

-   `max_s = 5`
-   `max_e = 4`
-   `result = 5`

**Result**: `5`

### Example 2: `{1, 10, 1, 1}`

#### Initial Setup

-   `max_s = 0`
-   `max_e = 10` (maximum value in the array)
-   `result = 0`

#### Binary Search Iterations

1.  **First Iteration**:
    
    -   `max_mid = (0 + 10) / 2 = 5`
    -   Call `isValid(nums, 5, 4)`:
        -   Check from end to start:
            -   `arr[3] (1) <= 5`: No change
            -   `arr[2] (1) <= 5`: No change
            -   `arr[1] (10) > 5`: Reduce `arr[1]` to `5`, transfer `5` to `arr[0]`: `arr = {6, 5, 1, 1}`
        -   `arr[0] (6) > 5`: Invalid
    -   `isValid` returns `false`, so update `max_s = 6`.
2.  **Second Iteration**:
    
    -   `max_mid = (6 + 10) / 2 = 8`
    -   Call `isValid(nums, 8, 4)`:
        -   Check from end to start:
            -   `arr[3] (1) <= 8`: No change
            -   `arr[2] (1) <= 8`: No change
            -   `arr[1] (10) > 8`: Reduce `arr[1]` to `8`, transfer `2` to `arr[0]`: `arr = {3, 8, 1, 1}`
        -   `arr[0] (3) <= 8`: Valid
    -   `isValid` returns `true`, so update `result = 8` and `max_e = 7`.
3.  **Third Iteration**:
    
    -   `max_mid = (6 + 7) / 2 = 6`
    -   Call `isValid(nums, 6, 4)`:
        -   Check from end to start:
            -   `arr[3] (1) <= 6`: No change
            -   `arr[2] (1) <= 6`: No change
            -   `arr[1] (10) > 6`: Reduce `arr[1] to` 6`, transfer` 4`to`arr[0]`:` arr = {5, 6, 1, 1}`
        -   `arr[0] (5) <= 6`: Valid
    -   `isValid` returns `true`, so update `result = 6` and `max_e = 5`.
4.  **Fourth Iteration**:
    
    -   `max_mid = (6 + 5) / 2 = 5`
    -   Call `isValid(nums, 5, 4)`:
        -   Check from end to start:
            -   `arr[3] (1) <= 5`: No change
            -   `arr[2] (1) <= 5`: No change
            -   `arr[1] (10) > 5`: Reduce `arr[1] to` 5`, transfer` 5`to`arr[0]`:` arr = {6, 5, 1, 1}`
        -   `arr[0] (6) > 5`: Invalid
    -   `isValid` returns `false`, so update `max_s = 6`.

#### End of Binary Search

-   `max_s = 6`
-   `max_e = 5`
-   `result = 6`

**Result**: `6`

### Summary

-   **Binary Search**: Narrow down the possible values of the maximum element.
-   **Validation Function**: Check if a given value can be the maximum element by redistributing excess values to the left.
