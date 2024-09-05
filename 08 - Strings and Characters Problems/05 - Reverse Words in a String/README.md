<h1 align='center'>Reverse - Words - in a - String</h1>

## Problem Statement

**Problem URL :** [Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/)

![image](https://github.com/user-attachments/assets/dfa36604-f95d-4565-b16e-618c80331212)

## Problem Explanation
The problem **"Reverse Words in a String"** asks you to reverse the order of the words in a given string. The words are separated by spaces, and you need to return a new string where the words appear in reverse order.

**Key Constraints:**
1. Words are defined as sequences of non-space characters.
2. Multiple spaces between words should be reduced to a single space in the result.
3. Leading and trailing spaces should be removed from the final result.

### Example:
**Input:**
```
s = "  the sky  is blue  "
```

**Output:**
```
"blue is sky the"
```

**Explanation:** 
- Remove leading/trailing spaces.
- Split the words by spaces.
- Reverse the order of words and join them with a single space.

### Approach:
1. **Trim spaces**: Remove leading, trailing, and extra spaces between words.
2. **Extract words**: Split the string into individual words.
3. **Reverse the words**: Reverse the order of the words.
4. **Return the result**: Join the words back together with a single space between them.
   
## Problem Solution
```cpp
class Solution {
public:
    string removeSpaces(string s){
        int start = s.find_first_not_of(" ");
        if(start == string::npos){
            return "";
        }
        int end = s.find_last_not_of(" ");

        string new_str = s.substr(start, end - start + 1);
        return new_str;
    }
    string reverseWords(string s) {
        istringstream iss(removeSpaces(s));
        vector<string> words;
        string word;

        while(iss >> word){
            words.push_back(word);
        }

        for(int i = words.size() -1; i > 0; i--){
            reversed += words[i] + " ";
        }

        if(!words.empty()){
            reversed += words[0];
        }

        return reversed;
    }
};
```

## Problem Solution Explanation
Let's break down the code line by line.

```cpp
class Solution {
public:
```
- **`class Solution`**: The problem is typically solved in an object-oriented way in coding platforms like LeetCode. The solution is enclosed within a class called `Solution`.
- **`public:`**: This indicates that all members under it are accessible publicly.

---

#### Function 1: `removeSpaces`

```cpp
string removeSpaces(string s){
    int start = s.find_first_not_of(" ");
```
- **`string removeSpaces(string s)`**: This function is designed to trim the leading and trailing spaces from the input string `s`.
- **`int start = s.find_first_not_of(" ");`**: This finds the first character in the string that is **not** a space. If all characters are spaces, `start` will be `string::npos`.

---

```cpp
if(start == string::npos){
    return "";
}
```
- **`if(start == string::npos)`**: If the entire string is made of spaces, this condition becomes true, and we return an empty string. This handles the edge case where the input string is just spaces.

---

```cpp
int end = s.find_last_not_of(" ");
```
- **`int end = s.find_last_not_of(" ");`**: This finds the last character in the string that is not a space.

---

```cpp
string new_str = s.substr(start, end - start + 1);
return new_str;
```
- **`string new_str = s.substr(start, end - start + 1);`**: This extracts the substring from the first non-space character (`start`) to the last non-space character (`end`). The `+1` ensures that the entire word is included.
- **`return new_str;`**: Return the trimmed string.

---

#### Function 2: `reverseWords`

```cpp
string reverseWords(string s) {
    istringstream iss(removeSpaces(s));
```
- **`string reverseWords(string s)`**: This function is designed to reverse the order of words in the string `s`.
- **`istringstream iss(removeSpaces(s));`**: Here, we call the `removeSpaces` function to remove leading and trailing spaces. We then use `istringstream` to treat the trimmed string `s` like a stream (a sequence of words separated by spaces).

---

```cpp
vector<string> words;
string word;
```
- **`vector<string> words;`**: This creates a vector of strings to hold individual words from the input string `s`.
- **`string word;`**: This declares a variable `word` to store each word extracted from the string.

---

```cpp
while(iss >> word){
    words.push_back(word);
}
```
- **`while(iss >> word)`**: This loop extracts words from the stream `iss` one by one and stores them in the `word` variable.
- **`words.push_back(word);`**: Each extracted word is added to the `words` vector.

---

```cpp
for(int i = words.size() -1; i > 0; i--){
    reversed += words[i] + " ";
}
```
- **`for(int i = words.size() -1; i > 0; i--)`**: This loop iterates over the `words` vector from the last word (`words.size() - 1`) to the second word (`i > 0`), appending each word to the `reversed` string with a space.
- **`reversed += words[i] + " ";`**: The current word `words[i]` is added to the result string `reversed`, followed by a space.

---

```cpp
if(!words.empty()){
    reversed += words[0];
}
```
- **`if(!words.empty())`**: This checks if the vector `words` is not empty.
- **`reversed += words[0];`**: The first word (index 0) is added to the `reversed` string without a trailing space. This ensures the last word in the reversed string doesn't have an extra space.

---

```cpp
return reversed;
```
- **`return reversed;`**: Finally, the reversed string is returned as the result.

---

### Complete Example Walkthrough:

**Example Input:**  
```cpp
s = "  the sky  is blue  ";
```

**Step-by-Step Execution:**

1. **Trimming the string:**  
   The input string `"  the sky  is blue  "` is passed to the `removeSpaces` function.
   - First non-space character: 't'
   - Last non-space character: 'e'
   - Result after trimming: `"the sky  is blue"`

2. **Extracting words:**  
   The `istringstream` breaks down the trimmed string into individual words:  
   `"the"`, `"sky"`, `"is"`, `"blue"`.

3. **Reversing the words:**  
   The words are stored in the `words` vector as: `["the", "sky", "is", "blue"]`.
   - The loop runs to reverse the words and forms the result as `"blue is sky the"`.

**Final Output:**  
```cpp
"blue is sky the"
```

### Approach for Beginners:

1. **Trimming**: First, remove leading, trailing, and multiple spaces between words. This can be done using the `find_first_not_of` and `find_last_not_of` functions or libraries like `istringstream`.
   
2. **Splitting the words**: Break the string into words using a stream (`istringstream`) or a string manipulation function.
   
3. **Reversing the words**: Store the words in a data structure (like a vector) and reverse the order.

4. **Handling edge cases**:
   - Input string contains only spaces.
   - The input string has multiple spaces between words.

By using this structured approach, you can solve the problem efficiently while covering all possible cases.
