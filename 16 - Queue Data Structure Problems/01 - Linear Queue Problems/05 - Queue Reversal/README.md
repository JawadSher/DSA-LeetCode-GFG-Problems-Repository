<h1 align='center'>Queue - Reversal</h1>

## Problem Statement

**Problem URL :** [Queue Reversal](https://www.geeksforgeeks.org/problems/queue-reversal/1)

![image](https://github.com/user-attachments/assets/08794330-7195-4b98-aa0d-70afced89c37)
![image](https://github.com/user-attachments/assets/f6ecd42d-b9e8-4f55-b933-dfabee6d70ad)

## Problem Explanation
**Description:**
The task is to reverse a given queue. A queue is a data structure that follows the First In First Out (FIFO) principle, meaning the first element added to the queue will be the first one to be removed. The reversal of a queue means that the first element will become the last, and the last element will become the first.

**Example:**
1. **Input:** `queue = [1, 2, 3, 4, 5]`
   - The elements of the queue are `1` at the front and `5` at the back.
2. **Output:** `queue = [5, 4, 3, 2, 1]`
   - After reversal, the first element is `5`, and the last element is `1`.

### Approach to Solve the Problem

The approach used in the given solution is **recursion**. The idea is to pop elements from the queue until it's empty, and then push them back in reverse order during the backtracking phase of recursion. 

Here’s a step-by-step breakdown of the approach:
1. **Base Case:** If the queue is empty, return the queue.
2. **Recursive Case:**
   - Store the front element of the queue.
   - Remove the front element (pop) from the queue.
   - Call the `rev` function recursively on the remaining queue.
   - After the recursive call returns the reversed queue, push the stored element back into the queue.

### Complexity Analysis
- **Time Complexity:** \(O(n)\), where \(n\) is the number of elements in the queue. Each element is processed once (popped and pushed).
- **Space Complexity:** \(O(n)\) for the recursive call stack. Each recursive call adds a layer to the stack until the base case is reached.

## Problem Solution
```cpp
class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        if(q.empty()) return q;
        
        int element = q.front();
        q.pop();
        
        q = rev(q);
        
        q.push(element);
        
        return q;
    }
};
```

## Problem Solution Explanation

1. **Class Declaration:**
   ```cpp
   class Solution
   ```
   - This defines a class named `Solution`, which encapsulates the method to reverse the queue.

2. **Public Method Declaration:**
   ```cpp
   public:
   queue<int> rev(queue<int> q)
   ```
   - This declares a public method `rev` that takes a `queue<int>` as an argument and returns a `queue<int>`. The parameter `q` is the queue to be reversed.

3. **Base Case:**
   ```cpp
   if(q.empty()) return q;
   ```
   - This checks if the queue `q` is empty. If it is, it returns the empty queue immediately. This serves as the base case for the recursion.

4. **Store the Front Element:**
   ```cpp
   int element = q.front();
   ```
   - This retrieves the front element of the queue and stores it in the variable `element`.

5. **Pop the Front Element:**
   ```cpp
   q.pop();
   ```
   - This removes the front element from the queue.

6. **Recursive Call:**
   ```cpp
   q = rev(q);
   ```
   - The method calls itself recursively with the updated queue (which now does not include the front element). This continues until the queue becomes empty.

7. **Push the Stored Element:**
   ```cpp
   q.push(element);
   ```
   - After the recursive call completes, it pushes the stored `element` back onto the queue. This is effectively placing the previously front element at the back of the reversed queue.

8. **Return the Reversed Queue:**
   ```cpp
   return q;
   ```
   - Finally, the method returns the reversed queue.

### Example 1
**Input:**
```cpp
queue<int> q;
q.push(1);
q.push(2);
q.push(3);
q.push(4);
q.push(5);

Solution sol;
queue<int> reversedQueue = sol.rev(q);
```

**Output:**
```
Reversed Queue: [5, 4, 3, 2, 1]
```

### Example 2
**Input:**
```cpp
queue<int> q;
q.push(10);
q.push(20);
q.push(30);
q.push(40);

Solution sol;
queue<int> reversedQueue = sol.rev(q);
```

**Output:**
```
Reversed Queue: [40, 30, 20, 10]
```

### Example 3
**Input:**
```cpp
queue<int> q;
q.push(100);
q.push(200);
q.push(300);

Solution sol;
queue<int> reversedQueue = sol.rev(q);
```

**Output:**
```
Reversed Queue: [300, 200, 100]
```

### Example 4
**Input:**
```cpp
queue<int> q;
q.push(1);
q.push(2);
q.push(3);
q.push(4);
q.push(5);
q.push(6);

Solution sol;
queue<int> reversedQueue = sol.rev(q);
```

**Output:**
```
Reversed Queue: [6, 5, 4, 3, 2, 1]
```

### Example 5
**Input (Empty Queue):**
```cpp
queue<int> q;

Solution sol;
queue<int> reversedQueue = sol.rev(q);
```

**Output:**
```
Reversed Queue: []
```

### Explanation of Outputs

- In each of the above examples, the original queue is printed in the order of elements that were inserted (FIFO order). The reversed queue is the output after applying the `rev` function, demonstrating that the first element is now at the back of the queue, and the last element is at the front.
- The last example shows that when an empty queue is provided as input, the output remains an empty queue.
  
### Conclusion
This implementation of queue reversal uses recursion to achieve the desired result effectively. The time complexity is linear in terms of the number of elements in the queue, and the space complexity is also linear due to the recursion depth.
