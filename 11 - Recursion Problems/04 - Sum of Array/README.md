<h1 align='center'>Sum - of - Array</h1>

## Problem Statement

**Problem URL :** [None]()

Write a recursive function to compute the sum of all elements in an array of integers. The function should take the array and its size as input and return the total sum of its elements.

### Detailed Requirements:
1. **Input**:
   - An array `arr[]` of integers and its size `n`.
   
2. **Output**:
   - Return the sum of all the elements in the array.
   
3. **Constraints**:
   - The size of the array `n` can be any non-negative integer (`n >= 0`).
   - If the array is empty (`n == 0`), the sum should be 0.

4. **Function Signature**:
   ```cpp
   int sum(int *arr, int n);
   ```

### Example:

#### Example 1:
**Input**:
```cpp
arr = {10, 20, 30, 40, 50}
n = 5
```
**Output**:
```
150
```
**Explanation**:
The sum of the array elements is `10 + 20 + 30 + 40 + 50 = 150`.

#### Example 2:
**Input**:
```cpp
arr = {1}
n = 1
```
**Output**:
```
1
```
**Explanation**:
The sum of a single-element array is just the element itself.

#### Example 3:
**Input**:
```cpp
arr = {}
n = 0
```
**Output**:
```
0
```
**Explanation**:
An empty array has a sum of `0`.

## Problem Solution
```cpp
#include <iostream>
using namespace std;

int sum(int *arr, int n){
  if(n == 0){
    return 0;
  }

  return *(arr) + sum(arr + 1, n-1);
}

int main() {
  int new_array[] = {10, 20, 30, 40, 50};

  int total = sum(new_array, 5);
  cout<<"The sum new_array is : "<< total <<endl;
  return 0;
}
```

## Problem Solution Explanation
### Code Explanation:

The provided code calculates the sum of the elements in an array using a recursive approach. Let's go through the logic step by step.

#### Function `sum(int *arr, int n)`:
1. **Base Case**:
   ```cpp
   if(n == 0){
      return 0;
   }
   ```
   - If the array has zero elements (`n == 0`), the sum is `0`. This is the base case that stops the recursion.
   
2. **Recursive Case**:
   ```cpp
   return *(arr) + sum(arr + 1, n - 1);
   ```
   - The function returns the value of the first element (`*arr`) added to the sum of the rest of the array (`sum(arr + 1, n - 1)`).
   - The recursion reduces the size of the array (`n - 1`) and shifts the pointer to the next element (`arr + 1`), continuously reducing the problem size.

#### Main Function:
1. The array `new_array[] = {10, 20, 30, 40, 50}` is passed to the `sum` function.
2. The result of the `sum` function is stored in the variable `total`, and then it is printed to the console.

### Function Call Stack and Recursion Tree:

#### Execution Flow:

Let’s consider the input array `new_array[] = {10, 20, 30, 40, 50}` with `n = 5`.

#### Function Call Stack:
1. The main function calls `sum(new_array, 5)`.
2. The function checks if `n == 0`. Since `n` is not zero, it adds `*arr` (the first element of the array) to the result of the recursive call.
   
   The sequence of function calls looks like this:
   - **Call 1**: `sum(new_array, 5)`:
     - Returns `10 + sum(arr + 1, 4)`
   - **Call 2**: `sum(new_array + 1, 4)` (array starts at `20`):
     - Returns `20 + sum(arr + 1, 3)`
   - **Call 3**: `sum(new_array + 2, 3)` (array starts at `30`):
     - Returns `30 + sum(arr + 1, 2)`
   - **Call 4**: `sum(new_array + 3, 2)` (array starts at `40`):
     - Returns `40 + sum(arr + 1, 1)`
   - **Call 5**: `sum(new_array + 4, 1)` (array starts at `50`):
     - Returns `50 + sum(arr + 1, 0)`
   - **Call 6**: `sum(new_array + 5, 0)`:
     - Base case: returns `0`

#### Unwinding the Call Stack:
- **Call 6** returns `0` to **Call 5**.
- **Call 5** returns `50 + 0 = 50` to **Call 4**.
- **Call 4** returns `40 + 50 = 90` to **Call 3**.
- **Call 3** returns `30 + 90 = 120` to **Call 2**.
- **Call 2** returns `20 + 120 = 140` to **Call 1**.
- **Call 1** returns `10 + 140 = 150` to `main`.

So the total sum is `150`.

---

### Recursion Tree:

Here’s a visualization of how the recursion tree looks:

```
sum([10, 20, 30, 40, 50], 5)
        |
        V
10 + sum([20, 30, 40, 50], 4)
        |
        V
20 + sum([30, 40, 50], 3)
        |
        V
30 + sum([40, 50], 2)
        |
        V
40 + sum([50], 1)
        |
        V
50 + sum([], 0) -> Base case: return 0
```

The recursion tree clearly shows how the function splits the problem into smaller parts, reducing the size of the array by 1 at each step, and then summing up the elements as it returns from the base case.

---

### Summary of Recursion Tree and Function Call Stack:

- **Function Call Stack**: Each recursive call is pushed onto the stack until the base case is reached (`n == 0`). After the base case returns `0`, the stack starts unwinding, and the results of the recursive calls are added together.
  
- **Recursion Tree**: The recursion progressively reduces the size of the array (`n`) while summing the elements. Once the base case is reached, the sum is computed as the recursive calls return their results.
