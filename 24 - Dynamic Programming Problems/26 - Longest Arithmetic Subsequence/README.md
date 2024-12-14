<h1 align="center">Longest - Arithmetic - Subsequence</h1>

## Problem Statement

**Problem URL (GFG):** [Longest Arithmetic Subsequence](https://www.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1)

**Problem URL (leetcode):** [Longest Arithmetic Subsequence](https://leetcode.com/problems/longest-arithmetic-subsequence/description/)

![image](https://github.com/user-attachments/assets/b37970ff-1d21-45bc-afd4-aeb6f8aaeff9)

### Problem Explanation
The problem **"Longest Arithmetic Progression"** (LAP) asks you to find the length of the longest subsequence in an array that forms an arithmetic progression (AP). 

An **arithmetic progression (AP)** is a sequence of numbers where the difference between any two consecutive terms is constant. For example:
- (2, 4, 6, 8) (Common difference: (+2))
- (10, 7, 4, 1) (Common difference: (-3))

In this problem, you are given an **array of integers**, and you need to find the **maximum length** of a subsequence that can form an AP. 

### **Important Points**:
1. **Subsequence**:
   - A subsequence is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.
   - Example: For the array ([1, 7, 3, 9]), possible subsequences include:
     - ([1, 7, 9])
     - ([1, 3, 9])
     - ([7, 9]), etc.

2. **You do not need to rearrange the array**.
   - The elements of the subsequence must follow the same order as in the given array.

### **Objective**:
Find the length of the **longest subsequence** that forms an AP.

### **Examples**:

#### **Example 1**:
**Input**: 
`{arr} = [1, 7, 10, 13, 14, 19]`

**Explanation**:
- Subsequence ([1, 10, 19]) forms an AP with a common difference of (+9).
- Subsequence ([1, 7, 13, 19]) forms an AP with a common difference of (+6).
- The longest AP here is ([1, 7, 13, 19]), which has a length of **4**.

**Output**: 
`4`

#### **Example 2**:
**Input**: 
`{arr} = [2, 4, 6, 8, 10]`

**Explanation**:
- The entire array ([2, 4, 6, 8, 10]) is an AP with a common difference of (+2).
- The longest AP is the whole array, with a length of **5**.

**Output**: 
`5`

#### **Example 3**:
**Input**: 
`{arr} = [1, 5, 7, 8, 10, 15, 20]`

**Explanation**:
- Subsequence ([1, 7, 13, 19]) forms an AP with a common difference of (+6).
- Subsequence ([5, 10, 15, 20]) forms an AP with a common difference of (+5).
- The longest AP here is ([5, 10, 15, 20]), which has a length of **4**.

**Output**: 
`4`

### **Constraints**:
1. The array size ((n)) can go up to (10^3).
2. The elements of the array are integers.

### **Key Notes**:
- The AP does not need to be contiguous in the array.
- You can have both positive and negative differences in AP.
- The problem focuses on identifying **subsequences**, not subarrays.

---

## Recursive Approach (caused TLE)
The goal is to find the **length of the longest arithmetic progression (LAP)** in the given array. A recursive approach explores all possible subsequences in the array, considering every pair of elements and checking if they can extend a previously established arithmetic progression.


### **Key Concepts**:
1. **Arithmetic Progression**:
   - A sequence is an AP if the difference between consecutive elements is constant.
   - For example:
     - ( [1, 4, 7, 10] ) is an AP with difference ( 3 ).
     - ( [10, 7, 4, 1] ) is an AP with difference ( -3 ).

2. **Recursive Definition**:
   - Let ( text{solve(arr, index, diff)} ) represent the **length of the longest AP ending at `arr[index]`** with a given common difference `diff`.
   - If there exists an earlier element ( arr[j] ) such that ( arr[index] - arr[j] = text{diff} ), then:
     `{solve(arr, index, diff)} = 1 + text{solve(arr, j, diff)}`
     
   - Otherwise, the length is simply ( 1 ), since ( arr[index] ) itself is part of an AP of length ( 1 ).

3. **Base Case**:
   - If ( text{index} < 0 ), return ( 0 ), as no valid AP can exist.

4. **Final Result**:
   - For every pair of elements ( (arr[i], arr[j]) ), calculate the common difference ( text{diff} = arr[j] - arr[i] ).
   - Use the recursive function to determine the LAP ending at ( arr[i] ) with that difference and find the global maximum.


### Source Code
```cpp
class Solution {
  public:
    // Helper function to recursively find the length of the longest arithmetic progression (AP)
    // ending at the current index with a given common difference `diff`.
    int solve(vector<int>& arr, int index, int diff) {
        // Base case: if the index goes out of bounds, return 0
        if(index < 0) return 0;

        int ans = 0;
        // Iterate backwards from the current index to find elements that can form an AP
        for(int j = index - 1; j >= 0; j--) {
            // Check if the difference between arr[index] and arr[j] matches the given `diff`
            if(arr[index] - arr[j] == diff) {
                // Recursively find the length of AP ending at arr[j] and update `ans`
                ans = max(ans, 1 + solve(arr, j, diff));
            }
        }
        
        // Return the maximum length of AP found
        return ans;
    }
    
    // Function to find the length of the longest arithmetic progression in the array
    int lengthOfLongestAP(vector<int>& arr) {
        int n = arr.size();
        
        // If the array has 2 or fewer elements, the entire array is an AP
        if(n <= 2) return n;

        int ans = 0;
        // Iterate through all pairs of elements to calculate the common difference `diff`
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                // Calculate the common difference and start a recursive search
                // The length of the AP is at least 2 (the current pair)
                ans = max(ans, 2 + solve(arr, i, arr[j] - arr[i]));
            }
        }
        
        // Return the maximum length of the AP found
        return ans;
    }
};
```

### Source Code Explanation

#### **1. Class Definition and Function Signature**:
```cpp
class Solution {
  public:
```
- **Explanation**: This defines a class called `Solution`. The class has a `public` access modifier, meaning its members (functions, variables) are accessible from outside the class.
  
#### **2. `solve` Function - Helper for Recursion**:
```cpp
    int solve(vector<int>& arr, int index, int diff) {
```
- **Explanation**: This defines a helper function `solve`. It takes three parameters:
  - `arr`: the array in which we are looking for an Arithmetic Progression (AP).
  - `index`: the current index in the array for which we are checking the AP.
  - `diff`: the common difference between the terms of the AP we are trying to find.
- The goal of this function is to find the length of the longest AP ending at the given index with the specified common difference `diff`.

#### **3. Base Case - Index Out of Bounds**:
```cpp
        if(index < 0) return 0;
```
- **Explanation**: This is the base case of the recursion. If `index` is less than 0, it means we've gone out of bounds of the array. In this case, return 0 because no AP can end before the first element.
  
#### **4. Initialize `ans`**:
```cpp
        int ans = 0;
```
- **Explanation**: Here, we initialize `ans` to 0. `ans` will keep track of the length of the longest AP ending at the current index `index` with the common difference `diff`.

#### **5. Iterate through all previous elements**:
```cpp
        for(int j = index - 1; j >= 0; j--) {
```
- **Explanation**: We start iterating backward through all the elements before the current `index`. The loop starts from `index - 1` and goes down to 0, checking if the current element (`arr[index]`) can extend the AP formed by the previous elements.
  
#### **6. Check if the current element can extend the AP**:
```cpp
            if(arr[index] - arr[j] == diff) {
```
- **Explanation**: Here, we check if the difference between `arr[index]` and `arr[j]` matches the `diff` (i.e., `arr[index]` and `arr[j]` form a valid progression with the given common difference). If this condition is true, it means that `arr[j]` can be part of an AP ending at `arr[index]` with the common difference `diff`.

#### **7. Recursively calculate the AP length**:
```cpp
                ans = max(ans, 1 + solve(arr, j, diff));
```
- **Explanation**: If the condition is met, we recursively call the `solve` function for the element `arr[j]` with the same common difference `diff`. This will check if `arr[j]` can further extend the AP. We add 1 to the result because `arr[index]` is a new element in the AP.
- The `max(ans, 1 + solve(...))` ensures we always keep the maximum AP length.

#### **8. Return the result**:
```cpp
        return ans;
```
- **Explanation**: Once the loop finishes, we return the value of `ans`, which represents the length of the longest AP that ends at `arr[index]` with the difference `diff`.



#### **9. Main Function - `lengthOfLongestAP`**:
```cpp
    int lengthOfLongestAP(vector<int>& arr) {
```
- **Explanation**: This is the main function that will calculate the length of the longest AP in the array. It takes one parameter:
  - `arr`: the array in which we are looking for the longest AP.

#### **10. If Array has 2 or Fewer Elements**:
```cpp
        if(n <= 2) return n;
```
- **Explanation**: If the array contains 2 or fewer elements, it is trivially an AP because any sequence with 2 or fewer elements forms an AP. In this case, we return `n` (the number of elements in the array).

#### **11. Initialize `ans`**:
```cpp
        int ans = 0;
```
- **Explanation**: `ans` is initialized to 0. It will hold the length of the longest AP found during the execution of the function.

#### **12. Iterate Over All Pairs**:
```cpp
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
```
- **Explanation**: We iterate over all pairs of elements `(arr[i], arr[j])` where `i < j`. These pairs are the starting points of potential APs. We will calculate the common difference between these two elements and then recursively find the longest AP ending at `arr[i]` with that common difference.

#### **13. Calculate Common Difference `diff`**:
```cpp
                int diff = arr[j] - arr[i];
```
- **Explanation**: The common difference `diff` is calculated as `arr[j] - arr[i]`. This difference will be used to check if the sequence can form an AP.

#### **14. Call `solve` to Find LAP Ending at `arr[i]`**:
```cpp
                ans = max(ans, 2 + solve(arr, i, diff));
```
- **Explanation**: For each pair `(arr[i], arr[j])`, we calculate the maximum length of the AP that can be formed starting with this pair. The length of the AP is at least 2 (the current pair), and we add the result of `solve(arr, i, diff)` to this count.

#### **15. Return the Final Answer**:
```cpp
        return ans;
    }
};
```
- **Explanation**: After all pairs have been checked, we return `ans`, which now contains the length of the longest AP found.


### **Example Walkthrough**:

#### **Input Array**: [1, 7, 10, 13, 14, 19]

- **First iteration (i=0, j=1)**:
  - The common difference `diff = 7 - 1 = 6`
  - Recursively check the AP ending at `arr[0]` with `diff = 6`. The AP is `[1, 7]` with length 2.

- **Second iteration (i=1, j=2)**:
  - The common difference `diff = 10 - 7 = 3`
  - The AP starting with `arr[1]` and `arr[2]` can be `[7, 10]` with length 2.

- **Continue for other pairs** until the longest AP `[7, 10, 13, 19]` is found.


### **Time and Space Complexity**:

#### **Time Complexity**:
- The solution involves two nested loops, each iterating over the array. The outer loop runs (O(n)) and the inner loop also runs (O(n)), so the overall time complexity is (O(n^2)).
- The `solve` function has a recursive call, but it does not result in excessive computation due to overlapping subproblems, as it is not memoized in the basic form.

Thus, the **time complexity** is (O(n^2)).

#### **Space Complexity**:
- The space complexity is determined by the recursive calls and the data structures used (such as the `dp` array).
- Since there are no additional data structures being used (like memoization), the **space complexity** is (O(n)) due to the recursion stack.

---

## Top-Down Approach (DP)
The goal of the problem is to find the **Longest Arithmetic Progression (LAP)** in an array. An Arithmetic Progression is a sequence where the difference between consecutive terms is constant. For instance, `[1, 3, 5, 7]` has a common difference of `2`.

#### **Top-Down Dynamic Programming Approach**:
In the top-down approach, we use **recursion** combined with **memoization** to compute the length of the longest arithmetic progression (LAP) efficiently.

1. **Recursive Function**:
   - The recursive function `solve` is designed to calculate the length of the longest AP that ends at a given index `index` with a specific common difference `diff`.
   - **Memoization**: We use a `dp` array (unordered map) to store the results of subproblems. This way, if we need the result for the same `index` and `diff` again, we can simply return the cached result instead of recalculating it.

2. **Main Function**:
   - The function `lengthOfLongestAP` iterates over all pairs of elements `(arr[i], arr[j])` in the array and calculates the common difference `diff = arr[j] - arr[i]`.
   - For each pair, we use the recursive `solve` function to compute the length of the AP ending at index `i` with the common difference `diff`.

3. **Base Case**:
   - The base case of the recursion is when the `index` is less than `0`, in which case the function returns `0` because there are no valid APs.

4. **Final Result**:
   - After iterating through all pairs, the function returns the maximum length of any AP found.

### Source Code
```cpp
class Solution {
  public:
    // Helper function to recursively find the length of the longest arithmetic progression (AP)
    // ending at the current index `index` with a given common difference `diff`.
    // The `dp` array is used for memoization to avoid redundant computations.
    int solve(vector<int>& arr, int index, int diff, unordered_map<int, int> dp[]) {
        // Base case: if the index goes out of bounds, return 0
        if(index < 0) return 0;

        // If the result for the current `index` and `diff` is already calculated, return it
        if(dp[index].count(diff)) return dp[index][diff];
        
        int ans = 0;
        // Iterate backward from the current index to find elements that can extend the AP
        for(int j = index - 1; j >= 0; j--) {
            // Check if the difference between arr[index] and arr[j] matches the given `diff`
            if(arr[index] - arr[j] == diff) {
                // Recursively find the length of the AP ending at arr[j] and update `ans`
                ans = max(ans, 1 + solve(arr, j, diff, dp));
            }
        }
        
        // Store the result in the `dp` array and return it
        return dp[index][diff] = ans;
    }
    
    // Function to find the length of the longest arithmetic progression (AP) in the array
    int lengthOfLongestAP(vector<int>& arr) {
        int n = arr.size();
        
        // If the array has 2 or fewer elements, the entire array is an AP
        if(n <= 2) return n;
        
        // `dp[i]` is an unordered map where the key is the difference `diff` and the value
        // is the length of the longest AP ending at index `i` with that difference
        unordered_map<int, int> dp[n + 1];
        
        int ans = 0; // Variable to store the maximum length of AP found
        // Iterate through all pairs of elements to calculate the common difference `diff`
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                // Calculate the common difference and start a recursive search
                // The length of the AP is at least 2 (the current pair)
                ans = max(ans, 2 + solve(arr, i, arr[j] - arr[i], dp));
            }
        }
        
        // Return the maximum length of AP found
        return ans;
    }
};
```
### Source Code Explanation

#### **1. Class Definition and Function Signature**:
```cpp
class Solution {
  public:
```
- This defines a class `Solution`. It contains the method `lengthOfLongestAP` to find the length of the longest arithmetic progression.

#### **2. `solve` Function**:
```cpp
    int solve(vector<int>& arr, int index, int diff, unordered_map<int, int> dp[]) {
```
- This helper function is responsible for calculating the length of the longest arithmetic progression (AP) ending at the current index `index` with a common difference `diff`. 
- **Parameters**:
  - `arr`: the input array.
  - `index`: the current index at which we are calculating the AP.
  - `diff`: the common difference between consecutive elements in the AP.
  - `dp`: a memoization array (unordered map) to store the results for subproblems.

#### **3. Base Case**:
```cpp
        if(index < 0) return 0;
```
- If the `index` is less than `0`, it means we have gone out of bounds, and no valid AP can exist beyond the array. Thus, we return `0`.

#### **4. Memoization Check**:
```cpp
        if(dp[index].count(diff)) return dp[index][diff];
```
- This line checks if the result for the given `index` and `diff` has already been calculated and stored in the `dp` array. If it exists, we return the cached result to avoid redundant calculations.

#### **5. Initialize `ans`**:
```cpp
        int ans = 0;
```
- We initialize a variable `ans` to keep track of the length of the longest AP that ends at the current `index` with the given `diff`.

#### **6. Iterate Backward**:
```cpp
        for(int j = index - 1; j >= 0; j--) {
```
- We start iterating from the previous index (`index - 1`) to check all previous elements to see if they can extend the AP. If `arr[index]` and `arr[j]` can form an AP with the given `diff`, we recursively compute the length of the AP.

#### **7. Check for Valid AP**:
```cpp
            if(arr[index] - arr[j] == diff) {
```
- This checks if the difference between `arr[index]` and `arr[j]` matches the expected common difference `diff`. If it matches, then we know that `arr[j]` can extend the AP ending at `arr[index]`.

#### **8. Recursive Call to Find LAP Length**:
```cpp
                ans = max(ans, 1 + solve(arr, j, diff, dp));
```
- If `arr[j]` forms a valid AP with `arr[index]`, we recursively find the length of the AP that ends at `arr[j]` and has the same common difference `diff`. We add `1` because we are including `arr[index]` in the AP.
- We update `ans` with the maximum AP length found.

#### **9. Store the Result and Return**:
```cpp
        return dp[index][diff] = ans;
```
- After calculating the maximum AP length for the given `index` and `diff`, we store the result in the `dp` array and return it.

#### **10. `lengthOfLongestAP` Function**:
```cpp
    int lengthOfLongestAP(vector<int>& arr) {
        int n = arr.size();
```
- This function is the main driver that will compute the longest arithmetic progression in the array.
- We first get the size of the array `arr`.

#### **11. Handle Small Arrays**:
```cpp
        if(n <= 2) return n;
```
- If the array has 2 or fewer elements, it is trivially an AP (since any two elements form an AP), so we return `n` (the length of the array).

#### **12. Initialize `dp`**:
```cpp
        unordered_map<int, int> dp[n + 1];
```
- We initialize the `dp` array, where each element is an unordered map. This map will store the results of the recursive calls for each `(index, diff)` pair.

#### **13. Iterate Through All Pairs**:
```cpp
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
```
- We iterate through all pairs of elements `(arr[i], arr[j])`, where `i < j`. For each pair, we compute the common difference `diff = arr[j] - arr[i]`.

#### **14. Call `solve` for Each Pair**:
```cpp
                ans = max(ans, 2 + solve(arr, i, arr[j] - arr[i], dp));
```
- For each pair, we call the `solve` function to find the length of the AP ending at `arr[i]` with the common difference `arr[j] - arr[i]`.
- We add `2` to account for the pair `(arr[i], arr[j])` itself, and update `ans` with the maximum length found.

#### **15. Return the Final Answer**:
```cpp
        return ans;
    }
};
```
- After iterating through all pairs, we return the final answer, which is the length of the longest arithmetic progression found.



### **Example Walkthrough**

#### **Input Array**: `[1, 7, 10, 13, 14, 19]`

- **Pair 1**: `(1, 7)`, `diff = 6`
  - Starting from `1`, we look for the longest AP with difference `6`. The AP is `[1, 7]`.
  - The recursive call checks further but finds no longer APs, returning `2`.

- **Pair 2**: `(7, 10)`, `diff = 3`
  - The AP is `[7, 10]`. Further calls recursively find no longer APs, returning `2`.

- **Continue with other pairs** until we find the longest AP `[7, 10, 13, 19]`, which has length `4`.

Thus, the function returns `4`.



### **Time and Space Complexity**

#### **Time Complexity**:
- The function iterates over all pairs `(i, j)` in the array, which takes (O(n^2)), where (n) is the length of the array.
- For each pair, the recursive `solve` function checks all previous elements, but the results are memoized, so each subproblem is computed at most once.
- Thus, the overall **time complexity** is (O(n^2)).

#### **Space Complexity**:
- The `dp` array stores memoized results for each `index` and `diff`. The space complexity of `dp` is proportional to the number of elements and the number of distinct differences, which is (O(n^2)) in the worst case.
- Additionally, the recursion stack depth can go up to (O(n)).
- Thus, the **space complexity** is (O(n^2)).

---

## Bottom-Up Approach (DP)
In a **bottom-up approach**, we iteratively build up the solution starting from the smallest subproblems. For this problem, the subproblems are the pairs of elements with a common difference that can potentially form an arithmetic progression (AP). The goal is to find the longest AP by processing the array from the beginning and storing intermediate results in a dynamic programming (DP) table.

### **Steps in Bottom-Up Approach**

1. **Initialize Variables:**
   - We start by defining the `dp` array, where each entry is a map. The map tracks the common differences for the subsequences that end at each index. Each key in the map represents the difference, and the value represents the length of the AP with that difference.

2. **Iterate Over Each Element:**
   - The outer loop iterates over each element `arr[i]` in the array, starting from the second element (index `1`).

3. **Check Previous Elements:**
   - For each `arr[i]`, the inner loop iterates over all previous elements `arr[j]` where `j < i`. This helps in calculating the common difference `arr[i] - arr[j]` and forming possible APs.

4. **Update DP Table:**
   - For each pair `(arr[i], arr[j])`, we calculate the difference `diff`. If there is already an AP ending at `arr[j]` with the same `diff`, then we extend that AP by including `arr[i]`.
   - The length of the AP is updated to be the length of the AP ending at `arr[j]` plus 1 (the current pair).

5. **Store Maximum Length:**
   - We update the maximum length of AP found so far.

6. **Return the Result:**
   - Finally, the longest AP length is returned.

### Source Code
```cpp
class Solution {
  public:
    // Function to find the length of the longest arithmetic progression (AP) in the array
    int lengthOfLongestAP(vector<int>& arr) {
        int n = arr.size();
        
        // If the array has 2 or fewer elements, the entire array is an AP
        if(n <= 2) return n;
        
        int ans = 0; // Variable to store the maximum length of AP found
        
        // `dp[i]` is an unordered map where the key is the difference `diff`
        // and the value is the length of the longest AP ending at index `i` with that difference
        unordered_map<int, int> dp[n + 1];
        
        // Iterate through all pairs of elements to build the `dp` table
        for(int i = 1; i < n; i++) { // Start from the second element
            for(int j = 0; j < i; j++) { // Compare with all previous elements
                // Calculate the common difference between arr[i] and arr[j]
                int diff = arr[i] - arr[j];
                int count = 1; // Minimum length of AP (current pair)
                
                // If there exists an AP ending at `j` with the same `diff`, retrieve its length
                if(dp[j].count(diff)) count = dp[j][diff];
                
                // Extend the AP by including the current element at `i`
                dp[i][diff] = 1 + count;

                // Update the maximum length of AP found so far
                ans = max(ans, dp[i][diff]);
            }
        }
        
        // Return the maximum length of AP
        return ans;
    }
};
```

### Source Code Explanation

```cpp
int lengthOfLongestAP(vector<int>& arr) {
    int n = arr.size();
    
    // If the array has 2 or fewer elements, the entire array is an AP
    if (n <= 2) return n;
```
- We start by checking if the array has fewer than or equal to 2 elements. If so, the entire array is an arithmetic progression by definition (any two numbers form an AP). We return `n` (the length of the array) in such cases.

```cpp
    int ans = 0; // Variable to store the maximum length of AP found
```
- `ans` will store the maximum length of the AP found during the iterations.

```cpp
    // `dp[i]` is an unordered map where the key is the difference `diff`
    // and the value is the length of the longest AP ending at index `i` with that difference
    unordered_map<int, int> dp[n + 1];
```
- We declare an array of unordered maps `dp`, where `dp[i]` keeps track of the APs that end at index `i`. The map stores the common difference `diff` as the key and the length of the AP as the value.

```cpp
    // Iterate through all pairs of elements to build the `dp` table
    for (int i = 1; i < n; i++) { // Start from the second element
        for (int j = 0; j < i; j++) { // Compare with all previous elements
```
- The outer loop starts from `i = 1` (the second element) and iterates through the array. The inner loop compares each element `arr[i]` with all previous elements `arr[j]` (where `j < i`).

```cpp
            // Calculate the common difference between arr[i] and arr[j]
            int diff = arr[i] - arr[j];
            int count = 1; // Minimum length of AP (current pair)
```
- We calculate the common difference `diff` between the current element `arr[i]` and the previous element `arr[j]`. Initially, the length of the AP is at least 2, since we are considering the pair `(arr[i], arr[j])`.

```cpp
            // If there exists an AP ending at `j` with the same `diff`, retrieve its length
            if (dp[j].count(diff)) count = dp[j][diff];
```
- If there is already an arithmetic progression ending at index `j` with the same difference `diff`, we extend that AP by adding `arr[i]` to it. The length of the AP becomes the length of the AP at `j` plus 1.

```cpp
            // Extend the AP by including the current element at `i`
            dp[i][diff] = 1 + count;
```
- We store the length of the AP ending at index `i` with the difference `diff` in the `dp` map for `dp[i]`. The length is `1 + count`, where `count` is the length of the AP ending at `j`.

```cpp
            // Update the maximum length of AP found so far
            ans = max(ans, dp[i][diff]);
```
- We update `ans` with the maximum length of the AP found so far.

```cpp
        }
    }
    
    // Return the maximum length of AP
    return ans;
}
```
- Finally, we return the value of `ans`, which is the length of the longest arithmetic progression in the array.

### **Example Walkthrough**

Let's walk through an example with the array `arr = [3, 6, 9, 12]`.

1. **Initial Setup:**
   - `n = 4` (length of array)
   - `dp = [ {}, {}, {}, {} ]` (for each element, we initialize an empty map for differences)

2. **Iteration 1 (i = 1, arr[i] = 6):**
   - Compare with `arr[j] = 3`:
     - Difference `diff = 6 - 3 = 3`.
     - The length of the AP with difference 3 is 2 (`[3, 6]`).
     - Update `dp[1][3] = 2`.

3. **Iteration 2 (i = 2, arr[i] = 9):**
   - Compare with `arr[j] = 3`:
     - Difference `diff = 9 - 3 = 6`.
     - Length of the AP with difference 6 is 2 (`[3, 9]`).
     - Update `dp[2][6] = 2`.
   - Compare with `arr[j] = 6`:
     - Difference `diff = 9 - 6 = 3`.
     - Length of the AP with difference 3 is 3 (`[3, 6, 9]`).
     - Update `dp[2][3] = 3`.

4. **Iteration 3 (i = 3, arr[i] = 12):**
   - Compare with `arr[j] = 3`:
     - Difference `diff = 12 - 3 = 9`.
     - Length of the AP with difference 9 is 2 (`[3, 12]`).
     - Update `dp[3][9] = 2`.
   - Compare with `arr[j] = 6`:
     - Difference `diff = 12 - 6 = 6`.
     - Length of the AP with difference 6 is 3 (`[3, 6, 12]`).
     - Update `dp[3][6] = 3`.
   - Compare with `arr[j] = 9`:
     - Difference `diff = 12 - 9 = 3`.
     - Length of the AP with difference 3 is 4 (`[3, 6, 9, 12]`).
     - Update `dp[3][3] = 4`.

5. **Final Result:**
   - The longest AP length found is `4`, which corresponds to the sequence `[3, 6, 9, 12]`.

### **Time and Space Complexity Analysis**

**Time Complexity:**
- The outer loop runs `n` times.
- The inner loop runs `i` times for each `i`, resulting in a total of `O(n^2)` iterations.
- Inside the inner loop, we perform constant-time operations for each pair.
- Therefore, the overall time complexity is **O(n^2)**.

**Space Complexity:**
- The `dp` array has `n` elements, and each element is an unordered map that, in the worst case, could store `n` keys (each difference for a pair of elements).
- Therefore, the space complexity is **O(n^2)** for storing the maps in `dp`.

Thus, the time complexity is **O(n^2)**, and the space complexity is **O(n^2)**.

---

## Space Optimization Approach (DP)
In this approach, we aim to optimize the space complexity by reducing the usage of the 2D `unordered_map` in the original approach, which tracks the length of the longest arithmetic progression (AP) for each pair of indices and common differences. Instead of storing the results for every pair `(i, j)` in a 2D map, we can reduce the space complexity by using a single `unordered_map` for each element that tracks the common differences and their corresponding lengths.

### **Steps for Space Optimization Approach**

1. **Initialize Variables:**
   - We start by defining the `dp` map, where each key is the difference `diff`, and the value is the length of the longest AP that ends at the current element with that common difference.

2. **Iterate Over Each Element:**
   - The outer loop iterates through each element `arr[i]`, starting from the second element (`i = 1`).

3. **Check Previous Elements:**
   - The inner loop compares `arr[i]` with all previous elements `arr[j]` (where `j < i`). For each pair, the common difference `diff` is computed.

4. **Update DP Map:**
   - For each pair `(arr[i], arr[j])`, the `dp` map at index `i` is updated. The key is the difference `diff`, and the value is the length of the longest AP ending at `i` with that difference. If an AP with the same difference already exists, its length is extended by including `arr[i]`.

5. **Track Maximum Length:**
   - After updating the DP map for each element, we check if the current AP length is the longest found so far and update the result accordingly.

6. **Return the Result:**
   - Finally, after processing all elements, we return the maximum length of the AP found.
  
### Source Code
```cpp
class Solution {
  public:
    // Function to find the length of the longest arithmetic progression (AP) in the array
    int lengthOfLongestAP(vector<int>& arr) {
        int n = arr.size();

        // If the array has 2 or fewer elements, the entire array is an AP
        if(n <= 2) return n;

        int ans = 2; // Minimum length of an AP is 2

        // `dp` is a 2D map where:
        // - The first key represents the index `i` of the array
        // - The second key represents the difference `diff`
        // - The value is the length of the longest AP ending at `i` with common difference `diff`
        unordered_map<int, unordered_map<int, int>> dp;

        // Iterate through all pairs of elements to fill the `dp` map
        for(int i = 1; i < n; i++) { // Start from the second element
            for(int j = 0; j < i; j++) { // Compare with all previous elements
                // Calculate the common difference between `arr[i]` and `arr[j]`
                int diff = arr[i] - arr[j];

                // Retrieve the length of the AP ending at `j` with the same `diff`
                // If no such AP exists, initialize it with length 1 (current pair)
                int count = dp[j][diff] ? dp[j][diff] : 1;

                // Update the length of the AP ending at `i` with the same `diff`
                dp[i][diff] = count + 1;

                // Update the maximum length of AP found so far
                ans = max(ans, dp[i][diff]);
            }
        }

        // Return the maximum length of AP found
        return ans;
    }
};
```

### Source Code Explanation

```cpp
int lengthOfLongestAP(vector<int>& arr) {
    int n = arr.size();

    // If the array has 2 or fewer elements, the entire array is an AP
    if(n <= 2) return n;
```
- We start by checking if the array has fewer than or equal to 2 elements. If so, the entire array is an arithmetic progression by definition, so we return `n` (the length of the array).

```cpp
    int ans = 2; // Minimum length of an AP is 2
```
- We initialize `ans` to 2 because the smallest possible arithmetic progression consists of two elements, and we need to ensure that we start with a valid AP length.

```cpp
    // `dp` is a map where the key represents the difference `diff`
    // and the value is the length of the longest AP ending at `i` with common difference `diff`
    unordered_map<int, int> dp;
```
- We declare a single `unordered_map` `dp` for each element in the array. The key represents the difference `diff`, and the value is the length of the longest AP that ends at the current element `i` with that difference.

```cpp
    // Iterate through all pairs of elements to fill the `dp` map
    for(int i = 1; i < n; i++) { // Start from the second element
        for(int j = 0; j < i; j++) { // Compare with all previous elements
```
- The outer loop starts from `i = 1` (the second element) and iterates through the array. The inner loop compares each element `arr[i]` with all previous elements `arr[j]` (where `j < i`).

```cpp
            // Calculate the common difference between `arr[i]` and `arr[j]`
            int diff = arr[i] - arr[j];
```
- We calculate the common difference `diff` between the current element `arr[i]` and the previous element `arr[j]`.

```cpp
            // Retrieve the length of the AP ending at `j` with the same `diff`
            // If no such AP exists, initialize it with length 1 (current pair)
            int count = dp[diff] ? dp[diff] : 1;
```
- If there exists an AP ending at index `j` with the same `diff`, we retrieve its length from the `dp` map. Otherwise, we initialize `count` to 1, which represents the current pair `(arr[i], arr[j])`.

```cpp
            // Update the length of the AP ending at `i` with the same `diff`
            dp[diff] = count + 1;
```
- We update the `dp` map at `i` with the new length of the AP ending at index `i` with the common difference `diff`. The new length is `count + 1`, where `count` is the length of the AP ending at `j`.

```cpp
            // Update the maximum length of AP found so far
            ans = max(ans, dp[diff]);
```
- We update the value of `ans` with the maximum AP length found so far.

```cpp
        }
    }

    // Return the maximum length of AP found
    return ans;
}
```
- Finally, after processing all elements, we return `ans`, which holds the length of the longest AP found.

### **Example Walkthrough**

Let's walk through an example with the array `arr = [3, 6, 9, 12]`.

1. **Initial Setup:**
   - `n = 4` (length of the array)
   - `dp = {}` (empty map for each element)

2. **Iteration 1 (i = 1, arr[i] = 6):**
   - Compare with `arr[j] = 3`:
     - Difference `diff = 6 - 3 = 3`.
     - No AP exists for this difference, so we initialize `count = 1`.
     - Update `dp[3] = 2` (length of the AP `[3, 6]`).
   - Update `ans = max(ans, dp[3]) = 2`.

3. **Iteration 2 (i = 2, arr[i] = 9):**
   - Compare with `arr[j] = 3`:
     - Difference `diff = 9 - 3 = 6`.
     - No AP exists for this difference, so we initialize `count = 1`.
     - Update `dp[6] = 2` (length of the AP `[3, 9]`).
   - Compare with `arr[j] = 6`:
     - Difference `diff = 9 - 6 = 3`.
     - Length of AP at `j` with difference 3 is 2 (`[3, 6]`), so `count = 2`.
     - Update `dp[3] = 3` (length of the AP `[3, 6, 9]`).
   - Update `ans = max(ans, dp[3]) = 3`.

4. **Iteration 3 (i = 3, arr[i] = 12):**
   - Compare with `arr[j] = 3`:
     - Difference `diff = 12 - 3 = 9`.
     - No AP exists for this difference, so we initialize `count = 1`.
     - Update `dp[9] = 2` (length of the AP `[3, 12]`).
   - Compare with `arr[j] = 6`:
     - Difference `diff = 12 - 6 = 6`.
     - Length of AP at `j` with difference 6 is 2 (`[3, 9]`), so `count = 2`.
     - Update `dp[6] = 3` (length of the AP `[3, 6, 12]`).
   - Compare with `arr[j] = 9`:
     - Difference `diff = 12 - 9 = 3`.
     - Length of AP at `j` with difference 3 is 3 (`[3, 6, 9]`), so `count = 3`.
     - Update `dp[3] = 4` (length of the AP `[3, 6, 9, 12]`).
   - Update `ans = max(ans, dp[3]) = 4`.

5. **Final Result:**
   - The longest AP length found is `4`, which corresponds to the sequence `[3, 6, 9, 12]`.

### **Time and Space Complexity Analysis**

**Time Complexity:**
- The outer loop runs `n` times.
- The inner loop runs `i` times for each `i`, resulting in a total of `O(n^2)` iterations.
- Inside the inner loop, we perform constant-time operations for each pair.
- Therefore, the overall time complexity is **O(n^2)**.

**Space Complexity:**
- The `dp` map stores differences and their corresponding lengths for each element. In the worst case, we need to store `n` different differences for each element.
- Thus, the space complexity is **O(n^2)** in the worst case, but it is more optimized compared to the original 2D map approach.

Thus, the time complexity is **O(n^2)**, and the space complexity is **O(n^2)**, but the space is optimized by reducing the 2D map to a 1D map at each element.
