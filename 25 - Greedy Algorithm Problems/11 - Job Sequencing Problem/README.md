<h1 align="center">Job - Sequencing - Problem</h1>

## Problem Statement

**Problem URL :** [Job Sequencing Problem](https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1)

![image](https://github.com/user-attachments/assets/a0836399-100c-4af5-b3f7-23c682a557bb)

### Problem Explanation
The **Job Sequencing Problem** is a classic problem where you are given a list of jobs, and each job has:
- A deadline, indicating by which time the job should be completed.
- A profit that will be earned if the job is completed before or at its deadline.

The goal is to **schedule the jobs** in such a way that the total profit is maximized. Additionally, the jobs need to be scheduled in a way that **no two jobs overlap**. 

#### Problem Input:

- `id[]`: A list of unique job identifiers.
- `deadline[]`: A list of deadlines corresponding to the jobs.
- `profit[]`: A list of profits corresponding to the jobs.

#### Problem Output:

- The **maximum profit** that can be earned by scheduling jobs before or at their deadlines.
- The **number of jobs** scheduled.

#### Constraints:

- The job id is a unique number.
- A job should be completed before or at its given deadline.
- A job can only be scheduled if there is a free slot available before or at its deadline.

#### Example:

Consider the following job list:

| Job ID | Deadline | Profit |
|--------|----------|--------|
| 1      | 4        | 20     |
| 2      | 1        | 10     |
| 3      | 1        | 40     |
| 4      | 1        | 30     |

#### Step-by-Step Explanation:

##### Step 1: Sort jobs by profit in descending order
To maximize the profit, we start by sorting the jobs based on their profit in descending order. The reason for this is that we want to prioritize jobs with higher profit.

**Sorted jobs by profit:**

| Job ID | Deadline | Profit |
|--------|----------|--------|
| 3      | 1        | 40     |
| 1      | 4        | 20     |
| 4      | 1        | 30     |
| 2      | 1        | 10     |

##### Step 2: Find the maximum deadline
The maximum deadline is `4`, which means that we need to create an array of slots from `1` to `4`.

##### Step 3: Create an array to track scheduled jobs
We initialize an array `schedule[]` where the index represents time slots. Initially, the slots are empty (i.e., `-1`).

**schedule[] (initial):** `[-1, -1, -1, -1]`

##### Step 4: Iterate through sorted jobs
Now, we iterate through the sorted jobs and try to place each job in the last available slot before its deadline. If a slot is available, we schedule the job in that slot.

- **Job 3** (Profit 40, Deadline 1): We check slot `1`. Since it's empty, we place Job 3 in slot `1`. The profit is now `40`, and one job is scheduled.

  **schedule[]:** `[3, -1, -1, -1]`
  
- **Job 1** (Profit 20, Deadline 4): We check slot `4`. Since it's empty, we place Job 1 in slot `4`. The profit is now `60`, and two jobs are scheduled.

  **schedule[]:** `[3, -1, -1, 1]`

- **Job 4** (Profit 30, Deadline 1): We check slot `1`, but slot `1` is already occupied by Job 3. We then check slot `0`, but since this is out of bounds, Job 4 cannot be scheduled.

  **schedule[] remains:** `[3, -1, -1, 1]`
  
- **Job 2** (Profit 10, Deadline 1): We check slot `1`, but slot `1` is already occupied by Job 3. We check slot `0`, but it is out of bounds. Job 2 cannot be scheduled either.

  **schedule[] remains:** `[3, -1, -1, 1]`

##### Step 5: Return the result
- The total number of jobs scheduled is `2`.
- The total profit earned is `40 + 20 = 60`.

#### Final Output:

- **Number of jobs scheduled:** 2
- **Total profit:** 60

### Greedy Algorithm Approach

##### Step 1: Sort the jobs by profit
We first sort the jobs in descending order of profit. This ensures that we try to schedule the most profitable jobs first, which helps in maximizing the total profit.

##### Step 2: Find the maximum deadline
We need to determine the latest deadline because that defines the size of the array we use to track scheduled jobs. The size of the `schedule[]` array will be equal to the maximum deadline, and it helps us know how many available time slots we have.

##### Step 3: Schedule jobs in available slots
We then iterate over the sorted jobs:
- For each job, we try to find a time slot that is available before or at the job's deadline.
- If we find an available slot, we schedule the job there and update the `schedule[]` array to mark that slot as occupied.
- If no slot is available, we move on to the next job.

##### Step 4: Calculate the result
Once all jobs have been considered, we calculate:
- The total number of jobs that were scheduled (count of jobs in the `schedule[]` array).
- The total profit earned from these scheduled jobs.

##### Step 5: Return the result
Finally, we return the total number of jobs scheduled and the total profit.

## Problem Solution
```cpp
class Solution {
  public:
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
        
        // Step 1: Create a vector of tuples to store job details (profit, job id, and deadline)
        vector<tuple<int, int, int>> v;
        
        // Loop through the job arrays and create tuples of (profit, job id, deadline)
        for(int i = 0; i < id.size(); i++){
            v.push_back(make_tuple(profit[i], id[i], deadline[i]));
        }
        
        // Step 2: Sort the jobs by profit in descending order
        // The job with higher profit is considered first
        sort(v.begin(), v.end(), [](tuple<int, int, int>& a, tuple<int, int, int>& b){
            return get<0>(a) > get<0>(b);  // Compare based on profit (first element of the tuple)
        });
        
        // Step 3: Find the maximum deadline to define the size of the schedule array
        int maxiDeadline = INT_MIN;
        for(int i = 0; i < deadline.size(); i++){
            maxiDeadline = max(maxiDeadline, deadline[i]);
        }
        
        // Step 4: Initialize the schedule array with -1 to represent unoccupied time slots
        // The array has size `maxiDeadline + 1` because deadlines are 1-based.
        vector<int> schedule(maxiDeadline+1, -1);
        
        // Step 5: Initialize variables to track the number of jobs selected and total profit
        int count = 0;
        int maxProfit = 0;
        
        // Step 6: Try to schedule jobs in decreasing order of their profit
        for(int i = 0; i < v.size(); i++){
            int currProfit = get<0>(v[i]);   // Profit of the current job
            int currJobId = get<1>(v[i]);    // Job id of the current job
            int currDeadline = get<2>(v[i]); // Deadline of the current job
            
            // Step 7: Try to find the latest available time slot before the job's deadline
            for(int k = currDeadline; k > 0; k--){
                // If the time slot is free (schedule[k] == -1), schedule the job there
                if(schedule[k] == -1){
                    schedule[k] = currJobId; // Assign the job id to the available slot
                    maxProfit += currProfit; // Add the profit of the job to the total profit
                    count++;                // Increment the count of scheduled jobs
                    break;                  // Break out of the loop after scheduling the job
                }
            }    
        }
        
        // Step 8: Return the count of jobs scheduled and the total profit
        return {count, maxProfit};
    }
};

```

## Problem Solution Explanation
#### 1. **Function Declaration:**

```cpp
vector<int> JobSequencing(vector<int> &id, vector<int> &deadline, vector<int> &profit) {
```

- This function is part of a class `Solution` and takes three parameters:
  - `id[]`: A vector containing job identifiers (ID of each job).
  - `deadline[]`: A vector containing the deadlines for each job.
  - `profit[]`: A vector containing the profit associated with each job.
  
  It returns a vector of two integers: the count of jobs scheduled and the maximum profit earned.


#### 2. **Creating the Vector of Tuples:**

```cpp
vector<tuple<int, int, int>> v;
```

- Here, a `vector` named `v` of tuples is created. Each tuple will store three values:
  - **Profit** (integer)
  - **Job ID** (integer)
  - **Deadline** (integer)


#### 3. **Populating the Tuple Vector:**

```cpp
for(int i = 0; i < id.size(); i++){
    v.push_back(make_tuple(profit[i], id[i], deadline[i]));
}
```

- A loop iterates over the input arrays (`id[]`, `profit[]`, `deadline[]`).
- In each iteration, a tuple of `(profit, job id, deadline)` is created using `make_tuple` and added to the vector `v`.
  
**Example:**
For input:
- `id[] = {1, 2, 3}`
- `deadline[] = {2, 1, 3}`
- `profit[] = {20, 10, 40}`

The vector `v` will contain the following tuples:
- `(20, 1, 2)`
- `(10, 2, 1)`
- `(40, 3, 3)`


#### 4. **Sorting the Jobs by Profit in Descending Order:**

```cpp
sort(v.begin(), v.end(), [](tuple<int, int, int>& a, tuple<int, int, int>& b){
    return get<0>(a) > get<0>(b);
});
```

- The jobs are sorted by profit in descending order using a custom comparison function.
- `get<0>(a)` retrieves the profit of the job in tuple `a` (since it's the first element of the tuple).
- Jobs with higher profits will come before jobs with lower profits.
  
**After Sorting (descending by profit):**
- `(40, 3, 3)`  → Job 3 with Profit 40
- `(20, 1, 2)`  → Job 1 with Profit 20
- `(10, 2, 1)`  → Job 2 with Profit 10


#### 5. **Finding the Maximum Deadline:**

```cpp
int maxiDeadline = INT_MIN;
for(int i = 0; i < deadline.size(); i++){
    maxiDeadline = max(maxiDeadline, deadline[i]);
}
```

- A variable `maxiDeadline` is initialized to the smallest possible integer (`INT_MIN`).
- A loop goes through all the deadlines and updates `maxiDeadline` to the largest value found in the `deadline[]` array.
  
**Example:**
For input `deadline[] = {2, 1, 3}`, `maxiDeadline` will become `3` after the loop.


#### 6. **Initializing the Schedule Array:**

```cpp
vector<int> schedule(maxiDeadline + 1, -1);
```

- A `schedule[]` array is created to keep track of the time slots.
- The array size is `maxiDeadline + 1` to accommodate all time slots from `1` to `maxiDeadline`.
- The array is initialized with `-1`, indicating that all time slots are initially empty.

**Example:**
If `maxiDeadline = 3`, the `schedule[]` will look like this: `[-1, -1, -1, -1]`.


#### 7. **Initializing Variables for Count and Profit:**

```cpp
int count = 0;
int maxProfit = 0;
```

- `count` keeps track of the number of jobs successfully scheduled.
- `maxProfit` stores the total profit earned from the scheduled jobs.


#### 8. **Scheduling Jobs:**

```cpp
for(int i = 0; i < v.size(); i++){
    int currProfit = get<0>(v[i]);
    int currJobId = get<1>(v[i]);
    int currDeadline = get<2>(v[i]);

    for(int k = currDeadline; k > 0; k--){
        if(schedule[k] == -1){
            schedule[k] = currJobId;
            maxProfit += currProfit;
            count++;
            break;
        }
    }
}
```

- The algorithm then iterates through each job (from the sorted list of jobs):
  - Extract the job's **profit**, **job ID**, and **deadline**.
  - For each job, it tries to find the latest available time slot (starting from the job's deadline).
  - It checks if the time slot is free (i.e., `schedule[k] == -1`).
  - If an empty slot is found, it schedules the job, updates the `schedule[]` array with the job ID, increments the total profit (`maxProfit`), and increments the count of scheduled jobs (`count`).
  - The loop breaks after scheduling the job to move on to the next job.

**Example:**
For sorted jobs:
- **Job 3**: Deadline = 3, Profit = 40. It finds an empty slot at time 3 and schedules it.
- **Job 1**: Deadline = 2, Profit = 20. It finds an empty slot at time 2 and schedules it.
- **Job 2**: Deadline = 1, Profit = 10. But both slots before its deadline are occupied, so it can't be scheduled.

The `schedule[]` array will look like this: `[-1, -1, 1, 3]`.


#### 9. **Returning the Result:**

```cpp
return {count, maxProfit};
```

- The function returns a vector containing:
  - `count`: The number of jobs scheduled.
  - `maxProfit`: The total profit earned from the scheduled jobs.


### Example Walkthrough:

For the input:
- `id[] = {1, 2, 3}`
- `deadline[] = {2, 1, 3}`
- `profit[] = {20, 10, 40}`

1. **After Sorting Jobs by Profit:**
   - `[(40, 3, 3), (20, 1, 2), (10, 2, 1)]`

2. **Find Maximum Deadline:** `maxiDeadline = 3`

3. **Initialize Schedule:** `[-1, -1, -1, -1]`

4. **Schedule Jobs:**
   - Job 3: Slot 3 → Schedule: `[-1, -1, -1, 3]`
   - Job 1: Slot 2 → Schedule: `[-1, -1, 1, 3]`
   - Job 2: Cannot be scheduled.

5. **Result:**
   - Number of jobs scheduled: `2`
   - Total profit: `40 + 20 = 60`


### Time Complexity:

- Sorting the jobs by profit takes **O(n log n)**, where `n` is the number of jobs.
- For each job, we may need to iterate through time slots up to its deadline. In the worst case, for each job, this takes **O(n)**.
- Thus, the total time complexity is **O(n log n) + O(n^2)**, which simplifies to **O(n^2)**.

### Space Complexity:

- The `schedule[]` array takes **O(n)** space (to store time slots).
- The vector `v` contains tuples, which also take **O(n)** space.
- Thus, the overall space complexity is **O(n)**.
