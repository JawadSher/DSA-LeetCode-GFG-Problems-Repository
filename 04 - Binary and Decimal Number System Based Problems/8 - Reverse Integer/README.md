<h1 align='center'>Reverse - Integer</h1>

## Problem Statement

![image](https://github.com/user-attachments/assets/da65c979-27dd-43f9-8ab9-f94364a1db15)

**Description**: Given a 32-bit signed integer `x`, reverse the digits of `x`. The reversed number should be returned as an integer.

**Constraints**:
- The function should handle overflow conditions. If the reversed integer overflows the 32-bit signed integer range, return 0.
- The 32-bit signed integer range is from `-2^31` to `2^31 - 1`, i.e., `[-2147483648, 2147483647]`.

## Problem Solution
```cpp
class Solution {
public:
    int reverse(int x) {
        int reverse_Num = 0;
        int i = 0;
        while(x){
            int digit = x % 10;
            if(reverse_Num > INT_MAX/10 || reverse_Num < INT_MIN/10){
                return 0;
            }
            reverse_Num = reverse_Num * 10 + digit;
            i++;
            x = x/10;
        }
        return reverse_Num;
    }
};
```

## Problem Solution Explanation

1. **Initialization**:
   - `reverse_Num` is initialized to `0`. This variable will store the reversed integer as we build it.

2. **Loop Through Digits**:
   - `while(x)` loops until `x` becomes `0`. This loop will process each digit of `x` from the end (rightmost) to the beginning (leftmost).

3. **Extract Last Digit**:
   - `int digit = x % 10;` extracts the last digit of `x`. For example, if `x` is `123`, `digit` will be `3`.

4. **Check for Overflow**:
   - `if(reverse_Num > INT_MAX / 10 || reverse_Num < INT_MIN / 10)` checks if adding the new digit would cause an overflow.
     - `INT_MAX` is `2147483647`, and `INT_MIN` is `-2147483648`. We use these constants to ensure that multiplying `reverse_Num` by `10` and adding `digit` does not exceed these limits.

5. **Construct Reversed Number**:
   - `reverse_Num = reverse_Num * 10 + digit;` appends the last digit to `reverse_Num`. For instance, if `reverse_Num` was `0` and `digit` was `3`, after this operation `reverse_Num` becomes `3`. If `reverse_Num` was `32` and `digit` was `1`, `reverse_Num` becomes `321`.

6. **Remove Last Digit**:
   - `x = x / 10;` removes the last digit from `x`. For example, if `x` was `123`, after this operation `x` becomes `12`.

7. **Return Result**:
   - After the loop ends, `reverse_Num` contains the reversed integer. This value is returned.

### Example Walkthrough

**Example 1**:
- Input: `123`
- Execution:
  1. `reverse_Num = 0`
  2. `digit = 3` (from `123 % 10`)
  3. `reverse_Num = 0 * 10 + 3 = 3`
  4. `x = 12` (from `123 / 10`)
  5. `digit = 2` (from `12 % 10`)
  6. `reverse_Num = 3 * 10 + 2 = 32`
  7. `x = 1` (from `12 / 10`)
  8. `digit = 1` (from `1 % 10`)
  9. `reverse_Num = 32 * 10 + 1 = 321`
  10. `x = 0` (from `1 / 10`)
- Output: `321`

**Example 2**:
- Input: `-123`
- Execution:
  1. `reverse_Num = 0`
  2. `digit = -3` (from `-123 % 10`)
  3. `reverse_Num = 0 * 10 - 3 = -3`
  4. `x = -12` (from `-123 / 10`)
  5. `digit = -2` (from `-12 % 10`)
  6. `reverse_Num = -3 * 10 - 2 = -32`
  7. `x = -1` (from `-12 / 10`)
  8. `digit = -1` (from `-1 % 10`)
  9. `reverse_Num = -32 * 10 - 1 = -321`
  10. `x = 0` (from `-1 / 10`)
- Output: `-321`

The code effectively handles both positive and negative integers while checking for overflow conditions.
