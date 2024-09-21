<h1 align='center'>Merge - Sort</h1>

## Problem Statement

**Problem URL :** [Merge Sort](https://www.geeksforgeeks.org/problems/merge-sort/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/a07d24e8-e413-46d4-be6e-05ac85e7af53)
![image](https://github.com/user-attachments/assets/d481565f-a9da-4bc3-af2e-7c6afd815027)

## Problem Solution
```cpp
class Solution
{
    public:
    void merge(int arr[], int s, int e)
    {
        int mid = s + (e - s)/2;
        
        int left = mid - s + 1;
        int right = e - mid;
        
        int *temp = new int[left + right];
        
        int i = s;
        int j = mid+1;
        int k = 0;
        
        while(i <= mid && j <= e){
            if(arr[i] < arr[j]){
                temp[k++] = arr[i++];
            }else{
                temp[k++] = arr[j++];
            }
        }
        
        while(i <= mid){
            temp[k++] = arr[i++];
        }
        
        while(j <= e){
            temp[k++] = arr[j++];
        }
        
        for(int x = 0; x < left+right; x++){
            arr[s+x] = temp[x];
        }
        
        delete []temp;
        
    }
    public:
    void mergeSort(int arr[], int s, int e)
    {
        if(s >= e) return;
        int mid = s + (e - s) /2;
        
        mergeSort(arr, s, mid);
        mergeSort(arr, mid+1, e);
        
        merge(arr, s, e);
    }
};

```

## Problem Solution Explanation
Let's break down the provided `mergeSort` class implementation line by line. This implementation sorts an array using the Merge Sort algorithm. 

### Class Definition

```cpp
class Solution
{
```
- Defines a class named `Solution`, which typically contains methods for solving problems, especially in competitive programming contexts.

### Merge Function

```cpp
public:
void merge(int arr[], int s, int e)
{
```
- This public method `merge` takes an array `arr`, a starting index `s`, and an ending index `e` as arguments. It merges two sorted halves of the array.

```cpp
int mid = s + (e - s)/2;
```
- Calculates the midpoint of the current segment of the array using a safe way to avoid overflow.

```cpp
int left = mid - s + 1;
int right = e - mid;
```
- Determines the lengths of the left and right subarrays:
  - `left` is the length of the left half.
  - `right` is the length of the right half.

```cpp
int *temp = new int[left + right];
```
- Allocates a temporary array `temp` to hold the merged values of the two halves.

```cpp
int i = s;
int j = mid + 1;
int k = 0;
```
- Initializes three indices:
  - `i` for iterating over the left half (starting from `s`).
  - `j` for iterating over the right half (starting from `mid + 1`).
  - `k` for tracking the index in the temporary array.

### Merging Process

```cpp
while(i <= mid && j <= e){
    if(arr[i] < arr[j]){
        temp[k++] = arr[i++];
    }else{
        temp[k++] = arr[j++];
    }
}
```
- This loop merges the two halves:
  - Compares elements from both halves. 
  - If the element from the left half (`arr[i]`) is smaller, it's added to `temp`, and `i` is incremented.
  - If the element from the right half (`arr[j]`) is smaller, it is added to `temp`, and `j` is incremented.
  - The `k` index is incremented to move to the next position in `temp`.

```cpp
while(i <= mid){
    temp[k++] = arr[i++];
}
```
- After the first loop, if there are any remaining elements in the left half (not yet added to `temp`), they are copied over.

```cpp
while(j <= e){
    temp[k++] = arr[j++];
}
```
- Similarly, this loop copies any remaining elements from the right half.

### Copy Back to Original Array

```cpp
for(int x = 0; x < left + right; x++){
    arr[s + x] = temp[x];
}
```
- Copies the sorted values from the `temp` array back into the original `arr` from index `s` to `e`.

```cpp
delete []temp;
```
- Deallocates the temporary array to free memory, preventing memory leaks.

### Merge Sort Function

```cpp
public:
void mergeSort(int arr[], int s, int e)
{
```
- This public method `mergeSort` takes the same parameters, `arr`, `s`, and `e`, to perform the sorting.

```cpp
if(s >= e) return;
```
- Base case: If the starting index is greater than or equal to the ending index, the segment is already sorted, and the function returns.

```cpp
int mid = s + (e - s) / 2;
```
- Calculates the midpoint for dividing the array.

```cpp
mergeSort(arr, s, mid);
mergeSort(arr, mid + 1, e);
```
- Recursively calls `mergeSort` for the left half (`s` to `mid`) and the right half (`mid + 1` to `e`).

```cpp
merge(arr, s, e);
```
- After sorting the two halves, it calls the `merge` function to combine them back into the original array in sorted order.

### Conclusion

The `Solution` class effectively implements the Merge Sort algorithm through the `merge` and `mergeSort` methods. It divides the array recursively and merges the sorted subarrays efficiently. The overall time complexity of this algorithm is \(O(n \log n)\), and the space complexity is \(O(n)\) due to the temporary array used for merging.
