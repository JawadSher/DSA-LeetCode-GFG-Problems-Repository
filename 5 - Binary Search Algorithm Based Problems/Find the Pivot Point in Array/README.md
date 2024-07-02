# Source Code Explanation

### Pivot Point

In the context of a rotated sorted array, the "pivot point" is the index at which the rotation has occurred. Essentially, it's the point where the array transitions from the end of one sorted sequence to the beginning of another. For instance, in the array `[10, 20, 30, 1, 2, 3]`, the pivot point is at index `3` because `1` marks the beginning of the second sorted sequence after the rotation.

### Explanation 

Let's break down the source code step by step:

#### 1. Function Definition


`int pivot_index(int arr[], int n) {
    // Function to find the pivot index in a rotated sorted array` 

This function takes two parameters:

-   `arr[]`: the rotated sorted array in which we need to find the pivot index.
-   `n`: the number of elements in the array.

#### 2. Variable Initialization

```
 int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
``` 

-   `start` is initialized to `0`, representing the beginning of the array.
-   `end` is initialized to `n - 1`, representing the last index of the array.
-   `mid` is calculated as the average of `start` and `end`.

#### 3. Binary Search Loop


 `while (start < end) {` 

A `while` loop is used to perform a binary search to find the pivot index. It continues until `start` is no longer less than `end`.

#### 4. Adjusting the Search Range

 ```
 if (arr[mid] >= arr[0]) {
            start = mid + 1;
        } else {
            end = mid;
        }
        
        mid = start + (end - start) / 2;
   ``` 

-   If the element at `mid` is greater than or equal to the first element (`arr[0]`), it means the pivot point is in the right half of the array. So, `start` is adjusted to `mid + 1`.
-   If the element at `mid` is less than the first element, it means the pivot point is in the left half of the array. So, `end` is adjusted to `mid`.
-   `mid` is recalculated to continue the binary search.

#### 5. Return Statement

cpp

Copy code

 `return start;
}` 

-   Once the loop terminates, the `start` variable will point to the pivot index. The function returns `start`.

#### 6. Main Function

```
int main() {
    int new_array[] = {10, 20, 30, 1, 2, 3};
    int size = sizeof(new_array) / sizeof(int);
    
    int index = pivot_index(new_array, size);
    cout << "The Pivot Point Index is : " << index;
    return 0;
}
``` 

-   Defines an array `new_array` and calculates its size.
-   Calls `pivot_index` with `new_array` and its size, and stores the result in `index`.
-   Prints the pivot index.

### Summary

This code uses a binary search approach to find the pivot index in a rotated sorted array. It iteratively checks the middle element and adjusts the search range based on the comparison with the first element of the array until it finds the pivot point. The pivot point is the index where the array transitions from the highest element to the lowest element due to rotation. The function returns the index of this pivot point.
