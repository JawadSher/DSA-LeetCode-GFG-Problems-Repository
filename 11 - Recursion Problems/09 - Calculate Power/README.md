<h1 align='center'>Calculate - Power</h1>

## Problem Statement

**Problem URL :** [None]()

Write a recursive function `power(a, b)` that calculates the value of \(a^b\) (i.e., a raised to the power of b). The function should minimize the number of recursive calls by applying an optimized approach. If \(b\) is even, \(a^b = (a^{b/2})^2\). If \(b\) is odd, \(a^b = a \times (a^{b/2})^2\).

## Problem Solution
```cpp
#include <iostream>
using namespace std;

int power(int a, int b){
  // base case
  if(b == 0) return 1;
  if(b == 1) return a;

  // Recursive call
  int ans = power(a, b/2);

  if(b%2 == 0){
    // if b is even
    return ans * ans;
  }else{
    // if b is odd
    return a * (ans * ans);
  }
}

int main() {
  int a = 2;
  int b = 9;

  int ans = power(a, b);

  cout<< "Answer is : "<< ans <<endl;
  return 0;
}
```

## Problem Solution Explanation



```cpp
#include <iostream>
using namespace std;
```
- **#include <iostream>**: Includes the input/output stream library, enabling the use of `cin` and `cout`.

```cpp
int power(int a, int b) {
```
- **int power(int a, int b)**: This defines a function to calculate \(a^b\), where `a` is the base, and `b` is the exponent.

```cpp
  if(b == 0) return 1;
```
- **if(b == 0) return 1;**: Base case 1: If the exponent is 0, the result is always 1, since any number raised to the power of 0 is 1.

```cpp
  if(b == 1) return a;
```
- **if(b == 1) return a;**: Base case 2: If the exponent is 1, the result is the base `a` itself (i.e., \(a^1 = a\)).

```cpp
  int ans = power(a, b / 2);
```
- **int ans = power(a, b / 2);**: Recursive call to calculate \(a^{b/2}\). This step reduces the problem size by half at each recursive step, making the process more efficient.

```cpp
  if(b % 2 == 0) {
    return ans * ans;
  }
```
- **if(b % 2 == 0)**: If `b` is even, it calculates \(a^b\) by squaring the result of \(a^{b/2}\) (i.e., \(a^b = (a^{b/2})^2\)).

```cpp
  else {
    return a * (ans * ans);
  }
```
- **else**: If `b` is odd, it calculates \(a^b\) by multiplying the base `a` with the square of \(a^{b/2}\) (i.e., \(a^b = a \times (a^{b/2})^2\)).

```cpp
int main() {
  int a = 2;
  int b = 9;
```
- **int a = 2; int b = 9;**: Initializes the base `a = 2` and the exponent `b = 9`.

```cpp
  int ans = power(a, b);
```
- **int ans = power(a, b);**: Calls the recursive `power` function with `a = 2` and `b = 9`, storing the result in `ans`.

```cpp
  cout<< "Answer is : "<< ans <<endl;
  return 0;
```
- **cout << "Answer is : " << ans << endl;**: Outputs the final result of \(2^9\), which is 512.
- **return 0;**: Ends the program.

---

### Recursive Function Calls and Tree:

#### Example 1: **\(a = 2, b = 9\)**

1. **Initial call**: `power(2, 9)`
   - \(b = 9\) is odd, so:
   - Recursive call: `power(2, 4)` (since \(b/2 = 4\))

2. **Next call**: `power(2, 4)`
   - \(b = 4\) is even, so:
   - Recursive call: `power(2, 2)`

3. **Next call**: `power(2, 2)`
   - \(b = 2\) is even, so:
   - Recursive call: `power(2, 1)`

4. **Base case**: `power(2, 1)`
   - Since \(b = 1\), return `a = 2`.

5. **Returning up the stack**:
   - From `power(2, 2)`: Multiply the result \(ans = 2\) by itself, returning \(2 \times 2 = 4\).
   - From `power(2, 4)`: Multiply the result \(ans = 4\) by itself, returning \(4 \times 4 = 16\).
   - From `power(2, 9)`: Multiply the base `a = 2` with the result \(ans = 16\) squared, returning \(2 \times (16 \times 16) = 512\).

- **Result**: 512

---

### Recursive Call Tree (Example 1: \(a = 2, b = 9\)):

```
power(2, 9)
    -> power(2, 4)
        -> power(2, 2)
            -> power(2, 1) -> Base case -> 2
        -> 2 * 2 = 4
    -> 4 * 4 = 16
-> 2 * (16 * 16) = 512
```

---

### Example 2: **\(a = 3, b = 6\)**

1. **Initial call**: `power(3, 6)`
   - \(b = 6\) is even, so:
   - Recursive call: `power(3, 3)`

2. **Next call**: `power(3, 3)`
   - \(b = 3\) is odd, so:
   - Recursive call: `power(3, 1)`

3. **Base case**: `power(3, 1)`
   - Since \(b = 1\), return `a = 3`.

4. **Returning up the stack**:
   - From `power(3, 3)`: Multiply the base `a = 3` with the result \(ans = 3\) squared, returning \(3 \times (3 \times 3) = 27\).
   - From `power(3, 6)`: Multiply the result \(ans = 27\) by itself, returning \(27 \times 27 = 729\).

- **Result**: 729

---

### Recursive Call Tree (Example 2: \(a = 3, b = 6\)):

```
power(3, 6)
    -> power(3, 3)
        -> power(3, 1) -> Base case -> 3
    -> 3 * (3 * 3) = 27
-> 27 * 27 = 729
```

---

### Example 3: **\(a = 5, b = 0\)**

1. **Initial call**: `power(5, 0)`
   - Since \(b = 0\), return 1 (base case).

- **Result**: 1

---

### Final Outputs for Each Example:

1. **Input**: \(a = 2, b = 9\)
   - **Output**: 512

2. **Input**: \(a = 3, b = 6\)
   - **Output**: 729

3. **Input**: \(a = 5, b = 0\)
   - **Output**: 1

---

### Summary:

- The function efficiently calculates the power of a number using the divide-and-conquer approach.
- It reduces the number of recursive calls by dividing the exponent \(b\) by 2 at each step.
- If \(b\) is even, it squares the result. If \(b\) is odd, it multiplies the base `a` by the square of the result.
