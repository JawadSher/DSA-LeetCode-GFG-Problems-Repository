## Source Code Explanation
1.  **Header Inclusions:**
    
    -   `<iostream>`: Included for input/output operations (like `cout` for printing).
    -   `<string>`: Included for working with strings (used to store the binary result).
2.  **`decimal_to_binary` Function:**
    
    -   **Parameters:**
        -   `n`: An integer representing the decimal number to be converted.
    -   **Return Type:**
        -   `string`: The function returns a string containing the binary representation of `n`.
    -   **Local Variables:**
        -   `binary`: An empty string (`""`) to store the binary digits as the function progresses.
    -   **Loop:**
        -   The `while(n)` loop continues as long as `n` (the decimal number) is not zero. This ensures all bits are processed.
        -   Inside the loop:
            -   `int bit = n & 1`: Extracts the least significant bit (LSB) of `n` using the bitwise AND operator (`&`). Numbers with an LSB of 1 are odd, while those with an LSB of 0 are even.
            -   `binary = to_string(bit) + binary`: Converts the extracted bit (`bit`) to a string using `to_string` and prepends it to the beginning of the `binary` string. This effectively builds the binary representation from LSB to MSB (most significant bit).
            -   `n = n >> 1`: Right shifts `n` by 1 bit. This removes the processed LSB from `n`, preparing it for the next iteration.
    -   **Return:** The function returns the final binary string stored in `binary`.
3.  **`main` Function:**
    
    -   **Variable Declaration:**
        -   `decimal`: An integer variable to store the decimal number to be converted (initialized to 10000 in this example).
    -   **Function Call:**
        -   `string output = decimal_to_binary(decimal)`: Calls the `decimal_to_binary` function, passing `decimal` as the argument, and stores the returned binary string in `output`.
    -   **Output:**
        -   `cout << "Binary of " << decimal << " is : " << output << endl;`: Prints a message indicating the binary representation of `decimal` along with the calculated binary value (`output`).

## Example Output

When you run this code with `decimal = 10000`, the following output will be produced:

```
Binary of 10000 is : 1010000000

```

This is the correct binary representation of 10000 (16 in decimal).

**Key Points:**

-   The code efficiently builds the binary representation by prepending each extracted bit to the beginning of the string.
-   The `to_string` function is used to convert the integer bit value (0 or 1) to a string character.
