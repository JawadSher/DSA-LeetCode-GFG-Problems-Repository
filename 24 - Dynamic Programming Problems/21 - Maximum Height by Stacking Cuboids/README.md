<h1 align="center">Maximum - Height by - Stacking - Cuboids</h1>


## Problem Statement

**Problem URL :** [Maximum Height By Stacking Cuboids](https://leetcode.com/problems/maximum-height-by-stacking-cuboids/description/)

![image](https://github.com/user-attachments/assets/9ac1db31-559d-45a6-aa42-d7274ffab90f)

### Problem Explanation
You are given a set of cuboids. Each cuboid has three dimensions: height, width, and length. The task is to stack these cuboids on top of each other to maximize the height of the stack. However, there are two restrictions:
1. A cuboid can be rotated in any way, meaning you can swap the dimensions (height, width, length) to create different orientations.
2. A cuboid can only be placed on top of another cuboid if its width and length (after rotation) are both smaller than or equal to the cuboid below it.

**Objective**:  
Find the maximum height of the tower that can be formed by stacking the cuboids.

### Step-by-Step Explanation of the Problem:

#### Step 1: Understanding Cuboid Rotation
For each cuboid, we can rotate it in three different ways. Each rotation changes which dimension is considered the height, width, and length. Let's take an example:

- **Cuboid A**: Dimensions are [4, 1, 4].  
  It can be rotated to produce the following three possible orientations:
  - Rotation 1: [1, 4, 4] → (height = 1, width = 4, length = 4)
  - Rotation 2: [4, 1, 4] → (height = 4, width = 1, length = 4)
  - Rotation 3: [4, 4, 1] → (height = 4, width = 4, length = 1)

#### Step 2: Stacking the Cuboids
The goal is to stack these cuboids in a way that maximizes the total height. The rules for stacking are:
- A cuboid can only be placed on top of another if:
  - Its width is less than or equal to the width of the cuboid below it.
  - Its length is less than or equal to the length of the cuboid below it.

For example:
- If cuboid A is [1, 4, 4] and cuboid B is [2, 5, 6], cuboid A can be placed on cuboid B because both the width (1 <= 2) and length (4 <= 5) of cuboid A are less than or equal to those of cuboid B.

#### Step 3: Rotating All Cuboids
To ensure we can stack cuboids in any orientation, we generate all possible rotations of each cuboid. Then, we try to stack them based on their dimensions.

#### Step 4: Dynamic Programming Approach
The approach uses dynamic programming (DP) to solve this problem. We can treat this as a "Longest Increasing Subsequence" problem where:
- Each cuboid’s height is considered as a potential "value" in a stack.
- We check if a cuboid can be placed on top of another cuboid (based on width and length).
- We compute the maximum height achievable for each cuboid by including it in the stack.

#### Example to Illustrate the Problem:

Consider the following cuboids:

```cpp
cuboids = [[4, 1, 4], [6, 2, 5], [7, 3, 6]]
```

1. **Rotation**:  
   For each cuboid, we generate all possible rotations:

   - Cuboid 1: `[4, 1, 4]` → Rotations are `[1, 4, 4]`, `[4, 1, 4]`, `[4, 4, 1]`
   - Cuboid 2: `[6, 2, 5]` → Rotations are `[2, 5, 6]`, `[5, 2, 6]`, `[6, 5, 2]`
   - Cuboid 3: `[7, 3, 6]` → Rotations are `[3, 6, 7]`, `[6, 3, 7]`, `[7, 6, 3]`

2. **Sorting the Dimensions**:  
   We standardize each cuboid by sorting the dimensions in ascending order, ensuring that each cuboid is represented in a consistent way (width <= length <= height).

   After sorting each cuboid:
   - Cuboid 1: `[1, 4, 4]`
   - Cuboid 2: `[2, 5, 6]`
   - Cuboid 3: `[3, 6, 7]`

3. **Sorting All Cuboids**:  
   Next, we sort all cuboids lexicographically based on their dimensions to make it easier to compare and stack them.

   After sorting:
   - Sorted cuboids: `[[1, 4, 4], [2, 5, 6], [3, 6, 7]]`

4. **Applying Dynamic Programming**:  
   Now we use dynamic programming to compute the maximum height achievable by stacking the cuboids.

   - **Initialization**:  
     Start with the base case where the height of the stack for each cuboid is its own height. So, `dp = [4, 6, 7]` initially.
   
   - **Checking for Stackability**:  
     For each cuboid `i`, check if it can be placed on top of any previous cuboid `j` (i.e., the dimensions of cuboid `j` must be smaller or equal to those of cuboid `i`).
     
     - For cuboid 1 (`[2, 5, 6]`), check if cuboid 0 (`[1, 4, 4]`) can be placed under it. Since `1 <= 2`, `4 <= 5`, and `4 <= 6`, cuboid 0 can be placed under cuboid 1. So, update the height:  
       `dp[1] = max(dp[1], dp[0] + 6) = max(6, 4 + 6) = 10`.
     
     - For cuboid 2 (`[3, 6, 7]`), check if cuboid 0 (`[1, 4, 4]`) can be placed under cuboid 2. Since `1 <= 3`, `4 <= 6`, and `4 <= 7`, cuboid 0 can be placed under cuboid 2. So, update the height:  
       `dp[2] = max(dp[2], dp[0] + 7) = max(7, 4 + 7) = 11`.

     - For cuboid 2 (`[3, 6, 7]`), check if cuboid 1 (`[2, 5, 6]`) can be placed under cuboid 2. Since `2 <= 3`, `5 <= 6`, and `6 <= 7`, cuboid 1 can be placed under cuboid 2. So, update the height:  
       `dp[2] = max(dp[2], dp[1] + 7) = max(11, 10 + 7) = 17`.

5. **Final Result**:  
   The maximum height of the stack is the maximum value in the `dp` array. So, `max(dp[0], dp[1], dp[2]) = max(4, 10, 17) = 17`.

### Explanation of the Approach Used in the Given Code:

1. **Sorting the Cuboids**:  
   Each cuboid is first rotated to generate all possible orientations, and the dimensions are sorted in ascending order. This ensures that cuboids are consistently represented.

2. **Dynamic Programming (DP)**:  
   A DP array is used to store the maximum stackable height achievable with each cuboid. Initially, each cuboid's own height is considered as the base of the tower. Then, for each cuboid, the algorithm checks if it can be stacked on top of any previous cuboid and updates the DP value accordingly.

3. **Sorting the Cuboids by Dimensions**:  
   After sorting the individual cuboid dimensions, the list of cuboids is sorted lexicographically. This ensures that the cuboids are processed in a way that simplifies the stacking process.

4. **Final Result**:  
   The final answer is the maximum value in the DP array, which represents the maximum height achievable by stacking the cuboids.

### Example Walkthrough:
- Given cuboids: `[[4, 1, 4], [6, 2, 5], [7, 3, 6]]`
- After rotations and sorting: `[[1, 4, 4], [2, 5, 6], [3, 6, 7]]`
- DP steps:
  - `dp[0] = 4`
  - `dp[1] = 10` (after stacking on cuboid 0)
  - `dp[2] = 17` (after stacking on cuboid 1)
- Final answer: `17`

This approach ensures that all possible orientations and valid stackings are considered to find the maximum height.

## Problem Solution
```cpp
class Solution {
public:
    int solve(vector<vector<int>>& cuboids, int n) {
        vector<int> dp(n);  // Array to store the maximum height of the tower ending at cuboid i
        int maxHeight = 0;  // Variable to store the overall maximum height of the tower

        // Loop through each cuboid (i represents the current cuboid being considered for the tower)
        for (int i = 0; i < n; i++) {
            dp[i] = cuboids[i][2];  // The initial height for each cuboid is its own height (third dimension)
            
            // Try to stack the current cuboid on top of all previously considered cuboids (j represents the previous cuboid)
            for (int j = 0; j < i; j++) {
                // Check if cuboid j can fit under cuboid i by comparing the dimensions
                if (cuboids[j][0] <= cuboids[i][0] &&  // width of cuboid j <= width of cuboid i
                    cuboids[j][1] <= cuboids[i][1] &&  // length of cuboid j <= length of cuboid i
                    cuboids[j][2] <= cuboids[i][2]) {  // height of cuboid j <= height of cuboid i
                    // If it fits, update the dp value for cuboid i to include the height of cuboid j
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }

            // Update the overall maximum height after considering the current cuboid
            maxHeight = max(maxHeight, dp[i]);
        }

        return maxHeight;  // Return the maximum height that can be achieved
    }

    // Function to find the maximum height of the tower that can be made from the given cuboids
    int maxHeight(vector<vector<int>>& cuboids) {
        // Sort the dimensions of each cuboid in non-decreasing order
        for (auto& cube : cuboids) {
            sort(cube.begin(), cube.end()); // Sorting each cuboid's dimensions (height, width, length)
        }

        // Sort the cuboids by their dimensions to ensure the cuboids are arranged in the right order for the DP approach
        sort(cuboids.begin(), cuboids.end()); // Sorting cuboids lexicographically by their dimensions

        return solve(cuboids, cuboids.size());  // Call the solve function to compute the maximum height
    }
};

```

## Problem Solution Explanation

#### 1. `int maxHeight(vector<vector<int>>& cuboids) {`
This is the starting point of the `maxHeight` function, which takes a reference to a 2D vector `cuboids`. Each element of `cuboids` is a vector representing the dimensions of a cuboid, where each cuboid has three dimensions: width, length, and height.

#### 2. `for (auto& cube : cuboids) {`
Here, we iterate through each cuboid in the `cuboids` list. `auto& cube` refers to each individual cuboid. This loop will allow us to sort the dimensions of each cuboid in the next step.

#### 3. `sort(cube.begin(), cube.end());`
For each cuboid, we sort its dimensions in ascending order. This ensures that the width, length, and height are in non-decreasing order for each cuboid.

**Example**:  
Consider the cuboid `[6, 2, 5]`. After sorting, it will become `[2, 5, 6]`. This sorting is done for every cuboid in the list.

#### 4. `sort(cuboids.begin(), cuboids.end());`
After sorting the dimensions of individual cuboids, we sort the cuboids themselves. This sorts the cuboids lexicographically by their dimensions. The sorting ensures that we process the cuboids in a consistent order to make the dynamic programming approach work.

**Example**:  
If the cuboids are `[[4, 1, 4], [6, 2, 5], [7, 3, 6]]`, after sorting each cuboid’s dimensions and sorting the cuboids, the result will be `[[1, 4, 4], [2, 5, 6], [3, 6, 7]]`.

#### 5. `return solve(cuboids, cuboids.size());`
After sorting the cuboids and their dimensions, we call the `solve` function, passing the sorted `cuboids` and the total number of cuboids (`cuboids.size()`) as arguments. The `solve` function will compute and return the maximum height of the stack of cuboids.



### `solve` Function Explanation (Line by Line)

#### 1. `vector<int> dp(n);`
Here, we declare a dynamic programming (DP) array `dp` of size `n`, where `n` is the number of cuboids. The `dp[i]` represents the maximum height of the tower that ends with the `i`-th cuboid.

#### 2. `int maxHeight = 0;`
This variable will store the overall maximum height of the tower formed by stacking cuboids.

#### 3. `for (int i = 0; i < n; i++) {`
This loop iterates over each cuboid `i` (from 0 to `n-1`). The idea is to consider cuboid `i` as the current cuboid that might be placed on top of previously considered cuboids.

#### 4. `dp[i] = cuboids[i][2];`
We initialize `dp[i]` with the height of the `i`-th cuboid (its third dimension). This is because, at the start, the maximum height of the tower ending with cuboid `i` is just the height of cuboid `i` itself.

**Example**:  
If `cuboids = [[1, 4, 4], [2, 5, 6], [3, 6, 7]]`, the initial `dp` array will be `[4, 6, 7]`.

#### 5. `for (int j = 0; j < i; j++) {`
The inner loop iterates over all previous cuboids (`j`), checking whether cuboid `i` can be stacked on top of cuboid `j`. 

#### 6. `if (cuboids[j][0] <= cuboids[i][0] && cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2]) {`
This condition checks whether cuboid `j` can be placed under cuboid `i`. For cuboid `j` to fit under cuboid `i`, the width, length, and height of cuboid `j` must all be less than or equal to those of cuboid `i`.

**Example**:  
If `cuboids[i] = [3, 6, 7]` and `cuboids[j] = [2, 5, 6]`, the condition checks if `2 <= 3`, `5 <= 6`, and `6 <= 7`. Since all conditions are true, cuboid `j` can be placed under cuboid `i`.

#### 7. `dp[i] = max(dp[i], dp[j] + cuboids[i][2]);`
If cuboid `j` can fit under cuboid `i`, we update the value of `dp[i]` to be the maximum of its current value and the value of `dp[j]` (the maximum height of the tower ending with cuboid `j`) plus the height of cuboid `i`.

**Example**:  
For `i = 2` and `j = 1`, if `dp[1] = 6` and `cuboids[2][2] = 7`, then:
`dp[2] = max(7, 6 + 7) = 13`.

#### 8. `maxHeight = max(maxHeight, dp[i]);`
After processing each cuboid `i`, we update `maxHeight` to be the maximum of the current `maxHeight` and `dp[i]`. This ensures that we track the overall maximum height of the tower across all cuboids.

#### 9. `return maxHeight;`
After considering all cuboids, we return the `maxHeight`, which is the maximum height of the tower that can be formed by stacking cuboids.



### Example Walkthrough

**Input**: `cuboids = [[4, 1, 4], [6, 2, 5], [7, 3, 6]]`

1. **Step 1: Sorting Dimensions of Each Cuboid**
   After sorting the dimensions of each cuboid:
   ```
   cuboids = [[1, 4, 4], [2, 5, 6], [3, 6, 7]]
   ```

2. **Step 2: Sorting Cuboids Lexicographically**
   After sorting the cuboids lexicographically:
   ```
   cuboids = [[1, 4, 4], [2, 5, 6], [3, 6, 7]]
   ```

3. **Step 3: Initialize dp Array**
   Initially, the `dp` array is:
   ```
   dp = [4, 6, 7]  // Heights of individual cuboids
   ```

4. **Step 4: Calculate dp Array for Maximum Heights**
   For each cuboid `i`, check if it can be stacked on previous cuboids `j`:
   - For `i = 1`, `cuboid = [2, 5, 6]`, it can be stacked on `j = 0`, so `dp[1] = max(dp[1], dp[0] + cuboids[1][2]) = max(6, 4 + 6) = 10`.
   - For `i = 2`, `cuboid = [3, 6, 7]`, it can be stacked on `j = 0` and `j = 1`, so `dp[2] = max(dp[2], dp[1] + cuboids[2][2]) = max(7, 10 + 7) = 17`.

   After processing all cuboids, the `dp` array becomes:
   ```
   dp = [4, 10, 17]
   ```

5. **Step 5: Calculate Maximum Height**
   The overall maximum height is `max(4, 10, 17) = 17`.

**Output**: `17`



### Time Complexity:

1. **Sorting dimensions of each cuboid**:  
   Sorting each cuboid's dimensions takes (O(3 log 3) = O(1)), so for (n) cuboids, this step takes (O(n)).

2. **Sorting the cuboids**:  
   Sorting (n) cuboids takes (O(n log n)).

3. **Dynamic Programming with nested loops**:  
   The outer loop runs (n) times, and the inner loop runs (i) times for each iteration of the outer loop. The time complexity of the nested loops is (O(n^2)).

Thus, the overall time complexity is:
`O(n log n) + O(n^2) = O(n^2)`

### Space Complexity:

1. **Space for the DP array**:  
   The DP array `dp` takes (O(n)) space.

2. **Space for storing the cuboids**:  
   The cuboids themselves take (O(n)) space.

Thus, the overall space complexity is:
`O(n)`

### Final Time and Space Complexity:
- **Time Complexity**: (O(n^2))
- **Space Complexity**: (O(n))
