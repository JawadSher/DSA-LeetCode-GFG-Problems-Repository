<h1 align='center'>Rotate - Image</h1>

## Problem Statement

**Problem URL :** [Rotate Image](https://leetcode.com/problems/rotate-image/)

![image](https://github.com/user-attachments/assets/5f8a06c6-30e7-46c5-8153-6f5fec36b0a5)
![image](https://github.com/user-attachments/assets/0ca0505d-5286-42b8-ac43-0fed3d4f9a87)

## Problem Explanation

You are given an \( n \times n \) 2D matrix representing an image. You need to rotate the image by 90 degrees clockwise **in-place** (i.e., modify the original matrix without using extra space).

### Approach

To solve the problem of rotating an image (matrix) 90 degrees clockwise, there are a few ways to think about it. The approach we use here is based on two steps:

1. **Transpose the Matrix:** 
   - In a transposed matrix, the rows become columns, and the columns become rows. This prepares the matrix for rotation.
   - After the transpose, the elements are rearranged in such a way that reversing the rows will complete the clockwise rotation.

2. **Reverse Each Row:** 
   - Once the matrix is transposed, the last step is to reverse each row, which effectively rotates the matrix by 90 degrees clockwise.
   
By combining these two steps (transpose + row reversal), we can rotate the matrix **in-place** without using additional space.

### Other Possible Approaches

Before explaining the code, let’s quickly mention some alternative approaches to solving the problem:

1. **Using a Temporary Matrix:**
   - Create a new matrix where you place each element from the original matrix in its rotated position. 
   - However, this approach uses extra space (an additional matrix), so it doesn’t meet the "in-place" requirement.

2. **In-Place Layer by Layer Rotation:**
   - Rotate the matrix layer by layer (starting from the outermost layer and moving inward).
   - For each layer, elements are swapped in sets of four. This is another in-place approach, but it requires a more complicated swapping mechanism.

The **transpose + reverse rows** method is more intuitive and simpler to implement.

### Explanation of the Chosen Approach (Transpose + Reverse Rows)

#### Step 1: Transpose the Matrix
In the transposition process:
- You convert rows into columns. The element at position `(i, j)` will move to `(j, i)`.

For example, given this 3x3 matrix:

```
1 2 3
4 5 6
7 8 9
```

After the transpose operation, the matrix becomes:

```
1 4 7
2 5 8
3 6 9
```

#### Step 2: Reverse Each Row
After the matrix has been transposed, reversing each row will result in the desired 90-degree clockwise rotation.

If we reverse each row in the transposed matrix:

```
7 4 1
8 5 2
9 6 3
```

The matrix is now rotated 90 degrees clockwise.

## Problem Solution
```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
```

## Problem Solution Explanation

1. **`int n = matrix.size();`**
   - This line stores the size of the matrix (which is `n x n`) in variable `n`. It will be used in the loops.

2. **Transpose the Matrix**
   - **Outer loop:** `for(int i = 0; i < n; i++)`
     - The outer loop goes through each row.
   - **Inner loop:** `for(int j = i + 1; j < n; j++)`
     - The inner loop starts from the diagonal element `(i, i)` and goes towards the right to swap elements. By starting from `i + 1`, the matrix elements are swapped above the diagonal, ensuring no double swaps.
   - **Swap operation:** `swap(matrix[i][j], matrix[j][i])`
     - This swaps the element at position `(i, j)` with the element at `(j, i)` to transpose the matrix.

   After this loop, the matrix is transposed.

3. **Reverse Each Row**
   - **Loop:** `for(int i = 0; i < n; i++)`
     - This loop goes through each row of the transposed matrix.
   - **Reverse operation:** `reverse(matrix[i].begin(), matrix[i].end());`
     - This reverses each row in-place using the C++ `reverse()` function from the STL. After reversing all rows, the matrix is rotated 90 degrees clockwise.

### Example Walkthrough

Let’s break down an example where the input matrix is:

```
1 2 3
4 5 6
7 8 9
```

1. **Step 1: Transpose the Matrix**
   - The transposition swaps elements `(i, j)` with `(j, i)`.
   - Swapping happens as follows:
     - Swap (1, 2), (2, 1) → 4 and 2
     - Swap (1, 3), (3, 1) → 7 and 3
     - Swap (2, 3), (3, 2) → 8 and 6
   - After transposing:
     ```
     1 4 7
     2 5 8
     3 6 9
     ```

2. **Step 2: Reverse Each Row**
   - Reverse each row:
     - Reverse row 1 → `7 4 1`
     - Reverse row 2 → `8 5 2`
     - Reverse row 3 → `9 6 3`
   - After reversing the rows:
     ```
     7 4 1
     8 5 2
     9 6 3
     ```

The matrix is now rotated 90 degrees clockwise.

### Time and Space Complexity

- **Time Complexity:** \(O(n^2)\)
  - Transposing the matrix takes \(O(n^2)\) as each element is visited once.
  - Reversing each row also takes \(O(n^2)\) since each row has \(n\) elements, and there are \(n\) rows.
  - Thus, the total time complexity is \(O(n^2)\).

- **Space Complexity:** \(O(1)\)
  - The matrix is modified in-place, and no extra space is used except for a few temporary variables, so the space complexity is \(O(1)\).

### Conclusion

The approach of transposing the matrix followed by reversing each row is an efficient way to rotate an image (or matrix) 90 degrees clockwise **in-place**. It is simple to implement and avoids using extra space, making it a great choice for this problem.
