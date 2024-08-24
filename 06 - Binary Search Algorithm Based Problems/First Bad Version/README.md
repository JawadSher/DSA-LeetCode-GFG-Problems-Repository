<h1 align='center'>First - Bad - Version</h1>

## Problem Statement

**Problem URL :** [First Bad Version](https://leetcode.com/problems/first-bad-version/)

![image](https://github.com/user-attachments/assets/f2aef13b-7c25-45d4-8ef0-7a48dae0a306)

## Problem Solution
```cpp
// The API isBadVersion is defined for you.
bool isBadVersion(int n, int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1;
        int end = n;

        while(start < end){
            int mid = start + (end - start)/2;

            if(isBadVersion(mid)){
                end = mid;
            }else{
                start = mid + 1;
            }
        }

        return start;
    }

};
```

## Problem Solution Explanation

let’s break down the `firstBadVersion` function in detail, explaining each line and example, and discussing the complexities involved.

```cpp
// The API isBadVersion is defined for you.
bool isBadVersion(int n, int version);
```
- This line is a declaration for the `isBadVersion` function, which is provided by the problem. It determines whether a given version is bad or not.

```cpp
class Solution {
public:
    int firstBadVersion(int n) {
```
- This line starts the definition of the `Solution` class and the `firstBadVersion` method, which aims to find the first bad version among `n` versions.

```cpp
        int start = 1;
        int end = n;
```
- **Initialization**:
  - `start` is initialized to `1`, assuming version indexing starts from `1`.
  - `end` is initialized to `n`, which is the total number of versions.

```cpp
        while(start < end){
```
- **Binary Search Loop**:
  - This loop runs while `start` is less than `end`. The loop will help in narrowing down the range to find the first bad version.

```cpp
            int mid = start + (end - start) / 2;
```
- **Calculate Midpoint**:
  - `mid` is calculated as the average of `start` and `end` using `mid = start + (end - start) / 2`. This prevents overflow that could occur if `start` and `end` are very large.

```cpp
            if(isBadVersion(mid)){
                end = mid;
            }else{
                start = mid + 1;
            }
```
- **Check if `mid` is Bad**:
  - `isBadVersion(mid)` checks if the version `mid` is bad.
  - If `mid` is a bad version, it means the first bad version could be `mid` or any version to the left of `mid`. Therefore, `end` is updated to `mid` to continue searching in the left half (including `mid`).
  - If `mid` is not a bad version, then the first bad version must be to the right of `mid`. Therefore, `start` is updated to `mid + 1` to search in the right half.

```cpp
        }

        return start;
    }
};
```
- **Loop Termination and Result**:
  - The loop terminates when `start` equals `end`. At this point, both `start` and `end` point to the first bad version, so `start` is returned as the result.

### Example Walkthrough

#### Example 1: Target Bad Version is Present

Assume `n = 5` and the first bad version is `4`.

**Process:**
1. **Initial State**:
   - `start = 1`, `end = 5`.

2. **First Iteration**:
   - `mid = 1 + (5 - 1) / 2 = 3`.
   - `isBadVersion(3)` returns `false` (not bad).
   - `start` is updated to `mid + 1 = 4`.

3. **Second Iteration**:
   - `mid = 4 + (5 - 4) / 2 = 4`.
   - `isBadVersion(4)` returns `true` (bad).
   - `end` is updated to `mid = 4`.

4. **Termination**:
   - `start` equals `end` (`4`), so the loop ends.

**Result**: `start = 4`, which is the first bad version.

#### Example 2: No Bad Version

Assume `n = 5` and there are no bad versions.

**Process:**
1. **Initial State**:
   - `start = 1`, `end = 5`.

2. **First Iteration**:
   - `mid = 1 + (5 - 1) / 2 = 3`.
   - `isBadVersion(3)` returns `false` (not bad).
   - `start` is updated to `mid + 1 = 4`.

3. **Second Iteration**:
   - `mid = 4 + (5 - 4) / 2 = 4`.
   - `isBadVersion(4)` returns `false` (not bad).
   - `start` is updated to `mid + 1 = 5`.

4. **Termination**:
   - `start` equals `end` (`5`), so the loop ends.

**Result**: `start = 5`. Since there are no bad versions, this result would indicate the position beyond the last version.

### Complexity Analysis

**Time Complexity**:
- The binary search approach has a time complexity of **O(log n)** because the search space is halved with each iteration of the loop.

**Space Complexity**:
- The space complexity is **O(1)** because the function uses only a constant amount of extra space (for `start`, `end`, and `mid`).

### Summary

- The `firstBadVersion` function uses binary search to efficiently find the first bad version by repeatedly narrowing the search range based on whether the midpoint version is bad.
- The approach ensures logarithmic time complexity, making it suitable for large inputs.
