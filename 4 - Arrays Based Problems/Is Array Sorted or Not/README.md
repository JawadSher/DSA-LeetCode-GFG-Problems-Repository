# Source Code Explanation

This program demonstrates how to check if an array is sorted in ascending order, descending order, or is unordered.

1.  **Include Necessary Headers**:
    
    -   `#include<iostream>`: This header file is included for input and output operations.
2.  **Function Definition**:
    
    -   `void check_sorting(int arr[], int s)`: This function takes two parameters:
        -   `int arr[]`: The array to be checked.
        -   `int s`: The size of the array.
    -   `bool isSorted = true;`: Initialize a boolean variable `isSorted` to `true`. This variable will keep track of whether the array is sorted.
    -   `string order = "";`: Initialize a string variable `order` to store the order of the array.
3.  **Check Array Size**:
    
    -   `if (s < 2)`: Check if the size of the array is less than 2.
        -   `isSorted = true;`: Set `isSorted` to `true`.
        -   `order = "Array is too small to determine order";`: Set `order` to "Array is too small to determine order".
4.  **Check Sorting Order**:
    
    -   `else`: If the array size is 2 or more:
        -   `bool Ascending = true;`: Initialize a boolean variable `Ascending` to `true`.
        -   `bool Descending = true;`: Initialize a boolean variable `Descending` to `true`.
        -   `for(int i = 1; i < s; i++)`: A `for` loop that iterates from index `1` to `s-1`.
            -   `if(arr[i] < arr[i-1])`: Check if the current element is less than the previous element.
                -   `Ascending = false;`: If true, set `Ascending` to `false`.
            -   `if(arr[i] > arr[i-1])`: Check if the current element is greater than the previous element.
                -   `Descending = false;`: If true, set `Descending` to `false`.
        -   `if(Ascending)`: If `Ascending` is still `true` after the loop:
            -   `order = "Ascending Order";`: Set `order` to "Ascending Order".
        -   `else if(Descending)`: If `Descending` is still `true` after the loop:
            -   `order = "Descending Order";`: Set `order` to "Descending Order".
        -   `else`: If neither `Ascending` nor `Descending` is `true`:
            -   `order = "Un-ordered Array";`: Set `order` to "Un-ordered Array".
            -   `isSorted = false;`: Set `isSorted` to `false`.
              
5.  **Print Results**:
    
    -   `string sorted = isSorted ? "True" : "False";`: Create a string `sorted` which is "True" if `isSorted` is `true`, otherwise "False".
    -   `cout << "Order: " << order << "\n" << "Status: " << sorted << endl;`: Print the order and status of the array.
      

```
		int main() {
	    int my_array_1[] = {10, 20, 30, 40, 50, 60};
	    int my_array_2[] = {60, 50, 40, 30, 20, 10};
	    int my_array_3[] = {60, 30, 50, 40, 20, 10};
	    int size = 6;
	    
	    cout<<"-----> First Array <-----"<<endl;
	    check_sorting(my_array_1, size);
	    cout<<endl;
	    cout<<"-----> Second Array <-----"<<endl;
	    check_sorting(my_array_2, size);
	    cout<<endl;
	    cout<<"-----> Third Array <-----"<<endl;
	    check_sorting(my_array_3, size);
	    return 0;
	}
```

6.  **Main Function**:
    -   `int my_array_1[] = {10, 20, 30, 40, 50, 60};`: Initialize the first array with elements in ascending order.
    -   `int my_array_2[] = {60, 50, 40, 30, 20, 10};`: Initialize the second array with elements in descending order.
    -   `int my_array_3[] = {60, 30, 50, 40, 20, 10};`: Initialize the third array with unordered elements.
    -   `int size = 6;`: Define the size of the arrays.
    -   `cout<<"-----> First Array <-----"<<endl; check_sorting(my_array_1, size);`: Print header and check the order of the first array.
    -   `cout<<"-----> Second Array <-----"<<endl; check_sorting(my_array_2, size);`: Print header and check the order of the second array.
    -   `cout<<"-----> Third Array <-----"<<endl; check_sorting(my_array_3, size);`: Print header and check the order of the third array.

## Example Output

When you run this program, it will output:

	```
	-----> First Array <-----
	Order: Ascending Order
	Status: True

	-----> Second Array <-----
	Order: Descending Order
	Status: True

	-----> Third Array <-----
	Order: Un-ordered Array
	Status: False
	``` 

This is because:

-   The first array is in ascending order.
-   The second array is in descending order.
-   The third array is unordered.

### Key Points

-   This implementation uses a linear approach with a time complexity of O(n).
-   The function checks the order of the array by comparing each element with its previous element.
-   It handles arrays with less than 2 elements by indicating they are too small to determine order.
