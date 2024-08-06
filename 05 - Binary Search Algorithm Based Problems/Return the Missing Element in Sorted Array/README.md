# Source Code Explanation

## Problem Explanation

Given a sorted array of integers where each element is unique and starts from 0, the task is to find the smallest missing element. For example:

-   If the input array is `[0, 1, 2, 3, 5, 6, 7]`, the smallest missing element is `4`.
-   If the input array is `[0, 1, 2, 3, 4, 5]`, there are no missing elements, so the smallest missing element is `6`.

## Approach to Solve the Problem

#### 1. **Binary Search Approach**

Since the array is sorted and we are looking for the smallest missing element, a binary search approach can be applied efficiently:

-   **Binary Search Idea**:
    
    -   Utilize the fact that in a sorted array where elements start from 0, the index of an element should match its value if no elements are missing up to that point.
-   **Steps**:
    
    -   Initialize `start` to `0` and `end` to `n-1`, where `n` is the size of the array.
    -   Calculate `mid` as `(start + end) / 2`.
    -   Check the element at `mid`:
        -   If `arr[mid]` is equal to `mid`, it means no elements are missing up to `arr[mid]`, so the missing element must be to the right of `mid`. Therefore, update `start= mid + 1`.
        -   If `arr[mid]` is greater than `mid`, it means at least one element is missing before `arr[mid]`, so the missing element must be to the left of `mid`. Therefore, update `end= mid - 1`.
-   **Termination**:
    
    -   The loop terminates when `start` exceeds `end`. At this point, `left` should indicate the smallest missing element.
     
## Code Explanation
```
#include<iostream>
using namespace std;

int missing_element(int arr[], int s){
    int start = 0;
    int end = s - 1;
    int mid = start + (end - start)/2;
    
    while(start <= end){
        if(arr[mid] == mid){
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return start;
}

int main(){
    int new_array[] = {0, 1, 2, 3, 5, 6};
    int size = sizeof(new_array) / sizeof(int);
    
    int missing_ele = missing_element(new_array, size); 
    cout<<"The missing Element is : "<<missing_ele;
    
    return 0;
}

```
#### `missing_element` Function

-   **Parameters**:
    
    -   `int arr[]`: Represents the input sorted array of integers where each element starts from 0.
    -   `int s`: Represents the size of the array (`sizeof(arr) / sizeof(int)`), though in this implementation, `s` is directly used as the size of the array.
-   **Initialization**:
    
    -   `start`: Initialized to `0`, indicating the beginning index of the search range.
    -   `end`: Initialized to `s - 1`, indicating the last index of the array.
    -   `mid`: Initially calculated as the midpoint index of the current search range.
-   **Binary Search Loop**:
    
    -   The `while` loop continues as long as `start` is less than or equal to `end`.
    -   Inside the loop:
        -   Calculates `mid` as `(start + end) / 2`, the midpoint of the current search range.
        -   Checks if `arr[mid]` is equal to `mid`:
            -   If true, it means no elements are missing up to index `mid`, so update `start = mid + 1` to search the right half.
            -   If false, it means at least one element is missing up to index `mid`, so update `end = mid - 1` to search the left half.
        -   Updates `mid` again based on the updated `start` and `end`.
-   **Return**:
    
    -   When the loop exits (`start > end`), `start` represents the index where the smallest missing element starts, because `arr[start]` will be the first element where `arr[start] != start`.

#### `main` Function

-   **Array Initialization**:
    
    -   Defines an example array `new_array` with elements `[0, 1, 2, 3, 5, 6]`.
-   **Size Calculation**:
    
    -   Calculates the size of `new_array` using `sizeof(new_array) / sizeof(int)`, which determines the number of elements in the array.
-   **Function Call**:
    
    -   Calls `missing_element(new_array, size)` to find the smallest missing element in `new_array`.
    -   Stores the result in `missing_ele`.
-   **Output**:
    
    -   Prints the result using `cout`, indicating the smallest missing element found in the array.

### Purpose and GitHub Context

-   **Purpose**: This code snippet demonstrates a binary search-based approach to find the smallest missing element in a sorted array where elements start from 0.
-   **Explanation**: It's designed to be clear and concise, efficiently handling the task with a time complexity of `O(log n)` due to binary search.

### DSA Students Information

For GitHub viewers, this code snippet serves as a concise example of implementing a binary search algorithm to solve a specific problem: finding the smallest missing element in a sorted array starting from 0. It's well-suited for learning and understanding binary search applications in algorithmic problem-solving scenarios.
