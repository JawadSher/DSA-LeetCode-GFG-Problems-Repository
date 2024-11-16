<h1 align='center'>Maximum - Subarray</h1>

## Problem Statement

**Problem URL :** [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)
![image](https://github.com/user-attachments/assets/5f511b8b-6dbe-4817-ab83-210e59ad4a73)

## Problem Explanation
The problem asks to find the contiguous subarray (containing at least one number) within a given array of integers `nums` that has the largest sum.

- **Input**: An integer array `nums`.
- **Output**: The maximum sum of a subarray.

#### **Example 1**:
For the array `[-2, 1, -3, 4, -1, 2, 1, -5, 4]`:
- The contiguous subarray `[4, -1, 2, 1]` has the largest sum, which is `6`.

#### **Example 2**:
For the array `[1]`:
- The only element is `1`, so the largest subarray sum is `1`.

#### **Approach**:

To solve this problem efficiently, we use **Kadane's Algorithm**, which allows us to find the maximum sum of a subarray in linear time, \(O(n)\), where \(n\) is the number of elements in the array.

**Kadane's Algorithm Idea**:
1. We traverse through the array while maintaining two variables:
   - `sum`: This tracks the sum of the current subarray. It is updated as we move through the array.
   - `maxi`: This stores the maximum sum encountered so far.

2. At each step:
   - Add the current element to `sum`.
   - If the sum exceeds `maxi`, update `maxi`.
   - If `sum` becomes negative, reset `sum` to 0 (because continuing with a negative sum would reduce the overall result).

#### **Why Kadane's Algorithm works**:
- If at any point the sum of the subarray becomes negative, it means the subarray is doing more harm than good in contributing to the maximum sum. Therefore, we reset the sum and start fresh from the next element.

## Problem Solution
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = nums[0];
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            maxi = max(maxi, sum);

            if(sum < 0) sum = 0;
        }

        return maxi;
    }
};
```

## Problem Solution Explanation

1. **`int sum = 0;`**
   - This variable keeps track of the sum of the current subarray.
   - Initially, we start with `sum = 0`, because we are starting from the beginning of the array.

2. **`int maxi = nums[0];`**
   - This variable keeps track of the maximum subarray sum found so far.
   - We initialize it to the first element of the array because, at the beginning, the maximum sum is at least the first element.

3. **`for (int i = 0; i < nums.size(); i++) {`**
   - A loop to iterate through each element of the array.

4. **`sum += nums[i];`**
   - We add the current element `nums[i]` to the `sum` of the current subarray.
   - This accumulates the sum of elements for the current subarray we're considering.

5. **`maxi = max(maxi, sum);`**
   - After updating the `sum`, we check if this sum is larger than the previously recorded maximum (`maxi`).
   - If `sum` is larger, update `maxi` with the new value.

6. **`if (sum < 0) sum = 0;`**
   - If the `sum` becomes negative, we reset `sum` to 0 because continuing with a negative sum would decrease the overall result.
   - We effectively discard any subarray with a negative sum and start from the next element.

7. **`return maxi;`**
   - Finally, we return `maxi`, which holds the largest sum of a contiguous subarray in the given array.

### **Step 3: Example Walkthrough**

Let's walk through the example with the array `[-2, 1, -3, 4, -1, 2, 1, -5, 4]`.

1. **Initialization**: 
   - `sum = 0`
   - `maxi = -2` (because the first element is `-2`)

2. **Iteration through the array**:

   - **i = 0** (current element `-2`):
     - `sum = sum + (-2) = 0 + (-2) = -2`
     - `maxi = max(-2, -2) = -2`
     - `sum` is negative, so we reset `sum = 0`.
   
   - **i = 1** (current element `1`):
     - `sum = sum + 1 = 0 + 1 = 1`
     - `maxi = max(-2, 1) = 1`

   - **i = 2** (current element `-3`):
     - `sum = sum + (-3) = 1 + (-3) = -2`
     - `maxi = max(1, -2) = 1`
     - `sum` is negative, so we reset `sum = 0`.

   - **i = 3** (current element `4`):
     - `sum = sum + 4 = 0 + 4 = 4`
     - `maxi = max(1, 4) = 4`

   - **i = 4** (current element `-1`):
     - `sum = sum + (-1) = 4 + (-1) = 3`
     - `maxi = max(4, 3) = 4`

   - **i = 5** (current element `2`):
     - `sum = sum + 2 = 3 + 2 = 5`
     - `maxi = max(4, 5) = 5`

   - **i = 6** (current element `1`):
     - `sum = sum + 1 = 5 + 1 = 6`
     - `maxi = max(5, 6) = 6`

   - **i = 7** (current element `-5`):
     - `sum = sum + (-5) = 6 + (-5) = 1`
     - `maxi = max(6, 1) = 6`

   - **i = 8** (current element `4`):
     - `sum = sum + 4 = 1 + 4 = 5`
     - `maxi = max(6, 5) = 6`

3. **Final Output**: After the iteration, the maximum subarray sum is `6`.

### **Step 4: Time and Space Complexity**

#### **Time Complexity**:
- The algorithm iterates through the entire array once, making the time complexity \(O(n)\), where \(n\) is the size of the array.

#### **Space Complexity**:
- The algorithm uses a constant amount of extra space (only two variables, `sum` and `maxi`), so the space complexity is \(O(1)\).

### **Step 5: Additional Recommendations**

1. **Practice Edge Cases**:
   - Single element arrays.
   - Arrays where all elements are negative.
   - Arrays with mixed positive and negative numbers.
   
2. **Visualize the Process**:
   - Try drawing or printing the `sum` and `maxi` at each step to better understand how Kadane's Algorithm works.

3. **Improve Problem Solving**:
   - Practice more problems related to dynamic programming and sliding window techniques, as they often involve similar principles.

By understanding Kadane's Algorithm and its implementation, beginners can efficiently solve problems related to maximum subarrays and build on this knowledge for more advanced dynamic programming problems.
