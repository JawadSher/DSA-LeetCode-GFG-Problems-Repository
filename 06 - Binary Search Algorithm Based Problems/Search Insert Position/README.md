<h1 align='center'>Search - Insert - Position</h1>

## Problem Statement

**Problem URL :** [Search Insert Position](https://leetcode.com/problems/search-insert-position/)

![image](https://github.com/user-attachments/assets/e5db1a90-8b23-4989-b654-d6d604159163)

## Problem Solution
```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        int start = 0;
        int end = n-1;
        
        while(start <= end){
            int mid = start + (end - start)/2;

            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }

        return (lower_bound(nums.begin(), nums.end(), target) - nums.begin());
    }
};
```

## Problem Solution Explanation
Let's go through the `searchInsert` function line by line, explain each part in detail, and discuss the complexities involved.


The function `searchInsert` is designed to find the index of the `target` in a sorted array `nums`. If the `target` is not found, it returns the index where the `target` should be inserted to maintain the sorted order.

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
```
- This line defines the `Solution` class with a public member function `searchInsert` that takes a reference to a vector of integers (`nums`) and an integer (`target`).
- The function returns an integer representing the index where `target` is found or where it should be inserted.

```cpp
        int n = nums.size();
```
- This line declares an integer `n` and initializes it with the size of the vector `nums`.
- Complexity: This operation takes **O(1)** time since it's simply accessing the size of the vector.

```cpp
        int start = 0;
        int end = n - 1;
```
- Here, two integers `start` and `end` are initialized to represent the start and end indices of the search range, respectively.
- `start` is initialized to `0` (the first index), and `end` is initialized to `n - 1` (the last index).
- Complexity: **O(1)**

```cpp
        while (start <= end) {
```
- This `while` loop will continue as long as `start` is less than or equal to `end`.
- The loop condition ensures that the search continues until the target is either found or the search range is exhausted.

```cpp
            int mid = start + (end - start) / 2;
```
- This line calculates the middle index `mid` of the current search range.
- The formula avoids potential overflow by computing the middle index in a safe manner.
- Complexity: **O(1)**

```cpp
            if (nums[mid] == target) {
                return mid;
            }
```
- The code checks if the middle element (`nums[mid]`) is equal to the `target`.
- If it is, the function immediately returns the `mid` index, as the target is found at this position.
- Complexity: **O(1)** (for the comparison and return)

```cpp
            else if (nums[mid] < target) {
                start = mid + 1;
            }
```
- If `nums[mid]` is less than the target, it means the target must be in the right half of the current search range.
- Therefore, `start` is updated to `mid + 1`, effectively discarding the left half and narrowing the search to the right half.
- Complexity: **O(1)**

```cpp
            else {
                end = mid - 1;
            }
```
- If `nums[mid]` is greater than the target, it means the target must be in the left half of the current search range.
- Therefore, `end` is updated to `mid - 1`, effectively discarding the right half and narrowing the search to the left half.
- Complexity: **O(1)**

```cpp
        }
```
- This closing brace marks the end of the `while` loop.
- The loop continues until `start` exceeds `end`, which means the target is not found in the array.

```cpp
        return (lower_bound(nums.begin(), nums.end(), target) - nums.begin());
```
- If the target is not found within the `while` loop, this line is executed.
- **`lower_bound(nums.begin(), nums.end(), target)`**:
  - This function returns an iterator pointing to the first element in `nums` that is not less than the target.
  - It finds the position where the target should be inserted to maintain the sorted order.
- **Subtracting `nums.begin()`**:
  - The result of `lower_bound` is an iterator. By subtracting `nums.begin()` from this iterator, we convert it to an index.
- The index returned is where the target should be inserted if it doesn't already exist in the vector.
- Complexity: **O(log n)**, as `lower_bound` internally uses a binary search algorithm.

```cpp
    }
};
```
- These closing braces mark the end of the `searchInsert` function and the `Solution` class.

### Examples

Let's walk through a couple of examples:

#### Example 1: Target Exists in `nums`
```cpp
vector<int> nums = {1, 3, 5, 6};
int target = 5;
int result = searchInsert(nums, target);
```

**Process:**
- The `while` loop starts with `start = 0` and `end = 3`.
- `mid` is calculated as `1`, `nums[mid] = 3`.
- Since `3 < 5`, `start` is updated to `2`.
- `mid` is recalculated as `2`, `nums[mid] = 5`.
- `nums[mid] == target`, so `mid = 2` is returned.

**Result:** `result = 2`

#### Example 2: Target Does Not Exist in `nums`
```cpp
vector<int> nums = {1, 3, 5, 6};
int target = 2;
int result = searchInsert(nums, target);
```

**Process:**
- The `while` loop starts with `start = 0` and `end = 3`.
- `mid` is calculated as `1`, `nums[mid] = 3`.
- Since `3 > 2`, `end` is updated to `0`.
- `mid` is recalculated as `0`, `nums[mid] = 1`.
- Since `1 < 2`, `start` is updated to `1`.
- Now `start > end`, so the loop exits.
- `lower_bound` is called and finds that `2` should be inserted at index `1`.

**Result:** `result = 1`

### Time Complexity

1. **Binary Search (`while` loop)**: The loop runs in **O(log n)** time because each iteration halves the search range.
2. **Lower Bound Calculation**: The `lower_bound` function also runs in **O(log n)** time.
3. **Overall Time Complexity**: **O(log n)**, because the dominant operations (binary search and `lower_bound`) both run in logarithmic time.

### Space Complexity

- The space complexity of this function is **O(1)** because only a constant amount of extra space is used, regardless of the input size. All variables (`start`, `end`, `mid`, `n`, etc.) occupy a fixed amount of space.

This detailed explanation should give you a clear understanding of how the `searchInsert` function works, with specific examples and a breakdown of the time and space complexities involved.
