<h1 align='center'>Minimum - Cost - Of - Ropes</h1>

## Problem Statement

**Problem URL :** [Minimum Cost of Ropes](https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1)

![image](https://github.com/user-attachments/assets/ded528c4-a20b-45d3-aecf-e0f9cd54ec49)
![image](https://github.com/user-attachments/assets/126aa3eb-2252-4110-8bf8-46a8764afff8)

## Problem Explanation
**Problem Statement**:
You are given an array, `arr`, where each element represents the length of a rope. Your task is to **combine all ropes into one single rope with the minimum cost**. The cost to connect two ropes is the sum of their lengths, and this combined rope can be used to connect with others in subsequent steps.

**Goal**:
Find the minimum total cost required to combine all ropes.

**Example**:
1. **Input**:
   ```
   arr = [4, 3, 2, 6]
   ```
   - **Output**: `29`
   - **Explanation**:
     - Step 1: Combine `2 + 3 = 5`, cost = `5`.
     - Step 2: Combine `4 + 5 = 9`, cost = `5 + 9 = 14`.
     - Step 3: Combine `6 + 9 = 15`, cost = `14 + 15 = 29`.

2. **Input**:
   ```
   arr = [1, 2, 3, 4, 5]
   ```
   - **Output**: `33`
   - **Explanation**:
     - Step 1: Combine `1 + 2 = 3`, cost = `3`.
     - Step 2: Combine `3 + 3 = 6`, cost = `3 + 6 = 9`.
     - Step 3: Combine `4 + 6 = 10`, cost = `9 + 10 = 19`.
     - Step 4: Combine `5 + 10 = 15`, cost = `19 + 15 = 33`.

**Approach**:
1. **Use a Min-Heap** (priority queue):
   - Insert all elements (rope lengths) into a min-heap. This ensures that the smallest elements are always at the top.
2. **Combine the Two Smallest Ropes**:
   - Repeatedly remove the two smallest ropes from the min-heap.
   - Add their lengths together to get the cost for that combination and push the combined rope back into the heap.
   - Accumulate this cost until only one rope remains in the heap.

This approach guarantees the minimum cost because it prioritizes combining the smallest lengths first, reducing the incremental costs at each step.

## Problem Solution
```cpp
class Solution {
  public:
    
    long long minCost(vector<long long>& arr) {
        
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        for(int i = 0; i < arr.size(); i++){
            pq.push(arr[i]);
        }
        
        long long cost = 0;
        while(pq.size() > 1){
            long long a = pq.top();
            pq.pop();
            
            long long b = pq.top();
            pq.pop();
            
            long long sum = a + b;
            cost += sum;
            
            pq.push(sum);
        }
        
        return cost;
    }
};

```

## Problem Solution Explanation

```cpp
class Solution {
  public:
    
    long long minCost(vector<long long>& arr) {
        
        priority_queue<long long, vector<long long>, greater<long long>> pq;
```
- **`minCost` function**: Takes an array `arr` as input and returns the minimum cost to combine all ropes.
- **Min-Heap Declaration**: `priority_queue` is initialized as a min-heap using `greater<long long>`. This ensures the smallest elements are at the top.

```cpp
        for(int i = 0; i < arr.size(); i++){
            pq.push(arr[i]);
        }
```
- **Push Elements into Min-Heap**: All elements of `arr` are pushed into `pq`, building a min-heap with the initial rope lengths.

```cpp
        long long cost = 0;
        while(pq.size() > 1){
            long long a = pq.top();
            pq.pop();
            
            long long b = pq.top();
            pq.pop();
            
            long long sum = a + b;
            cost += sum;
            
            pq.push(sum);
        }
```
- **Initialize Total Cost**: `cost` is set to `0` and will store the cumulative cost of combining ropes.
- **Loop**: While the size of the heap is greater than 1:
  - **Extract the Two Smallest Ropes**: `a` and `b` are the two smallest ropes. After accessing each, they are removed from `pq`.
  - **Calculate Combination Cost**: `sum = a + b` is the cost of combining `a` and `b`.
  - **Accumulate Cost**: Add `sum` to `cost`.
  - **Insert Combined Rope**: Push the combined rope length `sum` back into `pq` for further combinations if needed.

```cpp
        return cost;
    }
};
```
- **Return Total Cost**: After all ropes are combined, `cost` holds the minimum total cost.

### Step 3: Example Walkthrough

1. **Example 1**:
   - **Input**: `arr = [4, 3, 2, 6]`
   - **Process**:
     - Step 1: Heap = `[2, 3, 4, 6]`
       - Combine `2 + 3 = 5`, cost = `5`.
       - New Heap = `[4, 5, 6]`
     - Step 2:
       - Combine `4 + 5 = 9`, cost = `5 + 9 = 14`.
       - New Heap = `[6, 9]`
     - Step 3:
       - Combine `6 + 9 = 15`, cost = `14 + 15 = 29`.
       - New Heap = `[15]`
   - **Output**: `29`

2. **Example 2**:
   - **Input**: `arr = [1, 2, 3, 4, 5]`
   - **Process**:
     - Step 1: Heap = `[1, 2, 3, 4, 5]`
       - Combine `1 + 2 = 3`, cost = `3`.
       - New Heap = `[3, 3, 4, 5]`
     - Step 2:
       - Combine `3 + 3 = 6`, cost = `3 + 6 = 9`.
       - New Heap = `[4, 5, 6]`
     - Step 3:
       - Combine `4 + 6 = 10`, cost = `9 + 10 = 19`.
       - New Heap = `[5, 10]`
     - Step 4:
       - Combine `5 + 10 = 15`, cost = `19 + 15 = 33`.
       - New Heap = `[15]`
   - **Output**: `33`

### Step 4: Time and Space Complexity

- **Time Complexity**:
  - Pushing elements into the min-heap initially takes **O(n log n)**, where `n` is the number of ropes.
  - In the main loop, for each iteration:
    - We remove the two smallest elements and insert their sum back, which takes **O(log n)**.
    - Since we perform this operation `n - 1` times, the time complexity is **O(n log n)**.
  - Overall time complexity: **O(n log n)**.

- **Space Complexity**:
  - We use a min-heap `pq` that holds up to `n` elements, so the space complexity is **O(n)**.

### Step 5: Additional Recommendations for Students

- **Min-Heap Mastery**: Practice implementing and using min-heaps for similar greedy problems.
- **Greedy Choice Property**: This problem demonstrates the greedy approach by always combining the smallest ropes first to minimize cost.
- **Alternative Practice**: Try implementing this with custom heap logic to better understand heap operations if the priority queue is still challenging.
- **Edge Cases**: Try testing with single or minimal ropes (e.g., `arr = [5]`), where the cost should be `0`, as no combination is needed.
