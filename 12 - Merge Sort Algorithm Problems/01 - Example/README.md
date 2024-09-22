<h1 align='center'>Merge - Sort - Algorithm</h1>

## Problem Statement

**Problem URL :** [None]()

**Merge Sort** is a divide-and-conquer algorithm that sorts an array by recursively splitting it into halves until each half contains a single element (which is inherently sorted). Then, it merges these halves back together in sorted order.

### Steps of Merge Sort

1. **Divide**: Split the array into two halves.
2. **Conquer**: Recursively sort each half.
3. **Combine**: Merge the two sorted halves into a single sorted array.

### Example 1

**Input Array**: `[38, 27, 43, 3, 9, 82, 10]`

1. **Initial Call**: `mergeSort(arr, 0, 6)`
   - The array is divided into:
     - Left: `[38, 27, 43]`
     - Right: `[3, 9, 82, 10]`

2. **Divide the Left Half**: `mergeSort(arr, 0, 2)`
   - Further divided into:
     - Left: `[38]` (base case, sorted)
     - Right: `[27, 43]`

3. **Sort Right Half**: `mergeSort(arr, 1, 2)`
   - Further divided into:
     - Left: `[27]` (base case, sorted)
     - Right: `[43]` (base case, sorted)

4. **Merge Left Half**:
   - Merging `[27]` and `[43]` results in `[27, 43]`.

5. **Merge the Overall Left Half**:
   - Merging `[38]` and `[27, 43]` results in `[27, 38, 43]`.

6. **Sort the Right Half**: `mergeSort(arr, 3, 6)`
   - Divided into:
     - Left: `[3, 9]`
     - Right: `[82, 10]`

7. **Sort Left**: `mergeSort(arr, 3, 4)`
   - Merges `[3]` and `[9]` to get `[3, 9]`.

8. **Sort Right**: `mergeSort(arr, 5, 6)`
   - Merges `[82]` and `[10]` to get `[10, 82]`.

9. **Merge Right Half**:
   - Merging `[3, 9]` and `[10, 82]` results in `[3, 9, 10, 82]`.

10. **Final Merge**:
    - Merging `[27, 38, 43]` and `[3, 9, 10, 82]` results in the final sorted array:
      - **Output**: `[3, 9, 10, 27, 38, 43, 82]`

### Example 2

**Input Array**: `[12, 11, 13, 5, 6, 7]`

1. **Initial Call**: `mergeSort(arr, 0, 5)`
   - Divides into:
     - Left: `[12, 11, 13]`
     - Right: `[5, 6, 7]`

2. **Sort Left Half**:
   - Divides `[12, 11, 13]` into `[12]` and `[11, 13]`.
   - Sorts `[11, 13]` to get `[11, 13]`.
   - Merges `[12]` and `[11, 13]` to get `[11, 12, 13]`.

3. **Sort Right Half**:
   - Divides `[5, 6, 7]` into `[5]` and `[6, 7]`.
   - Sorts `[6, 7]` to get `[6, 7]`.
   - Merges `[5]` and `[6, 7]` to get `[5, 6, 7]`.

4. **Final Merge**:
   - Merges `[11, 12, 13]` and `[5, 6, 7]` to get:
     - **Output**: `[5, 6, 7, 11, 12, 13]`

### Example 3

**Input Array**: `[10, -1, 2, 3, 0]`

1. **Initial Call**: `mergeSort(arr, 0, 4)`
   - Divides into:
     - Left: `[10, -1, 2]`
     - Right: `[3, 0]`

2. **Sort Left Half**:
   - Divides `[10, -1, 2]` into `[10]` and `[-1, 2]`.
   - Sorts `[-1, 2]` to get `[-1, 2]`.
   - Merges `[10]` and `[-1, 2]` to get `[-1, 2, 10]`.

3. **Sort Right Half**:
   - Divides `[3, 0]` into `[3]` and `[0]`.
   - Merges `[3]` and `[0]` to get `[0, 3]`.

4. **Final Merge**:
   - Merges `[-1, 2, 10]` and `[0, 3]` to get:
     - **Output**: `[-1, 0, 2, 3, 10]`

