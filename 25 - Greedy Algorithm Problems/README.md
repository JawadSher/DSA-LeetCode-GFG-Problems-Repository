<h1 align='center'>GREEDY - ALGORITHM - PROBLEMS</h1>

The **Greedy Algorithm** is a problem-solving technique used in optimization problems. It works by making the **locally optimal choice** at each step with the hope that these local choices will lead to a **globally optimal solution**. 

In simpler terms, the algorithm chooses the best immediate option without considering the bigger picture or the overall problem space.

### **Key Characteristics of the Greedy Algorithm:**

1. **Greedy Choice Property:** 
   - A global optimal solution can be arrived at by choosing local optimal solutions at each step.
   
2. **Optimal Substructure:**
   - A problem exhibits optimal substructure if an optimal solution can be constructed from optimal solutions of its subproblems.

3. **Non-revisiting Decisions:**
   - Once a choice is made, it is never revisited.

### **Steps in the Greedy Algorithm:**
1. **Identify the Problem**:
   - Confirm the problem exhibits the greedy choice property and optimal substructure.
   
2. **Sort or Arrange Data**:
   - Sort the elements involved based on certain criteria, such as value, weight, or priority.

3. **Iterative Selection**:
   - At each step, pick the most optimal choice.

4. **Check Feasibility**:
   - Verify if the choice meets the constraints of the problem.

5. **Build the Solution**:
   - Continue making choices until the solution is complete.

### **Examples of the Greedy Algorithm:**

#### **1. Activity Selection Problem**
**Problem Statement**:
Given a set of activities with their start and end times, select the maximum number of activities that can be performed without overlapping.

**Steps**:
- Sort activities by their end time.
- Always select the activity that finishes first and does not overlap with the previously selected activity.

**Example**:
| Activity | Start Time | End Time |
|---|---|---|
| A1       | 1          | 4        |
| A2       | 3          | 5        |
| A3       | 0          | 6        |
| A4       | 5          | 7        |
| A5       | 8          | 9        |

**Solution**:
- Sort by end time: ( A1, A2, A4, A5, A3 ).
- Pick ( A1 ) (ends at 4), skip ( A2 ) (overlaps with ( A1 )), pick ( A4 ), and finally pick ( A5 ).

#### **2. Fractional Knapsack Problem**
**Problem Statement**:
Given weights and values of ( n ) items, maximize the total value in a knapsack with a limited capacity ( W ). You can take fractions of an item.

**Steps**:
- Calculate the value-to-weight ratio (( v/w )) for each item.
- Sort items by this ratio in descending order.
- Take items greedily until the capacity is filled.

**Example**:
| Item | Value (( v )) | Weight (( w )) | ( v/w ) |
|---|---|---|---|
| I1   | 60              | 10               | 6         |
| I2   | 100             | 20               | 5         |
| I3   | 120             | 30               | 4         |

**Knapsack Capacity**: ( W = 50 )

**Solution**:
- Take ( I1 ) entirely (( w = 10, v = 60 )).
- Take ( I2 ) entirely (( w = 20, v = 100 )).
- Take ( frac{2/3} ) of ( I3 ) (( w = 20, v = 80 )).

**Total Value**: ( 60 + 100 + 80 = 240 ).

#### **3. Huffman Encoding**
**Problem Statement**:
Build a binary tree to encode data such that the overall size of the encoded data is minimized.

**Steps**:
- Build a priority queue with the frequencies of characters.
- Iteratively combine the two smallest frequencies into a single node until one node remains.

**Example**:
| Character | Frequency |
|---|---|
| A         | 5         |
| B         | 9         |
| C         | 12        |
| D         | 13        |
| E         | 16        |
| F         | 45        |

**Solution**:
1. Combine ( A (5) ) and ( B (9) ) into ( AB (14) ).
2. Combine ( AB (14) ) and ( C (12) ) into ( ABC (26) ).
3. Continue until a single tree is formed.

### **Advantages of Greedy Algorithms**
- **Simplicity**: Easy to implement.
- **Efficiency**: Often faster due to fewer computations (usually ( O(n log n) )).

### **Limitations of Greedy Algorithms**
- **May Not Guarantee Optimal Solutions**:
   - Greedy algorithms don’t always produce the global optimum.
   - For example, in the **0/1 Knapsack Problem**, a greedy approach fails to find the correct solution.
   
