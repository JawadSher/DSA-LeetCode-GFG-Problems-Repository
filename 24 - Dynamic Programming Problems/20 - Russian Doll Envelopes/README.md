<h1 align="center">Russian - Doll - Envelopes</h1>

## Problem Statement

**Problem URL :** [Russian Doll Envelopes](https://leetcode.com/problems/russian-doll-envelopes/description/)

![image](https://github.com/user-attachments/assets/699fe0c5-3818-4335-9226-6f76ad046a3a)

### Problem Explanation
The **Russian Doll Envelopes** problem involves a set of envelopes where each envelope has a width and a height. The goal is to find the maximum number of envelopes that can be nested inside one another, following these rules:

1. An envelope can only be nested inside another envelope if both its width and height are strictly smaller than the other envelope.
2. The envelopes must be ordered by increasing width and height for nesting.

### Example:

#### Input:
```cpp
vector<vector<int>> envelopes = {{5,4}, {6,4}, {6,7}, {2,3}};
```

#### Step-by-Step Explanation:

1. **Initial Input**: You are given four envelopes with the following dimensions:
   - Envelope 1: (5, 4)
   - Envelope 2: (6, 4)
   - Envelope 3: (6, 7)
   - Envelope 4: (2, 3)

2. **Sorting**: Sort the envelopes by width in ascending order. If two envelopes have the same width, sort them by height in descending order.
   
   After sorting:
   ```cpp
   envelopes = {{2, 3}, {5, 4}, {6, 7}, {6, 4}};
   ```
   - First by width: 2 < 5 < 6 < 6
   - If widths are the same, sort by height in descending order (e.g., (6,7) comes before (6,4)).

3. **Finding the Longest Increasing Subsequence (LIS)**:
   - Extract the heights from the sorted envelopes: `[3, 4, 7, 4]`.
   - Now, find the Longest Increasing Subsequence (LIS) of heights. The LIS of heights `[3, 4, 7, 4]` is `[3, 4, 7]`, which has a length of 3.
   - The maximum number of envelopes that can be nested is 3: (2, 3) -> (5, 4) -> (6, 7).

#### Final Output: 
```cpp
3
```

### Approach of the Given Code

1. **Sorting**:
   - The envelopes are first sorted by width in ascending order. If two envelopes have the same width, they are sorted by height in descending order. This sorting step ensures that we do not need to worry about nested envelopes having the same width, as we handle this case by sorting heights in descending order when widths are equal.

2. **Finding LIS**:
   - After sorting, we extract the heights of the envelopes and use a binary search technique (`lower_bound`) to find the LIS of the heights. This approach ensures that we always maintain the smallest possible elements in the LIS, allowing us to extend the sequence with future elements.

3. **Result**:
   - The length of the LIS of heights is the maximum number of envelopes that can be nested.

## Problem Solution
```cpp
class Solution {
public:
    // Helper function to find the length of the Longest Increasing Subsequence (LIS)
    int solve(vector<int>& heights){
        int n = heights.size();   // Get the number of envelopes
        vector<int> ans;          // Vector to store the LIS of heights (not the actual subsequence, just its length)

        // Iterate through all the heights to find the LIS
        for(int i = 0; i < n; i++){
            // If the ans vector is empty or the current height is greater than the last element of ans,
            // add the current height to the LIS.
            if(ans.empty() || heights[i] > ans.back()){
                ans.push_back(heights[i]);
            } else {
                // Otherwise, find the first element in ans that is greater than or equal to heights[i]
                // and replace it with the current height.
                // This maintains the smallest possible value for the LIS subsequence, ensuring it's extensible.
                int index = lower_bound(ans.begin(), ans.end(), heights[i]) - ans.begin();
                ans[index] = heights[i]; // Update the value at the found position
            }
        }

        // Return the size of the LIS (i.e., the maximum number of envelopes that can be nested)
        return ans.size();
    }

    // Main function to solve the Russian Doll Envelopes problem
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Step 1: Sort the envelopes
        // Sort first by width in ascending order, and if the widths are the same, by height in descending order
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b){
            // If the widths are equal, we sort by height in descending order
            if(a[0] == b[0]) return a[1] > b[1];
            // Otherwise, sort by width in ascending order
            return a[0] < b[0];
        });

        // Step 2: Extract the heights of the envelopes after sorting
        vector<int> heights;
        for(const auto& envelope : envelopes) heights.push_back(envelope[1]);

        // Step 3: Find the LIS of heights (this will give the maximum number of envelopes that can be nested)
        return solve(heights);
    }
};

```

## Problem Solution Explanation

Let’s break down the given code line by line and explain it in detail with examples.

```cpp
class Solution {
public:
    // Helper function to find the length of the Longest Increasing Subsequence (LIS)
    int solve(vector<int>& heights){
        int n = heights.size();   // Get the number of envelopes
```

- **Line 1**: We begin by declaring the `Solution` class, which contains our solution.
- **Line 2**: The `solve` function is a helper function that takes a vector of integers `heights` and returns the length of the Longest Increasing Subsequence (LIS) of heights.
- **Line 3**: We define `n`, the size of the `heights` vector, which represents the number of envelopes after sorting them by width.

**Example**: Suppose `heights = [3, 4, 7, 4]` (extracted from the envelopes after sorting them by width).

```cpp
        vector<int> ans;          // Vector to store the LIS of heights (not the actual subsequence, just its length)
```

- **Line 4**: `ans` is a vector that will store the smallest possible elements of the LIS (the length of the LIS is stored, not the actual subsequence).
- **Explanation**: By maintaining the smallest elements, we ensure that we have the best potential to extend the LIS by adding larger elements.

**Example**: `ans = []` (Initially empty).

```cpp
        // Iterate through all the heights to find the LIS
        for(int i = 0; i < n; i++){
```

- **Line 5**: A loop is started to iterate over all the heights. The goal is to update the LIS progressively.

**Example**: The loop will iterate through `heights = [3, 4, 7, 4]`.

```cpp
            // If the ans vector is empty or the current height is greater than the last element of ans,
            // add the current height to the LIS.
            if(ans.empty() || heights[i] > ans.back()){
```

- **Line 6-7**: If `ans` is empty or if the current height is greater than the last element in `ans` (i.e., `heights[i] > ans.back()`), then the current height should be added to `ans`. This ensures that we are forming an increasing subsequence.
  
**Example**:
  - First iteration: `heights[i] = 3`. `ans = []` (empty), so `ans.push_back(3)`.
  - After the first iteration, `ans = [3]`.

```cpp
                ans.push_back(heights[i]);
            } else {
```

- **Line 8**: If the condition is true, `heights[i]` is added to the `ans` vector.
  
```cpp
                // Otherwise, find the first element in ans that is greater than or equal to heights[i]
                // and replace it with the current height.
                // This maintains the smallest possible value for the LIS subsequence, ensuring it's extensible.
                int index = lower_bound(ans.begin(), ans.end(), heights[i]) - ans.begin();
```

- **Line 9-10**: If the current height is **not greater** than the last element of `ans`, we need to find the first element in `ans` that is greater than or equal to `heights[i]`. We use `lower_bound` to find the position of the first element in `ans` that is greater than or equal to `heights[i]`. This index is then used to update the element at that position with `heights[i]`.
- **Reason**: Replacing the element at `index` ensures that we maintain the smallest possible values in `ans`, which allows for a potentially longer subsequence in future iterations.
  
**Example**:
  - Second iteration: `heights[i] = 4`. The `ans = [3]`, and `4` is greater than `3`, so `ans.push_back(4)`.

  - Third iteration: `heights[i] = 7`. The `ans = [3, 4]`, and `7` is greater than `4`, so `ans.push_back(7)`.

  - Fourth iteration: `heights[i] = 4`. The `ans = [3, 4, 7]`. Using `lower_bound`, we find that `4` can replace the second element in `ans` (because `4 <= 7`), so we update `ans = [3, 4, 7]`.

```cpp
                ans[index] = heights[i]; // Update the value at the found position
            }
        }
```

- **Line 11**: We replace the element at `index` in `ans` with the current `height[i]`. This maintains the smallest possible value for the LIS subsequence.
  
```cpp
        // Return the size of the LIS (i.e., the maximum number of envelopes that can be nested)
        return ans.size();
    }
```

- **Line 12-13**: The size of the `ans` vector is returned, which represents the length of the longest increasing subsequence (LIS) of heights. This is the maximum number of envelopes that can be nested.

**Example**: After iterating over all the heights, `ans = [3, 4, 7]`. The length of the LIS is `3`, which means the maximum number of envelopes that can be nested is 3.

### Main Function: `maxEnvelopes`

```cpp
    // Main function to solve the Russian Doll Envelopes problem
    int maxEnvelopes(vector<vector<int>>& envelopes) {
```

- **Line 14**: The main function `maxEnvelopes` receives a 2D vector `envelopes` where each element represents an envelope with its width and height.

```cpp
        // Step 1: Sort the envelopes
        // Sort first by width in ascending order, and if the widths are the same, by height in descending order
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b){
```

- **Line 15-16**: The envelopes are sorted by their width in ascending order. If two envelopes have the same width, they are sorted by height in descending order. This step ensures that we never have to worry about envelopes with the same width in our LIS computation, as we already handle that scenario by sorting heights in descending order when widths are equal.

**Example**:
  - Before sorting: `envelopes = [[5, 4], [6, 4], [6, 7], [2, 3]]`
  - After sorting: `envelopes = [[2, 3], [5, 4], [6, 7], [6, 4]]`

```cpp
            // If the widths are equal, we sort by height in descending order
            if(a[0] == b[0]) return a[1] > b[1];
            // Otherwise, sort by width in ascending order
            return a[0] < b[0];
        });
```

- **Line 17-19**: The lambda function used for sorting:
  - If the widths are equal (`a[0] == b[0]`), it sorts by height in descending order (`a[1] > b[1]`).
  - Otherwise, it sorts by width in ascending order (`a[0] < b[0]`).

```cpp
        // Step 2: Extract the heights of the envelopes after sorting
        vector<int> heights;
        for(const auto& envelope : envelopes) heights.push_back(envelope[1]);
```

- **Line 20-21**: After sorting, we extract the heights of all the envelopes and store them in a new vector `heights`. This is necessary because the LIS is computed only on the heights.
  
**Example**: From `envelopes = [[2, 3], [5, 4], [6, 7], [6, 4]]`, we extract `heights = [3, 4, 7, 4]`.

```cpp
        // Step 3: Find the LIS of heights (this will give the maximum number of envelopes that can be nested)
        return solve(heights);
    }
};
```

- **Line 22-23**: Finally, we pass the `heights` vector to the `solve` function, which calculates the length of the Longest Increasing Subsequence of heights and returns the result.

### Example Input and Output:

**Input**:
```cpp
vector<vector<int>> envelopes = {{5,4}, {6,4}, {6,7}, {2,3}};
Solution solution;
cout << solution.maxEnvelopes(envelopes);
```

**Output**:
```cpp
3
```

**Explanation**:
- The sorted envelopes are `[[2, 3], [5, 4], [6, 7], [6, 4]]`.
- The heights are `[3, 4, 7, 4]`.
- The longest increasing subsequence (LIS) of heights is `[3, 4, 7]`, so the maximum number of envelopes that can be nested is `3`.

### Time and Space Complexity:

**Time Complexity**:
- Sorting the envelopes takes `O(n log n)` where `n` is the number of envelopes.
- Finding the LIS using `lower_bound` also takes `O(n log n)` since for each height we perform a binary search in `ans`.
- Overall, the time complexity is `O(n log n)`.

**Space Complexity**:
- We use `O(n)` space to store the heights and the `ans` vector.
- The space complexity is `O(n)`.
