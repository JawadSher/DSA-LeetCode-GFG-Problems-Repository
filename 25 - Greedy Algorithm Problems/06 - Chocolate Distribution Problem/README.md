<h1 align="center">Chocolate - Distribution - Problem</h1>

## Problem Statement

**Problem URL :** [Chocolate Distribution Problem](https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1)

![image](https://github.com/user-attachments/assets/54b097ca-019e-4257-8a0c-7018f03f25be)

### Problem Explanation
We are given `n` packets of chocolates, each packet containing a certain number of chocolates. We are also given `m` students, and our task is to distribute the packets such that the difference between the largest and smallest number of chocolates distributed to the students is minimized. The problem is essentially about finding a subset of `m` packets such that the difference between the maximum and minimum chocolates in that subset is as small as possible.

#### Example:

**Input**:
- `n = 8` (the number of chocolate packets)
- `m = 5` (the number of students to distribute chocolates)
- `chocolates = [12, 4, 7, 9, 2, 23, 25, 41]`

**Goal**: Select `m` packets such that the difference between the maximum and minimum number of chocolates in any selected subset of `m` packets is minimized.

**Steps**:
1. **Sort the Array**: First, sort the array of chocolates. Sorting brings packets with similar chocolate counts next to each other.
2. **Sliding Window**: Consider a sliding window of size `m`. Move this window over the sorted array and calculate the difference between the maximum and minimum chocolates in each window.
3. **Track the Minimum Difference**: For each window, calculate the difference between the maximum and minimum chocolates, and track the smallest difference encountered.

#### Solution:

- **Sort the array**: `[2, 4, 7, 9, 12, 23, 25, 41]`
- Now, for every subset of `m = 5` packets, compute the difference between the maximum and minimum number of chocolates.

#### Sliding Window Examples:
1. Window 1: `[2, 4, 7, 9, 12]` → Difference = `12 - 2 = 10`
2. Window 2: `[4, 7, 9, 12, 23]` → Difference = `23 - 4 = 19`
3. Window 3: `[7, 9, 12, 23, 25]` → Difference = `25 - 7 = 18`
4. Window 4: `[9, 12, 23, 25, 28]` → Difference = `28 - 9 = 19`
5. Window 5: `[12, 23, 25, 28, 30]` → Difference = `30 - 12 = 18`
6. Window 6: `[23, 25, 28, 30, 40]` → Difference = `40 - 23 = 17`
7. Window 7: `[25, 28, 30, 40, 40]` → Difference = `40 - 25 = 15`
8. Window 8: `[28, 30, 40, 40, 41]` → Difference = `41 - 28 = 13`

**Minimum Difference**: The minimum difference is `10`, which occurs in the first window `[2, 4, 7, 9, 12]`.


### Greedy Algorithm Approach (Step-by-Step):

The **Greedy Algorithm** works in the following steps to find the solution for the Chocolate Distribution Problem:

1. **Sort the Array**: The first step is to sort the array of chocolates in non-decreasing order. This allows us to easily consider the packets that are closer in value.
  
2. **Consider All Possible Windows**: After sorting, you need to consider all possible contiguous subarrays (or windows) of size `m`. For each window, calculate the difference between the largest and smallest values.

3. **Track the Minimum Difference**: As you move through each window, keep track of the minimum difference between the maximum and minimum values in any window.

4. **Return the Minimum Difference**: Once all possible windows are checked, the smallest difference found is the answer.

#### Example:

- **Input**: `chocolates = [12, 4, 7, 9, 2, 23, 25, 41]`, `m = 5`
- **Sorted Array**: `[2, 4, 7, 9, 12, 23, 25, 41]`
- **Sliding Window Size**: `m = 5`

Iterate through the sorted array and check all possible windows of size 5:
1. `[2, 4, 7, 9, 12]`: Max - Min = `12 - 2 = 10`
2. `[4, 7, 9, 12, 23]`: Max - Min = `23 - 4 = 19`
3. `[7, 9, 12, 23, 25]`: Max - Min = `25 - 7 = 18`
4. `[9, 12, 23, 25, 28]`: Max - Min = `28 - 9 = 19`
5. `[12, 23, 25, 28, 30]`: Max - Min = `30 - 12 = 18`
6. `[23, 25, 28, 30, 40]`: Max - Min = `40 - 23 = 17`
7. `[25, 28, 30, 40, 40]`: Max - Min = `40 - 25 = 15`
8. `[28, 30, 40, 40, 41]`: Max - Min = `41 - 28 = 13`

The **minimum difference** is `10` from the first window.

## Problem Solution
```cpp
class Solution {
  public:
    // Function to find the minimum difference between the maximum and minimum values of m selected elements
    int findMinDiff(vector<int>& a, int m) {
        
        // Step 1: Sort the array to bring the closest values together
        sort(a.begin(), a.end());
        
        // Step 2: Initialize two pointers, i and j, to represent the window of m elements
        int i = 0;
        int j = m - 1;
        
        // Step 3: Initialize the variable 'mini' to store the minimum difference found
        int mini = INT_MAX;
        
        // Step 4: Iterate through the array using the sliding window approach
        // The window size is m elements
        while (j < a.size()) {
            // Calculate the difference between the maximum and minimum values in the current window (a[j] and a[i])
            int diff = a[j] - a[i];
            
            // Step 5: Update 'mini' with the smaller value between the current minimum difference and the calculated difference
            mini = min(mini, diff);
            
            // Move the window: increment both i and j to check the next possible set of m elements
            i++;
            j++;
        }
        
        // Step 6: Return the minimum difference found
        return mini;
    }
};
```

## Problem Solution Explanation

1. **Class Declaration**:
   ```cpp
   class Solution {
   ```
   - This line defines the class `Solution`, which contains the solution to the problem. The class will hold the function `findMinDiff`, which is the core function for solving the problem.

2. **Function Declaration**:
   ```cpp
   int findMinDiff(vector<int>& a, int m) {
   ```
   - This line declares the function `findMinDiff` that takes two parameters:
     - `a`: A vector of integers representing the chocolate packet sizes.
     - `m`: The number of students (or the number of packets to distribute).
   - The function returns an integer, which is the minimum difference between the largest and smallest number of chocolates among `m` selected packets.

3. **Sorting the Array**:
   ```cpp
   sort(a.begin(), a.end());
   ```
   - **Explanation**: The array `a` is sorted in non-decreasing order.
   - **Why?**: Sorting helps in easily finding the closest chocolate packet counts, as the solution requires selecting packets that minimize the difference between the maximum and minimum values in a subset.
   - **Example**: If `a = [12, 4, 7, 9, 2, 23, 25, 41]`, after sorting, it becomes `a = [2, 4, 7, 9, 12, 23, 25, 41]`.

4. **Initializing Variables `i`, `j`, and `mini`**:
   ```cpp
   int i = 0;
   int j = m - 1;
   int mini = INT_MAX;
   ```
   - **Explanation**:
     - `i`: Represents the starting index of the sliding window of size `m`.
     - `j`: Represents the ending index of the sliding window.
     - `mini`: This variable will store the smallest difference found between the maximum and minimum values in the window of size `m`.
     - **Example**: If `m = 5`, `i = 0` and `j = 4` initially.

5. **Sliding Window Loop**:
   ```cpp
   while (j < a.size()) {
   ```
   - **Explanation**: The `while` loop iterates as long as `j` is less than the size of the array `a`.
   - The loop represents the sliding window mechanism: for each iteration, we evaluate a window of `m` packets starting from `i` and ending at `j`.

6. **Calculate the Difference**:
   ```cpp
   int diff = a[j] - a[i];
   ```
   - **Explanation**: In this line, we calculate the difference between the maximum and minimum values in the current window (the values at indices `i` and `j`).
   - **Why?**: We want to minimize the difference between the largest and smallest chocolates within a selected set of packets.
   - **Example**: For the window `[2, 4, 7, 9, 12]`, `diff = 12 - 2 = 10`.

7. **Update the Minimum Difference**:
   ```cpp
   mini = min(mini, diff);
   ```
   - **Explanation**: We update `mini` with the minimum value between the current `mini` (which stores the smallest difference found so far) and the current difference `diff`.
   - **Why?**: This ensures that `mini` always contains the smallest difference encountered in any of the sliding windows.
   - **Example**: Initially, `mini = INT_MAX`. After the first window, `mini = 10`.

8. **Move the Window**:
   ```cpp
   i++;
   j++;
   ```
   - **Explanation**: Both `i` and `j` are incremented to move the window one step forward.
   - **Why?**: This shifts the window by one position, allowing us to consider the next possible set of `m` elements.
   - **Example**: For the window `[2, 4, 7, 9, 12]`, after incrementing, `i = 1` and `j = 5`.

9. **Return the Minimum Difference**:
   ```cpp
   return mini;
   ```
   - **Explanation**: Once the loop has processed all possible windows, the function returns the value of `mini`, which holds the minimum difference between the largest and smallest chocolates in any selected subset of `m` packets.
   - **Example**: After considering all windows, `mini = 10` will be returned.


### Example Walkthrough:

For the input:
- `chocolates = [12, 4, 7, 9, 2, 23, 25, 41]`
- `m = 5`

After sorting:
- `a = [2, 4, 7, 9, 12, 23, 25, 41]`

#### Iteration Details:
1. **First Window** (`i = 0, j = 4`): `[2, 4, 7, 9, 12]` → Difference = `12 - 2 = 10`
2. **Second Window** (`i = 1, j = 5`): `[4, 7, 9, 12, 23]` → Difference = `23 - 4 = 19`
3. **Third Window** (`i = 2, j = 6`): `[7, 9, 12, 23, 25]` → Difference = `25 - 7 = 18`
4. **Fourth Window** (`i = 3, j = 7`): `[9, 12, 23, 25, 41]` → Difference = `41 - 9 = 32`

The minimum difference is `10`, which occurs in the first window.


### Time and Space Complexity:

#### Time Complexity:
- **Sorting the Array**: `O(n log n)` where `n` is the number of chocolate packets. This is because the sorting step takes `O(n log n)` time.
- **Sliding Window Calculation**: `O(n)` because we only need to iterate through the array once to calculate the differences and update the minimum difference.

**Overall Time Complexity**: `O(n log n)` because the sorting dominates the overall complexity.

#### Space Complexity:
- **Auxiliary Space**: The algorithm uses only a constant amount of extra space, regardless of the size of the input (other than the input array itself).
  
**Overall Space Complexity**: `O(1)` (constant space).

In summary, the time complexity of this solution is `O(n log n)` due to the sorting step, and the space complexity is `O(1)` as we use only a fixed amount of extra space.



