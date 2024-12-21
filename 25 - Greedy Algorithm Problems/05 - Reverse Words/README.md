<h1 align="center">Reverse - Words</h1>

## Problem Statement

**Problem URL :** [Reverse - Words](https://www.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/393ae620-d127-45b5-81d6-75fc7e77fa7c)

### Problem Explanation
The problem requires reversing the words in a given string. A word is defined as a sequence of non-space characters, and words are separated by spaces. You are tasked with reversing the order of words in the string, but keeping the characters within each word intact.

#### **Example 1:**

- **Input:** `"The quick brown fox"`
- **Output:** `"fox brown quick The"`

**Explanation:** The order of the words is reversed, but the characters within each word remain unchanged.

#### **Example 2:**

- **Input:** `"Hello World"`
- **Output:** `"World Hello"`

**Explanation:** The words "Hello" and "World" are reversed, and the characters inside the words stay the same.

#### **Example 3:**

- **Input:** `"  I love   programming  "`
- **Output:** `"programming love I"`

**Explanation:** In this case, even though there are extra spaces before the first word and after the last word, they should be ignored while reversing the words.


### Approach: 

To solve this problem, you do **not** need a greedy algorithm, as it doesn’t require making optimal choices at each step. Instead, you can solve it in a straightforward manner by splitting the string into words and then reversing the order of the words.

#### **Step-by-Step Approach:**
1. **Split the String into Words:**
   - We can use an input string stream (`istringstream`) to extract words from the input string, splitting the string by spaces.
   
2. **Reverse the Order of Words:**
   - After splitting the string into words, we can reverse the list of words using the built-in `reverse()` function in C++.

3. **Reconstruct the String:**
   - After reversing the words, we will join them back together with a single space between each word and return the final string.


## Problem Solution
```cpp
class Solution {
  public:
    // Function to reverse words in a given string
    string reverseWords(string &s) {
        // Create a vector to store individual words from the string
        vector<string> words;
        
        // Temporary string to hold each word while reading from the string
        string word;
        
        // Create an input string stream to split the string 's' into words
        istringstream iss(s);
        
        // While there are words in the string stream, extract them and push to the 'words' vector
        while(iss >> word) 
            words.push_back(word);  // Extract each word and add it to the vector
        
        // Reverse the vector of words
        reverse(words.begin(), words.end());
        
        // Initialize an empty string to store the result
        string ans = "";
        
        // Loop through the reversed vector of words
        for(int i = 0; i < words.size(); i++){
            // Add the current word to the result string
            ans += words[i];
            
            // If this is not the last word, add a space between words
            if(i != words.size() - 1) 
                ans += " ";
        }
        
        // Return the final reversed string
        return ans;
    }
};
```

## Problem Solution Explanation

```cpp
class Solution {
  public:
    // Function to reverse words in a given string
    string reverseWords(string &s) {
```
- This is the function signature. It defines the function `reverseWords` which takes a string reference `s` and returns a string.
  
```cpp
        // Create a vector to store individual words from the string
        vector<string> words;
```
- A `vector` called `words` is declared to store the words extracted from the string `s`.

```cpp
        // Temporary string to hold each word while reading from the string
        string word;
```
- A temporary string `word` is used to hold each word as we extract them from the string.

```cpp
        // Create an input string stream to split the string 's' into words
        istringstream iss(s);
```
- An `istringstream` `iss` is created from the string `s`. This allows us to extract words from the string.

```cpp
        // While there are words in the string stream, extract them and push to the 'words' vector
        while(iss >> word) 
            words.push_back(word);  // Extract each word and add it to the vector
```
- The `while(iss >> word)` loop reads each word from the stream `iss` one by one. Each word is added to the `words` vector.

```cpp
        // Reverse the vector of words
        reverse(words.begin(), words.end());
```
- After extracting all the words, we reverse the order of the words in the `words` vector using the `reverse()` function. This places the last word at the front and so on.

```cpp
        // Initialize an empty string to store the result
        string ans = "";
```
- An empty string `ans` is initialized to store the final result after concatenating the words in reverse order.

```cpp
        // Loop through the reversed vector of words
        for(int i = 0; i < words.size(); i++){
            // Add the current word to the result string
            ans += words[i];
            
            // If this is not the last word, add a space between words
            if(i != words.size() - 1) 
                ans += " ";
        }
```
- The `for` loop iterates over the `words` vector, appending each word to the result string `ans`. 
- If the current word is not the last word, a space is added after the word.

```cpp
        // Return the final reversed string
        return ans;
    }
};
```
- Finally, the reversed string `ans` is returned, which contains the words in reversed order.


### Example Walkthrough:

Let's consider an example with the input string `"The quick brown fox"`.

1. **Step 1 - Split the String into Words:**
   - The `istringstream` will extract words one by one:
     - "The"
     - "quick"
     - "brown"
     - "fox"

2. **Step 2 - Reverse the Words:**
   - After extracting the words, the `words` vector will contain: `["The", "quick", "brown", "fox"]`.
   - Reversing the vector will give: `["fox", "brown", "quick", "The"]`.

3. **Step 3 - Reconstruct the String:**
   - We loop through the reversed words and concatenate them into the result string `ans`:
     - Add "fox" → `ans = "fox"`
     - Add "brown" → `ans = "fox brown"`
     - Add "quick" → `ans = "fox brown quick"`
     - Add "The" → `ans = "fox brown quick The"`

4. **Final Output:**
   - The final output is `"fox brown quick The"`.


### Time and Space Complexity:

#### **Time Complexity:**
1. **Extracting Words:**
   - Extracting words using the `istringstream` takes O(n), where `n` is the length of the input string `s`.
2. **Reversing the Vector:**
   - Reversing the vector of words takes O(k), where `k` is the number of words in the vector. In the worst case, `k` is O(n) (if each character is a separate word).
3. **Reconstructing the String:**
   - Reconstructing the string by concatenating the words takes O(n) because we are iterating through each word and appending it to the result string.

Therefore, the overall time complexity is **O(n)**.

#### **Space Complexity:**
1. **Storing Words:**
   - The space complexity is determined by the `words` vector, which stores each word separately. The total space required is proportional to the number of characters in the input string `s`, which is O(n).

Therefore, the overall space complexity is **O(n)**.


### Summary:

- The code successfully reverses the words in the given string while maintaining the character order within each word.
- The approach is simple and efficient, with both time and space complexity of **O(n)**.


