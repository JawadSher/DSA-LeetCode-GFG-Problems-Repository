<h1 align='center'>Power - Of - Two</h1>

## Problem Statement

![image](https://github.com/user-attachments/assets/a17bbac9-721c-4343-8c0f-5078db00921b)

**Description**: Given an integer `n`, write a function to determine if it is a power of two. A number is a power of two if it can be written as \(2^k\) where \(k\) is a non-negative integer.

**Examples**:
- Input: `16`  
  Output: `true`  
  Explanation: `16` is \(2^4\), so it is a power of two.
  
- Input: `14`  
  Output: `false`  
  Explanation: `14` cannot be expressed as \(2^k\), so it is not a power of two.

## Problem Solution
```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int ans = 1;
        for(int i = 0; i <= 30; i++){
            if(ans == n){
                return true;
            }
            if(ans < INT_MAX / 2)
            ans = ans * 2;
        }
        return false;
    }
};
```
## Problem Solution Explanation

Here’s the code to determine if a number is a power of two:


1. **Initialization**:
   ```cpp
   int ans = 1;  // Start with 1, which is 2^0
   ```
   - We start with `ans` initialized to `1`. This represents \(2^0\), which is `1`.

2. **Loop Through Powers of Two**:
   ```cpp
   for(int i = 0; i <= 30; i++){  // Check up to 2^30
   ```
   - We use a `for` loop to check values of `ans` from \(2^0\) up to \(2^{30}\). The upper limit of `30` is chosen because \(2^{31}\) would exceed the range of a 32-bit integer.

3. **Check If `ans` Matches `n`**:
   ```cpp
   if(ans == n){  // If ans matches n, n is a power of two
       return true;
   }
   ```
   - If `ans` equals `n`, it means that `n` is a power of two, and we return `true`.

4. **Prevent Overflow**:
   ```cpp
   if(ans < INT_MAX / 2)  // Ensure multiplication won't overflow
       ans = ans * 2;  // Multiply ans by 2 to get the next power of two
   ```
   - Before multiplying `ans` by `2`, we check if `ans` is less than `INT_MAX / 2`. This check ensures that multiplying `ans` by `2` won’t cause an overflow. `INT_MAX` is the maximum value an `int` can hold.

5. **If No Match Found**:
   ```cpp
   return false;  // If no match was found, return false
   ```
   - If the loop finishes without finding a match, it means `n` is not a power of two, so we return `false`.

### Summary

The function checks if a number `n` is a power of two by iterating through possible powers of two (from \(2^0\) to \(2^{30}\)) and comparing them with `n`. The multiplication check prevents integer overflow, ensuring that we correctly handle large values within the 32-bit integer range. If a power of two is found that matches `n`, the function returns `true`; otherwise, it returns `false`.