## Problem Solution
```cpp
#include <iostream>
using namespace std;

void merge(int *arr, int s, int e){
  int mid = s + (e - s)/2;
  
  int len1 = mid - s + 1;
  int len2 = e - mid;

  int *left = new int[len1];
  int *right = new int[len2];

  int MainIndex = s;
  for(int i = 0; i < len1; i++){
    left[i] = arr[MainIndex++];
  }

  MainIndex = mid + 1;
  for(int i = 0; i < len2; i++){
    right[i] = arr[MainIndex++];
  }

  int leftIndex = 0;
  int rightIndex = 0;
  MainIndex = s;

  while(leftIndex < len1 && rightIndex < len2){
    if(left[leftIndex] < right[rightIndex]){
      arr[MainIndex++] = left[leftIndex++];
    }else{
      arr[MainIndex++] = right[rightIndex++];
    }
  }

  while(leftIndex < len1){
    arr[MainIndex++] = left[leftIndex++];
  }

  while(rightIndex < len2){
    arr[MainIndex++] = right[rightIndex++];
  }

  delete[] left;
  delete[] right;
}

void mergeSort(int *arr, int s, int e){
  // base case
  if(s >= e) return;

  int mid = s + (e - s)/2;

  mergeSort(arr, s, mid);
  mergeSort(arr, mid+1, e);

  merge(arr, s, e);
}

int main() {
  int un_sorted_arr[5] = {2, 5, 1, 6, 9};
  int n = 5;


  cout<< "Un-sorted Array : ";
  for(int i = 0; i < n; i++){
    cout<< un_sorted_arr[i] << " ";
  }cout<<endl;
  

  mergeSort(un_sorted_arr, 0, n-1);


  cout<< "Sorted Array : ";
  for(int i = 0; i < n; i++){
    cout<< un_sorted_arr[i] << " ";
  }cout<<endl;
  return 0;
}
```

## Problem Solution Explanation

1. **Include Libraries**:
   ```cpp
   #include <iostream>
   using namespace std;
   ```
   - This includes the standard I/O library for C++ and allows the use of `std` functions without prefixing them with `std::`.

2. **Merge Function**:
   ```cpp
   void merge(int *arr, int s, int e) {
   ```
   - This function merges two halves of the array defined by the start index `s` and the end index `e`.

3. **Calculate Middle Index**:
   ```cpp
   int mid = s + (e - s) / 2;
   ```
   - This computes the middle index of the current segment of the array.

4. **Length of Left and Right Arrays**:
   ```cpp
   int len1 = mid - s + 1;
   int len2 = e - mid;
   ```
   - These lines calculate the lengths of the left and right subarrays.

5. **Dynamic Memory Allocation**:
   ```cpp
   int *left = new int[len1];
   int *right = new int[len2];
   ```
   - Here, two dynamic arrays, `left` and `right`, are created to hold the two halves of the original array.

6. **Copy Elements to Left Array**:
   ```cpp
   int MainIndex = s;
   for (int i = 0; i < len1; i++) {
       left[i] = arr[MainIndex++];
   }
   ```
   - This loop copies elements from the original array to the `left` array.

7. **Copy Elements to Right Array**:
   ```cpp
   MainIndex = mid + 1;
   for (int i = 0; i < len2; i++) {
       right[i] = arr[MainIndex++];
   }
   ```
   - This loop copies elements to the `right` array.

8. **Merge Two Sorted Arrays**:
   ```cpp
   int leftIndex = 0;
   int rightIndex = 0;
   MainIndex = s;
   ```
   - Initializes indices for the left and right arrays and the main array.

9. **While Loop to Merge**:
   ```cpp
   while (leftIndex < len1 && rightIndex < len2) {
       if (left[leftIndex] < right[rightIndex]) {
           arr[MainIndex++] = left[leftIndex++];
       } else {
           arr[MainIndex++] = right[rightIndex++];
       }
   }
   ```
   - This loop compares elements of both arrays and merges them back into the original array in sorted order.

10. **Copy Remaining Elements from Left**:
    ```cpp
    while (leftIndex < len1) {
        arr[MainIndex++] = left[leftIndex++];
    }
    ```
    - This copies any remaining elements from the `left` array.

11. **Copy Remaining Elements from Right**:
    ```cpp
    while (rightIndex < len2) {
        arr[MainIndex++] = right[rightIndex++];
    }
    ```
    - This copies any remaining elements from the `right` array.

12. **Memory Cleanup**:
    ```cpp
    delete[] left;
    delete[] right;
    ```
    - Deallocates the memory used for the `left` and `right` arrays.

13. **Merge Sort Function**:
    ```cpp
    void mergeSort(int *arr, int s, int e) {
    ```
    - This is the main function that implements the merge sort algorithm.

