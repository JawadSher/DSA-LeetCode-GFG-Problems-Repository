# Source Code Explanation

### Alternate Element Swapping in Arrays

This C++ program demonstrates how to swap adjacent elements in an array. It includes functions to perform the swapping and to print the array. The program handles both even and odd-sized arrays, ensuring that the last element in an odd-sized array remains in its original position.

#### Code Breakdown

1.  **Printing Function (`print_function`)**
    
    -   This function takes an array and its size as parameters.
    -   It iterates through the array and prints each element followed by a space.
    
    
    ```
    void print_function(int arr[], int s){
        for(int i = 0; i < s; i++){
            cout << arr[i] << " ";
        }
    }
    ``` 
    
2.  **Swapping Function (`swap_function`)**
    
    -   This function takes an array and its size as parameters.
    -   It creates a new array to store the swapped elements.
    -   It iterates through the array in steps of 2 and swaps adjacent elements.
    -   If the array has an odd size, the last element is not swapped and remains in its original position.
    -   It calls the `print_function` to display the swapped array.
    
    
    ```
    void swap_function(int arr[], int s){
        int new_array[s];
        
        for(int i = 0; i < s; i=i+2){
            if(i+1 < s){
                new_array[i] = arr[i+1];
                new_array[i+1] = arr[i];
            } else {
                new_array[i] = arr[i];
            }
        }
        
        print_function(new_array, s);
    }
    ``` 
    
3.  **Main Function (`main`)**
    
    -   It defines two arrays, one with an even size and one with an odd size.
    -   It calls the `swap_function` for both arrays and prints the results.
    
    
    ```
    int main(){
        int even_array[8] = {1, 2, 3, 4, 5, 6, 7, 8};
        int odd_array[5] = {1, 2, 3, 4, 5};
        
        cout << "Even Size of Array Swapped : ";
        swap_function(even_array, 8);
        
        cout << endl;
        
        cout << "Odd Size of Array Swapped : ";
        swap_function(odd_array, 5);
        return 0;
    }
    ``` 
    

## Example Output

-   **Even-sized array:**
    
    -   Input: `{1, 2, 3, 4, 5, 6, 7, 8}`
    -   Output: `2 1 4 3 6 5 8 7`
    -   Each adjacent pair of elements is swapped.
-   **Odd-sized array:**
    
    -   Input: `{1, 2, 3, 4, 5}`
    -   Output: `2 1 4 3 5`
    -   Each adjacent pair of elements is swapped, and the last element remains in its original position.

This program effectively demonstrates how to swap adjacent elements in an array while handling both even and odd-sized arrays correctly.
