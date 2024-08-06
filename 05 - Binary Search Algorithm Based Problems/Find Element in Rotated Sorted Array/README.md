# Source Code Explanation
### Rotated Sorted Array

A rotated sorted array is a sorted array that has been rotated (shifted) around a pivot point, causing the array to no longer be in a perfectly increasing order. However, within the array, two subarrays remain in sorted order: one from the start of the array to the pivot, and one from the pivot to the end of the array.

For example, consider the sorted array `[1, 2, 3, 4, 5, 6, 7]`. If this array is rotated at the pivot point `3`, it might look like this: `[4, 5, 6, 7, 1, 2, 3]`.

### Characteristics of a Rotated Sorted Array

1.  **Two Sorted Subarrays**: Despite the rotation, the array consists of two individually sorted subarrays. In the example `[4, 5, 6, 7, 1, 2, 3]`, the subarrays `[4, 5, 6, 7]` and `[1, 2, 3]` are both sorted.
2.  **Pivot Point**: The pivot point is where the rotation occurs. It is the index where the transition from the largest element of the first subarray to the smallest element of the second subarray happens.
3.  **Rotation**: The array maintains its order relative to the rotation, meaning the order of elements is preserved but shifted.

### Explanation of the Source Code with Rotated Sorted Array

The provided source code finds an element in a rotated sorted array by first identifying the pivot point and then performing a binary search on the appropriate subarray.

#### 1. Finding the Pivot Index

The `pivot_index` function finds the pivot point where the rotation occurs:


```
int pivot_index(int arr[], int n) {
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    
    while (start < end) {
        if (arr[mid] >= arr[0]) {
            start = mid + 1;
        } else {
            end = mid;
        }
        mid = start + (end - start) / 2;
    }
    return start;
}
``` 

-   The function initializes `start` to `0` and `end` to `n - 1`.
-   It calculates `mid` as the average of `start` and `end`.
-   In each iteration, it checks if the middle element (`arr[mid]`) is greater than or equal to the first element (`arr[0]`):
    -   If true, the pivot must be in the right half of the array, so `start` is set to `mid + 1`.
    -   Otherwise, the pivot must be in the left half, so `end` is set to `mid`.
-   The loop continues until `start` is no longer less than `end`, and the function returns `start`, which points to the pivot index.

#### 2. Binary Search

The `binary_search` function performs a binary search on a subarray:

```
int binary_search(int arr[], int s, int e, int key) {
    int start = s;
    int end = e;
    int mid = start + (end - start) / 2;
    
    while (start <= end) {  // Change from < to <= to handle cases where the array size is 1
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] > key) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1; // Return -1 if the element is not found
}
``` 

-   The function initializes `start` to `s` and `end` to `e`.
-   It calculates `mid` as the average of `start` and `end`.
-   In each iteration, it checks if the middle element (`arr[mid]`) is equal to the `key`:
    -   If true, it returns `mid`.
    -   If `arr[mid]` is greater than the `key`, the search range is adjusted to the left half (`end = mid - 1`).
    -   Otherwise, the search range is adjusted to the right half (`start = mid + 1`).
-   The loop continues until `start` is no longer less than or equal to `end`, and the function returns `-1` if the `key` is not found.

#### 3. Main Function

The `main` function integrates the `pivot_index` and `binary_search` functions to find the `key` in the rotated sorted array:

```
int main() {
    int new_array[] = {10, 20, 30, 1, 2, 3};
    int size = sizeof(new_array) / sizeof(int);
    int key = 1;
    
    int pivot = pivot_index(new_array, size);
    if (key >= new_array[pivot] && key <= new_array[size - 1]) {
        cout << "Element is Found on Index: " << binary_search(new_array, pivot, size - 1, key) << endl;
    } else {
        cout << "Element is Found on Index: " << binary_search(new_array, 0, pivot - 1, key) << endl;
    }
    
    return 0;
}
``` 

-   Defines an array `new_array` and calculates its size.
-   Defines the `key` to be searched.
-   Calls `pivot_index` to find the pivot index in `new_array`.
-   Determines if the `key` lies in the right subarray (`pivot` to `size - 1`) or the left subarray (`0` to `pivot - 1`).
-   Calls `binary_search` on the appropriate subarray and prints the result.

### Detailed Example

Given the array `[10, 20, 30, 1, 2, 3]` and the `key` `1`:

1.  **Finding the Pivot Index**:
    
    -   Initial values: `start = 0`, `end = 5`
    -   Calculate `mid`: `mid = (0 + 5) / 2 = 2`
    -   Since `arr[mid]` (30) is greater than `arr[0]` (10), set `start = mid + 1 = 3`
    -   Calculate new `mid`: `mid = (3 + 5) / 2 = 4`
    -   Since `arr[mid]` (2) is less than `arr[0]` (10), set `end = mid = 4`
    -   Calculate new `mid`: `mid = (3 + 4) / 2 = 3`
    -   Since `arr[mid]` (1) is less than `arr[0]` (10), set `end = mid = 3`
    -   Loop terminates as `start` (3) is no longer less than `end` (3)
    -   Pivot index is `3`
2.  **Searching for the Key**:
    
    -   Key to be searched: `1`
    -   Pivot index: `3`
    -   Since `key` (1) is greater than or equal to `new_array[pivot]` (1) and less than or equal to `new_array[size - 1]` (3), search in the right subarray (`pivot` to `size - 1`)
    -   Perform binary search on subarray `[1, 2, 3]`:
        -   Initial values: `start = 3`, `end = 5`
        -   Calculate `mid`: `mid = (3 + 5) / 2 = 4`
        -   Since `arr[mid]` (2) is greater than `key` (1), set `end = mid - 1 = 3`
        -   Calculate new `mid`: `mid = (3 + 3) / 2 = 3`
        -   Since `arr[mid]` (1) is equal to `key` (1), return `mid` (3)
## Example Output:
    
    -   The key `1` is found at index `3` in the array.
    -   The output is: `Element is Found on Index: 3`
