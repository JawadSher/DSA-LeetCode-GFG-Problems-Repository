<h1 align='center'>Move - Zeros</h1>

## Problem Statement

**Problem URL :** [Move Zeros](https://leetcode.com/problems/move-zeroes/)

![image](https://github.com/user-attachments/assets/5983d1f1-95f9-4abb-8b41-0ac4bb3b16d6)

## Problem Explanation

Given an integer array `nums`, the task is to move all the `0` elements to the end of the array while maintaining the relative order of the non-zero elements. This must be done in-place, without using extra space for another array.

## Problem Solution
```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] != 0){
                swap(nums[j], nums[i]);
                i++;
            }
        }
    }
};
```

## Problem Solution Explanation
Let's walk through this `moveZeroes` function step by step and explain the approach with an example.

#### 1. Initialization

```cpp
int i = 0;
```

- **`int i = 0;`**:
  - This variable `i` keeps track of the position where the next non-zero element should be moved. It starts at `0`, which is the beginning of the array.

#### 2. Iterating Through the Array

```cpp
for(int j = 0; j < nums.size(); j++){
```

- **`for(int j = 0; j < nums.size(); j++)`**:
  - This loop iterates over each element in the `nums` array using the index `j`.
  - `j` goes from `0` to `nums.size() - 1`.

#### 3. Checking for Non-Zero Elements and Swapping

```cpp
if(nums[j] != 0){
    swap(nums[j], nums[i]);
    i++;
}
```

- **`if(nums[j] != 0)`**:
  - This condition checks if the current element at index `j` is non-zero.
  
- **`swap(nums[j], nums[i]);`**:
  - If the element is non-zero, it is swapped with the element at index `i`.
  - This ensures that the non-zero element is moved to the front of the array, at the position indicated by `i`.
  
- **`i++;`**:
  - After the swap, `i` is incremented to point to the next position where a non-zero element should be placed.

### Example Walkthrough

Let's go through an example to see how this works in practice.

**Input**: `nums = [0, 1, 0, 3, 12]`

**Process**:
1. **Initial State**:
   - `nums = [0, 1, 0, 3, 12]`
   - `i = 0`
   - `j = 0`

2. **First Iteration (j = 0)**:
   - `nums[0]` is `0`, so nothing happens.
   - Array remains `[0, 1, 0, 3, 12]`.
   - `i` remains `0`.

3. **Second Iteration (j = 1)**:
   - `nums[1]` is `1`, which is non-zero.
   - Swap `nums[1]` with `nums[0]`.
   - Array becomes `[1, 0, 0, 3, 12]`.
   - Increment `i` to `1`.

4. **Third Iteration (j = 2)**:
   - `nums[2]` is `0`, so nothing happens.
   - Array remains `[1, 0, 0, 3, 12]`.
   - `i` remains `1`.

5. **Fourth Iteration (j = 3)**:
   - `nums[3]` is `3`, which is non-zero.
   - Swap `nums[3]` with `nums[1]`.
   - Array becomes `[1, 3, 0, 0, 12]`.
   - Increment `i` to `2`.

6. **Fifth Iteration (j = 4)**:
   - `nums[4]` is `12`, which is non-zero.
   - Swap `nums[4]` with `nums[2]`.
   - Array becomes `[1, 3, 12, 0, 0]`.
   - Increment `i` to `3`.

**Final State**:
- The final array is `[1, 3, 12, 0, 0]`.
- All non-zero elements have been moved to the front, and all zeros are at the end.

### Approach Explanation

- **Two-Pointer Technique**:
  - The solution uses two pointers, `i` and `j`. 
  - `i` tracks the position to place the next non-zero element, and `j` iterates over the entire array to find non-zero elements.
  
- **In-Place Swap**:
  - The `swap` operation efficiently moves non-zero elements to the correct position without needing extra space, achieving the goal in O(n) time with O(1) space complexity.

- **Preserving Order**:
  - Since the non-zero elements are swapped into their new positions in the order they are found, the relative order of non-zero elements remains the same as in the original array.

This method is optimal and maintains the original order of non-zero elements while effectively moving all zeros to the end of the array.
