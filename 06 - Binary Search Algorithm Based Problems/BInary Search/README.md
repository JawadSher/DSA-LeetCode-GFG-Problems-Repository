<h1 align='center'>Binary - Search</h1>

## Problem Statement

**Problem URL :** [Binary Search](https://leetcode.com/problems/binary-search/)

![image](https://github.com/user-attachments/assets/f1fe91b1-8885-4503-ba08-d34ea92372d6)

## Problem Solution
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int start = 0;
        int end = n-1;

        while(start <= end){
            int mid = start + (end - start)/2;

            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }

        return -1;
    }
};
```

## Problem Solution Explanation
Let's go through the binary search code line by line with detailed explanations for each part.

```cpp
class Solution {
public:
```
- This line defines the start of a class named `Solution`. In C++, classes are used to encapsulate data and functions. Here, the class `Solution` will contain the method `search`.

```cpp
    int search(vector<int>& nums, int target) {
```
- This line defines a public member function named `search` that returns an integer (`int`).
- The function takes two parameters:
  1. `vector<int>& nums`: A reference to a vector of integers (the array in which we want to search).
  2. `int target`: The integer value we want to find in the vector.

```cpp
        int n = nums.size();
```
- This line declares an integer variable `n` and initializes it with the size of the vector `nums`.
- `nums.size()` returns the number of elements in the vector `nums`.

```cpp
        int start = 0;
        int end = n - 1;
```
- These two lines declare and initialize two integer variables:
  1. `start = 0`: The starting index of the search range, initially set to the first element of the array.
  2. `end = n - 1`: The ending index of the search range, initially set to the last element of the array (`n-1` since arrays are zero-indexed).

```cpp
        while (start <= end) {
```
- This line starts a `while` loop that continues as long as `start` is less than or equal to `end`.
- The loop ensures that we search within a valid range. If `start` becomes greater than `end`, it means the target is not present in the array, and the loop will terminate.

```cpp
            int mid = start + (end - start) / 2;
```
- This line calculates the middle index (`mid`) of the current search range.
- `(end - start) / 2` finds the distance from `start` to the middle of the range, and adding `start` gives the actual middle index.
- The formula `start + (end - start) / 2` is used instead of `(start + end) / 2` to avoid potential overflow when `start` and `end` are large.

```cpp
            if (nums[mid] == target) {
                return mid;
```
- This line checks if the element at the middle index (`nums[mid]`) is equal to the target value.
- If they are equal, it means the target is found, and the function returns the index `mid` where the target is located.

```cpp
            } else if (nums[mid] > target) {
                end = mid - 1;
```
- If the middle element is greater than the target (`nums[mid] > target`), it means the target, if it exists, must be in the left half of the array.
- The line `end = mid - 1;` updates the `end` index to `mid - 1`, narrowing the search range to the left half of the current range.

```cpp
            } else {
                start = mid + 1;
```
- If the middle element is less than the target (`nums[mid] < target`), it means the target, if it exists, must be in the right half of the array.
- The line `start = mid + 1;` updates the `start` index to `mid + 1`, narrowing the search range to the right half of the current range.

```cpp
            }
        }
```
- These closing braces mark the end of the `if-else` block and the `while` loop. If the loop completes without finding the target, it means the target is not in the array.

```cpp
        return -1;
```
- This line is executed if the `while` loop exits without finding the target.
- It returns `-1` to indicate that the target value is not present in the array.

```cpp
    }
};
```
- These closing braces mark the end of the `search` function and the `Solution` class.

### Summary:

1. **Initialization**:
   - The function starts by initializing the search range (`start` to `end`).
   - It then enters a loop that repeatedly narrows the search range by comparing the target with the middle element of the current range.

2. **Midpoint Calculation**:
   - The middle index is calculated using a formula that avoids overflow.

3. **Comparison**:
   - If the middle element equals the target, the function immediately returns the middle index.
   - If the middle element is greater than the target, the search range is adjusted to exclude the right half.
   - If the middle element is less than the target, the search range is adjusted to exclude the left half.

4. **Loop Termination**:
   - The loop continues until the search range is exhausted.
   - If the target is not found, `-1` is returned.

This line-by-line explanation should help you understand how the binary search algorithm is implemented in the given code.
