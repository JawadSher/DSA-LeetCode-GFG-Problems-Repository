<h1 align='center'>Quick - Sort - Algorithm</h1>

## Problem Statement

**Problem URL :** [None]()

You are given an array of integers. Your task is to sort this array using the **Quick Sort** algorithm. Quick Sort is an efficient, in-place sorting algorithm that uses the **Divide and Conquer** strategy. You need to partition the array around a chosen **pivot element**, place it in its correct position, and recursively sort the sub-arrays on the left and right of the pivot.

### Quick Sort Algorithm:

**Quick Sort** is also a **Divide and Conquer** algorithm. It picks a "pivot" element from the array and partitions the remaining elements into two sub-arrays according to whether they are smaller or greater than the pivot. The pivot is placed in its correct sorted position, and this process is recursively applied to the sub-arrays.

#### Steps of Quick Sort:
1. **Choose a Pivot**: Select an element as the pivot. In the code, the first element is chosen as the pivot.
2. **Partition**: Rearrange the array such that elements smaller than the pivot are on the left and elements greater than the pivot are on the right.
3. **Recursively Sort**: Apply the same process to the left and right sub-arrays.
4. **Base Case**: If the array has one or no elements, it's already sorted.

#### Time Complexity of Quick Sort:
- **Best Case**: O(n log n)
- **Worst Case**: O(n²) (when the pivot is poorly chosen, e.g., always the smallest or largest element)
- **Average Case**: O(n log n)
- **Space Complexity**: O(log n) for recursion stack (in-place sorting)

## Problem Solution
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int partition(int *arr, int s, int e){
  int pivot = arr[s];

  int count = 0;
  for(int i = s+1; i <= e; i++){
    if(arr[i] <= pivot){
      count++;
    }
  }

  int pivotIndex = s + count;
  swap(arr[pivotIndex], arr[s]);

  int i = s, j = e;

  while(i < pivotIndex && j > pivotIndex){
    while(arr[i] <= pivot){
      i++;
    }

    while(arr[j] > pivot){
      j--;
    }

    if(i < pivotIndex && j > pivotIndex){
      swap(arr[i++], arr[j--]);
    }
  }

  return pivotIndex;
}

void quickSort(int *arr, int s, int e){
  if(s >= e) return;

  int index = partition(arr, s, e);

  quickSort(arr, s, index-1);
  quickSort(arr, index+1, e);

}

