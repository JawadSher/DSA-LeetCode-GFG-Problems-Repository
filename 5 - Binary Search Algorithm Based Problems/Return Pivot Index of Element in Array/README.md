# Source Code Explanation
### Pivot Index

The pivot index in an array is the index where the sum of all the numbers to the left of the index is equal to the sum of all the numbers to the right of the index. In other words, it is the point where the array is balanced. For example, in the array `[10, 20, 30, 60, 40, 5, 5, 10]`, the pivot index is `3` because the sum of elements on the left side of index `3` (`10 + 20 + 30`) equals the sum of elements on the right side (`40 + 5 + 5 + 10`).

### Explanation 

Let's break down the source code step by step:

#### 1. Function Definition


`int pivot_index(int arr[], int n) {
    // Function to find the pivot index in the array` 

This function takes two parameters:

-   `arr[]`: the array in which we need to find the pivot index.
-   `n`: the number of elements in the array.

#### 2. Variable Initialization

```
 int index = -1;
 int total_sum = 0;
 int left_sum = 0;
``` 

-   `index` is initialized to `-1` and will store the pivot index if found.
-   `total_sum` is initialized to `0` and will store the sum of all elements in the array.
-   `left_sum` is initialized to `0` and will store the sum of elements on the left side of the current index.

#### 3. Calculate Total Sum of Array

 ```
 for(int i = 0; i < n; i++) {
        total_sum += arr[i];
    }
``` 

-   This `for` loop iterates through the array and calculates the sum of all elements, storing it in `total_sum`.

#### 4. Find Pivot Index

 ```
 for(int i = 0; i < n; i++) {
        int right_sum = (total_sum - left_sum) - arr[i];
        
        if(left_sum == right_sum) {
            return i;
        }
        left_sum += arr[i];
    }
  ``` 

-   This `for` loop iterates through the array to find the pivot index.
-   For each element `arr[i]`, it calculates the `right_sum` by subtracting the `left_sum` and the current element `arr[i]` from `total_sum`.
-   If `left_sum` is equal to `right_sum`, it means the current index `i` is the pivot index, and the function returns `i`.
-   If not, it adds the current element `arr[i]` to `left_sum` and moves to the next index.

#### 5. Return Statement

 `return index;
}` 

-   If the pivot index is not found in the loop, the function returns `index`, which remains `-1`.

#### 6. Main Function

```
int main() {
    int new_array[] = {10, 20, 30, 60, 40, 5, 5, 10};
    int size = sizeof(new_array) / sizeof(int);
    
    int index = pivot_index(new_array, size);
    cout << "The Pivot Index is : " << index;
    return 0;
}
``` 

-   Defines an array `new_array` and calculates its size.
-   Calls `pivot_index` with `new_array` and its size, and stores the result in `index`.
-   Prints the pivot index.

### Summary

This code calculates the pivot index of an array where the sum of elements on the left side of the index is equal to the sum of elements on the right side. It first computes the total sum of the array, then iterates through the array to find the index where the left sum equals the right sum. If such an index is found, it returns that index; otherwise, it returns `-1`.
