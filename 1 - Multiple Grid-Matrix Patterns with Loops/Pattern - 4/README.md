# Problem Statement

Create a C++ program that generates a right-angled triangle pattern of asterisks (`*`) based on a user-provided integer `N`. The triangle should have `N` rows, where the number of asterisks in each row increases incrementally from 1 up to `N`. Each asterisk should be followed by a space, and each row should start on a new line.

**Requirements:**

1. **Input:**
   - An integer `N` that specifies the number of rows in the triangle.

2. **Output:**
   - A right-angled triangle with `N` rows.
   - The first row should contain 1 asterisk, the second row 2 asterisks, and so on until the `N`-th row contains `N` asterisks.
   - Each asterisk should be followed by a space.
   - Each row should end with a newline character.

**Constraints:**

- The value of `N` must be a positive integer.
- The maximum value of `N` should be within reasonable limits for practical display, e.g., up to `100`.

**Example 1:**

**Input:**
```
5
```

**Output:**
```
* 
* * 
* * * 
* * * * 
* * * * *
```

**Explanation:**
- For `N = 5`, the program should print a right-angled triangle with 5 rows, where each row `i` contains `i` asterisks.

**Example 2:**

**Input:**
```
3
```

**Output:**
```
* 
* * 
* * * 
```

**Explanation:**
- For `N = 3`, the program should print a right-angled triangle with 3 rows, where each row `i` contains `i` asterisks.

**Example 3:**

**Input:**
```
4
```

**Output:**
```
* 
* * 
* * * 
* * * * 
```

**Explanation:**
- For `N = 4`, the program should print a right-angled triangle with 4 rows, where each row `i` contains `i` asterisks.

---

## Problem Solution Explanation

- **Include Header and Namespace:**

    ```cpp
    #include <iostream>
    using namespace std;
    ```

    - This includes the `<iostream>` standard library for input and output operations (`cout`, `cin`). `using namespace std;` allows us to use `cout` and `cin` without prefixing `std::`.

- **Main Function:**

    ```cpp
    int main() {
        int N;
        cout << "Enter the value of N: ";
        cin >> N;
    ```

    - Defines the `main()` function, the entry point of the program. It declares an integer variable `N` to store the user input.

- **Input:**

    ```cpp
    cout << "Enter the value of N: ";
    cin >> N;
    ```

    - Prompts the user to enter a value for `N` and stores it in the variable `N`.

- **Initialization:**

    ```cpp
    int row = 1;
    ```

    - Initializes the variable `row` to 1. `row` will track the current row number in the output pattern.

- **Nested While Loop for Output:**

    ```cpp
    while (row <= N) {
        int col = 1;
        while (col <= row) {
            cout << "*" << " ";
            col++;
        }
        cout << endl;
        row++;
    }
    ```

    - **Outer Loop (`while (row <= N) { ... }`):**
        
        - Executes `N` times, once for each row, starting from 1 up to `N`.
        - `row` increments after each row is printed.

    - **Inner Loop (`while (col <= row) { ... }`):**

        - Executes `row` times for each row, starting from 1 up to the current value of `row`.
        - `col` increments after printing each asterisk.

    - **Printing:**
        
        - `cout << "*" << " ";` prints an asterisk followed by a space for each iteration of the inner loop.
        - After printing all asterisks for the current `row`, `cout << endl;` moves to the next line to start a new row.

- **Output:**

    - After executing the nested loops, the program prints a pattern of asterisks (`*`) where the number of asterisks in each row increases incrementally from 1 to `N`.

### Summary:

- The program takes an integer input `N` from the user.
- It then prints a right-angled triangle of asterisks with `N` rows.
- The number of asterisks in each row corresponds to the row number (1st row has 1 `*`, 2nd row has 2 `*`, and so on).
- The program uses nested `while` loops to achieve this output, with `row` controlling the number of rows and `col` controlling the number of asterisks per row.

This code snippet demonstrates basic control flow using loops and input/output operations in C++, generating a specific pattern of asterisks based on user input.