int main() {
  int new_array[] = {3, 2, 1, 5, 4, 0};
  int n = 6;

  cout<<"Un-sorted Before : ";
  for(int i = 0; i < n; i++){
    cout<< new_array[i] << " ";
  }cout<<endl;

  quickSort(new_array, 0, n-1);
  
  cout<<"sorted After : ";
  for(int i = 0; i < n; i++){
    cout<< new_array[i] << " ";
  }cout<<endl;


  return 0;
}
```

## Problem Solution Explanation

```cpp
int partition(int *arr, int s, int e) {
  int pivot = arr[s]; // Choose the first element as the pivot
```
- **Explanation**: This function selects a pivot element. In this case, the first element of the array (`arr[s]`) is chosen.

```cpp
  int count = 0;
  for(int i = s+1; i <= e; i++) {
    if(arr[i] <= pivot) {
      count++;
    }
  }
```
- **Explanation**: This loop counts how many elements are less than or equal to the pivot. This helps in placing the pivot in the correct position later on.

```cpp
  int pivotIndex = s + count; // The correct position for the pivot
  swap(arr[pivotIndex], arr[s]); // Place pivot in the correct position
```
- **Explanation**: The pivot is placed in its correct sorted position by swapping it with the element at the calculated `pivotIndex`.

```cpp
  int i = s, j = e;
  while(i < pivotIndex && j > pivotIndex) {
    while(arr[i] <= pivot) {
      i++;
    }
    while(arr[j] > pivot) {
      j--;
    }
    if(i < pivotIndex && j > pivotIndex) {
      swap(arr[i++], arr[j--]);
    }
  }
```
- **Explanation**: This loop ensures that elements smaller than the pivot are on the left side and elements larger than the pivot are on the right side. Two pointers `i` and `j` move towards the pivot from both ends and swap elements if they are misplaced.

```cpp
  return pivotIndex; // Return the index of the pivot element
}
```
- **Explanation**: After partitioning, the function returns the `pivotIndex`, where the pivot is now placed correctly.

```cpp
void quickSort(int *arr, int s, int e) {
  if(s >= e) return; // Base case: If there's one or no element, it's already sorted.
```
- **Explanation**: The recursion stops when there are no more elements to sort.

```cpp
  int index = partition(arr, s, e); // Partition the array and get the pivot index
  quickSort(arr, s, index-1); // Recursively sort the left half
  quickSort(arr, index+1, e); // Recursively sort the right half
}
```
- **Explanation**: The array is recursively sorted on the left and right of the pivot.

### Example Walkthrough:

#### Example 1:
- Input: `[3, 2, 1, 5, 4, 0]`
1. **First Call**:
   - Pivot = 3
   - Elements less than or equal to pivot = `[2, 1, 0]`
   - Pivot placed at correct position: `[2, 1, 0, 3, 5, 4]`
2. **Left Sub-array**:
   - Pivot = 2
   - Elements less than or equal to pivot = `[1, 0]`
   - Pivot placed at correct position: `[1, 0, 2, 3, 5, 4]`
3. **Continue Recursion**:
   - Sub-array `[1, 0]` gets sorted to `[0, 1]`
   - Sub-array `[5, 4]` gets sorted to `[4, 5]`

Final sorted array: `[0, 1, 2, 3, 4, 5]`

#### Example 2:
- Input: `[5, 3, 8, 4, 2, 7, 1, 10]`
1. **First Call**:
   - Pivot = 5
   - Partitioned: `[3, 4, 2, 1] [5] [8, 7, 10]`
2. **Sort Left and Right Sub-arrays**:
   - `[3, 4, 2, 1]` → `[1, 2, 3, 4]`
   - `[8, 7, 10]` → `[7, 8, 10]`

Final sorted array: `[1, 2, 3, 4, 5, 7, 8, 10]`

### Summary of Quick Sort:

- **Quick Sort** is in-place, but may degrade to O(n²) in the worst case if the pivot is poorly chosen. However, it is faster in practice with a good pivot.

### Stability in Sorting Algorithms:

A sorting algorithm is **stable** if it preserves the relative order of records with equal keys (or values). In other words, if two elements have the same value, their relative order in the sorted array is the same as in the input array.

### Example of Stability:
Consider an array of pairs where each pair has a number and a letter:
```
[(5, 'a'), (3, 'b'), (5, 'c'), (2, 'd')]
```
After sorting based on the numbers:
- A **stable** sort would produce: `[(2, 'd'), (3, 'b'), (5, 'a'), (5, 'c')]` (relative order of (5, 'a') and (5, 'c') is maintained).
- An **unstable** sort might produce: `[(2, 'd'), (3, 'b'), (5, 'c'), (5, 'a')]` (relative order is changed).

### Is Quick Sort Stable?

**Quick Sort** is **unstable by default** because when partitioning the array, elements with the same value as the pivot can be swapped across the pivot, potentially altering their original relative order. For example, if the elements `5a` and `5b` (both have value `5`) are on opposite sides of the pivot, the swapping might change their order in the final sorted array.

### Why Quick Sort is Unstable:
Quick Sort swaps elements during partitioning without preserving the relative order of elements with equal values. The following situation demonstrates instability:
- Input array: `[5a, 2, 5b, 1]`
  - Pivot chosen as `5a`
  - After partitioning, you might get `[2, 1, 5b, 5a]` (the relative order of `5a` and `5b` is swapped).

### How to Make Quick Sort Stable:

There are two main ways to make Quick Sort stable:

#### 1. Modify the Partitioning Logic:
You can modify the partitioning algorithm to maintain the relative order of elements with equal values. Instead of swapping elements blindly, the partition function can be written to ensure that elements equal to the pivot are grouped together while maintaining their relative order.

This can be achieved by:
- Using two auxiliary arrays or lists (or using a temporary buffer).
  - One array for elements **less than** the pivot.
  - One array for elements **equal to** the pivot.
  - One array for elements **greater than** the pivot.
- Concatenate the arrays after partitioning.

##### Example Code to Make Quick Sort Stable:

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Function to partition the array into three parts (less than, equal to, greater than pivot)
void stablePartition(int *arr, vector<int>& less, vector<int>& equal, vector<int>& greater, int s, int e) {
    int pivot = arr[s];  // Using the first element as the pivot
    
    for (int i = s; i <= e; i++) {
        if (arr[i] < pivot) {
            less.push_back(arr[i]);
        } else if (arr[i] == pivot) {
            equal.push_back(arr[i]);
        } else {
            greater.push_back(arr[i]);
        }
    }
}

// Stable Quick Sort function
void stableQuickSort(int *arr, int s, int e) {
    if (s >= e) return;  // Base condition
    
    // Vectors to store elements less than, equal to, and greater than the pivot
    vector<int> less, equal, greater;
    
    // Partition the array into less, equal, and greater groups
    stablePartition(arr, less, equal, greater, s, e);
    
    // Merge the results back into the original array
    int index = s;
    
    // Copy elements from 'less' group
    for (int i = 0; i < less.size(); i++) {
        arr[index++] = less[i];
    }
    
    // Copy elements from 'equal' group
    for (int i = 0; i < equal.size(); i++) {
        arr[index++] = equal[i];
    }
    
    // Copy elements from 'greater' group
    for (int i = 0; i < greater.size(); i++) {
        arr[index++] = greater[i];
    }
    
    // Recursively sort the 'less' and 'greater' parts
    stableQuickSort(arr, s, s + less.size() - 1);
    stableQuickSort(arr, s + less.size() + equal.size(), e);
}

// Main function to test the stable quicksort
int main() {
    int arr[] = {43, 595, 348, 857, 684, 94, 108, 542, 732, 655, 563, 434, 964, 92, 680, 434, 321, 966, 835, 774, 65, 984};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Print unsorted array
    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Perform stable quicksort
    stableQuickSort(arr, 0, n - 1);
    
    // Print sorted array
    cout << "Sorted array (stable): ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
```

