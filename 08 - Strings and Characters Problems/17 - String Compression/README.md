<h1 align='center'>String - Compression</h1>

## Problem Statement

**Problem URL :** [String Compression](https://leetcode.com/problems/string-compression/)

![image](https://github.com/user-attachments/assets/ba2b58e8-8856-472c-8063-4cfd64d53897)
![image](https://github.com/user-attachments/assets/612d052a-0d45-437c-81ab-9ee7d166fa5a)

## Problem Explanation

**Description:**
Given a list of characters `chars`, compress it using the following algorithm:

1. Begin with the first character in the list and count consecutive occurrences of this character.
2. Replace the sequence of characters with the character followed by the number of occurrences, but only if the number of occurrences is greater than 1.
3. After processing all characters, the compressed list should be stored in `chars`, and the length of the compressed list should be returned.

**Example:**

- **Input:** `['a', 'a', 'b', 'b', 'c', 'c', 'c']`
- **Output:** `['a', '2', 'b', '2', 'c', '3']`
- **Explanation:** The string `aabbbccc` is compressed to `a2b2c3`.
  
## Problem Solution
```cpp
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        int index = 0;

        while(i < n){
            int j = i + 1;

            while(j < n && chars[i] == chars[j]){
                j++;
            }

            chars[index++] = chars[i];
            
            int count = j - i;

            if(count > 1){
                string s_count = to_string(count);
                for(char c : s_count){
                    chars[index++] = c;
                }

            }

            i = j;
        }
        
        return index;
    }
};
```

## Problem Solution Explanation


Here's the code with detailed line-by-line explanations:

#### Initialization
```cpp
int n = chars.size();  // Size of the input vector.
int i = 0;            // Start index for the current sequence.
int index = 0;        // Index for placing compressed characters in the vector.
```

#### Main Loop
```cpp
while(i < n){
    int j = i + 1;
```
- **Purpose:** Start at index `i` and find the end of the sequence of the same character starting at `i`.

#### Find the End of the Current Character Sequence
```cpp
    while(j < n && chars[i] == chars[j]){
        j++;
    }
```
- **Purpose:** Move `j` to the position where the current character sequence ends.

#### Store the Current Character
```cpp
    chars[index++] = chars[i];
```
- **Purpose:** Store the character at position `i` into the compressed vector and increment the `index`.

#### Calculate the Number of Occurrences
```cpp
    int count = j - i;
```
- **Purpose:** Calculate the number of times the current character appears in sequence.

#### Store the Count if Greater Than 1
```cpp
    if(count > 1){
        string s_count = to_string(count);
        for(char c : s_count){
            chars[index++] = c;
        }
    }
```
- **Purpose:** If the count is greater than 1, convert the count to a string and store each digit in the compressed vector.

#### Move to the Next Character Sequence
```cpp
    i = j;
```
- **Purpose:** Move `i` to the start of the next character sequence.

#### Return the Length of the Compressed Vector
```cpp
return index;
```
- **Purpose:** Return the length of the compressed vector, which represents the number of characters in the compressed form.

### How This Solution Solves the Problem

1. **Iterates Through the Vector:** The solution uses a loop to process each character and find the sequences of identical characters.
2. **Compresses Sequences:** For each sequence of identical characters, it stores the character and, if necessary, the count of occurrences in the compressed vector.
3. **Updates the Vector In-Place:** The compressed characters are written directly into the original vector, effectively modifying it in place.
4. **Returns the Compressed Length:** The function returns the length of the vector after compression, which indicates how many characters are in the compressed form.

**Overall:** The solution efficiently compresses the input vector by processing each sequence of characters, storing only essential data, and ensures that the original vector is updated in place without additional space usage for another vector.
