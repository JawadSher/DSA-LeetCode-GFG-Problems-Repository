# Problem Statement

The task is to convert a binary string to its decimal integer representation. For instance, if the binary string is `"1101"`, the corresponding decimal integer is `13`.

### Constraints

- The binary string consists only of characters `'0'` and `'1'`.
- The binary string has a length between `1` and `32` characters (inclusive).

### Examples

1. **Example 1:**

   **Input:**

   `binary_str = "1101"`

   **Output:**

   `13`

   **Explanation:**

   The binary string `"1101"` converts to the decimal integer `13`. The calculation is as follows:
   - Binary `"1101"` = \(1 \times 2^3 + 1 \times 2^2 + 0 \times 2^1 + 1 \times 2^0\)
   - Decimal = `8 + 4 + 0 + 1` = `13`

2. **Example 2:**

   **Input:**

   `binary_str = "1010"`

   **Output:**

   `10`

   **Explanation:**

   The binary string `"1010"` converts to the decimal integer `10`. The calculation is as follows:
   - Binary `"1010"` = (1 * 2^3 + 0 * 2^2 + 1 * 2^1 + 0 * 2^0)
   - Decimal = `8 + 0 + 2 + 0` = `10`

3. **Example 3:**

   **Input:**

   `binary_str = "0001"`

   **Output:**

   `1`

   **Explanation:**

   The binary string `"0001"` converts to the decimal integer `1`. The calculation is as follows:
   - Binary `"0001"` = (0 * 2^3 + 0 * 2^2 + 0 * 2^1 + 1 * 2^0)
   - Decimal = `0 + 0 + 0 + 1` = `1`

---

## Problem Solution Explanation

### 1. Header Files and Namespace

```cpp
#include <iostream>
#include <string>
using namespace std;
```

- **`#include <iostream>`**: Includes the standard input-output stream library for input and output operations.
- **`#include <string>`**: Includes the string library for string manipulation.
- **`using namespace std;`**: Allows the use of standard C++ symbols and objects in the `std` namespace without prefixing them with `std::`.

### 2. Function `binary_to_integer`

```cpp
int binary_to_integer(const string& binary_str) {
    int result = 0;
    
    for (char c : binary_str) {
        result = (result << 1) | (c - '0');
    }
    
    return result;
}
```

#### Parameters

- **`const string& binary_str`**: A reference to a constant string representing the binary number.

#### Return Type

- **`int`**: Returns the integer representation of the binary string.

#### Logic

- **Initialization**:
  - `int result = 0;`: Initializes `result` to `0`, which will store the integer representation of the binary string.

- **Loop Through Characters**:

  ```cpp
  for (char c : binary_str) {
      result = (result << 1) | (c - '0');
  }
  ```

  - **`for (char c : binary_str)`**: Iterates through each character `c` in `binary_str`.
  - **`result = (result << 1) | (c - '0');`**:
    - **`result << 1`**: Left-shifts `result` by one position. This operation effectively multiplies `result` by 2 for each iteration, aligning with binary to decimal conversion.
    - **`(c - '0')`**: Converts the character `c` (which is either `'0'` or `'1'`) to its integer equivalent:
      - If `c` is `'0'`, `c - '0'` evaluates to `0`.
      - If `c` is `'1'`, `c - '0'` evaluates to `1`.
    - **`|`**: Bitwise OR operator combines the shifted `result` with the integer value of `c`.

  - This loop accumulates the integer value of the binary string as it processes each character from left to right.

### 3. Function `main`

```cpp
int main() {
    string binary_str = "1101"; // Example binary string
    int integer_value = binary_to_integer(binary_str);
    cout << binary_str << " in binary is " << integer_value << " in decimal." << endl;
    return 0;
}
```

#### Variables

- **`string binary_str = "1101";`**: Initializes `binary_str` with the binary string `"1101"`.
- **`int integer_value = binary_to_integer(binary_str);`**: Calls the `binary_to_integer` function to convert `binary_str` to its integer representation and stores the result in `integer_value`.

#### Output

- **`cout << binary_str << " in binary is " << integer_value << " in decimal." << endl;`**: Prints the original binary string (`binary_str`), followed by its corresponding integer value (`integer_value`), and a descriptive message indicating the conversion from binary to decimal.

---

## Example Execution

For `binary_str = "1101"`, the program executes as follows:

- **`binary_to_integer("1101")`** converts `"1101"` to `13`.
- **`cout`** statement prints: `"1101 in binary is 13 in decimal."`

This C++ program efficiently converts a binary string to its decimal integer representation using bitwise left shift (`<<`) and bitwise OR (`|`), demonstrating a practical application of bitwise operations in programming.

---
