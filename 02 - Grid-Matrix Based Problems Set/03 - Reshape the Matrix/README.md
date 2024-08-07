<h1 align='center'>Reshape - The - Matrix</h1>

## Problem Statement

![image](https://github.com/user-attachments/assets/c2c7a584-18b1-4cc1-9142-9ac0d52eeccc)
![image](https://github.com/user-attachments/assets/38d5983d-83c4-4935-950b-52b4a12bb8e9)


## Problem Explanation

Imagine you have a grid (matrix) that looks like this:

```
mat = [[1, 2],
       [3, 4]]
```

This matrix has 2 rows and 2 columns. Each cell contains a number, and the numbers are arranged in a grid format.

Now, you want to change this matrix into a new matrix with different dimensions, specifically `r` rows and `c` columns. The new matrix should contain all the numbers from the original matrix, but arranged in a new grid with the specified number of rows and columns.

### Key Points:

1. **Check if Reshape is Possible**:
   - First, you need to check if it is possible to reshape the matrix into the desired dimensions. 
   - You can only reshape the matrix if the total number of elements remains the same. For example, if your original matrix has 4 elements, the new matrix must also have 4 elements (i.e., `r * c` should be equal to the total number of elements in the original matrix).

2. **Flattening the Matrix**:
   - To reshape, you need to take all the elements of the original matrix and put them in a single list (or row). This is called "flattening" the matrix.

3. **Creating the New Matrix**:
   - After flattening the original matrix, you will fill the new matrix with the flattened elements in the row-wise order.

### Example 1:

**Input:**
- Original matrix: `[[1, 2], [3, 4]]`
- Desired dimensions: `r = 1`, `c = 4`

**Steps:**
1. **Flatten the Original Matrix**: Combine all elements into one list: `[1, 2, 3, 4]`.
2. **Create New Matrix**: Arrange these elements into a matrix with `1` row and `4` columns: `[[1, 2, 3, 4]]`.

**Output:** `[[1, 2, 3, 4]]`

### Example 2:

**Input:**
- Original matrix: `[[1, 2], [3, 4]]`
- Desired dimensions: `r = 2`, `c = 4`

**Steps:**
1. **Flatten the Original Matrix**: Combine all elements into one list: `[1, 2, 3, 4]`.
2. **Check Dimensions**: Here, the desired dimensions (2 rows and 4 columns) do not match the total number of elements (which is 4). Since the total number of elements in the new matrix does not match, reshaping is not possible.

**Output:** `[[1, 2], [3, 4]]` (The original matrix is returned because reshaping isn't possible.)

### Summary:

To solve the problem:
1. **Verify if reshaping is possible** by comparing the total number of elements.
2. **Flatten** the original matrix into a single list.
3. **Reconstruct** the new matrix using the list of elements, arranging them in the new dimensions.

This approach ensures that the new matrix has the same elements as the original one, just organized into a different shape.

## Problem Solution
```
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        int original_rows = mat.size();
        int original_cols = mat[0].size();

        if(original_rows * original_cols != r * c){
            return mat;
        }

        vector<int> mat_values;
        vector<vector<int>> reshapedMat(r, vector<int>(c));

        for(int i = 0; i < original_rows; i++){

            for(int j = 0; j < original_cols; j++){
                mat_values.push_back(mat[i][j]);
            }
        }


        for(int i = 0; i < r; i++){

            for(int j = 0; j < c; j++){
                reshapedMat[i][j] = mat_values[i * c + j];
            }
        }


    return reshapedMat;
    }
};
```

## Problem Solution Explanation

```cpp
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        int original_rows = mat.size();
        int original_cols = mat[0].size();
```
- **`int original_rows = mat.size();`**: Gets the number of rows in the original matrix `mat`.
- **`int original_cols = mat[0].size();`**: Gets the number of columns in the original matrix `mat`.

**Example:**
- For `mat = [[1, 2], [3, 4]]`, `original_rows` will be `2` and `original_cols` will be `2`.

```cpp
        if(original_rows * original_cols != r * c){
            return mat;
        }
```
- **Check if Reshape is Possible**: This line checks if the total number of elements in the original matrix (`original_rows * original_cols`) matches the total number of elements in the desired reshaped matrix (`r * c`). If they don't match, the reshaping is not possible, so it returns the original matrix.

**Example:**
- If `r = 1` and `c = 4`, then `r * c` is `4`. Since `original_rows * original_cols` is also `4`, reshaping is possible. 
- If `r = 2` and `c = 4`, then `r * c` is `8`. Since `original_rows * original_cols` is `4`, reshaping is not possible, so it will return the original matrix.

```cpp
        vector<int> mat_values;
        vector<vector<int>> reshapedMat(r, vector<int>(c));
```
- **Initialize Storage**:
  - **`vector<int> mat_values;`**: A vector to store all elements from the original matrix in a single list.
  - **`vector<vector<int>> reshapedMat(r, vector<int>(c));`**: Initializes a new matrix with `r` rows and `c` columns, filled with default values (0 in this case).

**Example:**
- For `r = 1` and `c = 4`, `reshapedMat` will be initialized as `[[0, 0, 0, 0]]`.

```cpp
        for(int i = 0; i < original_rows; i++){
            for(int j = 0; j < original_cols; j++){
                mat_values.push_back(mat[i][j]);
            }
        }
```
- **Flatten the Original Matrix**:
  - This nested loop iterates through each element in the original matrix and adds it to `mat_values`.

**Example:**
- For `mat = [[1, 2], [3, 4]]`, `mat_values` will become `[1, 2, 3, 4]`.

```cpp
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                reshapedMat[i][j] = mat_values[i * c + j];
            }
        }
```
- **Fill the New Matrix**:
  - This nested loop fills `reshapedMat` using elements from `mat_values`.
  - `i * c + j` calculates the correct index in `mat_values` to place in `reshapedMat`.

**Example:**
- For `r = 1` and `c = 4`, the final matrix `reshapedMat` will be `[[1, 2, 3, 4]]`.

```cpp
    return reshapedMat;
    }
};
```
- **Return the Reshaped Matrix**: The function returns the new reshaped matrix.

### Time and Space Complexity

- **Time Complexity (TC)**: \(O(m \times n)\)
  - The matrix is traversed twice: once to flatten it and once to fill the new matrix. `m` and `n` are the number of rows and columns in the original matrix, respectively.

- **Space Complexity (SC)**: \(O(m \times n)\)
  - Space is used for `mat_values` and `reshapedMat`, both of which store all elements of the original matrix.

### Summary with Example

Given `mat = [[1, 2], [3, 4]]`, `r = 1`, and `c = 4`:
- **Flatten**: `[1, 2, 3, 4]`
- **Reshape**: `[[1, 2, 3, 4]]`

If reshaping isn’t possible (e.g., `r = 2` and `c = 4`):
- **Output**: `[[1, 2], [3, 4]]`
