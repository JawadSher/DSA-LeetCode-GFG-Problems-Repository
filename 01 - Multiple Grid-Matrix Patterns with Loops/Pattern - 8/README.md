# Problem Statement

Write a program that generates a pattern of numbers based on the user input. For a given integer `n`, the program should print `n` rows where each row `i` contains numbers in descending order starting from `i` down to `1`.

### Input

- **An integer `n`**: The number of rows to be printed. 

### Output

- Print `n` rows where each row `i` contains numbers in descending order starting from `i` down to `1`.

### Constraints

- **1 ≤ n ≤ 100**

### Example

#### Input
```
Enter the value of n : 5
```

#### Output
```
1 
2 1 
3 2 1 
4 3 2 1 
5 4 3 2 1
```

## Problem Solution Explanation

### Include Header and Namespace

```cpp
#include <iostream>
using namespace std;
```

- **`#include <iostream>`**: Includes the `<iostream>` standard library which provides basic input and output operations (`cout`, `cin`).
- **`using namespace std;`**: Allows us to use standard library objects and functions (like `cout` and `cin`) without prefixing them with `std::`.

### Main Function

```cpp
int main() {
    int n;
    cout << "Enter the value of n : ";
    cin >> n;
```

- **`int main()`**: Entry point of the program.
- **`int n;`**: Declares an integer variable `n` to store the user input.

### Input

```cpp
cout << "Enter the value of n : ";
cin >> n;
```

- **`cout << "Enter the value of n : ";`**: Prompts the user to enter a value for `n`.
- **`cin >> n;`**: Reads the integer value entered by the user and stores it in `n`.

### Initialization

```cpp
int row = 1;
```

- **`int row = 1;`**: Initializes the variable `row` to 1. This variable will be used to track the current row number in the output pattern.

### Nested While Loop for Output

```cpp
while (row <= n) {
    int col = 1;
    while (col <= row) {
        cout << row - col + 1 << " ";
        col = col + 1;
    }
    cout << endl;
    row = row + 1;
}
```

- **Outer Loop (`while (row <= n) { ... }`)**:
    - Executes `n` times, once for each row from 1 up to `n`.
    - **`row`** increments after each row is printed.

- **Inner Loop (`while (col <= row) { ... }`)**:
    - Executes `row` times for each row, starting from 1 up to the current value of `row`.
    - **`col`** increments after printing each number.

- **Printing**:
    - **`cout << row - col + 1 << " ";`**: Prints the value of `row - col + 1` followed by a space for each iteration of the inner loop.
    - **`row - col + 1`**: Calculates the number to print. For each column in the current row, it prints numbers in descending order from `row` down to `1`.

- **After the Inner Loop**:
    - **`cout << endl;`**: Moves to the next line to start a new row.
    - **`row = row + 1;`**: Increments the `row` variable to proceed to the next row.

### Output

- After executing the nested loops, the program prints a pattern where each row `i` contains numbers in descending order starting from `i` down to `1`.

---

This code snippet demonstrates basic control flow using loops and input/output operations in C++, and it shows how to generate a specific pattern of numbers based on user input.

