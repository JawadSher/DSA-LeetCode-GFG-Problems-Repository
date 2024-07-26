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

-  **Header Inclusion (`#include <iostream>`)**
    
    -   The code starts by including the `<iostream>` header file. This header file provides input/output functionalities like `cout` for printing to the console and `cin` for reading input from the console.
-  **Namespace (`using namespace std;`)**
    
    -   The `using namespace std;` statement brings the standard C++ namespace `std` into scope. This allows us to use standard C++ objects like `cout`,  `cin`, and `endl` without having to prefix them with `std::`.
-  **Main Function (`int main()`)**
    
    -   The `main` function is the entry point of the program. The code execution begins here.
-  **Inputting N (`cout << "Enter the value of N: "; cin >> N;`)**
    
    -   The code prompts the user to enter a value for `N` using `cout`.
    -   The user's input is then stored in the variable `N` using `cin`.
-  **Outer Loop (`while (row <= N)`)**
    
    -   The outer loop iterates from `row = 1` to `row <= N`. It controls the number of rows printed in the pattern.
-  **Inner Loop (Printing Spaces) (`while (space < N - row + 1)`)**
    
    -   The inner loop iterates from `space = 1` to `space < N - row + 1`. It is used to print the leading hyphens in each row.
    -   In each iteration, the code prints a hyphen (`-`) followed by a space using `cout << "-" << " ";`.
    -   The number of spaces printed is determined by the condition `space < N - row + 1`. This ensures that there are enough spaces to form a right triangle of hyphens.
-  **Inner Loop (Printing Numbers) (`while (col <= row)`)**
    
    -   The inner loop iterates from `col = 1` to `col <= row`. It is used to print the numbers in each row.
    -   In each iteration, the code prints the current value of `row` followed by a space using `cout << row << " ";`.
    -   The number of times the number is printed is determined by the condition `col <= row`. This ensures that the number is printed `row` times in each row.
- **Printing Newline (`cout << endl;`)**
    
    -   After each row is printed, the code moves the cursor to the next line using `cout << endl;`.
- **Incrementing Row Counter (`row++`)**
    
    -   The `row` variable is incremented after each iteration of the outer loop. This ensures that the next row is printed in the subsequent iteration.
-  **Returning 0 (`return 0;`)**
    

-   The `main` function returns 0 to indicate successful program execution.

## Example Output (Input: N = 5)

When the user enters `5` for `N`, the code will print the following pattern:

```
- - - - 1 
- - - 2 2 
- - 3 3 3 
- 4 4 4 4 
5 5 5 5 5 

```
I hope this explanation is helpful!
