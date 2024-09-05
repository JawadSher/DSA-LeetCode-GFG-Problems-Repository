<h1 align='center'>Reverse - Words - in a - String III</h1>

## Problem Statement

**Problem URL :** [Reverse Words in a String III](https://leetcode.com/problems/reverse-words-in-a-string-iii/description/)

![image](https://github.com/user-attachments/assets/e0008055-c1c6-44fc-bbd2-565229807446)

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
        string char_reversed;

        while(iss >> word){
            words.push_back(word);
        }

        for(int i = 0; i < words.size(); i++){
            string c_word = words[i];
            int s = 0;
            int e = c_word.size() - 1;

            while(s<e){
                swap(c_word[s], c_word[e]);
                s++;
                e--;
            }
            
            char_reversed += c_word;

            if(i < words.size() - 1){
                char_reversed += ' ';
            }
        }


        return char_reversed;
    }
};
```

## Problem Solution Explanation
The given C++ code defines a class `Solution` that contains methods to remove extra spaces from a string and to reverse each word in the string while maintaining the order of the words. Here’s a detailed explanation of the code along with examples.

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
```

#### Function: `removeSpaces`

1. **Purpose**: To remove leading and trailing spaces from the string and return the trimmed string.

2. **`int start = s.find_first_not_of(" ");`**
   - Finds the index of the first character that is not a space. 
   - If the string is all spaces, `start` will be `string::npos` (indicating no non-space characters found).

3. **`if(start == string::npos){ return ""; }`**
   - If `start` is `string::npos`, this means the string consists only of spaces. Therefore, we return an empty string.

4. **`int end = s.find_last_not_of(" ");`**
   - Finds the index of the last character that is not a space.

5. **`string new_str = s.substr(start, end - start + 1);`**
   - Creates a substring from `start` to `end` (inclusive) which is the trimmed string without leading and trailing spaces.

6. **`return new_str;`**
   - Returns the trimmed string.

---

```cpp
    string reverseWords(string s) {
        istringstream iss(removeSpaces(s));
        vector<string> words;
        string word;
        string char_reversed;

        while(iss >> word){
            words.push_back(word);
        }
```

#### Function: `reverseWords`

1. **Purpose**: To reverse each word in the string while maintaining the order of the words.

2. **`istringstream iss(removeSpaces(s));`**
   - Creates an `istringstream` object `iss` to read words from the string returned by `removeSpaces(s)`. This effectively processes the trimmed string.

3. **`vector<string> words;`**
   - A vector to store individual words.

4. **`string word;`**
   - A temporary string variable to hold each word as it is extracted.

5. **`string char_reversed;`**
   - A string to build the final result with reversed words.

6. **`while(iss >> word){ words.push_back(word); }`**
   - Extracts each word from `iss` and appends it to the `words` vector.

---

```cpp
        for(int i = 0; i < words.size(); i++){
            string c_word = words[i];
            int s = 0;
            int e = c_word.size() - 1;

            while(s < e){
                swap(c_word[s], c_word[e]);
                s++;
                e--;
            }
            
            char_reversed += c_word;

            if(i < words.size() - 1){
                char_reversed += ' ';
            }
        }
```

1. **`for(int i = 0; i < words.size(); i++)`**
   - Loops through each word in the `words` vector.

2. **`string c_word = words[i];`**
   - Retrieves the current word to be reversed.

3. **`int s = 0; int e = c_word.size() - 1;`**
   - Initializes two pointers: `s` (start) and `e` (end) to the beginning and end of the word, respectively.

4. **`while(s < e){ swap(c_word[s], c_word[e]); s++; e--; }`**
   - Reverses the characters in `c_word` in place by swapping characters from the start and end, moving towards the center.

5. **`char_reversed += c_word;`**
   - Appends the reversed word to the `char_reversed` string.

6. **`if(i < words.size() - 1){ char_reversed += ' '; }`**
   - Adds a space after each word except the last one to separate words in the final result.

---

```cpp
        return char_reversed;
    }
};
```
- **`return char_reversed;`**: Returns the final string with each word reversed but the words themselves in their original order.

### Example Walkthrough

Let's consider the example input string `"  the quick  brown fox  "`.

1. **Removing Spaces**:
   - The `removeSpaces` function trims the leading and trailing spaces, resulting in `"the quick  brown fox"`.

2. **Extracting Words**:
   - The `istringstream` extracts the words: `["the", "quick", "brown", "fox"]`.

3. **Reversing Each Word**:
   - `"the"` becomes `"eht"`
   - `"quick"` becomes `"kciuq"`
   - `"brown"` becomes `"nworb"`
   - `"fox"` becomes `"xof"`

4. **Building Final Result**:
   - The words are concatenated with spaces in between: `"eht kciuq nworb xof"`

5. **Output**:
   - The final output is `"eht kciuq nworb xof"`.

### Summary

The code correctly handles the task of reversing each word while preserving their order in the string. It first removes unnecessary spaces, extracts and reverses each word, and then assembles the final string. This approach ensures that all words are processed individually, resulting in the correct output.
