<h1 align='center'>Reverse - Words in a - Given - String</h1>

## Problem Statement

**Problem URL :** [Reverse words in a Given String](https://www.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1)

![image](https://github.com/user-attachments/assets/993885d2-eea1-4c82-88f1-3334804c5826)
![image](https://github.com/user-attachments/assets/8070c7fc-3613-443a-b95f-1b340a3aa1a2)

## Problem Solution
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    string reverseWords(string S) 
    {   
        istringstream iss(S);
        vector<string> v;
        string word;
        string reversed = "";
        
        while (getline(iss, word, '.')) {
            if (!word.empty()) {
                v.push_back(word);
            }
        }

        for(int i = v.size() -1; i >= 0; i--){
            reversed += v[i];
            if(i > 0){
                reversed += '.';
            }
        }
        
        return reversed;
    } 
};

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
```

## Problem Solution Explanation
This C++ program is designed to reverse the words in a string where each word is separated by a period (`.`). The program reads an input string, splits it into words based on the period as a delimiter, reverses the order of the words, and then reconstructs the string with the reversed words.

Let's break it down step-by-step with examples.

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    string reverseWords(string S) 
    {   
        istringstream iss(S);
        vector<string> v;
        string word;
        string reversed = "";
        
        while (getline(iss, word, '.')) {
            if (!word.empty()) {
                v.push_back(word);
            }
        }

        for(int i = v.size() - 1; i >= 0; i--){
            reversed += v[i];
            if(i > 0){
                reversed += '.';
            }
        }
        
        return reversed;
    } 
};
```

#### Explanation of `reverseWords` function:

1. **`istringstream iss(S);`**
   - This creates a string stream from the input string `S`, which will be used to read the string word by word, separating them by the period (`.`).

2. **`vector<string> v;`**
   - A vector `v` is declared to store the individual words that will be extracted from the string `S`.

3. **`string word;`**
   - A temporary string variable `word` to hold each word extracted from the string `S`.

4. **`while (getline(iss, word, '.'))`**
   - The `getline` function is used to read the input string `S` and split it at each period (`.`). Each word found between periods is stored in the variable `word`.
   
5. **`if (!word.empty())`**
   - This ensures that if there are any empty substrings (e.g., if two periods appear together like `word1..word2`), they are not added to the vector `v`.

6. **`v.push_back(word);`**
   - The non-empty word is added to the vector `v`.

7. **Reversing the words**:
   - Once all the words have been extracted and stored in `v`, we iterate over `v` in reverse order.
   
   ```cpp
   for(int i = v.size() - 1; i >= 0; i--){
       reversed += v[i];
       if(i > 0){
           reversed += '.';
       }
   }
   ```
   - This loop goes through the vector `v` from the last word to the first. For each word, it adds it to the string `reversed`. If the word is not the last one (i.e., `i > 0`), it appends a period (`.`) after the word.
   
8. **`return reversed;`**
   - Finally, the function returns the string `reversed`, which contains the words in reverse order, separated by periods.

---

### `main` function

```cpp
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
```

1. **`int t;`**
   - The integer `t` represents the number of test cases.

2. **`cin >> t;`**
   - Input the number of test cases.

3. **`while (t--)`**
   - The loop runs `t` times for each test case.

4. **`cin >> s;`**
   - Input the string `s` for the current test case. Each test case contains a string where words are separated by periods.

5. **`Solution obj;`**
   - An object `obj` of the `Solution` class is created.

6. **`cout << obj.reverseWords(s) << endl;`**
   - The `reverseWords` function is called for the string `s`, and the result is printed.

---

### Example Walkthrough

#### Test Case 1:

**Input:**
```
1
hello.world.this.is.cplusplus
```

- **Step 1**: The input string is `"hello.world.this.is.cplusplus"`.
- **Step 2**: The `reverseWords` function processes this string by splitting it into the following words:
  - `hello`
  - `world`
  - `this`
  - `is`
  - `cplusplus`
- **Step 3**: These words are stored in the vector `v = ["hello", "world", "this", "is", "cplusplus"]`.
- **Step 4**: The program iterates through `v` in reverse order, constructing the string as:
  - `"cplusplus"` (first word added)
  - `"cplusplus.is"` (second word)
  - `"cplusplus.is.this"` (third word)
  - `"cplusplus.is.this.world"` (fourth word)
  - `"cplusplus.is.this.world.hello"` (fifth and final word)
- **Step 5**: The final reversed string is `"cplusplus.is.this.world.hello"`.
  
**Output:**
```
cplusplus.is.this.world.hello
```

---

#### Test Case 2:

**Input:**
```
1
abc.def.ghi
```

- **Step 1**: The input string is `"abc.def.ghi"`.
- **Step 2**: The `reverseWords` function splits the string into the words:
  - `abc`
  - `def`
  - `ghi`
- **Step 3**: These words are stored in the vector `v = ["abc", "def", "ghi"]`.
- **Step 4**: The words are reversed, and the result is constructed as:
  - `"ghi.def.abc"`
- **Step 5**: The final reversed string is `"ghi.def.abc"`.

**Output:**
```
ghi.def.abc
```

---

### Summary

- The code splits a string into words using the period (`.`) as a delimiter.
- It then reverses the order of the words and joins them back with periods in between.
- The final result is returned as a single string with the words reversed in order but maintaining periods between them.

This approach works for multiple test cases, and for each test case, the input string's words are processed and reversed individually.

