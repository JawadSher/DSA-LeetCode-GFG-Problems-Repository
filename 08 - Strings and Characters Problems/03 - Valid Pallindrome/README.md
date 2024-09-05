<h1 align='center'>Valid - Pallindrome</h1>

## Problem Statement

**Problem URL :** [Valid Pallindrome](https://leetcode.com/problems/valid-palindrome/)

![image](https://github.com/user-attachments/assets/6093ba32-a8e5-48f8-ae44-1051cdde72b6)

## Problem Explanation
You are given a string `s`, and your task is to determine whether it is a valid **palindrome**, considering only alphanumeric characters (letters and digits) and ignoring cases. A palindrome is a word, phrase, or sequence that reads the same forward and backward, after ignoring non-alphanumeric characters and treating uppercase and lowercase letters as equivalent.

#### Example:
```text
Input: s = "A man, a plan, a canal: Panama"
Output: true

Input: s = "race a car"
Output: false
```

#### Constraints:
- Ignore spaces, punctuation, and symbols.
- Treat uppercase and lowercase letters as equivalent.
  
### Approach to Solve the Problem

1. **Filter the String**: 
   - First, extract only alphanumeric characters from the input string `s`. Ignore all punctuation, spaces, and special characters.
   
2. **Convert to Lowercase**:
   - Convert all uppercase letters in the filtered string to lowercase, so that case differences are ignored.

3. **Check if the String is a Palindrome**:
   - Use two-pointer technique (start from the beginning and end of the filtered string and compare characters) to check whether the string is a palindrome.

#### Steps:
1. **Filtering the Input**: Loop through the string and build a new string with only alphanumeric characters.
2. **Lowercase Conversion**: Convert all uppercase characters to lowercase.
3. **Palindrome Check**: Use two pointers (`start` and `end`) to compare characters from both ends. If all characters match, the string is a palindrome.
## Problem Solution
```cpp
class Solution {
private:
    bool valid(char ch){
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
            return 1;
        }
        return 0;
    }
    char toLower(char ch){
        if((ch >= 'a' && ch <= 'z') || (ch >= '0' &&  ch <= '9')){
            return ch;
        }else{
            char temp = ch - 'A' + 'a';
            return temp;
        }
    }

    bool checkPalindrome(string a){
        int s = 0;
        int e = a.length() - 1;

        while(s<=e){
            if(a[s] != a[e]){
                return 0;
            }else{
                s++;
                e--;
            }
        }

        return 1;
    }
public:
    bool isPalindrome(string s) {
        int i = 0;
        string temp = "";

        for(int j = 0; j < s.length(); j++){
            if(valid(s[j])){
                temp.push_back(s[j]);
            }
        }

        for(int j = 0; j < temp.length(); j++){
            temp[j] = toLower(temp[j]);
        }

        return checkPalindrome(temp);
    }
};
```

## Problem Solution Explanation

```cpp
class Solution {
private:
    // Function to check if a character is alphanumeric
    bool valid(char ch){
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
            return true;
        }
        return false;
    }
```

- **`valid(char ch)`**: This helper function checks if a character `ch` is a valid alphanumeric character (either a letter or a digit). It returns `true` for alphanumeric characters, otherwise `false`.

---

```cpp
    // Function to convert a character to lowercase if it is an uppercase letter
    char toLower(char ch){
        if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')){
            return ch;  // If it's already lowercase or a digit, return it as is
        }else{
            char temp = ch - 'A' + 'a';  // Convert uppercase to lowercase
            return temp;
        }
    }
```

- **`toLower(char ch)`**: This function converts uppercase letters to lowercase. It checks if `ch` is already lowercase or a digit (in which case it returns `ch` unchanged). If `ch` is an uppercase letter, it converts it to lowercase by calculating the ASCII difference.

---

```cpp
    // Function to check if a string is a palindrome
    bool checkPalindrome(string a){
        int s = 0;
        int e = a.length() - 1;

        while(s <= e){
            if(a[s] != a[e]){
                return false;  // If characters don't match, return false
            }else{
                s++;  // Move start pointer forward
                e--;  // Move end pointer backward
            }
        }

        return true;  // Return true if all characters match
    }
```

- **`checkPalindrome(string a)`**: This function checks if the given string `a` is a palindrome. It uses two pointers, `s` (start) and `e` (end), to compare characters from both ends of the string. If any pair of characters don't match, it returns `false`. Otherwise, it continues until all characters are compared, and returns `true` if the string is a palindrome.

---

### Public Method: `isPalindrome`

```cpp
public:
    bool isPalindrome(string s) {
        int i = 0;
        string temp = "";

        // Step 1: Filter out non-alphanumeric characters
        for(int j = 0; j < s.length(); j++){
            if(valid(s[j])){
                temp.push_back(s[j]);
            }
        }

        // Step 2: Convert the filtered string to lowercase
        for(int j = 0; j < temp.length(); j++){
            temp[j] = toLower(temp[j]);
        }

        // Step 3: Check if the filtered string is a palindrome
        return checkPalindrome(temp);
    }
};
```

### Explanation:
1. **Filtering Non-Alphanumeric Characters**:
   - The loop `for(int j = 0; j < s.length(); j++)` iterates through the input string `s`. The `valid(s[j])` function is used to check if the character is alphanumeric. If it is, the character is added to the `temp` string, which will only contain alphanumeric characters.

2. **Convert to Lowercase**:
   - After building the `temp` string with only valid characters, the second loop converts all uppercase characters to lowercase using the `toLower()` function. 

3. **Check if Palindrome**:
   - Once the filtered string `temp` is prepared and all characters are lowercase, `checkPalindrome(temp)` is called to check if `temp` is a palindrome. The result is returned as the final answer.

---

### Example Walkthrough:
For the input string:
```
"A man, a plan, a canal: Panama"
```

1. After filtering, the `temp` string becomes:
```
"amanaplanacanalpanama"
```

2. After converting to lowercase (which in this case doesn't change anything since it's already lowercase), the string is still:
```
"amanaplanacanalpanama"
```

3. The `checkPalindrome()` function confirms this string is a palindrome by comparing characters from both ends.

Thus, the function returns `true`.
