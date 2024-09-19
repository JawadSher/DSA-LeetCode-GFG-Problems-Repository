<h1 align='center'>Linear - Search</h1>

## Problem Statement

**Problem URL :** [None]()

Write a recursive function to check whether a given integer `key` is present in an array of integers. The function should take as input the array, its size `n`, and the `key` to search for. If the `key` is found in the array, return `true`; otherwise, return `false`.

### Detailed Requirements:
1. **Input**:
   - An array `arr[]` of integers with size `n`.
   - An integer `key` to search for in the array.
   
2. **Output**:
   - Return `true` if the `key` is found in the array, otherwise return `false`.
   
3. **Constraints**:
   - The size of the array `n` can be any non-negative integer (`n >= 0`).
   - If the array is empty (`n == 0`), return `false`.
   - The array can contain duplicate values, but the function should return `true` upon finding the first occurrence of `key`.

4. **Function Signature**:
   ```cpp
   bool isFound(int *arr, int n, int key);
   ```

### Example:

#### Example 1:
**Input**:
```cpp
arr = {10, 20, 30, 15, 11, 19}
key = 11
n = 6
```
**Output**:
```
True
```
**Explanation**:
The `key` `11` is present in the array at index 4, so the function returns `true`.

#### Example 2:
**Input**:
```cpp
arr = {10, 20, 30, 15, 11, 19}
key = 25
n = 6
```
**Output**:
```
False
```
**Explanation**:
The `key` `25` is not present in the array, so the function returns `false`.

#### Example 3:
**Input**:
```cpp
arr = {}
key = 5
n = 0
```
**Output**:
```
False
```
**Explanation**:
An empty array does not contain any elements, so the function returns `false`.


### Code Explanation:
## Problem Solution
```cpp
#include <iostream>
using namespace std;

bool isFound(int *arr, int n, int key){
  if(n == 0){
    return false;
  }

  if(*arr == key) return true;

  return isFound(arr + 1, n-1, key);
}

int main() {
  int new_array[] = {10, 20, 30, 15, 11, 19};
  int key = 11;
  bool result = isFound(new_array, 6, key);
  cout<<"Is key present : "<<(result ? "True" : "False")<< endl;
  
  return 0;
}
```

## Problem Solution Explanation

Let's walk through the code line by line:

#### 1. **Function Definition:**

```cpp
bool isFound(int *arr, int n, int key)
```
- This function takes three parameters:
  - `arr`: A pointer to the first element of the array.
  - `n`: The number of elements in the array.
  - `key`: The integer value we are searching for.

---

#### 2. **Base Case:**
```cpp
if(n == 0){
  return false;
}
```
- **Base Case 1**: If the size of the array (`n`) becomes `0`, it means we have checked all the elements and did not find the key. In this case, we return `false`.

---

#### 3. **Key Check:**
```cpp
if(*arr == key) return true;
```
- **Base Case 2**: If the current element (`*arr`) is equal to the `key`, we return `true` because we have found the key in the array.

---

#### 4. **Recursive Call:**
```cpp
return isFound(arr + 1, n - 1, key);
```
- **Recursive Case**: If the current element is not equal to the key, we recursively call the function on the next part of the array (`arr + 1` shifts the pointer to the next element, and `n - 1` reduces the size of the array by 1). This continues until the base case is reached.

---

#### 5. **Main Function:**
```cpp
int main() {
  int new_array[] = {10, 20, 30, 15, 11, 19};
  int key = 11;
  bool result = isFound(new_array, 6, key);
  cout<<"Is key present : "<<(result ? "True" : "False")<< endl;
  
  return 0;
}
```
- We initialize the array `new_array[] = {10, 20, 30, 15, 11, 19}` and define the key `key = 11`.
- The `isFound` function is called with the array, its size `6`, and the key `11`.
- The result is printed: `"True"` if the key is found, otherwise `"False"`.

---

### Function Call Stack and Recursion Tree:

#### Example Execution with Input:
`arr = {10, 20, 30, 15, 11, 19}, key = 11, n = 6`

1. **First Call**: `isFound(new_array, 6, 11)`
   - `n` is `6`, `*arr` is `10`.
   - `10 != 11`, so call `isFound(new_array + 1, 5, 11)`.

2. **Second Call**: `isFound(new_array + 1, 5, 11)`
   - `n` is `5`, `*arr` is `20`.
   - `20 != 11`, so call `isFound(new_array + 2, 4, 11)`.

3. **Third Call**: `isFound(new_array + 2, 4, 11)`
   - `n` is `4`, `*arr` is `30`.
   - `30 != 11`, so call `isFound(new_array + 3, 3, 11)`.

4. **Fourth Call**: `isFound(new_array + 3, 3, 11)`
   - `n` is `3`, `*arr` is `15`.
   - `15 != 11`, so call `isFound(new_array + 4, 2, 11)`.

5. **Fifth Call**: `isFound(new_array + 4, 2, 11)`
   - `n` is `2`, `*arr` is `11`.
   - `11 == 11`, so return `true`.

6. The fifth call returns `true` to the fourth call, the fourth call returns `true` to the third, and so on until the first call returns `true` to the main function.

---

### Recursion Tree:

Here’s a visualization of how the recursion tree looks when searching for `key = 11`:

```
isFound([10, 20, 30, 15, 11, 19], 6, 11)
        |
        V
isFound([20, 30, 15, 11, 19], 5, 11)
        |
        V
isFound([30, 15, 11, 19], 4, 11)
        |
        V
isFound([15, 11, 19], 3, 11)
        |
        V
isFound([11, 19], 2, 11) --> Found the key, return true
```

At each recursive step, the function checks the first element and continues to search in the rest of the array. When it finds the key (`11`), it returns `true` and the recursion tree unwinds back to the main function.

---

### Function Call Stack:

#### Step-by-step Execution:
1. **Call 1**: `isFound(new_array, 6, 11)` → Check `10` → Call 2
2. **Call 2**: `isFound(new_array + 1, 5, 11)` → Check `20` → Call 3
3. **Call 3**: `isFound(new_array + 2, 4, 11)` → Check `30` → Call 4
4. **Call 4**: `isFound(new_array + 3, 3, 11)` → Check `15` → Call 5
5. **Call 5**: `isFound(new_array + 4, 2, 11)` → Check `11` → Return `true`
6. Each call returns `true` back through the stack until `main` receives the final result.

---

### Summary:
- The function checks each element of the array recursively until it either finds the key or reaches the end of the array.
- If the key is found, the recursion tree returns `true`; otherwise, it returns `false`.
- The recursion tree helps break down the array into smaller parts, and the function call stack ensures that results are passed back up to the original call.
