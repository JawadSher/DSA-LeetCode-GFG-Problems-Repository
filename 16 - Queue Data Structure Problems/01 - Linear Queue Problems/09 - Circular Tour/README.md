<h1 align='center'>Circular - Tour</h1>

## Problem Statement

**Problem URL :** [Circular Tour](https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1)

![image](https://github.com/user-attachments/assets/b3c13d58-074f-407f-9515-a40fe6ae0f34)
![image](https://github.com/user-attachments/assets/d95d959e-5d97-4e6f-8524-bee64522ce64)

## Problem Explanation
You are given an array of petrol pumps where each petrol pump has a certain amount of petrol and a distance to the next petrol pump. Your goal is to determine if there is a starting petrol pump from which a truck can complete a circular tour of all petrol pumps without running out of petrol.

Each petrol pump is represented by a structure with two values:
- `petrol`: The amount of petrol available at the pump.
- `distance`: The distance to the next petrol pump.

The truck starts with an empty tank and can travel to the next pump only if it has enough petrol. If the truck cannot reach the next pump, it has to stop, and you need to find if a starting pump exists that allows a complete tour.

### Example

1. **Example 1:**
   - **Input:** `p[] = {{4, 6}, {6, 5}, {7, 3}, {4, 5}}`
   - **Output:** `1`
   - **Explanation:** Starting from the second pump (index 1), the truck can complete the circular tour.

2. **Example 2:**
   - **Input:** `p[] = {{1, 5}, {10, 3}, {3, 4}}`
   - **Output:** `-1`
   - **Explanation:** It is not possible to complete a tour starting from any pump.

### Approach

To solve this problem, we can use a greedy approach:

1. **Initialization:**
   - Start by initializing three variables: `balance`, `deficit`, and `start`.
     - `balance`: Keeps track of the petrol balance while traversing.
     - `deficit`: Stores the total deficit when the balance goes negative.
     - `start`: Indicates the index of the starting pump.

2. **Iterate Over Petrol Pumps:**
   - Loop through each petrol pump:
     - Update the `balance` by adding the petrol available at the pump and subtracting the distance to the next pump.
     - If `balance` goes negative, update the `deficit` and move the starting pump to the next index (`i + 1`). Reset the `balance` to 0.

3. **Final Check:**
   - After completing the loop, check if the total petrol minus the total distance is non-negative (`deficit + balance >= 0`). If true, return the starting index; otherwise, return `-1`.

## Problem Solution
```cpp
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int deficit = 0;
       int balance = 0;
       int start = 0;
       
       for(int i = 0; i < n; i++){
           balance += p[i].petrol - p[i].distance;
            
            if(balance < 0) {
                deficit += balance;
                
                start = i + 1;
                balance = 0;
                
            }
       }
       
       if(deficit + balance >= 0){
           return start;
       }
       
       return -1;
    }
};
```

## Problem Solution Explanation


1. **Initialization of Variables:**
   ```cpp
   int deficit = 0; // Initialize total deficit
   int balance = 0; // Initialize balance of petrol
   int start = 0;   // Initialize starting pump index
   ```

2. **Iterating Through Petrol Pumps:**
   ```cpp
   for(int i = 0; i < n; i++){
       balance += p[i].petrol - p[i].distance; // Update balance
   ```
   - The loop iterates over each petrol pump, adjusting the balance of petrol by adding the petrol available at the current pump and subtracting the distance to the next pump.

3. **Checking Balance:**
   ```cpp
   if(balance < 0) {
       deficit += balance; // Accumulate deficit
       start = i + 1; // Move start to the next pump
       balance = 0; // Reset balance
   }
   ```
   - If the balance drops below zero, it means the truck cannot reach the next pump starting from the current `start`. The deficit is updated, and `start` is moved to the next index.

4. **Final Check:**
   ```cpp
   if(deficit + balance >= 0) { // Check if a valid tour is possible
       return start; // Return starting index
   }
   ```
   - After traversing all pumps, the final check determines if it is possible to start from the identified `start` index.

5. **Returning Result:**
   ```cpp
   return -1; // Return -1 if no valid starting point exists
   ```
   - If no valid starting point was found, return `-1`.

### Complexity Analysis

1. **Time Complexity:**
   - The algorithm involves a single pass through the petrol pumps array, which is \( O(N) \), where \( N \) is the number of petrol pumps.

2. **Space Complexity:**
   - The algorithm uses a constant amount of space for the variables `deficit`, `balance`, and `start`, resulting in \( O(1) \) space complexity.

### Summary of Complexities

- **Time Complexity:** \( O(N) \)
- **Space Complexity:** \( O(1) \)

This approach efficiently finds the starting petrol pump from which a truck can complete a circular tour, ensuring optimal use of resources.
