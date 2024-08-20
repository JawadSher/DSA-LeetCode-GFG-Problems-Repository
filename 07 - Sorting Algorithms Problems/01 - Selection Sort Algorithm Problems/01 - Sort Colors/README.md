<h1 align='center'>Sort - Colors</h1>

## Problem Statement

![image](https://github.com/user-attachments/assets/01c427de-71b2-414c-874a-a624b1ff767d)

## Problem Explanation
### Problem Statement: "Sort Colors"

The "Sort Colors" problem is a popular question on LeetCode that tests your ability to implement sorting algorithms efficiently. The problem is based on the Dutch National Flag problem and requires sorting an array containing only three distinct integers: 0, 1, and 2.

#### Problem Description:
- **Input:** An array `nums` containing `n` integers where each integer is either `0`, `1`, or `2`.
- **Output:** The array should be sorted in-place so that all `0`s come first, followed by all `1`s, and then all `2`s.

You are required to solve this problem without using the library's sort function, with a time complexity of O(n), and using only constant space O(1).

**Example:**
```plaintext
Input: nums = [2, 0, 2, 1, 1, 0]
Output: [0, 0, 1, 1, 2, 2]
```

## Problem Solution 
```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] > nums[j]){
                    swap(nums[i], nums[j]);
                }
            }

        }
    }
};
```

## Problem Solution Explanation
Let's break down the code you've provided, line by line, and explain how it works using an example.

#### 1. Class and Function Declaration

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
```

- **`class Solution`:** This defines a class named `Solution`. In competitive programming platforms like LeetCode, the function to solve the problem is typically placed inside a class.
- **`void sortColors(vector<int>& nums)`:** This is a member function of the `Solution` class. It takes a reference to a vector of integers (`vector<int>& nums`) as input. The function returns `void`, meaning it doesn't return any value, but it modifies the input vector `nums` directly.

#### 2. Outer `for` Loop

```cpp
for(int i = 0; i < nums.size(); i++){
```

- **`for(int i = 0; i < nums.size(); i++)`:** This is a standard `for` loop that iterates over the entire array `nums`. The loop starts with `i = 0` and continues as long as `i` is less than the size of the array. The variable `i` acts as an index pointing to the current element being considered in the array.

#### 3. Inner `for` Loop

```cpp
for(int j = i + 1; j < nums.size(); j++){
```

- **`for(int j = i + 1; j < nums.size(); j++)`:** This is another `for` loop nested inside the first one. It starts with `j = i + 1`, meaning it begins from the element right after `i` and continues until the end of the array. The idea is to compare the element at index `i` with every element after it (from `i + 1` to the end of the array).

#### 4. `if` Condition to Compare Elements

```cpp
if(nums[i] > nums[j]){
```

- **`if(nums[i] > nums[j])`:** This `if` statement checks whether the element at index `i` is greater than the element at index `j`. If it is, then the elements are out of order and need to be swapped to sort the array.

#### 5. Swapping Elements

```cpp
swap(nums[i], nums[j]);
```

- **`swap(nums[i], nums[j])`:** If the condition in the `if` statement is true, this line swaps the elements at indices `i` and `j`. The `swap` function is a standard utility in C++ that exchanges the values of `nums[i]` and `nums[j]`.

#### 6. End of Loops and Function

```cpp
            }
        }
    }
};
```

- **End of the inner and outer loops:** Once the inner loop finishes, the outer loop continues to the next element in `nums`. This process repeats until the entire array has been sorted.
- **`}`:** These closing braces mark the end of the loops and the function.

### Example Walkthrough

Let's walk through an example to see how the code works in practice.

**Example Input:**
```plaintext
nums = [2, 0, 2, 1, 1, 0]
```

**Step-by-Step Execution:**

1. **Outer Loop (`i = 0`):**
   - Compare `nums[0] = 2` with `nums[1] = 0` → Swap: `nums = [0, 2, 2, 1, 1, 0]`
   - Compare `nums[0] = 0` with `nums[2] = 2` → No Swap
   - Compare `nums[0] = 0` with `nums[3] = 1` → No Swap
   - Compare `nums[0] = 0` with `nums[4] = 1` → No Swap
   - Compare `nums[0] = 0` with `nums[5] = 0` → No Swap

2. **Outer Loop (`i = 1`):**
   - Compare `nums[1] = 2` with `nums[2] = 2` → No Swap
   - Compare `nums[1] = 2` with `nums[3] = 1` → Swap: `nums = [0, 1, 2, 2, 1, 0]`
   - Compare `nums[1] = 1` with `nums[4] = 1` → No Swap
   - Compare `nums[1] = 1` with `nums[5] = 0` → Swap: `nums = [0, 0, 2, 2, 1, 1]`

3. **Outer Loop (`i = 2`):**
   - Compare `nums[2] = 2` with `nums[3] = 2` → No Swap
   - Compare `nums[2] = 2` with `nums[4] = 1` → Swap: `nums = [0, 0, 1, 2, 2, 1]`
   - Compare `nums[2] = 1` with `nums[5] = 1` → No Swap

4. **Outer Loop (`i = 3`):**
   - Compare `nums[3] = 2` with `nums[4] = 2` → No Swap
   - Compare `nums[3] = 2` with `nums[5] = 1` → Swap: `nums = [0, 0, 1, 1, 2, 2]`

5. **Outer Loop (`i = 4`):**
   - Compare `nums[4] = 2` with `nums[5] = 2` → No Swap

6. **Outer Loop (`i = 5`):**
   - No elements left to compare, loop ends.

**Final Output:**
```plaintext
nums = [0, 0, 1, 1, 2, 2]
```

### Summary

The provided code implements a simple sorting algorithm (similar to bubble sort) that sorts the array by repeatedly comparing and swapping elements. However, this solution has a time complexity of O(n²) due to the nested loops, which is not optimal for the "Sort Colors" problem. An optimal solution would use the Dutch National Flag algorithm, which has a time complexity of O(n).



