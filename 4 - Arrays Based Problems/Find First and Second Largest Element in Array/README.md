# Source Code Explanation

1.  **Include Necessary Headers**:
    
    -   `#include<iostream>`: This header file is included for input and output operations.
2.  **Function Definition**:
    
    -   `void sec_element(int arr[], int s)`: This function takes two parameters:
        -   `int arr[]`: The array of integers.
        -   `int s`: The size of the array.
    -   `int first_element = 0;`: Initialize a variable `first_element` to `0`, which will hold the largest element found in the array.
    -   `int sec_element = 0;`: Initialize a variable `sec_element` to `0`, which will hold the second largest element found in the array.
    -   `for(int i = 0; i < s; i++)`: A `for` loop that iterates from `0` to `s-1`.
        -   `if(arr[i] > first_element)`: Check if the current element of the array is greater than `first_element`.
            -   `sec_element = first_element;`: If true, assign the value of `first_element` to `sec_element`.
            -   `first_element = arr[i];`: Then assign the value of the current element to `first_element`.
    -   `cout<<"The First Largest Element is : "<<first_element<<endl;`: Print the largest element found in the array.
    -   `cout<<"The second Largest Element is : "<<sec_element;`: Print the second largest element found in the array.


  ```
  int main(){
      int my_array[] = {10, 20, 30, 40, 50, -50};
      int size = sizeof(my_array) / sizeof(int);
      sec_element(my_array, size);
  }
  ``` 

3.  **Main Function**:
    -   `int my_array[] = {10, 20, 30, 40, 50, -50};`: Initialize an array `my_array` with some integer elements.
    -   `int size = sizeof(my_array) / sizeof(int);`: Calculate the size of the array by dividing the total size of the array (`sizeof(my_array)`) by the size of one element (`sizeof(int)`).
    -   `sec_element(my_array, size);`: Call the `sec_element` function with the array and its size as arguments to find and print the first and second largest elements in the array.

### Explanation

1.  **Initialize Variables**:
    
    -   The `sec_element` function initializes two variables: `first_element` and `sec_element`, both set to `0`. These variables will hold the largest and second largest elements found in the array.
2.  **Find Largest and Second Largest Elements**:
    
    -   The `for` loop iterates through each element of the array.
    -   For each element, the condition `if(arr[i] > first_element)` checks if the current element is greater than `first_element`.
    -   If the condition is true, the value of `first_element` is assigned to `sec_element`, and the current element is assigned to `first_element`. This ensures that `first_element` always holds the largest element encountered so far, and `sec_element` holds the second largest.
3.  **Print Results**:
    
    -   After the loop completes, the largest and second largest elements are printed to the console.

## Example Output

When you run this program, it will output:

`The First Largest Element is : 50`

`The second Largest Element is : 40` 

because `50` is the largest element in the array and `40` is the second largest.

### Key Points

-   This implementation uses a linear approach with a time complexity of O(n).
-   The array is traversed once, making the process efficient.
-   The use of two variables (`first_element` and `sec_element`) helps in keeping track of the largest and second largest elements found during the traversal.
