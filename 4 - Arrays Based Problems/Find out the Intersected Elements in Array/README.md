# Source Code Explanation

#### `intersection` Function


```
void intersection(int arr[], int arr1[], int n){
    vector<int> intersected_elements;
    
    int i = 0;
    int j = 0;
    
    while(i < n && j < n){
        if(arr[i] == arr1[j]){
            intersected_elements.push_back(arr[i]);
            i++;
            j++;
        } else if(arr[i] < arr1[j]){
            i++;
        } else {
            j++;
        }
    }
    
    cout<<"Intersected Elements are : ";
    for(auto elements : intersected_elements){
        cout<<elements<<" ";
    }
}
``` 

-   **Purpose**: This function finds the intersection of two sorted integer arrays `arr` and `arr1` of size `n`. It uses a two-pointer technique to efficiently find common elements between the arrays.
    
-   **Variables**:
    
    -   `intersected_elements`: A vector that stores elements common to both arrays.
    -   `i` and `j`: Pointers for iterating through `arr` and `arr1` respectively.
-   **Algorithm**:
    
    -   Initialize `i` and `j` to `0`.
    -   Use a while loop to iterate through both arrays while `i` and `j` are within bounds (`i < n` and `j < n`).
    -   Compare elements at `arr[i]` and `arr1[j]`:
        -   If they are equal (`arr[i] == arr1[j]`), add `arr[i]` (or `arr1[j]`, since they are equal) to `intersected_elements`, then increment both `i` and `j`.
        -   If `arr[i]` is less than `arr1[j]`, increment `i` to move to the next element in `arr`.
        -   If `arr[i]` is greater than `arr1[j]`, increment `j` to move to the next element in `arr1`.
    -   After exiting the loop, `intersected_elements` contains all elements common to both arrays.
-   **Output**:
    
    -   Print the intersected elements stored in `intersected_elements` using a range-based for loop.

#### `main` Function


```
int main(){
    int new_array[5] = {1, 2, 2, 3, 4};
    int new_array1[5] = {2, 2, 3, 3, 6};
    
    intersection(new_array, new_array1, 5);
    
    return 0;
}
``` 

-   **Purpose**: The `main` function demonstrates the usage of the `intersection` function by providing two sorted arrays (`new_array` and `new_array1`) and calling `intersection` to find and print their common elements.
    
-   **Operation**:
    
    -   It initializes two integer arrays `new_array` and `new_array1` with values `{1, 2, 2, 3, 4}` and `{2, 2, 3, 3, 6}` respectively.
    -   It calls the `intersection` function with `new_array`, `new_array1`, and size `5` (number of elements in each array).
    -   The function prints the intersected elements common to both arrays.

### Example Walkthrough

Given the input arrays:

-   `new_array = {1, 2, 2, 3, 4}`
-   `new_array1 = {2, 2, 3, 3, 6}`

The function proceeds as follows:

-   Initialize `i` and `j` to `0`.
-   Compare `arr[0]` (which is `1`) and `arr1[0]` (which is `2`): `1` is less than `2`, so increment `i`.
-   Compare `arr[1]` (which is `2`) and `arr1[0]` (which is `2`): They are equal, so add `2` to `intersected_elements` and increment both `i` and `j`.
-   Continue this process until both arrays are fully traversed.

After completing the intersection process, the `intersected_elements` vector will contain `{2, 2, 3}`.

## Example Output

The program will print:

`Intersected Elements are : 2 2 3` 

This indicates that `2` and `3` are the elements common to both `new_array` and `new_array1`.

### Conclusion

The provided C++ code effectively finds and prints the intersection of two sorted integer arrays using a two-pointer technique. It ensures that the solution is efficient with a time complexity of O(n)O(n)O(n), where nnn is the size of the arrays. This method is optimal for sorted arrays and provides a clear and concise way to determine common elements between two datasets.
