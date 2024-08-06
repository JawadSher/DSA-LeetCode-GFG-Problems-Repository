# Problem Statement

The task is to reverse the digits of a given integer. For example, if the input integer is `123456`, the reversed integer should be `654321`.

### Constraints

- The input integer is a non-negative integer.
- The reversed integer should preserve the digits but in reverse order.

### Examples

1. **Example 1:**

   **Input:**

   `num = 123456`

   **Output:**

   `654321`

   **Explanation:**

   The integer `123456` when reversed becomes `654321`.

2. **Example 2:**

   **Input:**

   `num = 407`

   **Output:**

   `704`

   **Explanation:**

   The integer `407` when reversed becomes `704`.

## Problem Solution Explanation

### 1. Header File and Namespace

```cpp
#include <iostream>
using namespace std;
```

- **`#include <iostream>`**: Includes the standard input-output stream library for input and output operations.
- **`using namespace std;`**: Allows usage of standard C++ symbols and objects in the `std` namespace without prefixing them with `std::`.

### 2. Function `reverser`

```cpp
int reverser(int num) {
    int reverse_num = 0;
    while (num) {
        int digit = num % 10;
        reverse_num = reverse_num * 10 + digit;
        num = num / 10;
    }
    return reverse_num;
}
```

#### Parameters

- **`int num`**: The integer to be reversed.

#### Return Type

- **`int`**: Returns the reversed integer.

#### Logic

- **Initialization**:
  - **`int reverse_num = 0;`**: Initializes `reverse_num` to `0`, which will store the reversed integer.

- **While Loop**:
  ```cpp
  while (num) {
      int digit = num % 10;
      reverse_num = reverse_num * 10 + digit;
      num = num / 10;
  }
  ```
  - **`int digit = num % 10;`**: Extracts the last digit of `num` using the modulus operation (`% 10`).
  - **`reverse_num = reverse_num * 10 + digit;`**:
    - **`reverse_num * 10`**: Shifts the current digits of `reverse_num` one position to the left.
    - **`+ digit`**: Adds the extracted digit to the rightmost position of `reverse_num`.
  - **`num = num / 10;`**: Removes the last digit from `num` by performing integer division by `10`.

- **Return**:
  - **`return reverse_num;`**: Returns the reversed integer.

### 3. Function `main`

```cpp
int main() {
    int num = 123456;
    cout << "Before Reverse : " << num << endl;
    int r_value = reverser(num);
    cout << "After Reverse : " << r_value;
    return 0;
}
```

#### Variables

- **`int num = 123456;`**: Initializes the integer to `123456`.
- **`int r_value = reverser(num);`**: Calls the `reverser` function to reverse `num` and stores the result in `r_value`.

#### Output

- **`cout << "Before Reverse : " << num << endl;`**: Prints the original integer (`num`) before reversing.
- **`cout << "After Reverse : " << r_value;`**: Prints the reversed integer (`r_value`).

---

## Example Execution

For `num = 123456`, the program executes as follows:

- **`reverser(123456)`** reverses `123456` to `654321`.
- **`cout`** statements print:
  - `"Before Reverse : 123456"`
  - `"After Reverse : 654321"`

This C++ program effectively reverses the digits of a given integer by utilizing basic arithmetic operations and demonstrates a straightforward approach to digit manipulation.
