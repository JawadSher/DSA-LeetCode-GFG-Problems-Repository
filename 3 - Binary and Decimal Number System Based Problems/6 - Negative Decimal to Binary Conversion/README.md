# Problem Statement

The task is to compute the one's complement and two's complement of a negative integer in binary representation. Given an integer `n`, this program first converts `-n` to its binary representation, then computes the one's complement (inverts all bits), and finally calculates the two's complement (adds 1 to the one's complement).

### Constraints

- The input integer `n` is a negative integer.
- The program assumes that the input `n` fits within typical integer limits in C++.

### Examples

1. **Example 1:**

   **Input:**

   ```
   -5
   ```

   **Output:**

   `1011`

   **Explanation:**

   - The binary representation of `5` is `101`.
   - The one's complement of `101` is `010`.
   - Adding 1 to the one's complement results in `011`, which is the two's complement of `-5`.

2. **Example 2:**

   **Input:**

   ```
   -3
   ```

   **Output:**

   `110`
   
   **Explanation:**

   - The binary representation of `3` is `11`.
   - The one's complement of `11` is `00`.
   - Adding 1 to the one's complement results in `01`, which is the two's complement of `-3`.

## Problem Solution Explanation

### 1. Header Files and Namespace

```cpp
#include <iostream>
#include <string>
using namespace std;
```

- **`#include <iostream>`**: Includes the standard input-output stream library for input and output operations.
- **`#include <string>`**: Includes the string library for string manipulation.
- **`using namespace std;`**: Allows usage of standard C++ symbols and objects in the `std` namespace without prefixing them with `std::`.

### 2. Function `main`

```cpp
int main() {
    int n;
    cin >> n;
    n = n * -1;
    string binary = "";

    while (n) {
        int bit = n & 1;
        binary = to_string(bit) + binary;
        n = n >> 1;
    }

    string oneComp = "";
    for (char c : binary) {
        int bit = c - '0';
        oneComp += (bit == 0 ? '1' : '0');
    }

    int carry = 1;
    for (int i = oneComp.size() - 1; i >= 0; i--) {
        int bit = oneComp[i] - '0' + carry;
        oneComp[i] = (bit % 2) + '0';
        carry = bit / 2;
    }

    cout << oneComp;

    return 0;
}
```

#### Input Reading

- **`int n; cin >> n;`**: Reads an integer `n` from the user input.

#### Conversion to Positive

- **`n = n * -1;`**: Converts `n` to its positive equivalent. Since `n` is negative, multiplying by `-1` yields its positive value.

#### Binary Conversion

- **Binary Computation Loop**:
  ```cpp
  while (n) {
      int bit = n & 1;
      binary = to_string(bit) + binary;
      n = n >> 1;
  }
  ```
  - **`int bit = n & 1;`**: Extracts the least significant bit of `n`.
  - **`binary = to_string(bit) + binary;`**: Prepend the bit to the binary string.
  - **`n = n >> 1;`**: Right shifts `n` to process the next bit.

#### One's Complement Calculation

- **`string oneComp = "";`**: Initializes an empty string for storing the one's complement.
- **One's Complement Loop**:
  ```cpp
  for (char c : binary) {
      int bit = c - '0';
      oneComp += (bit == 0 ? '1' : '0');
  }
  ```
  - **`int bit = c - '0';`**: Converts character `c` to its integer value.
  - **`oneComp += (bit == 0 ? '1' : '0');`**: Inverts the bit (0 to 1, and 1 to 0).

#### Two's Complement Calculation

- **Two's Complement Calculation Loop**:
  ```cpp
  int carry = 1;
  for (int i = oneComp.size() - 1; i >= 0; i--) {
      int bit = oneComp[i] - '0' + carry;
      oneComp[i] = (bit % 2) + '0';
      carry = bit / 2;
  }
  ```
  - **`carry = 1;`**: Initializes carry to 1 for the addition.
  - **`int bit = oneComp[i] - '0' + carry;`**: Adds the carry to the current bit.
  - **`oneComp[i] = (bit % 2) + '0';`**: Updates the bit in the result.
  - **`carry = bit / 2;`**: Updates the carry for the next bit.

#### Output

- **`cout << oneComp;`**: Prints the two's complement of the negative integer.

---

## Example Execution

For an input `-13`, the program executes as follows:

1. **Conversion to Positive**:
   - `n = 13`

2. **Binary Conversion**:
   - Binary representation of `13` is `1101`.

3. **One's Complement**:
   - One's complement of `1101` is `0010`.

4. **Two's Complement**:
   - Adding 1 to `0010` results in `0011`.

5. **Output**:
   - `0011` is printed as the two's complement of `-13`.

This program efficiently computes the one's and two's complement of a negative integer by first converting it to binary and then applying bitwise operations.
