# Problem Statement

The task is to convert a binary number, which may be negative, from its binary representation to its decimal equivalent. The binary number is provided as an integer where the most significant digit is on the left. If the number is negative, it should be handled appropriately in the conversion.

### Constraints

- The input binary number is provided as an integer (e.g., `-10101`).
- The input integer can be negative, indicating a negative binary number.

### Examples

1. **Example 1:**

   **Input:**

   ```
   -10101
   ```

   **Output:**

   `-21`

   **Explanation:**

   - The positive binary `10101` converts to decimal `21`.
   - Since the input is negative, the result is `-21`.

2. **Example 2:**

   **Input:**

   ```
   1101
   ```

   **Output:**

   `13`

   **Explanation:**

   - The binary `1101` converts to decimal `13`.

## Problem Solution Explanation

### 1. Header Files and Namespace

```cpp
#include <iostream>
#include <math.h>
using namespace std;
```

- **`#include <iostream>`**: Includes the standard input-output stream library for input and output operations.
- **`#include <math.h>`**: Includes the math library for mathematical functions like `pow()`.
- **`using namespace std;`**: Allows usage of standard C++ symbols and objects in the `std` namespace without prefixing them with `std::`.

### 2. Main Function

```cpp
int main() {
    int binary = -10101;
    bool isNegative = binary < 0;
    if (isNegative) {
        binary = -binary;
    }

    int decimal = 0;
    int i = 0;
    while (binary) {
        int digit = binary % 10;
        if (digit == 1) {
            decimal += pow(2, i);
        }
        binary = binary / 10;
        i++;
    }

    if (isNegative) {
        decimal = -decimal;
    }
    cout << "The Decimal is : " << decimal;

    return 0;
}
```

#### Input Handling

- **`int binary = -10101;`**: Initializes the binary number. This example uses `-10101`, but in practice, the input might be read from user input or another source.
- **`bool isNegative = binary < 0;`**: Checks if the binary number is negative.
- **`if (isNegative) { binary = -binary; }`**: Converts the binary number to positive if it is negative. This is done to handle the conversion process uniformly.

#### Binary to Decimal Conversion

- **`int decimal = 0;`**: Initializes the variable `decimal` to store the final decimal value.
- **`int i = 0;`**: Initializes the exponent for the power of 2.

- **Conversion Loop**:
  ```cpp
  while (binary) {
      int digit = binary % 10;
      if (digit == 1) {
          decimal += pow(2, i);
      }
      binary = binary / 10;
      i++;
  }
  ```
  - **`int digit = binary % 10;`**: Extracts the least significant digit (0 or 1) from the binary number.
  - **`if (digit == 1) { decimal += pow(2, i); }`**: Adds the corresponding power of 2 to `decimal` if the digit is `1`.
  - **`binary = binary / 10;`**: Removes the least significant digit from `binary`.
  - **`i++;`**: Increments the exponent for the next power of 2.

#### Final Adjustment

- **`if (isNegative) { decimal = -decimal; }`**: Restores the sign of `decimal` if the original binary number was negative.

#### Output

- **`cout << "The Decimal is : " << decimal;`**: Prints the final decimal value to the console.

---

## Example Execution

For an input `-10101`, the program executes as follows:

1. **Input Handling**:
   - `binary = -10101`
   - `isNegative = true`
   - `binary = 10101` (converted to positive)

2. **Binary to Decimal Conversion**:
   - Processing `10101`:
     - `1 * 2^0 = 1`
     - `0 * 2^1 = 0`
     - `1 * 2^2 = 4`
     - `0 * 2^3 = 0`
     - `1 * 2^4 = 16`
   - `decimal = 1 + 4 + 16 = 21`

3. **Final Adjustment**:
   - Since `isNegative` was `true`, `decimal` is set to `-21`.

4. **Output**:
   - `The Decimal is : -21`

This program accurately converts a binary number, including handling negative values, to its decimal equivalent using basic arithmetic and bitwise operations.
