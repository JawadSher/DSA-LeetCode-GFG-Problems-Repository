<h1 align='center'>Example</h1>

## Problem Statement

Write a function that sorts an array of integers in ascending order using the Bubble Sort algorithm. Implement the algorithm in C++ and ensure that the function stops early if the array becomes sorted before all passes are complete.

## Problem Solution
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

void bubble_sort(int new_array[], int n){
  int swapped = false;

  for(int i = 0; i < n-1; i++){

    for(int j = 0; j < n-i-1; j++){
      if(new_array[j] > new_array[j+1]){
        swap(new_array[j], new_array[j+1]);
        swapped = true;
      }
    }

    if(!swapped){
      break;
    }
  }

}

int main() {
  int new_array[6] = {10, 1, 7, 6, 14, 9};
  bubble_sort(new_array, 6);

  for(int i = 0; i < 6; i++){
    cout<<new_array[i] << " ";
  }
  return 0;
}
```

## Problem Solution Explanation
Let's go through the code line by line, explaining each part with examples.

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
```
- **`#include <iostream>`:** This line includes the standard input-output stream library, which allows the use of `cin` and `cout` for input and output operations.
- **`#include <algorithm>`:** This library includes a variety of useful algorithms, including the `swap` function used in this code.
- **`using namespace std;`**: This line tells the compiler to use the standard namespace, so you don't have to prefix `std::` before standard functions like `cout`.

### Function: `bubble_sort(int new_array[], int n)`

```cpp
void bubble_sort(int new_array[], int n){
  int swapped = false;
```
- **`void bubble_sort(int new_array[], int n)`**: This defines a function named `bubble_sort` that takes two arguments:
  - `new_array[]`: An array of integers that needs to be sorted.
  - `n`: The size of the array, i.e., the number of elements.
- **`int swapped = false;`**: This initializes a variable `swapped` to `false` (0). It will be used to track whether any elements were swapped during a pass through the array.

### Outer Loop: `for(int i = 0; i < n-1; i++)`

```cpp
  for(int i = 0; i < n-1; i++){
```
- This loop runs from `i = 0` to `i = n-2` (total of `n-1` times). Each iteration of this loop represents a single pass through the array to push the largest unsorted element to its correct position.
- **Example**: For an array of size 6 (`n = 6`), this loop will iterate 5 times (`i = 0` to `i = 4`).

### Inner Loop: `for(int j = 0; j < n-i-1; j++)`

```cpp
    for(int j = 0; j < n-i-1; j++){
```
- This loop compares adjacent elements in the array. It runs `n-i-1` times in each pass because, after each pass, the largest element in the unsorted portion is placed at the correct position.
- **Example**: On the first pass (`i = 0`), `j` will iterate from 0 to 4, comparing and possibly swapping elements at positions 0 and 1, 1 and 2, 2 and 3, etc.

### Condition: `if(new_array[j] > new_array[j+1])`

```cpp
      if(new_array[j] > new_array[j+1]){
        swap(new_array[j], new_array[j+1]);
        swapped = true;
```
- **`if(new_array[j] > new_array[j+1])`:** This checks if the current element (`new_array[j]`) is greater than the next element (`new_array[j+1]`). If it is, it means these two elements are out of order and need to be swapped.
- **`swap(new_array[j], new_array[j+1]);`**: This swaps the elements at positions `j` and `j+1`.
  - **Example**: If `new_array[j] = 10` and `new_array[j+1] = 1`, after the swap, `new_array[j]` will be `1`, and `new_array[j+1]` will be `10`.
- **`swapped = true;`**: This sets `swapped` to `true`, indicating that a swap occurred during this pass.

### Early Exit: `if(!swapped)`

```cpp
    if(!swapped){
      break;
    }
  }
}
```
- **`if(!swapped)`**: After the inner loop completes, the code checks if `swapped` is still `false`. If it is, this means no swaps were made during the pass, indicating that the array is already sorted.
- **`break;`**: If the array is already sorted, the loop breaks early, avoiding unnecessary comparisons in future passes.

### Main Function: `int main()`

