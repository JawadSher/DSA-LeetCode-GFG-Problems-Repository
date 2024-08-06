# Source Code Explanation
### Function: `median_of_array`

#### Purpose

The purpose of this function is to find the median of two sorted arrays. The median is the middle element in a sorted array, or the average of the two middle elements if the array has an even number of elements.

#### Parameters

-   `nums_1[]`: The first sorted array.
-   `n`: The number of elements in the first array.
-   `nums_2[]`: The second sorted array.
-   `m`: The number of elements in the second array.

#### Step-by-Step Explanation

1.  **Calculate Total Size**
    

    
    `int t_size = (n + m);` 
    
    -   `t_size` is the total number of elements after merging both arrays.
2.  **Temporary Array for Merging**
    

    
    `int temp_array[t_size];` 
    
    -   `temp_array` is a temporary array used to store the merged elements of `nums_1` and `nums_2`.
3.  **Initialize Indices**
    

    
    ```
    int i = 0;
    int j = 0;
    int k = 0;
    ``` 
    
    -   `i` is the index for traversing `nums_1`.
    -   `j` is the index for traversing `nums_2`.
    -   `k` is the index for filling `temp_array`.
4.  **Merge Arrays**
    
    -   This loop merges the two arrays into `temp_array` in sorted order.

    ```
    while (i < n && j < m) {
      if (nums_1[i] < nums_2[j]) {
        temp_array[k++] = nums_1[i++];
      } else {
        temp_array[k++] = nums_2[j++];
      }
    }
    ``` 
    
    -   If the current element of `nums_1` is smaller, it is added to `temp_array` and `i` is incremented.
    -   Otherwise, the current element of `nums_2` is added to `temp_array` and `j` is incremented.
5.  **Copy Remaining Elements from `nums_1`**
    
    -   After the first while loop, if any elements are left in `nums_1`, they are copied to `temp_array`.
    

    
    ```
    while (i < n) {
      temp_array[k++] = nums_1[i++];
    }
    ``` 
    
6.  **Copy Remaining Elements from `nums_2`**
    
    -   Similarly, if any elements are left in `nums_2`, they are copied to `temp_array`.
    

    
    ```
    while (j < m) {
      temp_array[k++] = nums_2[j++];
    }
    ``` 
    
7.  **Calculate the Median**
    
    -   If the total number of elements is odd, the median is the middle element.
    

    
    ```
    if (t_size % 2 == 1) {
      return temp_array[t_size / 2];
    } else {
      return (temp_array[t_size / 2] + temp_array[(t_size / 2) - 1]) / 2.0;
    }
    ``` 
    
    -   If the total number of elements is even, the median is the average of the two middle elements.

### Main Function

#### Purpose

The `main` function tests the `median_of_array` function with two example arrays.

#### Step-by-Step Explanation

1.  **Define Arrays**
    

    
    ```
    int array_1[] = {1, 2, 3};
    int n = sizeof(array_1) / sizeof(array_1[0]);
    
    int array_2[] = {1, 2, 3, 4, 5};
    int m = sizeof(array_2) / sizeof(array_2[0]);
    ``` 
    
    -   `array_1` and `array_2` are two example sorted arrays.
    -   `n` and `m` are the sizes of these arrays, calculated using `sizeof`.
2.  **Call the Function and Print the Result**
    
    
    ```
    double median = median_of_array(array_1, n, array_2, m);
    cout << "The median value is: " << median;
    ``` 
    
    -   The `median_of_array` function is called with the two arrays and their sizes.
    -   The resulting median is printed to the console.

### Summary

-   The `median_of_array` function merges two sorted arrays into a temporary array and finds the median of the merged array.
-   The main function tests this functionality with two example arrays and prints the result.
