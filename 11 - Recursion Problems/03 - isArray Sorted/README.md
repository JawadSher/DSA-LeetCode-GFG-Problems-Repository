<h1 align='center'></h1>

## Problem Statement

**Problem URL :** [None]()

Write a recursive function to determine if a given array of integers is sorted in strictly non-decreasing (ascending) order. The function should take as input the array and its size and return a boolean indicating whether the array is sorted.

### Detailed Requirements:
1. **Input**:
   - An array `arr[]` of integers with size `n`.
   
2. **Output**:
   - Return `true` if the array is sorted in non-decreasing order (i.e., each element is less than or equal to the next one). Otherwise, return `false`.
   
3. **Constraints**:
   - The size of the array `n` can be any non-negative integer (`n >= 0`).
   - If the array contains 0 or 1 elements, it is considered sorted.

4. **Function Signature**:
   ```cpp
   bool isSorted(int *arr, int n);
   ```

### Example:

#### Example 1:
**Input**:
```cpp
arr = {10, 20, 30, 40, 50, 60}
n = 6
```
**Output**:
```
True
```
**Explanation**:
The array is sorted in non-decreasing order since each element is less than or equal to the next one.

#### Example 2:
**Input**:
```cpp
arr = {10, 20, 30, 40, 25, 60}
n = 6
```
**Output**:
```
False
```
**Explanation**:
The array is not sorted because `25` is smaller than `40`, which breaks the sorting order.

#### Example 3:
**Input**:
```cpp
arr = {100}
n = 1
```
**Output**:
```
True
```
**Explanation**:
An array with only one element is always sorted.

#### Example 4:
**Input**:
```cpp
arr = {}
n = 0
```
**Output**:
```
True
```
**Explanation**:
An empty array is considered sorted by definition.

## Problem Solution
```cpp
#include <iostream>
using namespace std;

bool isSorted(int *arr, int n){
  if(n == 0 || n == 1){
    return true;
  }

  if(*arr > *(arr + 1)){
    return false;
  }else{
    return isSorted(arr+1, n-1);
  }

}

int main() {
  int new_array[6] = {10, 20, 30, 40, 50, 60};
  
  bool result = isSorted(new_array, 6);

  cout<<"Is Array sorted : "<< (result ? "True" : "False") <<endl;
  return 0;
}
```

## Problem Solution Explanation
This code checks if an array is sorted in ascending order using a recursive approach. Let's break down the logic step by step and explain the recursion tree and function call stack.

#### Function `isSorted(int *arr, int n)`:

- **Base Case**: If the size of the array `n` is 0 or 1, the array is trivially sorted, so the function returns `true`.
  ```cpp
  if(n == 0 || n == 1){
    return true;
  }
  ```
  - **Explanation**: 
    - If the array is empty (`n == 0`), there are no elements to compare, so it is considered sorted.
    - If the array contains only one element (`n == 1`), it's also trivially sorted.
  
- **Recursive Case**: 
  ```cpp
  if(*arr > *(arr + 1)){
    return false;
  }else{
    return isSorted(arr + 1, n - 1);
  }
  ```
  - **Explanation**: 
    - If the current element `*arr` is greater than the next element `*(arr + 1)`, the array is not sorted, so it returns `false`.
    - If the current pair of elements are in order, the function recursively checks the rest of the array by moving the pointer to the next element (`arr + 1`) and reducing the size `n` by 1 (`n - 1`).

---

### Execution Flow (Line-by-Line):

1. **Main Function**:
   - An array `new_array[]` with values `{10, 20, 30, 40, 50, 60}` is declared.
   - The function `isSorted(new_array, 6)` is called to check if this array is sorted.
   - The result of the function is printed to the console: `"Is Array sorted : True"` if the array is sorted.

---

### Function Call Stack and Recursion Tree:

The recursion tree describes the sequence of function calls. Here's how the recursion unfolds:

Let's take the input array: `{10, 20, 30, 40, 50, 60}` and `n = 6`.

#### Function Call Stack:

- The function starts by checking the first two elements and compares if `10 > 20`. Since it's false, it proceeds to check the rest of the array using recursion.
  
- **Call 1**: `isSorted(new_array, 6)`
  - `*arr = 10`, `*(arr+1) = 20`. `10 <= 20`. So, make the recursive call `isSorted(arr + 1, 5)`.
  
- **Call 2**: `isSorted(new_array + 1, 5)`  (array now starts at `20`)
  - `*arr = 20`, `*(arr+1) = 30`. `20 <= 30`. So, make the recursive call `isSorted(arr + 1, 4)`.
  
- **Call 3**: `isSorted(new_array + 2, 4)`  (array now starts at `30`)
  - `*arr = 30`, `*(arr+1) = 40`. `30 <= 40`. So, make the recursive call `isSorted(arr + 1, 3)`.
  
- **Call 4**: `isSorted(new_array + 3, 3)`  (array now starts at `40`)
  - `*arr = 40`, `*(arr+1) = 50`. `40 <= 50`. So, make the recursive call `isSorted(arr + 1, 2)`.

- **Call 5**: `isSorted(new_array + 4, 2)`  (array now starts at `50`)
  - `*arr = 50`, `*(arr+1) = 60`. `50 <= 60`. So, make the recursive call `isSorted(arr + 1, 1)`.

- **Call 6**: `isSorted(new_array + 5, 1)`  (array now starts at `60`)
  - Base case: `n == 1`, so return `true`.

#### Unwinding the Call Stack:
- The `true` returned by **Call 6** is passed back to **Call 5**.
- **Call 5** returns `true` to **Call 4**.
- This process continues until **Call 1**, which ultimately returns `true` to the main function.

---

### Visualization of Recursion Tree:

```
isSorted([10, 20, 30, 40, 50, 60], 6)
        |
        V
isSorted([20, 30, 40, 50, 60], 5)
        |
        V
isSorted([30, 40, 50, 60], 4)
        |
        V
isSorted([40, 50, 60], 3)
        |
        V
isSorted([50, 60], 2)
        |
        V
isSorted([60], 1) -> Base case: return true
```

At each step of the recursion, the size of the array (`n`) decreases by 1, and the starting point of the array moves one step ahead (`arr + 1`). When the base case is reached (array size `1`), the recursion terminates and returns `true` all the way up the stack.

---

### Summary of the Recursion Tree and Function Call Stack:

1. **Function Call Stack**: The function pushes each call onto the stack until it hits the base case. After reaching the base case, it starts popping from the stack and returning values to previous function calls.
  
2. **Recursion Tree**: The recursion progresses deeper into smaller subproblems, reducing the size of the array by 1 with each call, until the base case is reached. Once the base case is met, the results propagate back through the call stack.

Thus, the function checks each adjacent pair of elements in the array until it reaches the last element, ensuring that the entire array is sorted.
