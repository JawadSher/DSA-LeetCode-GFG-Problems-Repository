<h1 align='center'>Insertion - Sort - Algorithm - Example</h1>

## Problem Statement
The goal is to sort an array of integers in non-decreasing order using the **Insertion Sort** algorithm. This sorting algorithm is straightforward, works similarly to the way you might sort playing cards, and is particularly effective for small datasets or nearly sorted data.

### Insertion Sort Algorithm

**Insertion Sort** is a simple and efficient comparison-based sorting algorithm. It works similarly to how you might sort playing cards in your hands: you start with one card and insert each new card into its correct position in the already sorted portion of the hand.

The key idea behind **insertion sort** is to maintain a "sorted" portion of the list while inserting new elements one by one into the correct position within that sorted portion.

### Steps of the Insertion Sort Algorithm:

1. **Start with the second element** (index 1) of the list, considering the first element as a sorted portion.
2. **Compare the current element** (key) with the elements in the sorted portion (on its left).
3. **Shift all larger elements** of the sorted portion one position to the right to make room for the key element.
4. **Insert the key element** into its correct position in the sorted portion.
5. **Move to the next element** and repeat the process until the entire list is sorted.

### Example:

Let’s sort the list `[5, 3, 8, 4, 2]` using Insertion Sort:

**Initial list**: `[5, 3, 8, 4, 2]`

- **Step 1**: Start with the second element, `3`.
  - Compare `3` with `5`. Since `3` is smaller than `5`, **shift `5` to the right** and insert `3` in the first position.
  - Updated list: `[3, 5, 8, 4, 2]`

- **Step 2**: Move to the next element, `8`.
  - Compare `8` with `5`. Since `8` is greater than `5`, no shifting is needed, and `8` remains in place.
  - Updated list: `[3, 5, 8, 4, 2]`

- **Step 3**: Move to the next element, `4`.
  - Compare `4` with `8`. Since `4` is smaller, **shift `8` to the right**.
  - Compare `4` with `5`. Since `4` is smaller, **shift `5` to the right**.
  - Insert `4` at the position of `5`.
  - Updated list: `[3, 4, 5, 8, 2]`

- **Step 4**: Move to the next element, `2`.
  - Compare `2` with `8`. Since `2` is smaller, **shift `8` to the right**.
  - Compare `2` with `5`. Since `2` is smaller, **shift `5` to the right**.
  - Compare `2` with `4`. Since `2` is smaller, **shift `4` to the right**.
  - Compare `2` with `3`. Since `2` is smaller, **shift `3` to the right**.
  - Insert `2` at the first position.
  - Updated list: `[2, 3, 4, 5, 8]`

Now the list is sorted: `[2, 3, 4, 5, 8]`.

### Characteristics of Insertion Sort:

- **Time Complexity**:
  - Worst-case: **O(n²)** (when the list is sorted in reverse order).
  - Best-case: **O(n)** (when the list is already sorted).
  - Average-case: **O(n²)**.

- **Space Complexity**: **O(1)** (in-place sorting, so no extra space is required).

- **Stable Sorting**: Yes, Insertion Sort is a stable sorting algorithm, meaning that equal elements retain their relative order.

- **Adaptive**: Insertion Sort is adaptive, meaning it performs well when the input is already partially sorted.

### Advantages:
- **Efficient for small datasets**: Insertion Sort is very efficient for small or nearly sorted datasets, where its time complexity is closer to **O(n)**.
- **Simple to implement**: The algorithm is easy to understand and implement.
- **Adaptive**: Performs well when the list is already partially sorted.
- **Stable**: Maintains the relative order of equal elements.

### Disadvantages:
- **Inefficient for large datasets**: Due to its **O(n²)** time complexity, it is inefficient on large datasets compared to other algorithms like Merge Sort or Quick Sort.
- **Slow for large unsorted data**: The algorithm requires a lot of shifts when the data is completely unsorted.

### Visualization:

For better understanding, you can visualize Insertion Sort as inserting a card from an unsorted deck into a hand that is already sorted, gradually growing the sorted portion from left to right.


## Problem Solution
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void insertion_sort(vector<int>& nums){
  for(int i = 1; i < nums.size(); i++){
    int key = nums[i];
    
    int j = i-1;
    for(; j >= 0; j--){
      if(nums[j] > key){
        nums[j+1] = nums[j];
      }else{
        break;
      }
    }
    nums[j+1] = key;
  }
}

