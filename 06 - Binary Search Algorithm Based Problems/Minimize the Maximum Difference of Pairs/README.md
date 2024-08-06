# Minimize the Maximum Difference of Pairs

The problem is to minimize the maximum difference between pairs formed from an array of integers. Given an array `nums` and a number `p`, you need to form exactly `p` pairs of integers from `nums` such that the maximum difference between the integers in these pairs is minimized.

### Solution Explanation

The provided solution uses a binary search approach to find the minimum of the maximum differences. Here's a step-by-step explanation:

### Class `Solution`

1.  **Helper Function: `canFormPairs`**
    
    
    ```
    bool canFormPairs(vector<int>& nums, int p, int max_diff){
        int count = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] - nums[i-1] <= max_diff){
                ++count;
                ++i;  // Skip the next element since it's paired with the current one
            }
        }
        return count >= p;
    }
	   ``` 
    
    -   **Objective**: Check if it is possible to form at least `p` pairs such that the maximum difference between the pairs does not exceed `max_diff`.
    -   **Parameters**:
        -   `nums`: The sorted array of integers.
        -   `p`: Number of pairs to form.
        -   `max_diff`: Maximum allowed difference between paired integers.
    -   **Logic**:
        -   Traverse the sorted `nums` array and try to form pairs.
        -   If the difference between two adjacent integers is less than or equal to `max_diff`, count this pair.
        -   Skip the next element because it's paired with the current one.
        -   If the count of formed pairs is greater than or equal to `p`, return `true`; otherwise, return `false`.
2.  **Main Function: `minimizeMax`**

    
    ```
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
    
        int left = 0;
        int right = nums.back() - nums.front();
        int result = right;
    
        while(left <= right){
            int mid = left + (right - left) / 2;
    
            if(canFormPairs(nums, p, mid)){
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
    ``` 
    
    -   **Objective**: Find the minimum possible value of the maximum difference between paired integers.
    -   **Parameters**:
        -   `nums`: The array of integers.
        -   `p`: Number of pairs to form.
    -   **Logic**:
        1.  **Sort the Array**: Sorting `nums` helps to pair adjacent elements to minimize differences.
            -   Example: For `nums = {10, 1, 2, 7, 1, 3}`, sorting gives `nums = {1, 1, 2, 3, 7, 10}`.
        2.  **Initialize Binary Search**:
            -   `left` is initialized to `0` (smallest possible difference).
            -   `right` is initialized to `nums.back() - nums.front()` (largest possible difference).
            -   `result` is initialized to `right`, which represents the maximum difference found.
        3.  **Binary Search Loop**:
            -   **Calculate `mid`**: `mid` represents the current maximum difference being tested.
            -   **Check Feasibility**: Use `canFormPairs` to check if it is possible to form at least `p` pairs with the difference not exceeding `mid`.
            -   **Adjust Search Range**:
                -   If it is possible to form the pairs with the current `mid`, update `result` to `mid` and search for a potentially smaller maximum difference by setting `right` to `mid - 1`.
                -   If it is not possible to form the pairs, search for a larger maximum difference by setting `left` to `mid + 1`.
        4.  **Return Result**: After exiting the loop, `result` contains the minimum possible value of the maximum difference for the pairs.

### Example Walkthrough

Consider the array `nums = {10, 1, 2, 7, 1, 3}` and `p = 2`.

1.  **Sorting**: After sorting, `nums` becomes `{1, 1, 2, 3, 7, 10}`.
2.  **Binary Search**:
    -   **Initial Values**:
        -   `left = 0`
        -   `right = 10 - 1 = 9`
    -   **First Iteration**:
        -   `mid = (0 + 9) / 2 = 4`
        -   Check if you can form 2 pairs with a maximum difference of 4.
        -   The pairs `{1, 2}`, `{1, 3}`, and `{2, 7}` are valid.
        -   `canFormPairs` returns `true`.
        -   Update `result` to 4 and set `right = 3`.
    -   **Second Iteration**:
        -   `mid = (0 + 3) / 2 = 1`
        -   Check if you can form 2 pairs with a maximum difference of 1.
        -   The pairs `{1, 2}` and `{1, 3}` are valid.
        -   `canFormPairs` returns `true`.
        -   Update `result` to 1 and set `right = 0`.
    -   **Third Iteration**:
        -   `mid = (0 + 0) / 2 = 0`
        -   Check if you can form 2 pairs with a maximum difference of 0.
        -   Only the pair `{1, 1}` is valid, but you need more pairs.
        -   `canFormPairs` returns `false`.
        -   Set `left = 1`.

After binary search completes, `result` will be 1, which is the minimized maximum difference for the pairs.
