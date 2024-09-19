<h1 align='center'>Numbers - to - Letters</h1>

## Problem Statement

**Problem URL :** [None]()

## Problem Solution
```cpp
#include <iostream>
#include <string>
using namespace std;

void sayDigit(int n, string arr[]){
  // base case
  if(n == 0) return;

  int digit = n % 10;
  n = n / 10;
  
  sayDigit(n, arr);
  
  cout<< arr[digit] << " ";
}

int main() {
  
  string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

  int n = 234;

  sayDigit(n, arr);
  return 0;
}
```

## Problem Solution Explanation
Certainly! Let's dive into the details of the `sayDigit` function, how it works, and visualize its function call stack and recursion tree.

The purpose of the `sayDigit` function is to print the English word representation of each digit of a number `n` in the order from most significant to least significant. For example, if `n` is `234`, it should print "two three four".

Here's how the function works:

1. **Base Case**:
   - If `n == 0`, the function returns immediately. This is the stopping condition for the recursion when there are no more digits left to process.

2. **Recursive Case**:
   - **Extract the Last Digit**: `int digit = n % 10;`
     - The last digit of `n` is extracted using the modulus operator `%`.
   - **Remove the Last Digit**: `n = n / 10;`
     - The last digit is removed by integer division.
   - **Recursive Call**: `sayDigit(n, arr);`
     - The function is called recursively with the updated number `n`, which now has one less digit.
   - **Print the Digit**: `cout << arr[digit] << " ";`
     - After the recursive call returns, the function prints the English word corresponding to the last digit.

### Detailed Example

Let's go through an example with `n = 234`.

1. **Initial Call**: `sayDigit(234, arr)`

   - **Extract the Last Digit**: `digit = 234 % 10 = 4`
   - **Remove the Last Digit**: `n = 234 / 10 = 23`
   - **Recursive Call**: `sayDigit(23, arr)`

2. **Recursive Call**: `sayDigit(23, arr)`

   - **Extract the Last Digit**: `digit = 23 % 10 = 3`
   - **Remove the Last Digit**: `n = 23 / 10 = 2`
   - **Recursive Call**: `sayDigit(2, arr)`

3. **Recursive Call**: `sayDigit(2, arr)`

   - **Extract the Last Digit**: `digit = 2 % 10 = 2`
   - **Remove the Last Digit**: `n = 2 / 10 = 0`
   - **Recursive Call**: `sayDigit(0, arr)`

4. **Base Case**: `sayDigit(0, arr)`

   - Since `n == 0`, the function returns immediately.

5. **Returning from Recursion**:
   - The function call `sayDigit(2, arr)` resumes and prints `arr[2]` which is "two".
   - The function call `sayDigit(23, arr)` resumes and prints `arr[3]` which is "three".
   - The function call `sayDigit(234, arr)` resumes and prints `arr[4]` which is "four".

### Function Call Stack

Here’s what the function call stack looks like during the execution for `sayDigit(234, arr)`:

```
sayDigit(234, arr)
  |
  |-- sayDigit(23, arr)
        |
        |-- sayDigit(2, arr)
              |
              |-- sayDigit(0, arr)
```

- **sayDigit(234, arr)** calls **sayDigit(23, arr)**
- **sayDigit(23, arr)** calls **sayDigit(2, arr)**
- **sayDigit(2, arr)** calls **sayDigit(0, arr)**
- **sayDigit(0, arr)** hits the base case and returns immediately.

### Recursion Tree

The recursion tree for the call `sayDigit(234, arr)` looks like this:

```
                 sayDigit(234, arr)
                 /                 \
        sayDigit(23, arr)       (Print "four")
             /                  \
  sayDigit(2, arr)         (Print "three")
       /                     \
sayDigit(0, arr)        (Print "two")
   (Base Case)   
```

- **sayDigit(234, arr)** triggers **sayDigit(23, arr)**
- **sayDigit(23, arr)** triggers **sayDigit(2, arr)**
- **sayDigit(2, arr)** triggers **sayDigit(0, arr)**, which hits the base case and returns.

After hitting the base case, the recursion tree starts to return, and the prints occur from the most recent call to the oldest call. Thus, the output is "two three four".

This function effectively breaks down the problem into smaller subproblems by peeling off one digit at a time, processing them, and then combining the results in the desired order.
