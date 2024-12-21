<h1 align="center">N - Meetings in - One Room</h1>

## Problem Statement

**Problem URL :** [N Meetings in One Room](https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1)

![image](https://github.com/user-attachments/assets/c046bdf9-fa02-40a8-8883-074b6e62c82b)

### Problem Explanation
You are given ( N ) meetings with their **start times** and **end times**. You must schedule these meetings in a single room such that the maximum number of meetings can take place without any overlap.

### **Constraints:**
1. A meeting can only start after the previous one ends.
2. The room can only host one meeting at a time.

### **Objective:**
Find the **maximum number of non-overlapping meetings** that can be conducted.

### **Input Format:**
- ( N ): Number of meetings.
- Two arrays:
  - `start[]`: An array where each element represents the start time of a meeting.
  - `end[]`: An array where each element represents the end time of a meeting.

### **Output Format:**
The maximum number of meetings that can be conducted.

### **Example:**

#### **Input:**
- ( N = 6 )
- `start[] = [1, 3, 0, 5, 8, 5]`
- `end[] = [2, 4, 6, 7, 9, 9]`

#### **Output:**
4

#### **Explanation:**
You can schedule the following 4 meetings:
- Meeting 1: Starts at 1 and ends at 2.
- Meeting 2: Starts at 3 and ends at 4.
- Meeting 4: Starts at 5 and ends at 7.
- Meeting 5: Starts at 8 and ends at 9.

### **Greedy Algorithm Approach**

The problem is to find the **maximum number of non-overlapping meetings** that can be scheduled in one room. The **greedy approach** involves always making the most optimal choice at each step to ensure the maximum number of meetings can fit without overlapping.
1. **Sort Meetings by End Time**:
   - Sort all meetings based on their ending times.
   - **Why?** 
     - The meeting that ends the earliest leaves the room free for subsequent meetings sooner.
     - This maximizes the number of meetings we can schedule.
   - **Example**:
     ```cpp
     start = [1, 3, 0, 5, 8, 5];
     end = [2, 4, 6, 7, 9, 9];
     ```
     After pairing and sorting by end times:
     ```
     Meetings: [(1, 2), (3, 4), (5, 7), (0, 6), (8, 9), (5, 9)]
     ```

2. **Select the First Meeting**:
   - Always select the first meeting after sorting since it has the earliest ending time.
   - **Example**:
     - First meeting: `(1, 2)` → Selected.
     - The room is now booked until time `2`.

3. **Iterate and Select Non-Overlapping Meetings**:
   - Traverse through the sorted meetings and select a meeting only if its **start time** is after the **end time** of the last selected meeting.
   - **Why?**
     - This ensures no overlap, allowing us to include as many meetings as possible.
   - **Example** (Continuing from Step 2):
     - Next meeting `(3, 4)` → `3 > 2` → Selected. Room now booked until `4`.
     - Next meeting `(5, 7)` → `5 > 4` → Selected. Room now booked until `7`.
     - Next meeting `(0, 6)` → `0 < 7` → Skipped (overlaps).
     - Next meeting `(8, 9)` → `8 > 7` → Selected. Room now booked until `9`.
     - Next meeting `(5, 9)` → `5 < 9` → Skipped (overlaps).

4. **Return the Count**:
   - The total number of meetings selected is the maximum number of non-overlapping meetings that can be scheduled.
   - **Example Result**: `4`.

### **Detailed Example**

#### **Input**:
```cpp
start = [1, 3, 0, 5, 8, 5];
end = [2, 4, 6, 7, 9, 9];
```

#### **Step 1: Pair and Sort by End Times**:
- Pair the meetings: `[(1, 2), (3, 4), (0, 6), (5, 7), (8, 9), (5, 9)]`.
- Sort by end time:
  ```
  [(1, 2), (3, 4), (5, 7), (0, 6), (8, 9), (5, 9)]
  ```

#### **Step 2: Initialize**:
- Select the first meeting: `(1, 2)` → Count = 1, `ansEnd = 2`.

#### **Step 3: Traverse and Select**:
- **Meeting (3, 4)**:
  - `3 > 2` → Selected.
  - Count = 2, `ansEnd = 4`.
- **Meeting (5, 7)**:
  - `5 > 4` → Selected.
  - Count = 3, `ansEnd = 7`.
- **Meeting (0, 6)**:
  - `0 < 7` → Skipped (overlaps).
- **Meeting (8, 9)**:
  - `8 > 7` → Selected.
  - Count = 4, `ansEnd = 9`.
- **Meeting (5, 9)**:
  - `5 < 9` → Skipped (overlaps).

#### **Step 4: Return Result**:
- Maximum number of meetings = `4`.


### **Why the Greedy Approach Works**

1. **Optimal Substructure**:
   - The problem can be divided into smaller subproblems, where selecting the earliest finishing meeting is the best choice for maximizing the remaining time.
   
2. **No Overlap**:
   - By ensuring no overlap through the condition `start > ansEnd`, the algorithm guarantees that each meeting selected is valid.

3. **Locally Optimal Choices → Globally Optimal Solution**:
   - Sorting by end time and selecting the earliest available meeting ensures the global maximum number of meetings.

## Problem Solution
```cpp
class Solution {
  public:

    // Function to find the maximum number of meetings that can be scheduled
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size(); // Get the number of meetings
        
        // Vector to store pairs of (start time, end time) for each meeting
        vector<pair<int, int>> v;
        
        // Populate the vector with pairs of start and end times
        for(int i = 0; i < n; i++) {
            pair<int, int> p = make_pair(start[i], end[i]); // Create a pair of start and end time
            v.push_back(p); // Add the pair to the vector
        }
        
        // Sort the meetings based on their end times
        sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second < b.second; // Sort by the second element (end time) of the pair
        });
        
        // Initialize count of selected meetings and set the end time of the first meeting
        int count = 1; // The first meeting is always selected
        int ansEnd = v[0].second; // Set the end time of the first meeting
        
        // Iterate through the remaining meetings
        for(int i = 1; i < n; i++) {
            // If the start time of the current meeting is greater than the end time of the last selected meeting
            if(v[i].first > ansEnd) {
                count++; // Increment the count of selected meetings
                ansEnd = v[i].second; // Update the end time to the current meeting's end time
            }
        }
        
        // Return the maximum number of non-overlapping meetings
        return count;
    }
};
```

## Problem Solution Explanation

```cpp
class Solution {
public:
```
- A class named `Solution` is created with public access specifier to hold the function `maxMeetings`.


```cpp
int maxMeetings(vector<int>& start, vector<int>& end) {
```
- `maxMeetings` is a member function that takes two vectors as input:
  - `start`: Contains the start times of the meetings.
  - `end`: Contains the end times of the meetings.
- **Purpose**: To find the maximum number of non-overlapping meetings that can be attended.

**Example Input**:
```cpp
start = [1, 3, 0, 5, 8, 5];
end = [2, 4, 6, 7, 9, 9];
```


```cpp
int n = start.size(); 
```
- The variable `n` holds the number of meetings, which is the size of the `start` vector.
- For the given example, `n = 6`.


```cpp
vector<pair<int, int>> v;
```
- A vector `v` is declared to store pairs of `(start, end)` times for the meetings.
- **Purpose**: To manage meetings as pairs for easier sorting and processing.


```cpp
for(int i = 0; i < n; i++) {
    pair<int, int> p = make_pair(start[i], end[i]);
    v.push_back(p);
}
```
- **What Happens**:
  - Iterates through all meetings.
  - Creates a pair of `start` and `end` times using `make_pair`.
  - Adds the pair to the vector `v`.
- **Result for Example**:
  - After this loop, `v = [(1, 2), (3, 4), (0, 6), (5, 7), (8, 9), (5, 9)]`.


```cpp
sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
});
```
- The `sort` function sorts the meetings in `v` by their **end times** (second element of each pair).
- **Custom Comparator**:
  - Lambda function compares two pairs and sorts them by `end` time.
- **Result for Example**:
  - After sorting: `v = [(1, 2), (3, 4), (5, 7), (0, 6), (8, 9), (5, 9)]`.


```cpp
int count = 1; 
int ansEnd = v[0].second;
```
- Initializes:
  - `count` to 1: Assumes the first meeting is always selected.
  - `ansEnd` to the end time of the first meeting: Tracks the end time of the last selected meeting.
- **After Initialization**:
  - `count = 1`.
  - `ansEnd = 2`.


```cpp
for(int i = 1; i < n; i++) {
    if(v[i].first > ansEnd) {
        count++;
        ansEnd = v[i].second;
    }
}
```
- Iterates through all meetings starting from the second meeting.
- **Condition**: Checks if the `start` time of the current meeting (`v[i].first`) is greater than the `ansEnd` (end time of the last selected meeting).
  - If true, selects the meeting:
    - Increments `count`.
    - Updates `ansEnd` to the current meeting’s `end` time.

**Step-by-Step Execution** for Example:
- **Iteration 1** (`i = 1`):
  - Meeting: `(3, 4)`.
  - Condition: `3 > 2` (True).
  - Select the meeting. Update `count = 2`, `ansEnd = 4`.
- **Iteration 2** (`i = 2`):
  - Meeting: `(5, 7)`.
  - Condition: `5 > 4` (True).
  - Select the meeting. Update `count = 3`, `ansEnd = 7`.
- **Iteration 3** (`i = 3`):
  - Meeting: `(0, 6)`.
  - Condition: `0 > 7` (False).
  - Skip the meeting.
- **Iteration 4** (`i = 4`):
  - Meeting: `(8, 9)`.
  - Condition: `8 > 7` (True).
  - Select the meeting. Update `count = 4`, `ansEnd = 9`.
- **Iteration 5** (`i = 5`):
  - Meeting: `(5, 9)`.
  - Condition: `5 > 9` (False).
  - Skip the meeting.


```cpp
return count;
```
- Returns the total number of selected meetings.
- **For Example Input**: `count = 4`.


### **Detailed Example Output**

**Input**:
```cpp
start = [1, 3, 0, 5, 8, 5];
end = [2, 4, 6, 7, 9, 9];
```

**Step-by-Step Execution**:
1. Pair the meetings: `[(1, 2), (3, 4), (0, 6), (5, 7), (8, 9), (5, 9)]`.
2. Sort by end time: `[(1, 2), (3, 4), (5, 7), (0, 6), (8, 9), (5, 9)]`.
3. Select meetings:
   - Meeting `(1, 2)` → Selected.
   - Meeting `(3, 4)` → Selected.
   - Meeting `(5, 7)` → Selected.
   - Meeting `(8, 9)` → Selected.

**Output**:
```cpp
4
```

### **Time Complexity**
1. **Pair Creation**:
   - O(n): Populating the vector with `n` pairs.
2. **Sorting**:
   - O(n log n): Sorting the vector of `n` pairs by their end times.
3. **Iteration**:
   - O(n): Iterating through the meetings to count non-overlapping ones.

**Total**: **O(n log n)** (dominated by sorting).

### **Space Complexity**
1. **Vector `v`**:
   - Stores `n` pairs, requiring O(n) space.
2. **Auxiliary Space for Sorting**:
   - Depends on the sorting algorithm but typically O(log n).

**Total**: **O(n)**.
