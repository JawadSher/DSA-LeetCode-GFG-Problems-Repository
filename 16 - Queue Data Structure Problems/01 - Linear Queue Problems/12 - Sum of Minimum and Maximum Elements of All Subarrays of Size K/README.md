<h1 align='center'>Sum - of - Minimum & Maximum - Elements - of All - Subarrays of - Size K</h1>

## Problem Statement

**Problem URL :** [Sum of Minimum and Maximum Elements of All Subarrays of Size K](https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/)


**Problem:** Given an array of integers and a window size \( k \), calculate the sum of the maximum and minimum elements for each sliding window of size \( k \). 

**Example:** 
- Input: `arr = [2, 5, -1, 7, -3, -1, -2]`, \( k = 4 \)
- Output: The result should be the sum of maximum and minimum elements for each of the sliding windows of size \( k \).

**Windows:**
1. `[2, 5, -1, 7]` => Max = 7, Min = -1 => Sum = 6
2. `[5, -1, 7, -3]` => Max = 7, Min = -3 => Sum = 4
3. `[-1, 7, -3, -1]` => Max = 7, Min = -3 => Sum = 4
4. `[7, -3, -1, -2]` => Max = 7, Min = -3 => Sum = 4

**Final Output:** The sum of these results for all windows.

## Problem Solution
```cpp
#include <iostream>
#include <deque>
using namespace std;

int solve(int *arr, int n, int k){
  deque<int> maxi(k);
  deque<int> mini(k);

  // Addition of first k size window
  for(int i = 0; i < k; i++){
    while(!maxi.empty() && arr[maxi.back()] <= arr[i]) maxi.pop_back();
    while(!mini.empty() && arr[mini.back()] >= arr[i]) mini.pop_back();

    maxi.push_back(i);
    mini.push_back(i);
  }

  int ans = 0;
  ans += arr[maxi.front()] + arr[mini.front()];

  // Process remaining windows
  for(int i = k; i < n; i++){

    // next window
      // removal
      while(!maxi.empty() && i - maxi.front() >= k) maxi.pop_front();
      while(!mini.empty() && i - mini.front() >= k) mini.pop_front();

      // Addition
      while(!maxi.empty() && arr[maxi.back()] <= arr[i]) maxi.pop_back();
      while(!mini.empty() && arr[mini.back()] >= arr[i]) mini.pop_back();

    maxi.push_back(i);
    mini.push_back(i);

    ans += arr[maxi.front()] + arr[mini.front()];
  }

  return ans;
}

int main() {
  int arr[7] = {2, 5, -1, 7, -3, -1, -2};
  int k = 4;

  cout << "Result : " << solve(arr, 7, k) << endl;
  return 0;
}
```

## Problem Solution Explanation

Let’s go through the code line by line with examples:

```cpp
#include <iostream>
#include <deque>
using namespace std;

int solve(int *arr, int n, int k) {
    deque<int> maxi(k); // Deque to store indices of max elements
    deque<int> mini(k); // Deque to store indices of min elements
```
- **Includes and Namespace:** The code includes the necessary headers and uses the `std` namespace.
- **Function Signature:** `solve` takes an array, its size `n`, and the window size `k`.
- **Deques Initialization:** Two deques are initialized to store indices of the maximum and minimum elements within the current window.

```cpp
    // Addition of first k size window
    for (int i = 0; i < k; i++) {
        while (!maxi.empty() && arr[maxi.back()] <= arr[i]) maxi.pop_back();
        while (!mini.empty() && arr[mini.back()] >= arr[i]) mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }
```
- **First Window Processing:** The loop runs for the first \( k \) elements:
  - For each element, we remove indices from the back of `maxi` if the current element is greater or equal (to maintain max).
  - Similarly, we remove indices from `mini` if the current element is smaller or equal (to maintain min).
  - Finally, we add the current index to both `maxi` and `mini`.

**Example for `k=4`:**
- For `i=0`: `maxi=[0]`, `mini=[0]` (Element 2)
- For `i=1`: `maxi=[1]`, `mini=[0,1]` (Element 5)
- For `i=2`: `maxi=[1]`, `mini=[2]` (Element -1)
- For `i=3`: `maxi=[3]`, `mini=[2]` (Element 7)

After this loop, `maxi` contains the index of the maximum element (7 at index 3) and `mini` contains the index of the minimum element (-1 at index 2).

```cpp
    int ans = 0;
    ans += arr[maxi.front()] + arr[mini.front()];
```
- **Initial Answer Calculation:** The sum of the maximum and minimum for the first window is calculated and stored in `ans`.

```cpp
    // Process remaining windows
    for (int i = k; i < n; i++) {
```
- **Sliding Window:** The loop processes the remaining windows.

```cpp
        // next window
        // removal
        while (!maxi.empty() && i - maxi.front() >= k) maxi.pop_front();
        while (!mini.empty() && i - mini.front() >= k) mini.pop_front();
```
- **Removing Out-of-Bound Indices:** This ensures that the indices in the deques are within the current window size by popping indices that are no longer valid.

```cpp
        // Addition
        while (!maxi.empty() && arr[maxi.back()] <= arr[i]) maxi.pop_back();
        while (!mini.empty() && arr[mini.back()] >= arr[i]) mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
```
- **Adding Current Element:** Similar to the first window, we remove elements that are not needed and then add the current index.

```cpp
        ans += arr[maxi.front()] + arr[mini.front()];
    }
```
- **Update Answer:** We add the sum of the current window’s maximum and minimum to `ans`.

```cpp
    return ans;
}
```
- **Return Final Result:** The final sum is returned.

```cpp
int main() {
    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;

    cout << "Result : " << solve(arr, 7, k) << endl;
    return 0;
}
```
- **Main Function:** Initializes the array and calls the `solve` function, printing the result.

### Time and Space Complexities

#### 1. **Space Complexity:**

- The space complexity is determined by the deques, which store indices.
- The maximum size of both `maxi` and `mini` is \( k \), and they only hold at most \( k \) indices at a time.

**Space Complexity:**
\[
O(k)
\]

#### 2. **Time Complexity:**

- The outer loop runs \( n - k + 1 \) times (for each sliding window).
- Each inner while loop for both `maxi` and `mini` can remove elements up to \( k \) in the worst case for each iteration of the outer loop.
- Hence, each element is added and removed from the deques at most once.

**Time Complexity:**
\[
O(n)
\]

### Summary of Complexities:

- **Time Complexity:** \( O(n) \) - Efficiently processes each element a constant number of times.
- **Space Complexity:** \( O(k) \) - Requires space for two deques of size at most \( k \).

This implementation efficiently computes the desired sums for sliding windows using the properties of deques to maintain maximum and minimum values, making it well-suited for large datasets.
