# Minimum Cost to Make Array Equal

You have an array `nums` where each element `nums[i]` represents the value of the `i-th` element, and another array `cost` where `cost[i]` represents the cost to change `nums[i]` to any other integer value. Your goal is to find the minimum cost to make all elements of `nums` equal.

## Approach to Solve the Problem

To solve this problem effectively, we need to consider each potential target value (let's call it `mid`) that could potentially represent the value all elements of `nums` could be changed to. We use binary search on the possible values of `mid` because the cost function (to make all elements equal to `mid`) is likely to be unimodal — it decreases first and then increases.

Here's the step-by-step approach:

1.  **Binary Search Setup:** Initialize `start` as the minimum value in `nums` and `end` as the maximum value in `nums`.
    
2.  **Binary Search Execution:** While `start` is less than or equal to `end`, compute `mid` as `(start + end) / 2`.
    
3.  **Cost Calculation:** Use the `findCost` function to calculate:
    
    -   `cost1`: The total cost to make all elements equal to `mid`.
    -   `cost2`: The total cost to make all elements equal to `mid + 1`.
    
    Compare `cost1` and `cost2` to decide whether to move the search range (`start` to `mid-1` or `mid+1` to `end`).
    
4.  **Update Minimum Cost:** Keep track of the minimum cost encountered during the binary search.
    
5.  **Result:** After exiting the binary search loop, return the minimum cost found. If no valid cost is found (`answer` remains `LLONG_MAX`), return `0`.

## Explanation of the Solution

### `findCost` Function

1.  **Function Definition:**
    
    
    ```
    long long findCost(vector<int>& nums, int mid, vector<int>& cost)
    ``` 
    
    -   Defines a function `findCost` that calculates the total cost to change all elements of `nums` to the value `mid`.
2.  **Variable Declarations:**

    
    ```
    int m = nums.size();
    int n = cost.size();
    ``` 
    
    -   Initializes `m` and `n` to the sizes of `nums` and `cost`, respectively.
3.  **Total Cost Initialization:**
    

    
    ```
    long long total_cost = 0;
    ``` 
    
    -   Initializes `total_cost` to 0, which will accumulate the total cost.
4.  **Loop Through Elements:**
    

    
    ```
    for(int i = 0; i < m; i++) {
        total_cost += (long long)abs(nums[i] - mid) * cost[i];
    }
    ``` 
    
    -   Iterates through each element in `nums`, calculates the cost to change `nums[i]` to `mid`, and accumulates this cost.
5.  **Return Total Cost:**
    

    
    ```
    return total_cost;
    ``` 
    
    -   Returns the total accumulated cost.

### `minCost` Function

1.  **Function Definition:**
    
   
    
    ```
    long long minCost(vector<int>& nums, vector<int>& cost)
    ``` 
    
    -   Defines the main function `minCost` that finds the minimum cost to make all elements of `nums` equal.
2.  **Answer Initialization:**
    

    
    ```
    long long answer = LLONG_MAX;`
    ``` 
    
    -   Initializes `answer` to the maximum possible value of `long long` to keep track of the minimum cost encountered.
3.  **Find Start and End:**
    

    
    ```
    int start = *min_element(nums.begin(), nums.end());
    int end = *max_element(nums.begin(), nums.end());
    ``` 
    
    -   Initializes `start` and `end` to the minimum and maximum values of `nums`, respectively.
4.  **Binary Search Loop:**

    
    ```
    while(start <= end) {
        int mid = start + (end - start) / 2;
       ``` 
    
    -   Executes a binary search loop while `start` is less than or equal to `end`.
    -   Computes `mid` as the midpoint between `start` and `end`.
5.  **Calculate Costs:**
    

    
    ```
    long long cost1 = findCost(nums, mid, cost);
    long long cost2 = findCost(nums, mid + 1, cost);
    ``` 
    
    -   Calculates the cost to make all elements equal to `mid` (`cost1`) and `mid + 1` (`cost2`) using the `findCost` function.
6.  **Update Answer:**
    

    
    ```
    answer = min(cost1, cost2);
    ``` 
    
    -   Updates `answer` with the minimum of `cost1` and `cost2`.
7.  **Adjust Search Range:**

    
    ```
    if(cost2 > cost1) {
        end = mid - 1;
    } else {
        start = mid + 1;
    }
    ``` 
    
    -   Adjusts `start` and `end` based on which cost is smaller, narrowing the search range to the region with the lower cost.
8.  **Return Answer:**
    

    
    ```
    return answer == LLONG_MAX ? 0 : answer;
    ``` 
    
    -   Returns `answer`, which holds the minimum cost found during the binary search. If `answer` remains `LLONG_MAX`, it returns `0` indicating no valid cost was found.

### Main Function

1.  **Main Function Definition:**
    

    
    `int main() {` 
    
    -   Defines the main function.
2.  **Initialize Inputs:**
    

    
    ```
    vector<int> nums = {1, 3, 5, 2};
    vector<int> cost = {2, 3, 1, 14};
    ``` 
    
    -   Initializes the `nums` and `cost` vectors with example values.
3.  **Call `minCost` Function:**
    

    
    ```
    long long answer = minCost(nums, cost);
    ``` 
    
    -   Calls the `minCost` function with `nums` and `cost` as arguments, and stores the result in `answer`.
4.  **Print Result:**
    

    
    ```
    cout << "Minimum Cost to Make Array Equal is: " << answer << endl;
    ``` 
    
    -   Prints the result.
5.  **Return Statement:**
    

    
    `return 0;` 
    
    -   Returns 0, indicating successful execution.

### Summary

-   The `findCost` function calculates the total cost to make all elements of `nums` equal to a given `mid`.
-   The `minCost` function uses binary search to find the minimum cost efficiently, by iterating over potential target values and calculating the corresponding costs.
-   The main function initializes the input arrays, calls the `minCost` function, and prints the result.
