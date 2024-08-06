# Problem Statement

Write a C++ program that generates a specific pattern based on the integer input \( N \). The pattern consists of numbers and asterisks arranged in a symmetrical format. Each row of the pattern includes:

1. **Numbers in Ascending Order:** Starting from 1 up to (N - row + 1).
2. **Asterisks (`*`):** The number of asterisks is \( 2 * row - 1).
3. **Numbers in Descending Order:** Starting from  N - row + 1 down to 1.

### Input

- An integerN (1 ≤ 𝑁 ≤ 1000), which specifies the number of rows in the pattern.

### Output

- Print the pattern with 𝑁 rows as described.

### Constraints

- The integer 𝑁 must be between 1 and 1000, inclusive.

### Example

**Input:**
```
5
```

**Output:**
```
1 2 3 4 5 * 5 4 3 2 1
1 2 3 4 * * * 4 3 2 1
1 2 3 * * * * * 3 2 1
1 2 * * * * * * * 2 1
1 * * * * * * * * * 1
```

**Explanation:**

- **For \( N = 5 \):**
  - **Row 1:** Numbers from 1 to 5, then 1 asterisk, then numbers from 5 to 1.
  - **Row 2:** Numbers from 1 to 4, then 3 asterisks, then numbers from 4 to 1.
  - **Row 3:** Numbers from 1 to 3, then 5 asterisks, then numbers from 3 to 1.
  - **Row 4:** Numbers from 1 to 2, then 7 asterisks, then numbers from 2 to 1.
  - **Row 5:** Number 1, then 9 asterisks, then number 1.

## Problem Solution Explanation

- **Variable Declaration and User Input:**

    ```
    int N;
    cout << "Enter the value of N: ";
    cin >> N;
    ``` 

    - The program declares an integer variable `N`.
    - It prompts the user to enter the value of `N` and stores the input in the variable `N`.

- **Outer While Loop:**

    ```
    int row = 1;
    while (row <= N) {
    ```

    - This loop iterates over each row from 1 to `N`.

- **First Inner While Loop (Print Numbers in Ascending Order):**

    ```
    int col = 1;
    while (col <= N - row + 1) {
      cout << col << " ";
      col++;
    }
    ```

    - This loop prints numbers starting from 1 up to `N - row + 1`.
    - For example, if `N` is 5 and `row` is 1, it prints numbers from 1 to 5. If `row` is 2, it prints numbers from 1 to 4, and so on.

- **Second Inner While Loop (Print Asterisks):**

    ```
    int space = 2 * row - 1;
    while (space > 1) {
      cout << "*" << " ";
      space--;
    }
    ```

    - This loop prints asterisks. The number of asterisks to print is given by `2 * row - 1`.
    - This ensures that the number of asterisks increases with each row.
    - For example, if `row` is 1, it prints 1 asterisk. If `row` is 2, it prints 3 asterisks, and so on.

- **Third Inner While Loop (Print Numbers in Descending Order):**

    ```
    int col2 = N - row + 1;
    while (col2 >= 1) {
      cout << col2 << " ";
      col2--;
    }
    ```

    - This loop prints numbers in descending order from `N - row + 1` down to 1.
    - For example, if `N` is 5 and `row` is 1, it prints numbers from 5 down to 1. If `row` is 2, it prints numbers from 4 down to 1, and so on.

- **End of Row:**

    ```
    cout << endl;
    row++;
    ```

    - After finishing the current row, it moves to the next line and increments the `row` variable to proceed to the next row.

- **End of Program:**

    ```
    return 0;
    ```

    - The program ends after all rows are printed.


## Example Output

```
Enter the value of N : 5
```

  ```
  1 2 3 4 5 * 5 4 3 2 1
  1 2 3 4 * * * 4 3 2 1
  1 2 3 * * * * * 3 2 1
  1 2 * * * * * * * 2 1
  1 * * * * * * * * * 1
  ``` 

### Breakdown of Output Pattern :

-   **Row 1:** Numbers from 1 to 5, then 1 asterisk, then numbers from 5 to 1.
-   **Row 2:** Numbers from 1 to 4, then 3 asterisks, then numbers from 4 to 1.
-   **Row 3:** Numbers from 1 to 3, then 5 asterisks, then numbers from 3 to 1.
-   **Row 4:** Numbers from 1 to 2, then 7 asterisks, then numbers from 2 to 1.
-   **Row 5:** Number 1, then 9 asterisks, then number 1.

This pattern continues as described, forming a symmetrical pattern of numbers and asterisks.