### Explanation:

1. **Partitioning**: 
    - Instead of doing in-place partitioning, we create three separate arrays: 
      - `less`: Stores elements smaller than the pivot.
      - `equal`: Stores elements equal to the pivot.
      - `greater`: Stores elements greater than the pivot.
    - This ensures that the relative order of elements in the `equal` group is preserved, making the sorting stable.

2. **Merging**:
    - After partitioning, we merge the `less`, `equal`, and `greater` arrays back into the original array in the correct order.
    - By doing this, we avoid swapping elements with equal values across the pivot, which would otherwise make the sort unstable.

3. **Recursive Sort**:
    - The `less` and `greater` parts of the array are sorted recursively, while the `equal` part is left as-is since it's already sorted and stable.

### Example:
For the input array:
```
[43, 595, 348, 857, 684, 94, 108, 542, 732, 655, 563, 434, 964, 92, 680, 434, 321, 966, 835, 774, 65, 984]
```
The output will be a stable sorted array:
```
[43, 65, 92, 94, 108, 321, 348, 434, 434, 542, 563, 595, 655, 680, 684, 732, 774, 835, 857, 964, 966, 984]
```

In this case, the relative order of the two `434` values is maintained, making the sorting **stable**.

### Conclusion:
- By using auxiliary arrays (or vectors) to store elements less than, equal to, and greater than the pivot and then merging them back, you can make Quick Sort stable.
- This approach comes with a trade-off in space complexity (since we're using extra space for the auxiliary arrays), but it ensures that Quick Sort becomes stable.
