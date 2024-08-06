# Minimum Speed to Arrive on Time

You are given an array `dist` where `dist[i]` represents the distance of the i-th segment of a journey. You are also given a floating-point number `hour` representing the maximum amount of time allowed to complete the journey.

You need to find the minimum speed (in an integer value) required to travel through all segments within the given time `hour`. If it's impossible to complete the journey in the given time, return `-1`.

### Approach to Solve the Problem

1.  **Binary Search**:
    
    -   The problem requires finding the minimum speed. This can be efficiently done using a binary search.
    -   The search space for speed ranges from 1 to a very large number (e.g., `1e7`).
2.  **Calculate Total Time**:
    
    -   For a given speed, calculate the total time taken to travel all segments.
    -   For all segments except the last one, the time should be rounded up because even a partial hour counts as a full hour (ceil).
    -   For the last segment, use the exact time (no rounding).
3.  **Binary Search Logic**:
    
    -   Use the `reached_office` function to check if a given speed allows completing the journey within the allowed time.
    -   Adjust the search range based on whether the journey can be completed within the time or not.

## Line-by-Line Explanation

1.  **Function Definition: `reached_office`**:
    

    
    ```
    bool reached_office(vector<int>& dist, double hour, int min_speed) {
    ``` 
    
    -   This function checks if the journey can be completed within the given hour at a specified minimum speed.
2.  **Variable Initialization**:
    

    
    ```
    double time = 0.0;
    int n = dist.size();
    ``` 
    
    -   `time` keeps track of the total time taken.
    -   `n` is the number of segments in the journey.
3.  **Loop Through Segments (Except Last)**:

    
    ```
    for(int i = 0; i < n - 1; i++) {
        time += ceil(1.0 * dist[i] / min_speed);
    }
    ``` 
    
    -   Calculate the rounded-up time for each segment except the last one.
4.  **Exact Time for the Last Segment**:
    
 
    
    ```
    time += 1.0 * dist[n - 1] / min_speed;
    ``` 
    
    -   Add the exact time for the last segment.
5.  **Check Time Against Hour**:
    

    
    ```
    return time <= hour;
    ``` 
    
    -   Return true if the total time is within the allowed `hour`.
6.  **Function Definition: `minSpeedOnTime`**:
    

    
    ```
    int minSpeedOnTime(vector<int>& dist, double hour) {
    ``` 
    
    -   This function finds the minimum speed required to complete the journey within the given hour.
7.  **Variable Initialization**:
    

    
    ```
    int start = 1;
    int end = 1e7;
    int result = -1;
    ``` 
    
    -   `start` is the minimum possible speed.
    -   `end` is an arbitrary large value representing the maximum possible speed.
    -   `result` is initialized to `-1`, indicating an impossible case initially.
8.  **Binary Search Loop**:

    
    ```
    while(start <= end) {
        int min_speed = start + (end - start) / 2;
       ``` 
    
    -   Perform binary search within the speed range.
9.  **Check Current Speed**:

    
    ```
    if(reached_office(dist, hour, min_speed)) {
        result = min_speed;
        end = min_speed - 1;
    } else {
        start = min_speed + 1;
    }
    ``` 
    
    -   If the current speed allows completing the journey within the time, update `result` and try to find a smaller valid speed.
    -   If not, increase the speed and try again.
    
10.  **Return Result**:

  	  ```
       return result;
     ```
   
-   return the minimum valid speed or `-1` if it's impossible to complete the journey within the given time.
