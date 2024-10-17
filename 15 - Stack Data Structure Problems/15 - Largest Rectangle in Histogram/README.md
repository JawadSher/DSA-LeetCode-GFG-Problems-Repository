<h1 align='center'>Largest - Rectangle - In - Histogram</h1>

## Problem Statement

**Problem URL :** [Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)

![image](https://github.com/user-attachments/assets/ee85472c-9d88-4ebe-b776-8b57fe596724)
![image](https://github.com/user-attachments/assets/ae4e3cd2-dca6-483c-8c87-166332be6aec)

## Problem Explanation

**Objective**: Given an array of integers representing the heights of bars in a histogram, find the area of the largest rectangle that can be formed within the bounds of the histogram.

### Approach

1. **Understanding the Histogram**:
   - Each integer in the array represents the height of a bar, and the width of each bar is `1`.
   - The problem involves finding the maximum rectangular area that can be formed using one or more consecutive bars.

2. **Using Stacks**:
   - To efficiently find the nearest smaller bars to the left and right of each bar, we can use stacks.
   - This will help us determine the boundaries of the rectangle for each bar.

3. **Calculate Area**:
   - For each bar, calculate the width of the rectangle by finding the next smaller and previous smaller elements.
   - The area can be computed as `height * width`, where:
     - Height is the height of the current bar.
     - Width is the distance between the next and previous smaller bars.
       
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
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> next(n);
        next = nextSmallerElementIndexes(heights, n);

        vector<int> prev(n);
        prev = prevSmallerElementIndexes(heights, n);

        int area = INT_MIN;

        for(int i = 0; i < n; i++){
            int l = heights[i];

            if(next[i] == -1) next[i] = n;

            int b = next[i] - prev[i] - 1;
            
            int newArea = l*b;
            area = max(area, newArea);
        }

        return area;
    }
};
```

## Problem Solution Explanation
Let's break down the provided C++ code for finding the largest rectangle area in a histogram. We'll start with the problem statement, then go through the code step-by-step, providing examples and explaining the complexity.

#### Helper Functions

1. **`nextSmallerElementIndexes`**:
   - **Purpose**: To find the index of the next smaller element for each bar in the histogram.
   - **Logic**:
     - Iterate through the heights array from right to left.
     - Use a stack to keep track of indices.
     - For each element, pop elements from the stack until the top of the stack is smaller than the current element.
     - The top of the stack will be the index of the next smaller element.

```cpp
vector<int> nextSmallerElementIndexes(vector<int> arr, int n){
    stack<int> st;
    vector<int> ans(n);
    st.push(-1);  // Sentinel value

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
```

#### Example for `nextSmallerElementIndexes`

**Input**: `arr = [2, 1, 5, 6, 2, 3]`

- **Output**: `[-1, 4, 4, 4, -1, -1]`
  - For the bar at index `0` (height `2`), the next smaller bar is at index `1` (height `1`).
  - For the bar at index `1` (height `1`), there is no smaller bar, so the output is `-1`.
  - For the bar at index `2` (height `5`), the next smaller bar is at index `4` (height `2`), and so on.

---

2. **`prevSmallerElementIndexes`**:
   - **Purpose**: To find the index of the previous smaller element for each bar.
   - **Logic**:
     - Iterate through the heights array from left to right.
     - Use a stack to keep track of indices.
     - For each element, pop elements from the stack until the top of the stack is smaller than the current element.
     - The top of the stack will be the index of the previous smaller element.

```cpp
vector<int> prevSmallerElementIndexes(vector<int> arr, int n){
    stack<int> st;
    vector<int> ans(n);
    st.push(-1);  // Sentinel value

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
```

#### Example for `prevSmallerElementIndexes`

**Input**: `arr = [2, 1, 5, 6, 2, 3]`

- **Output**: `[-1, -1, 1, 2, 1, 4]`
  - For the bar at index `0` (height `2`), there is no smaller bar before it, so the output is `-1`.
  - For the bar at index `1` (height `1`), there is no smaller bar before it, so the output is `-1`.
  - For the bar at index `2` (height `5`), the previous smaller bar is at index `1` (height `1`), and so on.

---

#### `largestRectangleArea`

- **Purpose**: This is the main function that calculates the maximum rectangular area in the histogram.
- **Logic**:
  - First, get the next and previous smaller element indices for each bar.
  - For each bar, compute the width of the rectangle formed using the indices found.
  - Calculate the area as `height * width` and update the maximum area found.

```cpp
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();

    vector<int> next(n);
    next = nextSmallerElementIndexes(heights, n);

    vector<int> prev(n);
    prev = prevSmallerElementIndexes(heights, n);

    int area = INT_MIN;

    for(int i = 0; i < n; i++){
        int l = heights[i];

        if(next[i] == -1) next[i] = n;

        int b = next[i] - prev[i] - 1;
        
        int newArea = l*b;
        area = max(area, newArea);
    }

    return area;
}
```

### Example Walkthrough for `largestRectangleArea`

**Input**: `heights = [2, 1, 5, 6, 2, 3]`

1. **Find Next Smaller Indices**: `next = [-1, 4, 4, 4, -1, -1]`
2. **Find Previous Smaller Indices**: `prev = [-1, -1, 1, 2, 1, 4]`
3. **Calculate Areas**:
   - For bar `0`: `height = 2`, `width = 4 - (-1) - 1 = 4`, area = `2 * 4 = 8`
   - For bar `1`: `height = 1`, `width = 4 - (-1) - 1 = 4`, area = `1 * 4 = 4`
   - For bar `2`: `height = 5`, `width = 4 - 1 - 1 = 2`, area = `5 * 2 = 10`
   - For bar `3`: `height = 6`, `width = 4 - 2 - 1 = 1`, area = `6 * 1 = 6`
   - For bar `4`: `height = 2`, `width = 6 - 1 - 1 = 4`, area = `2 * 4 = 8`
   - For bar `5`: `height = 3`, `width = 6 - 4 - 1 = 1`, area = `3 * 1 = 3`

4. **Maximum Area**: The maximum area found is `10`.

---

### Complexity Analysis

- **Time Complexity**:
  - Each of the helper functions (`nextSmallerElementIndexes` and `prevSmallerElementIndexes`) runs in O(n) time.
  - The overall time complexity for `largestRectangleArea` is O(n) because it combines the results of these functions and processes each bar in the histogram.

- **Space Complexity**:
  - The space complexity is O(n) for storing the `next` and `prev` arrays and the stack used in the helper functions.

---

### Summary

The provided code effectively calculates the largest rectangle area in a histogram using stacks to find the next and previous smaller elements for each bar. The approach is efficient, operating in linear time and using a straightforward method to compute areas based on the boundaries determined by these smaller elements.
