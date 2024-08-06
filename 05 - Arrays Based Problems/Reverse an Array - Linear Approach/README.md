# Source Code Explanation

This program demonstrates how to reverse an array using a linear approach.

```
#include<iostream>
using namespace std;

void reverse_arr(int arr[], int s){
  int start = 0;
  int end = s - 1;
  while(start <= end){
    swap(arr[start], arr[end]);
    start++;
    end--;
    }
}
``` 

1.  **Include Necessary Headers**:
    
    -   `#include<iostream>`: This header file is included for input and output operations.
2.  **Function Definition**:
    
    -   `void reverse_arr(int arr[], int s)`: This function takes two parameters:
        -   `int arr[]`: The array to be reversed.
        -   `int s`: The size of the array.
    -   `int start = 0;`: Initialize a variable `start` to `0`, representing the index of the first element of the array.
    -   `int end = s - 1;`: Initialize a variable `end` to `s - 1`, representing the index of the last element of the array.
    -   `while(start <= end)`: A `while` loop that runs until `start` is less than or equal to `end`.
        -   `swap(arr[start], arr[end]);`: Swap the elements at the `start` and `end` indices.
        -   `start++;`: Increment the `start` index to move towards the middle of the array.
        -   `end--;`: Decrement the `end` index to move towards the middle of the array.


```
int main(){
  int my_array[] = {10, 20, 30, 40, 50, -50, -60};
  int size = sizeof(my_array) / sizeof(int);
  reverse_arr(my_array, size);
	    
  for(int i = 0; i < size; i++){
    cout<<my_array[i]<<" ";
  }
}
``` 

3.  **Main Function**:
    -   `int my_array[] = {10, 20, 30, 40, 50, -50, -60};`: Initialize an array `my_array` with some integer elements.
    -   `int size = sizeof(my_array) / sizeof(int);`: Calculate the size of the array by dividing the total size of the array (`sizeof(my_array)`) by the size of one element (`sizeof(int)`).
    -   `reverse_arr(my_array, size);`: Call the `reverse_arr` function with the array and its size as arguments to reverse the array.
    -   `for(int i = 0; i < size; i++)`: A `for` loop to iterate through the reversed array.
        -   `cout<<my_array[i]<<" ";`: Print each element of the reversed array followed by a space.

### Explanation

1.  **Initialize Pointers**:
    
    -   The `reverse_arr` function initializes two pointers: `start` and `end`, which point to the beginning and the end of the array, respectively.
2.  **Swap Elements**:
    
    -   The `while` loop runs as long as `start` is less than or equal to `end`.
    -   In each iteration of the loop, the elements at the `start` and `end` indices are swapped using the `swap` function.
    -   After swapping, the `start` index is incremented by `1`, and the `end` index is decremented by `1`.
3.  **Reverse Complete**:
    
    -   The loop continues until all elements are swapped, effectively reversing the array.
4.  **Print Reversed Array**:
    
    -   In the `main` function, the `reverse_arr` function is called to reverse the array.
    -   A `for` loop iterates through the reversed array, printing each element to the console.

## Example Output

When you run this program, it will output:


`-60 -50 50 40 30 20 10` 

because the array has been reversed.

### Key Points

-   This implementation uses a linear approach with a time complexity of O(n).
-   The `while` loop ensures that each element is swapped only once, making the process efficient.
-   The `swap` function is used to interchange the values at the `start` and `end` indices.
