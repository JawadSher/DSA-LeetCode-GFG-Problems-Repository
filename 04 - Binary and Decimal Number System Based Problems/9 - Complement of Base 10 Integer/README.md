<h1 align='center'>Complement - Of - Base - 10 - Integer</h1>

## Problem Statement

![image](https://github.com/user-attachments/assets/deaa3ccd-b9da-4c6a-8b16-8a01fb769987)

**Description**: Given a positive integer `n`, return its complement number. The complement of an integer is the number you get when you flip all the bits of its binary representation. For example, if the binary representation of `n` is `0101`, then its complement is `1010`.

## Problme Solution
```cpp
class Solution {
public:
    int bitwiseComplement(int n) {
        int m = n;
        int mask = 0;
        if(m == 0){
            return 1;
        }
        while(m){
            mask = (mask << 1) | 1;
            m = m >> 1;
        }
        int ans = (~n) & mask;
      return ans;
    }
};
```

## Problem Solution Explanation

Here is the code to find the complement of a given integer:

1. **Initialization**:
   ```cpp
   int m = n;  // Store the original value of n
   int mask = 0;  // Initialize mask to 0
   ```
   - `m` is used to manipulate the original number `n` without changing it.
   - `mask` will be used to create a bitmask that will help us isolate the bits of `n`.

2. **Handle Special Case**:
   ```cpp
   if(m == 0) {
       return 1;  // The complement of 0 is 1
   }
   ```
   - If `n` is `0`, its binary representation is `0`. The complement of `0` is `1` (binary `1`). So, we handle this special case directly.

3. **Create Bitmask**:
   ```cpp
   while(m) {
       mask = (mask << 1) | 1;  // Shift mask left and add 1
       m = m >> 1;  // Shift m right
   }
   ```
   - This loop creates a bitmask of the same length as the binary representation of `n`.
   - In each iteration:
     - `mask = (mask << 1) | 1`: Shifts the mask left by one position and sets the least significant bit to `1`. This builds a mask of `1`s with the same number of bits as `n`.
     - `m = m >> 1`: Shifts `m` right by one position, effectively reducing its bit length until `m` becomes `0`.

   **Example**:
   - Suppose `n` is `5` (binary `101`).
     - Initially, `mask = 0` (binary `0`).
     - First iteration: `mask = 1` (binary `1`), `m = 2` (binary `10`).
     - Second iteration: `mask = 3` (binary `11`), `m = 1` (binary `1`).
     - Third iteration: `mask = 7` (binary `111`), `m = 0` (binary `0`).

4. **Compute Complement**:
   ```cpp
   int ans = (~n) & mask;  // Compute the complement of n
   return ans;  // Return the result
   ```
   - `~n` computes the bitwise NOT of `n`, flipping all its bits.
   - `(~n) & mask` ensures that only the bits within the bitmask's length are considered. This isolates the relevant bits to match the bit length of `n`.
   - The result, `ans`, is the complement of `n` considering only its significant bits.

   **Example**:
   - For `n = 5` (binary `101`):
     - `~n` in binary is `...1111111010` (assuming 32-bit integers).
     - `mask` is `111` (binary for the length of `n`).
     - `(~n) & mask` results in `010` (binary `2`), which is the complement of `5` considering only the bits of `n`.

### Summary

The code efficiently computes the bitwise complement of a number by creating a mask with the same number of bits as the original number and then applying the complement operation within that bit-width. This ensures that we correctly handle the significant bits of the number and ignore any extraneous bits.
