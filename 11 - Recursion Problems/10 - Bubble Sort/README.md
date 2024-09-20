<h1 align='center'>Bubble - Sort</h1>

## Problem Statement

**Problem URL :** [None]()

Write a recursive function `sortArray(arr, n)` that sorts an array of integers using recursion. The function should use a bubble sort-like approach where, in each recursive call, the largest element moves to the end of the array, and the array size is reduced by one.

## Problem Solution
```cpp
#include <iostream>
using namespace std;

void sortArray(int *arr, int n){
  
  // base case - already sorted
  if(n == 0 || n == 1) return;

  for(int i = 0; i < n-1; i++){
    if(arr[i] > arr[i + 1]){
      swap(arr[i], arr[i+1]);
    }
  }

  sortArray(arr, n-1);
}

int main() {
  int new_arr[5] = {2, 5, 1, 6, 9};

   cout<<"Before : ";
  for(int i = 0; i < 5; i++){
    cout<< new_arr[i] << " ";
  }cout<<endl;

  sortArray(new_arr, 5);
  
  cout<<"After : ";
  for(int i = 0; i < 5; i++){
    cout<< new_arr[i] << " ";
  }
  return 0;
}
```

## Problem Solution Explanation

```cpp
#include <iostream>
using namespace std;
```
- **#include <iostream>**: Includes the input/output stream library for using `cin` and `cout`.

```cpp
void sortArray(int *arr, int n) {
```
- **void sortArray(int *arr, int n)**: This function sorts the array `arr` of size `n` using recursion.

```cpp
  if(n == 0 || n == 1) return;
```
- **if(n == 0 || n == 1) return;**: Base case: If the array has only one or zero elements, it is already sorted, so the function returns.

```cpp
  for(int i = 0; i < n - 1; i++) {
```
- **for(int i = 0; i < n - 1; i++)**: A loop to iterate through the array up to the second last element.

```cpp
    if(arr[i] > arr[i + 1]) {
      swap(arr[i], arr[i+1]);
    }
```
- **if(arr[i] > arr[i+1])**: Compares consecutive elements in the array. If the current element is greater than the next, they are swapped to move the larger element towards the end (bubble-up).

```cpp
  sortArray(arr, n - 1);
```
- **sortArray(arr, n - 1);**: After each iteration, the largest element is moved to the correct position, and the function is called recursively with a reduced array size `n-1`.

```cpp
int main() {
  int new_arr[5] = {2, 5, 1, 6, 9};
```
- **int new_arr[5] = {2, 5, 1, 6, 9};**: Initializes an array `new_arr` of size 5 with unsorted elements.

```cpp
  cout<<"Before : ";
  for(int i = 0; i < 5; i++){
    cout<< new_arr[i] << " ";
  }
  cout<<endl;
```
- **cout<<"Before : ";**: Outputs the array before sorting.

```cpp
  sortArray(new_arr, 5);
```
- **sortArray(new_arr, 5);**: Calls the `sortArray` function to sort the array `new_arr` with 5 elements.

```cpp
  cout<<"After : ";
  for(int i = 0; i < 5; i++) {
    cout<< new_arr[i] << " ";
  }
  return 0;
}
```
- **cout<<"After : ";**: Outputs the array after sorting.

---

### Recursive Function Calls and Tree:

#### Example 1: **Array = [2, 5, 1, 6, 9]**

1. **Initial call**: `sortArray([2, 5, 1, 6, 9], 5)`
   - Largest element (9) moves to the correct position.
   - Recursive call: `sortArray([2, 5, 1, 6], 4)`

2. **Next call**: `sortArray([2, 5, 1, 6], 4)`
   - Largest element (6) moves to the correct position.
   - Recursive call: `sortArray([2, 5, 1], 3)`

3. **Next call**: `sortArray([2, 5, 1], 3)`
   - Largest element (5) moves to the correct position.
   - Recursive call: `sortArray([2, 1], 2)`

4. **Next call**: `sortArray([2, 1], 2)`
   - Largest element (2) moves to the correct position.
   - Recursive call: `sortArray([1], 1)`

5. **Base case**: `sortArray([1], 1)`
   - Array has only one element, so return.

---

### Recursive Call Tree:

```
sortArray([2, 5, 1, 6, 9], 5)
    -> [2, 5, 1, 6], 9 is in place
    -> sortArray([2, 5, 1, 6], 4)
        -> [2, 5, 1], 6 is in place
        -> sortArray([2, 5, 1], 3)
            -> [2, 1], 5 is in place
            -> sortArray([2, 1], 2)
                -> [1], 2 is in place
                -> sortArray([1], 1) -> Base case
```

---

### Example 2: **Array = [7, 3, 9, 4]**

1. **Initial call**: `sortArray([7, 3, 9, 4], 4)`
   - Largest element (9) moves to the correct position.
   - Recursive call: `sortArray([7, 3, 4], 3)`

2. **Next call**: `sortArray([7, 3, 4], 3)`
   - Largest element (7) moves to the correct position.
   - Recursive call: `sortArray([3, 4], 2)`

3. **Next call**: `sortArray([3, 4], 2)`
   - Array becomes sorted, and no swap is needed.
   - Recursive call: `sortArray([3], 1)`

4. **Base case**: `sortArray([3], 1)`
   - Array has only one element, so return.

---

### Recursive Call Tree (Example 2):

```
sortArray([7, 3, 9, 4], 4)
    -> [7, 3, 4], 9 is in place
    -> sortArray([7, 3, 4], 3)
        -> [3, 4], 7 is in place
        -> sortArray([3, 4], 2)
            -> [3], 4 is in place
            -> sortArray([3], 1) -> Base case
```

---

### Example 3: **Array = [8, 6, 7]**

1. **Initial call**: `sortArray([8, 6, 7], 3)`
   - Largest element (8) moves to the correct position.
   - Recursive call: `sortArray([6, 7], 2)`

2. **Next call**: `sortArray([6, 7], 2)`
   - Array becomes sorted, and no swap is needed.
   - Recursive call: `sortArray([6], 1)`

3. **Base case**: `sortArray([6], 1)`
   - Array has only one element, so return.

---

### Final Outputs for Each Example:

1. **Input**: `[2, 5, 1, 6, 9]`
   - **Output**: `[1, 2, 5, 6, 9]`

2. **Input**: `[7, 3, 9, 4]`
   - **Output**: `[3, 4, 7, 9]`

3. **Input**: `[8, 6, 7]`
   - **Output**: `[6, 7, 8]`

---

### Summary:

- The function implements a recursive bubble sort-like approach.
- At each step, it bubbles the largest element to the end and reduces the problem size by one.
- The base case stops the recursion when the array is sorted or contains one element.
