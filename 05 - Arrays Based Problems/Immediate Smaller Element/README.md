<h1 align='center'>Immediate - Smaller - Element</h1>

## Problem Statement

**Problem URL :** [Immediate Smaller Element](https://www.geeksforgeeks.org/problems/immediate-smaller-element1142/1)

![image](https://github.com/user-attachments/assets/77a28c04-3b2b-4ed5-b237-e0a37223550b)
![image](https://github.com/user-attachments/assets/cca7b52e-8cfc-4ca9-b8fe-6e0efc3f9eec)

## Problem Explanation


**Objective**: Given an array of integers, replace each element in the array with the immediate smaller element that comes after it. If no such element exists, replace it with `-1`. The last element should always be replaced with `-1`.

### Approach

1. **Iterate Through the Array**: Loop through the array from the first element to the second-to-last element.
2. **Comparison**: For each element, compare it with the next element.
3. **Replacement**:
   - If the current element is greater than the next, replace it with the next element.
   - If not, replace it with `-1`.
4. **Handle Last Element**: Set the last element to `-1`.


## Problem Solution
```cpp
class Solution{
public:	
	void immediateSmaller(vector<int>&arr, int n) {
	    for(int i = 0; i < n-1; i++){
	        if(arr[i] > arr[i+1]){
	            arr[i] = arr[i+1];
	        }else{
	            arr[i] = -1;
	        }
	    }
	    
	    arr[n-1] = -1;
	}

};
```

## Problem Solution Explanation
Let's break down the provided C++ code for the `immediateSmaller` function, including the problem statement, a detailed explanation of the code, and examples.

#### Function Definition

```cpp
void immediateSmaller(vector<int>& arr, int n) {
```
- **Input Parameters**:
  - `vector<int>& arr`: A reference to the input array.
  - `int n`: The size of the array.

#### Main Loop

```cpp
for(int i = 0; i < n-1; i++){
```
- Loop through the array from index `0` to `n-2` (the second-to-last index).

---

#### Comparison and Replacement

```cpp
if(arr[i] > arr[i+1]){
    arr[i] = arr[i+1];
}else{
    arr[i] = -1;
}
```
- For each element `arr[i]`:
  - **If** `arr[i]` is greater than `arr[i+1]`, replace `arr[i]` with `arr[i+1]` (the immediate smaller element).
  - **Else**, replace `arr[i]` with `-1` (indicating no smaller element).

---

#### Handle the Last Element

```cpp
arr[n-1] = -1;
```
- After the loop, set the last element in the array to `-1`.

---

### Example Walkthrough

Let’s see how the function works with an example.

#### Input

```cpp
arr = [4, 3, 2, 1, 5]
n = 5
```

#### Step-by-Step Execution

1. **Initialization**:
   - Initial array: `[4, 3, 2, 1, 5]`

2. **Iteration**:
   - **i = 0**: Compare `4` (arr[0]) and `3` (arr[1]):
     - `4 > 3`, so replace `arr[0]` with `3`: `[3, 3, 2, 1, 5]`
   - **i = 1**: Compare `3` (arr[1]) and `2` (arr[2]):
     - `3 > 2`, so replace `arr[1]` with `2`: `[3, 2, 2, 1, 5]`
   - **i = 2**: Compare `2` (arr[2]) and `1` (arr[3]):
     - `2 > 1`, so replace `arr[2]` with `1`: `[3, 2, 1, 1, 5]`
   - **i = 3**: Compare `1` (arr[3]) and `5` (arr[4]):
     - `1 < 5`, so replace `arr[3]` with `-1`: `[3, 2, 1, -1, 5]`

3. **Handle Last Element**:
   - Set `arr[4]` to `-1`: `[3, 2, 1, -1, -1]`

#### Final Output

```cpp
arr = [3, 2, 1, -1, -1]
```

### Summary

The function `immediateSmaller` replaces each element in the array with the next smaller element to the right or `-1` if no such element exists, ensuring the last element is always set to `-1`. The algorithm operates in O(n) time complexity since it makes a single pass through the array and O(1) space complexity as it modifies the input array in place.
