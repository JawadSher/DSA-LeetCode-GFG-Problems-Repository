<h1 align='center'>Kth - Largest - Sum - Contiguous - Subarray</h1>

## Problem Statement

**Problem URL :** [Kth Largest Sum Contiguous Subarray](https://www.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1)

![image](https://github.com/user-attachments/assets/651b4b96-230e-4192-944b-f8233eda94da)

## Problem Explanation
Given an array of integers, you are tasked to find the `k`-th largest sum among all possible contiguous subarrays of the array.

#### Explanation with Example
A contiguous subarray is a subarray that consists of consecutive elements from the original array. For example, if the array is `[1, 2, 3]`, the contiguous subarrays are:
- `[1]`
- `[2]`
- `[3]`
- `[1, 2]`
- `[2, 3]`
- `[1, 2, 3]`

For each subarray, we calculate the sum:
- `[1]` → sum is `1`
- `[2]` → sum is `2`
- `[3]` → sum is `3`
- `[1, 2]` → sum is `3`
- `[2, 3]` → sum is `5`
- `[1, 2, 3]` → sum is `6`

If `k = 2`, we need to find the 2nd largest sum. After sorting all sums `{1, 2, 3, 3, 5, 6}`, the 2nd largest is `5`.

#### Approach to Solve the Problem
1. **Identify All Contiguous Subarrays**: To find the `k`-th largest sum among all possible contiguous subarrays, we need to consider all of them.
2. **Use a Min-Heap**: A min-heap (or priority queue) is ideal for tracking the largest `k` sums:
   - If the heap has less than `k` elements, push the sum directly.
   - Once the heap has `k` elements, compare the current sum with the smallest element in the heap (i.e., `pq.top()`). If the current sum is larger, replace `pq.top()` with the current sum to maintain only the largest `k` sums.
3. **Result**: After processing all possible subarray sums, `pq.top()` will hold the `k`-th largest sum.

## Problem Solution
```cpp
class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int n = arr.size();
        
        for(int i = 0; i < n; i++){
            
            int sum = 0;
            
            for(int j = i; j < n; j++){
                sum += arr[j];        
            
                if(pq.size() < k){
                    pq.push(sum);
                }else{
                    if(sum > pq.top()){
                        pq.pop();
                        pq.push(sum);
                    }
                }
            }
        }
        
        return pq.top();
    }
};
```

## Problem Solution Explanation

```cpp
class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
```

- **Explanation**:  
  This is the beginning of the `Solution` class, which contains a public method called `kthLargest`. This method takes a vector of integers (`arr`) and an integer (`k`) as input.
  
- **Example**:  
  If `arr = [3, 2, 1]` and `k = 2`, we are finding the 2nd largest sum among all possible contiguous subarrays of `arr`.



```cpp
        priority_queue<int, vector<int>, greater<int>> pq;
```

- **Explanation**:  
  Here, we create a min-heap (priority queue) called `pq`. We use `greater<int>` as the third parameter to make it a min-heap, where the smallest element is always at the top. This min-heap will help us keep track of the top `k` largest sums.

- **Example**:  
  For `k = 2`, this heap will store the 2 largest sums as we find them.  



```cpp
        int n = arr.size();
```

- **Explanation**:  
  We store the size of `arr` in the variable `n` for easy reference throughout the code.

- **Example**:  
  If `arr = [3, 2, 1]`, then `n = 3`.



```cpp
        for(int i = 0; i < n; i++){
```

- **Explanation**:  
  This is the beginning of an outer loop, which iterates over each element in `arr`. The variable `i` represents the starting index of each subarray. 

- **Example**:  
  For `arr = [3, 2, 1]`, the outer loop will run 3 times with `i = 0`, `i = 1`, and `i = 2`.



```cpp
            int sum = 0;
```

- **Explanation**:  
  We initialize a variable `sum` to 0. This `sum` variable will store the cumulative sum of each subarray that starts at index `i`.



```cpp
            for(int j = i; j < n; j++){
```

- **Explanation**:  
  This is the beginning of an inner loop, which iterates from the starting index `i` to the end of the array. The variable `j` represents the end index of the current subarray.

- **Example**:  
  - If `i = 0`, `j` will take values `0, 1, 2`, representing subarrays `[3]`, `[3, 2]`, and `[3, 2, 1]`.
  - If `i = 1`, `j` will take values `1, 2`, representing subarrays `[2]` and `[2, 1]`.



```cpp
                sum += arr[j];
```

- **Explanation**:  
  We add `arr[j]` to `sum`, updating the cumulative sum of the current subarray.

- **Example**:  
  - If `arr = [3, 2, 1]` and `i = 0`, the `sum` values in each inner loop iteration will be:
    - `j = 0`: `sum = 3` (subarray `[3]`)
    - `j = 1`: `sum = 5` (subarray `[3, 2]`)
    - `j = 2`: `sum = 6` (subarray `[3, 2, 1]`)



```cpp
                if(pq.size() < k){
                    pq.push(sum);
```

- **Explanation**:  
  Here, we check if the heap `pq` has fewer than `k` elements. If it does, we add `sum` to `pq`.

- **Example**:  
  - For `k = 2`, if `pq` has less than 2 elements, we push the `sum` of each subarray directly.



```cpp
                } else {
                    if(sum > pq.top()){
                        pq.pop();
                        pq.push(sum);
                    }
                }
```

- **Explanation**:  
  If `pq` already has `k` elements, we check if `sum` is greater than the smallest element in `pq` (which is `pq.top()`). If it is, we pop the smallest element and push the current `sum` to ensure that `pq` contains the `k` largest sums found so far.

- **Example**:  
  For `k = 2`:
  - Suppose `pq` already contains `[3, 5]` and `sum = 6`. Since `6 > 3`, we pop `3` and push `6`, updating `pq` to `[5, 6]`.
  - If `sum = 4` comes up, it’s not greater than `pq.top()`, so we skip it.



```cpp
            }
        }
        
        return pq.top();
```

- **Explanation**:  
  After both loops complete, the top element of `pq` (i.e., `pq.top()`) will be the `k`-th largest sum among all contiguous subarrays. This value is returned as the result.

- **Example**:  
  If `pq` contains `[5, 6]` after processing all subarrays for `k = 2`, `pq.top()` (which is `5`) is returned as the 2nd largest sum.



### Step 3: Additional Example

Let’s walk through the code with an example input to see how the heap changes.

**Example**  
Input: `arr = [3, 2, 1]`, `k = 2`

**Process**:
1. **i = 0**:
   - **j = 0**: sum = 3 → `pq` is `[3]`
   - **j = 1**: sum = 5 → `pq` becomes `[3, 5]`
   - **j = 2**: sum = 6 → `6 > 3` → pop `3`, push `6` → `pq` becomes `[5, 6]`
   
2. **i = 1**:
   - **j = 1**: sum = 2 → `2 < 5`, so `pq` remains `[5, 6]`
   - **j = 2**: sum = 3 → `3 < 5`, so `pq` remains `[5, 6]`
   
3. **i = 2**:
   - **j = 2**: sum = 1 → `1 < 5`, so `pq` remains `[5, 6]`

At the end, `pq` contains `[5, 6]`. Thus, `pq.top()`, which is `5`, is the 2nd largest sum.



### Step 4: Time and Space Complexity

1. **Time Complexity**:  
   - Outer loop runs `n` times (for each starting index).
   - Inner loop runs up to `n` times.
   - Each insertion and removal in the heap takes `O(log k)`.
   - Therefore, total time complexity = `O(n^2 * log k)`.

2. **Space Complexity**:
   - The heap size is at most `k`, so space complexity = `O(k)`.


### Step 5: Additional Recommendations for Students

1. **Practice with Min-Heaps**: Understanding how min-heaps work is essential, especially for maintaining top `k` elements.
2. **Work with Sliding Windows**: This problem introduces a concept similar to sliding windows and cumulative sums, helpful in optimizing problems with subarrays.
3. **Alternative Approach**: For very large arrays, advanced techniques like "prefix sums" could optimize finding subarray sums.

This explanation should give you a solid foundation for understanding and implementing the solution for the Kth Largest Sum Contiguous Subarray problem.
