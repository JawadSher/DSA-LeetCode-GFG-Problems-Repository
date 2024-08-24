<h1 align='center'>Minimum - Operations - to - Exceed - Threshold - Value I</h1>

## Problem Statement

**Problem URL :** [Minimum Operations to Exceed Threshold Value I](https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-i/)

![image](https://github.com/user-attachments/assets/2dd7289c-b406-4580-aa27-e58da2da3f4b)
![image](https://github.com/user-attachments/assets/97f6aefe-4196-4f65-bdc0-01a283423634)

## Problem Solution
```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int index = lower_bound(nums.begin(), nums.end(), k) - nums.begin();
        
        if(index > -1){
            return index;
        }

        return -1;
    }
};
```

## Problem Solution Explanation

#### 1. `sort(nums.begin(), nums.end());`

**Explanation**: 
- This line sorts the `nums` vector in non-decreasing order. The `sort` function uses a hybrid sorting algorithm (typically introsort), which combines quicksort, heapsort, and insertion sort.
  
**Time Complexity**: 
- **Sorting**: \( O(n \log n) \), where \( n \) is the number of elements in the `nums` vector.

**Example**:
- Before sorting: `nums = [5, 2, 7, 1, 3]`
- After sorting: `nums = [1, 2, 3, 5, 7]`

#### 2. `int index = lower_bound(nums.begin(), nums.end(), k) - nums.begin();`

**Explanation**:
- `lower_bound(nums.begin(), nums.end(), k)` finds the first position in the sorted `nums` where the value is not less than `k`. This is done using binary search, which is efficient for sorted data.
- The result of `lower_bound` is an iterator pointing to the element `k` (or the next larger element if `k` is not present).
- Subtracting `nums.begin()` from this iterator gives the zero-based index of the position in the vector.

**Time Complexity**:
- **Finding Lower Bound**: \( O(\log n) \), where \( n \) is the number of elements in the vector.

**Example**:
- For `nums = [1, 2, 3, 5, 7]` and `k = 4`, `lower_bound` returns an iterator pointing to 5 (index 3).
- `index = 3`.

#### 3. `if (index > -1) { return index; }`

**Explanation**:
- This line checks if the `index` is greater than -1. In this context, `index` from `lower_bound` is always valid and non-negative (as it represents a position in the vector). Thus, this condition will always be true if the vector is non-empty and the `lower_bound` operation was successful.

**Time Complexity**:
- **Condition Check**: \( O(1) \), a constant-time operation.

**Example**:
- Given `index = 3`, the condition `index > -1` evaluates to true, so it will return `3`.

#### 4. `return -1;`

**Explanation**:
- This line returns -1 if the `index` were not valid. However, due to the logic of `lower_bound` and the assumption that the vector has elements, this line will not be reached. The return value of -1 is thus more of a fallback and does not impact the final result in this implementation.

**Time Complexity**:
- **Return Operation**: \( O(1) \), a constant-time operation.

**Example**:
- This line will not be executed in practical scenarios because `index > -1` will always be true.

### Summary of Time Complexities

1. **Sorting**: \( O(n \log n) \)
2. **Finding Lower Bound**: \( O(\log n) \)
3. **Condition Check and Return**: \( O(1) \)

**Overall Time Complexity**: The dominant term is \( O(n \log n) \) due to the sorting step, making the overall complexity of the function \( O(n \log n) \).
