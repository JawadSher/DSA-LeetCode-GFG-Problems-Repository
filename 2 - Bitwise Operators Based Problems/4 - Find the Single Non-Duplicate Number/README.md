## Source Code Explanation

### Includes and Namespace

```#include <iostream>```

```using namespace std;``` 

-   `#include <iostream>`: Includes the Input/Output Stream library, which is necessary for using `cin` and `cout`.
-   `using namespace std;`: Allows using the standard namespace so that `std::` is not needed before standard library functions and objects like `cout`.

### Function Definition
```
int singleNonDuplicate(int arr[], int s) {
    int result = 0;
    for (int i = 0; i < s; i++) {
        result = result ^ arr[i];
    }
    return result;
}
``` 

-   `int singleNonDuplicate(int arr[], int s)`: Defines a function named `singleNonDuplicate` that takes an array `arr` and its size `s` as input, and returns an integer which is the single non-duplicate element.
-   `int result = 0;`: Initializes a variable `result` to `0`.
-   `for (int i = 0; i < s; i++)`: Loops over each element in the array `arr`.
    -   `result = result ^ arr[i];`: XORs each element with `result`. The XOR operation has the property that `a ^ a = 0` and `a ^ 0 = a`. When each element appears twice, the XOR operation cancels out the duplicates, leaving only the non-duplicate element.
-   `return result;`: Returns the single non-duplicate element.

### Main Function

```
int main() {
    int arr[] = {4, 1, 2, 1, 2};
    int size = sizeof(arr) / sizeof(int);
    int result = singleNonDuplicate(arr, size);
    cout << "The single non-duplicate element is: " << result << endl;
    return 0;
}
``` 

-   `int main() { ... }`: The main function where program execution begins.
-   `int arr[] = {4, 1, 2, 1, 2};`: Declares and initializes an array `arr` with elements `[4, 1, 2, 1, 2]`.
-   `int size = sizeof(arr) / sizeof(int);`: Calculates the size of the array `arr`.
    -   `sizeof(arr)`: Gives the total number of bytes occupied by the array.
    -   `sizeof(int)`: Gives the number of bytes occupied by an `int` type.
    -   `sizeof(arr) / sizeof(int)`: Divides the total size of the array by the size of an integer to get the number of elements in the array.
-   `int result = singleNonDuplicate(arr, size);`: Calls the `singleNonDuplicate` function with the array and its size, storing the result in the variable `result`.
-   `cout << "The single non-duplicate element is: " << result << endl;`: Outputs the result to the console.
-   `return 0;`: Indicates successful completion of the program.

## Example Execution

Given the array `[4, 1, 2, 1, 2]`:

1.  The `singleNonDuplicate` function is called with `arr` and `size`.
2.  Inside the function:
    -   `result` is initialized to `0`.
    -   Iterating over the array:
        -   `result ^= 4` results in `result = 4`.
        -   `result ^= 1` results in `result = 5` (since `4 ^ 1 = 5`).
        -   `result ^= 2` results in `result = 7` (since `5 ^ 2 = 7`).
        -   `result ^= 1` results in `result = 6` (since `7 ^ 1 = 6`).
        -   `result ^= 2` results in `result = 4` (since `6 ^ 2 = 4`).
3.  The function returns `4`, which is the single non-duplicate element.
4.  The main function prints `4` as the result.

### Summary

-   This code demonstrates how to find the single non-duplicate element in an array using the XOR operation.
-   The main function initializes an array, calculates its size, and calls the function to get and print the non-duplicate element.
-   The XOR operation effectively cancels out duplicate elements, leaving only the unique element.
