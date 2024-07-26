# Problem Statement

Create a C++ program that generates a pattern of numbers based on a user-provided integer `N`. The pattern should consist of `N` rows, where each row `i` contains the number `i` repeated `i` times. Each number should be followed by a space, and each row should start on a new line.

**Requirements:**

1. **Input:**
   - An integer `N` which specifies the number of rows in the pattern.

2. **Output:**
   - A pattern with `N` rows.
   - The first row should contain the number `1` repeated once.
   - The second row should contain the number `2` repeated twice.
   - The third row should contain the number `3` repeated three times, and so on.
   - Each number should be followed by a space.
   - Each row should end with a newline character.

**Constraints:**

- The value of `N` must be a positive integer.
- The maximum value of `N` should be within practical limits, e.g., up to `100`.

**Example 1:**

**Input:**
```
4
```

**Output:**
```
1 
2 2 
3 3 3 
4 4 4 4
```

**Explanation:**
- For `N = 4`, the program should print 4 rows. The first row has one `1`, the second row has two `2`s, the third row has three `3`s, and the fourth row has four `4`s.

**Example 2:**

**Input:**
```
3
```

**Output:**
```
1 
2 2 
3 3 3 
```

**Explanation:**
- For `N = 3`, the program should print 3 rows. The first row has one `1`, the second row has two `2`s, and the third row has three `3`s.

**Example 3:**

**Input:**
```
5
```

**Output:**
```
1 
2 2 
3 3 3 
4 4 4 4 
5 5 5 5 5 
```

**Explanation:**
- For `N = 5`, the program should print 5 rows. The first row has one `1`, the second row has two `2`s, the third row has three `3`s, the fourth row has four `4`s, and the fifth row has five `5`s.

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

    - Defines the `main()` function, the entry point of the program. It declares an integer variable `N` to store user input.

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
            cout << row << " ";
            col = col + 1;
        }
        cout << endl;
        row = row + 1;
    }
    ```

    - **Outer Loop (`while (row <= N) { ... }`):**
        
        - Executes `N` times, once for each row, starting from 1 up to `N`.
        - `row` increments after each row is printed.

    - **Inner Loop (`while (col <= row) { ... }`):**

        - Executes `row` times for each row, starting from 1 up to the current value of `row`.
        - `col` increments after printing each number (`row`).

    - **Printing:**
        
        - `cout << row << " ";` prints the current value of `row` followed by a space for each iteration of the inner loop.
        - After printing all numbers for the current `row`, `cout << endl;` moves to the next line to start a new row.

- **Output:**

    - After executing the nested loops, the program prints a pattern where each row `i` contains the number `i` repeated `i` times.

### Summary:

- The program takes an integer input `N` from the user.
- It then prints `N` rows where each row `i` contains `i` copies of the number `i`.
- The program uses nested `while` loops to achieve this output, with `row` controlling the number of rows and `col` controlling the number of times each number (`row`) is printed per row.

This code snippet demonstrates basic control flow using loops and input/output operations in C++, showcasing how to generate a specific numerical pattern based on user input.
