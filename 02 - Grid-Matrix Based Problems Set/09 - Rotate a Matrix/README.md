<h1 align='center'>Rotate - a - Matrix</h1>

## Problem Statement

**Problem URL :** [Rotate a Matrix](https://www.geeksforgeeks.org/problems/rotate-a-2d-array-without-using-extra-space1004/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/919419d2-e112-4f37-b783-aa51ec374381)

## Problem Explanation
This code rotates a matrix **90 degrees anti-clockwise** using a similar approach to the clockwise solution, but with a crucial difference in the second step. Let's go through the detailed explanation of this solution, including the **approach**, **code breakdown**, and **example**.

Given an \( n \times n \) matrix, we want to rotate it **90 degrees anti-clockwise** in-place (without using extra space).

### Approach

To rotate the matrix anti-clockwise by 90 degrees, we follow these steps:

1. **Transpose the Matrix:** 
   - The first step is the same as the clockwise solution: we transpose the matrix, where rows become columns and vice versa.

2. **Reverse Each Column:** 
   - Instead of reversing each row (as done in the clockwise solution), we reverse each column to rotate the matrix anti-clockwise.
   
This method effectively rotates the matrix by 90 degrees anti-clockwise without requiring additional space.

### Other Possible Approaches

There are alternative methods to rotate a matrix anti-clockwise, such as:

1. **Using an Auxiliary Matrix:** 
   - You could create a temporary matrix and place each element from the original matrix in its new rotated position. This method requires extra space.

2. **In-Place Layer by Layer Rotation:** 
   - You could rotate the matrix by 90 degrees anti-clockwise by rotating individual layers (outermost to innermost) in sets of four. This approach is more complex and involves careful swapping of elements.

The **transpose + reverse columns** method is simple and efficient for an in-place rotation.

### Explanation of the Chosen Approach (Transpose + Reverse Columns)

#### Step 1: Transpose the Matrix

In the transposition step, we swap the elements at positions `(i, j)` and `(j, i)`, effectively converting rows into columns. This prepares the matrix for rotation.

For example, given this 3x3 matrix:

```
1 2 3
4 5 6
7 8 9
```

After transposing, the matrix becomes:

```
1 4 7
2 5 8
3 6 9
```

#### Step 2: Reverse Each Column

After transposing the matrix, we reverse the elements of each column to get the final anti-clockwise rotation. For each column, we swap the top element with the bottom element and move inward.

Reversing each column in the transposed matrix:

```
7 4 1
8 5 2
9 6 3
```

This gives us the matrix rotated by 90 degrees anti-clockwise.

## Problem Solution
```cpp
#include <bits/stdc++.h> 
using namespace std; 
class Solution
{   
    public:
    void rotateby90(vector<vector<int> >& matrix, int n) 
    { 
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        
        for(int j = 0; j < n; j++){
            int top = 0;
            int bottom = n - 1;
            
            while(top < bottom){
                swap(matrix[top][j], matrix[bottom][j]);
                top++;
                bottom--;
            }
        }
    } 
};

int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix, n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
```

## Problem Solution Explanation

1. **Transpose the Matrix**
   - **Outer loop:** `for(int i = 0; i < n; i++)`
     - The outer loop iterates through each row.
   - **Inner loop:** `for(int j = i + 1; j < n; j++)`
     - The inner loop starts from the diagonal element `(i, i)` and moves to the right to transpose the matrix. This avoids double swaps.
   - **Swap operation:** `swap(matrix[i][j], matrix[j][i])`
     - This swaps elements at position `(i, j)` and `(j, i)` to transpose the matrix.

   After this loop, the matrix is transposed.

2. **Reverse Each Column**
   - **Outer loop:** `for(int j = 0; j < n; j++)`
     - This loop iterates through each column.
   - **Reverse logic (top and bottom pointers):**
     - Two pointers, `top` (initially 0) and `bottom` (initially \(n - 1\)), are used to reverse the elements in each column.
     - Inside the `while` loop, we swap the top and bottom elements of the column, moving inward until all elements are reversed.
   - **Swap operation:** `swap(matrix[top][j], matrix[bottom][j])`
     - This swaps the top element with the bottom element for each column.

   After reversing each column, the matrix is rotated by 90 degrees anti-clockwise.

### Example Walkthrough

Let’s go through an example where the input matrix is:

```
1 2 3
4 5 6
7 8 9
```

1. **Step 1: Transpose the Matrix**

   - Swap the elements to transpose:
     - Swap (1, 2) and (2, 1) → 4 and 2
     - Swap (1, 3) and (3, 1) → 7 and 3
     - Swap (2, 3) and (3, 2) → 8 and 6
   - After transposing the matrix, we get:
     ```
     1 4 7
     2 5 8
     3 6 9
     ```

2. **Step 2: Reverse Each Column**

   - Reverse each column:
     - Column 1: Swap (1, 3) → `7 4 1`
     - Column 2: Swap (2, 2) → `8 5 2`
     - Column 3: Swap (3, 1) → `9 6 3`
   - After reversing each column, the final matrix is:
     ```
     7 4 1
     8 5 2
     9 6 3
     ```

The matrix is now rotated 90 degrees anti-clockwise.

### Time and Space Complexity

- **Time Complexity:** \(O(n^2)\)
  - Transposing the matrix takes \(O(n^2)\) because each element is visited once.
  - Reversing each column also takes \(O(n^2)\) because each column has \(n\) elements, and there are \(n\) columns.
  - Thus, the total time complexity is \(O(n^2)\).

- **Space Complexity:** \(O(1)\)
  - The matrix is modified in-place, so no extra space is used except for a few temporary variables.

### Conclusion

This solution rotates the matrix by 90 degrees anti-clockwise by first **transposing the matrix** and then **reversing each column**. It is efficient and performs the rotation **in-place** without using additional space.

