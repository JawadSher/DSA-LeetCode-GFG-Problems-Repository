
# Painters Partition Problem

## Problem Overview

The **painters allocation problem** is similar to the book allocation problem but applied to a different context. It involves distributing painting work among a given number of painters such that the maximum amount of boards any painter has to paint is minimized. This ensures that the workload is balanced as evenly as possible among all painters.

### Detailed Problem Statement

Given:

-   `b` boards, each with a certain length.
-   `p` painters.

The goal is to allocate boards to painters such that:

1.  Each painter gets at least one board.
2.  The boards assigned to a painter are contiguous (i.e., each painter paints a sequence of boards).
3.  The maximum number of boards assigned to any painter is minimized.

### Constraints

-   Each board can only be assigned to one painter.
-   The number of painters (`p`) is less than or equal to the number of boards (`b`).

### Example

Consider `b = 4` boards with lengths `[10, 10, 10, 10]` and `p = 2` painters.

Possible ways to allocate the boards:

1.  Painter 1 paints boards [10, 10], and Painter 2 paints boards [10, 10].
    -   Maximum boards any painter paints = max(20, 20) = 20.
2.  Painter 1 paints boards [10, 10, 10], and Painter 2 paints board [10].
    -   Maximum boards any painter paints = max(30, 10) = 30.

Among all possible allocations, the allocation where Painter 1 paints boards [10, 10] and Painter 2 paints boards [10, 10] minimizes the maximum number of boards any painter has to paint (which is 20 boards).

## Solution Explanation

The provided code is a solution to the painters allocation problem. It involves two main functions: `is_possible` and `boards_allocation`. Here's a detailed explanation of each part:

### Function: `is_possible`

This function checks if it is possible to allocate boards such that no painter paints more than `mid` boards.


```
int is_possible(int boards_arr[], int b, int p, int mid) {
    int boards = 0;
    int painter = 1;
    
    for(int i = 0; i < b; i++) {
        if(boards + boards_arr[i] <= mid) {
            boards += boards_arr[i]; // Assign board to the current painter
        } else {
            painter++; // Move to the next painter
            if(boards_arr[i] > mid || painter > p) {
                return false; // If a single board exceeds mid or painters exceed the limit, return false
            }
            boards = boards_arr[i]; // Assign the board to the new painter
        }
    }
    return true; // Return true if allocation is possible
}
``` 

### Function: `boards_allocation`

This function finds the minimum number of boards a painter has to paint by using binary search.

```
int boards_allocation(int boards_arr[], int b, int p) {
    int sum = 0;
    for(int i = 0; i < b; i++) {
        sum += boards_arr[i]; // Calculate total sum of boards
    }
    
    int start = 0;
    int end = sum;
    int ans = -1;
    int mid;
    
    while(start <= end) {
        mid = start + (end - start) / 2;
        
        if(is_possible(boards_arr, b, p, mid)) {
            ans = mid;
            end = mid - 1; // Try to minimize the maximum boards
        } else {
            start = mid + 1; // Increase the minimum limit of boards
        }
    }
    return ans;
}
``` 

### Main Function


```
int main() {
    int boards[4] = {10, 10, 10, 10};
    int painters = 2;
    int minimum_boards = boards_allocation(boards, 4, painters);
    cout << "Minimum Number of boards assign to 1 painter: " << minimum_boards;
    return 0;
}
``` 

### Explanation

1.  **Initialization**:
    
    -   `boards` array contains the lengths of each board.
    -   `painters` is the number of painters.
2.  **Total Boards Calculation**:
    
    -   Calculate the total sum of board lengths to set the range for binary search.
3.  **Binary Search**:
    
    -   Use binary search to find the minimum number of boards by iteratively checking if a given middle point (`mid`) is a possible solution.
    -   Adjust the search range based on whether the current `mid` is a feasible solution.
4.  **Result**:
    
    -   The final answer (`ans`) gives the minimum number of boards that can be allocated to a painter without exceeding the limit.

## Time Complexity Analysis

### Explanation

The time complexity of the provided solution can be broken down as follows:

1.  **Sum Calculation**:
    
    -   Calculating the total sum of board lengths in the `boards_allocation` function takes `O(b)` time because it involves iterating through all `b` boards.
2.  **Binary Search**:
    
    -   The binary search is performed over the range from 0 to the sum of board lengths (`sum`), which gives us a range of `O(sum)`.
3.  **Feasibility Check (`is_possible` function)**:
    
    -   Each call to `is_possible` checks whether a given mid value can be a valid solution. This involves iterating through all `b` boards, giving a time complexity of `O(b)`.

The binary search splits the range into half repeatedly, resulting in `O(log(sum))` iterations. For each iteration, the `is_possible` function is called, which takes `O(b)` time.

### Combined Time Complexity

The combined time complexity of the solution is: O(b+b⋅log⁡(sum))O(b + b \cdot \log(\text{sum}))O(b+b⋅log(sum))

Here, `b` is for the initial sum calculation, and `b \cdot \log(\text{sum})` is for the binary search with feasibility checks.

Since `sum` is the total number of boards, in the worst case, `sum` can be `b \cdot \text{max(boards)}` where `max(boards)` is the maximum length of a single board. Therefore, the time complexity can also be written as: O(b⋅log⁡(b⋅max(boards)))O(b \cdot \log(b \cdot \text{max(boards)}))O(b⋅log(b⋅max(boards)))

### Detailed Steps in Binary Search

1.  **Initial Setup**:
    
    -   Compute the total sum of board lengths (`sum`).
    -   Set `start = 0` and `end = sum`.
    -   Initialize `ans = -1`.
2.  **Binary Search Loop**:
    
    -   Calculate `mid = start + (end - start) / 2`.
    -   Check if it is possible to allocate boards such that no painter paints more than `mid` boards using the `is_possible` function.
        -   If true, update `ans` to `mid` and move the end pointer (`end = mid - 1`) to search for a smaller possible maximum.
        -   If false, move the start pointer (`start = mid + 1`) to search for a larger possible maximum.
3.  **Result**:
    
    -   The final value of `ans` is the minimum possible value of the maximum number of boards any painter has to paint.

## Conclusion

This solution efficiently finds the optimal allocation of boards to painters, ensuring the workload is balanced. The detailed time complexity analysis confirms that the solution is efficient even for large inputs.
