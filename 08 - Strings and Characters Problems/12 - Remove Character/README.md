
<h1 align='center'>Remove - Character</h1>

## Problem Statement

**Problem URL :** [Remove Character](https://www.geeksforgeeks.org/problems/remove-character3815/1)

![image](https://github.com/user-attachments/assets/b8a89b0c-9285-4c0a-9b3d-3fbcc8f889fb)
![image](https://github.com/user-attachments/assets/dae3b42a-c2ab-41c7-b894-51ea2394c347)

### Problem Explanation

**Problem Statement:**  
Given two strings, `string1` and `string2`, the task is to remove all characters from `string1` that are present in `string2`. After removing these characters, return the modified version of `string1`.

**Input:**
- `t`: The number of test cases.
- For each test case:
  - `string1`: The string from which characters need to be removed.
  - `string2`: The string whose characters need to be removed from `string1`.

**Output:**
- For each test case, return the modified `string1` after removing all characters found in `string2`.

## Problem Solution
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string removeChars(string string1, string string2) {
        for(int i = 0; i < string1.length(); i++){
            for(int j = 0; j < string2.length(); j++){
                char ch = string2[j];
                if(ch == string1[i]){
                    string1.replace(i, 1, "");
                    i--;
                }
            }
        }
        
        return string1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string string1,string2;
        cin >> string1; 
        cin >> string2;
        Solution ob;
        cout << ob.removeChars(string1,string2) << endl;
    }
    return 0;
}

```

## Problem Solution Explanation

Here’s the breakdown of the solution step-by-step:

#### 1. **Outer loop (Traversing `string1`):**

```cpp
for(int i = 0; i < string1.length(); i++)
```
- This loop iterates over every character of `string1`.
- The index `i` starts from 0 and continues until it reaches the length of `string1`.

#### 2. **Inner loop (Traversing `string2`):**

```cpp
for(int j = 0; j < string2.length(); j++)
```
- For each character in `string1`, this inner loop iterates over all the characters of `string2`.
- The index `j` starts from 0 and goes up to the length of `string2`.
- The purpose of this inner loop is to check if any character in `string1` matches any character in `string2`.

#### 3. **Storing `string2[j]` in `ch`:**

```cpp
char ch = string2[j];
```
- This line assigns the character at position `j` of `string2` to the variable `ch`. 
- We will compare this `ch` with the current character in `string1`.

#### 4. **Checking if characters match:**

```cpp
if(ch == string1[i])
```
- This condition checks if the character `ch` (from `string2`) matches the current character in `string1[i]`.
- If they match, it indicates that the current character in `string1` should be removed.

#### 5. **Replacing the character in `string1`:**

```cpp
string1.replace(i, 1, "");
```
- The `replace()` function is used to remove the character from `string1`.
- The function call `replace(i, 1, "")` means: replace the character at position `i` in `string1` with an empty string (effectively removing it).
  
#### 6. **Adjusting the index `i`:**

```cpp
i--;
```
- Since the character has been removed from `string1`, the next character has shifted left by one position.
- To ensure that the next iteration checks the correct next character, `i` is decremented by 1. This way, after the outer loop increments `i`, the next character in the original position will be checked.

#### 7. **Returning the modified `string1`:**

```cpp
return string1;
```
- After the loops complete and all characters that match `string2` have been removed from `string1`, the function returns the modified string.

#### 8. **Reading input:**

```cpp
int t;
cin >> t;
```
- The program starts by reading the number of test cases `t`.

#### 9. **Processing each test case:**

```cpp
while (t--) {
    string string1,string2;
    cin >> string1; 
    cin >> string2;
    Solution ob;
    cout << ob.removeChars(string1,string2) << endl;
}
```
- For each test case, the program reads `string1` and `string2`.
- The function `removeChars` from the `Solution` class is called to remove characters from `string1`.
- The modified `string1` is printed as output.

---

### Example Walkthrough:

#### Test Case 1:

```cpp
string1 = "abcdef"
string2 = "bd"
```

**Iteration 1:**
- `i = 0`: `string1[0] = 'a'`, no match with any character in `string2`, so move to the next character.
- `i = 1`: `string1[1] = 'b'`, matches with `string2[0] = 'b'`. Remove `'b'` from `string1`. Now `string1 = "acdef"`, and `i` is decremented to `0` to recheck the next position.
  
**Iteration 2:**
- Continue iterating through `string1` and `string2`. At `i = 2`, `'d'` is removed because it matches with `string2[1] = 'd'`. The final `string1` becomes `"acef"`.

**Output:**
```
"acef"
```

#### Test Case 2:

```cpp
string1 = "hello"
string2 = "eol"
```

**Iteration 1:**
- The inner loop removes `'e'` and both occurrences of `'l'` from `string1`. The final `string1` becomes `"ho"`.

**Output:**
```
"ho"
```

---

### Time Complexity:

- **Time Complexity:** O(n * m), where:
  - `n` is the length of `string1`.
  - `m` is the length of `string2`.
- For each character in `string1`, the algorithm checks all characters in `string2`, leading to a time complexity of O(n * m).

- **Space Complexity:** O(1) because we are modifying the string in place and not using extra data structures.

### Conclusion:

This solution iterates over each character of `string1` and checks whether it appears in `string2`. If it finds a match, it removes the character from `string1`. This is repeated for every test case.
