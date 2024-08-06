# Source Code Explanation

### Peak Index in Mountain Array

A "mountain array" is an array that has a sequence of increasing elements followed by a sequence of decreasing elements. The "peak index" is the position of the highest element in this array, which is the point where the sequence changes from increasing to decreasing. For example, in the array `[10, 20, 30, 50, 60, 70, 50, 40]`, the peak index is `5` because `70` is the highest element, and the sequence increases up to `70` and then decreases.

### Explanation

Let's break down the source code step by step:

#### 1. Function Definition

`int peak_index(int arr[], int n) {
    // Function to find the peak index in a mountain array` 

This function takes two parameters:

-   `arr[]`: the array in which we need to find the peak index.
-   `n`: the number of elements in the array.

#### 2. Variable Initialization


 ```
 int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    int index = -1;
``` 

-   `start` is initialized to `0`, representing the beginning of the array.
-   `end` is initialized to `n - 1`, representing the last index of the array.
-   `mid` is calculated as the average of `start` and `end`.
-   `index` is initialized to `-1` and will store the peak index if found.

#### 3. Binary Search Loop

 `while(start < end) {` 

A `while` loop is used to perform a binary search to find the peak index. It continues until `start` is no longer less than `end`.

#### 4. Peak Element Check

```
 if(arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) {
    index = mid;
    return index;
``` 

-   Checks if the element at `mid` is greater than its neighbors (`mid + 1` and `mid - 1`). If true, `mid` is the peak index, and the function returns this index.

#### 5. Adjusting the Search Range

 ```
 } else if(arr[mid] < arr[mid - 1]) {
     end = mid - 1;
``` 

-   If the element at `mid` is less than the element before it (`mid - 1`), it means the peak is in the left half. So, `end` is adjusted to `mid - 1`.


```
 } else {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
``` 

-   If the element at `mid` is not less than the element before it, it means the peak is in the right half. So, `start` is adjusted to `mid + 1`.
-   `mid` is recalculated to continue the binary search.

#### 6. Return Statement

 `return index;
}` 

-   If the peak element is not found in the loop (which is unlikely for a proper mountain array), the function returns `index`, which remains `-1`.

#### 7. Main Function


```
int main() {
    int new_array[] = {10, 20, 30, 50, 60, 70, 50, 40};
    int size = sizeof(new_array) / sizeof(int);

    cout << "The peak index is : " << peak_index(new_array, size);

    return 0;
}
``` 

-   Defines an array `new_array` and calculates its size.
-   Calls `peak_index` with `new_array` and its size, and prints the peak index.

### Summary

This code uses a binary search approach to find the peak index in a mountain array. It iteratively checks the middle element and adjusts the search range based on the comparison with neighboring elements until it finds the peak element. The peak element is the highest point in the array, where the sequence transitions from increasing to decreasing.
