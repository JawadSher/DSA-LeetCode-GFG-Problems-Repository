# Source Code Explanation

### Headers and Namespace

```
#include<iostream>
using namespace std;
``` 

-   **`#include<iostream>`**: This directive includes the standard input-output stream library, which provides the functionality for input and output operations.
-   **`using namespace std;`**: This line allows us to use standard library features (like `cout` and `cin`) without needing to prefix them with `std::`.

### First Occurrence Function

```
int first_occurence(int arr[], int n, int k) {
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    int index = -1;
    
    while (start <= end) {
        if (arr[mid] == k) {
            index = mid;
            end = mid - 1;
        } else if (k < arr[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return index;
}
``` 

-   **Parameters**:
    -   `arr[]`: The array to search.
    -   `n`: The size of the array.
    -   `k`: The key to search for.
-   **Variables**:
    -   `start`: The starting index of the search range, initialized to `0`.
    -   `end`: The ending index of the search range, initialized to `n - 1`.
    -   `mid`: The middle index of the current search range, calculated as `start + (end - start) / 2`.
    -   `index`: Variable to store the index of the first occurrence of the key `k`, initialized to `-1` (indicating not found).
-   **Logic**:
    -   The `while` loop continues as long as `start` is less than or equal to `end`.
    -   If the middle element `arr[mid]` equals the key `k`, the index is updated to `mid`, and `end` is moved to `mid - 1` to continue searching in the left half for any earlier occurrence.
    -   If the key `k` is less than `arr[mid]`, the search range is moved to the left half by updating `end` to `mid - 1`.
    -   If the key `k` is greater than `arr[mid]`, the search range is moved to the right half by updating `start` to `mid + 1`.
    -   The middle index `mid` is recalculated in each iteration.
    -   If the key is not found, the function returns `-1`.

### Main Function


```
int main() {
    int new_array[] = {10, 20, 30, 30, 30, 40, 50, 60, 70};
    int size = sizeof(new_array) / sizeof(int);
    int key = 30;
    
    int occurrence = first_occurence(new_array, size, key);
    cout << "The First Occurrence is at Index " << occurrence << " for Value " << key;
    
    return 0;
}
``` 

-   **Array Declaration**:
    -   `new_array[]`: An array of integers initialized with `{10, 20, 30, 30, 30, 40, 50, 60, 70}`.
    -   `size`: The number of elements in `new_array`, calculated by dividing the total byte size of `new_array` by the byte size of an integer.
-   **Key Declaration**:
    -   `key`: The value to search for in the array, with a value of `30`.
-   **Function Call**:
    -   `first_occurence(new_array, size, key)`: Calls the function to find the first occurrence of the key (`30`) in `new_array` and stores the result in `occurrence`.
-   **Output**:
    -   Prints the index of the first occurrence of the key `30` using `cout`.

## Example Output

`The First Occurrence is at Index 2 for Value 30` 

## How to Use

1.  **Copy the code**: Copy the provided code into your C++ development environment (e.g., a file named `first_occurrence.cpp`).
2.  **Compile the code**: Use a C++ compiler to compile the code. For example, using g++:
    
   
    
    `g++ -o first_occurrence first_occurrence.cpp` 
    
3.  **Run the executable**: Execute the compiled program:
    

    
    `./first_occurrence` 
    
4.  **See the output**: The program will output the index of the first occurrence of the specified key in the array.
