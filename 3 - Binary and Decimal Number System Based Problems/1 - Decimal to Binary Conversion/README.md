## Problem Statement

The task is to convert a decimal number to its binary representation. For example, if the decimal number is `13`, its binary representation is `1101`.

### Constraints

- The decimal number is a non-negative integer.
- The binary representation will be expressed as an integer (e.g., `1101` for `13`).

### Examples

1. **Example 1:**

   **Input:**

   `decimal = 13`

   **Output:**

   `1101`

   **Explanation:**

   The decimal number `13` converts to the binary string `"1101"`. The calculation is as follows:
   - Decimal `13` = \(1 \times 2^3 + 1 \times 2^2 + 0 \times 2^1 + 1 \times 2^0\)
   - Binary = `"1101"`

2. **Example 2:**

   **Input:**

   `decimal = 10`

   **Output:**

   `1010`

   **Explanation:**

   The decimal number `10` converts to the binary string `"1010"`. The calculation is as follows:
   - Decimal `10` = \(1 \times 2^3 + 0 \times 2^2 + 1 \times 2^1 + 0 \times 2^0\)
   - Binary = `"1010"`

## Source Code Explanation

### 1. Header Files and Namespace

```cpp
#include <iostream>
#include <math.h>
using namespace std;
```

- **`#include <iostream>`**: Includes the standard input-output stream library for input and output operations.
- **`#include <math.h>`**: Includes the math library for mathematical functions, specifically `pow()` for power calculations.
- **`using namespace std;`**: Allows usage of standard C++ symbols and objects in the `std` namespace without prefixing them with `std::`.

### 2. Function `decimal_to_binary`

```cpp
int decimal_to_binary(int n) {
    int binary = 0;
    int i = 0;
    while (n) {
        int bit = n & 1;
        binary = (bit * pow(10, i)) + binary;
        n = n >> 1;
        i = i + 1;
    }
    return binary;
}
```

#### Parameters

- **`int n`**: The decimal number to be converted to binary.

#### Return Type

- **`int`**: Returns the binary representation of the decimal number as an integer.

#### Logic

- **Initialization**:
  - **`int binary = 0;`**: Initializes `binary` to `0`, which will store the binary representation of the decimal number.
  - **`int i = 0;`**: Initializes the variable `i` to `0`, which is used to keep track of the position in the binary number (units, tens, hundreds, etc.).

- **While Loop**:
  ```cpp
  while (n) {
      int bit = n & 1;
      binary = (bit * pow(10, i)) + binary;
      n = n >> 1;
      i = i + 1;
  }
  ```
  - **`int bit = n & 1;`**: Extracts the least significant bit of `n` using the bitwise AND operation. This bit represents the current binary digit (0 or 1).
  - **`binary = (bit * pow(10, i)) + binary;`**:
    - **`bit * pow(10, i)`**: Places the extracted bit at the correct position (units, tens, etc.) in the binary number.
    - **`+ binary`**: Adds the newly placed bit to the existing binary value.
  - **`n = n >> 1;`**: Right-shifts `n` by one position to process the next bit in the subsequent iteration.
  - **`i = i + 1;`**: Increments `i` to move to the next positional value (e.g., from units to tens).

- **Return**:
  - **`return binary;`**: Returns the computed binary representation.

### 3. Function `main`

```cpp
int main() {
    int decimal = 13;
    int output = decimal_to_binary(decimal);
    cout << "Binary of " << decimal << " is : " << output;
    return 0;
}
```

#### Variables

- **`int decimal = 13;`**: Initializes the decimal number to `13`.
- **`int output = decimal_to_binary(decimal);`**: Calls the `decimal_to_binary` function to convert `decimal` to its binary representation and stores the result in `output`.

#### Output

- **`cout << "Binary of " << decimal << " is : " << output;`**: Prints the original decimal number (`decimal`) and its binary representation (`output`).

---

## Example Execution

For `decimal = 13`, the program executes as follows:

- **`decimal_to_binary(13)`** converts `13` to `1101`.
- **`cout`** statement prints: `"Binary of 13 is : 1101"`

This C++ program efficiently converts a decimal number to its binary representation using bitwise operations and mathematical functions, demonstrating a practical approach to binary conversion.
