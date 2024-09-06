<h1 align='center'>Remove - All - Occurrences - of a - Substring</h1>

## Problem Statement

**Problem URL :** [Remove All Occurrences of a Substring](https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/)

![image](https://github.com/user-attachments/assets/026f573c-e368-4fa8-bd89-a7b66da3484e)
![image](https://github.com/user-attachments/assets/cb1ac857-c232-44cd-9de0-b5221bd45630)

You are given a string `s` and a substring `part`. You need to repeatedly remove all occurrences of the substring `part` from the string `s` until no occurrences of `part` are found.

**Function Signature:**

```cpp
string removeOccurrences(string s, string part)
```

**Input:**  
- `s`: A string containing alphanumeric characters.
- `part`: A non-empty substring that you need to remove from `s`.

**Output:**  
- Return the modified string `s` after all occurrences of `part` have been removed.

### Example 1:

**Input:**  
`s = "daabcbaabcbc"`  
`part = "abc"`

**Output:**  
`"dab"`

**Explanation:**  
- The substring "abc" is found at positions 2-4 and 6-8.
- After removing both occurrences of "abc", the string becomes `"dab"`.

### Example 2:

**Input:**  
`s = "axxxxyyyyb"`  
`part = "xy"`

**Output:**  
`"ab"`

**Explanation:**  
- The substring "xy" is found at positions 4-5 and 6-7.
- After removing both occurrences of "xy", the string becomes `"ab"`.

### Constraints:
- The string `s` can contain between 1 and 1000 characters.
- The substring `part` can contain between 1 and 100 characters.
- `s` and `part` consist of lowercase English letters.
  
## Problem Solution
```cpp
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length() != 0 && s.find(part) < s.length()){
            size_t pos = s.find(part);
            s.erase(pos, part.length());
        }
        return s;
    }
};
```

## Problem Solution Explanation

Now, let's break down the C++ solution step-by-step.

1. **`while(s.length() != 0 && s.find(part) < s.length())`:**
   - **`s.length() != 0`**: The loop runs as long as the string `s` is not empty.
   - **`s.find(part)`**: This function searches for the first occurrence of the substring `part` in `s`. If it finds `part`, it returns the position of the first occurrence. If `part` is not found, it returns `string::npos` (a constant value representing "not found").
   - The condition `s.find(part) < s.length()` checks if the substring `part` exists in `s`. If the position where `part` is found is less than the length of `s`, it indicates that `part` is present in the string, so the loop continues.
   - This loop continues removing occurrences of `part` until no more are found in the string.

2. **`size_t pos = s.find(part);`:**
   - This line finds the position of the first occurrence of the substring `part` in the string `s`.
   - `size_t` is an unsigned integer type that stores the position where the substring `part` starts in `s`.

3. **`s.erase(pos, part.length());`:**
   - This function erases a portion of the string `s` starting from position `pos` and removes `part.length()` characters.
   - `pos` is the starting index of the substring `part`, and `part.length()` gives the number of characters to remove (i.e., the length of `part`).
   - For example, if `s = "daabcbaabcbc"` and `part = "abc"`, and the first occurrence of "abc" is at position `2`, this will remove the characters from positions `2` to `4`, making the string `"dabaabcbc"`.

4. **`return s;`:**
   - Once all occurrences of the substring `part` are removed, the function returns the modified string `s`.

---

### Example Walkthrough:

Let’s go through the solution with the example:

#### Example 1:
```cpp
s = "daabcbaabcbc"
part = "abc"
```

**First Iteration:**
- `s.find(part)` returns `2` (the first occurrence of `"abc"`).
- The string becomes `"dabaabcbc"` after removing the first occurrence of `"abc"`.

**Second Iteration:**
- Now, `s.find(part)` returns `5` (the next occurrence of `"abc"` in the modified string).
- The string becomes `"dab"` after removing the second occurrence of `"abc"`.

**Third Iteration:**
- There are no more occurrences of `"abc"` in the string `"dab"`.
- The loop stops, and the function returns `"dab"`.

#### Example 2:
```cpp
s = "axxxxyyyyb"
part = "xy"
```

**First Iteration:**
- `s.find(part)` returns `4` (the first occurrence of `"xy"`).
- The string becomes `"axxxyyyb"` after removing the first occurrence of `"xy"`.

**Second Iteration:**
- Now, `s.find(part)` returns `4` again (another occurrence of `"xy"` in the modified string).
- The string becomes `"axxxb"` after removing the second occurrence of `"xy"`.

**Third Iteration:**
- Now, no more occurrences of `"xy"` are found, so the loop exits.
- The function returns `"axxxb"`.

---

### Time Complexity:
- **Time Complexity:** The time complexity of this solution is **O(n \* m)**, where:
  - `n` is the length of the string `s`.
  - `m` is the length of the substring `part`.
  - Each `find` operation takes O(n), and each `erase` operation also takes O(n) (since we may have to shift the remaining characters).
- **Space Complexity:** The space complexity is **O(1)** because no additional data structures are used, and all operations are done in place on the input string `s`.

---

### Conclusion:

This approach repeatedly finds and removes occurrences of the substring `part` from the string `s`. It continues until no more occurrences of `part` are found in `s`. The algorithm effectively reduces the string size by removing portions matching `part`, and it ensures the final result is a string where `part` no longer appears.
