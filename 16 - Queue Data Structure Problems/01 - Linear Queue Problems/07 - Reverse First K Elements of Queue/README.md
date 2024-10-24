<h1 align='center'>Reverse - First - K - Elements - of Queue</h1>

## Problem Statement

**Problem URL :** [Reverse First K Elements of Queue](https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1)

![image](https://github.com/user-attachments/assets/6235de32-6136-43fb-99c8-72795c58c07a)
![image](https://github.com/user-attachments/assets/4d5d4c30-3550-4627-9799-64409c7ffb97)

## Problem Explanation

Given a queue of integers and an integer \( k \), the task is to reverse the order of the first \( k \) elements in the queue while keeping the remaining elements in their original order.

### Example

1. **Example 1:**
   - **Input:**
     - Queue: `[1, 2, 3, 4, 5]`
     - \( k = 3 \)
   - **Output:**
     - Reversed Queue: `[3, 2, 1, 4, 5]`

2. **Example 2:**
   - **Input:**
     - Queue: `[10, 20, 30, 40, 50]`
     - \( k = 2 \)
   - **Output:**
     - Reversed Queue: `[20, 10, 30, 40, 50]`

3. **Example 3:**
   - **Input:**
     - Queue: `[7, 8, 9]`
     - \( k = 3 \)
   - **Output:**
     - Reversed Queue: `[9, 8, 7]`

### Approach

To solve this problem, we can use a stack to reverse the order of the first \( k \) elements. Here’s a step-by-step approach:

1. **Use a Stack:**
   - Push the first \( k \) elements of the queue into a stack. This will reverse their order since the stack is LIFO (Last-In-First-Out).

2. **Pop from Stack:**
   - Pop the elements from the stack and push them back into the queue. This restores the elements in reverse order.

3. **Rotate Remaining Elements:**
   - The remaining elements (from position \( k \) to the end of the queue) must maintain their original order. To achieve this, we can rotate these elements back to the end of the queue.

## Problem Solution
```cpp
class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        
        stack<int> st;
        
        for(int i = 0; i < k; i++){
            int val = q.front();
            q.pop();
            
            st.push(val);
        }
        
        while(!st.empty()){
            int val = st.top();
            st.pop();
            q.push(val);
        }
        
        int t = q.size() - k;
        
        while(t--){
            int val = q.front();
            q.pop();
            q.push(val);
        }
        
        return q;
    }
};
```

## Problem Solution Explanation

1. **Initialization:**
   ```cpp
   stack<int> st;
   ```
   - A stack `st` is initialized to hold the first \( k \) elements.

2. **Pop and Push into Stack:**
   ```cpp
   for(int i = 0; i < k; i++){
       int val = q.front();
       q.pop();
       st.push(val);
   }
   ```
   - This loop iterates \( k \) times. For each iteration:
     - The front element of the queue is retrieved and removed.
     - The retrieved element is pushed onto the stack.

   **Example Walkthrough:**
   - For the input queue `[1, 2, 3, 4, 5]` and \( k = 3 \):
     - After the loop, the stack will contain `[3, 2, 1]` and the queue will contain `[4, 5]`.

3. **Pop from Stack and Push Back to Queue:**
   ```cpp
   while(!st.empty()){
       int val = st.top();
       st.pop();
       q.push(val);
   }
   ```
   - This loop runs until the stack is empty:
     - The top element of the stack is retrieved and removed, then pushed back into the queue.

   **Example Walkthrough:**
   - Continuing with the previous example:
     - After this loop, the queue will now be `[4, 5, 3, 2, 1]`.

4. **Rotate Remaining Elements:**
   ```cpp
   int t = q.size() - k; 
   while(t--){
       int val = q.front();
       q.pop();
       q.push(val);
   }
   ```
   - Here, \( t \) is calculated as the number of remaining elements after the first \( k \).
   - This loop rotates the remaining elements back to the end of the queue.

   **Example Walkthrough:**
   - In our example, after calculating \( t \):
     - After this loop, the queue will be `[3, 2, 1, 4, 5]`.

5. **Return the Modified Queue:**
   ```cpp
   return q; 
   ```
   - Finally, the modified queue is returned.

### Complexity Analysis

1. **Time Complexity:**
   - **Popping First \( k \) Elements:** The first loop runs \( k \) times to pop elements from the queue and push them onto the stack.
     - **Time Complexity:** \( O(k) \)
   - **Popping from Stack and Pushing Back to Queue:** The while loop that pops elements from the stack runs \( k \) times.
     - **Time Complexity:** \( O(k) \)
   - **Rotating Remaining Elements:** The last loop runs \( N-k \) times.
     - **Time Complexity:** \( O(N-k) \)
   - Combining these parts:
     - **Total Time Complexity:** \( O(k) + O(k) + O(N-k) = O(N) \)

2. **Space Complexity:**
   - **Stack:** The stack holds at most \( k \) elements, so its space complexity is \( O(k) \).
   - The queue itself does not contribute additional complexity since we are modifying it in place.
   - Therefore, the total space complexity is:
     - **Total Space Complexity:** \( O(k) \)

### Summary of Complexities

- **Time Complexity:** \( O(N) \)
- **Space Complexity:** \( O(k) \)

This efficient approach ensures that we can reverse the first \( k \) elements in the queue while maintaining the order of the remaining elements effectively.
