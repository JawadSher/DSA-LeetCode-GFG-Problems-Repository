# Problem Statement

**Task:** Write a C++ program to generate a specific pattern based on a user-provided integer \( N \). 

The pattern consists of:
1. **Dashes (`-`)** followed by **Numbers**.
2. Each row starts with a decreasing number of dashes followed by an increasing sequence of numbers.

**Input:** 
- An integer \( N \) (1 ≤ \( N \) ≤ 1000), which determines the number of rows in the pattern.

**Output:** 
- A pattern where each row starts with dashes (`-`) and is followed by numbers that increment from a starting value.

### Constraints

`1 ≤ N ≤ 1000`

### Example

**Input:**
```
Enter the value of N: 4
```

**Output:**
```
- - - 1 
- - 2 3 
- 4 5 6 
7 8 9 10
``` 

**Explanation:**
- For \( N = 4 \):
  - Row 1: Three dashes, numbers from 1.
  - Row 2: Two dashes, numbers from 2 to 3.
  - Row 3: One dash, numbers from 4 to 6.
  - Row 4: No dashes, numbers from 7 to 10.

## Problem Solution Explanation 

- **Variable Declaration and Input:**

    ```cpp
    int N;
    cout << "Enter the value of N: ";
    cin >> N;
    ``` 
    
    -   `N` is an integer variable that stores the user input, representing the number of rows in the pattern.

- **Initialization:**

    ```cpp
    int row = 1;
    int num = 1;
    ``` 
    
    -   `row` is initialized to 1. It represents the current row number.
    -   `num` is initialized to 1. It represents the starting number to be printed in each row and increments as numbers are printed.

- **Outer While Loop (Rows):**

    ```cpp
    while (row <= N) { 
    ``` 
    
    -   This loop iterates from `row = 1` to `row = N`, which corresponds to the number of rows in the pattern.

- **First Inner While Loop (Spaces):**

    ```cpp
    int space = 1;
    while (space < N - row + 1) {
        cout << "-" << " ";
        space++;
    }
    ``` 
    
    -   `space` is initialized to 1 and represents the number of spaces to print before the numbers in each row.
    -   This loop prints `N - row` spaces followed by a space after each dash (`-`).

- **Second Inner While Loop (Numbers):**

    ```cpp
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

- **End of Row:**

    ```cpp
    cout << endl;
    row++;
    ``` 
    
    -   After printing all the dashes and numbers for the current row, a newline character (`endl`) is printed to move to the next line.
    -   `row` is incremented to move to the next row.

- **Return Statement:**

    ```cpp
    return 0;
    ``` 
    
    -   The `main` function returns 0, indicating successful execution of the program.

---

## Example Output

**Example 1:**

**Input:**
```
Enter the value of N: 3
```

**Output:**
```
- - 1 
- 2 3 
4 5 6
``` 

**Explanation:** 
- For \( N = 3 \):
  - Row 1: Two dashes, numbers from 1.
  - Row 2: One dash, numbers from 2 to 3.
  - Row 3: No dashes, numbers from 4 to 6.



---

### Time and Space Complexity

**Time Complexity:** O(N^2)
- The outer loop runs \( N \) times.
- The first inner loop runs up to `N - row` times.
- The second inner loop runs up to `row` times.
- Combining these, the total time complexity is quadratic.

**Space Complexity:** O(1)
- The program uses a fixed amount of space for variables (`N`, `row`, `space`, `col`, `num`).
- No additional data structures are used.

