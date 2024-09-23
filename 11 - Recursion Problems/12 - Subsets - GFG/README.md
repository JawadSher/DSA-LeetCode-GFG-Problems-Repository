<h1 align='center'>Subsets</h1>

## Problem Statement

**Problem URL :** [Subsets](https://www.geeksforgeeks.org/problems/subsets-1613027340/0)

![image](https://github.com/user-attachments/assets/24a12e88-8ecc-4a76-9255-19497f499fe3)
![image](https://github.com/user-attachments/assets/6ece8475-2bd5-4cc1-88ee-3bbdb9a43be2)

## Problem Solution
```cpp
class Solution {
  private:
    void solve(vector<int> &nums, vector<vector<int>> &answer, vector<int> output, int index){
        if(index >= nums.size()){
            answer.push_back(output);
            
            return;
        }
        
        solve(nums, answer, output, index+1);
        
        int element = nums[index];
        output.push_back(element);
        
        solve(nums, answer, output, index+1);
    }
  public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> output;
        int index = 0;
        
        solve(nums, answer, output, index);
        
        sort(answer.begin(), answer.end());
        
        return answer;
    }
};
```

## Problem Solution Explanation
Here’s a line-by-line explanation of the provided code for generating subsets:

```cpp
class Solution {
```
- Defines a class named `Solution`, which encapsulates the method to generate subsets of an array.

```cpp
private:
```
- Indicates that the following members (methods or variables) are accessible only within this class.

```cpp
    void solve(vector<int> &nums, vector<vector<int>> &answer, vector<int> output, int index){
```
- Defines a private method named `solve` that takes four parameters:
  - `vector<int> &nums`: A reference to the input vector of integers.
  - `vector<vector<int>> &answer`: A reference to the vector that stores all the generated subsets.
  - `vector<int> output`: The current subset being built (passed by value, so it’s a copy).
  - `int index`: The current position in the `nums` array being processed.

```cpp
        if(index >= nums.size()){
```
- Checks if the `index` is equal to or greater than the size of `nums`. This indicates that we have considered all elements.

```cpp
            answer.push_back(output);
```
- If the base case is met, it adds the current subset (`output`) to the `answer` vector.

```cpp
            return;
```
- Ends the current function call and returns control to the previous call in the recursion stack.

```cpp
        solve(nums, answer, output, index + 1);
```
- Makes a recursive call to `solve`, incrementing the `index` by 1. This call excludes the current element (at `index`) from the subset being built.

```cpp
        int element = nums[index];
```
- Retrieves the current element from `nums` at the specified `index` and stores it in the variable `element`.

```cpp
        output.push_back(element);
```
- Adds the current element to the `output` subset, indicating that this element will be included in the subset for the next recursive call.

```cpp
        solve(nums, answer, output, index + 1);
```
- Makes another recursive call to `solve`, again incrementing the `index` by 1, but this time including the current element in the `output` subset.

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
- Defines a public method named `subsets` that returns a vector of vectors containing all subsets. It takes one parameter, a reference to a vector of integers `nums`.

```cpp
        vector<vector<int>> answer;
```
- Initializes a vector `answer` that will store all the generated subsets.

```cpp
        vector<int> output;
```
- Initializes a vector `output` to build the current subset as we explore the possibilities.

```cpp
        int index = 0;
```
- Sets the starting index to `0`, which will be used to track our position in the `nums` array.

```cpp
        solve(nums, answer, output, index);
```
- Calls the recursive `solve` method to start generating subsets, passing in the initial parameters.

```cpp
        sort(answer.begin(), answer.end());
```
- Sorts the `answer` vector to ensure that the subsets are in a consistent order. (This step is optional based on whether order matters in the output.)

```cpp
        return answer;
```
- Returns the `answer` vector, which now contains all the generated subsets.

```cpp
    }
};
```
- Closes the `subsets` method and the `Solution` class.

### Summary with Example

For `nums = [1, 2]`, the function works as follows:

1. **First call to `solve`**:
   - **Index 0**: Excludes `1`, moves to index `1`.
   - Calls `solve(nums, answer, output, 1)`.

2. **Second call to `solve`**:
   - **Index 1**: Excludes `2`, moves to index `2`.
   - Calls `solve(nums, answer, output, 2)`.

3. **Base case reached**:
   - Adds `[]` (empty subset) to `answer`.

4. **Backtracking**:
   - Includes `2`, resulting in `[2]`, then adds it to `answer`.
   
5. **Backtrack to first call**:
   - Includes `1`, then moves to index `1` again.
   - Excludes `2`, adding `[1]` to `answer`.
   - Includes `2`, adding `[1, 2]` to `answer`.

Final `answer` would contain: `[[], [2], [1], [1, 2]]`.

This explanation provides a clearer understanding of how the code operates, detailing each part of the recursive process for generating subsets.
