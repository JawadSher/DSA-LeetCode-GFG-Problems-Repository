# find K Rotation Problem

This method takes a vector of integers (`arr`) as input and returns the index of the smallest element in the rotated sorted array.

```
int findKRotation(vector<int> &arr) {
    int start = 0;
    int end = arr.size() - 1;
    
    while(start < end){
        int mid = start + (end - start)/2;
        
        if(arr[mid] < arr[end]){
            end = mid;
        }else if(arr[mid] > arr[end]){
            start = mid + 1;
        }else{
            end--;
        }
    }
    
    return start;
}
``` 

### Explanation

1.  **Initialization**:
    
    -   `start` is initialized to 0.
    -   `end` is initialized to the last index of the array (`arr.size() - 1`).
2.  **Binary Search Loop**:
    
    -   The loop continues until `start` is less than `end`.
3.  **Mid Calculation**:
    
    -   `mid` is calculated as the middle index between `start` and `end`.
4.  **Comparison and Adjustment**:
    
    -   If `arr[mid] < arr[end]`, it means the smallest element is in the left half, including `mid`. Thus, `end` is updated to `mid`.
    -   If `arr[mid] > arr[end]`, the smallest element is in the right half, excluding `mid`. Thus, `start` is updated to `mid + 1`.
    -   If `arr[mid] == arr[end]`, decrement `end` by 1 to handle potential duplicates.
5.  **Termination**:
    
    -   The loop terminates when `start` equals `end`, pointing to the smallest element's index.
6.  **Return**:
    
    -   The method returns the index `start`, which is the index of the smallest element in the rotated sorted array.

## Driver Code

The driver code handles the input and output for multiple test cases.

```
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
    }
}
``` 

### Explanation

1.  **Number of Test Cases**:
    
    -   The number of test cases is read into `t`.
    -   `cin.ignore()` is used to ignore the newline character after reading `t`.
2.  **Processing Each Test Case**:
    
    -   A loop runs `t` times to handle multiple test cases.
3.  **Reading the Array**:
    
    -   For each test case, an empty vector `arr` is created.
    -   The entire line of input is read into the string `input1`.
    -   A stringstream `ss1` is created from `input1`.
    -   The stringstream extracts integers and appends them to the vector `arr`.
4.  **Finding Rotation Count**:
    
    -   An instance of the `Solution` class (`ob`) is created.
    -   The `findKRotation` method is called with `arr` as an argument, and the result is stored in `res`.
5.  **Output**:
    
    -   The result `res` is printed, which is the index of the smallest element in the rotated sorted array for the current test case.

### Summary

This code effectively uses binary search to find the index of the smallest element in a rotated sorted array, handling multiple test cases efficiently. The solution is optimized for time complexity, ensuring that it runs efficiently even for large inputs.
