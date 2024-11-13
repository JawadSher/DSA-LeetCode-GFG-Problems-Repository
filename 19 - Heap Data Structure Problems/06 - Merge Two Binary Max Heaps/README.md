<h1 align='center'>Merge - Two - Binary - Max - Heaps</h1>

## Problem Statement

**Problem URL :** [Merge Two Binary Max Heaps](https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1)

![image](https://github.com/user-attachments/assets/e5c580b0-6f4e-4a78-97a2-7d5dc3c646de)
![image](https://github.com/user-attachments/assets/5e20f073-349f-45e3-a667-685dce1be07e)
![image](https://github.com/user-attachments/assets/5f2555ea-b725-4540-bb3e-9a7605bf5d73)

## Problem Explanation

**Problem Statement**:
The task is to **merge two binary max-heaps** into a single max-heap. A binary max-heap is a complete binary tree where each node’s value is greater than or equal to its children’s values. The merged heap must satisfy both the **completeness** property and the **max-heap** property.

Given two arrays `a` and `b` that represent two binary max-heaps of sizes `n` and `m`, we need to:
1. Combine these arrays into a single array that represents the merged heap.
2. Ensure the combined array satisfies the max-heap property.

**Examples**:
1. **Input**:
   ``` 
   a = [10, 5, 6, 2]
   b = [8, 7, 3]
   ```
   - **Merged Heap**: `[10, 8, 7, 5, 2, 6, 3]`

2. **Input**:
   ```
   a = [9, 4, 8]
   b = [6, 5]
   ```
   - **Merged Heap**: `[9, 6, 8, 4, 5]`

**Approach**:
1. **Merge the Arrays**:
   - First, create a new array, `mergeHeap`, large enough to hold all elements from both arrays.
   - Copy all elements from `a` and `b` into `mergeHeap`.
   
2. **Heapify the Merged Array**:
   - Use the `maxHeapify` function to rearrange elements in `mergeHeap` to satisfy the max-heap property.
   - Start heapifying from the last non-leaf node up to the root node, ensuring all parent nodes are larger than their children.


## Problem Solution
```cpp
class Solution{
    public:
    void maxHeapify(vector<int> &v, int n, int i){
        int largest = i;
        int leftIndex = 2 * i + 1;
        int rightIndex = 2 * i + 2;
        
        if(leftIndex < n && v[largest] < v[leftIndex]) largest = leftIndex;
        if(rightIndex < n && v[largest] < v[rightIndex]) largest = rightIndex;
        
        if(largest != i){
            swap(v[largest], v[i]);
            maxHeapify(v, n, largest);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> mergeHeap(n + m);
        
        for(int i = 0; i < n; i++){
            mergeHeap[i] = a[i];
        }
        
        for(int i = 0; i < m; i++){
            mergeHeap[n+i] = b[i];
        }
        
        for(int i = m+n / 2 -1; i >= 0; i--){
            
            maxHeapify(mergeHeap, n+m, i);
        }
        
        return mergeHeap;
    }
};
```

## Problem Solution Explanation

```cpp
class Solution{
public:
    void maxHeapify(vector<int> &v, int n, int i){
        int largest = i;
        int leftIndex = 2 * i + 1;
        int rightIndex = 2 * i + 2;
```
- **`maxHeapify` Function**: A helper function to maintain the max-heap property.
  - `largest` is initially set to `i`, assuming `i` is the largest.
  - `leftIndex` and `rightIndex` calculate the indices of the left and right children of the node at index `i`.

```cpp
        if(leftIndex < n && v[largest] < v[leftIndex]) largest = leftIndex;
        if(rightIndex < n && v[largest] < v[rightIndex]) largest = rightIndex;
```
- Checks if the left and right children exist within bounds (`< n`) and if either child is larger than the current largest element.
- Updates `largest` to the index of the largest element among `i`, `leftIndex`, and `rightIndex`.

```cpp
        if(largest != i){
            swap(v[largest], v[i]);
            maxHeapify(v, n, largest);
        }
    }
```
- If `largest` is not `i`, it swaps the elements at `i` and `largest` to ensure the max-heap property.
- Calls `maxHeapify` recursively to fix any violations in the subtree rooted at `largest`.

```cpp
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> mergeHeap(n + m);
        
        for(int i = 0; i < n; i++){
            mergeHeap[i] = a[i];
        }
        
        for(int i = 0; i < m; i++){
            mergeHeap[n+i] = b[i];
        }
```
- **`mergeHeaps` Function**: The main function to merge two heaps.
  - Initializes `mergeHeap` with size `n + m`.
  - Copies elements from array `a` to `mergeHeap`.
  - Copies elements from array `b` into `mergeHeap` starting from index `n`.

```cpp
        for(int i = m+n / 2 -1; i >= 0; i--){
            maxHeapify(mergeHeap, n+m, i);
        }
        
        return mergeHeap;
    }
};
```
- Starts heapifying from the last non-leaf node (`(m + n) / 2 - 1`) up to the root.
- Calls `maxHeapify` for each node to restore the max-heap property.
- Returns the `mergeHeap` array.

### Step 3: Example Walkthrough

1. **Example 1**:
   - **Input**:
     ```
     a = [10, 5, 6, 2]
     b = [8, 7, 3]
     ```
   - **Steps**:
     - **Merging Arrays**: `mergeHeap = [10, 5, 6, 2, 8, 7, 3]`
     - **Heapifying**: Starting from the last non-leaf node and moving up.
       - At index `2`: Heapify `[10, 5, 7, 2, 8, 6, 3]`
       - At index `1`: Heapify `[10, 8, 7, 5, 2, 6, 3]`
       - At index `0`: Heapify `[10, 8, 7, 5, 2, 6, 3]`
   - **Output**: `[10, 8, 7, 5, 2, 6, 3]`

2. **Example 2**:
   - **Input**:
     ```
     a = [9, 4, 8]
     b = [6, 5]
     ```
   - **Steps**:
     - **Merging Arrays**: `mergeHeap = [9, 4, 8, 6, 5]`
     - **Heapifying**: Starting from the last non-leaf node and moving up.
       - At index `1`: Heapify `[9, 6, 8, 4, 5]`
       - At index `0`: Heapify `[9, 6, 8, 4, 5]`
   - **Output**: `[9, 6, 8, 4, 5]`

### Step 4: Time and Space Complexity

- **Time Complexity**:
  - Copying elements from `a` and `b` into `mergeHeap` takes **O(n + m)**.
  - Heapifying the merged array (`mergeHeap`) with `maxHeapify` takes **O(n + m)**, as each call to `maxHeapify` has a logarithmic complexity of **O(log(n + m))** and it’s applied to every element.
  - Total time complexity: **O(n + m)**.

- **Space Complexity**:
  - **O(n + m)**, as we create a new array `mergeHeap` to store the elements of both heaps.

### Step 5: Additional Recommendations for Students

- **Practice** with different combinations of arrays to understand how heapification works.
- **Understand Heap Structure**: Review how max-heaps are stored in arrays and how `leftIndex = 2 * i + 1` and `rightIndex = 2 * i + 2` access children nodes.
- **Debugging Tip**: For large arrays, printing intermediate states of `mergeHeap` can help visualize the transformations.
- **Further Exploration**: Practice merging heaps using priority queues to see different implementations and time complexities.
