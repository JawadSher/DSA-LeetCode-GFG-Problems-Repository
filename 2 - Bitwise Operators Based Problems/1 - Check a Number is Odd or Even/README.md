# Problem Statement

Write a C++ program to determine if a given integer is even or odd. The program should:

1. Take an integer input from the user.
2. Use a function to check if the number is even or odd.
3. Print the result to the console.

### Constraints

- The integer input ( n ) should be within the range of typical 32-bit integers, i.e. `−2^31 ≤ n ≤ 2^31 −1`.

### Example

**Input:**
```
4
```

**Output:**
```
The number is : Even
```

**Input:**
```
7
```

**Output:**
```
The number is : Odd
```

## Problem Solution Explanation

#### Includes and Namespace

```cpp
#include <iostream>
using namespace std;
```

- `#include <iostream>`: This line includes the Input/Output Stream library, which is necessary for using `cin` and `cout`.
- `using namespace std;`: This line allows us to use the standard namespace so that we don't have to prefix `std::` before standard functions and objects like `cin`, `cout`, and `string`.

#### Function Definition

```cpp
string function(int n) {
    return (n & 1) == 0 ? "Even" : "Odd";
}
```

- `string function(int n)`: This defines a function named `function` that takes an integer `n` as its parameter and returns a `string`.
- `(n & 1) == 0 ? "Even" : "Odd"`: This is a ternary operator that checks whether the number `n` is even or odd.
    - `(n & 1) == 0`: The expression `n & 1` performs a bitwise AND operation between `n` and `1`. If the least significant bit of `n` is 0, it means `n` is even; otherwise, `n` is odd.
    - If the condition `(n & 1) == 0` is true, it returns the string `"Even"`.
    - If the condition is false, it returns the string `"Odd"`.

#### Main Function

```cpp
int main() {
    int number;
    cin >> number;
    string output = function(number);
    cout << "The number is : " << output << endl;

    return 0;
}
```

- `int main() { ... }`: This is the main function, where the execution of the program begins.
- `int number;`: Declares an integer variable `number`.
- `cin >> number;`: Reads an integer input from the user and stores it in the variable `number`.
- `string output = function(number);`: Calls the `function` with `number` as the argument and stores the returned string ("Even" or "Odd") in the variable `output`.
- `cout << "The number is : " << output << endl;`: Prints the result to the console, indicating whether the number is even or odd.
- `return 0;`: Indicates that the program finished successfully.

## Example Execution Output

1. The program starts and waits for user input.
2. The user enters a number, e.g., `4`.
3. The `function(4)` is called.
    - Inside `function`, the bitwise operation `4 & 1` results in `0` (since 4 in binary is `100` and the least significant bit is `0`).
    - Since `0 == 0` is true, the function returns the string `"Even"`.
4. The main function then prints "The number is : Even".

This code effectively checks if a number is even or odd and outputs the appropriate message to the user.

--- 

This format provides a clear and structured approach to the problem, ensuring that users understand both the requirements and the implementation details of the solution.