int main() {
  vector<int> nums = {10, 2, 3, 8, 5, 1, 4, 7, 9, 6};
  insertion_sort(nums);

  for(int i : nums){
    cout<<i<<" ";
  }
  return 0;
}
```

## Problem Solution Explanation
Let's go through the `insertion_sort` function and `main` function line by line, explaining each part in detail.

### `insertion_sort` Function

```cpp
void insertion_sort(vector<int>& nums) {
```

- **Line 1:** 
  - This is the function declaration for `insertion_sort`.
  - `void` means the function does not return any value.
  - `vector<int>& nums` is a reference to a vector of integers passed to the function, meaning that the function will modify the original vector, not a copy of it.

```cpp
    for (int i = 1; i < nums.size(); i++) {
```

- **Line 2:**
  - This `for` loop starts with `i = 1` and iterates through the vector until `i` is less than the size of the vector (`nums.size()`).
  - The loop index `i` represents the current element that we are going to insert into the sorted portion of the array (which is the part of the array before `i`).

```cpp
        int key = nums[i];
```

- **Line 3:**
  - `key` stores the current element (`nums[i]`) that we want to insert into its correct position in the sorted portion of the array.
  - This is the element that will be compared against the elements in the sorted portion.

```cpp
        int j = i - 1;
```

- **Line 4:**
  - `j` is initialized to `i - 1`, meaning it starts at the last element in the sorted portion of the array.
  - The variable `j` will be used to compare the elements in the sorted portion against the `key`.

```cpp
        while (j >= 0 && nums[j] > key) {
```

- **Line 5:**
  - This `while` loop runs as long as `j` is non-negative (indicating there are elements to compare) and the current element in the sorted portion (`nums[j]`) is greater than the `key`.
  - If `nums[j] > key`, it means the current element is out of order, so it needs to be shifted to the right to make room for the `key`.

```cpp
            nums[j + 1] = nums[j];
```

- **Line 6:**
  - This line shifts the element at index `j` (`nums[j]`) one position to the right (`nums[j + 1]`).
  - This effectively makes space for the `key` by moving the larger element to the right.

```cpp
            j--;
```

- **Line 7:**
  - Decrement `j` by 1 to move to the next element on the left in the sorted portion of the array.
  - The loop continues to shift elements until we find the correct position for the `key` or reach the start of the array.

```cpp
        nums[j + 1] = key;
```

- **Line 8:**
  - After the `while` loop completes, `j` will be at the index where the `key` should be inserted.
  - `nums[j + 1] = key;` places the `key` in its correct position in the sorted portion of the array.

```cpp
    }
```

- **Line 9:**
  - This closes the `for` loop. The process is repeated for each element in the array until the entire array is sorted.

```cpp
}
```

- **Line 10:**
  - This closes the `insertion_sort` function.

### `main` Function

```cpp
int main() {
```

- **Line 1:**
  - This is the `main` function where the program execution begins.
  - The `int` indicates that the function will return an integer value (usually `0` for successful execution).

```cpp
    vector<int> nums = {10, 2, 3, 8, 5, 1, 4, 7, 9, 6};
```

- **Line 2:**
  - A vector of integers named `nums` is declared and initialized with the given list of integers.
  - This is the array we want to sort using the insertion sort algorithm.

```cpp
    insertion_sort(nums);
```

- **Line 3:**
  - The `insertion_sort` function is called with `nums` passed as an argument.
  - Since `nums` is passed by reference, the function will sort the original vector.

```cpp
    for (int i : nums) {
```

- **Line 4:**
  - This is a range-based `for` loop that iterates over each element in the sorted vector `nums`.
  - The loop variable `i` takes the value of each element in the vector one by one.

```cpp
        cout << i << " ";
```

- **Line 5:**
  - This line prints the current element (`i`) followed by a space.
  - This effectively prints the sorted array to the console.

```cpp
    }
```

- **Line 6:**
  - This closes the range-based `for` loop.

```cpp
    return 0;
```

- **Line 7:**
  - This returns `0` to indicate that the program has executed successfully.
  - The `main` function ends here.

```cpp
}
```

- **Line 8:**
  - This closes the `main` function.


### Time Complexity

1. **Best Case (O(n)):**
   - In the best-case scenario, the array is already sorted. 
   - The algorithm still iterates through the array, but since each element is already in its correct position, no shifting is required.
   - The inner `while` loop never executes, meaning the time complexity is linear, i.e., \( O(n) \).

2. **Average Case (O(n^2)):**
   - In the average case, the elements are in random order.
   - The number of comparisons and shifts required depends on how unsorted the array is.
   - On average, each element might be compared with half of the elements in the sorted portion, leading to a time complexity of \( O(n^2) \).

3. **Worst Case (O(n^2)):**
   - In the worst-case scenario, the array is sorted in reverse order.
   - The algorithm will need to compare each element with all previously sorted elements, shifting all of them to the right.
   - For example, the first element is compared 0 times, the second element is compared 1 time, and so on, leading to a quadratic time complexity, i.e., \( O(n^2) \).

### Space Complexity

1. **Space Complexity (O(1)):**
   - The algorithm sorts the array in place, meaning it doesn’t require any additional space proportional to the input size.
   - Only a constant amount of extra memory is used for variables like `key`, `i`, and `j`.
   - Therefore, the space complexity is \( O(1) \).

### Detailed Explanation:

- **Best Case:** \( O(n) \)
  - The array is already sorted. The algorithm just loops through the array with minimal operations, resulting in linear time complexity.

- **Average Case:** \( O(n^2) \)
  - The array is in random order. On average, each element needs to be compared and shifted with half of the previously sorted elements, leading to quadratic time complexity.

- **Worst Case:** \( O(n^2) \)
  - The array is sorted in reverse order. Every new element will need to be compared with all previous elements, making it the worst-case scenario with quadratic time complexity.

- **Space Complexity:** \( O(1) \)
  - Since the algorithm only requires a constant amount of additional space (no extra data structures), the space complexity is constant.

### Summary:

- **Insertion Sort** is efficient for small or nearly sorted arrays due to its simple implementation and good performance in the best case.
- However, it becomes inefficient for large, randomly ordered, or reverse-ordered arrays due to its \( O(n^2) \) time complexity in the average and worst cases.
- The algorithm is in-place and requires only \( O(1) \) extra space.
