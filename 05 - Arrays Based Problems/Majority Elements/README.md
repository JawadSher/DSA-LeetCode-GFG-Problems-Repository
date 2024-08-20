<h1 align='center'>Majority Elements</h1>

## Problem Statement

![image](https://github.com/user-attachments/assets/a39a1cb8-c224-4aeb-9fb0-44caa9e159fc)


## Problem Solution
```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int magority_element = -1;
        int counter = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(counter == 0){
                magority_element = nums[i];
            }

            if(magority_element == nums[i]){
                counter++;
            }else{
                counter--;
            }
            
        }
    return magority_element;
    }
};
```

## Problem Solution Explanation
The code you've written implements the **Boyer-Moore Voting Algorithm** to find the majority element in an array. The majority element is defined as the element that appears more than `n/2` times in the array, where `n` is the size of the array.

1. **Initialization:**
   ```cpp
   int magority_element = -1;
   int counter = 0;
   ```
   - `magority_element` is initialized to `-1` and will store the candidate for the majority element.
   - `counter` is initialized to `0` and will be used to count the occurrences of the candidate element.

2. **Iterating through the Array:**
   ```cpp
   for(int i = 0; i < nums.size(); i++){
       cout<<"Counter : "<<counter<<endl;
       if(counter == 0){
           magority_element = nums[i];
       }

       if(magority_element == nums[i]){
           counter++;
       }else{
           counter--;
       }
   }
   ```
   - The loop iterates through each element in the array `nums`.
   - **First Condition:**
     ```cpp
     if(counter == 0){
         magority_element = nums[i];
     }
     ```
     - If `counter` is `0`, it means that the current candidate (`magority_element`) is no longer valid, so the algorithm picks the current element (`nums[i]`) as the new candidate.
   - **Second Condition:**
     ```cpp
     if(magority_element == nums[i]){
         counter++;
     }else{
         counter--;
     }
     ```
     - If the current element (`nums[i]`) matches the candidate (`magority_element`), `counter` is incremented, indicating that the candidate appears more frequently.
     - If the current element is different from the candidate, `counter` is decremented, indicating a conflict with the current candidate.

3. **Returning the Majority Element:**
   ```cpp
   return magority_element;
   ```
   - After iterating through the array, the algorithm returns the candidate stored in `magority_element`. This candidate is the majority element.

### How the Boyer-Moore Voting Algorithm Works

- **Key Idea:**
  - The Boyer-Moore Voting Algorithm works by maintaining a candidate for the majority element and a counter. The counter keeps track of the balance between the candidate and other elements.
  - If the counter is `0`, a new candidate is chosen. If the current element matches the candidate, the counter is incremented; otherwise, it is decremented.

- **Why It Works:**
  - The algorithm guarantees that the candidate at the end of the array will be the majority element, provided there is one. This is because, by the time the array has been fully processed, the counter will have accounted for all elements in the array, leaving the majority element as the last candidate standing.

### Example Walkthrough

Let's go through the example `nums = {2, 2, 1, 1, 1, 2, 2}` step by step:

1. **Initial State:**
   - `magority_element = -1`, `counter = 0`

2. **Iteration 1 (`i = 0`):**
   - `nums[i] = 2`
   - `counter == 0`, so `magority_element = 2`
   - `magority_element == 2`, so `counter = 1`
   - **State:** `magority_element = 2`, `counter = 1`

3. **Iteration 2 (`i = 1`):**
   - `nums[i] = 2`
   - `magority_element == 2`, so `counter = 2`
   - **State:** `magority_element = 2`, `counter = 2`

4. **Iteration 3 (`i = 2`):**
   - `nums[i] = 1`
   - `magority_element != 1`, so `counter = 1`
   - **State:** `magority_element = 2`, `counter = 1`

5. **Iteration 4 (`i = 3`):**
   - `nums[i] = 1`
   - `magority_element != 1`, so `counter = 0`
   - **State:** `magority_element = 2`, `counter = 0`

6. **Iteration 5 (`i = 4`):**
   - `nums[i] = 1`
   - `counter == 0`, so `magority_element = 1`
   - `magority_element == 1`, so `counter = 1`
   - **State:** `magority_element = 1`, `counter = 1`

7. **Iteration 6 (`i = 5`):**
   - `nums[i] = 2`
   - `magority_element != 2`, so `counter = 0`
   - **State:** `magority_element = 1`, `counter = 0`

8. **Iteration 7 (`i = 6`):**
   - `nums[i] = 2`
   - `counter == 0`, so `magority_element = 2`
   - `magority_element == 2`, so `counter = 1`
   - **Final State:** `magority_element = 2`, `counter = 1`

**Result:**
- The algorithm returns `2`, which is indeed the majority element in the array.

This is how the Boyer-Moore Voting Algorithm efficiently finds the majority element with a time complexity of O(n) and space complexity of O(1).
