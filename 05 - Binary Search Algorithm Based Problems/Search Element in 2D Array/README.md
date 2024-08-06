iven an `m x n` matrix:

-   Each row is sorted in ascending order.
-   The first element of each row is greater than the last element of the previous row.

You need to determine if a target value exists in the matrix.

### Approach Explanation

#### 1. **Binary Search on Flattened Matrix**

The key idea is to treat the 2D matrix as a single sorted array and apply a binary search technique. Here's how the approach is structured:

-   **Initialization**:
    
    -   Determine the number of rows `m` and columns `n` in the matrix.
    -   Initialize `left` to 0, which represents the first element of the flattened matrix, and `right` to `m * n - 1`, which represents the last element.
-   **Binary Search Loop**:
    
    -   While `left` is less than or equal to `right`, compute the middle index `mid` as `(left + right) / 2`.
    -   Convert `mid` into its corresponding row and column indices:
        -   `row = mid / n` (integer division gives the row index)
        -   `col = mid % n` (modulo operation gives the column index)
    -   Retrieve the value `mid_value` from the matrix at `(row, col)`.
-   **Comparison**:
    
    -   Compare `mid_value` with the `target`:
        -   If `mid_value` equals `target`, return `true` because the target is found.
        -   If `mid_value` is less than `target`, adjust `left` to `mid + 1` to search the right half.
        -   If `mid_value` is greater than `target`, adjust `right` to `mid - 1` to search the left half.
-   **Completion**:
    
    -   If the loop completes without finding the target (`left > right`), return `false`.

### Example Walkthrough

Consider the matrix:

13571011162023303450\begin{matrix} 1 & 3 & 5 & 7 \\ 10 & 11 & 16 & 20 \\ 23 & 30 & 34 & 50 \end{matrix}11023​31130​51634​72050​

-   **Target**: `3`
-   **Steps**:
    -   Initialize `left = 0`, `right = 11` (since `m * n - 1 = 12 - 1 = 11`)
    -   Compute `mid = (0 + 11) / 2 = 5`
    -   Convert `mid` to `row = 5 / 4 = 1`, `col = 5 % 4 = 1`
    -   Compare `matrix[1][1] = 11` with `target = 3`
    -   Since `11 > 3`, adjust `right = 4`
    -   Compute `mid = (0 + 4) / 2 = 2`
    -   Convert `mid` to `row = 2 / 4 = 0`, `col = 2 % 4 = 2`
    -   Compare `matrix[0][2] = 5` with `target = 3`
    -   Since `5 > 3`, adjust `right = 1`
    -   Compute `mid = (0 + 1) / 2 = 0`
    -   Convert `mid` to `row = 0 / 4 = 0`, `col = 0 % 4 = 0`
    -   Compare `matrix[0][0] = 1` with `target = 3`
    -   Since `1 < 3`, adjust `left = 1`
    -   Compute `mid = (1 + 1) / 2 = 1`
    -   Convert `mid` to `row = 1 / 4 = 0`, `col = 1 % 4 = 1`
    -   Compare `matrix[0][1] = 3` with `target = 3`
    -   Target found, return `true`.

### Code Explanation

#### 1. Function Definition: `search_matrix`

```
bool search_matrix(int arr[][4], int s, int col, int key ){
    int start = 0;
    int end = s - 1;
    int mid = start + (end - start)/2;
    
    while(start <= end){
        int rows = mid / col;
        int cols = mid % col;
        
        if(arr[rows][cols] == key){
            cout<<"Element Found at Row: "<<rows<<" and Index: "<<cols<<endl;
            return true;
        } else if(arr[rows][cols] > key){
            end = mid - 1;
        } else {
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return false;
}
``` 

-   **Parameters**:
    
    -   `int arr[][4]`: Represents a 2D array where each row has 4 columns. This is a fixed-size array where the number of rows is determined by the calling context.
    -   `int s`: Represents the total number of elements in the matrix (`sizeof(matrix) / sizeof(int)`). This is not directly used in the function logic.
    -   `int col`: Specifies the number of columns in each row (`4` in this case).
    -   `int key`: Represents the target value that we are searching for in the matrix.
-   **Initialization**:
    
    -   `start`: Initialized to `0`, representing the starting index of the search range.
    -   `end`: Initialized to `s - 1`, where `s` is the total number of elements in the matrix (not used directly here).
    -   `mid`: Calculates the middle index using `(start + end) / 2` to start the binary search.
-   **Binary Search Loop**:
    
    -   The `while` loop continues as long as `start` is less than or equal to `end`.
    -   Inside the loop:
        -   Calculates `rows` as `mid / col` and `cols` as `mid % col`, converting the 1D index `mid` into 2D indices for `arr`.
        -   Compares `arr[rows][cols]` with `key`:
            -   If they match (`arr[rows][cols] == key`), prints the position of the element (`rows` and `cols`) and returns `true`.
            -   If `arr[rows][cols]` is greater than `key`, adjusts `end` to `mid - 1` to search the left half.
            -   If `arr[rows][cols]` is less than `key`, adjusts `start` to `mid + 1` to search the right half.
    -   Updates `mid` using `(start + end) / 2` to continue the binary search.
-   **Return**:
    
    -   If the target `key` is not found in the matrix after the loop (`start > end`), the function returns `false`.

#### 2. `main` Function

```
int main(){
    int matrix[][4] = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    
    int target_key = 30;
    int size = sizeof(matrix) / sizeof(int);
    bool is_found = search_matrix(matrix, size, 4, target_key);
    
    if(is_found){
        cout<<"Element Found";
    }else{
        cout<<"Element Not Found";
    }
    
    return 0;
}
``` 

-   **Matrix Initialization**:
    
    -   Defines a 2D array `matrix` with integer values. Here, it's a 3x4 matrix (3 rows and 4 columns).
-   **Target Key**:
    
    -   Sets `target_key` to `30`, the value we want to search for in the matrix.
-   **Function Call**:
    
    -   Calls `search_matrix(matrix, size, 4, target_key)`:
        -   `matrix`: Passes the matrix array to search.
        -   `size`: Calculates the total number of elements in the matrix (`sizeof(matrix) / sizeof(int)`). This is not used inside `search_matrix` but generally used for other purposes.
        -   `4`: Indicates each row has 4 columns.
        -   `target_key`: Specifies the value to search for.
-   **Output**:
    
    -   Depending on whether `search_matrix` returns `true` or `false`, prints either `"Element Found"` or `"Element Not Found"`.

### Explanation of the Approach

-   **Binary Search**:
    
    -   The function `search_matrix` uses a binary search approach adapted for a 2D matrix.
    -   It treats the 2D matrix as a 1D sorted array and applies binary search to efficiently locate the target `key`.
    -   The calculation of `rows` and `cols` allows mapping from the 1D index `mid` to the corresponding 2D matrix indices, facilitating comparison with the target `key`.
-   **Efficiency**:
    
    -   The binary search approach ensures that the search is efficient with a time complexity of `O(log(m * n))`, where `m` is the number of rows and `n` is the number of columns in the matrix.
    -   This efficiency is achieved by halving the search space (`start` to `end`) in each iteration of the loop.
-   **Edge Cases**:
    
    -   Handles cases where the matrix is empty (`s = 0`) or the target `key` is not found (`start > end`).

This method effectively utilizes the properties of sorted arrays (each row is sorted) to efficiently search for elements in a 2D matrix, making it suitable for scenarios where quick lookup operations are required.
