<h1 align='center'>Maximum - Occuring - Character</h1>

## Problem Statement

**Problem URL :** [Maximum Occuring Character](https://www.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/0)

![image](https://github.com/user-attachments/assets/e0556d8c-d89c-40b8-ae69-8dc307bda324)
![image](https://github.com/user-attachments/assets/53b31f3d-9c3b-4c1b-99ad-aa217f256ecf)

## Problem Explanation
Given a string, you need to find the character that appears the maximum number of times in the string. If there are multiple characters with the same frequency, return the lexicographically smallest character (i.e., the one that comes first alphabetically).

### Example:

**Input:**
```
2
testsample
outputoutput
```

**Output:**
```
e
t
```

Explanation:
1. In the first test case, the string `"testsample"` contains multiple occurrences of `t`, `e`, and `s`. The character `e` has the highest count and comes lexicographically first among the characters with the highest count.
   
2. In the second test case, `"outputoutput"` contains `t`, `u`, and `o` as the characters with the highest count, but `t` is lexicographically smaller, so it is the answer.


### Beginner Approach to Solve the Problem

To solve the problem, we need to understand the following:

1. **Count the occurrences of each character**: We need to iterate through the string and count how many times each character appears. Since we're dealing with English alphabet characters (both uppercase and lowercase), we can map the characters `a-z` (and `A-Z`) to an array of size 26. Each index of the array will correspond to a character's occurrence count.
   
2. **Find the maximum count**: After counting the occurrences, we need to find the character that has the highest count.

3. **Handle multiple characters with the same frequency**: If multiple characters have the same highest frequency, the lexicographically smallest character needs to be chosen.

## Problem Solution
```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    char getMaxOccuringChar(string str)
    {
        int arr[26] = {0};
        int number = 0;
        
        for(int i = 0; i < str.length(); i++){
            char ch = str[i];
            
            if(ch >= 'a' && ch <= 'z'){
                number = ch - 'a';
            }else{
                number = ch - 'A';
            }
            
            arr[number]++;
        }
        
        int maxi, ans;
        for(int i = 0; i < 26; i++){
            if(maxi < arr[i]){
                ans = i;
                maxi = arr[i];
            }
        }
        
        char maxChar = 'a' + ans;
        return maxChar;
    }

};

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
```

## Problem Solution Explanation

Here’s how the given C++ code works, explained line by line:

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    // Function to find the maximum occurring character in the string
    char getMaxOccuringChar(string str)
    {
        int arr[26] = {0};  // Array to count frequency of each character (lowercase 'a' to 'z')
        int number = 0;
```

1. **`int arr[26] = {0};`** initializes an array of size 26 to zero. Each index will represent a letter of the alphabet, where index 0 corresponds to 'a', index 1 to 'b', and so on.
   
2. **`int number = 0;`** is a variable that will hold the position of the character in the alphabet (0 for 'a', 1 for 'b', etc.).

---

```cpp
        for(int i = 0; i < str.length(); i++){  // Loop through the string
            char ch = str[i];
            
            // Check if the character is lowercase
            if(ch >= 'a' && ch <= 'z'){
                number = ch - 'a';  // Calculate index for lowercase letters
            }else{
                number = ch - 'A';  // Calculate index for uppercase letters
            }
            
            arr[number]++;  // Increment the count for the corresponding character
        }
```

3. **`for(int i = 0; i < str.length(); i++)`**: Loop through each character in the string.
   
4. **`char ch = str[i];`** extracts the character at position `i` in the string.

5. **Checking if the character is lowercase or uppercase**: 
   - If the character is lowercase (between 'a' and 'z'), we calculate its position by subtracting `'a'` from it, i.e., `ch - 'a'`.
   - If it is uppercase, we subtract `'A'` to map it similarly.
   
6. **`arr[number]++`** increments the frequency of the character in the `arr` array.

---

```cpp
        int maxi = -1, ans = 0;  // maxi holds the maximum frequency, ans holds the index of the character
        for(int i = 0; i < 26; i++){  // Loop through the frequency array
            if(maxi < arr[i]){  // If current character has a higher frequency
                ans = i;        // Update ans to this index (the character)
                maxi = arr[i];  // Update maxi to the new maximum frequency
            }
        }
```

7. **`int maxi = -1, ans = 0;`** initializes two variables:
   - `maxi` holds the highest frequency found so far.
   - `ans` holds the index of the character with the maximum frequency.

8. **Loop through the frequency array**: This loop checks the frequency of each character in the array. If the frequency of the current character (`arr[i]`) is greater than `maxi`, we update `maxi` and set `ans` to `i`.

---

```cpp
        char maxChar = 'a' + ans;  // Convert the index to the corresponding character
        return maxChar;  // Return the character with the maximum frequency
    }
};
```

9. **`char maxChar = 'a' + ans;`** converts the index `ans` back to the corresponding character. Since `ans` is the index of the character in the alphabet (0 for 'a', 1 for 'b', etc.), adding it to `'a'` gives the actual character.

10. **`return maxChar;`** returns the character with the highest occurrence.

---

### Main Function

```cpp
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
```

1. **Input number of test cases (`t`)**: The number of test cases is taken as input.
   
2. **Loop over each test case**: For each test case, the input string `str` is taken.

3. **Call the `getMaxOccuringChar` function**: For each input string, the `getMaxOccuringChar` function is called to find the character with the maximum occurrences.

4. **Output the result**: The result is printed for each test case.

---

### Example Walkthrough

**Test Case 1:**

Input: 
```
1
testsample
```

- **Step 1**: The input string is `"testsample"`.
- **Step 2**: The `getMaxOccuringChar` function processes the string and builds the frequency array. The character counts will look like this:
  - `t`: 3 times
  - `e`: 2 times
  - `s`: 3 times
  - `a`: 1 time
  - `m`: 1 time
  - `p`: 1 time
- **Step 3**: The characters `t` and `s` have the highest frequency (3), but since `e` appears lexicographically first, it is the answer.

**Output:**
```
t
```

### Summary of the Approach:

1. **Count occurrences**: Use an array of size 26 to store the frequency of each character.
2. **Find the maximum**: Iterate through the frequency array to find the character with the highest count.
3. **Lexicographical order**: If multiple characters have the same count, the lexicographically smallest character is chosen.


