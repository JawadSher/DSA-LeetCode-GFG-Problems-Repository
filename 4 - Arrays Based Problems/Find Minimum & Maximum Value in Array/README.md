# Source Code Explanation

#### 1. Header and Namespace

-   `#include<iostream>`: Includes the input/output stream library in C++, enabling input and output operations.
-   `#include<climits>`: Includes the `<climits>` header file, providing constants for minimum and maximum values of integral types (`INT_MIN` and `INT_MAX`).

#### 2. Function `maxValue(int arr[], int n)`

-   **Purpose**: Finds the maximum value in an integer array `arr` of size `n`.
-   **Initialization**: Initializes `value` to `INT_MIN` (`-2147483648`), ensuring any element in `arr` will be larger initially.
-   **Iteration**: Uses a `for` loop to iterate through the array.
-   **Comparison**: Checks if each element `arr[i]` is greater than `value`.
-   **Update**: Updates `value` to `arr[i]` if `arr[i]` is greater.
-   **Return**: Returns the maximum value found after iterating through the array.

#### 3. Function `minValue(int arr[], int n)`

-   **Purpose**: Finds the minimum value in an integer array `arr` of size `n`.
-   **Initialization**: Initializes `value` to `INT_MAX` (`2147483647`), ensuring any element in `arr` will be smaller initially.
-   **Iteration**: Iterates through the array using a `for` loop.
-   **Comparison**: Checks if each element `arr[i]` is less than `value`.
-   **Update**: Updates `value` to `arr[i]` if `arr[i]` is smaller.
-   **Return**: Returns the minimum value found after iterating through the array.

#### 4. `main()` Function

-   **Array Initialization**: Initializes an example integer array `my_arr`.
-   **Array Size Calculation**: Calculates the size of `my_arr` using `sizeof` operator.
-   **Function Calls**: Calls `maxValue(my_arr, size)` and `minValue(my_arr, size)` to find the maximum and minimum values.
-   **Output**: Prints the results using `cout` statements formatted for clarity.

#### 5. Execution Flow

-   Begins by defining the array `my_arr` and determining its size.
-   Utilizes `maxValue` and `minValue` functions to compute the maximum and minimum values within `my_arr`.
-   Outputs the results (`Max value is : <max_val>` and `Min value is : <min_val>`) for clarity and comprehension.

## Example Output

When you run the program, it will output:

`Max value is : 1000`

`Min value is : -50` 

This output indicates that the maximum value in the array `my_arr` is `1000` and the minimum value is `-50`. These values are computed using the `maxValue` and `minValue` functions, demonstrating the effectiveness of the linear search approach in finding extreme values within an array.
