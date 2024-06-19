## Source Code Explanation

- **Variable Declaration and Input:**
    
    
    ```
    int N;
    cout << "Enter the value of N: ";
    cin >> N;
    ``` 
    
    -   `N` is an integer variable that stores the user input, which represents the number of rows in the pattern.
-  **Initialization:**
    
    
    ```int row = 1;```
    
    ```int num = 1;``` 
    
    -   `row` is initialized to 1. It represents the current row number.
    -   `num` is initialized to 1. It represents the starting number to be printed in each row and increments as numbers are printed.
-  **Outer While Loop (Rows):**
    
    
    `while (row <= N) {` 
    
    -   This loop iterates from `row = 1` to `row = N`, which corresponds to the number of rows in the pattern.
-  **First Inner While Loop (Spaces):**
    
    ```int space = 1;
    while (space < N-row+1) {
      cout << "-" << " ";
      space++;
    }
    ``` 
    
    -   `space` is initialized to 1 and represents the number of spaces to print before the numbers in each row.
    -   This loop prints `N - row` spaces followed by a space after each dash (`-`).
-  **Second Inner While Loop (Numbers):**
    
    ```
    int col = 1;
    while (col <= row) {
      cout << num << " ";
      col++;
      num++;
    }
    ``` 
    
    -   `col` is initialized to 1 and represents the column number within each row.
    -   This loop prints `row` numbers starting from `num`.
    -   `num` is incremented after each number is printed to ensure the next number is printed in sequence.
-  **End of Row:**
    
    
    ```cout << endl;```
    
    ```row++;``` 
    
    -   After printing all the dashes and numbers for the current row, a newline character (`endl`) is printed to move to the next line.
    -   `row` is incremented to move to the next row.
-  **Return Statement:**
    
    
    `return 0;` 
    
    -   The `main` function returns 0, indicating successful execution of the program.

## Example Output

Let's see what the output looks like for different values of `N`.

### Example 1: N = 3

```
Enter the value of N: 3
- - 1 
- 2 3 
4 5 6
``` 

### Example 2: N = 4

```
Enter the value of N: 4
- - - 1 
- - 2 3 
- 4 5 6 
7 8 9 10
``` 

### Summary

-   The outer loop (`while (row <= N)`) controls the number of rows to be printed based on user input `N`.
-   The first inner loop (`while (space < N-row+1)`) prints dashes (`-`) with spaces before printing numbers.
-   The second inner loop (`while (col <= row)`) prints numbers starting from `num` and increments `num` after each print.
-   The pattern printed consists of rows where each row starts with a decreasing number of dashes (`-`) followed by a sequence of incrementing numbers.
