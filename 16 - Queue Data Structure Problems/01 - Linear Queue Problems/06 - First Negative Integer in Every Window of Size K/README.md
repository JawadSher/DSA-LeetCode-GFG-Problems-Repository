<h1 align='center'>First - Negative - Integer - in Every - of Size - K</h1>

## Problem Statement

**Problem URL :** [First Negative Integer in Every Window of Size K](https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1)

![image](https://github.com/user-attachments/assets/17d55142-6e91-4123-94bd-54da32ebff83)
![image](https://github.com/user-attachments/assets/6cd0706e-220d-45d5-b10f-045d1b1957cb)

## Problem Explanation
**Description:**
Given an array of integers, the task is to find the first negative integer for each contiguous subarray (or window) of size \( K \). If there is no negative integer in the current window, return `0` for that window.

**Example:**
1. **Input:**  
   - `A = [-1, 2, -3, 4, -5]`
   - `N = 5` (number of elements in the array)
   - `K = 3` (size of the window)

2. **Output:**  
   - The first negative integers for each window: `[-1, -3, -5]`

   - **Explanation of the Windows:**
     - **Window 1:** `[-1, 2, -3]` → First negative is `-1`
     - **Window 2:** `[2, -3, 4]` → First negative is `-3`
     - **Window 3:** `[-3, 4, -5]` → First negative is `-5`

### Approach to Solve the Problem

The approach used in this solution employs a **deque** (double-ended queue) to keep track of the indices of negative integers in the current window of size \( K \). This allows efficient access to the first negative integer for each window.

Here’s a step-by-step breakdown of the approach:

1. **Initialize a Deque and Result Vector:**
   - Use a deque to store the indices of negative integers in the current window.
   - Initialize a vector to store the results.

2. **Process the First Window:**
   - Iterate through the first \( K \) elements of the array.
   - For each negative element found, add its index to the deque.

3. **Store the Result for the First Window:**
   - If the deque is not empty, add the first negative integer (element at the front of the deque) to the results.
   - If the deque is empty, add `0` to the results.

4. **Slide the Window:**
   - For each subsequent element in the array, do the following:
     - Remove indices from the front of the deque if they are out of the current window.
     - Add the index of the new negative element (if any) to the deque.
     - Again, check the deque for the first negative integer and update the results.

5. **Return the Results:**
   - After processing all elements, return the result vector.

### Complexity Analysis
- **Time Complexity:** \(O(N)\), where \(N\) is the number of elements in the array. Each element is processed at most twice (once added and once removed from the deque).
- **Space Complexity:** \(O(K)\), for the deque that stores the indices of negative numbers in the current window.
  
## Problem Solution
```cpp
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K){ 
        
        deque<long long int> dq;
        vector<long long> ans;
        
        for(int i = 0; i < K; i++){
            if(A[i] < 0) dq.push_back(i);
        }
        
        if(dq.size() > 0) ans.push_back(A[dq.front()]);
        else ans.push_back(0);
        
        
        for(int i = K; i < N; i++){
            if(!dq.empty() && i - dq.front() >= K) dq.pop_front();
            
            if(A[i] < 0) dq.push_back(i);
            
            if(dq.size() > 0) ans.push_back(A[dq.front()]);
            else ans.push_back(0);
        }
        
        
        return ans;
                                                 
 }
```

## Problem Solution Explanation

1. **Function Declaration:**
   ```cpp
   vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
   ```
   - This defines a function that takes an array of integers `A`, the number of elements `N`, and the size of the window `K`. It returns a vector of long long integers.

2. **Initialize Deque and Result Vector:**
   ```cpp
   deque<long long int> dq;
   vector<long long> ans;
   ```
   - A deque `dq` is initialized to store indices of negative integers, and a vector `ans` is initialized to store the results.

3. **Process the First Window:**
   ```cpp
   for(int i = 0; i < K; i++){
       if(A[i] < 0) dq.push_back(i);
   }
   ```
   - This loop processes the first \( K \) elements. If an element is negative, its index is added to the deque.

4. **Store Result for the First Window:**
   ```cpp
   if(dq.size() > 0) ans.push_back(A[dq.front()]);
   else ans.push_back(0);
   ```
   - After checking the first window, if the deque is not empty, the first negative integer (element at the front) is added to the results. If empty, `0` is added.

5. **Slide the Window:**
   ```cpp
   for(int i = K; i < N; i++){
       if(!dq.empty() && i - dq.front() >= K) dq.pop_front();
       if(A[i] < 0) dq.push_back(i);
       if(dq.size() > 0) ans.push_back(A[dq.front()]);
       else ans.push_back(0);
   }
   ```
   - This loop processes the remaining elements, sliding the window one position to the right. Indices that are out of the current window are removed from the front of the deque. New negative elements are added, and the results are updated accordingly.

6. **Return the Result Vector:**
   ```cpp
   return ans;
   ```
   - Finally, the function returns the vector containing the first negative integers for each window.

### Output Examples

Here are some output examples for the `First Negative Integer in Every Window of Size K` problem using the provided implementation:

### Example 1
**Input:**
```cpp
long long A[] = {-1, 2, -3, 4, -5};
long long N = 5;
long long K = 3;

vector<long long> result = printFirstNegativeInteger(A, N, K);
```

**Output:**
```
[-1, -3, -5]
```

### Example 2
**Input:**
```cpp
long long A[] = {12, -1, -7, 8, -15, 30, 16, 28};
long long N = 8;
long long K = 3;

vector<long long> result = printFirstNegativeInteger(A, N, K);
```

**Output:**
```
[-1, -1, -15, -15, 0]
```

### Example 3
**Input:**
```cpp
long long A[] = {1, 2, 3, 4, 5};
long long N = 5;
long long K = 2;

vector<long long> result = printFirstNegativeInteger(A, N, K);
```

**Output:**
```
[0, 0, 0, 0]
```

### Example 4
**Input:**
```cpp
long long A[] = {-5, 2, -1, -4, 3, -2};
long long N = 6;
long long K = 4;

vector<long long> result = printFirstNegativeInteger(A, N, K);
```

**Output:**
```
[-5, -1, -1]
```

### Example 5
**Input (All Negative):**
```cpp
long long A[] = {-1, -2, -3, -4};
long long N = 4;
long long K = 2;

vector<long long> result = printFirstNegativeInteger(A, N, K);
```

**Output:**
```
[-1, -2, -3]
```

### Explanation of Outputs

- Each example shows how the function processes the input array and produces a vector of the first negative integer for each window of size \( K \). 
- If no negative integer exists in a window, the output is `0`. 
- The results are stored in the order of the windows processed.

  Sure! Here’s a detailed analysis of the time and space complexities for the problem **"First Negative Integer in Every Window of Size K."**

### Time Complexity

The time complexity of the solution can be analyzed as follows:

1. **Processing the First Window:**
   - The loop that processes the first \( K \) elements runs \( K \) times. In this loop, we check if each element is negative and possibly add it to the deque.
   - **Time Complexity:** \( O(K) \)

2. **Sliding the Window:**
   - The second loop that processes the remaining elements runs \( N-K \) times, where \( N \) is the total number of elements in the array.
   - Inside this loop, we perform the following operations:
     - **Checking and Removing from the Deque:** Removing an index from the front of the deque can happen at most once for each element in the array (in the worst case, every element could be added and removed). Thus, the total operations for removing elements will not exceed \( N \).
     - **Adding to the Deque:** Similarly, adding a negative index to the deque occurs at most \( N \) times.
     - **Accessing the Front Element:** This operation (getting the first negative integer) is \( O(1) \).

   - Therefore, each element is processed at most twice (once added and once removed from the deque).
   - **Time Complexity for Sliding the Window:** \( O(N) \)

Combining both parts:
- **Total Time Complexity:** \( O(K) + O(N) = O(N) \)

### Space Complexity

The space complexity can be analyzed as follows:

1. **Deque:**
   - The deque `dq` stores indices of negative integers from the current window. In the worst case, all elements in the current window could be negative.
   - Therefore, the maximum size of the deque could be \( K \) (the size of the window).
   - **Space Complexity for Deque:** \( O(K) \)

2. **Result Vector:**
   - The result vector `ans` stores the first negative integer for each of the \( N-K+1 \) windows.
   - The size of the result vector is \( N-K+1 \), which is \( O(N) \) in the worst case.

Overall, considering both the deque and the result vector:
- **Total Space Complexity:** \( O(K) + O(N) = O(N) \)

### Summary of Complexities

- **Time Complexity:** \( O(N) \)
- **Space Complexity:** \( O(K) \) for the deque, with an overall impact of \( O(N) \) considering the result vector as well.

This efficient approach ensures that we can handle large inputs within a reasonable time frame while managing space effectively.
