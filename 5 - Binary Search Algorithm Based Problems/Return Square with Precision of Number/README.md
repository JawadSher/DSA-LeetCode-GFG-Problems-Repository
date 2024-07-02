# Source Code Explanation

This code calculates the square root of a given number with a specified precision using a combination of binary search and iterative refinement.

#### 1. `find_sqrt` Function

The `find_sqrt` function calculates the integer part of the square root of a given number `n`.


```
int find_sqrt(int n) {
    int start = 0;
    int end = n;
    int mid = start + (end - start) / 2;
    int sqr = 0;

    while (start <= end) {
        int square = mid * mid;
        if (square == n) {
            return mid;
        } else if (square < n) {
            sqr = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return sqr;
}
``` 

-   **Initialization**:
    
    -   `start` is set to `0`.
    -   `end` is set to `n`.
    -   `mid` is initialized to the average of `start` and `end`.
    -   `sqr` is initialized to `0`.
-   **Binary Search**:
    
    -   The `while` loop runs as long as `start` is less than or equal to `end`.
    -   `square` is calculated as `mid * mid`.
    -   If `square` is equal to `n`, `mid` is the exact square root, so return `mid`.
    -   If `square` is less than `n`, set `sqr` to `mid` and adjust `start` to `mid + 1`.
    -   If `square` is greater than `n`, adjust `end` to `mid - 1`.
    -   Recalculate `mid` for the next iteration.
-   **Return Value**:
    
    -   If the loop terminates without finding an exact square root, return `sqr`, which holds the largest integer whose square is less than or equal to `n`.

#### 2. `set_precision` Function

The `set_precision` function refines the square root calculation to the specified precision.


```
double set_precision(int num, int precision, int sqr) {
    double factor = 1;
    double ans = sqr;
    for (int i = 0; i < precision; i++) {
        factor = factor / 10;
        for (double j = ans; j * j < num; j = j + factor) {
            ans = j;
        }
    }
    return ans;
}
``` 

-   **Initialization**:
    
    -   `factor` is set to `1`.
    -   `ans` is set to `sqr`, the integer part of the square root.
-   **Iterative Refinement**:
    
    -   The outer `for` loop runs `precision` times.
    -   In each iteration, `factor` is divided by `10` to refine the answer to the next decimal place.
    -   The inner `for` loop iterates over potential values of the square root starting from `ans` and increasing by `factor`, checking if the square of `j` is less than `num`.
    -   If `j * j` is less than `num`, `ans` is updated to `j`.
-   **Return Value**:
    
    -   The function returns `ans`, which now holds the square root refined to the specified precision.

#### 3. `main` Function

The `main` function integrates the `find_sqrt` and `set_precision` functions to calculate and print the square root with the desired precision.

```
int main() {
    int num = 37;
    int precision = 3;
    int sqr = find_sqrt(num);
    cout << "The Sqrt of " << num << " is with precision: " << set_precision(num, precision, sqr);
    return 0;
}
``` 

-   Defines an integer `num` with the value `37`.
-   Defines `precision` with the value `3`.
-   Calls `find_sqrt(num)` to compute the integer part of the square root of `37`.
-   Calls `set_precision(num, precision, sqr)` to refine the square root calculation to 3 decimal places.
-   Prints the result.

### Detailed Example

Let's go through an example where `num` is `37` and `precision` is `3`.

1.  **Finding the Integer Part of the Square Root**:
    
    -   Initial values: `start = 0`, `end = 37`
    -   Calculate `mid`: `mid = (0 + 37) / 2 = 18`
    -   `square = 18 * 18 = 324`, which is greater than `37`, so set `end = 18 - 1 = 17`
    -   Calculate new `mid`: `mid = (0 + 17) / 2 = 8`
    -   `square = 8 * 8 = 64`, which is greater than `37`, so set `end = 8 - 1 = 7`
    -   Calculate new `mid`: `mid = (0 + 7) / 2 = 3`
    -   `square = 3 * 3 = 9`, which is less than `37`, so set `sqr = 3` and `start = 3 + 1 = 4`
    -   Calculate new `mid`: `mid = (4 + 7) / 2 = 5`
    -   `square = 5 * 5 = 25`, which is less than `37`, so set `sqr = 5` and `start = 5 + 1 = 6`
    -   Calculate new `mid`: `mid = (6 + 7) / 2 = 6`
    -   `square = 6 * 6 = 36`, which is less than `37`, so set `sqr = 6` and `start = 6 + 1 = 7`
    -   Calculate new `mid`: `mid = (7 + 7) / 2 = 7`
    -   `square = 7 * 7 = 49`, which is greater than `37`, so set `end = 7 - 1 = 6`
    -   Loop terminates as `start (7)` is now greater than `end (6)`
    -   The integer part of the square root is `6`.
2.  **Refining the Square Root to 3 Decimal Places**:
    
    -   Initial values: `factor = 1`, `ans = 6`
    -   **First Iteration**:
        -   `factor = 0.1`
        -   Inner loop starts with `j = 6.0`
        -   `j = 6.0` to `6.9` (since `6.9^2` < `37`)
        -   `ans = 6.1` (next iteration starts from `6.1`)
    -   **Second Iteration**:
        -   `factor = 0.01`
        -   Inner loop starts with `j = 6.1`
        -   `j = 6.1` to `6.19` (since `6.19^2` < `37`)
        -   `ans = 6.2` (next iteration starts from `6.2`)
    -   **Third Iteration**:
        -   `factor = 0.001`
        -   Inner loop starts with `j = 6.2`
        -   `j = 6.2` to `6.23` (since `6.23^2` < `37`)
        -   `ans = 6.082` (final refined square root)

##  Example Output 
    
   The program prints: `The Sqrt of 37 is with precision: 6.082`, indicating that the square root of `37` refined to 3 decimal places is approximately `6.082`.
