<h1 align='center'>Island - Perimeter</h1>

## Problem Statement

![image](https://github.com/user-attachments/assets/413d1450-4efb-4973-a08b-f8ce3184ee00)
![image](https://github.com/user-attachments/assets/3f08deb1-9a46-4d69-bcb6-89e82a472684)


## Problem Explanation

To solve the problem of finding the perimeter of the island on a grid, let's break it down into simpler steps:

1. **Grid Layout**: 
   - You have a grid where each cell is either land (`1`) or water (`0`).
   - The grid is completely surrounded by water, and there is exactly one island consisting of land cells.

2. **Island Definition**:
   - An island is made up of land cells connected either horizontally (left/right) or vertically (up/down). Diagonal connections don't count.

3. **Objective**:
   - You need to calculate the perimeter of the island. The perimeter is the total length of the boundary around the island.

### Approach to Solve:

1. **Perimeter Calculation**:
   - For each land cell (`1`), you need to check its surrounding cells (up, down, left, right). If a neighboring cell is water (`0`) or out of bounds (the edge of the grid), it contributes to the perimeter of the island.

2. **Steps to Find Perimeter**:
   - **Iterate through each cell in the grid**:
     - If the cell contains land (`1`), check its four neighbors (up, down, left, right).
     - For each neighbor:
       - If it is water (`0`) or out of bounds, count that side of the land cell as part of the perimeter.
   - **Add up all the sides counted for perimeter**.

### Example Breakdown:

- **Example 1**:
  ```plaintext
  Input: [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
  ```
  - Here, the land cells form an island. By checking each land cell and counting how many of its sides are exposed to water or the edge of the grid, you can sum up the total perimeter.

- **Example 2**:
  ```plaintext
  Input: [[1]]
  ```
  - A single land cell in the grid has all four of its sides exposed to water. Therefore, the perimeter is 4.

- **Example 3**:
  ```plaintext
  Input: [[1,0]]
  ```
  - A land cell next to water on one side will have a perimeter of 4, as it is adjacent to water on one side and has edges exposed to water on the other three sides.

### Summary:

To find the perimeter of the island, simply check each land cell and count how many of its sides are adjacent to water or the grid's boundary. This gives you the total perimeter of the island.

## Problem Solution 

```
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        int perimeter = 0;

        for(int i = 0; i < row; i++){

            for(int j = 0; j < col; j++){

                if(grid[i][j] == 1){
                    perimeter += 4;

                    if(j > 0 && grid[i][j-1] == 1){
                        perimeter -= 2;
                    }

                    if(i > 0 && grid[i-1][j] == 1){
                        perimeter -= 2;
                    }
                }

            }
            
        }

        
    return perimeter;
    }
};
```

## Problem Solution Explanation

Here’s the line-by-line explanation of the code with examples of inputs and their outputs:

```cpp
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
```
- **Class Definition**: Defines a class `Solution` with a public method.
- **Method Declaration**: `int islandPerimeter(vector<vector<int>>& grid)` is a method that takes a 2D vector `grid` as input and returns an integer representing the perimeter of the island.

```cpp
        int row = grid.size();
        int col = grid[0].size();
        int perimeter = 0;
```
- **Row and Column Size**: `int row = grid.size();` retrieves the number of rows in the grid.
- **Column Size**: `int col = grid[0].size();` retrieves the number of columns in the grid. Assumes that the grid has at least one row.
- **Perimeter Initialization**: `int perimeter = 0;` initializes the variable `perimeter` to 0. This will be used to accumulate the perimeter of the island.

```cpp
        for(int i = 0; i < row; i++){
```
- **Row Iteration**: Begins a loop to iterate over each row in the grid. `i` is the row index.

```cpp
            for(int j = 0; j < col; j++){
```
- **Column Iteration**: Begins a nested loop to iterate over each column in the current row. `j` is the column index.

```cpp
                if(grid[i][j] == 1){
```
- **Land Cell Check**: Checks if the current cell `(i, j)` is land (`1`). If it is, the following code block will be executed.

```cpp
                    perimeter += 4;
```
- **Initial Perimeter Contribution**: For each land cell, initially assume it contributes 4 units to the perimeter (one unit for each side: left, right, top, bottom).

```cpp
                    if(j > 0 && grid[i][j-1] == 1){
```
- **Left Neighbor Check**: Checks if there is a land cell to the left (`grid[i][j-1]`) and ensures `j > 0` to avoid out-of-bounds errors.

```cpp
                        perimeter -= 2;
```
- **Adjust Perimeter for Left Neighbor**: If the left cell is also land, it shares a side with the current cell, so subtract 2 units from the perimeter for the shared boundary.

```cpp
                    if(i > 0 && grid[i-1][j] == 1){
```
- **Top Neighbor Check**: Checks if there is a land cell above (`grid[i-1][j]`) and ensures `i > 0` to avoid out-of-bounds errors.

```cpp
                        perimeter -= 2;
```
- **Adjust Perimeter for Top Neighbor**: If the cell above is also land, it shares a side with the current cell, so subtract 2 units from the perimeter for the shared boundary.

```cpp
                }
            }
        }
```
- **End of Inner Loop and Outer Loop**: Closes the inner loop and then the outer loop. These loops iterate over all cells in the grid.

```cpp
        return perimeter;
    }
};
```
- **Return Statement**: Returns the final computed perimeter of the island.
- **End of Method and Class**: Ends the method and the class definition.

### Examples and Outputs:

1. **Example 1**:
   ```cpp
   vector<vector<int>> grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
   ```
   - **Explanation**: This grid has a single island with a perimeter of 16.
   - **Output**: `16`

2. **Example 2**:
   ```cpp
   vector<vector<int>> grid = {{1}};
   ```
   - **Explanation**: This grid has a single cell island with a perimeter of 4.
   - **Output**: `4`

3. **Example 3**:
   ```cpp
   vector<vector<int>> grid = {{1,0}};
   ```
   - **Explanation**: This grid has a single cell island with a perimeter of 4 (since there is only one land cell with no neighbors).
   - **Output**: `4`

### Time and Space Complexity:

- **Time Complexity**: \(O(m \times n)\)
  - The algorithm iterates over each cell in the grid exactly once, where \(m\) is the number of rows and \(n\) is the number of columns. Thus, the time complexity is proportional to the size of the grid.

- **Space Complexity**: \(O(1)\)
  - The algorithm uses a constant amount of extra space beyond the input grid (a few variables). It does not use any additional space proportional to the input size. Thus, the space complexity is constant.
