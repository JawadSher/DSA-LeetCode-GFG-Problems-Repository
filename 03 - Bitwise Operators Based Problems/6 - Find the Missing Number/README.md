# Problem Statement

The task is to find the missing number in an array containing all integers from `0` to `n` except one. For instance, if `n` is `4`, the array should contain integers from the set `{0, 1, 2, 3, 4}`, with one number missing. For example, the array `{3, 0, 1, 4}` is missing the number `2`.

### Constraints

- The array contains exactly `n` elements.
- Each integer in the array is unique and falls within the range `0` to `n`.
- The size of the array is always `n`, meaning one number is missing from a complete sequence.

### Examples

1. **Example 1:**

   **Input:**

   ```
   nums = {3, 0, 1, 4}
   ```

   **Output:**

   ```
   2
   ```

   **Explanation:**

   The array `{3, 0, 1, 4}` is missing the number `2`. The function will return `2`.

3. **Example 2:**

   **Input:**

   ```
   nums = {0, 1, 3}
   ```

   **Output:**

   ```
   2
   ```

   **Explanation:**

   The array `{0, 1, 3}` is missing the number `2`. The function will return `2`.

5. **Example 3:**

   **Input:**

   ```
   nums = {1, 2, 3, 5}
   ```

   **Output:**

   ```
   4
   ```

   **Explanation:**

   The array `{1, 2, 3, 5}` is missing the number `4`. The function will return `4`.

---

## Problem Solution Explanation

### 1. Function Definition

```cpp
int find_missing_number(int nums[], int n) {
    int xor_sum = 0;
    
    for (int i = 0; i <= n; i++){
        xor_sum ^= i;
    }
    for (int i = 0; i < n; i++){
        xor_sum ^= nums[i];
    }
    return xor_sum;
}
```

#### Parameters:

- `nums[]`: The input array containing `n` elements, where one number from `0` to `n` is missing.
- `n`: The size of the input array, which is `n` since one number is missing.

#### XOR Initialization:

- `int xor_sum = 0;`: Initializes `xor_sum` to `0`.

#### First Loop:

```cpp
for (int i = 0; i <= n; i++){
    xor_sum ^= i;
}
```

- **Purpose**: Iterates through all integers from `0` to `n` (inclusive) and XORs each number with `xor_sum`.
- **Result**: Computes the XOR of all numbers from `0` to `n`.

#### Second Loop:

```cpp
for (int i = 0; i < n; i++){
    xor_sum ^= nums[i];
}
```

- **Purpose**: Iterates through all elements in the input array `nums` and XORs each element with `xor_sum`.
- **Result**: Computes the XOR of all elements in the array.

#### Return Statement:

```cpp
return xor_sum;
```

- **Purpose**: The result stored in `xor_sum` is the missing number.

### 2. Main Function

```cpp
int main() {
    int nums[] = {3, 0, 1, 4}; // Array with one number missing
    int size = sizeof(nums) / sizeof(nums[0]);
    int missing_number = find_missing_number(nums, size);
    cout << "The missing number is: " << missing_number << endl;
    return 0;
}
```

#### Array Initialization:

- `int nums[] = {3, 0, 1, 4};`: The input array with one number missing.

#### Size Calculation:

- `int size = sizeof(nums) / sizeof(nums[0]);`: Calculates the size of the array `nums`. Since `sizeof(nums)` gives the total byte size of the array and `sizeof(nums[0])` gives the byte size of an individual element, dividing these yields the number of elements in the array, which is `4`.

#### Function Call:

- `int missing_number = find_missing_number(nums, size);`: Calls the `find_missing_number` function with the array `nums` and its size.

#### Print Result:

- `cout << "The missing number is: " << missing_number << endl;`: Prints the missing number.

---

## Explanation of Why It Works

### XOR Properties

- `a ^ a = 0`: XOR of a number with itself results in `0`.
- `a ^ 0 = a`: XOR of a number with `0` is the number itself.
- XOR operation is both commutative and associative.

### Finding Missing Number

- **First Loop**: Computes the XOR of all numbers from `0` to `n`.
- **Second Loop**: Computes the XOR of all elements in the array `nums`.
- **Final XOR**: Since all numbers from `0` to `n` are included in the XOR computation except the missing number, XORing the results of the two loops cancels out all pairs of identical numbers, leaving only the missing number.

---

## Example Output

For the array `{3, 0, 1, 4}`, the missing number is `2`. When the code is executed, the output will be:

```
The missing number is: 2
```

This confirms that the function correctly identifies the missing number using the properties of the XOR operation.

---
