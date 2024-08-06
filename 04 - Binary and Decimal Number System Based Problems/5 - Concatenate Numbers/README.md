# Problem Statement

The task is to read a specified number of integers from the user, concatenate them to form a single integer, and then display the concatenated integer. For instance, if the user inputs the numbers `1`, `2`, `3`, `4`, and `5`, the concatenated integer should be `12345`.

### Constraints

- The number of integers to be concatenated is fixed at `5`.
- Each integer input by the user is a single-digit number.

### Examples

1. **Example 1:**

   **Input:**

   ```
   Enter the value of n : 1
   Enter the value of n : 2
   Enter the value of n : 3
   Enter the value of n : 4
   Enter the value of n : 5
   ```

   **Output:**

   `Concatenated Number is : 12345`

   **Explanation:**

   The integers `1`, `2`, `3`, `4`, and `5` are concatenated to form `12345`.

2. **Example 2:**

   **Input:**

   ```
   Enter the value of n : 9
   Enter the value of n : 8
   Enter the value of n : 7
   Enter the value of n : 6
   Enter the value of n : 5
   ```

   **Output:**

   `Concatenated Number is : 98765`

   **Explanation:**

   The integers `9`, `8`, `7`, `6`, and `5` are concatenated to form `98765`.

## Problem Solution Explanation

### 1. Header File and Namespace

```cpp
#include <iostream>
using namespace std;
```

- **`#include <iostream>`**: Includes the standard input-output stream library for input and output operations.
- **`using namespace std;`**: Allows usage of standard C++ symbols and objects in the `std` namespace without prefixing them with `std::`.

### 2. Function `main`

```cpp
int main() {
    int n;
    int range = 5;
    int ans = 0;
    while (range) {
        cout << "Enter the value of n : ";
        cin >> n;
        ans = ans * 10 + n;
        range--;
    }
    cout << "Concatenated Number is : " << ans;

    return 0;
}
```

#### Variables

- **`int n;`**: Variable to store the user input.
- **`int range = 5;`**: Initializes `range` to `5`, indicating the number of integers to read.
- **`int ans = 0;`**: Initializes `ans` to `0`, which will store the concatenated result.

#### Logic

- **While Loop**:
  ```cpp
  while (range) {
      cout << "Enter the value of n : ";
      cin >> n;
      ans = ans * 10 + n;
      range--;
  }
  ```
  - **`cout << "Enter the value of n : ";`**: Prompts the user to enter a value.
  - **`cin >> n;`**: Reads the user input and stores it in `n`.
  - **`ans = ans * 10 + n;`**:
    - **`ans * 10`**: Shifts the digits of `ans` one position to the left (i.e., multiplies by 10).
    - **`+ n`**: Adds the new digit `n` to the rightmost position of `ans`.
  - **`range--;`**: Decreases the `range` by `1` for each iteration, eventually terminating the loop after 5 inputs.

- **Output**:
  ```cpp
  cout << "Concatenated Number is : " << ans;
  ```
  - Prints the concatenated integer stored in `ans`.

---

## Example Execution

For the user inputs `1`, `2`, `3`, `4`, and `5`, the program executes as follows:

- **`ans = 0`**
  - **Iteration 1**: `n = 1`, `ans = 0 * 10 + 1 = 1`
  - **Iteration 2**: `n = 2`, `ans = 1 * 10 + 2 = 12`
  - **Iteration 3**: `n = 3`, `ans = 12 * 10 + 3 = 123`
  - **Iteration 4**: `n = 4`, `ans = 123 * 10 + 4 = 1234`
  - **Iteration 5**: `n = 5`, `ans = 1234 * 10 + 5 = 12345`

- **Output**: `Concatenated Number is : 12345`

This C++ program reads a fixed number of single-digit integers from the user and concatenates them into a single integer using basic arithmetic operations and a loop.
