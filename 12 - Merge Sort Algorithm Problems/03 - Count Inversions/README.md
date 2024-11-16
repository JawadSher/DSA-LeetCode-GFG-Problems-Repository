<h1 align='center'>Count - Inversions</h1>

## Problem Statement

**Problem URL :** [Count Inversions](https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/d9687734-fb6e-4b2e-8a4b-e918f47e0a73)
![image](https://github.com/user-attachments/assets/bf574c31-b93b-401a-8e1b-37e9d1c65d72)


## Problem Solution
```cpp
class Solution {
  public:
  
    long long inversions = 0;
    
    void merge(vector<long long> &arr, long long s, long long e){
        long long mid = s + (e - s)/2;
        
        long long left = mid - s + 1;
        long long right = e - mid;
        
        long long i = s;
        long long j = mid+1;
        long long k = 0;
        
        long long *temp = new long long[left+right];
        
        while(i <= mid && j <= e){
            if(arr[i] <= arr[j]){
                temp[k++] = arr[i++];
            }else{
                temp[k++] = arr[j++];
                inversions += (mid - i + 1);
            }
        }
        
        while(i <= mid){
            temp[k++] = arr[i++];
        }
        
        while(j <= e){
            temp[k++] = arr[j++];
        }
        
        for(long long i = 0; i < left+right; i++){
            arr[s+i] = temp[i];
        }
        
        delete [] temp;
    };
    
    void mergeSort(vector<long long> &arr, long long s, long long e){
        if(s >= e) return;
        
        long long mid = s + (e - s) /2;
        
        mergeSort(arr, s, mid);
        mergeSort(arr, mid+1, e);
        
        merge(arr, s, e);
    };
    
    long long int inversionCount(vector<long long> &arr) {
        inversions = 0;
        
        int s = 0;
        int e = arr.size() -1;
        
        mergeSort(arr, s, e);
        
        return inversions;
    }
};
```

## Problem Solution Explanation
Let's break down the provided `Solution` class that counts inversions in an array using the Merge Sort algorithm, explaining each line in detail.

### Class Definition

```cpp
class Solution {
```
- This defines a class named `Solution`, typically used for implementing algorithms in competitive programming.

### Member Variable

```cpp
public:
long long inversions = 0;
```
- Declares a public member variable `inversions` to keep track of the count of inversions in the array. It is initialized to `0`.

### Merge Function

```cpp
void merge(vector<long long> &arr, long long s, long long e) {
```
- This public method `merge` takes a reference to a vector `arr` and two indices, `s` (start) and `e` (end), for merging the two halves of the array.

```cpp
long long mid = s + (e - s) / 2;
```
- Calculates the midpoint of the current segment using a safe method to prevent overflow.

```cpp
long long left = mid - s + 1;
long long right = e - mid;
```
- Determines the lengths of the left and right halves:
  - `left` is the number of elements in the left half.
  - `right` is the number of elements in the right half.

```cpp
long long i = s;
long long j = mid + 1;
long long k = 0;
```
- Initializes three indices:
  - `i` for the left half, starting from `s`.
  - `j` for the right half, starting from `mid + 1`.
  - `k` for the temporary array's index.

```cpp
long long *temp = new long long[left + right];
```
- Allocates a temporary array `temp` to hold the merged values from the two halves.

### Merging Process with Inversion Count

```cpp
while(i <= mid && j <= e) {
```
- This loop continues as long as both pointers `i` and `j` are within their respective halves.

```cpp
if(arr[i] <= arr[j]) {
    temp[k++] = arr[i++];
} else {
    temp[k++] = arr[j++];
    inversions += (mid - i + 1);
}
```
- Compares the current elements from both halves:
  - If the element in the left half (`arr[i]`) is less than or equal to that in the right half (`arr[j]`), it adds `arr[i]` to `temp` and increments `i`.
  - If `arr[j]` is smaller, it adds `arr[j]` to `temp`, increments `j`, and counts the inversions:
    - The number of inversions is incremented by `(mid - i + 1)` because all remaining elements in the left half (from `i` to `mid`) are greater than `arr[j]`.

```cpp
while(i <= mid) {
    temp[k++] = arr[i++];
}
```
- After the first loop, if there are remaining elements in the left half, they are copied to `temp`.

```cpp
while(j <= e) {
    temp[k++] = arr[j++];
}
```
- Similarly, this loop copies any remaining elements from the right half to `temp`.

### Copy Back to Original Array

```cpp
for(long long i = 0; i < left + right; i++) {
    arr[s + i] = temp[i];
}
```
- Copies the sorted values from the `temp` array back into the original `arr` from index `s` to `e`.

```cpp
delete [] temp;
```
- Deallocates the temporary array to free memory and prevent memory leaks.

### Merge Sort Function

```cpp
void mergeSort(vector<long long> &arr, long long s, long long e) {
```
- This public method `mergeSort` takes a reference to the array and indices `s` and `e` to perform sorting.

```cpp
if(s >= e) return;
```
- Base case: If the starting index is greater than or equal to the ending index, the segment is already sorted, and the function returns.

```cpp
long long mid = s + (e - s) / 2;
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
- After sorting the two halves, it calls the `merge` function to combine them back into the original array in sorted order and count inversions.

### Inversion Count Function

```cpp
long long int inversionCount(vector<long long> &arr) {
```
- This public method counts the number of inversions in the array.

```cpp
inversions = 0;
```
- Resets the `inversions` count to `0` before starting the counting process.

```cpp
int s = 0;
int e = arr.size() - 1;
```
- Initializes the start (`s`) and end (`e`) indices for the whole array.

```cpp
mergeSort(arr, s, e);
```
- Calls the `mergeSort` function to sort the array and count inversions.

```cpp
return inversions;
}
```
- Returns the total count of inversions.

### Summary

This class effectively counts the number of inversions in an array using a modified Merge Sort algorithm. The overall time complexity of this algorithm is \(O(n \log n)\), and the space complexity is \(O(n)\) due to the temporary array used for merging. An inversion is defined as a pair of indices \( (i, j) \) such that \( i < j \) and \( arr[i] > arr[j] \).
