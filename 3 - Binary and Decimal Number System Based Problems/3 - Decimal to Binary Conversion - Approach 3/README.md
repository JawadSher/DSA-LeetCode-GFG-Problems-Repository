## Source Code Explanation
1.  **Function Definition (`decimal_to_binary`):**
    
    -   The  `decimal_to_binary`  function converts a decimal number to its binary representation.
    -   It takes an integer  `n`  as an argument.
    -   The function starts by checking if  `n`  is equal to 0. If it is, it returns -1 (which seems to be an error condition).
    -   Otherwise, it proceeds with the binary conversion.
2.  **Binary Conversion Process:**
    
    -   Inside the function, an array called  `binary`  is created to store the binary digits.
    -   An  `index`  variable is initialized to 0. This variable keeps track of the position in the  `binary`  array.
    -   The core of the conversion happens in a  `while`  loop:
        -   As long as  `n`  is not zero, the loop continues.
        -   Inside the loop:
            -   The remainder of  `n`  divided by 2 (i.e.,  `n % 2`) is calculated.
            -   This remainder (either 0 or 1) represents the next binary digit.
            -   The current binary digit is stored in the  `binary`  array at the current  `index`.
            -   `n`  is updated by dividing it by 2 (i.e.,  `n = n / 2`).
            -   The  `index`  is incremented to move to the next position in the  `binary`  array.
    -   After the loop, the  `binary`  array contains the binary representation of the original decimal number.
3.  **Printing the Binary Representation:**
    
    -   Finally, another loop (a  `for`  loop) is used to print the binary digits.
    -   It starts from the highest index (i.e.,  `index - 1`) and goes down to 0.
    -   Each binary digit is printed, resulting in the complete binary representation of the original decimal number.
4.  **Example with 10000:**
    
    -   In your specific example, the  `main()`  function sets  `decimal`  to 10000.
    -   Calling  `decimal_to_binary(decimal)`  results in printing the binary representation of 10000.
