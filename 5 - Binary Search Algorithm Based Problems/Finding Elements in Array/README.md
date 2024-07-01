# Source Code Explanation

### Headers and Namespace

```
#include<iostream>
using namespace std;
``` 

-   **`#include<iostream>`**: This directive includes the standard input-output stream library, which is necessary for using `cout` for output.
-   **`using namespace std;`**: This line allows us to use standard library features (like `cout` and `cin`) without needing to prefix them with `std::`.

### Binary Search Function


```
int binary_search(int arr[], int n, int k) {
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    
    while (start <= end) {
        if (arr[mid] == k) {
            return mid;
        }
        
        if (k > arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        
        mid = start + (end - start) / 2;
    }
    return -1;
}
``` 

-   **Parameters**:
    -   `arr[]`: The array to search.
    -   `n`: The size of the array.
    -   `k`: The key to search for.
-   **Variables**:
    -   `start`: The starting index of the search range.
    -   `end`: The ending index of the search range.
    -   `mid`: The middle index of the current search range.
-   **Logic**:
    -   The `while` loop continues as long as `start` is less than or equal to `end`.
    -   If the middle element `arr[mid]` equals the key `k`, it returns the index `mid`.
    -   If the key `k` is greater than `arr[mid]`, it moves the `start` index to `mid + 1` to search the right half.
    -   Otherwise, it moves the `end` index to `mid - 1` to search the left half.
    -   The middle index `mid` is recalculated in each iteration.
    -   If the key is not found, the function returns `-1`.

### Main Function


```
int main() {
    int new_array[] = {10, 20, 30, 40, 50, 60, 70};
    int size = sizeof(new_array) / sizeof(int);
    int key = 30;
    int key1 = 70;
    
    int key_index = binary_search(new_array, size, key);
    cout << "Index of value " << key << " is " << key_index;
    
    cout << endl;
        
    int key_index1 = binary_search(new_array, size, key1);
    cout << "Index of value " << key1 << " is " << key_index1;
    
    return 0;
}
``` 

-   **Array Declaration**:
    -   `new_array[]`: An array of integers initialized with `{10, 20, 30, 40, 50, 60, 70}`.
    -   `size`: The number of elements in `new_array`, calculated by dividing the total byte size of `new_array` by the byte size of an integer.
-   **Key Declarations**:
    -   `key`: The first key to search for, with a value of `30`.
    -   `key1`: The second key to search for, with a value of `70`.
-   **Function Calls**:
    -   `binary_search(new_array, size, key)`: Searches for the first key (`30`) in `new_array` and returns its index.
    -   `binary_search(new_array, size, key1)`: Searches for the second key (`70`) in `new_array` and returns its index.
-   **Output**:
    -   The indices of the keys `30` and `70` in the array are printed using `cout`.

### Sample Output

```
Index of value 30 is 2
Index of value 70 is 6
``` 

## How to Use

1.  **Copy the code**: Copy the provided code into your C++ development environment (e.g., a file named `binary_search.cpp`).
2.  **Compile the code**: Use a C++ compiler to compile the code. For example, using g++:
    
    `g++ -o binary_search binary_search.cpp` 
    
3.  **Run the executable**: Execute the compiled program:
    
    
    `./binary_search` 
    
4.  **See the output**: The program will output the indices of the specified keys in the array.

## Conclusion

This example demonstrates how to implement and use the Binary Search algorithm in C++. Binary Search is a fundamental algorithm with a wide range of applications, especially in scenarios where efficient searching of sorted data is required.

Feel free to use and modify this code for your own projects. Happy coding!
