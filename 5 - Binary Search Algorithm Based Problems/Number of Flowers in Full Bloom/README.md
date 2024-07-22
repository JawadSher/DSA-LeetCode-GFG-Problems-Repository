# Number of Flowers in Full Bloom

You are given a list of flowers, where each flower is represented as a pair of integers `[start, end]` indicating that the flower starts blooming at `start` and stops blooming at `end` (inclusive). You are also given a list of integers `people` where each integer represents a specific time. For each time in the `people` list, you need to determine how many flowers are in full bloom at that specific time.

## Approach: Using Sorting and Binary Search

To solve this problem efficiently, we can use sorting and binary search. Here’s a detailed step-by-step explanation of the approach implemented in the given solution:

1.  **Initialization**:
    
    -   First, we determine the number of flowers (`m`) and the number of people (`n`).
    -   We create three vectors: `start_time` and `end_time` to store the start and end times of each flower, and `result` to store the number of flowers in full bloom for each time in `people`.
2.  **Extract Start and End Times**:
    
    -   We populate the `start_time` and `end_time` vectors with the respective start and end times of each flower.
3.  **Sort the Times**:
    
    -   We sort both `start_time` and `end_time` vectors. This allows us to perform binary search operations on these vectors to quickly determine the number of flowers that have started and ended blooming by a specific time.
4.  **Count Bloomed and Died Flowers for Each Time**:
    
    -   For each time in the `people` vector:
        -   **Bloomed Flowers**: We use `upper_bound` on the `start_time` vector to find the count of flowers that have started blooming by the given time. `upper_bound(start_time.begin(), start_time.end(), time)` returns an iterator to the first element that is greater than `time`, so the distance from the beginning of the vector to this iterator gives the number of flowers that have started blooming.
        -   **Died Flowers**: We use `lower_bound` on the `end_time` vector to find the count of flowers that have stopped blooming by the given time. `lower_bound(end_time.begin(), end_time.end(), time)` returns an iterator to the first element that is not less than `time`, so the distance from the beginning of the vector to this iterator gives the number of flowers that have stopped blooming.
        -   The number of flowers in full bloom at the given time is then calculated as the difference between the number of bloomed flowers and the number of died flowers.
5.  **Return the Result**:
    
    -   Finally, we return the `result` vector containing the number of flowers in full bloom for each time in `people`.

## Source Code Explanation


```
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
   ``` 

-   Defines a class `Solution` with a public method `fullBloomFlowers` that takes two arguments:
    -   `flowers`: A 2D vector where each sub-vector represents the start and end times of a flower blooming.
    -   `people`: A vector of times at which we want to know how many flowers are blooming.



 ```
 int m = flowers.size();
        int n = people.size();
   ``` 

-   `m` is the number of flower intervals.
-   `n` is the number of people (or query times).



 ```
 vector<int> start_time(m);
        vector<int> end_time(m);
        vector<int> result(n);
   ``` 

-   Initializes three vectors:
    -   `start_time`: Will hold the start times of the flowers.
    -   `end_time`: Will hold the end times of the flowers.
    -   `result`: Will store the number of blooming flowers at each query time.


 ```
 for(int i = 0; i < m; i++){
            start_time[i] = flowers[i][0];
            end_time[i] = flowers[i][1];
        }
   ``` 

-   Loops through each flower interval and fills the `start_time` and `end_time` vectors with the respective start and end times of the flowers.


 ```
 sort(start_time.begin(), start_time.end());
        sort(end_time.begin(), end_time.end());
   ``` 

-   Sorts the `start_time` and `end_time` vectors. Sorting is necessary to efficiently find how many flowers are blooming at any given time using binary search.



 ```
 for(int i = 0; i < n; i++){
            int time = people[i];
   ``` 

-   Loops through each query time in the `people` vector.


 ```
 int bloomed_flowers = upper_bound(start_time.begin(), start_time.end(), time) - start_time.begin();
 ``` 

-   `upper_bound` returns an iterator to the first element in `start_time` that is greater than `time`.
-   The difference between this iterator and `start_time.begin()` gives the count of flowers that have started blooming by `time`.



 ```
 int died_allready = lower_bound(end_time.begin(), end_time.end(), time) - end_time.begin();
 ``` 

-   `lower_bound` returns an iterator to the first element in `end_time` that is not less than `time`.
-   The difference between this iterator and `end_time.begin()` gives the count of flowers that have ended blooming by `time`.


 ```
 result[i] = bloomed_flowers - died_allready;
  }
   ``` 

-   Computes the number of flowers that are blooming at `time` by subtracting the count of flowers that have ended from the count of flowers that have started.
-   Stores the result in the `result` vector.



 ```
return result;
}
``` 

-   Returns the `result` vector, which contains the number of blooming flowers for each query time.

### Summary

1.  **Extract Start/End Times**: Collect start and end times of blooming periods from the `flowers` vector.
2.  **Sort Times**: Sort these times to use binary search efficiently.
3.  **Query Processing**: For each query time, use binary search (`upper_bound` and `lower_bound`) to count blooming flowers.
4.  **Calculate Results**: Compute and store the number of blooming flowers for each query time.

This approach efficiently processes each query in logarithmic time relative to the number of intervals, making it suitable for large datasets.
