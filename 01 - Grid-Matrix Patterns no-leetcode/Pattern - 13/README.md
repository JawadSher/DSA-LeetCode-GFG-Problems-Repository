# Problem Statement

Write a C++ program that takes an integer input \( N \) and prints a pattern of characters. The pattern should consist of \( N \) rows where each row \( i \) contains \( i \) characters starting from 'A', and each subsequent row continues the sequence of characters from where the previous row ended. Characters should be printed with a space in between.

### Constraints

 `1 ≤ N ≤ 26`

### Example

#### Input
```
Enter the value of N: 4
```

#### Output
```
A 
B C 
D E F 
G H I J
```

### Explanation

- **Input \( N = 4 \)**:
  - **Row 1**: Starts with 'A' and contains 1 character.
  - **Row 2**: Continues with 'B' and contains 2 characters: 'B C'.
  - **Row 3**: Continues with 'D' and contains 3 characters: 'D E F'.
  - **Row 4**: Continues with 'G' and contains 4 characters: 'G H I J'.

---

## Problem Solution Explanation

- **Include Header and Namespace**:

  ```cpp
  #include <iostream>
  using namespace std;
  ```

  - This includes the `<iostream>` standard library which provides basic input and output operations (`cout`, `cin`). `using namespace std;` allows us to use `cout` and `cin` without prefixing `std::`.

- **Main Function**:

  ```cpp
  int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;
  ```

  - This defines the `main()` function, which is the entry point of the program. It declares an integer variable `N` to store user input.

- **Input**:

  ```cpp
  cout << "Enter the value of N: ";
  cin >> N;
  ```

  - Prompts the user to enter a value for `N` and stores it in the variable `N`.

- **Initialization**:

  ```cpp
  int row = 1;
  char ch = 'A';
  ```

  - Initializes the variable `row` to 1. `row` will track the current row number in the output pattern.
  - Initializes the variable `ch` to `'A'`. `ch` will be used to print characters starting from 'A' and incrementing for each column.

- **Nested While Loop for Output**:

  ```cpp
  while (row <= N) {
    int col = 1;
    while (col <= row) {
      cout << ch << " ";
      col++;
      ch++;
    }
    cout << endl;
    row++;
  }
  ```

  - **Outer Loop (`while (row <= N) { ... }`)**:
    - Executes `N` times, once for each row from 1 up to `N`.
    - `row` increments after each row is printed.
  - **Inner Loop (`while (col <= row) { ... }`)**:
    - Executes `row` times for each row, printing characters starting from `ch`.
    - `cout << ch << " ";` prints the current character `ch`.
    - `ch++;` increments `ch` to the next character in the ASCII sequence ('A' -> 'B' -> 'C', etc.).
  - **Printing**:
    - After printing all characters for the current row (`col` from 1 to `row`), `cout << endl;` moves to the next line to start a new row.

- **Output**:

  - After the execution of the nested loops, the program prints a pattern of characters where each row `i` contains characters starting from 'A' up to `'A' + i - 1`, repeated `i` times horizontally.

### Time and Space Complexity

- **Time Complexity**: \( O(N^2) \)
  - The outer while loop runs `N` times, and the inner while loop runs up to `N` times for each row. Thus, the total number of iterations is \( \frac{N \times (N + 1)}{2} \), which simplifies to \( O(N^2) \).

- **Space Complexity**: \( O(1) \)
  - The space used by the program does not depend on the input size and remains constant. We only use a few variables to store the current row, column, and character.

---

This completes the full explanation of the C++ code snippet, including the problem statement, constraints, examples, code explanation, and complexity analysis.
