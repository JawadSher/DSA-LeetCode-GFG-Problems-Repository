# Source Code Explanation

This program demonstrates a simple linear search algorithm to check if an element is present in an array.

```
#include<iostream>
#include<climits>
using namespace std;
``` 

1.  **Include Necessary Headers**:
    -   `#include<iostream>`: This header file is included for input and output operations.
    -   `#include<climits>`: This header file is included for defining the limits of integral types.



```
bool findElement(int arr[], int n, int element){
    bool isPresent = false;  
    for(int i = 0; i < n; i++){
        if(element == arr[i]){  
            isPresent = true;  
            break;  
        }
    }
    return isPresent;  
}
``` 

2.  **Function Definition**:
    -   `bool findElement(int arr[], int n, int element)`: This is a function that takes three parameters:
        -   `int arr[]`: An array of integers where we will search for the element.
        -   `int n`: The size of the array.
        -   `int element`: The element we are searching for in the array.
    -   `bool isPresent = false;`: Initialize a boolean variable `isPresent` to `false`. This variable will keep track of whether the element is found in the array.
    -   `for(int i = 0; i < n; i++)`: A `for` loop that iterates from `0` to `n-1`, checking each element of the array.
        -   `if(element == arr[i])`: Inside the loop, check if the current element of the array (`arr[i]`) is equal to the target element (`element`).
            -   `isPresent = true;`: If the target element is found, set `isPresent` to `true`.
            -   `break;`: Exit the loop since we have found the element.
    -   `return isPresent;`: Return the value of `isPresent`. It will be `true` if the element was found, otherwise `false`.

  ```
  int main(){
      int my_arr[] = {10, 20, 30, -50, -30, 100, 1000};  // Initialize the array
      int size = sizeof(my_arr)/sizeof(int);  // Calculate the size of the array
      
      int target_element = 100;  
      bool Status = findElement(my_arr, size, target_element); 
      string output = (Status) ? "Element is Present" : "Element is Absent";
      cout<<output; 
    
      return 0;
  }
  ``` 

3.  **Main Function**:
    -   `int my_arr[] = {10, 20, 30, -50, -30, 100, 1000};`: Initialize an array `my_arr` with some integer elements.
    -   `int size = sizeof(my_arr)/sizeof(int);`: Calculate the size of the array by dividing the total size of the array (`sizeof(my_arr)`) by the size of one element (`sizeof(int)`).
    -   `int target_element = 100;`: Define the target element (`100`) that we want to search for in the array.
    -   `bool Status = findElement(my_arr, size, target_element);`: Call the `findElement` function with the array, its size, and the target element as arguments. Store the result (true or false) in the `Status` variable.
    -   `string output = (Status) ? "Element is Present" : "Element is Absent";`: Prepare the output message based on the result. If `Status` is `true`, the message will be "Element is Present". Otherwise, it will be "Element is Absent".
    -   `cout<<output;`: Print the output message to the console.
    -   `return 0;`: Return `0` to indicate that the program has executed successfully.

## Example Output

When you run this program, it will output:


`Element is Present` 

because `100` is present in the array.

### Key Points

-   This implementation uses a linear search algorithm, which has a time complexity of O(n).
-   The `for` loop checks each element in the array sequentially until the target element is found or the end of the array is reached.
-   The use of a boolean flag helps in keeping the function simple and readable.
