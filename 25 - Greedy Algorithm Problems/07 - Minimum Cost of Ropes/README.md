<h1 align="center">Minimum - Cost of - Ropes</h1>

## Problem Statement

**Problem URL :** [Minimum Cost of Ropes](https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1)

![image](https://github.com/user-attachments/assets/25884057-489c-47f4-895c-b7b981cc8a66)

### Problem Explanation
You are given a collection of ropes with different lengths. The task is to connect these ropes into a single rope. Each time you connect two ropes, the cost of the operation is equal to the sum of the lengths of the two ropes. You need to minimize the total cost of connecting all the ropes.

**Example:**
- Suppose you have ropes with lengths `{4, 3, 2, 6}`.

  - **Step 1**: Select the two smallest ropes (lengths 2 and 3). The cost of connecting them is `2 + 3 = 5`.
  - **Step 2**: The new rope formed has a length of `5`. Now, the ropes are `{4, 5, 6}`.
  - **Step 3**: Select the two smallest ropes (lengths 4 and 5). The cost of connecting them is `4 + 5 = 9`.
  - **Step 4**: The new rope formed has a length of `9`. Now, the ropes are `{6, 9}`.
  - **Step 5**: Select the two smallest ropes (lengths 6 and 9). The cost of connecting them is `6 + 9 = 15`.
  
  - **Total cost**: `5 + 9 + 15 = 29`.

Thus, the minimum cost of connecting all the ropes is `29`.

### Greedy Algorithm Approach

The greedy approach works well for this problem because at each step, you are always making the locally optimal choice, i.e., selecting the two smallest ropes to connect, which ensures the minimum cost in the long run.

#### Steps:
1. **Sort the ropes** (or use a priority queue/min-heap to easily extract the smallest ropes).
2. **Extract the two smallest ropes**.
3. **Connect the ropes**, which adds to the total cost.
4. **Push the new combined rope** back into the heap or list.
5. **Repeat the process** until only one rope remains.

### Example Walkthrough of the Greedy Algorithm

For the array `{4, 3, 2, 6}`:
1. **Initialization**: Use a priority queue (min-heap) to automatically sort the ropes.
2. After pushing all the ropes into the heap, we get `{2, 3, 4, 6}`.
3. **First iteration**:
   - Extract `2` and `3` (the two smallest ropes).
   - Cost to combine them: `2 + 3 = 5`.
   - New rope of length `5` is pushed back into the heap, so the heap becomes `{4, 5, 6}`.
4. **Second iteration**:
   - Extract `4` and `5`.
   - Cost to combine them: `4 + 5 = 9`.
   - New rope of length `9` is pushed back into the heap, so the heap becomes `{6, 9}`.
5. **Final iteration**:
   - Extract `6` and `9`.
   - Cost to combine them: `6 + 9 = 15`.
   - Total cost is `5 + 9 + 15 = 29`.

## Problem Solution
```cpp
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    int minCost(vector<int>& arr) {
        // Create a min-heap (priority queue) to store the rope lengths
        priority_queue<int, vector<int>, greater<int>> pq;
        
        // Push all the rope lengths into the priority queue
        for(int i = 0; i < arr.size(); i++) pq.push(arr[i]);
        
        // Variable to store the total cost of connecting the ropes
        int totalCost = 0;
        
        // Continue combining the two smallest ropes until only one rope remains
        while(pq.size() > 1){
            // Get the two smallest ropes from the heap
            int mini_1 = pq.top();
            pq.pop();
            
            int mini_2 = pq.top();
            pq.pop();
            
            // Calculate the cost of connecting the two smallest ropes
            int total = mini_1 + mini_2;
            
            // Add this cost to the total cost
            totalCost += total;
            
            // Push the new combined rope (total length) back into the priority queue
            pq.push(total);
        }
        
        // Return the total cost of connecting all ropes
        return totalCost;
    }
};
```

## Problem Solution Explanation

#### 1. **Class Definition**:
```cpp
class Solution {
```
- The class `Solution` is defined to encapsulate the logic for the problem of finding the minimum cost of connecting ropes.

#### 2. **Function Definition**:
```cpp
int minCost(vector<int>& arr) {
```
- The function `minCost` takes a reference to a vector of integers `arr`, where each integer represents the length of a rope. The function returns the minimum cost of connecting all the ropes.

#### 3. **Priority Queue Definition**:
```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```
- Here, a **min-heap** (implemented using a priority queue) is defined. The min-heap will store the rope lengths and allow us to efficiently extract the two smallest lengths.
- The type `greater<int>` specifies that the priority queue will give priority to the smallest element (i.e., it behaves like a min-heap).

#### 4. **Inserting Rope Lengths into the Priority Queue**:
```cpp
for(int i = 0; i < arr.size(); i++) pq.push(arr[i]);
```
- This loop iterates over all the elements in the vector `arr`, and each rope length is pushed into the priority queue.
- For example, if `arr = [8, 4, 6, 12]`, the priority queue after this loop will be `pq = {4, 6, 8, 12}`.

#### 5. **Initialize Total Cost**:
```cpp
int totalCost = 0;
```
- We initialize the `totalCost` variable to 0. This variable will keep track of the total cost of combining the ropes.

#### 6. **While Loop to Combine Ropes**:
```cpp
while(pq.size() > 1){
```
- The `while` loop runs as long as there is more than one rope in the priority queue. This is because, at the end, we want only one rope left, which represents the final connected rope.

#### 7. **Extract the Two Smallest Ropes**:
```cpp
int mini_1 = pq.top();
pq.pop();

int mini_2 = pq.top();
pq.pop();
```
- `pq.top()` gives the smallest element in the heap, and `pq.pop()` removes the smallest element from the heap.
- The two smallest ropes (`mini_1` and `mini_2`) are extracted here. 
- For example, if the heap is `pq = {4, 6, 8, 12}`, after this code, `mini_1 = 4` and `mini_2 = 6`.

#### 8. **Calculate the Cost of Connecting the Two Smallest Ropes**:
```cpp
int total = mini_1 + mini_2;
```
- We calculate the cost of connecting the two smallest ropes by adding their lengths together (`total = mini_1 + mini_2`).

#### 9. **Add the Cost to the Total Cost**:
```cpp
totalCost += total;
```
- The calculated `total` is added to the `totalCost`, which accumulates the cost of connecting all ropes.

#### 10. **Push the New Combined Rope Back into the Priority Queue**:
```cpp
pq.push(total);
```
- The newly combined rope (with length `total`) is pushed back into the priority queue.

#### 11. **Repeat the Process Until One Rope Remains**:
- This loop continues until only one rope remains in the priority queue.

#### 12. **Return the Total Cost**:
```cpp
return totalCost;
```
- Finally, after all ropes are connected, we return the `totalCost`, which is the minimum cost to connect all the ropes.

### Example Walkthrough:

Let's consider an example input `arr = [8, 4, 6, 12]`.

1. Initially, the priority queue will be: `{4, 6, 8, 12}`.

2. **First Iteration:**
   - Extract the two smallest ropes: `mini_1 = 4`, `mini_2 = 6`.
   - The cost to connect these ropes is `4 + 6 = 10`.
   - Add this cost to the total cost: `totalCost = 0 + 10 = 10`.
   - Push the new rope of length `10` into the priority queue. The new queue is: `{8, 10, 12}`.

3. **Second Iteration:**
   - Extract the two smallest ropes: `mini_1 = 8`, `mini_2 = 10`.
   - The cost to connect these ropes is `8 + 10 = 18`.
   - Add this cost to the total cost: `totalCost = 10 + 18 = 28`.
   - Push the new rope of length `18` into the priority queue. The new queue is: `{12, 18}`.

4. **Third Iteration:**
   - Extract the two smallest ropes: `mini_1 = 12`, `mini_2 = 18`.
   - The cost to connect these ropes is `12 + 18 = 30`.
   - Add this cost to the total cost: `totalCost = 28 + 30 = 58`.
   - Now, only one rope remains in the queue, and the loop ends.

5. The final `totalCost` is `58`, which is returned as the minimum cost of connecting the ropes.

### Time Complexity:

1. **Inserting into the Priority Queue**:  
   Inserting `n` elements into the priority queue takes `O(log n)` time for each element, so inserting all elements will take `O(n log n)` time.

2. **Combining the Ropes**:  
   In each iteration, we extract two ropes and insert the combined rope back into the queue. Each extract and insert operation takes `O(log n)` time. Since there are `n - 1` iterations (as we combine the ropes until one remains), the total time for combining the ropes is `O(n log n)`.

3. **Overall Time Complexity**:  
   The overall time complexity is `O(n log n)`.

### Space Complexity:

- The primary space usage is by the priority queue, which stores all `n` rope lengths at once.
- The space complexity is therefore `O(n)` due to the priority queue.

### Summary:

- The **time complexity** of the solution is `O(n log n)` because each insert and extract operation in the priority queue takes `O(log n)` time, and there are `n` operations.
- The **space complexity** is `O(n)` because we store all `n` rope lengths in the priority queue.

This approach efficiently minimizes the cost of connecting ropes by always combining the smallest available ropes first, making it a typical greedy algorithm.

