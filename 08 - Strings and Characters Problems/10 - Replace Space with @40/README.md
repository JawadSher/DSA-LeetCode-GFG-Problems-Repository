

<h1 align='center'>Replace - Space - with - @40</h1>

## Problem Statement

**Problem URL :** Self Made

You are given a string `s` that may contain spaces. Your task is to replace every space in the string with the substring `"@40"`.

**Function Signature:**  
```cpp
void replaceSpace(string& s)
```

**Input:**  
- A single string `s` containing alphanumeric characters, spaces, or special characters.

**Output:**  
- The function modifies the string `s` in-place by replacing every space character (`' '`) with the substring `"@40"`.

**Example:**

1. **Input:**  
   `s = "Hello World"`
   
   **Output:**  
   `"Hello@40World"`

2. **Input:**  
   `s = "This is a test"`
   
   **Output:**  
   `"This@40is@40a@40test"`

3. **Input:**  
   `s = "NoSpacesHere"`
   
   **Output:**  
   `"NoSpacesHere"`

**Constraints:**
- The input string `s` can contain spaces, letters, digits, or special characters.
- The length of the string `s` can range from 1 to 1000 characters.

## Problem Solution
```cpp
#include <iostream>
using namespace std;

void replaceSpace(string& s){
  string part = "@40";
  for(int i = 0; i < s.length(); i++){
    if(s[i] == ' '){
      s.replace(i, 1, part);
    }
  }
}

int main() {  
  string str = "Hello World 2";
  replaceSpace(str);

  cout<<"updated str : "<<str<<endl;
  return 0;
}
```

## Problem Solution Explanation
Let’s break down the code in detail and explain each part of the process, along with how it works.

### Code Breakdown

```cpp
#include <iostream>
using namespace std;
```
- **`#include <iostream>`**: This includes the standard input/output library, which allows you to use functions like `cin` and `cout` for input and output operations.
- **`using namespace std;`**: This eliminates the need to prefix standard library functions like `cout` with `std::`. 

---

### `replaceSpace` Function

```cpp
void replaceSpace(string& s) {
  string part = "@40";  // 1
  for(int i = 0; i < s.length(); i++) {  // 2
    if(s[i] == ' ') {  // 3
      s.replace(i, 1, part);  // 4
    }
  }
}
```

1. **`string part = "@40";`**  
   - This creates a string `part` which holds the value `"@40"`. This is the string that will replace every space (' ') in the input string.

2. **`for(int i = 0; i < s.length(); i++)`**  
   - This is a loop that iterates over every character of the string `s` from index `0` to the last index (`s.length() - 1`).
   - `s.length()` returns the length of the string `s`. In the example string `"Hello World 2"`, the length is 12.
   - The loop will go through each character one by one.

3. **`if(s[i] == ' ')`**  
   - This condition checks whether the current character in the string `s` at position `i` is a space (`' '`).
   - If a space is found, it triggers the code inside the `if` block.

4. **`s.replace(i, 1, part);`**  
   - This replaces the character at index `i` (which is a space in this case) with the string `part` (`"@40"`).
   - **`s.replace(i, 1, part)`** means:
     - Start at position `i`.
     - Replace **1 character** (the space) with the string `part` (`"@40"`).
     - Example: If `i = 5` (the space in `"Hello World 2"`), the space is replaced with `"@40"`, making the string `"Hello@40World 2"`.
   - Note that the string length increases by 2 for each space replaced, since `"@40"` has 3 characters, and a single space is being replaced.

---

### Main Function

```cpp
int main() {
  string str = "Hello World 2";  // 1
  replaceSpace(str);  // 2

  cout << "updated str : " << str << endl;  // 3
  return 0;
}
```

1. **`string str = "Hello World 2";`**  
   - A string `str` is initialized with the value `"Hello World 2"`. This is the string that will be passed to the `replaceSpace` function for modification.

2. **`replaceSpace(str);`**  
   - The function `replaceSpace` is called with `str` passed by reference.
   - The reference ensures that the function modifies the original `str`, not a copy. This is why the changes made in `replaceSpace` will reflect in `main()`.

3. **`cout << "updated str : " << str << endl;`**  
   - This prints the modified string `str` to the console.
   - Since `replaceSpace` modifies `str`, this will print the string with all spaces replaced by `"@40"`.

---

### Step-by-Step Example

Let’s walk through the example input string `"Hello World 2"`:

- **Initial String**: `"Hello World 2"`
- Length: 12 characters

1. **Iteration 1** (`i = 0`): The first character is `'H'`, not a space. No replacement occurs.
2. **Iteration 2** (`i = 1`): The second character is `'e'`, not a space. No replacement occurs.
3. **Iteration 3** (`i = 2`): The third character is `'l'`, not a space. No replacement occurs.
4. **Iteration 4** (`i = 3`): The fourth character is `'l'`, not a space. No replacement occurs.
5. **Iteration 5** (`i = 4`): The fifth character is `'o'`, not a space. No replacement occurs.
6. **Iteration 6** (`i = 5`): The sixth character is `' '`, which **is a space**. The `replace` function replaces the space at index 5 with `"@40"`. 
   - The string becomes: `"Hello@40World 2"`
   - Length after replacement: 14 characters (space is replaced by 3 characters).
7. **Iteration 7–10** (`i = 6–9`): The next characters are `'W'`, `'o'`, `'r'`, `'l'`. No replacement occurs.
8. **Iteration 11** (`i = 10`): The 11th character is `'d'`, not a space. No replacement occurs.
9. **Iteration 12** (`i = 11`): The 12th character is `' '`, which **is a space**. The `replace` function replaces the space at index 11 with `"@40"`.
   - The string becomes: `"Hello@40World@402"`
   - Length after replacement: 16 characters.

### Final Output

The string `"Hello World 2"` is transformed into `"Hello@40World@402"`, with spaces replaced by `"@40"`.

The final output is:
```
updated str : Hello@40World@402
```

### Key Points:
- The function modifies the original string by passing it by reference.
- For every space found in the string, it is replaced by `"@40"`, increasing the length of the string with each replacement.
- The code works correctly for replacing spaces in any input string with the desired string.
