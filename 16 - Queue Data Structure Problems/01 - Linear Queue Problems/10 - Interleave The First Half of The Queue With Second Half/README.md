<h1 align='center'>Interleave - The First - Half of - The Queue - With - Second - Half</h1>

## Problem Statement

**Problem URL :** [Interleave The First Half of the Queue with Second Half](https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/019916c4-c782-4c47-8a82-54487f1e8b04)
![image](https://github.com/user-attachments/assets/592d0669-2427-4a00-99dc-bd43747cd76f)

## Problem Explanation

You are given a queue of integers, and your task is to interleave the first half of the queue with the second half. This means that the first element of the queue should be followed by the first element of the second half, then the second element of the first half, followed by the second element of the second half, and so on.

### Example

1. **Example 1:**
   - **Input:** Queue: `[1, 2, 3, 4]`
   - **Output:** Interleaved Queue: `[1, 3, 2, 4]`
   - **Explanation:** The first half is `[1, 2]`, and the second half is `[3, 4]`. Interleaving them gives `[1, 3, 2, 4]`.

2. **Example 2:**
   - **Input:** Queue: `[10, 20, 30, 40, 50, 60]`
   - **Output:** Interleaved Queue: `[10, 40, 20, 50, 30, 60]`
   - **Explanation:** The first half is `[10, 20, 30]`, and the second half is `[40, 50, 60]`. Interleaving them gives `[10, 40, 20, 50, 30, 60]`.

### Approach

To solve this problem, we can use the following approach:

1. **Determine the Size of the Queue:**
   - Calculate the size of the queue and determine the halfway point (the number of elements in the first half).

2. **Push the First Half into a Stack:**
   - Use a stack to reverse the order of the first half of the queue. This will allow us to interleave it with the second half correctly.

3. **Rearrange the Queue:**
   - After reversing the first half, we can rearrange the queue:
     - First, push back the elements of the first half (from the stack) into the queue.
     - Then, rotate the queue to position the second half correctly.
     - Finally, interleave the elements from the stack with the remaining elements in the queue.

4. **Store and Return the Final Result:**
   - Once interleaved, store the final arrangement in a vector and return it.
## Problem Solution
```cpp
class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        stack<int> st;
        vector<int> v;
        
        int n = q.size() / 2;
        
        for(int i = 0; i < n; i++){
            st.push(q.front());
            q.pop();
        }
        
        while(!st.empty()){
            q.push(st.top());
            st.pop();
            
        }
        
        for(int i = 0; i < n; i++){
            q.push(q.front());
            q.pop();
        }
        
        for(int i = 0; i < n; i++){
            st.push(q.front());
            q.pop();
        }
        
        while(!st.empty()){
            q.push(st.top());
            st.pop();
            q.push(q.front());
            q.pop();
        }
        
        while(!q.empty()){
            v.push_back(q.front());
            q.pop();
        }
        
        return v;
    }
};
```

## Problem Solution Explanation

1. **Initialization of Stack and Vector:**
   ```cpp
   stack<int> st; // Initialize a stack to hold the first half
   vector<int> v; // Vector to store the result
   ```

2. **Determine the Size of the First Half:**
   ```cpp
   int n = q.size() / 2; // Calculate the size of the first half
   ```

3. **Push the First Half into the Stack:**
   ```cpp
   for(int i = 0; i < n; i++){
       st.push(q.front()); // Push the front element of the queue onto the stack
       q.pop(); // Remove the front element from the queue
   }
   ```
   - The loop runs `n` times, pushing the first half of the queue into the stack.

4. **Reverse the First Half:**
   ```cpp
   while(!st.empty()){
       q.push(st.top()); // Push the top element of the stack back into the queue
       st.pop(); // Remove the top element from the stack
   }
   ```
   - This step pushes the first half back into the queue in reversed order.

5. **Rotate the Queue:**
   ```cpp
   for(int i = 0; i < n; i++){
       q.push(q.front()); // Rotate the front element to the back
       q.pop(); // Remove the front element
   }
   ```
   - This step effectively moves the second half of the queue to the front.

6. **Push the Second Half into the Stack:**
   ```cpp
   for(int i = 0; i < n; i++){
       st.push(q.front()); // Push the front element (second half) onto the stack
       q.pop(); // Remove the front element from the queue
   }
   ```

7. **Interleave Elements from the Stack and Queue:**
   ```cpp
   while(!st.empty()){
       q.push(st.top()); // Push from stack
       st.pop(); // Remove from stack
       q.push(q.front()); // Push from queue
       q.pop(); // Remove from queue
   }
   ```
   - This loop interleaves the elements from the stack with the queue.

8. **Store the Final Arrangement:**
   ```cpp
   while(!q.empty()){
       v.push_back(q.front()); // Add the front element of the queue to the result vector
       q.pop(); // Remove the front element
   }
   ```

9. **Return the Result:**
   ```cpp
   return v; // Return the final interleaved vector
   ```

### Complexity Analysis

1. **Time Complexity:**
   - The algorithm involves multiple passes through the queue, leading to a linear time complexity of \( O(N) \), where \( N \) is the number of elements in the queue.

2. **Space Complexity:**
   - The algorithm uses additional space for the stack and the result vector, both of which can hold up to \( N/2 \) elements. Therefore, the space complexity is \( O(N) \).

### Summary of Complexities

- **Time Complexity:** \( O(N) \)
- **Space Complexity:** \( O(N) \)

This approach effectively interleaves the first half of the queue with the second half while maintaining a clear and efficient structure, utilizing both a stack and the original queue.
