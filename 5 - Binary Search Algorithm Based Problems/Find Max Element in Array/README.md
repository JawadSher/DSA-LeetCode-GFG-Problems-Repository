# Source Code Explanation

### Libraries and Namespace


```
#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;
``` 

-   **`#include<iostream>`**: This includes the standard input-output stream library, which allows us to use `cout` and `cin`.
-   **`#include<algorithm>`**: This includes the algorithm library, which provides various algorithms like `std::sort`.
-   **`#include<numeric>`**: This includes the numeric library, which provides algorithms for numerical computations, although it's currently unused in this code snippet.
-   **`using namespace std;`**: This line allows us to use elements from the `std` namespace without prefixing them with `std::`.

### 2. `is_max` Function



```
bool is_max(int mid, int nums[], int n){
   for(int i = 0; i < n; i++){
       if(nums[i] > mid){
           return false;
       }
   }
   return true;
}
``` 

-   **`is_max` Function**: This function checks if `mid` is the maximum element in the array `nums` of size `n`.
    -   It iterates through each element of the array.
    -   If any element in the array is greater than `mid`, it returns `false`, indicating `mid` is not the maximum.
    -   If it iterates through the entire array without finding any element greater than `mid`, it returns `true`, indicating `mid` is the maximum.

### 3. `max_element` Function



```
int max_element(int nums[], int n){
    int left = nums[0];
    int right = nums[0];
    
    for(int i = 1; i < n; i++){
        if(nums[i] < left) left = nums[i];
        if(nums[i] > right) right = nums[i];
    }
    
    while(left < right){
        int mid = left + (right - left)/2;
        
        if(is_max(mid, nums, n)){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    return right;
}
``` 

-   **`max_element` Function**: This function finds the maximum element in the array `nums` of size `n` using a binary search-like approach.
    -   It initializes `left` and `right` to the first element of the array (`nums[0]`).
    -   It then iterates through the array to determine the actual range of elements (`left` as the smallest and `right` as the largest).
    -   It enters a `while` loop that continues as long as `left` is less than `right`.
    -   Inside the loop, it calculates `mid` as the midpoint between `left` and `right`.
    -   It calls the `is_max` function to check if `mid` can be the maximum element.
        -   If `is_max(mid, nums, n)` returns `true`, it updates `right` to `mid`, indicating that `mid` could be the maximum element and narrowing the search range.
        -   Otherwise, it updates `left` to `mid + 1`, excluding `mid` from further consideration.
    -   The loop continues until `left` is no longer less than `right`, at which point `right` contains the maximum element.
    -   It returns `right` as the maximum element found.

### 4. `main` Function


```
int main() {
    int nums[] = {1,2,3,4,5,6,7,8,9,10};
    
    int w_length = sizeof(nums) / sizeof(nums[0]);
    int max_value = max_element(nums, w_length);
    cout<<"Max Value is : "<<max_value;
    
    return 0;
}
``` 

-   **`main` Function**: This is the entry point of the program.
    -   It initializes an array `nums` with values `{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}`.
    -   It calculates the length of the array (`w_length`) using `sizeof(nums) / sizeof(nums[0])`.
    -   It calls the `max_element` function to find the maximum element in the array.
    -   It prints out the maximum element using `cout`.

### Summary

-   The program uses a binary search-like approach to find the maximum element in the array `nums`.
-   It defines helper functions (`is_max`) to facilitate this search.
-   The `max_element` function iteratively narrows down the search range based on whether the midpoint (`mid`) could be the maximum element.
-   Finally, the `main` function demonstrates the usage of these functions to find and print the maximum element in the array `{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}`.
