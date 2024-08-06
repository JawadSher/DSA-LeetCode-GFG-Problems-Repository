# Successful Pairs of Spells and Potions

The problem is to find the number of successful pairs of spells and potions such that the product of a spell and a potion is greater than or equal to a given success value.

Given two arrays, `spells` and `potions`, and an integer `success`, for each spell, we need to count how many potions can form a successful pair with that spell.

### Approach

1.  **Sort the potions array**: Sorting allows us to use binary search to quickly find the threshold where potions can form successful pairs.
2.  **Binary Search (lower bound)**: For each spell, determine the minimum potion needed using binary search.
3.  **Count the pairs**: Count how many potions are greater than or equal to the minimum required potion for each spell.

### Detailed Code Explanation

```
class Solution {
public:
    // Binary search to find the lower bound of the minimum potion required
    int lowerBound(int start, int end, vector<int>& potions, int min_potion) {
        int answer = 0;
        while (start <= end) {
            int mid = start + (end - start) / 2; // Calculate the mid index
            if (potions[mid] >= min_potion) { // If potion at mid is greater or equal to min_potion
                answer = mid; // Update answer with mid index
                end = mid - 1; // Move to the left half
            } else {
                start = mid + 1; // Move to the right half
            }
        }
        return answer;
    }

    // Main function to find the number of successful pairs
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end()); // Sort the potions array
        int m = potions.size(); // Get the size of the potions array
        int n = spells.size(); // Get the size of the spells array

        int max_potion = potions[m - 1]; // Get the maximum potion value
        vector<int> answer; // Vector to store the results

        // Iterate through each spell
        for (int i = 0; i < n; i++) {
            int spell = spells[i]; // Get the current spell
            long long min_potion = ceil((1.0 * success) / spell); // Calculate the minimum potion required

            if (min_potion > max_potion) { // If min_potion is greater than max_potion
                answer.push_back(0); // No valid pairs, push 0
                continue; // Continue to the next spell
            }

            // Find the index of the first potion that is greater or equal to min_potion
            int index = lowerBound(0, m - 1, potions, min_potion);
            int count = m - index; // Calculate the number of valid potions
            answer.push_back(count); // Add the count to the result
        }
        return answer; // Return the result vector
    }
};
``` 

### Line-by-Line Explanation

1.  **Class Declaration**:

    
    ```
    class Solution {
    ``` 
    
    -   This declares the `Solution` class which will contain our functions.
3.  **Lower Bound Function**:
    

    
    ```
    int lowerBound(int start, int end, vector<int>& potions, int min_potion) {
    ``` 
    
    -   This function uses binary search to find the smallest index where the potion value is at least `min_potion`.
4.  **Variable Declaration**:
    

    
    ```
    int answer = 0;
    ``` 
    
    -   This variable will store the index of the lower bound.
6.  **Binary Search Loop**:
    

    
    ```
    while (start <= end) {
    ``` 
    
    -   This loop continues as long as the `start` index is less than or equal to the `end` index.
7.  **Calculate Mid Index**:
    

    
	   ```
    int mid = start + (end - start) / 2;
	 ``` 
    
    -   Calculate the middle index of the current range to avoid overflow.
8.  **Check Potion Value**:
    

    
    ```
    if (potions[mid] >= min_potion) {
        answer = mid;
        end = mid - 1;
    } else {
        start = mid + 1;
    }
    ``` 
    
    -   If the potion at `mid` is greater than or equal to `min_potion`, update the `answer` and move to the left half. Otherwise, move to the right half.
9.  **Return the Lower Bound Index**:
    

    
    ```
    return answer;
    ``` 
    
10.  **Main Function Declaration**:

    
      ```
      vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
      ``` 
    
11.  **Sort the Potions Array**:

    
      ```
      sort(potions.begin(), potions.end());
      ``` 
    
11.  **Get Array Sizes**:
  
    
	   ```
	    int m = potions.size();
	    int n = spells.size();
	   ``` 
    
12.  **Get Maximum Potion Value**:

	   ```
	    int max_potion = potions[m - 1];
	    ``` 
    
13.  **Initialize Result Vector**:
  
    
	    ```
     vector<int> answer;
     ``` 
    
15.  **Iterate Through Spells**:
    
	   ```
	    for (int i = 0; i < n; i++) {
	        int spell = spells[i];
	        long long min_potion = ceil((1.0 * success) / spell);
		``` 
    
16.  **Check If Minimum Potion is Greater Than Maximum**:
    
	    ```
	    if (min_potion > max_potion) {
	        answer.push_back(0);
	        continue;
	    }
		``` 
    
17.  **Find Lower Bound Index**:
    
	   ```
	    int index = lowerBound(0, m - 1, potions, min_potion);
	   ``` 
    
18.  **Count Valid Potions**:

    
      ```
      int count = m - index;
      ``` 
    
19.  **Store the Result**:
    
    
      ```
      answer.push_back(count);
      ``` 
    
20.  **Return the Result Vector**:

      ```
      return answer;
      ``` 
    

### Example Walkthrough

Given:

-   `spells = [5, 1, 3]`
-   `potions = [5, 4, 2, 1, 3]`
-   `success = 7`

1.  **Sort `potions`**: `[1, 2, 3, 4, 5]`
2.  **For each spell**:
    -   **Spell 5**:
        -   `min_potion = ceil(7/5) = 2`
        -   Find the lower bound index: 1 (`potions[1] >= 2`)
        -   Valid potions: 4 (`5, 4, 3, 2`)
        -   `answer = [4]`
    -   **Spell 1**:
        -   `min_potion = ceil(7/1) = 7`
        -   No valid potions (`max_potion = 5 < 7`)
        -   `answer = [4, 0]`
    -   **Spell 3**:
        -   `min_potion = ceil(7/3) = 3`
        -   Find the lower bound index: 2 (`potions[2] >= 3`)
        -   Valid potions: 3 (`5, 4, 3`)
        -   `answer = [4, 0, 3]`

### Conclusion

This code efficiently finds the number of successful pairs for each spell using sorting and binary search, significantly improving performance compared to a brute-force approach. It covers important DSA concepts and demonstrates a practical application of binary search within a sorted array.
