# Source Code Explanation
### Function: `median`

#### Purpose

The purpose of this function is to find the median of two sorted arrays using a binary search approach.

#### Parameters

-   `nums1[]`: The first sorted array.
-   `m`: The number of elements in the first array.
-   `nums2[]`: The second sorted array.
-   `n`: The number of elements in the second array.

#### Step-by-Step Explanation

1.  **Ensure `nums1` is the Smaller Array**
    

    
    ```
    if(m > n){
        return median(nums2, n, nums1, m);
    }
    ``` 
    
    -   If `nums1` is larger than `nums2`, swap the arrays so that the binary search is performed on the smaller array. This ensures that the binary search is efficient.
2.  **Initialize Binary Search Parameters**
    

    
    ```
    int start = 0;
    int end = m;
    ``` 
    
    -   `start` and `end` define the range for the binary search on the smaller array.
3.  **Binary Search Loop**
    

    
    
    ```
    while(start <= end){
        int px = start + (end - start) / 2;
        int py = (m + n + 1) / 2 - px;
    ``` 
    
    -   `px` is the partition index for `nums1`.
    -   `py` is the partition index for `nums2`.
4.  **Calculate Boundary Values**
    
  
    
    ```
    int x1 = (px == 0) ? INT_MIN : nums1[px - 1];
    int x2 = (py == 0) ? INT_MIN : nums2[py - 1];
    int x3 = (px == m) ? INT_MAX : nums1[px];
    int x4 = (py == n) ? INT_MAX : nums2[py];
    ``` 
    
    -   `x1` is the maximum value on the left side of the partition in `nums1` (or `INT_MIN` if `px` is 0).
    -   `x2` is the maximum value on the left side of the partition in `nums2` (or `INT_MIN` if `py` is 0).
    -   `x3` is the minimum value on the right side of the partition in `nums1` (or `INT_MAX` if `px` is `m`).
    -   `x4` is the minimum value on the right side of the partition in `nums2` (or `INT_MAX` if `py` is `n`).
5.  **Check Partition Validity**
    

    ```
    if(x1 <= x4 && x2 <= x3){
        if((m + n) % 2 == 1){
            return max(x1, x2);
        } else {
            return (max(x1, x2) + min(x3, x4)) / 2.0;
        }
    }
    ``` 
    
    -   If the left side maximum values are less than or equal to the right side minimum values, the partitions are correct.
    -   If the combined length of the arrays is odd, the median is the maximum value of the left partitions.
    -   If the combined length is even, the median is the average of the maximum value of the left partitions and the minimum value of the right partitions.
6.  **Adjust Binary Search Range**
    
    
    
    ```
    if(x1 > x4){
        end = px - 1;
    } else {
        start = px + 1;
    }
    ``` 
    
    -   If `x1` is greater than `x4`, move the partition in `nums1` to the left by updating `end`.
    -   If `x2` is greater than `x3`, move the partition in `nums1` to the right by updating `start`.
7.  **Return Error Value**
    

    
    `return -1;` 
    
    -   If the loop exits without finding the correct partition, return an error value (though this should not happen if the arrays are sorted and non-empty).

### Main Function

#### Purpose

The `main` function tests the `median` function with two example arrays.

#### Step-by-Step Explanation

1.  **Define Arrays**
    
   
    
    ```
    int array_1[] = {1, 2, 3};
    int m = sizeof(array_1) / sizeof(array_1[0]);
    
    int array_2[] = {1, 2, 3, 4, 5};
    int n = sizeof(array_2) / sizeof(array_2[0]);
    ``` 
    
    -   `array_1` and `array_2` are two example sorted arrays.
    -   `m` and `n` are the sizes of these arrays, calculated using `sizeof`.
2.  **Call the Function and Print the Result**

    
    ```
    double median_value = median(array_1, m, array_2, n);
    cout << "The median value is: " << median_value;
    ``` 
    
    -   The `median` function is called with the two arrays and their sizes.
    -   The resulting median is printed to the console.

### Summary

-   The `median` function uses a binary search approach to find the median of two sorted arrays.
-   This approach is efficient, with a time complexity of O(log⁡min⁡(m,n))O(\log \min(m, n))O(logmin(m,n)), making it suitable for large arrays.
-   The main function tests this functionality with two example arrays and prints the result.

## Video Explanation
1. [Brute Force & Better Approach Explained](https://www.youtube.com/watch?v=6D9T2ZY8h5c)
2. [Binary Search Approach Explained](https://www.youtube.com/watch?v=7nABqJCEMuY)
