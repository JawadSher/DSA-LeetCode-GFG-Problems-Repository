## Source Code Explanation

### Includes and Namespace

```#include <iostream>```

```using namespace std;``` 

-   `#include <iostream>`: Includes the Input/Output Stream library for using `cin` and `cout`.
-   `using namespace std;`: Allows using the standard namespace to avoid having to prefix `std::` before standard functions and objects.

### Function Definition

#### Approach One (Commented Out)
```
// Approach One 
// int function(int n){
//     int count = 0;
//     while(n){
//         if (n & 1){
//             count++;
//         }
//         n = n >> 1;
//     }
//     return count;
// }
``` 

This approach counts the number of `1s` by checking each bit:

1.  Initialize `count` to 0.
2.  While `n` is not zero:
    -   Check if the least significant bit (`n & 1`) is `1`. If so, increment `count`.
    -   Right shift `n` by 1 bit (`n = n >> 1`), effectively dividing `n` by 2 and discarding the least significant bit.
3.  Return the `count`.

#### Approach Two (Implemented)
```
int function(int n){
    int count = 0;
    while(n){
        count += n & 1;
        n = n >> 1;
    }
    return count;
}
``` 

This approach is similar but slightly more concise:

1.  Initialize `count` to 0.
2.  While `n` is not zero:
    -   Add the result of `n & 1` to `count`. This effectively adds 1 to `count` if the least significant bit is `1`, otherwise adds 0.
    -   Right shift `n` by 1 bit (`n = n >> 1`).
3.  Return the `count`.

Both approaches correctly count the number of `1s` in the binary representation of `n`.

### Main Function
```
int main() {
    int number;
    cin >> number;
    int output = function(number);
    cout << "The no of 1s in " << number << " in Binary : " << output << endl;

    return 0;
}
``` 

-   `int main() { ... }`: The main function where program execution begins.
-   `int number;`: Declares an integer variable `number`.
-   `cin >> number;`: Reads an integer input from the user and stores it in `number`.
-   `int output = function(number);`: Calls the `function` with `number` as the argument and stores the result (number of `1s`) in `output`.
-   `cout << "The no of 1s in " << number << " in Binary : " << output << endl;`: Outputs the result to the console, indicating the number of `1s` in the binary representation of the input number.
-   `return 0;`: Indicates successful completion of the program.

## Example Execution

Let's consider the example of the number `7`:

-   The binary representation of `7` is `111`.
-   The `function` will count the number of `1s` as follows:
    -   Initial `n = 7` (`111` in binary). `n & 1` is `1`, so `count` becomes `1`. Right shift `n` to `3` (`11` in binary).
    -   Now, `n = 3`. `n & 1` is `1`, so `count` becomes `2`. Right shift `n` to `1` (`1` in binary).
    -   Now, `n = 1`. `n & 1` is `1`, so `count` becomes `3`. Right shift `n` to `0` (`0` in binary).
    -   Now, `n = 0`, so the loop terminates.
-   The function returns `3`, indicating there are three `1s` in the binary representation of `7`.

### Summary

This code reads an integer from the user, uses a function to count the number of `1s` in its binary representation, and prints the result. It effectively demonstrates bit manipulation and the use of a loop to traverse the bits of the integer.
