<h1 align='center'>Recursively - Remove - All - Adjacent - Duplicates</h1>

## Problem Statement

**Problem URL :** [Recursively Remove All Adjacent Duplicates](https://www.geeksforgeeks.org/problems/recursively-remove-all-adjacent-duplicates0744/1)

![image](https://github.com/user-attachments/assets/bd2c5540-f4b8-4a7c-8e9b-2bee82a4397a)
![image](https://github.com/user-attachments/assets/48c0b935-ff43-4aba-92e2-26394c9242c7)

## Problem Explanation

**Description:**
You are given a string `s`. Your task is to recursively remove all adjacent duplicate characters in the string until no more adjacent duplicates can be removed. The final string should be returned after all possible adjacent duplicates have been removed.

**Example:**
- **Input:** `"abbbcddc"`
- **Output:** `"a"`

**Explanation:** 
1. **Initial String:** `"abbbcddc"`
2. **First Pass Removal:** `"ac"`
3. **Second Pass Removal:** `"a"`

### Solution Approach

The solution involves recursively removing adjacent duplicates from the string until no more duplicates can be removed. The process consists of two main parts:
1. **Removing Adjacent Duplicates:** Identify and remove all adjacent duplicate characters in one pass.
2. **Recursively Apply the Removal:** Repeat the removal process until the string no longer changes.
   
## Problem Solution
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        // Helper function to remove adjacent duplicates
        string removeAdjecent(const string& s){
           string unique_s;
           
           int i = 0;
           // Iterate through the string
           while(i < s.length()){
               // Check if the current character is equal to the next character
               if(s[i] == s[i+1] && i+1 < s.length()){
                   // Skip all adjacent duplicates
                   while(s[i] == s[i+1] && i+1 < s.length()){
                       i++;
                   }
               } else {
                   // Add the current character to the result string
                   unique_s += s[i];
               }
               
               i++;
           }
           
           return unique_s;
        }
  
  public:
    // Main function to recursively remove adjacent duplicates
    string rremove(string s) {
       string current = s;
       string previous;
       // Repeat the removal process until no more changes
       do {
           previous = current;
           current = removeAdjecent(current);
       } while(current != previous);
       
       return current;
    }   
};

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);  // Read the number of test cases
    while (t--) {
        string s;
        getline(cin, s);  // Read the input string
        Solution ob;
        cout << ob.rremove(s) << "\n";  // Output the result of removing adjacent duplicates
    }
    return 0;
}

```

## Problem Solution Explanation

1. **Include Headers:**
   ```cpp
   #include <bits/stdc++.h>
   using namespace std;
   ```
   - Includes standard headers and uses the `std` namespace for convenience.

2. **Class Definition:**
   ```cpp
   class Solution {
   ```
   - Defines the `Solution` class which will contain the methods to solve the problem.

3. **Private Method - `removeAdjecent`:**
   ```cpp
   private:
       string removeAdjecent(const string& s){
           string unique_s;
   ```
   - **`removeAdjecent`:** This method removes adjacent duplicates from the input string `s`.

4. **Initialize Index and Start Iteration:**
   ```cpp
           int i = 0;
           while(i < s.length()){
   ```
   - **`i`:** Index to traverse the string.
   - **`while(i < s.length())`:** Loop through each character in the string.

5. **Check for Adjacent Duplicates:**
   ```cpp
               if(s[i] == s[i+1] && i+1 < s.length()){
   ```
   - **`s[i] == s[i+1] && i+1 < s.length()`:** Checks if the current character is the same as the next character.

6. **Skip Adjacent Duplicates:**
   ```cpp
                   while(s[i] == s[i+1] && i+1 < s.length()){
                       i++;
                   }
   ```
   - **`while(s[i] == s[i+1] && i+1 < s.length())`:** Skips all adjacent duplicates by incrementing the index `i`.

7. **Add Non-Duplicate Character:**
   ```cpp
               } else {
                   unique_s += s[i];
               }
               
               i++;
           }
   ```
   - **`unique_s += s[i]`:** Adds the current character to the result string `unique_s` if it is not part of an adjacent duplicate.
   - **`i++`:** Move to the next character.

8. **Return Processed String:**
   ```cpp
           return unique_s;
       }
   ```
   - **`return unique_s`:** Returns the string after removing adjacent duplicates.

9. **Public Method - `rremove`:**
   ```cpp
   public:
       string rremove(string s) {
   ```
   - **`rremove`:** This method repeatedly removes adjacent duplicates until the string stabilizes.

10. **Initialize Variables for Recursion:**
    ```cpp
           string current = s;
           string previous;
    ```
    - **`current`:** Stores the current string being processed.
    - **`previous`:** Stores the string from the previous iteration.

11. **Recursive Removal Loop:**
    ```cpp
           do {
               previous = current;
               current = removeAdjecent(current);
           } while(current != previous);
    ```
    - **`do-while`:** Continues processing until the string no longer changes (i.e., no more adjacent duplicates).

12. **Return Final Result:**
    ```cpp
           return current;
       }
    ```
    - **`return current`:** Returns the final string with all adjacent duplicates removed.

13. **Main Function:**
    ```cpp
     int main() {
       int t;
       string tc;
       getline(cin, tc);
       t = stoi(tc);
       while (t--) {
           string s;
           getline(cin, s);
           Solution ob;
           cout << ob.rremove(s) << "\n";
       }
       return 0;
     }
    ```
    - **`int t;`:** Reads the number of test cases.
    - **`getline(cin, tc);`:** Reads the number of test cases as a string and converts it to an integer.
    - **`while (t--)`:** Processes each test case.
    - **`getline(cin, s);`:** Reads each string input.
    - **`Solution ob;`:** Creates an instance of the `Solution` class.
    - **`cout << ob.rremove(s) << "\n";`:** Prints the result of removing adjacent duplicates.

### Example Walkthrough

**Example Input:**
```
"abbbaacc"
```

**Steps:**
1. **Initial String:** `"abbbaacc"`
2. **First Pass Removal:**
   - **Remove adjacent duplicates:** `"cc"` removed to `"aa"`, `"aa"` removed to `""` which is not correct here.
3. **After correction and final check:** `"abc"`

**Final Output:**
```
"abc"
```

### How the Solution Works:

- **Recursive Removal:** The `rremove` method applies the `removeAdjecent` function iteratively until no more changes are made to the string, ensuring all adjacent duplicates are removed.
- **Efficient Removal:** The `removeAdjecent` method efficiently processes the string to remove adjacent duplicates in a single pass.
- **Stabilization Check:** The `do-while` loop ensures that all possible adjacent duplicates are removed by repeatedly applying the removal function until the string stabilizes.

This approach efficiently handles the problem by using iterative removal combined with recursive checking, ensuring the final string is devoid of adjacent duplicates.
