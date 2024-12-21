<h1 align="center">Maximum - Meetings in - One Room</h1>

## Problem Statement

**Problem URL :** [Maximum Meetings in One Room](https://www.geeksforgeeks.org/problems/maximum-meetings-in-one-room/0)

![image](https://github.com/user-attachments/assets/c973f852-90df-40f8-a6a3-9acb77ba39df)

### Problem Explanation
The problem is about scheduling the maximum number of meetings in a single meeting room. Each meeting has a start time and an end time. The goal is to select as many non-overlapping meetings as possible and return the indices of the selected meetings in ascending order.

#### Example Input:

1. **Number of meetings**:  
   ( n = 6 )

2. **Start times**:  
   ( S = [1, 3, 0, 5, 8, 5] )

3. **End times**:  
   ( F = [2, 4, 6, 7, 9, 9] )

#### Expected Output:

Indices of meetings that can be attended:  
[ textbf{[1, 2, 4, 5]} ]


### Greedy Algorithm Explanation

The **Greedy Algorithm** is used to solve the problem by prioritizing meetings that end earliest to maximize the number of meetings that can be attended.  


#### Steps of the Greedy Algorithm:

1. **Input Preparation**:  
   Create a list of meetings where each meeting is represented by its start time, end time, and original index.

   Example:  
   ```
   v = [({1, 2}, 1), ({3, 4}, 2), ({0, 6}, 3), ({5, 7}, 4), ({8, 9}, 5), ({5, 9}, 6)]
   ```

2. **Sort Meetings**:  
   Sort meetings by their end times in ascending order. If two meetings have the same end time, sort them by their start times.

   Sorted list:  
   ```
   v = [({1, 2}, 1), ({3, 4}, 2), ({5, 7}, 4), ({0, 6}, 3), ({8, 9}, 5), ({5, 9}, 6)]
   ```

3. **Select Meetings**:
   - Initialize an empty list `ans` to store the indices of selected meetings.
   - Add the first meeting to the result and track its end time.
   - For each subsequent meeting, check if its start time is greater than the end time of the last selected meeting. If yes, select the meeting and update the end time.

   Selection process:  
   - **Meeting 1**: Add (index 1) → `endAns = 2`
   - **Meeting 2**: Add (index 2) → `endAns = 4`
   - **Meeting 4**: Add (index 4) → `endAns = 7`
   - **Meeting 5**: Add (index 5) → `endAns = 9`

   Selected meetings:  
   ```
   ans = [1, 2, 4, 5]
   ```

4. **Sort Results**:  
   Sort the selected indices in ascending order.

   Final result:  
   ```
   ans = [1, 2, 4, 5]
   ```

## Problem Solution
```cpp
class Solution {
public:
    // Function to find the order of meetings that can be scheduled
    // without overlapping, maximizing the number of meetings.
    vector<int> maxMeetings(int n, vector<int> &S, vector<int> &F) {
        vector<int> ans; // To store the result (order of meetings that can be scheduled)
        
        // Vector to store pairs of (start time, end time) with their original index
        vector<pair<pair<int, int>, int>> v;
        
        // Populate the vector with pairs of start and end times along with the meeting index
        for (int i = 0; i < n; i++) {
            v.push_back({{S[i], F[i]}, i + 1}); // Store the start time, end time, and meeting index (1-based)
        }
        
        // Sort the vector of meetings:
        // 1. First by end time (ascending).
        // 2. If two meetings have the same end time, sort by start time (ascending).
        sort(v.begin(), v.end(), [](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
            if (a.first.second == b.first.second) 
                return a.first.first < b.first.first; // Sort by start time if end times are equal
            return a.first.second < b.first.second; // Otherwise, sort by end time
        });
        
        // Select the first meeting (greedy choice)
        ans.push_back(v[0].second); // Add the index of the first meeting to the result
        int endAns = v[0].first.second; // Store the end time of the first selected meeting
        
        // Iterate through the remaining meetings to find non-overlapping meetings
        for (int i = 1; i < n; i++) {
            // Check if the start time of the current meeting is greater than
            // the end time of the last selected meeting
            if (v[i].first.first > endAns) {
                ans.push_back(v[i].second); // Add the meeting index to the result
                endAns = v[i].first.second; // Update the end time to the current meeting's end time
            }
        }
        
        // Sort the result to return the meeting indices in ascending order
        sort(ans.begin(), ans.end());
        
        return ans; // Return the order of meeting indices that can be scheduled
    }
};
```

## Problem Solution Explanation

```cpp
class Solution {
public:
    vector<int> maxMeetings(int n, vector<int> &S, vector<int> &F) {
        vector<int> ans; // To store the result (order of meetings that can be scheduled)
        vector<pair<pair<int, int>, int>> v; // To store (start time, end time, index)
```

- `ans`: Stores indices of selected meetings.  
- `v`: Stores meeting information as ((text{start time}, text{end time}, text{index})).


```cpp
        // Populate vector `v` with start times, end times, and their original indices.
        for (int i = 0; i < n; i++) {
            v.push_back({{S[i], F[i]}, i + 1}); 
        }
```

- Loop iterates through all meetings.  
- Push each meeting's start time, end time, and index (1-based) into `v`.

Example after population:  
```
v = [({1, 2}, 1), ({3, 4}, 2), ({0, 6}, 3), ({5, 7}, 4), ({8, 9}, 5), ({5, 9}, 6)]
```


```cpp
        // Sort meetings by end time. If end times are equal, sort by start time.
        sort(v.begin(), v.end(), [](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
            if (a.first.second == b.first.second) 
                return a.first.first < b.first.first;
            return a.first.second < b.first.second;
        });
```

- Meetings are sorted by:
  - End time (ascending).
  - If two meetings have the same end time, they are sorted by start time.

Sorted `v`:  
```
v = [({1, 2}, 1), ({3, 4}, 2), ({5, 7}, 4), ({0, 6}, 3), ({8, 9}, 5), ({5, 9}, 6)]
```


```cpp
        // Add the first meeting to the result
        ans.push_back(v[0].second); 
        int endAns = v[0].first.second;
```

- Add the first meeting (index 1) to the result.  
- `endAns` tracks the end time of the last selected meeting.


```cpp
        // Iterate through remaining meetings
        for (int i = 1; i < n; i++) {
            if (v[i].first.first > endAns) {
                ans.push_back(v[i].second); 
                endAns = v[i].first.second;
            }
        }
```

- For each meeting, check if its start time is greater than `endAns`.  
- If yes, add the meeting's index to `ans` and update `endAns`.


```cpp
        // Sort the result indices
        sort(ans.begin(), ans.end());
        
        return ans; 
    }
};
```

- Sort the indices in ascending order.  
- Return the final result.


### Example Walkthrough

#### Input:
( n = 6, S = [1, 3, 0, 5, 8, 5], F = [2, 4, 6, 7, 9, 9] )

#### Execution:
1. Populate ( v ):  
   ```
   [({1, 2}, 1), ({3, 4}, 2), ({0, 6}, 3), ({5, 7}, 4), ({8, 9}, 5), ({5, 9}, 6)]
   ```

2. Sort ( v ):  
   ```
   [({1, 2}, 1), ({3, 4}, 2), ({5, 7}, 4), ({0, 6}, 3), ({8, 9}, 5), ({5, 9}, 6)]
   ```

3. Select meetings:  
   ```
   ans = [1, 2, 4, 5]
   ```

4. Sort ( ans ):  
   ```
   [1, 2, 4, 5]
   ```

#### Output:
```
[1, 2, 4, 5]
```


### Time and Space Complexity

1. **Time Complexity**:  
   - Sorting meetings: ( O(n log n) ).  
   - Iterating through meetings: ( O(n) ).  
   Total: ( O(n log n) ).

2. **Space Complexity**:  
   - Auxiliary space for vector ( v ): ( O(n) ).  
   Total: ( O(n) ).
