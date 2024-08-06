# Source Code Explanation

### Sorting an Array Using a Brute Force Method

This C++ program sorts an array of integers by manually finding the smallest element in the unsorted part of the array and swapping it with the current element.

#### Code Breakdown

1.  **Sorting Function (`sort_array`)**
    
    -   This function takes an array `arr` and its size `n` as parameters.
    -   It uses two nested loops to sort the array:
        -   The outer loop iterates over each element of the array except the last one (`for(int i = 0; i < n-1; i++)`). This loop ensures that each element gets its correct position.
        -   The inner loop starts from the element right after the current element of the outer loop and iterates to the end of the array (`for(int k = i+1; k < n; k++)`). It searches for the smallest element in the unsorted part of the array.
        -   If a smaller element is found (`if(arr[k] < arr[i])`), it swaps the current element of the outer loop with this smaller element. This ensures that the smallest element is moved to the correct position.
        -   The swapping is done using a temporary variable `temp`.
    
  <hr> 
  
  ```
    void sort_array(int arr[], int n){
        for(int i = 0; i < n-1; i++){
            for(int k = i+1; k < n; k++){
                if(arr[k] < arr[i]){
                    int temp = arr[i];
                    arr[i] = arr[k];
                    arr[k] = temp;
                }
            }
        }
    }
  ``` 
    
2.  **Main Function (`main`)**
    
    -   It defines an array `new_array` containing unsorted integers.
    -   It calls the `sort_array` function to sort the array.
    -   It prints the sorted array by iterating through it and outputting each element.

<hr>

  ```
    int main(){
        int new_array[8] = {1, 3, 2, 5, 7, 4, 8, 6};
        sort_array(new_array, 8);
        
        for(int i = 0; i < 8; i++){
            cout << new_array[i] << " ";
        }
        
        return 0;
    }
  ``` 
    

### How the Brute Force Method Works

1.  **Initialization**:
    
    -   The array `new_array` is initialized with the elements `{1, 3, 2, 5, 7, 4, 8, 6}`.
2.  **Outer Loop** (`for(int i = 0; i < n-1; i++)`):
    
    -   This loop runs `n-1` times, ensuring each element is correctly positioned.
    -   With each iteration, it considers the element at index `i` and finds the smallest element in the remaining unsorted part of the array.
3.  **Inner Loop** (`for(int k = i+1; k < n; k++)`):
    
    -   This loop finds the minimum element in the unsorted part of the array (from index `i+1` to `n-1`).
4.  **Swapping**:
    
    -   If a smaller element is found (`if(arr[k] < arr[i])`), the elements at indices `i` and `k` are swapped using a temporary variable `temp`.

### Example Walkthrough

Given the initial array `{1, 3, 2, 5, 7, 4, 8, 6}`:

-   **First Pass** (`i = 0`):
    -   The outer loop starts with `i = 0`.
    -   The inner loop finds that `1` is already the smallest element in the range `[1, 3, 2, 5, 7, 4, 8, 6]`.
    -   No swap is needed.
-   **Second Pass** (`i = 1`):
    -   The outer loop moves to `i = 1`.
    -   The inner loop finds that `2` is the smallest element in the range `[3, 2, 5, 7, 4, 8, 6]`.
    -   `3` and `2` are swapped. The array becomes `{1, 2, 3, 5, 7, 4, 8, 6}`.
-   **Third Pass** (`i = 2`):
    -   The outer loop moves to `i = 2`.
    -   The inner loop finds that `3` is already the smallest element in the range `[3, 5, 7, 4, 8, 6]`.
    -   No swap is needed.

This process continues until the entire array is sorted.

## Example Output

After sorting the array, the program prints the sorted array:

`1 2 3 4 5 6 7 8` 

### Conclusion

This brute force sorting method is simple and effective for small datasets. It has a time complexity of O(n2)O(n^2)O(n2), where nnn is the number of elements in the array. While not efficient for large datasets, it serves as a good educational example of basic sorting techniques.

Feel free to add this explanation as a README file or as comments in your code on GitHub to help viewers understand the functionality and logic behind your brute force sorting algorithm.
