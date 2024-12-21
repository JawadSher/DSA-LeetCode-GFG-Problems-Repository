<h1 align="center">Activity - Selection</h1>

## Problem Statement

**Problem URL :** [Activity Selection](https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1)

![image](https://github.com/user-attachments/assets/ea5ed61a-0317-4d41-abc5-7e62ed383bfb)

### Problem Explanation
The **Activity Selection Problem** is a classical problem in computer science, where you are given a set of activities with their start and end times. Your task is to select the maximum number of activities that do not overlap with each other. Each activity takes a specific time to start and end, and the activities are considered overlapping if one starts before the other ends.

#### Input:
- Two arrays of size `n`:
  - `start[]`: An array representing the start times of the activities.
  - `end[]`: An array representing the end times of the activities.

- You need to select the maximum number of activities such that no two activities overlap.

#### Output:
- The maximum number of activities that can be selected without any overlapping.

### Example:

#### Input:
- `start[] = {1, 3, 0, 5, 8, 5}`
- `end[] = {2, 4, 6, 7, 9, 9}`

#### Explanation:

1. **Step 1: Sort the Activities by their End Times**
   - First, we sort the activities based on their end times, as we want to select activities that finish the earliest, leaving more room for the next activities.
   
   Sorted activities based on end times:
   ```
   (1, 2), (3, 4), (5, 7), (0, 6), (8, 9), (5, 9)
   ```

2. **Step 2: Select the First Activity**
   - We always select the first activity (after sorting by end time), as it finishes first and doesn't overlap with any previous activity.
   - We select activity `(1, 2)`.

3. **Step 3: Select Subsequent Activities**
   - Now, we need to select the next activity that starts after the previous one ends.
   - The activity `(3, 4)` starts at `3`, which is after the end time of the previous activity (`2`), so we can select it.
   - Next, we need to select an activity that starts after `4`.

4. **Step 4: Continue the Selection Process**
   - The next possible activity is `(5, 7)`, which starts at `5` (after `4`), so we select it.
   - Now, we need to select an activity that starts after `7`.

5. **Step 5: Continue Until All Activities are Checked**
   - The next possible activity is `(8, 9)`, which starts at `8` (after `7`), so we select it.

6. **Step 6: Output the Maximum Number of Activities**
   - The activities selected are `(1, 2)`, `(3, 4)`, `(5, 7)`, and `(8, 9)`.
   - The total number of selected activities is `4`.

#### Output:
```
4
```

### Greedy Algorithm Approach

The **Greedy Approach** is optimal for solving the Activity Selection problem. The idea is to always pick the activity that finishes the earliest (i.e., select the activity with the minimum end time), so that we leave as much room as possible for other activities.

#### Greedy Strategy:
1. **Sort the Activities by their End Times:** We start by sorting the activities based on their end times. This allows us to pick the activity that finishes the earliest, which leaves more time for subsequent activities.
   
2. **Select the First Activity:** Always select the first activity after sorting because it finishes the earliest.

3. **Iterate Over the Remaining Activities:** Starting from the second activity, we check if the activity starts after the end time of the last selected activity. If it does, we select it and update the end time to the end time of the current activity.

4. **Repeat the Process:** Continue this process until all activities are checked.

5. **Return the Total Number of Selected Activities:** The result is the total number of non-overlapping activities that have been selected.

#### Example Walkthrough:

Let’s walk through the code with the example input `start[] = {1, 3, 0, 5, 8, 5}` and `end[] = {2, 4, 6, 7, 9, 9}`.

##### Step 1: Sorting the Activities by End Times

First, we create pairs of `(start, end)` and sort them by the end times:
```
(1, 2), (3, 4), (0, 6), (5, 7), (8, 9), (5, 9)
```
After sorting by end time:
```
(1, 2), (3, 4), (5, 7), (0, 6), (8, 9), (5, 9)
```

##### Step 2: Selecting the First Activity

We select the first activity `(1, 2)` because it ends the earliest, leaving the most room for other activities.

##### Step 3: Iterating Over the Remaining Activities

Now, we iterate through the remaining activities and check if they can be selected:
- Activity `(3, 4)` starts at `3`, which is after `2` (the end time of the previously selected activity). So, we select it.
- Activity `(5, 7)` starts at `5`, which is after `4`. We select it as well.
- Activity `(8, 9)` starts at `8`, which is after `7`. We select it.

At this point, no more activities can be selected because all remaining activities overlap with one of the already selected ones.

##### Step 4: Return the Total Number of Selected Activities

The selected activities are `(1, 2)`, `(3, 4)`, `(5, 7)`, and `(8, 9)`. Thus, the maximum number of non-overlapping activities that can be selected is `4`.

## Problem Solution
```cpp
class Solution {
  public:
    // Function to find the maximum number of activities that can be selected
    int activitySelection(vector<int> &start, vector<int> &end) {
        int n = start.size(); // Get the number of activities (size of the start array)
        
        // Step 1: Create a vector of pairs to store the start and end times of each activity
        vector<pair<int, int>> v;
        
        // Step 2: Fill the vector 'v' with pairs of (start time, end time)
        // This helps in storing both the start and end times together for sorting and comparison
        for(int i = 0; i < n; i++){
            v.push_back({start[i], end[i]});
        }
        
        // Step 3: Sort the activities based on their end times (ascending order)
        // Sorting by end times allows us to select the activities that finish the earliest,
        // leaving more room for subsequent activities.
        sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){
            return a.second < b.second;  // Compare by the second element of the pair (end time)
        });
        
        // Step 4: Initialize the activity count and the end time of the first activity
        int activityCount = 1; // We always select the first activity (after sorting)
        int endTime = v[0].second; // The end time of the first activity
        
        // Step 5: Iterate through the remaining activities and select the ones that do not overlap
        for(int i = 1; i < n; i++){
            // If the start time of the current activity is greater than the end time of the last selected activity
            if(v[i].first > endTime){
                activityCount++;  // Select the current activity
                endTime = v[i].second;  // Update the end time to the end time of the current activity
            }
        }
        
        // Step 6: Return the total number of activities that can be selected
        return activityCount;
    }
};
```

## Problem Solution Explanation

```cpp
class Solution {
  public:
    // Function to find the maximum number of activities that can be selected
    int activitySelection(vector<int> &start, vector<int> &end) {
        int n = start.size(); // Get the number of activities (size of the start array)
```
- **Line 1-3:** The `activitySelection` function is defined, which takes two input vectors: `start[]` and `end[]` representing the start and end times of the activities.
- `n = start.size()` computes the number of activities (assuming both arrays have the same size). This value is used to determine the number of iterations needed later in the code.

```cpp
        // Step 1: Create a vector of pairs to store the start and end times of each activity
        vector<pair<int, int>> v;
```
- **Line 4:** A vector of pairs `v` is created. Each pair contains two integers: the start time and the end time of an activity. This vector will store the combined data of each activity to facilitate sorting and selection.

```cpp
        // Step 2: Fill the vector 'v' with pairs of (start time, end time)
        // This helps in storing both the start and end times together for sorting and comparison
        for(int i = 0; i < n; i++){
            v.push_back({start[i], end[i]});
        }
```
- **Line 5-7:** A loop is used to populate the vector `v` with pairs of start and end times. For each activity `i`, the pair `{start[i], end[i]}` is added to `v`. This step groups each activity's start and end time together, making it easier to sort and manipulate them later.

Example:  
For `start[] = {1, 3, 0, 5, 8, 5}` and `end[] = {2, 4, 6, 7, 9, 9}`, the vector `v` will look like:
```
v = [(1, 2), (3, 4), (0, 6), (5, 7), (8, 9), (5, 9)]
```

```cpp
        // Step 3: Sort the activities based on their end times (ascending order)
        // Sorting by end times allows us to select the activities that finish the earliest,
        // leaving more room for subsequent activities.
        sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){
            return a.second < b.second;  // Compare by the second element of the pair (end time)
        });
```
- **Line 8-10:** The activities in `v` are sorted based on their end times. This is done using the `sort` function, where a custom lambda function is passed to compare the second element (the end time) of each pair.
- Sorting by the end time ensures that we always select the activity that finishes first, which maximizes the number of activities we can select afterward.

Example:  
For the above `v = [(1, 2), (3, 4), (0, 6), (5, 7), (8, 9), (5, 9)]`, after sorting by the second element (end time):
```
v = [(1, 2), (3, 4), (5, 7), (0, 6), (8, 9), (5, 9)]
```

```cpp
        // Step 4: Initialize the activity count and the end time of the first activity
        int activityCount = 1; // We always select the first activity (after sorting)
        int endTime = v[0].second; // The end time of the first activity
```
- **Line 11-13:** 
  - `activityCount = 1` initializes the activity count to 1, as we always select the first activity (after sorting).
  - `endTime = v[0].second` sets the `endTime` to the end time of the first activity, which is used to compare with the start times of subsequent activities.

```cpp
        // Step 5: Iterate through the remaining activities and select the ones that do not overlap
        for(int i = 1; i < n; i++){
            // If the start time of the current activity is greater than the end time of the last selected activity
            if(v[i].first > endTime){
                activityCount++;  // Select the current activity
                endTime = v[i].second;  // Update the end time to the end time of the current activity
            }
        }
```
- **Line 14-18:** 
  - We iterate over the activities starting from the second one (`i = 1`).
  - For each activity `i`, we check if its start time `v[i].first` is greater than the `endTime` of the previously selected activity.
  - If it is, that means the activity doesn't overlap with the previously selected one, and we can select it:
    - Increment `activityCount`.
    - Update `endTime` to the end time of the newly selected activity.
  
Example:
- After selecting the first activity `(1, 2)`, `endTime = 2`. Now we check the next activity `(3, 4)`. Since `3 > 2`, it can be selected, so `activityCount++` becomes `2` and `endTime = 4`.

```cpp
        // Step 6: Return the total number of activities that can be selected
        return activityCount;
    }
};
```
- **Line 19-21:** The function returns the total number of activities selected (`activityCount`), which is the maximum number of non-overlapping activities that can be selected.

### Example Walkthrough:

For the input:

- `start[] = {1, 3, 0, 5, 8, 5}`
- `end[] = {2, 4, 6, 7, 9, 9}`

1. **Step 1:** Create the vector `v`:
   ```
   v = [(1, 2), (3, 4), (0, 6), (5, 7), (8, 9), (5, 9)]
   ```
2. **Step 2:** Sort the vector by end times:
   ```
   v = [(1, 2), (3, 4), (5, 7), (0, 6), (8, 9), (5, 9)]
   ```
3. **Step 3:** Initialize `activityCount = 1` and `endTime = 2`.
4. **Step 4:** Iterate through the activities:
   - Activity `(3, 4)` is selected because `3 > 2`, so `activityCount = 2` and `endTime = 4`.
   - Activity `(5, 7)` is selected because `5 > 4`, so `activityCount = 3` and `endTime = 7`.
   - Activity `(8, 9)` is selected because `8 > 7`, so `activityCount = 4` and `endTime = 9`.
5. **Step 5:** Return `activityCount = 4`, which is the maximum number of non-overlapping activities.

### Time Complexity:

1. **Sorting** the activities by their end times takes **O(n log n)** where `n` is the number of activities.
2. **Iterating** through the activities to select the ones that do not overlap takes **O(n)**.
   
Thus, the overall time complexity is:
```
O(n log n) + O(n) = O(n log n)
```

### Space Complexity:

- We use a vector `v` to store the activities as pairs, which requires **O(n)** space.
- There are no other significant space-consuming operations.

Thus, the space complexity is:
```
O(n)
```
