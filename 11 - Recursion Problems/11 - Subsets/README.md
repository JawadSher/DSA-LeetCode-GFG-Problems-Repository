<h1 align='center'>Subsets</h1>

## Problem Statement

**Problem URL :** [Subsets](https://leetcode.com/problems/subsets/)

![image](https://github.com/user-attachments/assets/13d44ab4-6a2b-4ed4-88c8-c952e21bddbf)

Given an integer array `nums` of **unique elements**, your task is to return **all possible subsets** (the power set) of the array. The solution **must not contain duplicate subsets**.

**Constraints**:
- All elements in `nums` are unique.
- The order of the subsets does not matter, but the contents of the subsets must be unique.

### Example:
**Input**: `nums = [1, 2, 3]`  
**Output**: `[[], [1], [2], [3], [1, 2], [1, 3], [2, 3], [1, 2, 3]]`

### Problem Breakdown:
- A **subset** is any combination of elements from the original array (including the empty set and the set itself).
- The goal is to generate all possible subsets of the given array, including the empty set.
- The array is unique, so there are no duplicate elements to handle.
  
### Approach: Recursion (Backtracking)

#### Key Idea:
We use a **recursive approach** to build subsets step by step. At each index, we decide whether to:
1. **Exclude** the current element from the subset.
2. **Include** the current element in the subset.

This results in a decision tree, where each node corresponds to a decision of whether to include an element or not.

#### Steps:
1. **Recursive Function**:
   - Start from the first element (index `0`).
   - For each element, either:
     - **Exclude** it (move to the next element without adding it to the current subset).
     - **Include** it (add the element to the current subset and move to the next).
   - When all elements have been processed (i.e., when the index exceeds the size of the array), add the current subset to the answer list.

2. **Base Case**:
   - When we have processed all elements (i.e., `index >= nums.size()`), we add the current subset to the list of answers.

3. **Recursive Calls**:
   - We make two recursive calls at each step:
     - One that **excludes** the current element.
     - One that **includes** the current element.


### Detailed Explanation with Examples:

#### Example 1: `nums = [1, 2]`

1. **Start with the first element (1)**:
   - Exclude 1: Call the function recursively for the rest of the array (`nums = [2]`).
   - Include 1: Add 1 to the current subset and call the function recursively for the rest of the array.

2. **Process the second element (2)**:
   - Exclude 2: If the subset so far is empty, the result is still `[]`.
   - Include 2: Add 2 to the current subset.

3. **End of array**:
   - At each recursive call, when we reach the end of the array (i.e., when `index >= nums.size()`), we add the current subset to the answer.

The recursive tree for `nums = [1, 2]` looks like this:

```
              []
            /    \
          []     [1]
         /  \    /   \
       []  [2]  [1]  [1, 2]
```

**Final subsets**: `[], [2], [1], [1, 2]`

#### Example 2: `nums = [1, 2, 3]`

```
                               []
                            /      \
                         []         [1]
                       /   \       /   \
                    []   [2]    [1]   [1, 2]
                   /  \   /  \   /  \   /   \
                 [] [3] [2] [2, 3] [1] [1, 3] [1, 2] [1, 2, 3]
```

**Final subsets**: `[], [3], [2], [2, 3], [1], [1, 3], [1, 2], [1, 2, 3]`

## Problem Solution
```cpp
class Solution {
private:
    void solve(vector<int> &nums, vector<int> output, int index, vector<vector<int>> &answer){
        if(index >= nums.size()){
            answer.push_back(output);
            return;
        }

        // exclude
        solve(nums, output, index+1, answer);

        // include
        int element = nums[index];
        output.push_back(element);
        solve(nums, output, index+1, answer);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> output;
        int index = 0;

        solve(nums, output, index, answer);

        return answer;
    }
};
```

## Problem Solution Explanation

Sure! Here’s a detailed line-by-line explanation of the code:

```cpp
class Solution {
```
- This line defines a class named `Solution`, which will contain methods to solve the problem.

```cpp
private:
```
- This access specifier indicates that the following methods and variables are only accessible within this class.

```cpp
    void solve(vector<int> &nums, vector<int> output, int index, vector<vector<int>> &answer) {
```
- Defines a private method `solve` that takes four parameters:
  - `vector<int> &nums`: A reference to the input vector of integers.
  - `vector<int> output`: The current subset being built (passed by value).
  - `int index`: The current index in the `nums` array.
  - `vector<vector<int>> &answer`: A reference to the vector that will store all the subsets.

```cpp
        if(index >= nums.size()) {
```
- Checks if the `index` has reached or exceeded the size of `nums`, indicating that all elements have been processed.

```cpp
            answer.push_back(output);
```
- If the base case is met, it adds the current subset (`output`) to the `answer` vector.

```cpp
            return;
```
- Ends the current function call, returning control back to the previous call in the recursion stack.

```cpp
        // Recursive step: EXCLUDE the current element
        solve(nums, output, index + 1, answer);
```
- Makes a recursive call to `solve`, moving to the next index (`index + 1`) without including the current element in the subset.

```cpp
        // Recursive step: INCLUDE the current element
        int element = nums[index];
```
- Stores the current element from `nums` at `index` into the variable `element`.

```cpp
        output.push_back(element);
```
- Adds the current element to the `output` subset, indicating that this element will be included.

```cpp
        solve(nums, output, index + 1, answer);
```
- Makes another recursive call to `solve`, moving to the next index while including the current element in the subset.

```cpp
    }
```
- Closes the `solve` method.

```cpp
public:
```
- This access specifier indicates that the following methods are accessible from outside the class.

```cpp
    vector<vector<int>> subsets(vector<int>& nums) {
```
- Defines a public method `subsets` that returns a vector of vectors containing all subsets. It takes one parameter, a reference to a vector of integers `nums`.

```cpp
        vector<vector<int>> answer;
```
- Initializes a vector `answer` that will store all the subsets generated.

```cpp
        vector<int> output;
```
- Initializes a vector `output` to build the current subset as we explore the possibilities.

```cpp
        int index = 0;
```
- Sets the starting index to `0`, which will be used to track our position in the `nums` array.

```cpp
        solve(nums, output, index, answer);
```
- Calls the recursive `solve` method to start generating subsets, passing in the initial parameters.

```cpp
        return answer;
```
- Returns the `answer` vector, which now contains all the subsets generated.

```cpp
    }
};
```
- Closes the `subsets` method and the `Solution` class.

### Summary with Example

For `nums = [1, 2]`, the function works as follows:

1. **First call to `solve`**:
   - **Index 0**: Excludes `1`, moves to index `1`.
   - Calls `solve(nums, output, 1, answer)`.

2. **Second call to `solve`**:
   - **Index 1**: Excludes `2`, moves to index `2`.
   - Calls `solve(nums, output, 2, answer)`.

3. **Base case reached**:
   - Adds `[]` (empty subset) to `answer`.

4. **Backtracking**:
   - Includes `2`, resulting in `[2]`, then adds it to `answer`.
   
5. **Backtrack to first call**:
   - Includes `1`, then moves to index `1` again.
   - Excludes `2`, adding `[1]` to `answer`.
   - Includes `2`, adding `[1, 2]` to `answer`.

Final `answer` would contain: `[[], [2], [1], [1, 2]]`.

This line-by-line explanation provides a clearer understanding of how the code works and how it generates all subsets through recursion.


### Time Complexity:
- **O(2^n)**: Each element can either be included or excluded, leading to \(2^n\) subsets.
- **O(n * 2^n)** for time: Since each subset can take `O(n)` to construct and we generate \(2^n\) subsets.

### Space Complexity:
- **O(n)**: Due to the recursion stack and storage of subsets in the answer.

This approach ensures we explore all possibilities for each element (either include or exclude), and we efficiently build all subsets recursively.
