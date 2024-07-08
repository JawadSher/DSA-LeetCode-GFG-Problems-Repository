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

    
    `int t_size = n + m;` 
    
    -   `t_size` is the total number of elements after merging both arrays.
2.  **Determine Indices for Median Calculation**

    
    ```
    int index_1 = (t_size - 1) / 2;  // The correct 0-based middle index for odd size
    int index_2 = t_size / 2;        // The correct 0-based middle index for even size
    ``` 
    
    -   `index_1` is the index of the middle element if the total size is odd.
    -   `index_2` is the index of the second middle element if the total size is even.
3.  **Initialize Elements and Indices**
    

    
    `int elmnt_1 = -1;
    int elmnt_2 = -1;
    
    int i = 0, j = 0, k = 0;` 
    
    -   `elmnt_1` and `elmnt_2` are placeholders for the elements at `index_1` and `index_2`.
    -   `i` is the index for traversing `nums_1`.
    -   `j` is the index for traversing `nums_2`.
    -   `k` is a counter to keep track of the position in the merged sequence.
4.  **Merge Arrays Until One is Exhausted**

    
    ```
    while (i < n && j < m) {
        if (nums_1[i] < nums_2[j]) {
            if (k == index_1) elmnt_1 = nums_1[i];
            if (k == index_2) elmnt_2 = nums_1[i];
            i++;
        } else {
            if (k == index_1) elmnt_1 = nums_2[j];
            if (k == index_2) elmnt_2 = nums_2[j];
            j++;
        }
        k++;
    }
    ``` 
    
    -   This loop merges the two arrays by comparing their current elements and placing the smaller one in the merged sequence.
    -   If the position `k` matches `index_1` or `index_2`, the corresponding element is stored in `elmnt_1` or `elmnt_2`.
5.  **Copy Remaining Elements from `nums_1`**

    
    ```
    while (i < n) {
        if (k == index_1) elmnt_1 = nums_1[i];
        if (k == index_2) elmnt_2 = nums_1[i];
        i++;
        k++;
    }
    ``` 
    
    -   After the first while loop, if any elements are left in `nums_1`, they are processed and the relevant elements are stored.
6.  **Copy Remaining Elements from `nums_2`**

    
    ```
    while (j < m) {
        if (k == index_1) elmnt_1 = nums_2[j];
        if (k == index_2) elmnt_2 = nums_2[j];
        j++;
        k++;
    }
    ``` 
    
    -   Similarly, if any elements are left in `nums_2`, they are processed and the relevant elements are stored.
7.  **Calculate Median**

    
    ```
    if (t_size % 2 == 1) {
        return elmnt_2;
    } else {
        return (elmnt_1 + elmnt_2) / 2.0;
    }
    ``` 
    
    -   If the total number of elements is odd, the median is the element at `index_2`.
    -   If the total number of elements is even, the median is the average of the elements at `index_1` and `index_2`.

### Main Function

#### Purpose

The `main` function tests the `median_of_array` function with two example arrays.

#### Step-by-Step Explanation

1.  **Define Arrays**
    
   
    
    ```
    int array_1[] = {1, 2, 3};
    int n = sizeof(array_1) / sizeof(array_1[0]);
    
    int array_2[] = {1, 2, 3, 4};
    int m = sizeof(array_2) / sizeof(array_2[0]);
    ``` 
    
    -   `array_1` and `array_2` are two example sorted arrays.
    -   `n` and `m` are the sizes of these arrays, calculated using `sizeof`.
2.  **Call the Function and Print the Result**
    

    
    `double median = median_of_array(array_1, n, array_2, m);
    cout << "The median value is: " << median << endl;` 
    
    -   The `median_of_array` function is called with the two arrays and their sizes.
    -   The resulting median is printed to the console.

### Why This Approach is Better

1.  **Space Efficiency**
    
    -   This approach does not require the creation of a temporary array to hold the merged elements, which saves space.
2.  **Time Efficiency**
    
    -   This approach only merges the arrays up to the point needed to find the median, potentially saving time.
3.  **Direct Calculation**
    
    -   The median is calculated directly during the merge process, avoiding the need to sort or fully traverse the merged array.

Overall, this approach is more efficient in both time and space, making it a better solution for finding the median of two sorted arrays.