```cpp
int main() {
  int new_array[6] = {10, 1, 7, 6, 14, 9};
```
- **`int main()`**: This is the main function where the program execution starts.
- **`int new_array[6] = {10, 1, 7, 6, 14, 9};`**: This declares an array `new_array` with 6 elements: `10, 1, 7, 6, 14, 9`.

### Sorting the Array

```cpp
  bubble_sort(new_array, 6);
```
- **`bubble_sort(new_array, 6);`**: This calls the `bubble_sort` function, passing the array `new_array` and its size (6) as arguments. The array will be sorted in ascending order.

### Printing the Sorted Array

```cpp
  for(int i = 0; i < 6; i++){
    cout<<new_array[i] << " ";
  }
  return 0;
}
```
- **`for(int i = 0; i < 6; i++)`**: This loop iterates over the sorted array and prints each element.
- **`cout << new_array[i] << " ";`**: This prints the `i`-th element of the sorted array followed by a space.
- **`return 0;`**: This ends the main function, returning 0 to indicate successful execution.

### Example Execution

Let's go through the sorting process with the given array `{10, 1, 7, 6, 14, 9}`:

- **Initial Array**: `[10, 1, 7, 6, 14, 9]`
- **Pass 1 (i = 0)**:
  - Compare 10 and 1 → Swap → `[1, 10, 7, 6, 14, 9]`
  - Compare 10 and 7 → Swap → `[1, 7, 10, 6, 14, 9]`
  - Compare 10 and 6 → Swap → `[1, 7, 6, 10, 14, 9]`
  - Compare 10 and 14 → No swap
  - Compare 14 and 9 → Swap → `[1, 7, 6, 10, 9, 14]`
- **Pass 2 (i = 1)**:
  - Compare 1 and 7 → No swap
  - Compare 7 and 6 → Swap → `[1, 6, 7, 10, 9, 14]`
  - Compare 7 and 10 → No swap
  - Compare 10 and 9 → Swap → `[1, 6, 7, 9, 10, 14]`
  - Compare 10 and 14 → No swap
- **Pass 3 (i = 2)**:
  - Compare 1 and 6 → No swap
  - Compare 6 and 7 → No swap
  - Compare 7 and 9 → No swap
  - Compare 9 and 10 → No swap

Since no swaps occurred in Pass 3, the array is already sorted, and the algorithm terminates early.

- **Final Sorted Array**: `[1, 6, 7, 9, 10, 14]`

### Summary
This code sorts an array of integers in ascending order using the Bubble Sort algorithm. The algorithm repeatedly compares adjacent elements and swaps them if they are in the wrong order, with an optimization to stop early if the array becomes sorted before completing all passes. The sorted array is then printed to the console.

### Time Complexity

#### Worst-Case Time Complexity: **O(n²)**
- **Explanation**: In the worst case, the array is in reverse order, so the algorithm needs to perform the maximum number of swaps and comparisons. For each of the `n-1` passes, the algorithm performs up to `n-i-1` comparisons (where `i` is the current pass index). This results in a total of approximately `n * (n-1)/2` comparisons, which simplifies to O(n²).

#### Average-Case Time Complexity: **O(n²)**
- **Explanation**: On average, the bubble sort algorithm still needs to make about half the total possible comparisons and swaps. This results in the same O(n²) complexity as in the worst case.

#### Best-Case Time Complexity: **O(n)**
- **Explanation**: If the array is already sorted, the `swapped` flag remains `false`, and the algorithm breaks out of the loop after the first pass. Thus, only `n-1` comparisons are made, resulting in a best-case time complexity of O(n).

### Space Complexity

#### Space Complexity: **O(1)**
- **Explanation**: Bubble Sort is an in-place sorting algorithm, meaning it doesn't require any extra space other than a few variables (like `i`, `j`, and `swapped`). Therefore, the space complexity is constant, or O(1).

### Summary of Complexities

- **Worst-Case Time Complexity**: O(n²)
- **Average-Case Time Complexity**: O(n²)
- **Best-Case Time Complexity**: O(n)
- **Space Complexity**: O(1)
