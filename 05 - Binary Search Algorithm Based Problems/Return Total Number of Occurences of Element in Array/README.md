# Source Code Explanation

### Headers and Namespace

```
#include<iostream>
using namespace std;
``` 

-   **`#include<iostream>`**: This directive includes the standard input-output stream library, which provides the functionality for input and output operations.
-   **`using namespace std;`**: This line allows us to use standard library features (like `cout` and `cin`) without needing to prefix them with `std::`.

### First Index Function


```
int first_Index(int arr[], int n, int k) {
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    int index = -1;
    
    while (start <= end) {
        if (arr[mid] == k) {
            index = mid;
            end = mid - 1;
        } else if (k < arr[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return index;
};
``` 

-   **Parameters**:
    -   `arr[]`: The array to search.
    -   `n`: The size of the array.
    -   `k`: The key to search for.
-   **Variables**:
    -   `start`: The starting index of the search range, initialized to `0`.
    -   `end`: The ending index of the search range, initialized to `n - 1`.
    -   `mid`: The middle index of the current search range, calculated as `start + (end - start) / 2`.
    -   `index`: Variable to store the index of the first occurrence of the key `k`, initialized to `-1` (indicating not found).
-   **Logic**:
    -   The `while` loop continues as long as `start` is less than or equal to `end`.
    -   If the middle element `arr[mid]` equals the key `k`, the index is updated to `mid`, and `end` is moved to `mid - 1` to continue searching in the left half for any earlier occurrence.
    -   If the key `k` is less than `arr[mid]`, the search range is moved to the left half by updating `end` to `mid - 1`.
    -   If the key `k` is greater than `arr[mid]`, the search range is moved to the right half by updating `start` to `mid + 1`.
    -   The middle index `mid` is recalculated in each iteration.
    -   If the key is not found, the function returns `-1`.

### Last Index Function

```
int last_Index(int arr[], int n, int k) {
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    int index = -1;
    
    while (start <= end) {
        if (arr[mid] == k) {
            index = mid;
            start = mid + 1;
        } else if (k < arr[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return index;
};
``` 

-   **Parameters and Variables**: Same as the `first_Index` function.
-   **Logic**:
    -   The `while` loop continues as long as `start` is less than or equal to `end`.
    -   If the middle element `arr[mid]` equals the key `k`, the index is updated to `mid`, and `start` is moved to `mid + 1` to continue searching in the right half for any later occurrence.
    -   If the key `k` is less than `arr[mid]`, the search range is moved to the left half by updating `end` to `mid - 1`.
    -   If the key `k` is greater than `arr[mid]`, the search range is moved to the right half by updating `start` to `mid + 1`.
    -   The middle index `mid` is recalculated in each iteration.
    -   If the key is not found, the function returns `-1`.

### Main Function

```
int main() {
    int new_array[] = {10, 20, 30, 30, 30, 40, 50, 60, 70};
    int size = sizeof(new_array) / sizeof(int);
    int key = 30;
    
    int first_index = first_Index(new_array, size, key);
    int last_index = last_Index(new_array, size, key);
    int total_occurrences = (last_index - first_index) + 1;
    
    cout << "Total Number of Occurrences is " << total_occurrences << " of Element " << key;
    
    return 0;
}
``` 

-   **Array Declaration**:
    -   `new_array[]`: An array of integers initialized with `{10, 20, 30, 30, 30, 40, 50, 60, 70}`.
    -   `size`: The number of elements in `new_array`, calculated by dividing the total byte size of `new_array` by the byte size of an integer.
-   **Key Declaration**:
    -   `key`: The value to search for in the array, with a value of `30`.
-   **Function Calls**:
    -   `first_Index(new_array, size, key)`: Calls the function to find the first occurrence of the key (`30`) in `new_array` and stores the result in `first_index`.
    -   `last_Index(new_array, size, key)`: Calls the function to find the last occurrence of the key (`30`) in `new_array` and stores the result in `last_index`.
-   **Total Occurrences Calculation**:
    -   `total_occurrences`: Calculates the total number of occurrences of the key by subtracting `first_index` from `last_index` and adding `1`.
-   **Output**:
    -   Prints the total number of occurrences of the key `30` using `cout`.

## Example Output


`Total Number of Occurrences is 3 of Element 30` 

## How It Works

1.  **Initialization**:
    -   Arrays and key are defined, and their sizes are calculated.
2.  **Finding First Occurrence**:
    -   The `first_Index` function is called to find the index of the first occurrence of the key (`30`).
3.  **Finding Last Occurrence**:
    -   The `last_Index` function is called to find the index of the last occurrence of the key (`30`).
4.  **Calculating Total Occurrences**:
    -   The total number of occurrences is calculated by subtracting the first index from the last index and adding `1`.
5.  **Output**:
    -   The total number of occurrences is printed to the console.
