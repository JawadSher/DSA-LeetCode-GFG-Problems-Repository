# Problem Statement

Determine whether a given integer is a power of two. A number is a power of two if it can be expressed as \(2^k\), where \(k\) is a non-negative integer.

## Constraints

- The number should be a positive integer.

## Example

**Input:**
```
16
```

**Output:**
```
True
```

---

## Problem Solution Explanation

### 1. Header Inclusion

```cpp
#include <iostream>
```

- `#include <iostream>`: Includes the `iostream` header file, which provides functionalities for input/output operations such as `cout` (for console output) and `cin` (for console input).

### 2. Namespace

```cpp
using namespace std;
```

- `using namespace std;`: This brings the standard namespace into scope, allowing you to use standard C++ objects like `cout`, `cin`, and `string` without needing to prefix them with `std::`.

### 3. `power_of_two` Function

```cpp
string power_of_two(int n) {
    return n > 0 && (n & (n - 1)) == 0 ? "True" : "False";
}
```

- `string power_of_two(int n)`: Defines a function named `power_of_two` that takes an integer `n` as input and returns a `string` ("True" or "False") indicating whether `n` is a power of two.

#### Function Body:

- `return n > 0 && (n & (n - 1)) == 0 ? "True" : "False";`:
  - **Check Positive Number:** `n > 0` ensures that `n` is positive because a power of two cannot be zero or negative.
  - **Bitwise Operation:** `(n & (n - 1)) == 0` efficiently checks if `n` is a power of two:
    - In binary representation, a power of two has only one set bit (1) and all other bits are zero.
    - Subtracting 1 from `n` flips the least significant set bit to 0, and the result of `n & (n - 1)` will be zero only if `n` was a power of two.
  - **Ternary Operator:** The entire condition is used in a ternary operator. If the condition is true, "True" is returned; otherwise, "False" is returned.

### 4. `main` Function

```cpp
int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    string output = power_of_two(n);
    cout << "Is the number a power of two: " << output << endl;
    return 0;
}
```

- `int main()`: This is the entry point of the program where execution starts.
  
#### Function Body:

- `int n;`: Declares an integer variable `n` to store the user input.
- `cout << "Enter a number: ";`: Prompts the user to enter a number.
- `cin >> n;`: Reads the user's input and stores it in `n`.
- `string output = power_of_two(n);`: Calls the `power_of_two` function with `n` as input and stores the returned string ("True" or "False") in `output`.
- `cout << "Is the number a power of two: " << output << endl;`: Prints a message to the console indicating whether the entered number is a power of two.
- `return 0;`: Indicates successful program termination.

---

## How the Code Works

1. The program starts by prompting the user to enter an integer number.
2. The entered number is passed to the `power_of_two` function.
3. Inside the `power_of_two` function:
   - It checks if the number is positive and if the result of `n & (n - 1)` is zero.
   - If both conditions are met, the function returns "True", indicating the number is a power of two. Otherwise, it returns "False".
4. The `main` function receives the result and prints whether the number is a power of two.

## Example Execution

**Input:**
```
16
```

**Execution:**
1. The number 16 is passed to the `power_of_two` function.
2. Inside the function:
   - `n > 0` evaluates to `true` as 16 is positive.
   - `(16 & (16 - 1)) == 0`:
     - Binary representation of 16: `10000`
     - Subtracting 1: `10000 - 1 = 01111`
     - Bitwise AND: `10000 & 01111 = 00000`
   - Since the result is zero, the function returns "True".
3. The `main` function prints: `Is the number a power of two: True`.

### Key Takeaway

This code efficiently checks if a number is a power of two by leveraging bitwise operations. It provides a concise solution to determine the power of two status using binary representation properties.

---
