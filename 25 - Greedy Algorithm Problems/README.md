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

Would you like to see more examples or dive into any specific problem in detail?
