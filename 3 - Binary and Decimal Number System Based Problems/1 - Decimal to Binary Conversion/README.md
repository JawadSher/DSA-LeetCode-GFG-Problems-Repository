## Source Code Explanation

1.  **Header Inclusions:**
    
    -   `<iostream>`: Provides input/output functionality (e.g.,  `cout`).
    -   `<math.h>` (or `<cmath>` in C++11): Provides mathematical functions (e.g.,  `pow`).
2.  **`decimal_to_binary` Function:**
    
    -   **Parameters:**
        -   `n`: The decimal number to be converted.
    -   **Local Variables:**
        -   `binary`: Stores the binary equivalent of `n` (initialized to 0).
        -   `i`: Keeps track of the position of the current bit in the binary number (initialized to 0).
    -   **Loop:**
        -   The `while (n)` loop continues as long as `n` (the decimal number) is not zero. This ensures all bits are processed.
        -   Inside the loop:
            -   `bit = n & 1`: Extracts the least significant bit (LSB) of `n` using the bitwise AND operator (`&`). Numbers with an LSB of 1 are odd, while those with an LSB of 0 are even.
            -   **Incorrect Calculation:** The current line `binary = (bit * pow(10, i)) + binary;` attempts to add the extracted bit (`bit`) to the binary representation by multiplying it with the power of 10 (`pow(10, i)`) based on its position (`i`). However, binary numbers use base 2, not base 10. This line needs to be corrected to use base 2 for accurate conversion.
            -   `n = n >> 1`: Right shifts `n` by 1 bit. This effectively removes the processed LSB from `n`, preparing it for the next iteration.
            -   `i = i + 1`: Increments the position counter (`i`) to account for the next bit to be processed.
    -   **Return:** The function returns the final binary equivalent stored in `binary`.
3.  **`main` Function:**
    
    -   **Variable Declaration:**
        -   `decimal`: Stores the decimal number to be converted (initialized to 10000 in this example).
    -   **Function Call:**
        -   `output = decimal_to_binary(decimal)`: Calls the `decimal_to_binary` function, passing `decimal` as the argument, and stores the returned binary value in `output`.
    -   **Output:**
        -   `cout << "Binary of " << decimal << " is : " << output;`: Prints the message indicating the binary representation of `decimal` along with the calculated binary value (`output`).

## **Correction:**

To accurately convert decimal to binary, the calculation in the `decimal_to_binary` function should use base 2 instead of base 10. Here's the corrected line:

```
binary = (bit << i) + binary; // Use left shift (<<) and base 2

```
This line left-shifts the extracted bit (`bit`) by `i` positions (based on its significance) and adds it to the `binary` representation.

With this correction, the code will correctly perform decimal-to-binary conversion. 

- **Note** 
  - The current source code is just reliable for converting decimal to binary binary under 1000 range of decimal. Explore another one in his parent repo of this repo.
