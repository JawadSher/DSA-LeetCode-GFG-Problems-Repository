<h1 align='center'>Search - a - 2D - Matrix - II</h1>

## Problem Statement

**Problem URL :** [Search a 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii/description/)

![image](https://github.com/user-attachments/assets/ed101b00-5489-4a1f-a159-76d8580be411)
![image](https://github.com/user-attachments/assets/e6bc87ed-994a-4851-8924-e9a8ef444e46)

## Problem Explanation

We are given a 2D matrix where:
- Each row is sorted in ascending order.
- The first integer of each row is greater than the last integer of the previous row.

We need to determine if a specific target value exists in this matrix.

### Approach:
The solution involves using **binary search** within each row of the matrix. Since each row is sorted, binary search is an efficient way to find the target in a row.


## Problem Solution
```cpp
class Solution {
    
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int i = 0; i < rows; i++){
            int start = 0;
            int end = cols-1;

            while(start <= end){
                int mid = start + (end - start)/2;

                if(matrix[i][mid] == target){
                   return true;
                }else if(matrix[i][mid] > target){
                    end = mid - 1;
                }else{
                    start = mid + 1;
                }
            }
        }

        return false;
    }
};
```

## Problem Solution Explanation

Here is a step-by-step explanation of the approach:

1. **Matrix Dimensions**:
   First, the code calculates the number of rows (`rows`) and the number of columns (`cols`) in the matrix:
   ```cpp
   int rows = matrix.size();
   int cols = matrix[0].size();
   ```
   This helps the program know how many rows and columns are available for searching.

2. **Loop Over Each Row**:
   The code loops through each row using a `for` loop:
   ```cpp
   for(int i = 0; i < rows; i++){
   ```
   This loop will go row by row, performing binary search on each row.

3. **Binary Search in Each Row**:
   For each row, the code performs binary search to efficiently search for the target:
   
   - **Initialization**:
     Two pointers, `start` and `end`, are initialized. `start` points to the beginning of the row (index 0), and `end` points to the last element of the row (index `cols - 1`).
     ```cpp
     int start = 0;
     int end = cols - 1;
     ```

   - **Binary Search Loop**:
     While the `start` pointer is less than or equal to the `end` pointer, the binary search continues:
     ```cpp
     while(start <= end){
     ```
     This loop will keep halving the search range until the target is found or the entire row has been searched.

     - **Find Middle Index**:
       The middle index of the current search range is calculated:
       ```cpp
       int mid = start + (end - start) / 2;
       ```
       This `mid` index is the middle element of the current range.

     - **Check Middle Value**:
       The code checks if the value at `mid` is equal to the target:
       ```cpp
       if(matrix[i][mid] == target){
           return true;
       }
       ```
       If the value matches the target, it immediately returns `true`, meaning the target was found in the matrix.

     - **Adjust Search Range**:
       - If the value at `mid` is greater than the target, the target must be in the left half of the row, so the `end` pointer is moved to `mid - 1`:
         ```cpp
         else if(matrix[i][mid] > target){
             end = mid - 1;
         }
         ```
       - If the value at `mid` is less than the target, the target must be in the right half of the row, so the `start` pointer is moved to `mid + 1`:
         ```cpp
         else{
             start = mid + 1;
         }
         ```

4. **Move to Next Row**:
   If the binary search in the current row does not find the target, the loop moves to the next row. The process is repeated for each row in the matrix.

5. **Return False**:
   If the binary search has completed all rows and still hasn't found the target, the code returns `false`:
   ```cpp
   return false;
   ```

### Why Binary Search?
- Binary search is used because it allows us to eliminate half of the search space at each step, making the search much faster than a linear search.
- Since each row is sorted, binary search is ideal for reducing the number of comparisons needed to find the target.

### Time Complexity:
- **Outer Loop**: We are iterating over each row, so the loop runs `m` times, where `m` is the number of rows.
- **Binary Search on Each Row**: For each row, binary search is performed on `n` elements (where `n` is the number of columns). The time complexity of binary search is \(O(\log n)\).
  
Thus, the overall time complexity is \(O(m \log n)\), where:
- `m` is the number of rows.
- `n` is the number of columns.

### Space Complexity:
- The space complexity of the solution is \(O(1)\) because we are only using a fixed amount of extra space (for variables like `start`, `end`, and `mid`), regardless of the size of the input matrix.

### Example:
Consider the matrix:
```
[
  [1, 3, 5, 7],
  [10, 11, 16, 20],
  [23, 30, 34, 60]
]
```
- Suppose the target is `3`. The binary search starts with the first row `[1, 3, 5, 7]`. It checks the middle element `3`, which matches the target, so it returns `true`.

If the target were `13`, the binary search would continue through the rows but would eventually return `false` as `13` does not exist in the matrix.

### Summary:
- The code efficiently searches for the target in a 2D matrix by performing binary search on each row.
- The time complexity is \(O(m \log n)\), and the space complexity is \(O(1)\).

