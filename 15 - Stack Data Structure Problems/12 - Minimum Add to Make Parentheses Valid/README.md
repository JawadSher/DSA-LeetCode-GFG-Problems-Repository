<h1 align='center'>Minimum - Add to - Make - Parentheses - Valid </h1>

## Problem Statement

**Problem URL :** [Minimum Add to Make Parentheses Valid](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/)

![image](https://github.com/user-attachments/assets/e1436728-4d58-4bd8-9a74-0455ce85676a)

## Problem Explanation

In this problem, you are given a string `s` containing only the characters `(` and `)`. Your task is to determine the minimum number of parentheses (either `(` or `)`) that need to be added to the string so that it becomes a **valid parentheses string**.

A string of parentheses is considered **valid** if:
1. Every opening bracket `(` has a corresponding closing bracket `)`.
2. Every closing bracket `)` has a preceding matching opening bracket `(`.

---

### Example

- **Example 1**:
    - Input: `"())"`
    - Output: `1`
    - Explanation: One closing bracket `)` doesn't have a matching opening bracket, so we need to add `1` opening bracket `(` to make it valid.

- **Example 2**:
    - Input: `"((("`
    - Output: `3`
    - Explanation: All three opening brackets `(` don't have matching closing brackets, so we need to add `3` closing brackets `)`.

---

### Approach

We can solve this problem using a **counting approach** instead of using a stack:
1. Use two counters:
   - `open`: Tracks the number of unmatched opening brackets `(`.
   - `close`: Tracks the number of unmatched closing brackets `)`.
2. Loop through the string:
   - For each opening bracket `(`, increment the `open` counter.
   - For each closing bracket `)`, if there is an unmatched opening bracket (`open > 0`), we match it by decrementing the `open` counter. Otherwise, increment the `close` counter (indicating an unmatched closing bracket).
3. After the loop, the total number of unmatched parentheses will be `open + close`, which is the minimum number of parentheses we need to add to make the string valid.


## Problem Solution
```cpp
class Solution {
public:
    int minAddToMakeValid(string s) {
        int close = 0;
        int open = 0;

        for(int i = 0; i < s.length(); i++){
            char ch = s[i];

            if(ch == '('){
                open++;
            }else if(ch == ')'){
                if(open > 0){
                    open--;
                }else{
                    close++;
                }
            }
        }

        return open + close;
    }
};
```

## Problem Solution Explanation

```cpp
class Solution {
public:
    int minAddToMakeValid(string s) {
```

The function `minAddToMakeValid` takes a string `s` as input and returns an integer representing the minimum number of parentheses that need to be added to make the string valid.

---

### Step 1: Initialize Counters for Unmatched Parentheses

```cpp
int close = 0;
int open = 0;
```

- `open`: Tracks unmatched opening brackets `(`.
- `close`: Tracks unmatched closing brackets `)`.

---

### Step 2: Loop Through Each Character in the String

```cpp
for (int i = 0; i < s.length(); i++) {
    char ch = s[i];
```

We loop through each character in the string `s`.

---

### Step 3: Handle Opening Brackets

```cpp
if (ch == '(') {
    open++;
}
```

If the character is an **opening bracket** `(`, we increment the `open` counter since it is unmatched.

- **Example**:
    - Input: `"((("`
    - After processing the first `(`, `open = 1`.
    - After processing the second `(`, `open = 2`.
    - After processing the third `(`, `open = 3`.

---

### Step 4: Handle Closing Brackets

```cpp
else if (ch == ')') {
    if (open > 0) {
        open--;
    } else {
        close++;
    }
}
```

If the character is a **closing bracket** `)`:
1. If there is an unmatched opening bracket (`open > 0`), we match it by decrementing the `open` counter.
2. Otherwise, we increment the `close` counter since this closing bracket is unmatched.

- **Example 1**:
    - Input: `"())"`
    - First `(`: `open = 1`.
    - First `)` matches the `(`: `open = 0`.
    - Second `)` is unmatched, so `close = 1`.

- **Example 2**:
    - Input: `"))("`
    - First `)` is unmatched: `close = 1`.
    - Second `)` is unmatched: `close = 2`.
    - Then `(`: `open = 1`.

---

### Step 5: Return the Total Number of Unmatched Parentheses

```cpp
return open + close;
```

Finally, we return the sum of the unmatched opening and closing brackets (`open + close`). This gives us the **minimum number of parentheses** that need to be added to make the string valid.

- **Example 1**:
    - Input: `"())"`
    - Result: `open = 0`, `close = 1`, so the function returns `1`.

- **Example 2**:
    - Input: `"((("`
    - Result: `open = 3`, `close = 0`, so the function returns `3`.


### Example Walkthrough

#### Example 1: `"())"`
1. **Initial State**: `open = 0`, `close = 0`
2. First character is `(`, so `open = 1`.
3. Second character is `)`, which matches the first `(`, so `open = 0`.
4. Third character is `)`, which is unmatched, so `close = 1`.
5. Final result: `open = 0`, `close = 1`, so the minimum number of parentheses to add is `1`.

#### Example 2: `"((("`
1. **Initial State**: `open = 0`, `close = 0`
2. First character is `(`, so `open = 1`.
3. Second character is `(`, so `open = 2`.
4. Third character is `(`, so `open = 3`.
5. Final result: `open = 3`, `close = 0`, so the minimum number of parentheses to add is `3`.

#### Example 3: `"))("`
1. **Initial State**: `open = 0`, `close = 0`
2. First character is `)`, which is unmatched, so `close = 1`.
3. Second character is `)`, which is unmatched, so `close = 2`.
4. Third character is `(`, so `open = 1`.
5. Final result: `open = 1`, `close = 2`, so the minimum number of parentheses to add is `3`.

---

### Time and Space Complexity

1. **Time Complexity**: 
   - The time complexity is **O(n)**, where `n` is the length of the string. We only make a single pass through the string.

2. **Space Complexity**: 
   - The space complexity is **O(1)** because we are only using a few integer variables (`open`, `close`), regardless of the input size.
