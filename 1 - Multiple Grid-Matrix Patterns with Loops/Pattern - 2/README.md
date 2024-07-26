## Problem Statement

Create a C++ program that generates a square grid pattern based on a user-provided integer `N`. The grid should consist of `N` rows and `N` columns, where each row contains numbers in descending order from `N` down to `1`. The output should be formatted such that each number is followed by a space, and each row starts on a new line.

**Requirements:**

1. **Input:**
   - An integer `N` that specifies the number of rows and columns in the grid.

2. **Output:**
   - A square grid of numbers where each row contains numbers from `N` down to `1`, with each number separated by a space.
   - Each row should be printed on a new line.

3. **Formatting:**
   - Numbers in each row should be separated by a single space.
   - No trailing spaces should be present at the end of each row.
   - Each row should end with a newline character.

### **Constraints:**

- The value of `N` must be a positive integer.
- The maximum value of `N` should be within reasonable limits for practical display, e.g., up to `1000`.

**Example 1:**

**Input:**
```
3
```

**Output:**
```
3 2 1
3 2 1
3 2 1
```

**Explanation:**
- For `N = 3`, the program should print a 3x3 grid where each row contains the numbers 3, 2, and 1 in descending order.

**Example 2:**

**Input:**
```
4
```

**Output:**
```
4 3 2 1
4 3 2 1
4 3 2 1
4 3 2 1
```

**Explanation:**
- For `N = 4`, the program should print a 4x4 grid where each row contains the numbers 4, 3, 2, and 1 in descending order.

**Example 3:**

**Input:**
```
5
```

**Output:**
```
5 4 3 2 1
5 4 3 2 1
5 4 3 2 1
5 4 3 2 1
5 4 3 2 1
```

**Explanation:**
- For `N = 5`, the program should print a 5x5 grid where each row contains the numbers 5, 4, 3, 2, and 1 in descending order.




## Problem Solution Explanation

- **Including necessary libraries:**

    ```cpp
    #include <iostream>
    using namespace std;
    ```

    - This includes the standard input-output stream (`iostream`) library and uses the `std` namespace.

- **Main function definition:**

    ```cpp
    int main() {
        // Code for the program
        return 0;
    }
    ```

    - `main()` is the entry point of every C++ program.

- **Variable declaration and user input:**

    ```cpp
    int N;
    cout << "Enter the value of N: ";
    cin >> N;
    ```

    - `int N;` declares an integer variable `N`.
    - `cout << "Enter the value of N: ";` prompts the user to enter a value for `N`.
    - `cin >> N;` reads an integer value from the user input and assigns it to `N`.

- **Nested while loops for pattern printing:**

    ```cpp
    int row = 1;
    while (row <= N) {
        int col = 1;
        while (col <= N) {
            cout << N - col + 1 << " ";
            col++;
        }
        cout << endl;
        row++;
    }
    ```

    - **Outer `while` loop (`row` loop):**
        - `int row = 1;` initializes `row` to `1`.
        - `while (row <= N) { ... }` continues as long as `row` is less than or equal to `N`.
        - Each iteration of the outer loop handles one row of the pattern.

    - **Inner `while` loop (`col` loop):**
        - `int col = 1;` initializes `col` to `1`.
        - `while (col <= N) { ... }` continues as long as `col` is less than or equal to `N`.
        - Each iteration of the inner loop prints `N - col + 1`.
        - `N - col + 1` calculates the numbers to be printed in reverse order from `N` down to `1`.

    - **Output:**
        - `cout << N - col + 1 << " ";` prints the current number followed by a space.
        - `col++;` increments `col` to move to the next number in the current row.

    - **End of row:**
        - After printing all numbers in a row, `cout << endl;` moves to the next line to start a new row.

    - **End of `row` loop:**
        - `row++;` increments `row` to move to the next row, repeating the process until `row` exceeds `N`.

## Example Output



- **Example 3:**

    **Input:**
    ```
    5
    ```

    **Output:**
    ```
    5 4 3 2 1
    5 4 3 2 1
    5 4 3 2 1
    5 4 3 2 1
    5 4 3 2 1
    ```

    **Explanation:**
    - For `N = 5`, the program outputs a 5x5 grid where each row contains numbers from `5` down to `1`.

## Summary

- The program prompts the user to enter a number `N`.
- It then prints a square pattern of numbers where each row contains numbers in descending order from `N` to `1`.
- The size of the pattern (number of rows and columns) is determined by the value of `N` entered by the user.
- This program demonstrates the use of nested `while` loops, input-output operations (`cout` and `cin`), and basic arithmetic operations in C++.

---
