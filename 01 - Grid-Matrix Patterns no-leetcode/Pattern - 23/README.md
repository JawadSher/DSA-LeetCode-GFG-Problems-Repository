# Problem Statement

Write a C++ program that prints a pattern of numbers and dashes based on the integer input \( N \). The pattern consists of:

1. **Dashes (`-`)**: Printed at the beginning and end of each row.
2. **Ascending Numbers**: Printed in ascending order from 1 up to the current row number.
3. **Descending Numbers**: Printed in descending order from the current row number minus 1 down to 1.

### Pattern Description:

- Each row starts with a number of dashes.
- After the dashes, numbers are printed in ascending order from 1 up to the current row number.
- Then, numbers are printed in descending order from the current row number minus 1 down to 1.
- Finally, the row ends with a number of dashes.


## Constraints

`1 ≤ N ≤ 1000`

### Input:

- An integer \( N \) (1 ≤ \( N \) ≤ 1000), which specifies the number of rows in the pattern.

### Output:

- Print a pattern with \( N \) rows as described above.

### Example:

**Input:**
```
3
```

**Output:**
```
- - 1 - - 
- 1 2 1 - 
1 1 2 1 1
```

**Explanation:**
- For \( N = 3 \):
  - **Row 1**: 2 dashes, followed by numbers from 1, and then 2 dashes.
  - **Row 2**: 1 dash, numbers from 1 to 2, descending from 2 to 1, followed by 1 dash.
  - **Row 3**: No dashes, numbers from 1 to 2, descending from 2 to 1, followed by no dashes.

**Input:**
```
4
```

**Output:**
```
- - - 1 - - - 
- - 1 2 1 - - 
- 1 1 2 1 1 - 
1 1 1 2 2 1 1
```

**Explanation:**
- For \( N = 4 \):
  - **Row 1**: 3 dashes, numbers from 1, and then 3 dashes.
  - **Row 2**: 2 dashes, numbers from 1 to 2, descending from 2 to 1, followed by 2 dashes.
  - **Row 3**: 1 dash, numbers from 1 to 2, descending from 2 to 1, followed by 1 dash.
  - **Row 4**: No dashes, numbers from 1 to 2, descending from 2 to 1, followed by no dashes.


## Problem Solution Explanation

- **Variable Declaration and Input:**

    ```cpp
    int N;
    cout << "Enter the value of N: ";
    cin >> N;
    ``` 
    
    - `N` is an integer variable that stores the user input, representing the number of rows in the pattern.

- **Outer While Loop (Rows):**

    ```cpp
    int row = 1;
    while (row <= N) { 
    ``` 
    
    - This loop iterates from `row = 1` to `row = N`, which corresponds to the number of rows in the pattern.

- **First Inner While Loop (Spaces and Dashes before Numbers):**

    ```cpp
    int space = 1;
    while (space < N - row + 1) {
        cout << "-" << " ";
        space++;
    }
    ``` 
    
    - `space` is initialized to 1 and represents the number of spaces to print before the numbers in each row.
    - This loop prints `N - row` dashes (`-`) followed by a space. The number of dashes decreases with each row.

- **Second Inner While Loop (Numbers in Ascending Order):**

    ```cpp
    int col = 1;
    while (col <= row) {
        cout << col << " ";
        col++;
    }
    ``` 
    
    - `col` is initialized to 1 and represents the column number within each row.
    - This loop prints numbers starting from 1 up to `row`.

- **Third Inner While Loop (Numbers in Descending Order):**

    ```cpp
    int col2 = 1;
    while (col2 < row) {
        cout << row - col2 << " ";
        col2++;
    }
    ``` 
    
    - `col2` is initialized to 1 and represents another loop variable.
    - This loop prints numbers in descending order from `row - 1` down to 1.

- **Fourth Inner While Loop (Spaces and Dashes after Numbers):**

    ```cpp
    int space2 = 1;
    while (space2 <= N - row + 1) {
        cout << "-" << " ";
        space2++;
    }
    ``` 
    
    - `space2` is initialized to 1 and represents the number of spaces to print after the numbers in each row.
    - This loop prints `N - row + 1` dashes (`-`) followed by a space, similar to the first loop but for the trailing spaces and dashes.

- **End of Row:**

    ```cpp
    cout << endl;
    row++;
    ``` 
    
    - After printing all the dashes, spaces, and numbers for the current row, a newline character (`endl`) is printed to move to the next line.
    - `row` is incremented to move to the next row.

- **Return Statement:**

    ```cpp
    return 0;
    ``` 
    
    - The `main` function returns 0, indicating successful execution of the program.

---

### Example Output

**Input:**
```
Enter the value of N: 4
```

**Output:**
```
- - - 1 - - - 
- - 1 2 1 - - 
- 1 1 2 1 1 - 
1 1 1 2 2 1 1
``` 

**Explanation:**
- For \( N = 4 \):
  - Row 1: Three dashes, numbers from 1, followed by three dashes.
  - Row 2: Two dashes, numbers from 1 to 2, descending from 2 to 1, followed by two dashes.
  - Row 3: One dash, numbers from 1 to 2, descending from 2 to 1, followed by one dash.
  - Row 4: No dashes, numbers from 1 to 2, descending from 2 to 1, followed by no dashes.

---

### Time and Space Complexity

**Time Complexity:** \( O(N^2) \)
- The outer loop runs \( N \) times.
- Each inner loop runs up to \( N \) times in total across all rows.
- Combining these, the total time complexity is quadratic.

**Space Complexity:** \( O(1) \)
- The program uses a fixed amount of space for variables (`N`, `row`, `space`, `col`, `col2`, `space2`).
- No additional data structures are used.

---

This explanation provides a comprehensive overview of the code, its functionality, and how the pattern is generated, including constraints and examples for better understanding. Let me know if you need any further adjustments!
