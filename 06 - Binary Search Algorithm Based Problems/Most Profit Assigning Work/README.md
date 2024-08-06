# Most Profit Assigning Work 

You are given:

- `difficulty`: A vector of integers where `difficulty[i]` represents the difficulty of job `i`.
- `profit`: A vector of integers where `profit[i]` represents the profit of job `i`.
- `worker`: A vector of integers where `worker[i]` represents the ability level of worker `i`.

The goal is to assign jobs to workers such that each worker can only take jobs whose difficulty is less than or equal to their ability. Each worker can take at most one job. The objective is to maximize the total profit.

### Approach

**Step-by-Step Explanation:**

1. **Pair Jobs with Difficulty and Profit:**
   - Combine the `difficulty` and `profit` into pairs so that each pair represents a job with its difficulty and profit.
   - Sort these pairs based on the difficulty of the job.

2. **Optimize Profit for Jobs:**
   - Traverse the sorted job list and update each job’s profit to be the maximum profit achievable for jobs with the same or lower difficulty. This ensures that every job has the maximum profit available up to that difficulty level.

3. **Assign Jobs to Workers:**
   - For each worker, find the job that they can perform (i.e., where the job difficulty is less than or equal to the worker’s ability) and get the maximum profit for that job.


### Source Code Explanation

```cpp
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int m = difficulty.size(); // Number of jobs
        int n = worker.size();     // Number of workers

        vector<pair<int, int>> pairs; // Vector to hold pairs of difficulty and profit

        // Create pairs of difficulty and profit
        for (int i = 0; i < m; i++) {
            pairs.push_back({difficulty[i], profit[i]});
        }
```
- **`int m = difficulty.size();`**: Gets the number of jobs by determining the size of the `difficulty` vector.
- **`int n = worker.size();`**: Gets the number of workers by determining the size of the `worker` vector.
- **`vector<pair<int, int>> pairs;`**: Declares a vector of pairs to store job difficulties and corresponding profits.
- **`for (int i = 0; i < m; i++)`**: Iterates over each job.
- **`pairs.push_back({difficulty[i], profit[i]});`**: Adds a pair to the `pairs` vector where each pair consists of job difficulty and profit.

```cpp
        // Sort pairs by difficulty
        sort(pairs.begin(), pairs.end());
```
- **`sort(pairs.begin(), pairs.end());`**: Sorts the `pairs` vector by the first element of each pair (i.e., job difficulty) in ascending order.

```cpp
        // Update each job's profit to be the maximum profit for jobs with the same or lower difficulty
        for (int i = 1; i < pairs.size(); i++) {
            pairs[i].second = max(pairs[i].second, pairs[i-1].second);
        }
```
- **`for (int i = 1; i < pairs.size(); i++)`**: Iterates through the sorted list of jobs starting from the second job.
- **`pairs[i].second = max(pairs[i].second, pairs[i-1].second);`**: Updates the profit of the current job to be the maximum profit of all jobs with the same or lower difficulty. This ensures that for any difficulty level, you have the maximum profit available.

```cpp
        int totalProfit = 0; // Initialize total profit
```
- **`int totalProfit = 0;`**: Initializes a variable to keep track of the total profit accumulated from assigning jobs to workers.

```cpp
        // For each worker, determine the maximum profit they can achieve
        for (int i = 0; i < n; i++) {
            int maxProfit = 0; // Initialize maximum profit for the current worker
```
- **`for (int i = 0; i < n; i++)`**: Iterates over each worker.
- **`int maxProfit = 0;`**: Initializes a variable to keep track of the maximum profit that the current worker can achieve.

```cpp
            // Binary search to find the highest difficulty job the worker can handle
            int l = 0;
            int r = pairs.size() - 1;
```
- **`int l = 0;`**: Initializes the left pointer for binary search.
- **`int r = pairs.size() - 1;`**: Initializes the right pointer for binary search (last index in the `pairs` vector).

```cpp
            while (l <= r) {
                int mid = l + (r - l) / 2;
```
- **`while (l <= r)`**: Starts a binary search loop while the left pointer is less than or equal to the right pointer.
- **`int mid = l + (r - l) / 2;`**: Calculates the middle index to avoid overflow and to check the middle element.

```cpp
                if (pairs[mid].first <= worker[i]) {
                    maxProfit = max(maxProfit, pairs[mid].second);
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
```
- **`if (pairs[mid].first <= worker[i])`**: Checks if the job at the middle index can be handled by the current worker.
    - **`maxProfit = max(maxProfit, pairs[mid].second);`**: Updates the maximum profit that the worker can achieve based on the current job.
    - **`l = mid + 1;`**: Moves the left pointer to the right to check if there are any higher profits available that the worker can handle.
- **`else { r = mid - 1; }`**: Moves the right pointer to the left if the current job's difficulty is too high for the worker.

```cpp
            totalProfit += maxProfit; // Add the maximum profit for this worker to the total profit
        }
```
- **`totalProfit += maxProfit;`**: Adds the maximum profit that the current worker can achieve to the total profit.

```cpp
        return totalProfit; // Return the total profit
    }
};
```
- **`return totalProfit;`**: Returns the total profit accumulated from assigning jobs to workers.

### Summary

- **Create Pairs:** Combine job difficulties and profits into pairs.
- **Sort Pairs:** Sort jobs by difficulty to facilitate easier profit calculations.
- **Update Profits:** Ensure each job’s profit reflects the maximum profit available up to that difficulty level.
- **Binary Search:** For each worker, use binary search to find the highest difficulty job they can handle and determine the maximum profit.
- **Accumulate Profit:** Sum up the maximum profits for all workers.

### Time Complexity

1. **Pair Creation:** O(M)
2. **Sorting Pairs:** O(M log M)
3. **Updating Profits:** O(M)
4. **Binary Search for Each Worker:** O(N log M)

Combining these, the overall time complexity is **O(M log M + N log M)**.
