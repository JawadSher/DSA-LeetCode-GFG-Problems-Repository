<h1 align='center'>Reverse - a String - Using - Stack</h1>

Given a string `str`, the goal is to **reverse the string** using a stack. The reversed string is then printed.

## Problem Explanation

A beginner would approach this problem by thinking about how a stack can be useful. A **stack** follows the **Last In, First Out (LIFO)** principle, meaning the last element you insert into the stack is the first one that gets removed. This property of a stack makes it ideal for reversing a sequence of characters.

Here’s how a beginner might approach the problem step by step:
1. Start by reading the string character by character.
2. Push each character onto the stack.
3. Once all the characters are in the stack, pop them out one by one. As we pop characters, we append them to a new string, which gives us the reversed string.

The problem can be solved efficiently using a stack because of its LIFO behavior.

## Source Code 
```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
  string str = "HelloWorld";

  stack<char> st;

  for(int i = 0; i < str.length(); i++){
    char ch = str[i];
    st.push(ch);
  }

  string ans = "";
  while(!st.empty()){
    char ch = st.top();
    ans.push_back(ch);
    st.pop();
  }

  cout << "Answer is : " << ans <<endl;
  return 0;
}
```

## Source Code Explanation

```cpp
#include <iostream>  // Includes the input/output stream library.
#include <stack>     // Includes the stack data structure.
using namespace std; // Allows us to use standard namespace directly without the "std::" prefix.
```

The first part of the code includes necessary libraries for input-output operations (`iostream`) and the stack data structure (`stack`).

```cpp
int main() {
  string str = "HelloWorld";
```

- `string str = "HelloWorld";`: This declares and initializes a string `str` with the value `"HelloWorld"`. You can think of `str` as the input to our problem. The task is to reverse this string.
- Example: If `str = "HelloWorld"`, we want to output `"dlroWolleH"`.

```cpp
  stack<char> st;
```

- `stack<char> st;`: This declares an empty stack `st` that will hold characters. We’ll use this stack to store the characters of the string.

```cpp
  for(int i = 0; i < str.length(); i++){
    char ch = str[i];
    st.push(ch);
  }
```

- `for(int i = 0; i < str.length(); i++)`: This loop iterates over each character in the string `str` from the first character (`i = 0`) to the last character (`i = str.length() - 1`).
  
- `char ch = str[i];`: For each iteration, we extract the character at position `i` in the string `str` and store it in the variable `ch`.

- `st.push(ch);`: This pushes the character `ch` onto the stack `st`. Since we push characters in the order they appear in the string, the first character (`'H'`) will be at the bottom of the stack, and the last character (`'d'`) will be at the top of the stack.

  Example:
  - For `str = "HelloWorld"`, after the loop, the stack looks like this (top to bottom):
    ```
    d
    l
    r
    o
    W
    o
    l
    l
    e
    H
    ```

```cpp
  string ans = "";
```

- `string ans = "";`: This declares an empty string `ans`, which will store the reversed string.

```cpp
  while(!st.empty()){
    char ch = st.top();
    ans.push_back(ch);
    st.pop();
  }
```

- `while(!st.empty())`: This loop continues as long as the stack is not empty.
  
- `char ch = st.top();`: This retrieves the top element (the character on top of the stack) and stores it in the variable `ch`. Since the stack is LIFO, this will be the last character of the original string (e.g., `'d'` in the case of `"HelloWorld"`).

- `ans.push_back(ch);`: This appends the character `ch` to the end of the string `ans`.

- `st.pop();`: This removes the top element from the stack. Each time we pop the stack, we are removing one character from the reversed order.

  Example:
  - On the first iteration, `ch = 'd'` (the last character of the string), and we append it to `ans`, making `ans = "d"`.
  - On the second iteration, `ch = 'l'`, and `ans = "dl"`, and so on.
  
- After this loop finishes, the string `ans` will hold the reversed version of the input string `str`.

```cpp
  cout << "Answer is : " << ans <<endl;
  return 0;
}
```

- `cout << "Answer is : " << ans << endl;`: This outputs the reversed string stored in `ans`.

- Example: If `str = "HelloWorld"`, then `ans = "dlroWolleH"`, and the output will be:
  ```
  Answer is : dlroWolleH
  ```

- `return 0;`: Ends the `main` function, indicating successful execution.

---

### Example Walkthroughs:

#### Example 1:
**Input**: `"Hello"`
- Stack after pushing: `['o', 'l', 'l', 'e', 'H']`
- Reversed string: `"olleH"`

**Output**:
```
Answer is : olleH
```

#### Example 2:
**Input**: `"Stack"`
- Stack after pushing: `['k', 'c', 'a', 't', 'S']`
- Reversed string: `"kcatS"`

**Output**:
```
Answer is : kcatS
```

#### Example 3:
**Input**: `"ABCDE"`
- Stack after pushing: `['E', 'D', 'C', 'B', 'A']`
- Reversed string: `"EDCBA"`

**Output**:
```
Answer is : EDCBA
```

---

### Time Complexity:
- **Pushing characters onto the stack**: We push each character exactly once, so the time complexity is \(O(N)\), where \(N\) is the length of the string.
- **Popping characters from the stack**: We pop each character exactly once, so this is also \(O(N)\).
  
Therefore, the **total time complexity** is \(O(N)\).

### Space Complexity:
- We use a stack to store the characters of the string. In the worst case, the stack will store all \(N\) characters, so the **space complexity** is \(O(N)\), where \(N\) is the length of the string.

### Summary:
This approach efficiently reverses the string by utilizing the LIFO property of a stack. It pushes each character of the string onto the stack and then pops them in reverse order to build the reversed string. The overall time and space complexity of the solution is \(O(N)\), where \(N\) is the length of the input string.
