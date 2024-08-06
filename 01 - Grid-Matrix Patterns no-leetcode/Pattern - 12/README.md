# Problem Statement

Write a program that generates a pattern of characters based on user input. For a given integer `N`, the program should print `N` rows where each row `i` contains the character `'A' + (i - 1)` repeated `i` times horizontally.

### Input

- **An integer `N`**: The number of rows in the pattern.

### Output

- Print `N` rows where each row `i` contains the character `'A' + (i - 1)` repeated `i` times horizontally.

### Constraints

- **1 ≤ N ≤ 26**

### Example

#### Input
```
Enter the value of N: 5
```

#### Output
```
A 
B B 
C C C 
D D D D 
E E E E E
```

---

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
    int N;
    cout << "Enter the value of N: ";
    cin >> N;
```

- **`int main()`**: Entry point of the program.
- **`int N;`**: Declares an integer variable `N` to store the user input.

### Input

```cpp
cout << "Enter the value of N: ";
cin >> N;
```

- **`cout << "Enter the value of N: ";`**: Prompts the user to enter a value for `N`.
- **`cin >> N;`**: Reads the integer value entered by the user and stores it in `N`.

### Initialization

```cpp
int row = 1;
```

- **`int row = 1;`**: Initializes the variable `row` to 1. This variable will be used to track the current row number in the output pattern.

### Nested While Loop for Output

```cpp
while (row <= N) {
    int col = 1;
    while (col <= row) {
        char ch = 'A' + row - 1;
        cout << ch << " ";
        col++;
    }
    cout << endl;
    row++;
}
```

- **Outer Loop (`while (row <= N) { ... }`)**:
    - Executes `N` times, once for each row from 1 up to `N`.
    - **`row`** increments after each row is printed.

- **Inner Loop (`while (col <= row) { ... }`)**:
    - Executes `row` times for each row, printing characters based on the value of `row`.
    - **`char ch = 'A' + row - 1;`**: Calculates the character to print in each position of the grid.
        - When `row` is 1, `ch` is `'A' + 1 - 1`, which is `'A'`.
        - When `row` is 2, `ch` is `'A' + 2 - 1`, which is `'B'`, and so on.
    - **`cout << ch << " ";`**: Prints the character `ch` followed by a space for each iteration of the inner loop.
    - After printing all characters for the current row (`col` from 1 to `row`), **`cout << endl;`** moves to the next line to start a new row.

### Output

- After executing the nested loops, the program prints a pattern where each row `i` contains the character `'A' + (i - 1)` repeated `i` times horizontally.

---

## Time and Space Complexity

### Time Complexity

- **Outer Loop**: Runs `N` times.
- **Inner Loop**: Runs `row` times for each iteration of the outer loop.

Thus, the total time complexity is \( O(1 + 2 + 3 + \ldots + N) \), which simplifies to \( O(N^2) \), where `N` is the number of rows.

### Space Complexity

- **Auxiliary Space**: The program uses a constant amount of extra space for variables (`N`, `row`, `col`, and `ch`).

Thus, the space complexity is \( O(1) \).

---

This code snippet demonstrates basic control flow using loops and input/output operations in C++, and it shows how to generate a specific pattern of characters based on user input. The analysis covers both the time and space complexity of the solution.
