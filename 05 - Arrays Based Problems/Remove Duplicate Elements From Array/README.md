# Source Code Explanation

This program removes duplicate elements from an array and prints the array without duplicates.

1.  **Include Necessary Headers**:
    
    -   `#include<iostream>`: This header file is included for input and output operations.
2.  **Function Definition - `r_duplicate`**:
    
    -   `void r_duplicate(int arr[], int s)`: This function takes two parameters:
        -   `int arr[]`: The original array from which duplicates are to be removed.
        -   `int s`: The size of the original array.
    -   `int temp_array[s];`: Declare a temporary array `temp_array` to store unique elements. It's sized to be the same as the original array.
    -   `int new_size = 0;`: Initialize `new_size` to `0`, which will track the number of unique elements found.
3.  **Removing Duplicates**:
    
    -   The function uses a nested loop structure:
        -   Outer loop (`for(int i = 0; i < s; i++)`): Iterates through each element of the original array.
        -   Inner loop (`for(int j = 0; j < new_size; j++)`): Checks if the current element (`arr[i]`) already exists in `temp_array`.
            -   If a duplicate is found (`if(arr[i] == temp_array[j])`), `isDuplicate` is set to `true`, and the inner loop breaks.
        -   If the element is not a duplicate (`if(!isDuplicate)`), it is added to `temp_array` at index `new_size`, and then `new_size` is incremented (`temp_array[new_size++] = arr[i];`).
4.  **Create and Populate New Array**:
    
    -   After identifying unique elements, a new array `new_array` is declared with size `new_size`.
    -   Elements from `temp_array` are copied to `new_array` using a simple loop (`for(int i = 0; i < new_size; i++)`).
5.  **Print Array Without Duplicates**:
    
    -   Another loop (`for(int i = 0; i < new_size; i++)`) iterates through `new_array` to print each unique element.
6.  **Main Function**:
    
    -   `int my_array[] = {10, 20, 30, 40, 50, 10, 60};`: Initialize an array `my_array` with some integer elements, including duplicates.
    -   `int size = sizeof(my_array) / sizeof(int);`: Calculate the size of the array by dividing the total size of the array (`sizeof(my_array)`) by the size of one element (`sizeof(int)`).
    -   Print the original array elements before removing duplicates (`cout << "Before Remove Duplicates" << endl;` and the corresponding loop).
    -   Print a blank line for clarity (`cout << endl << endl;`).
    -   Print a header indicating the array after removing duplicates (`cout << "After Remove Duplicates" << endl;`).
    -   Call `r_duplicate(my_array, size);` to remove duplicates and print the unique elements.

## Example Output

When you run this program, it will output:

```
Before Remove Duplicates
10 20 30 40 50 10 60 

After Remove Duplicates
10 20 30 40 50 60
``` 

This is because the function `r_duplicate` removes the duplicate `10` from `my_array`, resulting in `10 20 30 40 50 60` being printed as the array without duplicates.

### Key Points

-   This implementation uses a linear approach to remove duplicates, iterating through the array once, resulting in a time complexity of O(n).
-   It maintains order and preserves the first occurrence of each unique element.
-   The function uses a temporary array to track unique elements before copying them to a new array of the correct size for output.
