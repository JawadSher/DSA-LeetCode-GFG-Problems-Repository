<h1 align='center'>Binary - Search</h1>

## Problem Statement

**Problem URL :** [None]()

You need to implement a recursive binary search algorithm to find whether a given integer `key` is present in a sorted array of integers. The function should take as input the array, the starting index `s`, the ending index `e`, and the `key` to search for. If the `key` is found, return `true`; otherwise, return `false`.

### Detailed Requirements:
1. **Input**:
   - A sorted array `arr[]` of integers.
   - Two integers `s` (starting index) and `e` (ending index) representing the range of the search.
   - An integer `key` to search for in the array.

2. **Output**:
   - Return `true` if the `key` is found in the array, otherwise return `false`.

3. **Constraints**:
   - The array is sorted in ascending order.
   - If the key is not present, the function will return `false`.

4. **Function Signature**:
   ```cpp
   bool isFound(int *arr, int s, int e, int key);
   ```

---

### Example:

#### Example 1:
**Input**:
```cpp
arr = {10, 20, 30, 40, 50, 60, 70}, key = 40
```
**Output**:
```
True
```
**Explanation**:
The `key` `40` is present in the array, so the function returns `true`.

#### Example 2:
**Input**:
```cpp
arr = {10, 20, 30, 40, 50, 60, 70}, key = 90
```
**Output**:
```
False
```
**Explanation**:
The `key` `90` is not present in the array, so the function returns `false`.


## Problem Solution
```cpp
#include <iostream>
using namespace std;

bool isFound(int *arr, int s, int e, int key){
  if(s > e) return false;

  int mid = s + (e - s) / 2;

  if(arr[mid] == key) return true;

  if(arr[mid] < key){
    return isFound(arr, mid+1, e, key);
  }else{
    return isFound(arr, s, mid-1, key);
  }
}

int main() {
  int new_array[] = {10, 20, 30, 40, 50, 60, 70};
  int key = 90;
  int s = 0;
  int e = 6;

  bool result = isFound(new_array, s, e, key);
  cout<< "Is key found : "<< (result ? "True" : "False") <<endl;
  return 0;
}
```

## Problem Solution Explanation

#### 1. **Function Definition:**

```cpp
bool isFound(int *arr, int s, int e, int key)
```
- This function takes four parameters:
  - `arr`: A pointer to the first element of the array.
  - `s`: The starting index of the current range.
  - `e`: The ending index of the current range.
  - `key`: The integer value we are searching for.

#### 2. **Base Case:**
```cpp
if(s > e) return false;
```
- **Base Case**: If the starting index `s` becomes greater than the ending index `e`, it means that we have exhausted all possible elements in the array without finding the `key`. Hence, we return `false`.

#### 3. **Mid-point Calculation:**
```cpp
int mid = s + (e - s) / 2;
```
- The middle index is calculated as `mid = s + (e - s) / 2`. This ensures that we avoid potential overflow issues that can arise when using `(s + e) / 2` in large arrays.

#### 4. **Check Mid-point:**
```cpp
if(arr[mid] == key) return true;
```
- If the element at the middle index `arr[mid]` is equal to the `key`, we return `true` since we have found the `key`.

#### 5. **Recursive Case - Right Half:**
```cpp
if(arr[mid] < key) return isFound(arr, mid+1, e, key);
```
- If the middle element `arr[mid]` is less than the `key`, this means the `key` must be in the right half of the array (since the array is sorted). Therefore, we recursively search the right half by calling `isFound(arr, mid+1, e, key)`.

#### 6. **Recursive Case - Left Half:**
```cpp
else return isFound(arr, s, mid-1, key);
```
- If the middle element `arr[mid]` is greater than the `key`, this means the `key` must be in the left half of the array. Hence, we recursively search the left half by calling `isFound(arr, s, mid-1, key)`.

#### 7. **Main Function:**
```cpp
int main() {
  int new_array[] = {10, 20, 30, 40, 50, 60, 70};
  int key = 90;
  int s = 0;
  int e = 6;

  bool result = isFound(new_array, s, e, key);
  cout<< "Is key found : "<< (result ? "True" : "False") <<endl;
  return 0;
}
```
- We initialize the array `new_array[] = {10, 20, 30, 40, 50, 60, 70}` and define the key `key = 90`.
- The `isFound` function is called with the array, starting index `s = 0`, ending index `e = 6`, and the `key = 90`.
- The result is printed: `"True"` if the key is found, otherwise `"False"`.

---

### Function Call Stack and Recursion Tree:

#### Example Execution with Input:
`arr = {10, 20, 30, 40, 50, 60, 70}, key = 90, s = 0, e = 6`

#### **First Call:**
```cpp
isFound(new_array, 0, 6, 90)
```
- `s = 0`, `e = 6`, `mid = (0 + 6) / 2 = 3`, `arr[mid] = 40`.
- Since `40 < 90`, search the right half: `isFound(new_array, 4, 6, 90)`.

---

#### **Second Call:**
```cpp
isFound(new_array, 4, 6, 90)
```
- `s = 4`, `e = 6`, `mid = (4 + 6) / 2 = 5`, `arr[mid] = 60`.
- Since `60 < 90`, search the right half: `isFound(new_array, 6, 6, 90)`.

---

#### **Third Call:**
```cpp
isFound(new_array, 6, 6, 90)
```
- `s = 6`, `e = 6`, `mid = (6 + 6) / 2 = 6`, `arr[mid] = 70`.
- Since `70 < 90`, search the right half: `isFound(new_array, 7, 6, 90)`.

---

#### **Fourth Call (Base Case):**
```cpp
isFound(new_array, 7, 6, 90)
```
- Now `s = 7`, `e = 6`, and since `s > e`, return `false`.

---

### Recursion Tree:

Here’s a visualization of how the recursion tree looks when searching for `key = 90`:

```
isFound([10, 20, 30, 40, 50, 60, 70], 0, 6, 90)
        |
        V
isFound([50, 60, 70], 4, 6, 90)
        |
        V
isFound([70], 6, 6, 90)
        |
        V
isFound([], 7, 6, 90) --> s > e, return false
```

---

### Function Call Stack:

#### Step-by-step Execution:
1. **Call 1**: `isFound(new_array, 0, 6, 90)` → Check `arr[3] = 40` → Call 2.
2. **Call 2**: `isFound(new_array, 4, 6, 90)` → Check `arr[5] = 60` → Call 3.
3. **Call 3**: `isFound(new_array, 6, 6, 90)` → Check `arr[6] = 70` → Call 4.
4. **Call 4**: `isFound(new_array, 7, 6, 90)` → Base case `s > e`, return `false`.
5. Each call returns `false` back through the stack until `main` receives the final result.

---

### Summary:
- The binary search recursively splits the array into halves and searches for the key in the appropriate half.
- The recursion tree demonstrates how the array is broken into smaller subarrays.
- If the key is found, the function returns `true`; otherwise, it returns `false`.
- In this example, since `90` is not present in the array, the function eventually reaches the base case and returns `false`.
