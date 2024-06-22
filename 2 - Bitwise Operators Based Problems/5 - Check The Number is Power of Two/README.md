## Source Code Explanation

1.  **Header Inclusion:**
    
    -   `#include <iostream>`: This line includes the `iostream` header file, which provides functionalities for input/output operations like `cout` (console output) and `cin` (console input).
2.  **Namespace:**
    
    -   `using namespace std;`: This line brings the `std` namespace into scope, allowing you to use standard C++ objects like `cout`, `cin`, `string`, and `int` without having to prefix them with `std::`.
3.  **`power_of_two` Function:**
    
    -   `string power_of_two(int n)`: This line defines a function named `power_of_two` that takes an integer `n` as input and returns a string ("True" or "False") indicating whether `n` is a power of two.
        
        -   **Function Body:**
            -   `return n > 0 && (n & (n - 1)) == 0 ? "True" : "False";`: This line is the core logic of the function and uses a **ternary conditional operator** to determine the return value:
                -   `n > 0`: This checks if `n` is positive. A power of two cannot be negative or zero.
                -   `(n & (n - 1)) == 0`: This is the key part that efficiently checks if `n` is a power of two using a bitwise AND operation (`&`):
                    -   In binary representation, a power of two has only one set bit (1) and the rest are zeros. Subtracting 1 from a power of two flips the least significant set bit to 0, resulting in a binary number with all bits set to 0 except for the one that was previously set.
                    -   Performing a bitwise AND between `n` and `n - 1` will result in zero only if `n` was indeed a power of two (because all bits will be 0 after the AND operation).
                -   **Ternary Operator:** The entire conditional expression `n > 0 && (n & (n - 1)) == 0` is used in a ternary operator. If the condition is true (meaning `n` is a positive power of two), "True" is returned. Otherwise, "False" is returned.
4.  **`main` Function:**
    
    -   `int main()`: This is the main function where the program execution begins.
        
        -   **Function Body:**
            -   `int n;`: Declares an integer variable `n` to store the user input.
            -   `cout << "Enter a number: ";`: Prompts the user to enter a number.
            -   `cin >> n;`: Reads the user's input and stores it in `n`.
            -   `string output = power_of_two(n);`: Calls the `power_of_two` function with `n` as input and stores the returned string ("True" or "False") in the variable `output`.
            -   `cout << "Is the number a power of two: " << output << endl;`: Prints a message to the console indicating whether the entered number is a power of two, based on the value of `output`.
            -   `return 0;`: Indicates successful program termination.

**How the Code Works:**

1.  When you run the program, it first displays the prompt "Enter a number: ".
2.  You enter an integer number.
3.  The program passes that number to the `power_of_two` function.
4.  The function checks if the number is positive and if performing a bitwise AND between the number and the result of subtracting 1 from it yields zero.
5.  If both conditions are met, the number is a power of two, and the function returns "True". Otherwise, it returns "False".
6.  The main function receives the return value from the `power_of_two` function and prints a message indicating whether the entered number is a power of two.

## **Example:**

If you enter 16 (which is a power of two, specifically 2^4), the code will execute as follows:

1.  The number 16 is passed to the `power_of_two` function.
    
2.  The function checks:
    
    -   `n > 0`: Since 16 is positive, this condition is true.
    -   `(n & (n - 1)) == 0`:
        -   Binary representation of 16: 10000
        -   Subtracting 1: 10000 - 1 = 01111
        -   Bitwise AND of 16 and 15: 10000 & 01111 = 00000
        -   Since the result is zero, this condition is also true.
3.  Both conditions in the `power_of_two` function are true, so it returns "True".
    
4.  The `main` function receives "True" and prints the message: "Is the number a power of two: True".
    

**Key Takeaway:**

This code efficiently checks if a number is a power of two in its binary representation by leveraging bitwise operations. It demonstrates a concise way to solve this problem in C++.
