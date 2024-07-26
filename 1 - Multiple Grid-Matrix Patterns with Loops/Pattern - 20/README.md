# Problem Statement

Write a C++ program to generate and print a right-aligned pattern of numbers based on a user-defined number of rows NNN. Each row in the pattern consists of hyphens (`-`) followed by the row number repeated a certain number of times. The number of hyphens decreases while the number of repeated numbers increases with each successive row.

### Constraints

-   N (number of rows) is a positive integer.
-  ` 1 ≤ N ≤ 20`

## Example

**Input:**


`Enter the value of N: 5` 

**Output:**


```
- - - - 1 
- - - 2 2 
- - 3 3 3 
- 4 4 4 4 
5 5 5 5 5
```
## Problem Solution Explanation

This C++ program generates a right-aligned pattern based on the input value \( N \). The pattern consists of hyphens (`-`) and numbers, with the number of hyphens decreasing and the number of repeated numbers increasing with each row.

Here's a detailed breakdown of the code:

1. **Header Inclusion and Namespace:**
    ```cpp
    #include <iostream>
    using namespace std;
    ```
    - The `#include <iostream>` directive includes the standard input-output stream library.
    - `using namespace std;` allows the use of standard library names like `cout` and `cin` without needing to prefix them with `std::`.

2. **Main Function:**
    ```cpp
    int main() {
        int N;
        cout << "Enter the value of N : ";
        cin >> N;
    ```
    - `int N;` declares an integer variable `N` to store the number of rows for the pattern.
    - `cout << "Enter the value of N : ";` prompts the user for input.
    - `cin >> N;` reads the user's input and stores it in `N`.

3. **Outer While Loop (`row` loop):**
    ```cpp
    int row = 1;
    while (row <= N) {
    ```
    - Initializes `row` to 1.
    - The loop continues while `row` is less than or equal to `N`. Each iteration corresponds to a row of the pattern.

4. **Inner While Loop (Printing Spaces):**
    ```cpp
    int space = 1;
    while (space < N - row + 1) {
        cout << "-" << " ";
        space++;
    }
    ```
    - Initializes `space` to 1.
    - This loop prints hyphens (`-`) followed by a space. The number of hyphens printed is determined by `N - row + 1`, creating the right alignment of the pattern.

5. **Inner While Loop (Printing Numbers):**
    ```cpp
    int col = 1;
    while (col <= row) {
        cout << row << " ";
        col++;
    }
    ```
    - Initializes `col` to 1.
    - This loop prints the current row number (`row`) followed by a space. The number of times the row number is printed is equal to the current row number.

6. **Newline and Row Increment:**
    ```cpp
    cout << endl;
    row++;
    ```
    - After printing all characters for the current row, `cout << endl;` moves to the next line.
    - `row++` increments the `row` variable to process the next row.

7. **Program Termination:**
    ```cpp
    return 0;
    }
    ```
    - `return 0;` indicates that the program finished successfully.

### Time Complexity

- **Outer Loop (`while (row <= N)`):** Runs `N` times.
- **First Inner Loop (`while (space < N - row + 1)`):** The number of iterations decreases as `row` increases. On average, it runs about \( O(N) \) times for each row.
- **Second Inner Loop (`while (col <= row)`):** Runs `row` times for each row, where `row` ranges from 1 to `N`. On average, this loop runs \( O(N) \) times for each row.

Thus, the total time complexity is: O(N^2) 

### Space Complexity

- **Variables:** The program uses a constant amount of extra space for variables (`N`, `row`, `space`, `col`). 
- **No additional data structures** are used.

Therefore, the space complexity is: O(1)

### Summary

- **Time Complexity:** O(N^2) because both inner loops combined contribute to quadratic complexity.
- **Space Complexity:** O(1) due to the use of a fixed amount of extra space regardless of input size.
