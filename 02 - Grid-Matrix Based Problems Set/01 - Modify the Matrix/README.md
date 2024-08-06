<h1 align='center'>Modify-The-Matrix-Problem</h1>

## Problem Statement
![image](https://github.com/user-attachments/assets/994200b3-83e1-490f-822e-91b64f73d1fa)
![image](https://github.com/user-attachments/assets/27a3f25b-b598-4a04-97c4-eaffcbc339aa)

## Problem Explanation

### **Modify the Matrix Problem on LeetCode**

**Problem Statement:**

You are given a matrix where some elements are `-1` and others are non-negative integers. Your task is to replace each `-1` in the matrix with the maximum value in the corresponding column.

**Example:**

**Input:**
```
[
  [1, 2, -1],
  [4, -1, 6],
  [7, 8, 9]
]
```

**Output:**
```
[
  [1, 2, 9],
  [4, 8, 6],
  [7, 8, 9]
]
```

**Explanation:**

- For the first column, the maximum value is `7`. The `-1` in the first column is replaced with `7`.
- For the second column, the maximum value is `8`. The `-1` in the second column is replaced with `8`.
- For the third column, the maximum value is `9`. The `-1` in the third column is replaced with `9`.

**Approach for Beginners:**

1. **Find Maximum Values:** Traverse through the matrix to find the maximum value for each column. Store these maximum values in a separate array or vector.
2. **Replace `-1` Values:** Traverse the matrix again. For each `-1`, replace it with the corresponding maximum value from the array of maximum values you obtained in the first step.


## Problem Solution
```cpp
class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();        // Get the number of rows in the matrix
        int n = matrix[0].size();     // Get the number of columns in the matrix
        
        // Initialize a vector to store the maximum value of each column
        vector<int> maxColumn(n, INT_MIN);

        // Traverse through the matrix to find the maximum value for each column
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // Update the maximum value for column j
                maxColumn[j] = max(maxColumn[j], matrix[i][j]);
            }
        }

        // Traverse through the matrix to replace -1 values with the maximum value of the respective column
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == -1){
                    // Replace -1 with the maximum value of column j
                    matrix[i][j] = maxColumn[j];
                }
            }
        }

        return matrix; // Return the modified matrix
    }
};
```

## Problem Solution Explanation

1. **`int m = matrix.size();`**
   - Retrieves the number of rows in the matrix.

2. **`int n = matrix[0].size();`**
   - Retrieves the number of columns in the matrix (assuming all rows have the same number of columns).

3. **`vector<int> maxColumn(n, INT_MIN);`**
   - Initializes a vector `maxColumn` with `n` elements, all set to `INT_MIN`. This vector will store the maximum values for each column.

4. **`for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ maxColumn[j] = max(maxColumn[j], matrix[i][j]); }}`**
   - Iterates through each cell in the matrix and updates `maxColumn[j]` with the maximum value found in column `j`.

5. **`for(int i = 0; i < m; i++){ for(int j = 0; j < n; j++){ if(matrix[i][j] == -1){ matrix[i][j] = maxColumn[j]; }}`**
   - Iterates through the matrix again, replacing each `-1` with the maximum value of the corresponding column from `maxColumn`.

6. **`return matrix;`**
   - Returns the modified matrix.

This approach is straightforward and efficient for beginners as it involves two simple passes over the matrix: one for finding maximum values and another for replacements.

## Time and Space Complexity Analysis

**1. Time Complexity:**

- **Finding Maximum Values:**
  - We traverse the entire matrix once to find the maximum values in each column.
  - The time complexity for this step is \(O(m \times n)\), where \(m\) is the number of rows and \(n\) is the number of columns.

- **Replacing `-1` Values:**
  - We traverse the matrix again to replace `-1` values with the maximum values from the `maxColumn` vector.
  - The time complexity for this step is also \(O(m \times n)\).

Combining both steps, the total time complexity is \(O(m \times n) + O(m \times n) = O(m \times n)\).

**2. Space Complexity:**

- **Auxiliary Space:**
  - We use an additional vector `maxColumn` of size \(n\) to store the maximum values of each column.
  - The space complexity for this vector is \(O(n)\).

- **Input and Output Matrix:**
  - The space used by the input matrix is not considered in auxiliary space complexity analysis because it's given as input.
  - The output matrix is the same as the input matrix but modified in place.

Thus, the overall space complexity is \(O(n)\).

### **Example Output**

Here’s how you can represent the output in a Markdown file (`OUTPUT.md`):

```markdown
# Output for the "Modify the Matrix" Problem

**Input:**

```
[
  [1, 2, -1],
  [4, -1, 6],
  [7, 8, 9]
]
```

**Output:**

```
[
  [1, 2, 9],
  [4, 8, 6],
  [7, 8, 9]
]
```

**Explanation:**

- For the first column, the maximum value is `7`. The `-1` is replaced with `7`.
- For the second column, the maximum value is `8`. The `-1` is replaced with `8`.
- For the third column, the maximum value is `9`. The `-1` is replaced with `9`.
```

You can create a file named `OUTPUT.md` with the content above to document the results of the matrix modification.






