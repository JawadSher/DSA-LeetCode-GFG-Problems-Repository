<h1 align='center'>Rotate - Array</h1>

## Problem Statement

**Problem URL :** [Rotate Array](https://leetcode.com/problems/rotate-array/)

![image](https://github.com/user-attachments/assets/317b44ba-14a9-4b52-9633-03b5550319d0)
![image](https://github.com/user-attachments/assets/986fbdb6-b3cb-4f45-85d2-ef8005d617c5)

## Problem Explanation

The "Rotate Array" problem on LeetCode requires you to rotate an array of integers to the right by `k` steps. Here’s what this means:

1. **Array Rotation**: To "rotate" an array means to shift all elements to the right (or left) by a certain number of positions. Elements that are shifted beyond the end of the array wrap around to the beginning.

2. **Right Rotation**: In the problem, you are specifically asked to perform a right rotation, which means elements move towards the end of the array. If they reach the last position, they wrap around to the first position.

3. **Number of Steps (k)**: The problem asks you to rotate the array by `k` steps. For example, if `k` is 2, each element of the array should be moved 2 positions to the right.

Let’s break down the problem statement with an example.

**Example:**
- **Input**: `nums = [1, 2, 3, 4, 5, 6, 7]`, `k = 3`
- **Output**: `[5, 6, 7, 1, 2, 3, 4]`

**Explanation**:

- Start with the array: `[1, 2, 3, 4, 5, 6, 7]`.
- After rotating by 1 step to the right, it becomes: `[7, 1, 2, 3, 4, 5, 6]`.
- After rotating by 2 steps to the right, it becomes: `[6, 7, 1, 2, 3, 4, 5]`.
- After rotating by 3 steps to the right, it becomes: `[5, 6, 7, 1, 2, 3, 4]`.

## Problem Solution
```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> rotated(n);

        for(int i = 0; i < n; i++){
            rotated[(i+k)%n] = nums[i];
        }

        nums = rotated;
    }
};
```

## Problem Solution Explanation
Here’s a step-by-step breakdown of the provided solution:

1. **Line 1**: `class Solution { public: ... };`
   - This is the declaration of the `Solution` class, which is typical in LeetCode solutions.

2. **Line 3**: `void rotate(vector<int>& nums, int k) {`
   - This line defines a function named `rotate` that takes two parameters: `nums`, a reference to a vector of integers, and `k`, an integer representing the number of steps to rotate the array.

3. **Line 4**: `int n = nums.size();`
   - The size of the `nums` array is calculated and stored in the variable `n`. This represents the number of elements in the array.

4. **Line 6**: `vector<int> rotated(n);`
   - A new vector called `rotated` is created with the same size as `nums`. This will hold the elements in their rotated positions.

5. **Line 8**: `for(int i = 0; i < n; i++){`
   - A loop starts that iterates over each index `i` of the original `nums` array.

6. **Line 9**: `rotated[(i+k)%n] = nums[i];`
   - Each element of `nums` is placed into its new position in the `rotated` array. The new position is calculated as `(i + k) % n`. This formula ensures that the index wraps around if it goes beyond the length of the array, effectively rotating the elements.

   **Example Calculation:**
   - If `i = 0` and `k = 3` in an array of size `n = 7`, the new position of `nums[0]` (`1`) would be `(0 + 3) % 7 = 3`. So, `rotated[3] = 1`.

7. **Line 11**: `nums = rotated;`
   - The `rotated` array, now containing the elements in their correct rotated positions, is copied back into `nums`, effectively updating the original array.

### Example Walkthrough:

Let’s walk through the code using an example:

- **Initial Array**: `nums = [1, 2, 3, 4, 5, 6, 7]`
- **k = 3**:
  
  1. Initialize `n = 7` and `rotated = [0, 0, 0, 0, 0, 0, 0]`.
  
  2. For each `i` from `0` to `6` (the indices of `nums`):
  
     - `i = 0`: Place `nums[0]` (which is `1`) at position `(0+3)%7 = 3` in `rotated`. Now, `rotated = [0, 0, 0, 1, 0, 0, 0]`.
     - `i = 1`: Place `nums[1]` (which is `2`) at position `(1+3)%7 = 4` in `rotated`. Now, `rotated = [0, 0, 0, 1, 2, 0, 0]`.
     - `i = 2`: Place `nums[2]` (which is `3`) at position `(2+3)%7 = 5` in `rotated`. Now, `rotated = [0, 0, 0, 1, 2, 3, 0]`.
     - `i = 3`: Place `nums[3]` (which is `4`) at position `(3+3)%7 = 6` in `rotated`. Now, `rotated = [0, 0, 0, 1, 2, 3, 4]`.
     - `i = 4`: Place `nums[4]` (which is `5`) at position `(4+3)%7 = 0` in `rotated`. Now, `rotated = [5, 0, 0, 1, 2, 3, 4]`.
     - `i = 5`: Place `nums[5]` (which is `6`) at position `(5+3)%7 = 1` in `rotated`. Now, `rotated = [5, 6, 0, 1, 2, 3, 4]`.
     - `i = 6`: Place `nums[6]` (which is `7`) at position `(6+3)%7 = 2` in `rotated`. Now, `rotated = [5, 6, 7, 1, 2, 3, 4]`.
  
  3. Finally, copy `rotated` back to `nums`. The final `nums` array is `[5, 6, 7, 1, 2, 3, 4]`.

### Conclusion

This method effectively rotates the array by utilizing a new vector to store the rotated elements, ensuring that each element is placed in its correct new position based on the rotation amount `k`. The complexity of this approach is O(n) due to the single pass through the array, and the space complexity is also O(n) due to the additional array used.
