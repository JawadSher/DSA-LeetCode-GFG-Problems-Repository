# Source Code Explanation

#### Function `is_rotated_sorted`

1.  **Initialization**:
   
    
    `int start = 0;
    int end = n - 1;` 
    
    -   `start` and `end` are initialized to the beginning and end of the array, respectively.
2.  **Binary Search to Find Rotation Point**:
    

    
    ```
    while(start <= end){
        int mid = start + (end - start)/2;
        
        if(arr[mid] > arr[end]){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    ``` 
    
    -   This loop uses binary search to find the smallest element in the array, which indicates the rotation point.
    -   `mid` is calculated as the middle index between `start` and `end`.
    -   If `arr[mid] > arr[end]`, it means the smallest element is in the right half, so `start` is updated to `mid + 1`.
    -   Otherwise, the smallest element is in the left half or at `mid`, so `end` is updated to `mid - 1`.
    
    However, there is an issue here:
    
    -   The correct update should be `end = mid` instead of `end = mid - 1`. If you use `end = mid - 1`, you might skip the rotation point.
    
    Here is the corrected part:

    
    ```
    while(start < end){
        int mid = start + (end - start)/2;
        
        if(arr[mid] > arr[end]){
            start = mid + 1;
        }else{
            end = mid;
        }
    }
    ``` 
    
    -   After the loop, `start` should point to the rotation point, which is the smallest element in the array.
3.  **Validation of Sorted Order**:
    


    
    ```
    int rotation = start; // This line should be added
    
    for(int i = 0; i < n-1; i++){
        if(arr[(rotation + i)%n] > arr[(rotation + i + 1)%n]){
            return false;
        }
    }
    return true;
    ``` 
    
    -   `rotation` is the index of the smallest element found using the binary search.
    -   The `for` loop checks if the elements from the rotation point are in increasing order.
    -   It uses modulo arithmetic `(rotation + i) % n` to handle the circular nature of the array, wrapping around to the start of the array when needed.
    -   If any element is greater than the next element, it returns `false`, indicating the array is not a rotated sorted array.
    -   If all elements are in order, it returns `true`.

#### `main` Function

1.  **Input Array**:
    

    
    ```
    int new_array[] = {2,1,3,4};
    int size = sizeof(new_array) / sizeof(new_array[0]);
    ``` 
    
    -   An array `new_array` is defined with 4 elements, and its size is calculated.
2.  **Check if Rotated & Sorted**:
    

    
    ```
    bool is_true = is_rotated_sorted(new_array, size);
    string status = (is_true) ? "True" : "False";
    cout << "Rotated & Sorted : " << status;
    ``` 
    
    -   The function `is_rotated_sorted` is called with `new_array` and its size.
    -   The result `is_true` is converted to a string (`"True"` or `"False"`) and printed.
