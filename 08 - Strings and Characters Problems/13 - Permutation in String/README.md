<h1 align='center'>Permutation - in - String</h1>

## Problem Statement

**Problem URL :** [Permutation in String](https://leetcode.com/problems/permutation-in-string/)

![image](https://github.com/user-attachments/assets/6e3c98cb-4358-4a2c-9fdf-2fae279986d6)

### Problem Explanation

You are given two strings `s1` and `s2`. You need to determine if some permutation of `s1` is a **substring** of `s2`. In other words, you need to check if any permutation of `s1` exists in `s2`.

A **permutation** of a string is any rearrangement of the characters of that string.

### Example:
- **Input:** `s1 = "ab"`, `s2 = "eidbaooo"`
- **Output:** `true`
  
  Explanation: The permutation "ba" of `s1` is present in `s2` starting at index 3.

### Approach:

The problem can be solved by using a **sliding window** approach. Essentially, you want to slide a window of size equal to `s1` over `s2` and check if any of the substrings in that window is a permutation of `s1`.

## Problem Solution
```cpp
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int win_size = s1.length();
        int s2_len = s2.length();

        if(win_size > s2_len) return false;

        vector<int> s1_(26, 0), s2_(26, 0);

        for(int i = 0; i < win_size; i++){
            s1_[s1[i] - 'a']++;
            s2_[s2[i] - 'a']++;
        }

        if(s1_ == s2_) return true;

        for(int i = win_size; i < s2_len; i++){
            s2_[s2[i] - 'a']++;
            s2_[s2[i - win_size] - 'a']--;

            if(s1_ == s2_) return true;
        }

        return false;
    }
};
```

## Problem Solution Explanation
The provided code solves the problem using a **sliding window** and **frequency counting** approach. Let's break down the code and understand how it works step-by-step:

```cpp
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
```

- **Line 1:** We define a class `Solution` with a public method `checkInclusion` that takes two strings, `s1` and `s2`, as input.
- **Purpose:** This method will check if any permutation of `s1` exists as a substring in `s2`.

```cpp
        int win_size = s1.length();
        int s2_len = s2.length();
```

- **Line 2:** We calculate the length of `s1` and store it in `win_size`. This represents the size of the window we will slide over `s2`.
- **Line 3:** We calculate the length of `s2` and store it in `s2_len`.

```cpp
        if(win_size > s2_len) return false;
```

- **Line 4:** If the length of `s1` (i.e., `win_size`) is greater than the length of `s2`, it’s impossible for any permutation of `s1` to be in `s2`. So, in this case, we return `false`.

```cpp
        vector<int> s1_(26, 0), s2_(26, 0);
```

- **Line 5:** We create two vectors of size 26 (one for each letter of the alphabet). The vector `s1_` will store the frequency of each letter in `s1`, and `s2_` will store the frequency of the letters in the current window of `s2`.

```cpp
        for(int i = 0; i < win_size; i++){
            s1_[s1[i] - 'a']++;
            s2_[s2[i] - 'a']++;
        }
```

- **Line 6-9:** This loop goes over the first `win_size` characters of both `s1` and `s2`.
  - For each character in `s1`, we update the `s1_` vector by incrementing the frequency count for that character.
  - Similarly, we update the `s2_` vector for the first `win_size` characters of `s2` to track the character frequencies in this window.

```cpp
        if(s1_ == s2_) return true;
```

- **Line 10:** After initializing the frequency arrays for `s1` and the first window of `s2`, we check if the frequencies match (i.e., if the current window is a permutation of `s1`). If they are equal, we return `true`.

```cpp
        for(int i = win_size; i < s2_len; i++){
            s2_[s2[i] - 'a']++;
            s2_[s2[i - win_size] - 'a']--;
```

- **Line 11-14:** This is the **sliding window loop**.
  - For each character starting from index `win_size`, we slide the window over `s2`:
    - We add the character `s2[i]` (new character entering the window) to `s2_` by incrementing its frequency.
    - We remove the character `s2[i - win_size]` (character leaving the window) from `s2_` by decrementing its frequency.

```cpp
            if(s1_ == s2_) return true;
```

- **Line 15:** After updating the frequencies, we check if the frequency array `s2_` matches `s1_`. If they match, it means the current window of `s2` is a permutation of `s1`, so we return `true`.

```cpp
        }

        return false;
```

- **Line 16:** If the loop finishes without finding any matching window, we return `false`, meaning no permutation of `s1` exists as a substring in `s2`.

---

### Example Walkthrough:

#### Input:
```cpp
s1 = "ab"
s2 = "eidbaooo"
```

1. **Step 1:** Initialize `win_size = 2` (length of `s1`) and `s2_len = 8` (length of `s2`).
2. **Step 2:** Build frequency arrays for the first two characters of both `s1` and `s2`.
   - For `s1 = "ab"`, the frequency array is `[1, 1, 0, 0, 0, ...]` (1 occurrence of 'a' and 1 occurrence of 'b').
   - For the first window of `s2 = "ei"`, the frequency array is `[0, 0, 1, 0, 1, ...]` (1 occurrence of 'e' and 1 occurrence of 'i').
   - These don't match, so we slide the window.

3. **Step 3:** Slide the window over `s2`:
   - New window: "id" (slide one position to the right).
   - Update the frequency array for the new window.
   - Check if the frequency arrays match. They don’t.

4. **Step 4:** Continue sliding until the window is "ba":
   - The frequency array for "ba" matches the frequency array for `s1`.
   - Return `true`, since "ba" is a permutation of `s1`.

This is how the code efficiently solves the problem using the sliding window technique and frequency counting.


### How This Code Solves the Problem:

- The code checks all possible substrings of `s2` that are the same length as `s1` to see if any of them are a permutation of `s1`.
- It efficiently tracks the frequency of characters using two vectors (`s1_` and `s2_`) for the current window of `s2` and updates them as the window slides across `s2`.
- Instead of generating all possible permutations of `s1` and then searching them in `s2` (which would be computationally expensive), the code cleverly uses frequency counting and compares the frequency arrays.

---

### Time Complexity:

- The time complexity is O(n), where `n` is the length of `s2`. This is because the sliding window iterates over each character of `s2` exactly once, and each comparison of frequency arrays takes constant time (since they are fixed in size, 26 for lowercase letters).
  
### Space Complexity:

- The space complexity is O(1), as we only use fixed-size vectors of length 26 to store character frequencies.

This approach efficiently solves the problem using the sliding window technique and frequency counting.
