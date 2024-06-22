## Source Code Explanation

### Includes and Namespace

```#include <iostream>```

```using namespace std;```

-   `#include <iostream>`: Includes the Input/Output Stream library, necessary for using `cin` and `cout`.
-   `using namespace std;`: Allows us to use standard namespace components like `cout` without prefixing them with `std::`.

### Function Definition

```
void function(int n1, int n2){
    n1 = n1 ^ n2;
    n2 = n1 ^ n2;
    n1 = n1 ^ n2;
    cout << "The value of n1 is : " << n1 << endl;
    cout << "The value of n2 is : " << n2 << endl;
}
```

-   `void function(int n1, int n2)`: Defines a function named `function` that takes two integer parameters `n1` and `n2`, and returns `void` (i.e., it doesn't return any value).
-   The function swaps the values of `n1` and `n2` using the XOR bitwise operator:
    1.  `n1 = n1 ^ n2;`: This sets `n1` to the result of `n1 XOR n2`.
    2.  `n2 = n1 ^ n2;`: This sets `n2` to the result of the new `n1` XOR the original `n2`, which effectively assigns the original value of `n1` to `n2`.
    3.  `n1 = n1 ^ n2;`: This sets `n1` to the result of the new `n1` XOR the new `n2`, which effectively assigns the original value of `n2` to `n1`.
-   After these operations, the values of `n1` and `n2` are swapped.
-   `cout << "The value of n1 is : " << n1 << endl;` and `cout << "The value of n2 is : " << n2 << endl;`: Print the swapped values of `n1` and `n2`.

### Main Function
```
int main() {
    int num1 = 10;
    int num2 = 20;
    cout << "------>Before Swap<------" << endl;
    cout << "The value of n1 is : " << num1 << endl;
    cout << "The value of n2 is : " << num2 << endl;
    cout << "------>After Swap<------" << endl;
    function(num1, num2);
    return 0;
}
```

-   `int main() { ... }`: The main function where program execution starts.
-   `int num1 = 10;` and `int num2 = 20;`: Declare and initialize two integer variables `num1` and `num2`.
-   `cout << "------>Before Swap<------" << endl;`: Print a header indicating the values before swapping.
-   `cout << "The value of n1 is : " << num1 << endl;`: Print the initial value of `num1`.
-   `cout << "The value of n2 is : " << num2 << endl;`: Print the initial value of `num2`.
-   `cout << "------>After Swap<------" << endl;`: Print a header indicating the values after swapping.
-   `function(num1, num2);`: Call the `function` to swap `num1` and `num2`.
-   `return 0;`: Indicate successful program termination.

### Explanation of XOR Swap Algorithm

The XOR swap algorithm is a way to swap two variables without using a temporary variable. It works because of the properties of the XOR bitwise operation:

1.  `a ^ a = 0`
2.  `a ^ 0 = a`
3.  XOR is commutative and associative, meaning the order of operations does not change the result.

Given `a` and `b`:

1.  `a = a ^ b`
2.  `b = a ^ b` (which is `a ^ b ^ b`, simplifying to `a` since `b ^ b = 0` and `a ^ 0 = a`)
3.  `a = a ^ b` (which is `a ^ b ^ a`, simplifying to `b` since `a ^ a = 0` and `0 ^ b = b`)

### Summary

-   The program demonstrates how to swap two integers using the XOR bitwise operator.
-   It first prints the values before swapping, then performs the swap using the `function`, and finally prints the values after swapping.
-   The XOR swap algorithm efficiently swaps values without needing a temporary variable.
