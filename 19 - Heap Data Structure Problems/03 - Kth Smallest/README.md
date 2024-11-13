<h1 align='center'>Kth - Smallest</h1>

## Problem Statement
**Problem URL :** [Kth Smallest](https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/8a47a181-3af6-49e7-8e7e-695c2a8c3d22)

## Problem Explanation

The **Kth Smallest Element** problem requires us to find the `k`th smallest element in a given array. This is commonly encountered in coding interviews and is essential for learning how to handle selection problems in an array efficiently.

Let's break down what it means with an example:
1. **Input**: We have an unsorted array `arr = [7, 10, 4, 3, 20, 15]` and we want to find the 3rd smallest element (`k = 3`).
2. **Output**: The 3rd smallest element in this array is `7`, because if we sorted the array, we would get `[3, 4, 7, 10, 15, 20]`.

To solve this, the naive approach would be to sort the entire array and pick the `k`th element directly, but that could take time `O(n log n)` where `n` is the size of the array. However, we can use a more efficient solution using a **Max Heap** (or priority queue), which allows us to only keep track of the smallest `k` elements without fully sorting the array.

### Approach to Solve the Problem

1. **Max Heap Initialization**:
   - We initialize a **Max Heap** to store the smallest `k` elements seen so far. This is done because, in a Max Heap, the largest element among the smallest `k` elements will always be at the top.
   - In C++, the `priority_queue<int>` by default is a Max Heap.

2. **First `k` Elements**:
   - Push the first `k` elements of `arr` into the heap. After adding these `k` elements, the root of the heap (i.e., `pq.top()`) will contain the largest element among the first `k` elements.

3. **Traverse Remaining Elements**:
   - For each element from the `k+1`th element onwards:
     - If this element is smaller than the top of the Max Heap, remove the top element and insert the current element.
     - This step ensures that we always maintain only the `k` smallest elements in the heap, with the largest of them at the root.

4. **Result**:
   - Once all elements have been processed, the top of the Max Heap will contain the `k`th smallest element in the array.

## Problem Solution
```cpp
class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> pq;
        
        for(int i = 0; i < k; i++){
            pq.push(arr[i]);
        }
        
        for(int i = k; i < arr.size(); i++){
            if(arr[i] < pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        return pq.top();
    }
};
```

## Problem Solution Explanation
Here's a line-by-line breakdown of the code, including explanations for each part with examples.

```cpp
class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
```

- We define a class `Solution` with a public method `kthSmallest`.
- The method takes a reference to a vector `arr` (our input array) and an integer `k`, representing the position of the smallest element we want to find.
- **Example**: If `arr = [7, 10, 4, 3, 20, 15]` and `k = 3`, our goal is to find the 3rd smallest element.

```cpp
        priority_queue<int> pq;
```

- Here, we declare a max-heap `pq` using `priority_queue<int>` in C++. By default, `priority_queue` in C++ is a max-heap, which means the largest element will always be at the top.
- This max-heap will help us keep track of the `k` smallest elements in the array.
- **Example**: Initially, the max-heap is empty: `pq = {}`.

```cpp
        for(int i = 0; i < k; i++){
            pq.push(arr[i]);
        }
```

- We push the first `k` elements of `arr` into the max-heap.
- After this loop, the heap `pq` will contain the first `k` elements of `arr`, with the largest of these elements at the root/top of the heap.
- **Example**: If `arr = [7, 10, 4, 3, 20, 15]` and `k = 3`, after this loop, the heap contains `{10, 7, 4}`, with `10` as the largest element at the top.

```cpp
        for(int i = k; i < arr.size(); i++){
            if(arr[i] < pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
```

- Now we iterate over the rest of the array, starting from index `k`.
  - `arr[i] < pq.top()`: We check if the current element of `arr` is smaller than the largest element in our heap (`pq.top()`).
    - If it is smaller, we pop the largest element from the heap (remove the root) and push the current element. This step ensures that we maintain only the `k` smallest elements in `pq`, with the largest of those `k` elements at the top.
  - If the current element is not smaller, we ignore it and move to the next one.
- **Example**:
  - Let’s continue with `arr = [7, 10, 4, 3, 20, 15]` and `k = 3`.
  - Initially, `pq = {10, 7, 4}`.
  - For `arr[3] = 3`: `3 < 10` (top of heap), so we pop `10` and push `3`. Now, `pq = {7, 4, 3}`.
  - For `arr[4] = 20`: `20 > 7` (top of heap), so we ignore it.
  - For `arr[5] = 15`: `15 > 7` (top of heap), so we ignore it.

```cpp
        return pq.top();
    }
};
```

- After processing all elements, the top of the heap (`pq.top()`) holds the `k`th smallest element.
- **Example**: In our example, `pq.top()` is `7`, so `7` is the 3rd smallest element in `arr = [7, 10, 4, 3, 20, 15]`.

### Full Example Walkthrough

For `arr = [7, 10, 4, 3, 20, 15]` and `k = 3`:
1. **Initialize Heap**:
   - Insert first `k` elements `[7, 10, 4]` into `pq`.
   - `pq = {10, 7, 4}`, with `10` as the max (top of heap).

2. **Process Remaining Elements**:
   - `3 < 10`: Pop `10`, push `3` → `pq = {7, 4, 3}`.
   - `20 > 7`: Ignore it.
   - `15 > 7`: Ignore it.

3. **Result**:
   - `pq.top()` is `7`, which is the 3rd smallest element in `arr`.

### Step 4: Time and Space Complexity

1. **Time Complexity**:
   - Building the initial Max Heap with `k` elements takes `O(k log k)`.
   - For the remaining `n - k` elements, each comparison and insertion takes `O(log k)`, leading to an overall complexity of `O(k log k) + O((n - k) log k)`, which simplifies to `O(n log k)`.

2. **Space Complexity**:
   - The space complexity is `O(k)` due to the Max Heap storing up to `k` elements.

### Step 5: Additional Recommendations for Students

- **Heap Fundamentals**: Understanding how heaps work and when to use Max vs. Min Heaps is critical for similar problems.
- **Edge Cases**: Consider cases where `k` is `1` (smallest element) or equal to the array's length (largest element).
- **Alternative Approaches**: For large values of `k`, a Min Heap might be a better choice, or use quickselect for linear-time average solutions.

This approach using a Max Heap is efficient and aligns well with real-world problem-solving needs where we handle partial sorts frequently.
