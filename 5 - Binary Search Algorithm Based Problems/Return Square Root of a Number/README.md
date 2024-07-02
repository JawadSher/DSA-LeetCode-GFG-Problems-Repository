# Source Code Explanation

This code snippet calculates the integer part of the square root of a given number using a binary search approach. Let's break down the code step by step.

#### 1. `find_sqrt` Function

The `find_sqrt` function takes an integer `num` and returns the integer part of its square root.


```
int find_sqrt(int num) {
    int start = 0;
    int end = num;
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end) {
        int sqr = mid * mid;
        if (sqr == num) {
            return mid;
        } else if (sqr > num) {
            end = mid - 1;
        } else {
            start = mid + 1;
            ans = mid;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}
``` 

-   **Initialization**:
    
    -   `start` is set to `0`.
    -   `end` is set to `num`.
    -   `mid` is initialized to the average of `start` and `end`.
    -   `ans` is initialized to `-1`.
-   **Binary Search**:
    
    -   The `while` loop runs as long as `start` is less than or equal to `end`.
    -   `sqr` is calculated as `mid * mid`.
    -   If `sqr` is equal to `num`, `mid` is the exact square root, so return `mid`.
    -   If `sqr` is greater than `num`, it means `mid` is too large, so adjust `end` to `mid - 1`.
    -   If `sqr` is less than `num`, it means `mid` is too small, so adjust `start` to `mid + 1` and set `ans` to `mid`.
    -   Recalculate `mid` for the next iteration.
-   **Return Value**:
    
    -   If the loop terminates without finding an exact square root, return `ans`, which holds the largest integer whose square is less than or equal to `num`.

#### 2. `main` Function

The `main` function calls the `find_sqrt` function and prints the result.

```
int main() {
    int num = 8;
    int sqrt_num = find_sqrt(num);
    cout << "Square Root of " << num << " is : " << sqrt_num;
   
    return 0;
}
``` 

-   Defines an integer `num` with the value `8`.
-   Calls `find_sqrt(num)` to compute the integer part of the square root of `8`.
-   Prints the result.

### Detailed Example

Let's go through an example where `num` is `8`.

1.  **Initialization**:
    
    -   `start = 0`
    -   `end = 8`
    -   `mid = (0 + 8) / 2 = 4`
    -   `ans = -1`
2.  **First Iteration**:
    
    -   `sqr = 4 * 4 = 16`
    -   Since `sqr > 8`, set `end = 4 - 1 = 3`
    -   Calculate new `mid = (0 + 3) / 2 = 1`
3.  **Second Iteration**:
    
    -   `sqr = 1 * 1 = 1`
    -   Since `sqr < 8`, set `start = 1 + 1 = 2` and `ans = 1`
    -   Calculate new `mid = (2 + 3) / 2 = 2`
4.  **Third Iteration**:
    
    -   `sqr = 2 * 2 = 4`
    -   Since `sqr < 8`, set `start = 2 + 1 = 3` and `ans = 2`
    -   Calculate new `mid = (3 + 3) / 2 = 3`
5.  **Fourth Iteration**:
    
    -   `sqr = 3 * 3 = 9`
    -   Since `sqr > 8`, set `end = 3 - 1 = 2`
    -   Loop terminates as `start (3)` is now greater than `end (2)`
6.  **Return Value**:
    
    -   The function returns `ans`, which is `2`.

## Example Output

The program prints: `Square Root of 8 is : 2`, indicating that the integer part of the square root of `8` is `2`.
