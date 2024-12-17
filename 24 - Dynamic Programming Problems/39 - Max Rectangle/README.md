<h1 align="center">Max - Rectangle</h1>

## Problem Statement

**Problem URL :** [Max Rectangle](https://www.geeksforgeeks.org/problems/max-rectangle/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/f18e5670-7ec0-48b2-bd1f-26847e4d207b)

### Problem Explanation
You are given a binary matrix, where each element is either `0` or `1`. Your task is to find the largest rectangle that can be formed with `1`s in the matrix. The rectangle must be entirely composed of `1`s, and its sides must be parallel to the edges of the matrix.

### Approach:

The problem is an extension of the **Largest Rectangle in Histogram** problem, where the histogram represents the height of consecutive `1`s in each column for each row of the matrix. Here's how to approach the problem:

1. **Transform the problem into a histogram problem:**
   - We can treat each row of the matrix as a base of a histogram. The height of each histogram bar corresponds to the number of consecutive `1`s in the column up to that row.

2. **For each row, update the heights and calculate the maximum rectangle area:**
   - For each row, update the heights of the columns. If the element is `1`, increment the height of the column, otherwise, reset the height to `0`.
   - After updating the heights, apply the **largest rectangle in histogram** algorithm to find the largest rectangle area using the updated heights.

### Example:

Consider the following binary matrix:

```
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
```

- **First Row:** `1 0 1 0 0`  
  Heights after this row: `[1, 0, 1, 0, 0]`  
  The largest rectangle area in this histogram is `1` (just the `1` in the first column).
  
- **Second Row:** `1 0 1 1 1`  
  Heights after this row: `[2, 0, 2, 1, 1]`  
  The largest rectangle area is `2` (the rectangle formed by columns 1 and 2 with height `2`).

- **Third Row:** `1 1 1 1 1`  
  Heights after this row: `[3, 1, 3, 2, 2]`  
  The largest rectangle area is `6` (the rectangle formed by columns 1, 2, and 3 with height `3`).

- **Fourth Row:** `1 0 0 1 0`  
  Heights after this row: `[4, 0, 0, 3, 0]`  
  The largest rectangle area is `4` (the rectangle formed by columns 1 with height `4`).

The largest rectangle area in this matrix is `6`.

### Step-by-Step Explanation of the Approach:

1. **Initialize the Height Array:**
   - For each row in the binary matrix, treat each column as a histogram bar.
   - The value of each bar (column) is the number of consecutive `1`s in that column up to the current row. If a `0` is encountered in the matrix, the height for that column is reset to `0`.

2. **Process Each Row One by One:**
   - For each row in the matrix, update the heights of the histogram bars. If the matrix cell is `1`, increase the height of that column's bar. If it's `0`, reset the height to `0` for that column.

3. **Apply the Largest Rectangle in Histogram Approach:**
   - Once the height array is updated for the current row, apply the **Largest Rectangle in Histogram** algorithm to find the maximum rectangular area for that row.
     - This is done by finding the **previous smaller element index** and **next smaller element index** for each column (bar).
     - The width of the rectangle is determined by the distance between these two indices (previous smaller and next smaller).
     - The height of the rectangle is the value of the current column's height.
     - Calculate the area using the formula:  
       `Area = Height * Width`.
   
4. **Update the Maximum Area:**
   - For each row's histogram, calculate the maximum rectangle area and update the overall maximum area encountered so far.

5. **Repeat for All Rows:**
   - Repeat the above steps for every row in the matrix, updating the height array and calculating the maximum area for each row's histogram.

6. **Return the Maximum Area:**
   - Once all rows are processed, return the largest rectangle area found across all rows.

### Why This Approach Works:

- **Histogram Transformation:** The matrix is transformed row by row into a histogram of heights, making it easier to calculate the maximum rectangle area using the well-known histogram approach.
  
- **Efficient Calculation with Stacks:** Using the monotonic stack-based method to find the next and previous smaller elements ensures efficient computation of the area in O(n) time for each row, where `n` is the number of columns.
  
- **Optimal for Multiple Rows:** By leveraging the updated height array after each row, the problem is broken down into manageable subproblems, where each row can be processed independently, and the solution builds incrementally.

## Problem Solution
```cpp
class Solution {
    // Function to find the index of the next smaller element for each element in the array
    private:
        vector<int> nextSmallerElementIndexes(vector<int> arr, int n){
            stack<int> st;  // Stack to store indices
            vector<int> ans(n);  // Vector to store the result
    
            st.push(-1);  // Push -1 as the base value for comparison
    
            for(int i = n-1; i >= 0; i--){  // Traverse the array from right to left
                int current = arr[i];  // Current element
                
                // Pop elements from the stack until a smaller element is found
                while(st.top() != -1 && arr[st.top()] >= current){
                    st.pop();
                }
    
                ans[i] = st.top();  // Store the index of the next smaller element
                st.push(i);  // Push current index to the stack
            }
    
            return ans;
        }
        
        // Function to find the index of the previous smaller element for each element in the array
        vector<int> prevSmallerElementIndexes(vector<int> arr, int n){
            stack<int> st;  // Stack to store indices
            vector<int> ans(n);  // Vector to store the result
    
            st.push(-1);  // Push -1 as the base value for comparison
    
            for(int i = 0; i < n; i++){  // Traverse the array from left to right
                int current = arr[i];  // Current element
    
                // Pop elements from the stack until a smaller element is found
                while(st.top() != -1 && arr[st.top()] >= current){
                    st.pop();
                }
    
                ans[i] = st.top();  // Store the index of the previous smaller element
                st.push(i);  // Push current index to the stack
            }
    
            return ans;
        }
        
        // Function to calculate the largest rectangular area that can be formed from the histogram
        int largestRectangleArea(vector<int>& heights) {
            int n = heights.size();  // Get the number of bars in the histogram
        
            // Get the next smaller element indexes for each bar
            vector<int> next(n);
            next = nextSmallerElementIndexes(heights, n);
        
            // Get the previous smaller element indexes for each bar
            vector<int> prev(n);
            prev = prevSmallerElementIndexes(heights, n);
        
            int area = INT_MIN;  // Initialize area to the minimum possible value
        
            for(int i = 0; i < n; i++){
                int l = heights[i];  // Height of the current bar
        
                // If no next smaller element exists, set it to n (end of the histogram)
                if(next[i] == -1) next[i] = n;
        
                // Width is the distance between the previous and next smaller elements
                int b = next[i] - prev[i] - 1;
                
                // Calculate the area for the current bar and update the maximum area
                int newArea = l * b;
                area = max(area, newArea);
            }
        
            return area;  // Return the maximum area found
        }
        
    public:
        // Function to calculate the maximum area of a rectangle in a 2D matrix
        int maxArea(vector<vector<int>> &mat) {
            vector<int> height(mat[0].size(), 0);  // Initialize height array with 0s (one for each column)
            int maxi = INT_MIN;  // Variable to store the maximum area
        
            for(int i = 0; i < mat.size(); i++){  // Traverse each row of the matrix
                for(int j = 0; j < height.size(); j++){  // Traverse each column in the row
                    if(mat[i][j] == 1) height[j]++;  // If the element is 1, increment the height
                    else height[j] = 0;  // If the element is 0, reset the height
                }
                
                // Calculate the maximum area for the current row using the histogram approach
                maxi = max(maxi, largestRectangleArea(height));
            }
            
            return maxi;  // Return the maximum area found
        }
};

```

## Problem Solution Explanation
Let's break down the entire code and explain each function with examples using function names as headers.

### `nextSmallerElementIndexes` Function:

This function finds the **next smaller element index** for each element in the array.

```cpp
vector<int> nextSmallerElementIndexes(vector<int> arr, int n) {
    stack<int> st;    // Stack to store indices of elements
    vector<int> ans(n);    // Array to store the next smaller element's index for each element
    st.push(-1);   // Initialize the stack with -1 (sentinel value)
```
- We use a **stack** `st` to store indices of the array elements as we traverse the array.
- The vector `ans` holds the result: the index of the next smaller element for each element in `arr`.
- We push `-1` onto the stack initially to handle edge cases where no smaller element exists.

**Example:**
- Let's consider an array `arr = [4, 5, 2, 10]`.
  - We need to find the index of the next smaller element for each element.



```cpp
    // Traverse the array from right to left
    for (int i = n-1; i >= 0; i--) {
        int current = arr[i];   // Current element in the array
```
- The array is processed **from right to left**.
- `current` holds the value of the element at index `i`.

**Example:**
- For `arr = [4, 5, 2, 10]`, when `i = 3`, `current = 10`.



```cpp
        // Pop from the stack until we find a smaller element than the current one
        while (st.top() != -1 && arr[st.top()] >= current) {
            st.pop();
        }
```
- This **while loop** removes elements from the stack that are **greater than or equal** to the current element. This ensures that we find the next smaller element.
- The loop continues until the stack is empty or the element at the top of the stack is smaller than the current element.

**Example:**
- When `current = 10`, the stack will be checked, and elements will be popped if they are greater than or equal to `10`. In this case, the stack is empty, so no elements are popped.



```cpp
        ans[i] = st.top();   // Set the next smaller element's index for current element
        st.push(i);   // Push the current index onto the stack
    }
```
- We assign the index of the next smaller element (which is at the top of the stack) to `ans[i]`.
- We then push the current index `i` onto the stack for future comparisons.

**Example:**
- For `arr = [4, 5, 2, 10]`, after processing the element `10`:
  - The stack will have the index `3`, which corresponds to the element `10`.



**Final Example for `nextSmallerElementIndexes`:**
For `arr = [4, 5, 2, 10]`, the result will be:
- Next smaller element for `4` → `2` (index 2).
- Next smaller element for `5` → `2` (index 2).
- Next smaller element for `2` → `-1` (no smaller element).
- Next smaller element for `10` → `-1` (no smaller element).
- **Output:** `ans = [2, 2, -1, -1]`.



### `prevSmallerElementIndexes` Function:

This function finds the **previous smaller element index** for each element in the array.

```cpp
vector<int> prevSmallerElementIndexes(vector<int> arr, int n) {
    stack<int> st;    // Stack to store indices of elements
    vector<int> ans(n);    // Array to store the previous smaller element's index for each element
    st.push(-1);   // Initialize the stack with -1 (sentinel value)
```
- Similar to the `nextSmallerElementIndexes` function, we use a stack `st` to store indices of elements.
- The vector `ans` will hold the result: the index of the previous smaller element for each element in `arr`.
- We initialize the stack with `-1` to handle the edge case when no smaller element exists.

**Example:**
- Consider `arr = [4, 5, 2, 10]`.
  - We want to find the index of the previous smaller element for each element.



```cpp
    // Traverse the array from left to right
    for (int i = 0; i < n; i++) {
        int current = arr[i];   // Current element in the array
```
- The array is processed **from left to right**.
- `current` holds the value of the element at index `i`.

**Example:**
- For `arr = [4, 5, 2, 10]`, when `i = 0`, `current = 4`.



```cpp
        // Pop from the stack until we find a smaller element than the current one
        while (st.top() != -1 && arr[st.top()] >= current) {
            st.pop();
        }
```
- The **while loop** pops elements from the stack as long as they are **greater than or equal** to the current element. This helps in finding the previous smaller element for `current`.

**Example:**
- When `current = 4`, the stack is checked. Initially, the stack has `-1`, so no elements are popped.



```cpp
        ans[i] = st.top();   // Set the previous smaller element's index for current element
        st.push(i);   // Push the current index onto the stack
    }
```
- We assign the index of the previous smaller element (top of the stack) to `ans[i]`.
- We then push the current index `i` onto the stack for future comparisons.

**Example:**
- For `arr = [4, 5, 2, 10]`, after processing the element `4`, the stack will contain index `0`.



**Final Example for `prevSmallerElementIndexes`:**
For `arr = [4, 5, 2, 10]`, the result will be:
- Previous smaller element for `4` → `-1` (no smaller element).
- Previous smaller element for `5` → `4` (index 0).
- Previous smaller element for `2` → `-1` (no smaller element).
- Previous smaller element for `10` → `2` (index 2).
- **Output:** `ans = [-1, 0, -1, 2]`.



### `largestRectangleArea` Function:

This function calculates the **maximum area of a rectangle** that can be formed in a histogram.

```cpp
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
```
- The function takes an array `heights` that represents the histogram's bar heights. We store the number of elements (bars) in `n`.

**Example:**
- If `heights = [2, 1, 5, 6, 2, 3]`, then `n = 6`.



```cpp
    vector<int> next(n);
    next = nextSmallerElementIndexes(heights, n);
    
    vector<int> prev(n);
    prev = prevSmallerElementIndexes(heights, n);
```
- We call the `nextSmallerElementIndexes` and `prevSmallerElementIndexes` functions to find the next and previous smaller element indices for each element in the `heights` array.

**Example:**
- For `heights = [2, 1, 5, 6, 2, 3]`, after calling both functions:
  - `next = [1, 6, 4, 6, 6, 6]`
  - `prev = [-1, -1, 1, 2, -1, 4]`.



```cpp
    int area = INT_MIN;
```
- We initialize `area` to the smallest possible integer (`INT_MIN`), which will be used to store the maximum rectangle area found.



```cpp
    for (int i = 0; i < n; i++) {
        int l = heights[i];
        
        if (next[i] == -1) next[i] = n;
        
        int b = next[i] - prev[i] - 1;
        
        int newArea = l * b;
        area = max(area, newArea);
    }
```
- Loop over each histogram bar:
  - `l` is the height of the bar at index `i`.
  - If `next[i] == -1`, set it to `n` (i.e., the end of the histogram).
  - The width `b` is calculated as the difference between the next smaller index (`next[i]`) and the previous smaller index (`prev[i]`), minus 1.
  - The area of the rectangle is calculated as `l * b`.
  - We update the `area` by taking the maximum of the current `area` and the newly calculated `newArea`.



### `maxArea` Function:

This is the main function that calculates the maximum rectangular area in a binary matrix.

```cpp
int maxArea(vector<vector<int>> &mat) {
    vector<int> height(mat[0].size(), 0);  // Initialize height array
    int maxi = INT_MIN;  // To store the maximum area found
```
- The `height` vector is initialized to `0` for each column of the first row of the matrix.
- `maxi` stores the maximum rectangular area found so far.



```cpp
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < height.size(); j++) {
            if (mat[i][j] == 1) height[j]++;  // Update height if the cell is 1
            else height[j] = 0;  // Reset height if the cell is 0
        }
        
        maxi = max(maxi, largestRectangleArea(height));  // Update maxi with the max area for this row
    }
```
- For each row `i` of the matrix:
  - If `mat[i][j] == 1`, increase the height of column `j`.
  - If `mat[i][j] == 0`, reset the height for column `j` to `0`.
- After updating the height array, we call `largestRectangleArea` to calculate the maximum area for the current row.



```cpp
    return maxi;  // Return the maximum area found
}
```
- Finally, the function returns `maxi`, which contains the maximum rectangular area found in the matrix.


Let's walk through an example to understand the **output** of the algorithm step by step.

### Example Input:
Consider the following binary matrix (`mat`):

```cpp
mat = {
    {1, 0, 1, 0, 0},
    {1, 0, 1, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0}
}
```

### Step-by-Step Execution:

#### Step 1: Initialize Height Array

We start by initializing the height array with all zeros, corresponding to the columns of the matrix:

```cpp
height = [0, 0, 0, 0, 0]
```

#### Step 2: Process Each Row

We now process each row of the matrix. For each row, we update the height array and calculate the maximum rectangular area.



### Row 1: `{1, 0, 1, 0, 0}`

- Update the `height` array based on the current row:
  - `height[0]` becomes `1` because `mat[0][0] = 1`.
  - `height[1]` stays `0` because `mat[0][1] = 0`.
  - `height[2]` becomes `1` because `mat[0][2] = 1`.
  - `height[3]` stays `0` because `mat[0][3] = 0`.
  - `height[4]` stays `0` because `mat[0][4] = 0`.

```cpp
height = [1, 0, 1, 0, 0]
```

Now, call `largestRectangleArea(height)`:

- The **next smaller element** indices for the current `height` array:
  - `next = [1, 5, 3, 5, 5]`
  - `prev = [-1, -1, 1, -1, -1]`

- The area for each bar:
  - Bar 1: Height = 1, Width = 1 - (-1) - 1 = 1 → Area = 1 * 1 = 1
  - Bar 2: Height = 0, Width = 5 - (-1) - 1 = 5 → Area = 0 * 5 = 0
  - Bar 3: Height = 1, Width = 3 - 1 - 1 = 1 → Area = 1 * 1 = 1
  - Bar 4: Height = 0, Width = 5 - (-1) - 1 = 5 → Area = 0 * 5 = 0
  - Bar 5: Height = 0, Width = 5 - (-1) - 1 = 5 → Area = 0 * 5 = 0

**Maximum area for Row 1**: `max(1, 0, 1, 0, 0) = 1`.



### Row 2: `{1, 0, 1, 1, 1}`

- Update the `height` array based on the current row:
  - `height[0]` becomes `2` because `mat[1][0] = 1` and `height[0]` was `1` from the previous row.
  - `height[1]` stays `0` because `mat[1][1] = 0`.
  - `height[2]` becomes `2` because `mat[1][2] = 1` and `height[2]` was `1` from the previous row.
  - `height[3]` becomes `1` because `mat[1][3] = 1`.
  - `height[4]` becomes `1` because `mat[1][4] = 1`.

```cpp
height = [2, 0, 2, 1, 1]
```

Now, call `largestRectangleArea(height)`:

- The **next smaller element** indices for the current `height` array:
  - `next = [1, 5, 3, 5, 5]`
  - `prev = [-1, -1, 1, 1, 1]`

- The area for each bar:
  - Bar 1: Height = 2, Width = 1 - (-1) - 1 = 1 → Area = 2 * 1 = 2
  - Bar 2: Height = 0, Width = 5 - (-1) - 1 = 5 → Area = 0 * 5 = 0
  - Bar 3: Height = 2, Width = 3 - 1 - 1 = 1 → Area = 2 * 1 = 2
  - Bar 4: Height = 1, Width = 5 - 1 - 1 = 3 → Area = 1 * 3 = 3
  - Bar 5: Height = 1, Width = 5 - 1 - 1 = 3 → Area = 1 * 3 = 3

**Maximum area for Row 2**: `max(2, 0, 2, 3, 3) = 3`.



### Row 3: `{1, 1, 1, 1, 1}`

- Update the `height` array based on the current row:
  - `height[0]` becomes `3` because `mat[2][0] = 1` and `height[0]` was `2` from the previous row.
  - `height[1]` becomes `1` because `mat[2][1] = 1` and `height[1]` was `0` from the previous row.
  - `height[2]` becomes `3` because `mat[2][2] = 1` and `height[2]` was `2` from the previous row.
  - `height[3]` becomes `2` because `mat[2][3] = 1` and `height[3]` was `1` from the previous row.
  - `height[4]` becomes `2` because `mat[2][4] = 1` and `height[4]` was `1` from the previous row.

```cpp
height = [3, 1, 3, 2, 2]
```

Now, call `largestRectangleArea(height)`:

- The **next smaller element** indices for the current `height` array:
  - `next = [1, 5, 3, 5, 5]`
  - `prev = [-1, -1, 1, 1, 1]`

- The area for each bar:
  - Bar 1: Height = 3, Width = 1 - (-1) - 1 = 1 → Area = 3 * 1 = 3
  - Bar 2: Height = 1, Width = 5 - (-1) - 1 = 5 → Area = 1 * 5 = 5
  - Bar 3: Height = 3, Width = 3 - 1 - 1 = 1 → Area = 3 * 1 = 3
  - Bar 4: Height = 2, Width = 5 - 1 - 1 = 3 → Area = 2 * 3 = 6
  - Bar 5: Height = 2, Width = 5 - 1 - 1 = 3 → Area = 2 * 3 = 6

**Maximum area for Row 3**: `max(3, 5, 3, 6, 6) = 6`.



### Row 4: `{1, 0, 0, 1, 0}`

- Update the `height` array based on the current row:
  - `height[0]` becomes `4` because `mat[3][0] = 1` and `height[0]` was `3` from the previous row.
  - `height[1]` becomes `0` because `mat[3][1] = 0`.
  - `height[2]` becomes `0` because `mat[3][2] = 0`.
  - `height[3]` becomes `3` because `mat[3][3] = 1` and `height[3]` was `2` from the previous row.
  - `height[4]` becomes `0` because `mat[3][4] = 0`.

```cpp
height = [4, 0, 0, 3, 0]
```

Now, call `largestRectangleArea(height)`:

- The **next smaller element** indices for the current `height` array:
  - `next = [1, 5, 5, 5, 5]`
  - `prev = [-1, -1, -1, 1, -1]`

- The area for each bar:
  - Bar 1: Height = 4, Width = 1 - (-1) - 1 = 1 → Area = 4 * 1 = 4
  - Bar 2: Height = 0, Width = 5 - (-1) - 1 = 5 → Area = 0 * 5 = 0
  - Bar 3: Height = 0, Width = 5 - (-1) - 1 = 5 → Area = 0 * 5 = 0
  - Bar 4: Height = 3, Width = 5 - 1 - 1 = 3 → Area = 3 * 3 = 9
  - Bar 5: Height = 0, Width = 5 - (-1) - 1 = 5 → Area = 0 * 5 = 0

**Maximum area for Row 4**: `max(4, 0, 0, 9, 0) = 9`.


### Final Maximum Area:
After processing all rows, the overall maximum area is:

```
max(1, 3, 6, 9) = 9
```

### Output:

```cpp
9
```

Thus, the **maximum rectangular area** in this matrix is **9**.

### Time Complexity:
- The **`nextSmallerElementIndexes`** and **`prevSmallerElementIndexes`** functions each take **O(n)** time, where `n` is the number of columns.
- The **`largestRectangleArea`** function also runs in **O(n)** time.
- The **`maxArea`** function processes each row of the matrix and calls `largestRectangleArea`, so the overall time complexity is **O(m * n)**, where `m` is the number of rows and `n` is the number of columns.

### Space Complexity:
- The space complexity is **O(n)**, as we are storing arrays for the next and previous smaller element indices, and the height array in the `maxArea` function.

