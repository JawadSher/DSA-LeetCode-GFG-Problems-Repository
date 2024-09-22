<h1 align='center'>Quick - Sort</h1>

## Problem Statement

**Problem URL :** [Quick Sort](https://www.geeksforgeeks.org/problems/quick-sort/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/987e2f16-95ae-4a4c-a93b-cef86164690d)
![image](https://github.com/user-attachments/assets/de104bb1-d1f2-476c-8c67-0d6b83008126)

## Problem Solution
```cpp
class Solution
{
    public:
    int partition (int arr[], int s, int e)
    {
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
    
    public:
    void quickSort(int arr[], int s, int e)
    {
        if(s >= e) return;
        
        
        int index = partition(arr, s, e);
        
        quickSort(arr, s, index-1);
        quickSort(arr, index+1, e);
        
    }
    
};
```

## Problem Solution Explanation

Let’s break down the provided Quick Sort implementation step by step, explaining each part of the code and providing examples along the way.

#### Class Definition
```cpp
class Solution
{
```
- A class named `Solution` is defined. This can be used to encapsulate the sorting functionality.

#### Partition Function
```cpp
public:
int partition(int arr[], int s, int e)
```
- The `partition` function is defined. It takes an array `arr`, a starting index `s`, and an ending index `e` to partition the array.

##### Pivot Selection
```cpp
int pivot = arr[s];
```
- The pivot is selected as the first element of the current subarray (`arr[s]`).

##### Counting Elements
```cpp
int count = 0;
for(int i = s+1; i <= e; i++) {
    if(arr[i] <= pivot) {
        count++;
    }
}
```
- This loop counts how many elements are less than or equal to the pivot. This helps in placing the pivot in its correct position after partitioning.

**Example**: For `arr = [3, 2, 1, 5, 4]`, if `s = 0` and `e = 4`, the pivot is `3`. The count will be `2` (for `2` and `1`).

##### Placing the Pivot
```cpp
int pivotIndex = s + count;
swap(arr[pivotIndex], arr[s]);
```
- The pivot is moved to its correct position (where all elements to the left are smaller or equal). This is done by swapping it with the element at `pivotIndex`.

**Example**: Continuing with `arr = [3, 2, 1, 5, 4]`, after counting, `pivotIndex` will be `2`. The array becomes `[1, 2, 3, 5, 4]`.

##### Two Pointers for Final Partitioning
```cpp
int i = s, j = e;
```
- Two pointers `i` and `j` are initialized to traverse the array.

##### Partitioning Process
```cpp
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
- This loop continues until `i` and `j` meet.
- The inner loops adjust `i` to find elements greater than the pivot and `j` to find elements less than or equal to the pivot.
- When valid indices are found, the elements are swapped.

**Example**: After the swap operations, for the array `[1, 2, 3, 5, 4]`, it will ensure that elements are in their correct partition.

##### Return Pivot Index
```cpp
return pivotIndex;
```
- Finally, the function returns the index where the pivot is now located.

#### Quick Sort Function
```cpp
public:
void quickSort(int arr[], int s, int e)
{
    if(s >= e) return;
```
- The `quickSort` function is defined. If the start index `s` is greater than or equal to the end index `e`, it returns (base case for recursion).

##### Recursive Calls
```cpp
int index = partition(arr, s, e);
quickSort(arr, s, index - 1);
quickSort(arr, index + 1, e);
```
- The array is partitioned, and then `quickSort` is called recursively on the two subarrays formed by the pivot.

### Example Walkthrough
Let's see how this Quick Sort algorithm works with an example array:

**Input**: `arr = [3, 2, 1, 5, 4]`

1. **First Call to `quickSort`**:
   - `s = 0`, `e = 4`, pivot is `3`, after partitioning: `[1, 2, 3, 5, 4]`, pivot index `2`.
   - Recursive calls: `quickSort(arr, 0, 1)` and `quickSort(arr, 3, 4)`.

2. **Second Call to `quickSort`** (`arr, 0, 1`):
   - `s = 0`, `e = 1`, pivot is `1`, after partitioning: `[1, 2]`, pivot index `0`.
   - Recursive calls: `quickSort(arr, 0, -1)` (base case) and `quickSort(arr, 1, 1)` (base case).

3. **Third Call to `quickSort`** (`arr, 3, 4`):
   - `s = 3`, `e = 4`, pivot is `5`, after partitioning: `[1, 2, 3, 4, 5]`, pivot index `4`.
   - Recursive calls: `quickSort(arr, 3, 3)` (base case) and `quickSort(arr, 5, 4)` (base case).

At the end of all recursive calls, the sorted array is `[1, 2, 3, 4, 5]`.

### Summary
- The provided Quick Sort implementation uses the partitioning method to sort an array in place.
- It recursively sorts subarrays created around the pivot.
- Each step effectively organizes the elements around the pivot, ultimately leading to a sorted array.
