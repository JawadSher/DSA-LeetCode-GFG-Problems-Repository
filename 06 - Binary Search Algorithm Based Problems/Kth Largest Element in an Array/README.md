<h1 align='center'>Kth - Largest - Element - in an - Array</h1>

## Problem Statement

**Problem URL :** [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)

![image](https://github.com/user-attachments/assets/861f7d7f-8ac7-4d2d-8586-1da82f9201c7)


## Problem Explanation
You are given an array of integers and an integer `k`. Your task is to find the **kth largest element** in this array. The "kth largest" element is the element that would appear in the k-th position if the array were sorted in descending order.

#### Detailed Explanation

1. **Definition of "Kth Largest":**
   - If you were to sort the array in descending order (from largest to smallest), the kth largest element is the element at the k-th position in this sorted array.
   - For example, in the sorted array `[6, 5, 4, 3, 2, 1]`, the 2nd largest element is `5`.

2. **Objective:**
   - Find the kth largest element in the array without necessarily sorting the entire array.

#### Example Scenarios

**Example 1:**

- **Input:** `nums = [3, 2, 1, 5, 6, 4]`, `k = 2`
- **Output:** `5`
- **Explanation:**
  1. Sort the array in descending order: `[6, 5, 4, 3, 2, 1]`.
  2. The 2nd largest element in this sorted array is `5`.

**Example 2:**

- **Input:** `nums = [3, 2, 3, 1, 2, 4, 5, 5, 6]`, `k = 4`
- **Output:** `4`
- **Explanation:**
  1. Sort the array in descending order: `[6, 5, 5, 4, 3, 3, 2, 2, 1]`.
  2. The 4th largest element in this sorted array is `4`.

**Example 3:**

- **Input:** `nums = [7, 10, 4, 3, 20, 15]`, `k = 3`
- **Output:** `10`
- **Explanation:**
  1. Sort the array in descending order: `[20, 15, 10, 7, 4, 3]`.
  2. The 3rd largest element in this sorted array is `10`.

**Example 4:**

- **Input:** `nums = [1, 2, 3, 4, 5]`, `k = 1`
- **Output:** `5`
- **Explanation:**
  1. Sort the array in descending order: `[5, 4, 3, 2, 1]`.
  2. The 1st largest element (i.e., the largest element) in this sorted array is `5`.

#### Key Points

1. **Sorting Perspective:**
   - If the array is sorted in descending order, the kth largest element is at index `k-1` in the sorted array.
   - Sorting the array directly has a time complexity of `O(N log N)`, where `N` is the number of elements in the array.

2. **Alternative Approaches:**
   - **Min-Heap:** Use a min-heap to keep track of the top k largest elements. This method has a time complexity of `O(N log k)`.
   - **Binary Search:** Use binary search combined with counting to find the kth largest element without sorting the entire array. This approach can be more efficient in some cases with a time complexity of `O(N * log(max - min))`.

Understanding the problem involves recognizing that you're looking for a specific position in a sorted order, but there are multiple efficient ways to find this element without fully sorting the array.

## Problem Solution
```cpp
class Solution {
public:
    int Counter(vector<int>& nums, int target){
        int count = 0;

        for(int num : nums){
            if(num >= target){
                count++;
            }
        }

        return count;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int start = *min_element(nums.begin(), nums.end());
        int end = *max_element(nums.begin(), nums.end());

        while(start < end){
            int mid = start + (end - start + 1)/2;

            int count = Counter(nums, mid);

            if(count >= k){
                start = mid;
            }else{
                end = mid - 1;
            }
        }
    return start;
    }
};
```

## Problem Solution Explanation

1. **Class Definition:**
   ```cpp
   class Solution {
   public:
   ```
   - Defines a class named `Solution` with public access.

2. **Counter Function:**
   ```cpp
   int Counter(vector<int>& nums, int target){
       int count = 0;
   ```
   - `Counter` is a helper function that takes a vector `nums` and an integer `target`. It returns the count of elements in `nums` that are greater than or equal to `target`.

   ```cpp
       for(int num : nums){
           if(num >= target){
               count++;
           }
       }
       return count;
   }
   ```
   - Iterates through each element `num` in `nums`. If `num` is greater than or equal to `target`, it increments the `count`.
   - After the loop, it returns the count of such elements.

3. **findKthLargest Function:**
   ```cpp
   int findKthLargest(vector<int>& nums, int k) {
       int start = *min_element(nums.begin(), nums.end());
       int end = *max_element(nums.begin(), nums.end());
   ```
   - `findKthLargest` is the main function to find the kth largest element in the array `nums`.
   - `start` is initialized to the minimum value in `nums`.
   - `end` is initialized to the maximum value in `nums`.

   ```cpp
       while(start < end){
           int mid = start + (end - start + 1)/2;
           int count = Counter(nums, mid);
   ```
   - Performs binary search within the range `[start, end]`.
   - `mid` is calculated as the midpoint of `start` and `end`. The formula `(end - start + 1)/2` ensures that `mid` is biased towards the higher end when the range has an odd number of elements.
   - `count` is the number of elements in `nums` that are greater than or equal to `mid`, as determined by the `Counter` function.

   ```cpp
           if(count >= k){
               start = mid;
           } else {
               end = mid - 1;
           }
       }
   ```
   - If the number of elements greater than or equal to `mid` is greater than or equal to `k`, `start` is moved up to `mid` (meaning `mid` could be the kth largest).
   - Otherwise, `end` is decreased to `mid - 1` to look for a smaller value.

   ```cpp
       return start;
   }
   ```
   - When the loop terminates, `start` will be equal to the kth largest element. The function returns this value.

### Complexity:

- **Time Complexity:**
  - **Binary Search:** The binary search range is `[min(nums), max(nums)]`. The maximum number of iterations is `O(log(max - min))`, where `max` and `min` are the maximum and minimum values in `nums`, respectively.
  - **Counting Elements:** Counting how many elements are greater than or equal to `mid` takes `O(N)`, where `N` is the number of elements in the array.
  - Overall time complexity is `O(N * log(max - min))`.

- **Space Complexity:**
  - **Auxiliary Space:** The space complexity is `O(1)`, as the algorithm uses only a few extra variables for computation.

This code efficiently finds the kth largest element without sorting the entire array by leveraging binary search and counting operations.