- **Problem Specific**:
   - Requires the problem to exhibit greedy-choice property and optimal substructure.

### **When to Use Greedy Algorithms?**
- Problems where greedy choice leads to an optimal solution.
- Scenarios that allow breaking problems into simpler subproblems.
- When performance and simplicity are priorities. 

## Repository Content
<p>
<img src="https://img.shields.io/badge/problems%20count-00-orange?logo=leetcode" alt="LeetCode">
<img src="https://img.shields.io/badge/problems%20count-11-darkgreen?logo=geeksforGeeks" alt="GeeksforGeeks">
<img src="https://img.shields.io/badge/total%20problems%20count-11-blue" alt="Problem Count"> 
</p>


| No  | Problem Name                                                                 | Description                                                                 | LeetCode | GFG  |
|-----|-------------------------------------------------------------------------------|-----------------------------------------------------------------------------|----------|------|
| 01  | [N Meetings in One Room](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/25%20-%20Greedy%20Algorithm%20Problems/01%20-%20N%20Meetings%20in%20One%20Room) | Find the maximum number of meetings that can be conducted in one room.       | Non      | [Link](https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1)  |
| 02  | [Maximum Meetings in One Room](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/25%20-%20Greedy%20Algorithm%20Problems/02%20-%20Maximum%20Meetings%20in%20One%20Room) | Maximize the number of meetings in a single room by scheduling them optimally. | Non      | [Link](https://www.geeksforgeeks.org/problems/maximum-meetings-in-one-room/0)  |
| 03  | [Shop in Candy Store](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/25%20-%20Greedy%20Algorithm%20Problems/03%20-%20Shop%20in%20Candy%20Store) | Select the most expensive candies from a store, keeping the total cost within a budget. | Non      | [Link](https://www.geeksforgeeks.org/problems/shop-in-candy-store1145/1)  |
| 04  | [Check if it is possible to survive on Island](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/25%20-%20Greedy%20Algorithm%20Problems/04%20-%20Check%20if%20it%20is%20possible%20to%20survive%20on%20Island) | Check if it's possible to survive on an island based on available resources. | Non      | [Link](https://www.geeksforgeeks.org/problems/check-if-it-is-possible-to-survive-on-island4922/0)  |
| 05  | [Reverse Words](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/25%20-%20Greedy%20Algorithm%20Problems/05%20-%20Reverse%20Words) | Reverse the order of words in a given string.                               | Non      | [Link](https://www.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)  |
| 06  | [Chocolate Distribution Problem](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/25%20-%20Greedy%20Algorithm%20Problems/06%20-%20Chocolate%20Distribution%20Problem) | Distribute chocolates in such a way that the minimum difference between the maximum and minimum chocolates is minimized. | Non      | [Link](https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1)  |
| 07  | [Minimum Cost of Ropes](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/25%20-%20Greedy%20Algorithm%20Problems/07%20-%20Minimum%20Cost%20of%20Ropes) | Minimize the cost of connecting ropes of different lengths.                  | Non      | [Link](https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1)  |
| 08  | [Huffman Encoding](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/25%20-%20Greedy%20Algorithm%20Problems/08%20-%20Huffman%20Encoding) | Perform data compression using Huffman encoding.                             | Non      | [Link](https://www.geeksforgeeks.org/problems/huffman-encoding3345/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)  |
| 09  | [Fractional Knapsack](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/25%20-%20Greedy%20Algorithm%20Problems/09%20-%20Fractional%20Knapsack) | Solve the knapsack problem by taking fractional items to maximize the total value. | Non      | [Link](https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)  |
| 10  | [Activity Selection](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/25%20-%20Greedy%20Algorithm%20Problems/10%20-%20Activity%20Selection) | Select the maximum number of activities that can be performed by a single person, given start and finish times. | Non      | [Link](https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1)  |
| 11  | [Job Sequencing Problem](https://github.com/JawadSher/DSA-LeetCode-GFG-Problems-Repository/tree/main/25%20-%20Greedy%20Algorithm%20Problems/11%20-%20Job%20Sequencing%20Problem) | Sequence jobs in a way that maximizes profit, subject to deadlines.           | Non      | [Link](https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1)  |

---
Happy Coding! 😊

