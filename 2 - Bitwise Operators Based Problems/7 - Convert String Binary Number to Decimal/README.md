## Source Code Explanation
1.  **Header Files and Namespace**:
    
    -   `#include <iostream>`: Includes the standard input-output stream library for input and output operations.
    -   `#include <string>`: Includes the string library for string manipulation.
    -   `using namespace std;`: Allows usage of standard C++ symbols and objects in the `std` namespace without prefixing them with `std::`.
2.  **Function `binary_to_integer`**:
    
    -   **Parameters**: `const string& binary_str` is a reference to a constant string representing the binary number.
    -   **Return Type**: `int` - returns the integer representation of the binary string.
    -   **Logic**:
        -   `int result = 0;`: Initializes `result` to 0, which will store the integer representation of the binary string.
        -   `for (char c : binary_str) {`: Iterates through each character `c` in the `binary_str`.
        -   `result = (result << 1) | (c - '0');`:
            -   `result << 1`: Left-shifts `result` by one position. This operation effectively multiplies `result` by 2 for each iteration, which aligns with converting binary to decimal.
            -   `(c - '0')`: Converts the character `c` (which is either `'0'` or `'1'`) to its integer equivalent:
                -   If `c` is `'0'`, `c - '0'` evaluates to `0`.
                -   If `c` is `'1'`, `c - '0'` evaluates to `1`.
            -   `|`: Bitwise OR operator combines the shifted `result` with the integer value of `c`.
        -   This loop accumulates the integer value of the binary string as it processes each character from left to right.
3.  **Function `main`**:
    
    -   **Variables**:
        -   `string binary_str = "1101";`: Initializes `binary_str` with the binary string `"1101"`.
        -   `int integer_value = binary_to_integer(binary_str);`: Calls `binary_to_integer` function to convert `binary_str` to its integer representation and stores the result in `integer_value`.
    -   **Output**:
        -   `cout << binary_str << " in binary is " << integer_value << " in decimal." << endl;`: Prints the original binary string (`binary_str`), followed by its corresponding integer value (`integer_value`), and a descriptive message indicating the conversion from binary to decimal.

## Example Execution:

For `binary_str = "1101"`, the program executes as follows:

-   `binary_to_integer("1101")` converts `"1101"` to `13`.
-   `cout` statement prints: `"1101 in binary is 13 in decimal."`

This C++ program efficiently converts a binary string to its decimal integer representation using bitwise left shift (`<<`) and bitwise OR (`|`), demonstrating a practical application of bitwise operations in programming.
