<h1 align='center'>Merge - Sorted - Array</h1>

## Problem Statement

**Problem URL :** [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)

![image](https://github.com/user-attachments/assets/a67537a7-d24c-40db-a834-7966d0d94ad4)
![image](https://github.com/user-attachments/assets/454c5581-8fa7-4d2b-a1af-7796352f408a)

## Problem Explanation

You have two sorted integer arrays, `nums1` and `nums2`, and two integers `m` and `n`. The array `nums1` has a size of `m + n`, where the first `m` elements are the elements of `nums1`, and the last `n` elements are set to `0` (these are placeholders and do not count as part of the array). The array `nums2` has `n` elements. The task is to merge `nums2` into `nums1` such that `nums1` becomes a sorted array.


## Problem Solution
```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastnonZeroIndex = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                nums[lastnonZeroIndex++] = nums[i];
            }
        }

        for(int i = lastnonZeroIndex; i < nums.size(); i++){
            nums[i] = 0;
        }
    }
};
```

## Problem Solution Explanation
This solution effectively merges two sorted arrays, `nums1` and `nums2`, into one sorted array, stored in `nums1`. The approach used is efficient and works in-place, meaning it doesn't require extra space beyond the given input arrays.

Let's break down the solution line by line and explain how it works.

```cpp
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;   // Point to the last element in the initial portion of nums1
    int j = n - 1;   // Point to the last element in nums2
    int k = m + n - 1;  // Point to the last position in nums1 (end of the array)
```

- **`int i = m - 1;`**:
  - `i` is initialized to `m - 1`, which is the index of the last valid element in the initial part of `nums1`. For example, if `m = 3` and `nums1 = [1, 2, 3, 0, 0, 0]`, then `i = 2`, pointing to the element `3`.
  
- **`int j = n - 1;`**:
  - `j` is initialized to `n - 1`, which is the index of the last element in `nums2`. For example, if `n = 3` and `nums2 = [2, 5, 6]`, then `j = 2`, pointing to the element `6`.

- **`int k = m + n - 1;`**:
  - `k` is initialized to `m + n - 1`, which is the last index of the combined array (`nums1` after merging). For example, with `m = 3` and `n = 3`, `k = 5`, which is the index of the last `0` in `nums1 = [1, 2, 3, 0, 0, 0]`.

### Main Merging Logic

```cpp
    while(i >= 0 && j >= 0){
        if(nums1[i] > nums2[j]){
            nums1[k--] = nums1[i--];
        }else{
            nums1[k--] = nums2[j--];
        }
    }
```

- **`while(i >= 0 && j >= 0)`**:
  - This loop runs as long as there are elements left in both `nums1` and `nums2` that need to be compared and merged.

- **`if(nums1[i] > nums2[j])`**:
  - Compare the current element pointed to by `i` in `nums1` with the current element pointed to by `j` in `nums2`. If `nums1[i] > nums2[j]`, place `nums1[i]` at the `k` position in `nums1`, then decrement both `i` and `k`. This ensures that the largest of the two elements is placed at the end of `nums1`.

  - **Example**:
    - Suppose `nums1 = [1, 3, 5, 0, 0, 0]`, `nums2 = [2, 4, 6]`, and `i = 2`, `j = 2`, `k = 5`.
    - Compare `nums1[2] = 5` with `nums2[2] = 6`. Since `6 > 5`, place `6` in `nums1[5]`, so now `nums1 = [1, 3, 5, 0, 0, 6]`. Then decrement `j` and `k`.

- **`else`**:
  - If `nums2[j] >= nums1[i]`, place `nums2[j]` at the `k` position in `nums1`, then decrement both `j` and `k`.

  - **Example**:
    - Continuing from the previous example, after placing `6` in `nums1[5]`, now `k = 4` and `j = 1`.
    - Compare `nums1[2] = 5` with `nums2[1] = 4`. Since `5 > 4`, place `5` in `nums1[4]`, so now `nums1 = [1, 3, 5, 0, 5, 6]`.

### Handle Remaining Elements in `nums2`

```cpp
    while(j >= 0){
        nums1[k--] = nums2[j--];
    }
```

- **`while(j >= 0)`**:
  - After the main loop, if there are still elements left in `nums2`, they must be smaller than all elements in `nums1` already processed, so they can be directly copied to the beginning of `nums1`.

  - **Example**:
    - After processing all elements as above, suppose `nums1 = [1, 3, 5, 0, 5, 6]`, and `j = 0` pointing to `2` in `nums2`.
    - Since `2` is smaller than all other elements, place it in `nums1[3]`, so the final `nums1` becomes `[1, 2, 3, 4, 5, 6]`.

### Final Example Walkthrough

- **Input**:
  - `nums1 = [1, 2, 3, 0, 0, 0]`, `m = 3`
  - `nums2 = [2, 5, 6]`, `n = 3`

- **Process**:
  - Compare `3` and `6`: Place `6` in `nums1[5]`
  - Compare `3` and `5`: Place `5` in `nums1[4]`
  - Compare `3` and `2`: Place `3` in `nums1[3]`
  - Place the remaining `2` and `2` in `nums1[2]` and `nums1[1]`.

- **Output**:
  - `nums1` becomes `[1, 2, 2, 3, 5, 6]`.

### Conclusion

This solution efficiently solves the "merge sorted array" problem by starting the merge from the end of `nums1`, which allows it to place the largest elements first and avoid overwriting elements in `nums1` before they've been compared. The approach uses only O(1) additional space and runs in O(m + n) time, making it optimal for this problem.