14. **Base Case**:
    ```cpp
    if (s >= e) return;
    ```
    - If the segment has one or zero elements, it’s already sorted.

15. **Recursive Calls**:
    ```cpp
    int mid = s + (e - s) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    ```
    - The array is divided into two halves, and `mergeSort` is called recursively on both halves.

16. **Merge the Sorted Halves**:
    ```cpp
    merge(arr, s, e);
    ```
    - After both halves are sorted, they are merged back together.

17. **Main Function**:
    ```cpp
    int main() {
        int un_sorted_arr[5] = {2, 5, 1, 6, 9};
        int n = 5;
    ```
    - This initializes an unsorted array and its size.

18. **Display Unsorted Array**:
    ```cpp
    cout << "Un-sorted Array : ";
    for (int i = 0; i < n; i++) {
        cout << un_sorted_arr[i] << " ";
    } cout << endl;
    ```
    - Prints the original unsorted array.

19. **Sort the Array**:
    ```cpp
    mergeSort(un_sorted_arr, 0, n - 1);
    ```
    - Calls the `mergeSort` function to sort the array.

20. **Display Sorted Array**:
    ```cpp
    cout << "Sorted Array : ";
    for (int i = 0; i < n; i++) {
        cout << un_sorted_arr[i] << " ";
    } cout << endl;
    return 0;
    ```
    - Prints the sorted array and exits the program.

### Time and Space Complexity
- **Time Complexity**: 
  - The merge sort algorithm has a time complexity of \(O(n \log n)\), where \(n\) is the number of elements in the array. This is because the array is repeatedly divided in half (which takes \(O(\log n)\)) and each level of recursion involves merging the arrays, which takes \(O(n)\).

- **Space Complexity**:
  - The space complexity is \(O(n)\) due to the additional space required for the temporary `left` and `right` arrays. This additional space is needed to hold the split arrays during the merging process.


### Stability of Merge Sort Algorithm
**Merge Sort** is a **stable sorting algorithm** by nature. Stability in a sorting algorithm means that if two elements have the same value, their relative order is preserved in the sorted output as it was in the input.

### Why Merge Sort is Stable:

Merge Sort works by dividing the array into smaller subarrays, sorting these subarrays, and then merging them back together. During the merge process, if two elements are equal, the element that appears first in the original array will also appear first in the merged array. This ensures the stability of the algorithm.

#### Example of Stability in Merge Sort:

Consider the array:
```
[2a, 3, 2b, 1]
```
where `2a` and `2b` are two distinct elements with the same value but different identities (let's say they represent different objects with the same sorting key).

After applying **Merge Sort**, the sorted array will be:
```
[1, 2a, 2b, 3]
```
Here, the relative order of `2a` and `2b` is preserved (i.e., `2a` appears before `2b`), ensuring the sort is **stable**.

### How Stability is Achieved in Merge Sort:

- When merging two sorted halves, if elements from both halves are equal, the element from the left subarray is chosen before the one from the right subarray.
- This "left-first" rule ensures that elements that appear earlier in the input array retain their relative order when they are merged back.

### Example Walkthrough:

Let's consider an array:

```
[5a, 2, 5b, 1]
```
Where `5a` and `5b` are two different elements with the same value.

1. **Step 1**: The array is divided into two halves:
   - Left: `[5a, 2]`
   - Right: `[5b, 1]`

2. **Step 2**: Recursively sort both halves:
   - Sort the left half: `[2, 5a]`
   - Sort the right half: `[1, 5b]`

3. **Step 3**: Merge the two sorted halves:
   - Compare `2` and `1`: since `1` is smaller, it comes first.
   - Compare `2` and `5b`: since `2` is smaller, it comes next.
   - Compare `5a` and `5b`: since `5a` appears earlier in the original array, it comes before `5b`.

Final sorted array (stable):
```
[1, 2, 5a, 5b]
```

The relative order of `5a` and `5b` is preserved, making Merge Sort **stable**.

### Conclusion:

- Merge Sort is inherently stable because, during the merging process, elements with the same value retain their original relative order.
- The stability of Merge Sort is guaranteed by ensuring that when two equal elements are encountered during the merge, the one from the left subarray (which came earlier) is placed before the one from the right subarray.


### Summary
Merge Sort is an efficient, stable sorting algorithm that works well for large datasets. It’s particularly useful when the array cannot fit into memory and requires sorting via external storage methods.

