# Source Code Explanation

#### 1. Header and Namespace

-   `#include<iostream>`: Includes the input/output stream library in C++, allowing input and output operations.

#### 2. Function `totalSum(int arr[], int n)`

-   **Purpose**: Calculates the total sum of elements in an integer array `arr` of size `n`.
-   **Initialization**: Initializes `total` to `0`, which will accumulate the sum of all elements in the array.
-   **Iteration**: Uses a `for` loop to iterate through the array.
-   **Accumulation**: Adds each element `arr[i]` to `total`.
-   **Return**: Returns the computed `total` sum after iterating through the entire array.

#### 3. `main()` Function

-   **Array Initialization**: Initializes an example integer array `my_arr` with values `{10, 20, 30, -50, -30, 100, 1000}`.
-   **Array Size Calculation**: Calculates the size of `my_arr` using `sizeof(my_arr)/sizeof(int)`, which gives the number of elements in the array.
-   **Function Call**: Calls `totalSum(my_arr, size)` to calculate the sum of elements in `my_arr`.
-   **Output**: Prints the calculated total sum using `cout`.

## Example Output

When you run the program, it will output:

`Total Sum is : 1080` 

This output indicates that the sum of all elements in the `my_arr` array (`10 + 20 + 30 - 50 - 30 + 100 + 1000 = 1080`) is calculated and displayed using the `totalSum` function.
