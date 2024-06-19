This C++ program prints a pattern using asterisks (*) and hyphens (-) based on user input N. Let's break down the program step by step.

## Source Code Explanation

-  **User Input:**
    
    -   The program prompts the user to enter a value for `N`. This value determines the number of rows in the pattern.
- **Outer `while` Loop (`row` loop):**
    
    -   `row` variable starts from 1 and increments up to `N`.
    -   Each iteration of the outer loop corresponds to one row of output.
- **First Inner `while` Loop (`col` loop):**
    
    -   Inside the `row` loop, there is an inner `col` loop that starts from 1 and runs up to `N - row + 1`.
    -   This loop prints `*` followed by a space for each iteration, controlling the number of asterisks printed per row.
-  **Second Inner `while` Loop (`space` loop):**
    
    -   After printing the asterisks, there is another inner loop (`space` loop) that runs from 1 to `row - 1`.
    -   This loop prints `-` followed by a space for each iteration, controlling the number of hyphens printed per row after the asterisks.
-  **Printing Newline (`endl`):**
    
    -   After completing the inner loops for each row, a newline (`endl`) is used to move to the next line, starting a new row.
-  **Incrementing `row`:**
    
    -   After completing the current row, `row` is incremented by 1 to move to the next row in the pattern.
- **Termination:**
    
    -   Once all rows have been processed (`row` exceeds `N`), the program exits with `return 0;`.

## Example Output:

If the user enters `N = 5`, the program will output:

```
Enter the value of N : 5
* * * * * 
* * * * - 
* * * - - 
* * - - - 
* - - - -
``` 

-   In the first row (`row = 1`), there are 5 asterisks (`*`).
-   In subsequent rows, the number of asterisks decreases by 1 each row, and hyphens (`-`) are added after the asterisks.

### Notes:

-   The program assumes valid input for `N` (positive integer).
-   It demonstrates nested loops and conditional printing based on the current row number.
-   This pattern generation approach is commonly used in beginner programming exercises to practice nested loops and pattern printing.
