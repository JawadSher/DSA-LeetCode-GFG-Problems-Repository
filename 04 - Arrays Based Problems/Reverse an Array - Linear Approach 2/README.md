# Source Code Explanation

This program demonstrates how to reverse an array by creating a new array and filling it with elements from the original array in reverse order.

```
#include<iostream>
using namespace std;

void reverse_arr(int arr[], int s){
    int reverse_array[s];
    for(int i = 0; i < s; i++){
        reverse_array[i] = arr[s - i - 1];
    }
    
    for(int i = 0; i < s; i++){
        cout<<reverse_array[i]<<" ";
    }
}
``` 

1.  **Include Necessary Headers**:
    
    -   `#include<iostream>`: This header file is included for input and output operations.
2.  **Function Definition**:
    
    -   `void reverse_arr(int arr[], int s)`: This function takes two parameters:
        -   `int arr[]`: The original array to be reversed.
        -   `int s`: The size of the array.
    -   `int reverse_array[s];`: Declare a new array `reverse_array` with the same size `s` as the original array.
    -   `for(int i = 0; i < s; i++)`: A `for` loop that iterates from `0` to `s-1`.
        -   `reverse_array[i] = arr[s - i - 1];`: In each iteration, assign the element from the original array in reverse order to the new array. The element at index `i` of the new array is assigned the value from index `s - i - 1` of the original array.
    -   `for(int i = 0; i < s; i++)`: Another `for` loop that iterates from `0` to `s-1`.
        -   `cout<<reverse_array[i]<<" ";`: Print each element of the new reversed array followed by a space.


```
int main(){
    int my_array[] = {10, 20, 30, 40, 50, -50, -60};
    int size = sizeof(my_array) / sizeof(int);
    reverse_arr(my_array, size);
}
``` 

3.  **Main Function**:
    -   `int my_array[] = {10, 20, 30, 40, 50, -50, -60};`: Initialize an array `my_array` with some integer elements.
    -   `int size = sizeof(my_array) / sizeof(int);`: Calculate the size of the array by dividing the total size of the array (`sizeof(my_array)`) by the size of one element (`sizeof(int)`).
    -   `reverse_arr(my_array, size);`: Call the `reverse_arr` function with the original array and its size as arguments to reverse the array and print the reversed array.

### Explanation

1.  **Initialize New Array**:
    
    -   The `reverse_arr` function declares a new array `reverse_array` with the same size as the original array.
2.  **Fill New Array in Reverse Order**:
    
    -   The first `for` loop iterates through each index `i` of the new array.
    -   For each index `i`, the corresponding element from the original array at index `s - i - 1` is assigned to `reverse_array[i]`.
3.  **Print Reversed Array**:
    
    -   The second `for` loop iterates through each index `i` of the new array.
    -   Each element of the new array is printed to the console followed by a space.

## Example Output

When you run this program, it will output:


`-60 -50 50 40 30 20 10` 

because the array has been reversed.

### Key Points

-   This implementation uses a linear approach with a time complexity of O(n).
-   The original array is traversed once to create the reversed array and once more to print the elements.
-   The new array `reverse_array` is used to store the elements in reverse order, making the process straightforward and easy to understand.
