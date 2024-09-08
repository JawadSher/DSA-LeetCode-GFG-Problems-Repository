<h1 align='center'>Spiral - Matrix</h1>

## Problem Statement

**Problem URL :** [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/)

![image](https://github.com/user-attachments/assets/829fa3ba-aa25-4589-9980-5d26e665b980)
![image](https://github.com/user-attachments/assets/cfbffb9c-2daa-43df-a826-01d0395802aa)

## Problem Solution Approach

1. **Initial Boundaries**: 
   - `top`: The first row that hasn't been traversed yet. Initialized to `0`.
   - `bottom`: The last row that hasn't been traversed yet. Initialized to `matrix.size() - 1` (the last row index).
   - `left`: The first column that hasn't been traversed yet. Initialized to `0`.
   - `right`: The last column that hasn't been traversed yet. Initialized to `matrix[0].size() - 1` (the last column index).
   
2. **Spiral Traversal**:
   - You perform the traversal in four directions:
     1. **Left to right** (on the top row).
     2. **Top to bottom** (on the rightmost column).
     3. **Right to left** (on the bottom row).
     4. **Bottom to top** (on the leftmost column).
   - After traversing in one direction, you shrink the corresponding boundary (e.g., after traversing the top row, increase `top` to exclude that row).
   - Continue this process until the boundaries cross each other (i.e., `top > bottom` or `left > right`).

### Example: 

Consider the following 4x4 matrix:

```
[
  [1,  2,  3,  4],
  [5,  6,  7,  8],
  [9,  10, 11, 12],
  [13, 14, 15, 16]
]
```

- **Step 1**: Start at the top-left corner with the initial boundaries: 
  - `top = 0`, `bottom = 3`, `left = 0`, `right = 3`.
  
  Traverse **left to right** on the top row (i.e., `top = 0`):
  - Add elements: `[1, 2, 3, 4]`.
  - After traversing, increment `top` to 1, so the new boundary for `top` is row 1.
  
- **Step 2**: Traverse **top to bottom** on the rightmost column (i.e., `right = 3`):
  - Add elements: `[8, 12, 16]`.
  - After traversing, decrement `right` to 2, so the new boundary for `right` is column 2.

- **Step 3**: Traverse **right to left** on the bottom row (i.e., `bottom = 3`):
  - Add elements: `[15, 14, 13]`.
  - After traversing, decrement `bottom` to 2, so the new boundary for `bottom` is row 2.

- **Step 4**: Traverse **bottom to top** on the leftmost column (i.e., `left = 0`):
  - Add elements: `[9, 5]`.
  - After traversing, increment `left` to 1, so the new boundary for `left` is column 1.

At this point, the boundaries are:
- `top = 1`, `bottom = 2`, `left = 1`, `right = 2`.

- **Step 5**: Traverse **left to right** on the second row (i.e., `top = 1`):
  - Add elements: `[6, 7]`.
  - After traversing, increment `top` to 2.

- **Step 6**: Traverse **top to bottom** on the second-to-last column (i.e., `right = 2`):
  - Add elements: `[11]`.
  - After traversing, decrement `right` to 1.

- **Step 7**: Traverse **right to left** on the second-to-last row (i.e., `bottom = 2`):
  - Add elements: `[10]`.
  - After traversing, decrement `bottom` to 1.

At this point, the boundaries have crossed (`top > bottom` and `left > right`), so the loop ends.

The final spiral order for this matrix is:
```
[1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]
```
## Problem Solution
```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0;
        int left = 0;

        int bottom = matrix.size() -1;
        int right = matrix[0].size() -1;
        vector<int> result;

        if(matrix.empty()) return result;

        while(top <= bottom && left <= right){
           for(int i = left; i <= right; i++){
            result.push_back(matrix[top][i]);
           }
           top++;

           for(int i = top; i <= bottom; i++){
             result.push_back(matrix[i][right]);
           }
           right--;

           if(top <= bottom){
            for(int i = right; i >= left; i--){
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
           }
           
           if(left <= right){
            for(int i = bottom; i >= top; i--){
                 result.push_back(matrix[i][left]);
            }
            left++;
           }
        }

        return result;
    }
};
```

## Problem Solution Explanation
Certainly! Let's go through the `spiralOrder` function line by line and explain each part in detail.

```cpp
vector<int> spiralOrder(vector<vector<int>>& matrix) {
```
- **Line Explanation**: This is the function header. The function is named `spiralOrder` and it accepts a 2D vector (matrix) as an input. It returns a `vector<int>` which contains the elements of the matrix in spiral order.


```cpp
    int top = 0;
    int left = 0;
```
- **Line Explanation**: These variables define the current boundaries of the rows and columns. 
  - `top = 0`: This is the index of the topmost row that hasn't been traversed yet.
  - `left = 0`: This is the index of the leftmost column that hasn't been traversed yet.


```cpp
    int bottom = matrix.size() - 1;
    int right = matrix[0].size() - 1;
```
- **Line Explanation**: These variables define the bottom and right boundaries.
  - `bottom = matrix.size() - 1`: This is the index of the bottommost row (last row) that hasn't been traversed yet.
  - `right = matrix[0].size() - 1`: This is the index of the rightmost column (last column) that hasn't been traversed yet.


```cpp
    vector<int> result;
```
- **Line Explanation**: This initializes an empty vector `result` to store the elements of the matrix in spiral order.


```cpp
    if (matrix.empty()) return result;
```
- **Line Explanation**: This checks if the matrix is empty (has no elements). If the matrix is empty, the function immediately returns the empty `result` vector since there is nothing to traverse.


```cpp
    while (top <= bottom && left <= right) {
```
- **Line Explanation**: This is the main loop for the spiral traversal. The loop runs as long as the `top` boundary is less than or equal to the `bottom` boundary and the `left` boundary is less than or equal to the `right` boundary. This ensures that there are still rows and columns left to traverse.


```cpp
        for (int i = left; i <= right; i++) {
            result.push_back(matrix[top][i]);
        }
```
- **Line Explanation**: This first `for` loop traverses the **top row** from left to right.
  - `i` goes from `left` to `right`, and elements from the `top` row are added to `result`.
  - After this loop, the entire top row is traversed, so we can move the `top` boundary down.



```cpp
        top++;
```
- **Line Explanation**: After traversing the top row, we increment the `top` boundary to exclude the row that was just visited. This reduces the matrix area by one row.


```cpp
        for (int i = top; i <= bottom; i++) {
            result.push_back(matrix[i][right]);
        }
```
- **Line Explanation**: This `for` loop traverses the **rightmost column** from top to bottom.
  - `i` goes from `top` to `bottom`, and elements from the `right` column are added to `result`.
  - After this loop, the rightmost column is fully traversed, so we can move the `right` boundary left.



```cpp
        right--;
```
- **Line Explanation**: After traversing the rightmost column, we decrement the `right` boundary to exclude the column that was just visited. This reduces the matrix area by one column.



```cpp
        if (top <= bottom) {
```
- **Line Explanation**: This condition checks if there are still rows left to traverse (i.e., the top boundary is still less than or equal to the bottom boundary).



```cpp
            for (int i = right; i >= left; i--) {
                result.push_back(matrix[bottom][i]);
            }
```
- **Line Explanation**: If there are rows left, this `for` loop traverses the **bottom row** from right to left.
  - `i` goes from `right` to `left`, and elements from the `bottom` row are added to `result`.
  - After this loop, the entire bottom row is traversed, so we can move the `bottom` boundary up.



```cpp
            bottom--;
```
- **Line Explanation**: After traversing the bottom row, we decrement the `bottom` boundary to exclude the row that was just visited. This reduces the matrix area by one row.



```cpp
        if (left <= right) {
```
- **Line Explanation**: This condition checks if there are still columns left to traverse (i.e., the left boundary is still less than or equal to the right boundary).



```cpp
            for (int i = bottom; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }
```
- **Line Explanation**: If there are columns left, this `for` loop traverses the **leftmost column** from bottom to top.
  - `i` goes from `bottom` to `top`, and elements from the `left` column are added to `result`.
  - After this loop, the entire leftmost column is traversed, so we can move the `left` boundary right.



```cpp
            left++;
```
- **Line Explanation**: After traversing the leftmost column, we increment the `left` boundary to exclude the column that was just visited. This reduces the matrix area by one column.



```cpp
    }

    return result;
}
```
- **Line Explanation**: The `while` loop continues as long as the boundaries allow, and when the loop finishes, we return the `result` vector containing the matrix elements in spiral order.


### Example Walkthrough:

For a 4x4 matrix:

```
[
  [1,  2,  3,  4],
  [5,  6,  7,  8],
  [9,  10, 11, 12],
  [13, 14, 15, 16]
]
```

- **Initial Boundaries**: `top = 0`, `bottom = 3`, `left = 0`, `right = 3`
  - Traverse top row: `[1, 2, 3, 4]`
  - Move `top` to 1.
  - Traverse rightmost column: `[8, 12, 16]`
  - Move `right` to 2.
  - Traverse bottom row: `[15, 14, 13]`
  - Move `bottom` to 2.
  - Traverse leftmost column: `[9, 5]`
  - Move `left` to 1.

- **New Boundaries**: `top = 1`, `bottom = 2`, `left = 1`, `right = 2`
  - Traverse top row: `[6, 7]`
  - Move `top` to 2.
  - Traverse rightmost column: `[11]`
  - Move `right` to 1.
  - Traverse bottom row: `[10]`

The spiral order for this matrix is:
```
[1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]
```

This code efficiently traverses the matrix in a spiral order while shrinking the boundaries after each traversal.

