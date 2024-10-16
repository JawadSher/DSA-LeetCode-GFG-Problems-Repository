<h1 align='center'>Valid - Parentheses</h1>

## Problem Statement

**Problem URL :** [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)

![image](https://github.com/user-attachments/assets/c7c2b170-ae24-41fa-9a22-e3c91eafb4f7)
![image](https://github.com/user-attachments/assets/6e2492eb-a44f-4ddd-8af6-b3011bc049d9)


## Problem Explanation

You are given a string `s` containing just the characters `'(', ')', '{', '}', '[', ']'`. You need to determine if the input string is **valid**. A string is considered valid if:
1. **Every open bracket has a corresponding closing bracket of the same type** (e.g., `(` matches with `)`).
2. **Brackets are closed in the correct order** (e.g., the string `"[{()}]"` is valid, but `"[{])}"` is not).

### Approach

We need to ensure that:
- **Opening brackets** like `(`, `{`, or `[` are stored somewhere so we can find their matching **closing brackets**.
- **Closing brackets** must correctly match the most recent (last opened) corresponding opening bracket.

A **stack** is the perfect data structure for this because it follows the **Last-In-First-Out (LIFO)** principle:
- **Push** opening brackets onto the stack.
- **Pop** brackets off the stack to check if they correctly match a closing bracket.

### Steps to Solve the Problem:
1. **Create a stack** to store opening brackets.
2. **Loop through the string**:
   - If you encounter an **opening bracket** (`(`, `{`, `[`), push it onto the stack.
   - If you encounter a **closing bracket** (`)`, `}`, `]`), check:
     - If the stack is empty, return false (unmatched closing bracket).
     - Otherwise, pop from the stack and check if the popped opening bracket matches the current closing bracket.
3. At the end of the loop, if the stack is **empty**, the string is valid (all brackets matched). If the stack is **not empty**, the string is invalid.

### Example

Input: `"([{}])"`
- Push `(` onto the stack.
- Push `[` onto the stack.
- Push `{` onto the stack.
- Pop `{` (matches `}`), continue.
- Pop `[` (matches `]`), continue.
- Pop `(` (matches `)`), continue.
- Stack is empty. The string is valid.

## Problem Solution
```cpp
class Solution {

public:
    bool isValid(string s) {
        stack<char> st;

        for(char ch : s){
            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
            }else {

                if(st.empty()) return false;

                char top = st.top();
                st.pop();

                if((ch == ')' && top != '(') ||
                   (ch == '}' && top != '{') ||
                   (ch == ']' && top != '[')) {
                    return false;
                }
            }
        }
        
        return st.empty();
    }
};
```

## Problem Solution Explanation

Let’s go for a clearer, **step-by-step line-by-line explanation** of the code, along with examples, followed by the **time and space complexities** at the end.


```cpp
class Solution {
public:
    bool isValid(string s) {
```

This defines a class `Solution` and a function `isValid` that takes a string `s` and returns `true` if the string has valid parentheses, and `false` otherwise.

---

### Step 1: Stack Initialization

```cpp
stack<char> st;
```

We declare an empty stack called `st`. We’ll use the stack to store opening brackets (`(`, `{`, `[`) as we encounter them in the string.

- **Stack (LIFO)**: The stack works on the **Last In, First Out** principle. This helps us handle parentheses because the last opened parenthesis must be closed first.

---

### Step 2: Iterate Through the String

```cpp
for (char ch : s) {
```

We start a loop that iterates through each character `ch` in the string `s`.

- **Example 1:**
    - Input: `"()"`
    - We start reading the characters one by one.
    - First character: `(`.

- **Example 2:**
    - Input: `"([{}])"`
    - First character: `(`, second character: `[`, third character: `{`.

---

### Step 3: Handling Opening Brackets

```cpp
if (ch == '(' || ch == '[' || ch == '{') {
    st.push(ch);
}
```

Whenever we encounter an **opening bracket** (`(`, `{`, or `[`), we push it onto the stack.

- **Example 1:**
    - Input: `"()"`
    - First character `(` is pushed onto the stack.
    - Stack now contains: `['(']`.

- **Example 2:**
    - Input: `"([{}])"`
    - First character `(` is pushed onto the stack.
    - Stack: `['(']`.
    - Second character `[`, so we push `[`.
    - Stack: `['(', '[']`.

---

### Step 4: Handling Closing Brackets

```cpp
else {
    if (st.empty()) return false;
    char top = st.top();
    st.pop();
```

When we encounter a **closing bracket** (`)`, `}`, or `]`), we first check if the stack is **empty**:
- If the stack is empty, it means there is no matching opening bracket for this closing bracket, so the string is invalid. We return `false`.

Otherwise:
- We **pop** the top element from the stack (the most recent opening bracket) and store it in `top`.
  
---

### Step 5: Match the Opening and Closing Brackets

```cpp
if ((ch == ')' && top != '(') ||
    (ch == '}' && top != '{') ||
    (ch == ']' && top != '[')) {
    return false;
}
```

Next, we check if the **closing bracket** matches its corresponding **opening bracket**. If the characters don’t match, the string is invalid, so we return `false`.

- **Example 1:**
    - Input: `"()"`
    - Second character: `)`. We pop `(` from the stack. `)` matches `(`.
    - Stack is empty, continue.

- **Example 2:**
    - Input: `"([{}])"`
    - Fourth character: `}`. We pop `{` from the stack. `}` matches `{`.
    - Fifth character: `]`. We pop `[` from the stack. `]` matches `[`.
    - Sixth character: `)`. We pop `(` from the stack. `)` matches `(`.

---

### Step 6: Final Check for Validity

```cpp
return st.empty();
```

After the loop finishes, we check if the stack is empty:
- If the stack is empty, it means all the opening brackets had corresponding closing brackets, and the string is valid.
- If the stack is not empty, it means there are unmatched opening brackets, so the string is invalid.

- **Example 1:**
    - Input: `"()"`
    - Stack is empty, so the string is valid. Return `true`.

- **Example 2:**
    - Input: `"([{}])"`
    - Stack is empty, so the string is valid. Return `true`.


### Examples with Code Execution

#### Example 1: `"()"`

- First character: `(` → push to stack → Stack: `['(']`
- Second character: `)` → pop from stack → `(` matches `)`
- Stack is empty, so the string is valid → return `true`.

#### Example 2: `"([{}])"`

- First character: `(` → push to stack → Stack: `['(']`
- Second character: `[` → push to stack → Stack: `['(', '[']`
- Third character: `{` → push to stack → Stack: `['(', '[', '{']`
- Fourth character: `}` → pop from stack → `{` matches `}`
- Fifth character: `]` → pop from stack → `[` matches `]`
- Sixth character: `)` → pop from stack → `(` matches `)`
- Stack is empty, so the string is valid → return `true`.

#### Example 3: `"([)]"`

- First character: `(` → push to stack → Stack: `['(']`
- Second character: `[` → push to stack → Stack: `['(', '[']`
- Third character: `)` → pop from stack → Top is `[`, which doesn't match `)`
- Return `false`.

---

### Time and Space Complexity

1. **Time Complexity: O(n)**:
   - We iterate through each character in the string exactly once, pushing or popping from the stack as needed. Here, `n` is the length of the string.

2. **Space Complexity: O(n)**:
   - In the worst case, we could be pushing all opening brackets into the stack, so the maximum size of the stack is proportional to the number of characters in the input string, i.e., `n`.
