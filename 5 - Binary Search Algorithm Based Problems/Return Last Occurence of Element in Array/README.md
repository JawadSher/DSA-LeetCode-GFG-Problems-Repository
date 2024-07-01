# Source Code Explanation

### Headers and Namespace

```
#include<iostream>
using namespace std;
``` 

-   **`#include<iostream>`**: This directive includes the standard input-output stream library, which provides the functionality for input and output operations.
-   **`using namespace std;`**: This line allows us to use standard library features (like `cout` and `cin`) without needing to prefix them with `std::`.

### Last Occurrence Function

```
int last_occurence(int arr[], int n, int k) {
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    int index = -1;
    
    while (start <= end) {
        if (arr[mid] == k) {
            index = mid;
            start = mid + 1;
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
    -   `index`: Variable to store the index of the last occurrence of the key `k`, initialized to `-1` (indicating not found).
-   **Logic**:
    -   The `while` loop continues as long as `start` is less than or equal to `end`.
    -   If the middle element `arr[mid]` equals the key `k`, the index is updated to `mid`, and `start` is moved to `mid + 1` to continue searching in the right half for any later occurrence.
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
    
    int occurrence = last_occurence(new_array, size, key);
    cout << "The Last Occurrence is at Index " << occurrence << " for Value " << key;
    
    return 0;
}
``` 

-   **Array Declaration**:
    -   `new_array[]`: An array of integers initialized with `{10, 20, 30, 30, 30, 40, 50, 60, 70}`.
    -   `size`: The number of elements in `new_array`, calculated by dividing the total byte size of `new_array` by the byte size of an integer.
-   **Key Declaration**:
    -   `key`: The value to search for in the array, with a value of `30`.
-   **Function Call**:
    -   `last_occurrence(new_array, size, key)`: Calls the function to find the last occurrence of the key (`30`) in `new_array` and stores the result in `occurrence`.
-   **Output**:
    -   Prints the index of the last occurrence of the key `30` using `cout`.

## Example Output

`The Last Occurrence is at Index 4 for Value 30` 

## How It Works

1.  **Initialization**: Start with `start` at the beginning of the array (`0`) and `end` at the end of the array (`n - 1`).
2.  **Binary Search**:
    -   Calculate `mid` as the middle index of the current range.
    -   Check if `arr[mid]` equals `k`.
        -   If true, update `index` to `mid` (potential last occurrence) and adjust `start` to search for more occurrences to the right.
        -   If `k` is less than `arr[mid]`, adjust `end` to search the left half.
        -   If `k` is greater than `arr[mid]`, adjust `start` to search the right half.
    -   Recalculate `mid` for the next iteration.
3.  **Termination**: The loop continues until `start` exceeds `end`, ensuring all possible occurrences are checked.
4.  **Return**: Finally, return `index`, which holds the index of the last occurrence of `k`, or `-1` if `k` is not found.
