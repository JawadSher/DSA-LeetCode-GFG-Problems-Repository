# Problem Statement

Write a C++ program that takes an integer input \( N \) and prints a triangular pattern of characters. The pattern should start from 'D' at the top row and decrement by one character for each subsequent row, with each row containing more characters.

### Constraints

`1 ≤ N ≤ 26`

### Example

#### Input
```
Enter the value of N: 4
```

#### Output
```
D 
C D 
B C D 
A B C D
```

---

## Problem Solution Explanation

- **Header and Namespace:**

  ```cpp
  #include <iostream>
  using namespace std;
  ```

  - `#include <iostream>`: Includes the `iostream` header file, which provides input and output functionalities for the program. You'll use `cout` for printing to the console and `cin` for getting user input.
  - `using namespace std;`: Declares the use of the `std` namespace, which contains standard library components frequently used in C++.

- **Main Function:**

  ```cpp
  int main() {
  ```

  - Defines the `main` function, which is the entry point of your C++ program. The code execution begins here.

- **Variable Declaration:**

  ```cpp
  int N;
  ```

  - Declares an integer variable `N` to store the number of rows the user will enter later.

- **User Input:**

  ```cpp
  cout << "Enter the value of N : ";
  cin >> N;
  ```

  - `cout << "Enter the value of N : ";`: Prompts the user to enter a value for `N` using `cout`.
  - `cin >> N;`: Reads the user's input and stores it in the `N` variable using `cin`.

- **Outer Loop for Rows (while loop):**

  ```cpp
  int row = 1;
  while (row <= N) {
  ```

  - Initializes a variable `row` to 1. This `while` loop continues as long as `row` is less than or equal to `N` (the number of rows entered by the user). This loop controls the number of rows printed in the pattern.

- **Inner Loop for Columns (while loop):**

  ```cpp
  int col = 1;
  while (col <= row) {
  ```

  - Inside each iteration of the outer loop, initializes `col` to 1. This `while` loop continues as long as `col` is less than or equal to `row`. This loop controls the number of characters printed in each row.

- **Character Calculation and Printing:**

  ```cpp
  char ch = 'D' - row + col;
  cout << ch << " ";
  ```

  - `char ch = 'D' - row + col;`: Calculates the character to be printed based on the current `row` and `col` values. It subtracts `row - 1` from 'D' (which has an ASCII code of 68) to get the corresponding character code.
  - `cout << ch << " ";`: Prints the calculated character `ch` followed by a space using `cout`.

- **Increment and Newline:**

  ```cpp
  col++;
  cout << endl;
  ```

  - `col++;`: Increments the `col` counter to move to the next character in the current row.
  - `cout << endl;`: Prints a newline character `endl` after each row is complete, moving the output cursor to the next line.

- **Outer Loop Increment:**

  ```cpp
  row++;
  ```

  - After printing all characters for the current row (`col` from 1 to `row`), increments the `row` counter to move to the next row in the outer loop.

- **Program Termination:**

  ```cpp
  return 0;
  ```

  - Indicates successful program termination by returning 0 from the `main` function.

---

### Example Output

#### For `N = 4`:

```
Enter the value of N: 4
D 
C D 
B C D 
A B C D
```

### Summary

- This C++ program prompts the user to enter an integer `N`.
- It then prints `N` rows where each row `i` starts from `'D' - (i - 1)` and extends up to `'D'` for that row.
- The program uses nested `while` loops: the outer loop controls the number of rows (`row`), and the inner loop controls the number of characters per row (`col`), with `char ch = 'D' - row + col;` calculating the character to print at each position in the pattern.

This explanation covers the functionality and structure of the C++ code snippet, detailing how it generates the specific output pattern based on user input.
