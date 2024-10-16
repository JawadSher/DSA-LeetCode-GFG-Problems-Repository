<h1 align='center'>Expression - Contains - Redundant - Bracket - OR - Not</h1>

## Problem Statement

**Problem URL :** [Expression Contains Redundant Bracket or Not](https://www.geeksforgeeks.org/problems/expression-contains-redundant-bracket-or-not/0)

![image](https://github.com/user-attachments/assets/5f415e81-d35a-488d-aee2-64a66794c6ff)
![image](https://github.com/user-attachments/assets/80ea3d0c-d4d1-4d0a-9997-4492fd095540)

## Problem Explanation

In this problem, you are given a string `s` that represents a mathematical expression. Your task is to check whether the expression contains **redundant brackets**. A bracket is considered **redundant** if there are extra brackets around operators that don’t serve any purpose.

### Example

- **Input 1**: `"((a+b))"`
    - **Output**: `1` (indicating redundant brackets)

- **Input 2**: `"(a + (b*c))"`
    - **Output**: `0` (no redundant brackets)

### Approach

We will use a **stack** to check for redundant brackets. The idea is:
1. **Push** each opening bracket `(` and operator (`*`, `+`, `-`, `/`) onto the stack.
2. When we encounter a closing bracket `)`, we pop from the stack until we find an opening bracket `(`. If there are no operators between these brackets, it means the brackets are redundant.
3. If redundancy is found, return `1`; otherwise, after processing the entire string, return `0`.


## Problem Solution
```cpp
class Solution {
  public:
    int checkRedundancy(string s) {
        stack<char> st;
        
        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            if(ch == '(' || ch == '*' || ch == '+' || ch == '-' || ch == '/'){
                st.push(ch);
            }else if(ch == ')'){
                
                bool isRedundant = true;
                
                while(!st.empty() && st.top() != '('){
                    char top = st.top();
                    st.pop();
                    
                    if (top == '*' || top == '+' || top == '-' || top == '/') {
                        isRedundant = false;
                    }
                }
                
                if(!st.empty()) st.pop();
                
                if(isRedundant) return 1;
            }
            
            
        }
        
        return 0;
    }
};

```

## Problem Solution Explanation

```cpp
class Solution {
  public:
    int checkRedundancy(string s) {
```

The function `checkRedundancy` takes a string `s` as input and returns `1` if the string contains **redundant brackets**, and `0` otherwise.

---

### Step 1: Declare a Stack to Keep Track of Characters

```cpp
stack<char> st;
```

We use a **stack** to store characters (`(`, `*`, `+`, `-`, `/`) while processing the string.

---

### Step 2: Iterate Over Each Character of the String

```cpp
for (int i = 0; i < s.length(); i++) {
    char ch = s[i];
```

We loop through each character of the string `s`.

---

### Step 3: Push Operators and Opening Brackets onto the Stack

```cpp
if (ch == '(' || ch == '*' || ch == '+' || ch == '-' || ch == '/') {
    st.push(ch);
}
```

If the character is an **opening bracket** `(` or an **operator** (`*`, `+`, `-`, `/`), we **push** it onto the stack.

- **Example 1**:
    - Input: `"(a + (b))"`
    - After processing `a`, the stack will have the operator `+` and the opening bracket `(`.

---

### Step 4: Handle Closing Brackets and Check for Redundancy

```cpp
else if (ch == ')') {
    
    bool isRedundant = true;
    
    while (!st.empty() && st.top() != '(') {
        char top = st.top();
        st.pop();
        
        if (top == '*' || top == '+' || top == '-' || top == '/') {
            isRedundant = false;
        }
    }
```

When we encounter a **closing bracket** `)`, we:
1. Assume initially that the brackets are **redundant** (`isRedundant = true`).
2. **Pop** elements from the stack until we find the corresponding **opening bracket** `(`. If we pop an operator (`*`, `+`, `-`, `/`), then the brackets are **not redundant** (`isRedundant = false`).

- **Example 1 (continued)**:
    - For `"(a + (b))"`, after processing `b`, we encounter `)`. We pop until we find `(`.
    - Since no operator was found between the parentheses, the brackets are redundant.

---

### Step 5: Remove the Corresponding Opening Bracket

```cpp
if (!st.empty()) st.pop();
```

After processing the closing bracket, we **pop** the corresponding opening bracket `(` from the stack.

- **Example**:
    - After popping all characters between the parentheses, we pop the opening bracket `(` as well.

---

### Step 6: Return 1 If Redundant Brackets Are Found

```cpp
if (isRedundant) return 1;
```

If the brackets are redundant, i.e., no operator was found between the parentheses, we return `1`.

- **Example**:
    - In the case of `"((a+b))"`, redundant brackets were found, so the function will return `1`.

---

### Step 7: Return 0 If No Redundant Brackets Are Found

```cpp
return 0;
```

If the loop completes without finding any redundant brackets, we return `0`.

### Example Walkthrough

#### Example 1: `"((a+b))"`
1. The stack processes the first `(`.
2. Then, it processes another `(`.
3. After encountering the closing `)`, we pop from the stack until we find the corresponding `(`.
4. No operator is found between the parentheses, so the function returns `1` (redundant).

#### Example 2: `"(a + (b*c))"`
1. The stack processes the first `(`, then the operator `+`, and another `(`.
2. After encountering the closing `)`, we pop from the stack and find the operator `*` between the parentheses.
3. Since an operator is found, the brackets are not redundant, and the function continues processing.
4. The function returns `0` (no redundancy).

---

### Time and Space Complexity

1. **Time Complexity**: 
   - The time complexity is **O(n)**, where `n` is the length of the string. This is because we are processing each character of the string exactly once.

2. **Space Complexity**: 
   - The space complexity is **O(n)** due to the stack, which in the worst case can store all the characters of the string.

This approach efficiently checks for redundant brackets in the expression using a stack and a single pass through the input string.
