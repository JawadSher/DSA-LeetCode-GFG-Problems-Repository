<h1 align="center">Longest - Arithmetic - Subsequence of - Given Difference</h1>

## Problem Statement

**Problem URL :** [Longest Arithmetic Subsequence of Given Difference](https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/)

![image](https://github.com/user-attachments/assets/c2ceec99-2f4c-4067-8bce-36df38825f26)

### Problem Explanation
The problem is titled **"Longest Arithmetic Subsequence of Given Difference"**. The goal is to find the length of the longest subsequence of a given array such that the difference between consecutive elements of the subsequence is a constant value `difference`.

#### **Definition of the Problem:**
Given an array `arr` and an integer `difference`, the task is to find the length of the longest subsequence of `arr` where the difference between every two consecutive elements is exactly equal to `difference`.

**Subsequence**: A subsequence is derived by deleting some or none of the elements of the array, without changing the order of the remaining elements.

**Example**:

- Input: 
  ```
  arr = [1, 5, 7, 8, 5, 3, 4, 2, 1], difference = 2
  ```

- **Explanation**:
  We need to find the longest subsequence where the difference between consecutive elements is `2`.

  One possible subsequence is:
  ```
  [1, 3, 5, 7]  →  (difference between consecutive elements is 2)
  ```
  This is a subsequence with a length of 4, and there is no longer subsequence with the given difference.

- **Output**: 
  ```
  4
  ```

The goal is to output the length of the longest such subsequence.

### Approach to the Code:

The approach used in the given solution leverages **dynamic programming (DP)** and **hash maps (unordered_map)** to store the length of the longest subsequences with specific differences.

#### Steps:

1. **Initialize a HashMap `dp`**: 
   - `dp` will store the longest subsequence length for each possible number in the array, based on the given difference.
   - The key in the map is the number itself, and the value is the length of the longest subsequence ending at that number.

2. **Iterate Through Each Element**:
   - For each element `arr[i]`, compute the `temp` value, which is `arr[i] - difference`. This is the value that would precede `arr[i]` in an arithmetic subsequence with the given `difference`.
   
3. **Check if a Valid Subsequence Exists**:
   - If `temp` is present in the map `dp`, it means that there is an arithmetic subsequence ending with `temp`. In this case, the subsequence can be extended by adding `arr[i]`, so the length of the subsequence ending at `arr[i]` is `dp[temp] + 1`.
   - If `temp` is not found in the map, we initialize the subsequence ending at `arr[i]` with length `1` (it is a subsequence of just itself).

4. **Update the DP Map**:
   - After determining the length of the subsequence ending at `arr[i]`, update the map `dp[arr[i]]` to the new length.

5. **Track the Maximum Length**:
   - Keep track of the maximum subsequence length found so far using the variable `ans`.

6. **Return the Result**:
   - Once all elements have been processed, the variable `ans` holds the length of the longest subsequence with the given difference.

## Problem Solution
```cpp
class Solution {
public:
    // Function to find the length of the longest arithmetic subsequence with the given difference
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();  // Get the size of the input array
        unordered_map<int, int> dp;  // Map to store the longest subsequence length for each element

        int ans = 0;  // Variable to store the maximum length of any subsequence found so far

        // Iterate through each element of the array
        for(int i = 0; i < n; i++) {
            // Calculate the previous element in the subsequence with the given difference
            int temp = arr[i] - difference;

            // If there's a subsequence ending with `temp`, we get its length from dp. If not, set prevAns to 0
            int prevAns = dp.count(temp) ? dp[temp] : 0;

            // Update the longest subsequence ending at arr[i], adding 1 to the length of the previous subsequence
            dp[arr[i]] = 1 + prevAns;

            // Update the maximum subsequence length found so far
            ans = max(ans, dp[arr[i]]);
        }

        // Return the maximum length of the subsequence found
        return ans;
    }
};
```

## Problem Solution Explanation

```cpp
int longestSubsequence(vector<int>& arr, int difference) {
    int n = arr.size();
    unordered_map<int, int> dp;
    int ans = 0;
```
- `n = arr.size()`: The length of the input array `arr` is stored in `n`.
- `unordered_map<int, int> dp`: This hash map will store the length of the longest subsequence for each number as a key.
- `int ans = 0`: This variable will hold the maximum length of the subsequence found.

```cpp
    for(int i = 0; i < n; i++){
        int temp = arr[i] - difference;
        int prevAns = dp.count(temp) ? dp[temp] : 0;
```
- The loop iterates through each element `arr[i]` of the array.
- `int temp = arr[i] - difference`: For each `arr[i]`, the value `temp` is the number that would precede it in the subsequence (i.e., `arr[i] - difference`).
- `int prevAns = dp.count(temp) ? dp[temp] : 0`: If `temp` is found in the map `dp`, we fetch the value `dp[temp]`, which is the length of the longest subsequence ending at `temp`. If `temp` is not found, `prevAns` is initialized to `0` because no subsequence exists ending with `temp`.

```cpp
        dp[arr[i]] = 1 + prevAns;
        ans = max(ans, dp[arr[i]]);
    }
```
- `dp[arr[i]] = 1 + prevAns`: Update the length of the longest subsequence ending at `arr[i]`. If `temp` exists in `dp`, we extend the subsequence by 1. Otherwise, the subsequence only consists of `arr[i]` itself, so the length is `1`.
- `ans = max(ans, dp[arr[i]])`: Update the maximum length `ans` with the longest subsequence found so far.

```cpp
    return ans;
}
```
- Finally, return `ans`, which holds the length of the longest subsequence with the given difference.

### Example Walkthrough:

#### Example 1:
- **Input**:
  ```
  arr = [1, 5, 7, 8, 5, 3, 4, 2, 1]
  difference = 2
  ```

1. **First iteration (i = 0)**:
   - `arr[i] = 1`
   - `temp = 1 - 2 = -1`
   - `dp[-1]` doesn't exist, so `prevAns = 0`.
   - `dp[1] = 1 + 0 = 1`.

2. **Second iteration (i = 1)**:
   - `arr[i] = 5`
   - `temp = 5 - 2 = 3`
   - `dp[3]` doesn't exist, so `prevAns = 0`.
   - `dp[5] = 1 + 0 = 1`.

3. **Third iteration (i = 2)**:
   - `arr[i] = 7`
   - `temp = 7 - 2 = 5`
   - `dp[5]` exists and has value `1`, so `prevAns = 1`.
   - `dp[7] = 1 + 1 = 2`.

4. **Fourth iteration (i = 3)**:
   - `arr[i] = 8`
   - `temp = 8 - 2 = 6`
   - `dp[6]` doesn't exist, so `prevAns = 0`.
   - `dp[8] = 1 + 0 = 1`.

5. **Subsequent iterations** follow the same logic, and `dp` gradually accumulates the lengths of valid subsequences.

- After processing all elements, the final answer is `4`, corresponding to the subsequence `[1, 3, 5, 7]`.

#### **Output**:
```
4
```

### Time and Space Complexity Analysis:

- **Time Complexity**:  
  - The algorithm iterates through the array once, and for each element, it performs constant-time operations (hash map lookups, insertions, and updates).
  - Thus, the time complexity is **O(n)**, where `n` is the number of elements in the array.

- **Space Complexity**:  
  - We use a hash map `dp` to store the longest subsequence length for each element. In the worst case, all elements in the array could have distinct differences, so the space used by the hash map is **O(n)**.
  - Therefore, the space complexity is **O(n)**.
