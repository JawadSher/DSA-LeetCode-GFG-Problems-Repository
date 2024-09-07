<h1 align='center'></h1>

## Problem Statement

**Problem URL :** None

You are given a 2D array (matrix) of size `n x m` (rows × columns). Your task is to print the matrix in a "wave-like" manner, column by column. Specifically:
- If the column index is **even**, print the elements from **top to bottom**.
- If the column index is **odd**, print the elements from **bottom to top**.

### Example:
For the input matrix:
```
1   2   3   4   5
11  12  13  14  15
21  22  23  24  25
```

The output (wave-like traversal) would be:
```
1 11 21 
22 12 2 
3 13 23 
24 14 4 
5 15 25 
```


## Problem Solution
```cpp
#include <iostream>
using namespace std;

void waveIteration(int array_2d[][5], int row, int col){
  for(int j = 0; j < col; j++){
    if(j&1){
      for(int i = row-1; i>=0; i--){
        cout<<array_2d[i][j] << " ";
      }
      cout<<endl;
    }else{
      for(int i = 0; i<=row-1; i++){
        cout<<array_2d[i][j]<< " ";
      }
      cout<<endl;
    }
  }
}

int main() {
  int array_2d[3][5] = {{1, 2, 3, 4, 5}, 
                  {11, 12, 13, 14, 15}, 
                  {21, 22, 23, 24, 25}};

  waveIteration(array_2d, 3, 5);
  return 0;
}
```

## Problem Solution Explanation

```cpp
#include <iostream>
using namespace std;
```
- **`#include <iostream>`**: This includes the input/output stream library, allowing us to use functions like `cin` and `cout` for input and output.
- **`using namespace std;`**: This allows us to avoid prefixing `std::` before standard functions like `cout` and `cin`.

---

```cpp
void waveIteration(int array_2d[][5], int row, int col){
```
- **`void waveIteration(int array_2d[][5], int row, int col)`**: This is the function definition for `waveIteration`. It takes three parameters:
  - `array_2d[][5]`: A 2D array of integers with 5 columns (specified).
  - `row`: The number of rows in the 2D array.
  - `col`: The number of columns in the 2D array.

---

```cpp
for(int j = 0; j < col; j++){
```
- **`for(int j = 0; j < col; j++)`**: This loop iterates over each column (`j` goes from 0 to `col - 1`). The idea is to process each column separately in a wave-like manner.

---

```cpp
if(j & 1){
```
- **`if(j & 1)`**: This checks whether the current column index `j` is odd. The expression `j & 1` performs a bitwise AND operation between `j` and `1`. If `j` is odd, this condition evaluates to `true`.
  - **Odd columns** (like `1`, `3`, `5`, etc.) will be printed from **bottom to top**.

---

```cpp
for(int i = row-1; i >= 0; i--){
```
- **`for(int i = row-1; i >= 0; i--)`**: If the column is odd, this loop prints the elements of the column starting from the **bottom row** (`row - 1`) and goes up to the **top row** (`0`).
  - This loop will print column elements in reverse order for odd-indexed columns.

---

```cpp
cout << array_2d[i][j] << " ";
```
- **`cout << array_2d[i][j] << " ";`**: This prints each element of the 2D array located at row `i` and column `j`. Since we're iterating column by column, the elements are printed accordingly.

---

```cpp
cout << endl;
```
- **`cout << endl;`**: This prints a newline after processing each column, ensuring the output looks clean.

---

```cpp
}else{
```
- **`else {`**: This block handles the case where `j` is even. For even columns, the elements will be printed from **top to bottom**.

---

```cpp
for(int i = 0; i <= row-1; i++){
```
- **`for(int i = 0; i <= row-1; i++)`**: This loop iterates from the **top row** (`i = 0`) to the **bottom row** (`i = row-1`) when the column is even, printing elements in normal order.

---

```cpp
cout << array_2d[i][j] << " ";
```
- **`cout << array_2d[i][j] << " ";`**: Again, this prints each element in the current column, but this time in normal order from top to bottom since we're in an even column.

---

```cpp
cout << endl;
```
- **`cout << endl;`**: As before, this adds a newline after printing a column, ensuring the wave-like output format.

---

```cpp
int main() {
  int array_2d[3][5] = {{1, 2, 3, 4, 5}, 
                        {11, 12, 13, 14, 15}, 
                        {21, 22, 23, 24, 25}};
```
- **`int array_2d[3][5] = {...};`**: This declares and initializes a 2D array `array_2d` of size 3x5 with some sample values.

---

```cpp
waveIteration(array_2d, 3, 5);
```
- **`waveIteration(array_2d, 3, 5);`**: This calls the `waveIteration` function, passing the `array_2d`, the number of rows (`3`), and the number of columns (`5`) as arguments. This triggers the wave-like printing.

---

```cpp
return 0;
}
```
- **`return 0;`**: This signals the successful termination of the `main` function.

---

### Output of the Code:

The matrix will be printed in a wave-like manner:
```
1 11 21 
22 12 2 
3 13 23 
24 14 4 
5 15 25 
```

### Summary of the Process:
- Columns are iterated from left to right.
- If the column index is **even**, print the elements **top to bottom**.
- If the column index is **odd**, print the elements **bottom to top**.

This method achieves the "wave-like" traversal of the matrix, where each odd-indexed column reverses the direction of printing.
