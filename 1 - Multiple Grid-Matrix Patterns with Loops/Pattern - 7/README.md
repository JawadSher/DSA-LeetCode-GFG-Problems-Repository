# Problem Statement

Write a C++ program that generates a number pattern based on a user-provided integer `N`. The pattern should consist of `N` rows where each row contains a sequence of numbers starting from the row number. The sequence should increase by one with each column in the row.

### Requirements

1. **Input:**
   - An integer `N` representing the number of rows in the pattern. The value of `N` should be provided by the user.

2. **Output:**
   - Print `N` rows. Each row `i` should contain a sequence of numbers starting from `i` and ending at `i + (i - 1)`, separated by spaces. Each row should be printed on a new line.

### Constraints

- `1 ≤ N ≤ 100`

### Example

**Input:**

```
Enter the value of N: 4
```

**Output:**

```
1 
2 3 
3 4 5 
4 5 6 7
```

**Explanation:**

- For `N = 4`, the output will be:
    - Row 1: `1` (Starting number is `1`)
    - Row 2: `2 3` (Starting number is `2`)
    - Row 3: `3 4 5` (Starting number is `3`)
    - Row 4: `4 5 6 7` (Starting number is `4`)

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
    ```
    
    - Initializes the variable `row` to 1. `row` will track the current row number in the output pattern.

- **Nested While Loop for Output**:
    
    ```cpp
    while (row <= N) {
        int col = 1;
        while (col <= row) {
            cout << row + col - 1 << " ";
            col++;
        }
        cout << endl;
        row++;
    }
    ```
    
    - **Outer Loop (`while (row <= N) { ... }`)**:
        - Executes `N` times, once for each row from 1 up to `N`.
        - `row` increments after each row is printed.
    
    - **Inner Loop (`while (col <= row) { ... }`)**:
        - Executes `row` times for each row, starting from 1 up to the current value of `row`.
        - `col` increments after printing each number.

    - **Printing**:
        - `cout << row + col - 1 << " ";` prints the value of `row + col - 1` followed by a space for each iteration of the inner loop.
        - `row + col - 1` calculates the number to print in each position of the current row. For the first column (`col = 1`), it prints `row`, for the second column (`col = 2`), it prints `row + 1`, and so on.
        - After printing all numbers for the current `row`, `cout << endl;` moves to the next line to start a new row.

- **Output**:
    
    - After the execution of the nested loops, the program prints a pattern of numbers where each row `i` contains numbers starting from `i` and ending at `i + (i - 1)`.

### Summary

- This program takes an integer input `N` from the user.
- It then prints `N` rows where each row `i` contains numbers starting from `i` and ending at `i + (i - 1)`.
- The program uses nested while loops to achieve this output, with `row` controlling the number of rows, `col` controlling the number of numbers per row, and the expression `row + col - 1` calculating the value to print at each position in the pattern.

This code snippet demonstrates basic control flow using loops and input/output operations in C++, and it showcases how to generate a specific pattern of numbers based on user input.

---
