# Problem Statement

Write a C++ program that prints a pattern of asterisks (`*`) and hyphens (`-`) based on user input `N`. The pattern should consist of `N` rows. In each row, the number of asterisks decreases from the previous row, and the number of hyphens increases. 

### Constraints

- `N` should be a positive integer.
- `1 ≤ N ≤ 20`
## Example Outputs

### Example 1: `N = 3`

If the user inputs `3`, the output will be:

```
* * * 
* * - 
* - -
``` 

**Explanation:**

-   The first row contains 3 asterisks (`*`).
-   The second row contains 2 asterisks and 1 hyphen (`-`).
-   The third row contains 1 asterisk and 2 hyphens.

### Example 2: `N = 4`

If the user inputs `4`, the output will be:

```
* * * * 
* * * - 
* * - - 
* - - -
``` 

**Explanation:**

-   The first row contains 4 asterisks.
-   The second row contains 3 asterisks and 1 hyphen.
-   The third row contains 2 asterisks and 2 hyphens.
-   The fourth row contains 1 asterisk and 3 hyphens.
## Problem Solution Explanation

- **User Input:**
  - The program prompts the user to enter a value for `N`. This value determines the number of rows in the pattern.

- **Outer `while` Loop (`row` loop):**
  - Initializes the `row` variable to start from 1 and increments up to `N`.
  - Each iteration of the outer loop corresponds to one row of output.

- **First Inner `while` Loop (`col` loop):**
  - Inside the `row` loop, initializes the `col` variable to 1 and runs up to `N - row + 1`.
  - This loop prints `*` followed by a space for each iteration, controlling the number of asterisks printed in the current row.

- **Second Inner `while` Loop (`space` loop):**
  - After printing the asterisks, initializes the `space` variable to 1 and runs up to `row - 1`.
  - This loop prints `-` followed by a space for each iteration, controlling the number of hyphens printed after the asterisks in the current row.

- **Printing Newline (`endl`):**
  - After completing the inner loops for each row, a newline (`endl`) is used to move to the next line, starting a new row.

- **Incrementing `row`:**
  - After completing the current row, increments the `row` variable by 1 to move to the next row.

- **Termination:**
  - Once all rows have been processed (i.e., `row` exceeds `N`), the program terminates successfully with `return 0;`.

## Example Output

For `N = 5`, the output will be:

```
* * * * * 
* * * * - 
* * * - - 
* * - - - 
* - - - -
```

### Notes

- The program assumes valid input for `N` (positive integer).
- It demonstrates the use of nested loops to create patterns and basic control structures in C++.
- This pattern generation approach is commonly used in beginner programming exercises to practice nested loops and pattern printing.

---
