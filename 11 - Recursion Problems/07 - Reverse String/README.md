<h1 align='center'></h1>

## Problem Statement

**Problem URL :** [None]()

Write a function to reverse a given string using recursion. The function should take the input string and reverse it without using any built-in reverse functions.


## Problem Solution
```cpp
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void reversed(string &new_str, int i){

  int n = new_str.size()-i-1;
  if(i >= n) return ;

  swap(new_str[i], new_str[n]);

  reversed(new_str, i+1);
}

int main() {
  string new_str = "ABCDEF";
  int i = 0;
  // int j = new_str.size();

  cout << "Before : " << new_str <<endl;

  reversed(new_str, i);

  cout<< "After : " << new_str <<endl;
  return 0;
}
```

## Problem Solution Explanation

```cpp
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
```
- **#include <iostream>**: Includes the input/output stream library to use `cin` and `cout` for console input and output.
- **#include <algorithm>**: Includes the algorithm library, but here it's not used. This can be removed.
- **#include <string>**: Includes the string library to manipulate strings.

```cpp
void reversed(string &new_str, int i) {
```
- **void reversed(string &new_str, int i)**: This is a recursive function that reverses a string in place. It takes a reference to a string (`new_str`) and an integer `i` that represents the current index.

```cpp
  int n = new_str.size()-i-1;
```
- **int n = new_str.size()-i-1;**: This calculates the corresponding index from the end of the string that needs to be swapped with the character at index `i`. For example, if `i` is 0, `n` will be the last index (`size - 1`).

```cpp
  if(i >= n) return ;
```
- **if(i >= n) return;**: This is the base case of the recursion. If the index `i` reaches or exceeds `n`, which indicates that the swapping is complete or the middle of the string is reached, the function exits.

```cpp
  swap(new_str[i], new_str[n]);
```
- **swap(new_str[i], new_str[n]);**: Swaps the character at the `i`-th index with the `n`-th index, reversing the string step by step.

```cpp
  reversed(new_str, i+1);
```
- **reversed(new_str, i+1);**: This makes the recursive call to the function, incrementing `i` to move forward with the next pair of characters.

```cpp
int main() {
  string new_str = "ABCDEF";
  int i = 0;
```
- **string new_str = "ABCDEF";**: Initializes a string `new_str` with the value "ABCDEF" to be reversed.
- **int i = 0;**: Declares the initial index `i` to start recursion from the first character.

```cpp
  cout << "Before : " << new_str <<endl;
```
- **cout << "Before : " << new_str <<endl;**: Prints the original string before the reversal.

```cpp
  reversed(new_str, i);
```
- **reversed(new_str, i);**: Calls the recursive function to reverse the string starting from index `0`.

```cpp
  cout<< "After : " << new_str <<endl;
```
- **cout << "After : " << new_str <<endl;**: Prints the reversed string after recursion completes.

```cpp
  return 0;
```
- **return 0;**: Ends the `main` function, indicating successful execution.

---

### Recursive Function Calls and Tree:

Let's consider how the recursion works for the string "ABCDEF":

1. **Initial call**: `reversed("ABCDEF", 0)`
   - `i = 0`, `n = 5`
   - Swap: `A` and `F`
   - String becomes: "FBCDEA"
   - Recursive call: `reversed("FBCDEA", 1)`

2. **Next call**: `reversed("FBCDEA", 1)`
   - `i = 1`, `n = 4`
   - Swap: `B` and `E`
   - String becomes: "FECDBA"
   - Recursive call: `reversed("FECDBA", 2)`

3. **Next call**: `reversed("FECDBA", 2)`
   - `i = 2`, `n = 3`
   - Swap: `C` and `D`
   - String becomes: "FEDCBA"
   - Recursive call: `reversed("FEDCBA", 3)`

4. **Next call**: `reversed("FEDCBA", 3)`
   - `i = 3`, `n = 2`
   - Base case reached (`i >= n`), so recursion stops.

At each recursive level, the string is modified, and once the base case is reached, the recursion unwinds, returning back to the previous calls until it exits.

### Recursive Function Calls Tree:
```
reversed("ABCDEF", 0)
    -> swap(0, 5) -> "FBCDEA"
    -> reversed("FBCDEA", 1)
        -> swap(1, 4) -> "FECDBA"
        -> reversed("FECDBA", 2)
            -> swap(2, 3) -> "FEDCBA"
            -> reversed("FEDCBA", 3) -> return (base case)
```

### Final Output:
- **Before**: "ABCDEF"
- **After**: "FEDCBA"

---

### Recursion Summary:

- The recursive function keeps dividing the problem by moving indices `i` and `n` closer to the center of the string.
- At each recursion level, characters are swapped, and the process repeats until the base case is met (`i >= n`).
- Once the base case is reached, the function returns, completing the reversal of the string.
