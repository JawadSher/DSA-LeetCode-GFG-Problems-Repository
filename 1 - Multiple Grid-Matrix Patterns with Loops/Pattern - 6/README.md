# Problem Statement

Write a C++ program that generates a specific pattern based on a user-provided integer `N`. The pattern should consist of `N` rows where each row contains sequentially increasing numbers starting from 1. The number of elements in each row should be equal to the row number.

### Requirements

1. **Input:**
   - An integer `N` representing the number of rows in the pattern. The value of `N` should be provided by the user.

2. **Output:**
   - Print `N` rows. Each row `i` should contain `i` sequential numbers starting from the last printed number plus 1, separated by spaces. Each row should be printed on a new line.

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
4 5 6 
7 8 9 10
```

**Explanation:**

- For `N = 4`, the output will be:
    - Row 1: `1` (Starting number is `1`)
    - Row 2: `2 3` (Starting number is `2`)
    - Row 3: `4 5 6` (Starting number is `4`)
    - Row 4: `7 8 9 10` (Starting number is `7`)

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
    int num = row;
    ```
    
    - Initializes two integer variables:
        - `row` is initialized to 1 and is used to track the current row number in the output pattern.
        - `num` is initialized to `row`. It will be used to print sequential numbers starting from the current row number.

- **Nested While Loop for Output**:
    
    ```cpp
    while (row <= N) {
        int col = 1;
        while (col <= row) {
            cout << num << " ";
            col++;
            num++;
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
        - `col` increments after printing each number (`num`).
    
    - **Printing**:
        - `cout << num << " ";` prints the current value of `num` followed by a space for each iteration of the inner loop.
        - After printing all numbers for the current `row`, `cout << endl;` moves to the next line to start a new row.

- **Output**:
    
    - After the execution of the nested loops, the program prints a pattern of numbers where each row `i` contains `i` sequential numbers starting from the last printed number plus 1.
    - For example, the first row prints `1`, the second row prints `2 3`, the third row prints `4 5 6`, and so on up to `N`.

### Summary

- This program takes an integer input `N` from the user.
- It then prints `N` rows where each row `i` contains `i` sequential numbers starting from the last printed number plus 1.
- The program uses nested while loops to achieve this output, with `row` controlling the number of rows, `col` controlling the number of numbers per row, and `num` keeping track of the sequence of numbers printed.

This code snippet demonstrates basic control flow using loops and input/output operations in C++, and it showcases how to generate a specific pattern of numbers based on user input.

---
