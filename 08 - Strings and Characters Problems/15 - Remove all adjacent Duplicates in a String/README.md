

<h1 align='center'>Remove - All - Adjacent - Duplicates - in - String</h1>

## Problem Statement

**Problem URL :** [Remove all adjacent Duplicates in String](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/)

![image](https://github.com/user-attachments/assets/164eda3d-cff8-4c63-bb5d-7a4e168cea14)

## Problem Explanation

**Description:**
You are given a string `s`. Your task is to remove all adjacent duplicate characters in the string. This process should be repeated until no more adjacent duplicates can be removed. The final string should be returned after all possible adjacent duplicates have been removed.

**Example:**
- **Input:** `"abbaca"`
- **Output:** `"ca"`

**Explanation:** 
1. Remove the adjacent duplicates `"bb"`, resulting in `"aaca"`.
2. Remove the adjacent duplicates `"aa"`, resulting in `"ca"`.

### Solution Approach:

The approach to solve this problem efficiently is to use a stack-based method. Here’s how the solution works:

1. **Use a Stack (or Equivalent):** Utilize a string to simulate the stack behavior where we can efficiently manage the characters and remove duplicates.
2. **Iterate Over Characters:** Traverse the given string and process each character to handle adjacent duplicates.
3. **Check and Remove Duplicates:** For each character, check if it is the same as the last character in the stack (or string). If it is, remove the last character (simulating a pop operation). If it isn’t, add the current character to the stack (or string).

## Problem Solution
```cpp
class Solution {
public:
    string removeDuplicates(string s) {
        string ans;

        for(auto ch : s){
            if(!ans.empty() && ans.back() == ch){
                ans.pop_back();
            }else{
                ans.push_back(ch);
            }
        }

        return ans;
    }
};
```

## Problem Solution Explanation

Here is the code with line-by-line explanations:


1. **Initialization:**
   ```cpp
   string ans;
   ```
   - **`ans`:** An empty string is initialized to act like a stack. It will be used to store characters as we process the input string.

2. **Iterating Through Characters:**
   ```cpp
   for(auto ch : s){
   ```
   - **`for(auto ch : s)`:** This loop iterates through each character `ch` in the input string `s`.

3. **Checking for Adjacent Duplicates:**
   ```cpp
   if(!ans.empty() && ans.back() == ch){
   ```
   - **`!ans.empty() && ans.back() == ch`:** This condition checks if the `ans` string is not empty and if the last character in `ans` is the same as the current character `ch`. If both conditions are true, it indicates an adjacent duplicate.

4. **Removing Duplicates:**
   ```cpp
   ans.pop_back();
   ```
   - **`ans.pop_back()`:** If there is an adjacent duplicate, the last character in `ans` is removed (simulating a stack pop operation).

5. **Adding Characters:**
   ```cpp
   ans.push_back(ch);
   ```
   - **`ans.push_back(ch)`:** If there is no adjacent duplicate, the current character `ch` is added to `ans`.

6. **Returning the Result:**
   ```cpp
   return ans;
   ```
   - **`return ans`:** After processing all characters, `ans` contains the string with all adjacent duplicates removed, which is then returned.

### Example Walkthrough:

**Example Input:**
```
s = "abbaca"
```

**Steps:**
1. **Initial String:** `ans = ""`
2. **Process `'a'`:** `ans = "a"`
3. **Process `'b'`:** `ans = "ab"`
4. **Process `'b'`:** `ans = "a"` (since `'b'` matches the last `'b'`, remove `'b'`)
5. **Process `'a'`:** `ans = "aa"`
6. **Process `'c'`:** `ans = "aac"`
7. **Process `'a'`:** `ans = "ca"` (since `'a'` matches the last `'a'`, remove `'a'`)

**Final Output:**
```
"ca"
```

### How the Solution Works:

- **Simulates Stack Behavior:** The `ans` string simulates stack behavior where we can efficiently add or remove characters based on the condition of adjacent duplicates.
- **Efficient Removal:** The approach ensures that we efficiently remove adjacent duplicates in a single pass through the string. Each character is processed once, leading to a time complexity of O(n), where n is the length of the string. The space complexity is also O(n) due to the use of the `ans` string.

This method is both time-efficient and easy to implement, making it a suitable approach for solving the problem of removing adjacent duplicates in a string.
