# Problem Statement

**Task:** Write a C++ program to generate a specific pattern based on a user-provided integer \( N \). 

The pattern consists of two parts:
1. **Dashes (`-`)** followed by **Numbers**.
2. Each row starts with a decreasing number of dashes followed by increasing numbers from the current row number.

**Input:** 
- An integer \( N \) (1 ≤ \( N \) ≤ 1000), which determines the number of rows in the pattern.

**Output:** 
- A pattern where each row starts with dashes (`-`) and is followed by numbers that increment from the current row number.

### Constraints

`1 ≤ 𝑁 ≤ 1000 `

### Example

**Input:**
```
Enter the value of N: 4
```

**Output:**
```
1 2 3 4 
- 2 3 4 
- - 3 4 
- - - 4
``` 

**Explanation:**
- For \( N = 4 \):
  - Row 1: No dashes, numbers from 1 to 4.
  - Row 2: One dash, numbers from 2 to 4.
  - Row 3: Two dashes, numbers from 3 to 4.
  - Row 4: Three dashes, only the number 4.

## Problem Solution Explanation 

-  **Variable Declaration and Input:**
    
    ```cpp
    int N;
    cout << "Enter the value of N: ";
    cin >> N;
    ``` 
    
    -   An integer variable `N` is declared.
    -   The program prompts the user to enter a value for `N` and stores it in the variable `N`.

-  **Outer While Loop (Rows):**
    
    ```cpp
    int row = 1;
    while (row <= N) { 
    ``` 
    
    -   `row` is initialized to 1.
    -   This loop will iterate from `row = 1` to `row = N`. Each iteration corresponds to a row in the output pattern.

-  **First Inner While Loop (Spaces):**
    
    ```cpp
    int space = 1;
    while (space < row) {
        cout << "-" << " ";
        space++;
    }
    ``` 
    
    -   `space` is initialized to 1.
    -   This loop prints a dash (`-`) followed by a space. It runs `row - 1` times, so the number of dashes printed increases with each row.
    -   For example, when `row = 1`, it prints 0 dashes; when `row = 2`, it prints 1 dash; when `row = 3`, it prints 2 dashes, and so on.

- **Second Inner While Loop (Numbers):**
    
    ```cpp
    int col = 1;
    int num = row;
    while (col <= N - row + 1) {
        cout << num << " ";
        col++;
        num++;
    }
    ``` 
    
    -   `col` is initialized to 1, and `num` is initialized to the current `row` value.
    -   This loop prints numbers starting from `num` and increments `num` in each iteration.
    -   The loop runs `N - row + 1` times, so the number of numbers printed decreases with each row.
    -   For example, when `row = 1` and `N = 4`, it prints 4 numbers starting from 1; when `row = 2`, it prints 3 numbers starting from 2; when `row = 3`, it prints 2 numbers starting from 3, and so on.

- **End of Row:**
    
    ```cpp
    cout << endl;
    row++;
    ``` 
    
    -   After printing the dashes and numbers for the current row, a newline character is printed to move to the next line.
    -   `row` is incremented to process the next row.

-  **Return Statement:**
    
    ```cpp
    return 0;
    ``` 
    
    -   The `main` function returns 0, indicating successful execution of the program.

---

### Example Output

**Input:**
```
Enter the value of N: 3
```

**Output:**
```
1 2 3 
- 2 3 
- - 3
``` 

**Explanation:** 
- For \( N = 3 \):
  - Row 1: No dashes, numbers from 1 to 3.
  - Row 2: One dash, numbers from 2 to 3.
  - Row 3: Two dashes, only the number 3.



### Time and Space Complexity

**Time Complexity:**  O(N^2)
- The outer loop runs ( N ) times.
- The first inner loop runs up to ( row - 1 ) times.
- The second inner loop runs ( N - row + 1 ) times.
- Combining these, the total time complexity is quadratic.

**Space Complexity:**  O(1)
- The program uses a fixed amount of space for variables (`N`, `row`, `space`, `col`, `num`).
- No additional data structures are used.

---

This comprehensive explanation includes the problem statement, constraints, examples, and a detailed breakdown of the code along with its time and space complexity. If you have more questions or need further assistance, just let me know!
