<h1 align="center">Nth - Fibonacci - Number - Example</h1>

## Problem Statement
**Problem URL :** [Nth Fibonacci Number](https://www.geeksforgeeks.org/problems/nth-fibonacci-number1335/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/4f743224-0c5c-4b88-a02d-6cf06513ffa0)

## Problem Explanation
The task is to find the Nth Fibonacci number. The Fibonacci sequence is a series of numbers where each number is the sum of the two preceding ones, starting from 0 and 1. Therefore, the sequence starts: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, and so on.

You are required to write a function to compute the Nth Fibonacci number in this sequence.

### What is a Fibonacci Number?
The Fibonacci sequence is defined as:
- F(0) = 0
- F(1) = 1
- For n > 1, F(n) = F(n-1) + F(n-2)

This means that each number in the sequence is the sum of the two preceding ones.

### Calculation of Fibonacci Numbers:
Let's break it down step-by-step.

#### Step 1: Base Cases
There are two base cases in the Fibonacci sequence:
- If N = 0, the Fibonacci number is 0.
- If N = 1, the Fibonacci number is 1.

#### Step 2: Recursive Definition
For any other number N (N > 1), the Fibonacci number is defined as the sum of the two preceding numbers:
- F(N) = F(N-1) + F(N-2)

## What is Dynamic Programming
Dynamic Programming (DP) is a problem-solving technique used to solve problems with overlapping subproblems and optimal substructure. It avoids redundant computations by storing the results of subproblems, making it more efficient than plain recursion.

### **Core Concepts of Dynamic Programming**

#### 1. **Overlapping Subproblems**  
   Subproblems are solved multiple times during the computation.  
   Example:  
   Computing Fibonacci numbers recursively involves solving \( F(n-1) \) and \( F(n-2) \), but \( F(n-1) \) and \( F(n-2) \) have common subproblems like \( F(n-3) \), leading to redundant work.

#### 2. **Optimal Substructure**  
   A problem exhibits optimal substructure if its solution can be derived from solutions of smaller subproblems.  
   Example:  
   The shortest path between two nodes in a graph can be computed by finding the shortest paths between intermediate nodes.

### **Three Key DP Techniques**

### **1. Top-Down Approach (Recursion + Memoization)**

The top-down approach involves solving problems recursively while storing results of already-computed subproblems in a cache or a table. This process is called **memoization**.

- **How It Works**:  
  - Start solving the problem from the largest input.
  - Store the result of each subproblem in a memoization table.
  - Before solving a subproblem, check the table to see if it has already been solved.

- **Example: Fibonacci Sequence**  
  The Fibonacci sequence is defined as:  
  \( F(n) = F(n-1) + F(n-2) \), where \( F(0) = 0, F(1) = 1 \).

##### Source Code
```cpp
#include <vector>
using namespace std;

class Solution {
  public:
    int fibonacci(int n, vector<int>& dp) {
        // Base cases
        if (n == 0 || n == 1) return n;

        // If already computed, return the cached result
        if (dp[n] != -1) return dp[n];

        // Compute the value recursively and store it in dp[n]
        dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
        return dp[n];
    }

    int nthFibonacci(int n) {
        vector<int> dp(n + 1, -1); // Initialize memoization table
        return fibonacci(n, dp);
    }
};
```

- **Advantages**: Efficient compared to plain recursion due to reduced recomputation.
- **Disadvantages**: Uses extra space for the memoization table.



### **2. Bottom-Up Approach (Tabulation)**

The bottom-up approach involves solving all subproblems iteratively, starting from the smallest subproblems and building up to the desired solution. This is called **tabulation** because it uses a table to store intermediate results.

- **How It Works**:  
  - Define a table (array or matrix) to store the results of subproblems.
  - Solve the smallest subproblem first, then use its result to solve larger subproblems.

- **Example: Fibonacci Sequence**

##### Source Code
```cpp
#include <vector>
using namespace std;

class Solution {
  public:
    int nthFibonacci(int n) {
        vector<int> dp(n + 1); // Table to store Fibonacci numbers
        dp[0] = 0; // Base case
        dp[1] = 1; // Base case

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2]; // Use previously computed values
        }

        return dp[n];
    }
};
```

- **Advantages**: Avoids recursion and stack overflow.
- **Disadvantages**: Requires space proportional to the size of the table.


### **3. Space-Optimized Approach**

In many problems, only a few values from the table are required at any given time. We can optimize the space by storing only the necessary states.

- **How It Works**:  
  - Reduce the size of the table by keeping only the last few values needed for the computation.

- **Example: Fibonacci Sequence**

##### Source Code
```cpp
class Solution {
  public:
    int nthFibonacci(int n) {
        if (n == 0) return 0; // Base case
        if (n == 1) return 1; // Base case

        int a = 0, b = 1; // Store only the last two Fibonacci numbers
        int current;

        for (int i = 2; i <= n; i++) {
            current = a + b; // Compute the current Fibonacci number
            a = b; // Update a to the previous b
            b = current; // Update b to the current value
        }

        return current;
    }
};
```

- **Advantages**: Significantly reduces space complexity.
- **Disadvantages**: Slightly harder to implement compared to the tabulation approach.



### **Comparison of Techniques**

| **Technique**            | **Space Complexity** | **Time Complexity** | **Approach**                           |
|-|-|-|-|
| **Top-Down (Memoization)**| \( O(n) \)          | \( O(n) \)          | Recursive with caching                |
| **Bottom-Up (Tabulation)**| \( O(n) \)          | \( O(n) \)          | Iterative, builds solution step-by-step |
| **Space-Optimized**       | \( O(1) \)          | \( O(n) \)          | Iterative, stores only needed values   |


## Why Not Recursive Approach
##### source code
```cpp
class Solution {
  public:
    int nthFibonacci(int n) {
        // Base case: If n is 0 or 1, return n directly.
        // F(0) = 0 and F(1) = 1 are the first two terms of the Fibonacci sequence.
        if (n == 0 || n == 1) 
            return n;

        // Recursive case:
        // The nth Fibonacci number is the sum of the (n-1)th and (n-2)th Fibonacci numbers.
        // Recursively calculate the values for smaller subproblems.
        return nthFibonacci(n - 1) + nthFibonacci(n - 2);
    }
};
```

The **recursive approach** for solving problems like the Fibonacci sequence may seem intuitive and elegant, but it has significant drawbacks that make it inefficient for larger inputs. Let’s break this down:

### **Reasons to Avoid the Recursive Approach**

#### 1. **Exponential Time Complexity**
   - The time complexity of the recursive Fibonacci solution is **O(2^n)**. This happens because each call to the function makes two additional calls, leading to an exponential growth in the number of calls.
   - Example: Calculating \( F(5) \) involves computing \( F(4) \) and \( F(3) \), but \( F(4) \) also computes \( F(3) \) and \( F(2) \), leading to redundant calculations.

#### 2. **Redundant Calculations**
   - The same subproblems are solved repeatedly. For example:
     - To compute \( F(5) \), you compute \( F(4) \) and \( F(3) \).
     - Computing \( F(4) \) requires \( F(3) \) and \( F(2) \), so \( F(3) \) is calculated twice.
   - This redundancy increases with \( n \), wasting computation time.

#### 3. **Stack Overflow (Memory Constraints)**
   - Recursive calls consume stack space proportional to the depth of the recursion. For Fibonacci, the depth of the recursion is \( n \), so the space complexity is **O(n)**.
   - For very large \( n \), this can lead to **stack overflow errors**.

#### 4. **Lack of Intermediate Storage**
   - In the recursive approach, no storage (memoization) is used to save the results of already-computed subproblems. This makes it inefficient compared to dynamic programming approaches.


### **Comparison with Dynamic Programming**

| **Aspect**          | **Recursive Approach**       | **Dynamic Programming**            |
|----------------------|------------------------------|-------------------------------------|
| **Time Complexity**  | \( O(2^n) \)                | \( O(n) \)                         |
| **Space Complexity** | \( O(n) \) (due to the call stack) | \( O(n) \) (or \( O(1) \) if space optimized) |
| **Redundancy**       | High (repeated subproblems) | Avoided (results stored and reused) |
| **Usability**        | Simple but inefficient      | Slightly complex but highly efficient |


### **Example: Recursive Redundancy**
To calculate \( F(5) \):

#### Recursive Tree:
```
          F(5)
         /    \
      F(4)    F(3)
     /   \     /   \
  F(3)  F(2) F(2) F(1)
  /  \
F(2) F(1)
```

- **Redundancy**: \( F(3) \) is computed **twice**, \( F(2) \) is computed **three times**, and the redundancy increases exponentially as \( n \) grows.


### **When Is Recursion Acceptable?**
The recursive approach can be used for:
- **Small inputs**: When \( n \) is small (e.g., \( n \leq 10 \)), the inefficiency is negligible.
- **Educational purposes**: Useful for understanding the problem structure and basic recursion.
- **Tree-like problems**: Where each recursive call generates unique subproblems without overlap.

### **Conclusion**
The recursive approach for problems like Fibonacci is not practical for large inputs due to exponential time complexity and stack overflow issues. It is better to use **dynamic programming** with memoization (Top-Down) or tabulation (Bottom-Up) to solve these problems efficiently.
