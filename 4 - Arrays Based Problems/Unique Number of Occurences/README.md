# Source Code Explanation

#### Sorting Function (`sort_function`)

```
void sort_function(int arr[], int n){
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

-   **Purpose**: This function sorts an integer array `arr` of size `n` in ascending order using a brute force approach similar to Selection Sort.
-   **Operation**:
    -   It iterates through the array using two nested loops.
    -   The outer loop (`i`) runs from `0` to `n-1`, ensuring each element is considered for its correct position.
    -   The inner loop (`k`) starts from `i+1` to `n`, comparing each element with the current element (`arr[i]`).
    -   If an element (`arr[k]`) is smaller than `arr[i]`, they are swapped to ensure `arr[i]` contains the smallest element in the remaining unsorted part.
    -   This process continues until the array is sorted.

#### Unique Occurrences Function (`unique_occurences`)

```
bool unique_occurences(int arr[], int n){
    bool unique_occurences = true;
    int new_arr[100] = {0};
    
    // Count occurrences of each element in arr
    for(int i = 0; i < n; i++){
        new_arr[arr[i] + 50]++;
    }
    
    // Sort new_arr using sort_function
    sort_function(new_arr, 100);
    
    // Check if any element has non-unique occurrences
    for(int i = 0; i < 99; i++){
        if(new_arr[i] != 0 && new_arr[i] == new_arr[i+1]){
            unique_occurences = false;
            break;
        }
    }
    
    return unique_occurences;
}
``` 

-   **Purpose**: This function checks if all elements in the input array `arr` have unique occurrences.
-   **Operation**:
    -   It initializes a boolean variable `unique_occurrences` to `true`, assuming initially that all elements have unique occurrences.
    -   It declares an integer array `new_arr` of size `100` and initializes all elements to `0`. This array is used to count occurrences of each element from `arr`.
    -   It iterates through `arr`, incrementing the corresponding index in `new_arr` (adjusted by adding `50` to handle negative indices) for each occurrence of an element.
    -   It sorts `new_arr` using the `sort_function` to arrange the occurrence counts in ascending order.
    -   It then checks `new_arr` to ensure that no two consecutive elements (except zeros) have the same value. If it finds any consecutive non-zero elements with the same value, it sets `unique_occurrences` to `false`.
    -   Finally, it returns the value of `unique_occurrences`.

#### Main Function

```
int main(){
    int new_array[6] = {1, 2, 2, 1, 1, 3};
    bool status = unique_occurences(new_array, 6);
    
    if(status){
        cout << "Unique Occurrences";
    }else{
        cout << "Duplicate Occurrences";
    }
    
    return 0;
}
``` 

-   **Purpose**: The `main` function demonstrates the usage of `unique_occurences` function by checking if the elements in `new_array` have unique occurrences or not.
-   **Operation**:
    -   It initializes an integer array `new_array` with `{1, 2, 2, 1, 1, 3}`.
    -   It calls `unique_occurences` function with `new_array` and size `6` (number of elements in `new_array`).
    -   It stores the returned boolean status (`true` or `false`) in `status`.
    -   Based on the value of `status`, it prints `"Unique Occurrences"` if all elements have unique occurrences, otherwise it prints `"Duplicate Occurrences"`.

### Example Walkthrough

Given the input array `new_array = {1, 2, 2, 1, 1, 3}`:

-   **Counting Occurrences**:
    
    -   `new_arr` will be populated based on the occurrences of each element:
        -   `new_arr[51] = 3` (for element `1`)
        -   `new_arr[52] = 2` (for element `2`)
        -   `new_arr[53] = 1` (for element `3`)
        -   Other elements in `new_arr` remain `0`.
-   **Sorting `new_arr`**:
    
    -   After sorting, `new_arr` might look like `{0, 0, 0, ..., 0, 1, 2, 3}` (depending on the input).
-   **Checking Unique Occurrences**:
    
    -   The function checks if any two consecutive non-zero elements in `new_arr` have the same value.
    -   In this case, `new_arr[51] = 3` and `new_arr[52] = 2`, which are not consecutive.
    -   Hence, `unique_occurences` will be `true`, indicating that all elements in `new_array` have unique occurrences.

## Example Output

Based on the input array `{1, 2, 2, 1, 1, 3}`, the program will output:


`Duplicate Occurrences` 

This indicates that not all elements in `new_array` have unique occurrences.

### Conclusion

The provided code effectively uses a brute force approach to determine if all elements in an array have unique occurrences. It utilizes array indexing and sorting to count occurrences and validate uniqueness, providing a clear and structured approach to solve the problem.
