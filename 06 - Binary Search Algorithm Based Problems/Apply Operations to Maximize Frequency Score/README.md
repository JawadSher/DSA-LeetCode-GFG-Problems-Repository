# Apply Operations to Maximize Frequency Score

Given an array `nums` and an integer `k`, you need to find the maximum frequency of any number in the array after performing at most `k` operations. Each operation increments an element by 1. The goal is to determine the maximum possible frequency of any number with these operations.

## Approach to Solve the Problem

1.  **Sort the Array:**
    
    -   Sorting helps in efficiently calculating the number of operations needed to make a subarray of elements equal.
2.  **Prefix Sum Array:**
    
    -   Use this array to quickly compute the sum of any subarray, which helps in calculating operations required.
3.  **Binary Search:**
    
    -   Perform binary search to find the maximum frequency. Check feasibility for different frequencies using a helper function.
4.  **Feasibility Check (`isPossible` function):**
    
    -   Determine if it's possible to achieve a given frequency with at most `k` operations.

## Source Code Explanation

### `isPossible` Function

This function checks whether it's possible to achieve a frequency of `len` for any number with at most `k` operations.




``` 
bool isPossible(int len, const vector<int>& nums, const vector<ll>& prefix, ll k, int n) {
``` 

-   **Line 1:** Defines the `isPossible` function that takes the desired frequency `len`, the sorted array `nums`, the prefix sum array `prefix`, the maximum allowed operations `k`, and the size of the array `n`.



 
``` 
int s = 0;
int e = len - 1;
``` 

-   **Line 2-3:** Initializes two pointers `s` (start of the window) and `e` (end of the window) to represent a window of size `len`.



 
``` 
while (e < n) {
```  

-   **Line 4:** Starts a while loop that slides the window across the array as long as `e` is within bounds.



 
``` 
ll target_idx = s + (e - s) / 2;
ll target_num = nums[target_idx];
``` 

-   **Line 5-6:** Calculates `target_idx` as the median index within the window and `target_num` as the value at this median index.



 ```
ll operation_left = 0;
ll operation_right = 0;
``` 

-   **Line 7-8:** Initializes variables `operation_left` and `operation_right` to store the number of operations needed for the left and right parts of the window.


 
``` 
if (target_idx == 0) {
            operation_left = 0;
        } else {
            operation_left = ((target_idx - s) * target_num) - (prefix[target_idx - 1] - (s > 0 ? prefix[s - 1] : 0));
        }
``` 

-   **Line 9-13:** Calculates `operation_left`:
    -   **Line 9:** If `target_idx` is 0, no elements are to the left, so `operation_left` is 0.
    -   **Line 11-12:** Otherwise, compute the cost to make all elements from `s` to `target_idx` equal to `target_num`. This is done by:
        -   Calculating the total sum needed (`(target_idx - s) * target_num`).
        -   Subtracting the current sum of these elements (`prefix[target_idx - 1] - (s > 0 ? prefix[s - 1] : 0)`).



 
```
operation_right = (prefix[e] - prefix[target_idx]) - ((e - target_idx) * target_num);
```  

-   **Line 14:** Calculates `operation_right`:
    -   Compute the cost to make all elements from `target_idx + 1` to `e` equal to `target_num`.
    -   This is done by:
        -   Calculating the total sum needed (`(e - target_idx) * target_num`).
        -   Subtracting the current sum of these elements (`prefix[e] - prefix[target_idx]`).



 
``` 
if (operation_right + operation_left <= k) {
            return true;
        }
```  

-   **Line 15-16:** If the sum of `operation_right` and `operation_left` is less than or equal to `k`, it's possible to achieve the frequency `len` and the function returns `true`.



 
``` 
	s++;
	e++;
	  }
	return false;
}
```  

-   **Line 17-19:** Move the window one step to the right by incrementing `s` and `e`. If no valid window is found, return `false`.

### `maxFrequencyScore` Function

This function uses binary search to find the maximum frequency that can be achieved.




``` 
int maxFrequencyScore(vector<int>& nums, long long k) {
    int n = nums.size();
    sort(nums.begin(), nums.end()); 

``` 
-   **Line 1-2:** Defines the `maxFrequencyScore` function. Initializes `n` as the size of `nums` and sorts `nums`.




``` 
vector<ll> prefix(n, 0);
    prefix[0] = nums[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + nums[i];
    }
``` 
-   **Line 3-7:** Initializes and fills the `prefix` sum array:
    -   **Line 4:** Sets the first element of `prefix`.
    -   **Line 5-7:** Computes the prefix sum for each index.



 
```
int min_score = 1;
    int max_score = n;
    int result = 0;
```

-   **Line 8-10:** Initializes binary search bounds (`min_score` and `max_score`) and `result` to store the maximum frequency.


 
``` 
while (min_score <= max_score) {
        int win_size = min_score + (max_score - min_score) / 2;
```  

-   **Line 11-12:** Performs binary search by calculating `win_size` as the midpoint of the current range.



 
```
if (isPossible(win_size, nums, prefix, k, n)) {
            result = win_size;
            min_score = win_size + 1;
        } else {
            max_score = win_size - 1;
        }
    }
``` 

-   **Line 13-18:** Checks if achieving `win_size` frequency is possible:
    -   **Line 14:** Calls `isPossible` with the current `win_size`.
    -   **Line 15-16:** If possible, update `result` and search in the higher half (`min_score = win_size + 1`).
    -   **Line 17:** If not possible, search in the lower half (`max_score = win_size - 1`).


 ```
 return result;
}
``` 

-   **Line 19:** Returns `result`, which is the maximum frequency achievable.

### Time and Space Complexity

-   **Time Complexity:**
    
    -   Sorting the array: O(n log ⁡n) O(n log n) O(n log n).
    -   Binary search: O(log⁡ n) O(log n) O(logn) iterations, each requiring O(n) O(n) O(n) work (for the `isPossible` function).
    -   Overall complexity: O(n log⁡ n) O(n log n) O(n log n).
-   **Space Complexity:**
    
    -   Prefix sum array: O(n) O(n) O(n).
    -   Other space usage: Constant.
    -   Overall complexity: O(n) O(n) O(n).
