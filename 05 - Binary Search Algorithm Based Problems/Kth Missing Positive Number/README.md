# Problem Explanation: Kth Missing Positive Number

The problem asks us to find the k-th missing positive number in a given sorted array. A positive number is considered missing if it is not present in the array.

### Example

**Input:**

-   `arr = [2, 3, 4, 7, 11]`
-   `k = 5`

**Output:**

-   The 5th missing positive number is `9`.

### Explanation

For the array `[2, 3, 4, 7, 11]`, the first few missing positive numbers are:

1.  1 (missing)
2.  5 (missing)
3.  6 (missing)
4.  8 (missing)
5.  9 (missing)

Hence, the 5th missing positive number is `9`.

### Approach

This approach uses binary search to efficiently find the k-th missing positive number. Here’s a detailed explanation of the code:

### Code Explanation

Here's the step-by-step explanation of the given code:


```
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start = 0;
        int end = arr.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            // Check how many numbers are missing before arr[mid]
            if ((arr[mid] - (mid + 1)) < k) {
                start = mid + 1;  // Move to the right half
            } else {
                end = mid - 1;  // Move to the left half
            }
        }
        // start is the index where k-th missing number is located
        return start + k;
    }
};
``` 

1.  **Initialization:**
    
    -   `start` is initialized to `0`, which is the beginning of the array.
    -   `end` is initialized to `arr.size() - 1`, which is the last index of the array.
2.  **Binary Search Loop:**
    
    -   The loop continues as long as `start` is less than or equal to `end`.
    -   Calculate `mid` as the middle index between `start` and `end`.
    -   Check the number of missing integers before the `mid` index: `arr[mid] - (mid + 1)`.
    -   If the number of missing integers is less than `k`, it means the k-th missing number is in the right half of the array. Move the `start` to `mid + 1`.
    -   Otherwise, move the `end` to `mid - 1`.
3.  **Post-Loop Calculation:**
    
    -   After the loop, `start` will point to the position where the k-th missing positive integer should be.
    -   The k-th missing positive number is given by `start + k`.

## Approach

#### Problem Description

The "Kth Missing Positive Number" problem requires us to find the k-th missing positive integer from a given sorted array of positive integers.

1.  **Initialization:**
    
    -   Start with `start` at the beginning of the array and `end` at the last index.
2.  **Binary Search:**
    
    -   Use binary search to find the position where the k-th missing positive number would be located.
    -   In each iteration, calculate the mid-point and determine how many positive numbers are missing up to that point.
    -   Adjust the `start` and `end` pointers based on the comparison.
3.  **Post-Loop Calculation:**
    
    -   After the binary search loop, compute the k-th missing positive number using the final value of `start`.

#### Example

For an input array `[2, 3, 4, 7, 11]` and `k = 5`, the output is `9` because the 5th missing positive number is `9`.

This approach ensures we efficiently find the k-th missing positive number by leveraging binary search, making the solution both optimal and easy to understand.
