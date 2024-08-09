<h1 align='center'>Image - Smoother</h1>

## Problem Statement

![image](https://github.com/user-attachments/assets/a00db277-d432-4f67-acb0-6b2001036a3a)
![image](https://github.com/user-attachments/assets/6735933d-1132-436c-9864-b87518a08f0f)
![image](https://github.com/user-attachments/assets/951a141e-455f-4456-95d7-d3943ed72761)


## Problem Explanation 

**Image Smoothing Problem:**

Imagine you have a picture made up of a grid of numbers, where each number represents the intensity of a pixel. The goal is to make the picture look smoother by averaging the values of pixels around each pixel. This is similar to blurring an image to remove sharp edges and noise.

Here’s how the smoothing process works:

1. **For Each Pixel:**
   - **Interior Pixels:** Average the values of the pixel itself and its 8 neighboring pixels (a 3x3 grid centered on the pixel).
   - **Edge and Corner Pixels:** Average the values of the pixel and its available neighbors (fewer than 8 neighbors because it's on the edge).

### How Beginners Solve This Problem Using DSA Concepts

**1. Understanding the Problem:**
   - Beginners first need to understand how to navigate through a 2D grid and how to access the neighbors of each cell.

**2. Iterating Through the Grid:**
   - They need to iterate over each cell in the grid and apply the averaging logic.

**3. Handling Edge Cases:**
   - For cells on the edges and corners, they need to handle fewer neighbors and avoid going out of bounds.

**4. Average Calculation:**
   - Use a nested loop to sum up the values of the pixel and its neighbors and then divide by the number of valid pixels to get the average.

## Problem Solution
```cpp
class Solution {
public:
    vector<vector<int>> imageMatrix;
    int total_rows, total_cols;

    // Calculates the sum of values in the 3x3 grid centered at (row, col)
    int calculate3X3sum(int row, int col) {
        int total_sum = 0;

        for (int i = row - 1; i <= row + 1; ++i) {
            for (int j = col - 1; j <= col + 1; ++j) {
                if (i >= 0 && i < total_rows && j >= 0 && j < total_cols) {
                    total_sum += imageMatrix[i][j];
                }
            }
        }

        return total_sum;
    }

    // Calculates the average value for border cells, considering valid neighbors
    int calculateBorderAvg(int row, int col) {
        int sum = 0;
        int count = 0;

        for (int i = max(row - 1, 0); i <= min(row + 1, total_rows - 1); ++i) {
            for (int j = max(col - 1, 0); j <= min(col + 1, total_cols - 1); ++j) {
                sum += imageMatrix[i][j];
                count++;
            }
        }

        return sum / count;
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        imageMatrix = img;
        total_rows = img.size();
        total_cols = img[0].size();

        vector<vector<int>> smoothedImage(total_rows, vector<int>(total_cols));

        for (int row = 0; row < total_rows; ++row) {
            for (int col = 0; col < total_cols; ++col) {
                if (row > 0 && row < total_rows - 1 && col > 0 && col < total_cols - 1) {
                    smoothedImage[row][col] = calculate3X3sum(row, col) / 9;
                } else {
                    smoothedImage[row][col] = calculateBorderAvg(row, col);
                }
            }
        }

        return smoothedImage;
    }

};
```
## Problem Solution Explanation

Here's a detailed, line-by-line explanation of the code you provided:

```cpp
#include <iostream>
#include <vector>
using namespace std;
```
- **Includes necessary headers**: `iostream` for input/output operations and `vector` for using the `vector` container.
- **`using namespace std;`**: Avoids the need to prefix standard library names with `std::`.

```cpp
class Solution {
public:
    vector<vector<int>> imageMatrix;
    int total_rows, total_cols;
```
- **`class Solution {`**: Begins the definition of the `Solution` class.
- **`public:`**: Access specifier indicating that the following members are accessible from outside the class.
- **`vector<vector<int>> imageMatrix;`**: A 2D vector to store the image matrix.
- **`int total_rows, total_cols;`**: Variables to store the number of rows and columns in the image matrix.

```cpp
    int calculate3X3sum(int row, int col) {
        int total_sum = 0;
```
- **`int calculate3X3sum(int row, int col)`**: Defines a method to calculate the sum of the 3x3 grid centered at `(row, col)`.
- **`int total_sum = 0;`**: Initializes a variable to accumulate the sum of pixel values.

```cpp
        for (int i = row - 1; i <= row + 1; ++i) {
            for (int j = col - 1; j <= col + 1; ++j) {
                if (i >= 0 && i < total_rows && j >= 0 && j < total_cols) {
                    total_sum += imageMatrix[i][j];
                }
            }
        }
```
- **`for (int i = row - 1; i <= row + 1; ++i)`**: Loops over the rows from `row - 1` to `row + 1` to cover the 3x3 grid.
- **`for (int j = col - 1; j <= col + 1; ++j)`**: Loops over the columns from `col - 1` to `col + 1`.
- **`if (i >= 0 && i < total_rows && j >= 0 && j < total_cols)`**: Checks if the current indices are within the bounds of the matrix.
- **`total_sum += imageMatrix[i][j];`**: Adds the value of the pixel at `(i, j)` to `total_sum`.

```cpp
        return total_sum;
    }
```
- **`return total_sum;`**: Returns the sum of the 3x3 grid.

```cpp
    int calculateBorderAvg(int row, int col) {
        int sum = 0;
        int count = 0;
```
- **`int calculateBorderAvg(int row, int col)`**: Defines a method to calculate the average of pixel values for border or corner pixels.
- **`int sum = 0;`**: Initializes a variable to accumulate the sum of pixel values.
- **`int count = 0;`**: Initializes a variable to count the number of valid pixels.

```cpp
        for (int i = max(row - 1, 0); i <= min(row + 1, total_rows - 1); ++i) {
            for (int j = max(col - 1, 0); j <= min(col + 1, total_cols - 1); ++j) {
                sum += imageMatrix[i][j];
                count++;
            }
        }
```
- **`for (int i = max(row - 1, 0); i <= min(row + 1, total_rows - 1); ++i)`**: Loops over rows, ensuring indices are within bounds.
- **`for (int j = max(col - 1, 0); j <= min(col + 1, total_cols - 1); ++j)`**: Loops over columns, ensuring indices are within bounds.
- **`sum += imageMatrix[i][j];`**: Adds the value of the pixel at `(i, j)` to `sum`.
- **`count++;`**: Increments the count of valid pixels.

```cpp
        return sum / count;
    }
```
- **`return sum / count;`**: Returns the average value of the border or corner pixel.

```cpp
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        imageMatrix = img;
        total_rows = img.size();
        total_cols = img[0].size();
```
- **`vector<vector<int>> imageSmoother(vector<vector<int>>& img)`**: Defines the method to smooth the image.
- **`imageMatrix = img;`**: Stores the input image matrix.
- **`total_rows = img.size();`**: Sets `total_rows` to the number of rows in the image.
- **`total_cols = img[0].size();`**: Sets `total_cols` to the number of columns in the image.

```cpp
        vector<vector<int>> smoothedImage(total_rows, vector<int>(total_cols));
```
- **`vector<vector<int>> smoothedImage(total_rows, vector<int>(total_cols));`**: Initializes a 2D vector to store the smoothed image.

```cpp
        for (int row = 0; row < total_rows; ++row) {
            for (int col = 0; col < total_cols; ++col) {
                if (row > 0 && row < total_rows - 1 && col > 0 && col < total_cols - 1) {
                    smoothedImage[row][col] = calculate3X3sum(row, col) / 9;
                } else {
                    smoothedImage[row][col] = calculateBorderAvg(row, col);
                }
            }
        }
```
- **`for (int row = 0; row < total_rows; ++row)`**: Loops through each row of the image.
- **`for (int col = 0; col < total_cols; ++col)`**: Loops through each column of the image.
- **`if (row > 0 && row < total_rows - 1 && col > 0 && col < total_cols - 1)`**: Checks if the current pixel is an interior pixel (not on the edge).
- **`smoothedImage[row][col] = calculate3X3sum(row, col) / 9;`**: Sets the value of the smoothed image to the average of the 3x3 grid centered on the pixel.
- **`else`**: If the pixel is on the edge or corner.
- **`smoothedImage[row][col] = calculateBorderAvg(row, col);`**: Sets the value of the smoothed image to the average of the valid neighbors.

```cpp
        return smoothedImage;
    }
};
```
- **`return smoothedImage;`**: Returns the smoothed image matrix.

```cpp
int main() {
    Solution sol;
    vector<vector<int>> img = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int>> result = sol.imageSmoother(img);

    // Print the result
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
```
- **`int main() {`**: Entry point of the program.
- **`Solution sol;`**: Creates an instance of the `Solution` class.
- **`vector<vector<int>> img = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};`**: Initializes a sample image matrix.
- **`vector<vector<int>> result = sol.imageSmoother(img);`**: Calls the `imageSmoother` method and stores the result.
- **`for (const auto& row : result) {`**: Loops through each row of the smoothed image.
- **`for (int val : row) {`**: Loops through each value in the row.
- **`cout << val << " ";`**: Prints the value.
- **`cout << endl;`**: Moves to the next line after printing a row.
- **`return 0;`**: Returns 0 to indicate successful execution.

### Time Complexity

1. **`calculate3X3sum` Function**:
   - The function iterates over a 3x3 grid centered at `(row, col)`, which has a constant number of operations, specifically 9 iterations.
   - The time complexity of this function is \(O(1)\) because the number of operations does not depend on the size of the input matrix.

2. **`calculateBorderAvg` Function**:
   - This function also iterates over a grid of size up to 3x3, but it only considers valid cells, which means the number of iterations is bounded by a constant.
   - The time complexity of this function is \(O(1)\) for the same reason as above.

3. **`imageSmoother` Function**:
   - The function iterates over every cell in the `img` matrix. For each cell, it either calculates the 3x3 sum or the border average.
   - The time complexity of iterating through all cells is \(O(n \cdot m)\), where \(n\) is the number of rows and \(m\) is the number of columns of the matrix.
   - Since both `calculate3X3sum` and `calculateBorderAvg` functions are \(O(1)\), they do not affect the overall time complexity.

Combining these, the total time complexity of the `imageSmoother` function is \(O(n \cdot m)\).

### Space Complexity

1. **Space for `imageMatrix` and `smoothedImage`**:
   - Both `imageMatrix` and `smoothedImage` are 2D vectors with dimensions \(n \times m\).
   - The space complexity for storing these matrices is \(O(n \cdot m)\).

2. **Auxiliary Space**:
   - The `calculate3X3sum` and `calculateBorderAvg` functions use a few additional variables (`total_sum`, `sum`, `count`, etc.), but these are constants with respect to the input size.
   - Therefore, the auxiliary space complexity is \(O(1)\).

Combining these, the total space complexity is dominated by the storage of the input matrix and the smoothed matrix, which is \(O(n \cdot m)\).

### Summary

- **Time Complexity**: \(O(n \cdot m)\)
- **Space Complexity**: \(O(n \cdot m)\)

Here, \(n\) is the number of rows and \(m\) is the number of columns in the image matrix. The time complexity is linear in the number of pixels in the image, and the space complexity is also linear in the number of pixels due to the need to store the smoothed image.
