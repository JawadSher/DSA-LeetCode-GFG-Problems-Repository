<h1 align='center'>Palindrom - String</h1>

## Problem Statement

**Problem URL :** [None]()

Write a recursive function to check if a given string is a palindrome. The function should compare characters from the beginning and the end of the string and check if the string reads the same forward and backward. If the string is a palindrome, print "Palindrome"; otherwise, print "Not Palindrome."

## Problem Solution
```cpp
#include <iostream>
using namespace std;

void pallindrome(string new_str, int i){
  int n = new_str.size() - i - 1;

  if(i >= n){
    cout<< "Palindrom" <<endl;
    return;
  }

  if (new_str[i] != new_str[n]){
    cout<< "Not Palindrom" <<endl;
    return;
  }

  pallindrome(new_str, i+1);
}

int main() {
  string new_str = "ABBCCBBA";
  int i = 0;

  pallindrome(new_str, i);
  return 0;
}
```

## Problem Solution Explanation

```cpp
#include <iostream>
using namespace std;
```
- **#include <iostream>**: Includes the input/output stream library for using `cin` and `cout` for input and output operations.

```cpp
void pallindrome(string new_str, int i) {
```
- **void pallindrome(string new_str, int i)**: Defines a recursive function that takes a string (`new_str`) and an integer `i` (representing the current index) to check if the string is a palindrome.

```cpp
  int n = new_str.size() - i - 1;
```
- **int n = new_str.size() - i - 1;**: Calculates the index `n` of the character from the end of the string that corresponds to the character at index `i`. For example, if `i = 0`, `n = size - 1`.

```cpp
  if(i >= n) {
    cout<< "Palindrom" <<endl;
    return;
  }
```
- **if(i >= n)**: This is the base case of the recursion. If `i` is greater than or equal to `n`, it means all characters have been checked, and the string is confirmed to be a palindrome. The function prints "Palindrome" and returns.

```cpp
  if (new_str[i] != new_str[n]) {
    cout<< "Not Palindrom" <<endl;
    return;
  }
```
- **if(new_str[i] != new_str[n])**: If the character at index `i` does not match the character at index `n`, the string is not a palindrome. The function prints "Not Palindrome" and returns.

```cpp
  pallindrome(new_str, i+1);
```
- **pallindrome(new_str, i+1)**: The recursive call increments `i` to check the next pair of characters.

```cpp
int main() {
  string new_str = "ABBCCBBA";
  int i = 0;
```
- **string new_str = "ABBCCBBA";**: Initializes the string to be checked for being a palindrome. In this example, the string is "ABBCCBBA".
- **int i = 0;**: Starts the recursion from the first index of the string.

```cpp
  pallindrome(new_str, i);
```
- **pallindrome(new_str, i);**: Calls the recursive function to check if the string is a palindrome.

```cpp
  return 0;
```
- **return 0;**: Terminates the `main` function, indicating successful program execution.

---

### Recursive Function Calls and Tree:

Let's analyze how the recursive calls work for different examples.

#### Example 1: **"ABBCCBBA"**

1. **Initial call**: `pallindrome("ABBCCBBA", 0)`
   - `i = 0`, `n = 7` (last index)
   - Compare: `A == A` → True
   - Recursive call: `pallindrome("ABBCCBBA", 1)`

2. **Next call**: `pallindrome("ABBCCBBA", 1)`
   - `i = 1`, `n = 6`
   - Compare: `B == B` → True
   - Recursive call: `pallindrome("ABBCCBBA", 2)`

3. **Next call**: `pallindrome("ABBCCBBA", 2)`
   - `i = 2`, `n = 5`
   - Compare: `B == B` → True
   - Recursive call: `pallindrome("ABBCCBBA", 3)`

4. **Next call**: `pallindrome("ABBCCBBA", 3)`
   - `i = 3`, `n = 4`
   - Compare: `C == C` → True
   - Recursive call: `pallindrome("ABBCCBBA", 4)`

5. **Base case**: `pallindrome("ABBCCBBA", 4)`
   - `i = 4`, `n = 3`
   - Since `i >= n`, the recursion stops, and "Palindrom" is printed.

- **Result**: Palindrome

#### Example 2: **"ABCBA"**

1. **Initial call**: `pallindrome("ABCBA", 0)`
   - `i = 0`, `n = 4`
   - Compare: `A == A` → True
   - Recursive call: `pallindrome("ABCBA", 1)`

2. **Next call**: `pallindrome("ABCBA", 1)`
   - `i = 1`, `n = 3`
   - Compare: `B == B` → True
   - Recursive call: `pallindrome("ABCBA", 2)`

3. **Base case**: `pallindrome("ABCBA", 2)`
   - `i = 2`, `n = 2`
   - Since `i >= n`, the recursion stops, and "Palindrom" is printed.

- **Result**: Palindrome

#### Example 3: **"ABCD"**

1. **Initial call**: `pallindrome("ABCD", 0)`
   - `i = 0`, `n = 3`
   - Compare: `A != D` → False
   - "Not Palindrom" is printed, and the recursion stops.

- **Result**: Not Palindrome

#### Example 4: **"A"**

1. **Initial call**: `pallindrome("A", 0)`
   - `i = 0`, `n = 0`
   - Since `i >= n`, the recursion stops, and "Palindrom" is printed.

- **Result**: Palindrome (a single character is always a palindrome)

### Recursive Function Call Tree (Example 1):

```
pallindrome("ABBCCBBA", 0)
    -> Compare('A', 'A') -> True
    -> pallindrome("ABBCCBBA", 1)
        -> Compare('B', 'B') -> True
        -> pallindrome("ABBCCBBA", 2)
            -> Compare('B', 'B') -> True
            -> pallindrome("ABBCCBBA", 3)
                -> Compare('C', 'C') -> True
                -> pallindrome("ABBCCBBA", 4) -> Base case reached
```

### Final Output for Each Example:

1. **Input**: "ABBCCBBA"
   - **Output**: Palindrome

2. **Input**: "ABCBA"
   - **Output**: Palindrome

3. **Input**: "ABCD"
   - **Output**: Not Palindrome

4. **Input**: "A"
   - **Output**: Palindrome

### Summary:

- The recursive function checks characters from the beginning and the end of the string.
- If all corresponding pairs of characters match, the string is a palindrome. Otherwise, it's not.
- The base case is reached when the middle of the string is reached (`i >= n`).
