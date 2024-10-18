<h1 align='center'>Maximal - Rectangle</h1>

## Problem Statement

**Problem URL :** [Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/)

![image](https://github.com/user-attachments/assets/cd8fc441-57b9-4a17-98f3-a304d3893cd8)
![image](https://github.com/user-attachments/assets/653c08ef-4f8f-4471-af56-f01cb7bdff70)

## Problem Explanation
Given a 2D binary matrix filled with `'0'` and `'1'`, you need to find the largest rectangle containing only `'1'` and return its area. 

For example, in the matrix:
```
[
  ['1', '0', '1', '0', '0'],
  ['1', '0', '1', '1', '1'],
  ['1', '1', '1', '1', '1'],
  ['1', '0', '0', '1', '0']
]
```
The largest rectangle of `1s` has an area of **6** (in the third row, covering the last three columns).

### Approach:
The main idea is to convert each row of the matrix into a histogram where the height of each bar represents the count of consecutive `1s` up to that row. For each row, we calculate the largest rectangle that can be formed using the heights.

#### Steps:
1. **Initialize Heights:** Create an array to keep track of the height of `1s` in each column as you traverse the rows of the matrix.
2. **Calculate Heights:** For each row, if a cell contains `1`, increment the height for that column; if it contains `0`, reset the height to `0`.
3. **Find Maximum Rectangle:** Use a function that calculates the maximum area of a rectangle that can be formed in the histogram represented by the heights array.

## Problem Solution
```cpp
class Solution {
private:
    vector<int> nextSmallerElementIndexes(vector<int> arr, int n){
        stack<int> st;
        vector<int> ans(n);

        st.push(-1);

        for(int i = n-1; i >= 0; i--){
            int current = arr[i];

            while(st.top() != -1 && arr[st.top()] >= current){
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }
    vector<int> prevSmallerElementIndexes(vector<int> arr, int n){
        stack<int> st;
        vector<int> ans(n);

        st.push(-1);

        for(int i = 0; i < n; i++){
            int current = arr[i];

            while(st.top() != -1 && arr[st.top()] >= current){
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }
    int largestRectangleArea(vector<int> heights, int n) {

        vector<int> next = nextSmallerElementIndexes(heights, n);

        vector<int> prev = prevSmallerElementIndexes(heights, n);

        int area = 0;

        for(int i = 0; i < n; i++){
            int height = heights[i];

            if(next[i] == -1) next[i] = n;

            int width = next[i] - prev[i] - 1;
            
            int newArea = height * width;
            area = max(area, newArea);
        }

        return area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();

        if(n == 0) return 0;

        int m = matrix[0].size();

        vector<int> heights(m, 0);
        int maxArea = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1') heights[j] += 1;
                else heights[j] = 0;
            }

            int area = largestRectangleArea(heights, m);
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }

};
```

## Problem Solution Explanation

```cpp
class Solution {
private:
    // Function to find the next smaller element's index for each element in the array.
    vector<int> nextSmallerElementIndexes(vector<int> arr, int n) {
        stack<int> st;  // Stack to store indices
        vector<int> ans(n);  // To store the indexes of the next smaller elements

        st.push(-1);  // Sentinel value to indicate no smaller element exists

        // Iterate from the last element to the first
        for(int i = n-1; i >= 0; i--){
            int current = arr[i];

            // Keep popping from stack while top of the stack is greater or equal to current element
            while(st.top() != -1 && arr[st.top()] >= current){
                st.pop();
            }

            // If stack is empty, there's no smaller element to the right; otherwise, store index
            ans[i] = st.top();
            st.push(i);  // Push the current index onto the stack
        }

        return ans;  // Return the array of next smaller element indexes
    }
```

#### Explanation:
- **Purpose:** This function finds the index of the next smaller element for each element in the given array.
- **Stack Usage:** The stack helps track the indices of elements in descending order. When we encounter a smaller element, we pop from the stack until we find an element smaller than the current one.
- **Output:** The `ans` vector will contain the index of the next smaller element. If there is none, it will be `-1`.

#### Example of `nextSmallerElementIndexes`:
For `arr = [2, 1, 5, 6, 2, 3]`:
- The output will be `[1, -1, 3, 4, 5, -1]`.

---

```cpp
    // Function to find the previous smaller element's index for each element in the array.
    vector<int> prevSmallerElementIndexes(vector<int> arr, int n) {
        stack<int> st;
        vector<int> ans(n);

        st.push(-1);  // Sentinel value to indicate no smaller element exists

        // Iterate from the first element to the last
        for(int i = 0; i < n; i++) {
            int current = arr[i];

            // Keep popping from stack while top of the stack is greater or equal to current element
            while(st.top() != -1 && arr[st.top()] >= current) {
                st.pop();
            }

            // Store the index of the previous smaller element
            ans[i] = st.top();
            st.push(i);  // Push the current index onto the stack
        }

        return ans;  // Return the array of previous smaller element indexes
    }
```

#### Explanation:
- **Purpose:** This function finds the index of the previous smaller element for each element in the array.
- **Logic:** Similar to the next smaller element function, but we process the array from left to right.

#### Example of `prevSmallerElementIndexes`:
For `arr = [2, 1, 5, 6, 2, 3]`:
- The output will be `[-1, -1, 1, 2, 1, 4]`.

---

```cpp
    // Function to calculate the largest rectangle area in a histogram
    int largestRectangleArea(vector<int> heights, int n) {
        vector<int> next = nextSmallerElementIndexes(heights, n);
        vector<int> prev = prevSmallerElementIndexes(heights, n);

        int area = 0;  // Variable to store the maximum area

        // Iterate through each bar in the histogram
        for(int i = 0; i < n; i++) {
            int height = heights[i];  // Current height

            // If there's no smaller element to the right, set the next smaller index to n
            if(next[i] == -1) next[i] = n;

            // Width of the rectangle formed by the current height
            int width = next[i] - prev[i] - 1;

            // Calculate the area of the rectangle and update the maximum area
            int newArea = height * width;
            area = max(area, newArea);
        }

        return area;  // Return the largest rectangle area
    }
```

#### Explanation:
- **Purpose:** To calculate the largest rectangle area that can be formed in the histogram defined by `heights`.
- **Logic:**
  - For each height, we find the indices of the next and previous smaller elements.
  - The width of the rectangle can be calculated using the difference between these indices.
  - The area for each bar is calculated as `height * width`, and the maximum area is updated accordingly.

#### Example:
For `heights = [2, 1, 5, 6, 2, 3]`:
- The function calculates the maximum area using the histogram heights derived from the matrix rows.

---

```cpp
public:
    // Function to calculate the maximal rectangle area in a binary matrix
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();  // Number of rows

        if(n == 0) return 0;  // If the matrix is empty, return 0

        int m = matrix[0].size();  // Number of columns

        vector<int> heights(m, 0);  // Initialize heights array for histogram
        int maxArea = 0;  // To track the maximum rectangle area

        // Iterate through each row of the matrix
        for(int i = 0; i < n; i++) {
            // Update the heights array
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1') heights[j] += 1;  // Increment height for '1'
                else heights[j] = 0;  // Reset height to 0 for '0'
            }

            // Calculate the largest rectangle area for the current row's histogram
            int area = largestRectangleArea(heights, m);
            maxArea = max(maxArea, area);  // Update the maximum area
        }

        return maxArea;  // Return the maximum rectangle area
    }
};
```

#### Explanation:
- **Purpose:** This is the main function to find the maximal rectangle area in the given binary matrix.
- **Logic:**
  - It initializes a `heights` vector for the columns.
  - For each row, it updates the `heights` vector based on the current row:
    - If the current cell is `'1'`, increment the corresponding height.
    - If the current cell is `'0'`, reset the height to `0`.
  - After updating the heights for a row, it calls the `largestRectangleArea` function to get the maximum rectangle area for that histogram.

#### Example of the complete process:
Given the matrix:
```
[
  ['1', '0', '1', '0', '0'],
  ['1', '0', '1', '1', '1'],
  ['1', '1', '1', '1', '1'],
  ['1', '0', '0', '1', '0']
]
```
1. For the first row: `heights = [1, 0, 1, 0, 0]`
   - The largest rectangle area is `1`.
2. For the second row: `heights = [2, 0, 2, 1, 1]`
   - The largest rectangle area is `3`.
3. For the third row: `heights = [3, 1, 3, 2, 2]`
   - The largest rectangle area is `6`.
4. For the fourth row: `heights = [4, 0, 0, 3, 0]`


   - The largest rectangle area is `3`.

Finally, the maximum area found through all iterations is `6`.

### Output
The function returns the maximum area of `6`, which is the area of the largest rectangle filled with `1s` in the given matrix.

### Space Complexity:
- The space complexity is **O(N)** due to the use of the stack and auxiliary arrays for each row.

This is an efficient solution for the maximal rectangle problem in a binary matrix.

### Conclusion
The code efficiently computes the largest rectangle area in a binary matrix using the concept of histogram and stack. Each step is crucial in building up to the final result, ensuring that every height and width calculation is accurate for determining the maximal rectangle area. If you have any further questions or need clarification on specific parts, feel free to ask!
