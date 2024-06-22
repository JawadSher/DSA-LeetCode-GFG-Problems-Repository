## Source Code Explanation
1.  **Function Definition (`reverser`):**
    
    -   The  `reverser`  function takes an integer  `num`  as its argument.
    -   Its purpose is to reverse the digits of the input number.
    -   Inside the function, an integer variable called  `reverse_num`  is initialized to 0. This variable will store the reversed number.
2.  **Reversing the Digits:**
    
    -   The core of the reversal process happens in a  `while`  loop:
        -   As long as  `num`  is not zero, the loop continues.
        -   Inside the loop:
            -   The remainder of  `num`  divided by 10 (i.e.,  `num % 10`) gives the last digit of the number.
            -   This last digit is stored in the  `digit`  variable.
            -   The  `reverse_num`  is updated by multiplying it by 10 and adding the  `digit`. This effectively shifts the existing digits to the left and adds the new digit to the right.
            -   `num`  is updated by dividing it by 10 (i.e.,  `num = num / 10`), effectively removing the last digit.
        -   The loop repeats until all digits have been processed.
3.  **Example with 123456:**
    
    -   In your specific example, the  `main()`  function sets  `num`  to 123456.
    -   It prints the original value of  `num`  (i.e., “Before Reverse : 123456”).
    -   Then, it calls the  `reverser`  function with  `num`  as the argument.
    -   The reversed value is stored in  `r_value`.
    -   Finally, it prints the reversed value (i.e., “After Reverse : 654321”).
4.  **Output:**
    
    -   The output of this program will be:
        
        ```
        Before Reverse : 123456
        After Reverse : 654321
        ```
