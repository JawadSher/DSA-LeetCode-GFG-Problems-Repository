<h1 align='center'>Count - Elements - With - Maximum - Frequency</h1>

## Problem Statement

**Problem URL :** [Count Elements With Maximum Frequency](https://leetcode.com/problems/count-elements-with-maximum-frequency/)

![image](https://github.com/user-attachments/assets/0822e141-1903-47a1-b671-ee004b9bf03a)

## Problem Explanation
The problem is asking us to **count how many elements** appear with the **maximum frequency** in a given list of integers.

### Problem Breakdown:
- You are given a vector of integers, `nums`.
- The task is to determine the element(s) that appear the most frequently (i.e., the maximum frequency).
- Once you have the most frequent element(s), return the total number of times the maximum frequency occurs, **counting all such elements** with the maximum frequency.

### Example 1:
```cpp
nums = [1, 2, 2, 3, 3, 3, 4]
```
- Frequency of elements:
  - `1` appears 1 time.
  - `2` appears 2 times.
  - `3` appears 3 times.
  - `4` appears 1 time.
  
- The maximum frequency is `3` (for element `3`).
- There is 1 element (`3`) with this frequency.
  
**Output:** `1` (because only the element `3` has the maximum frequency)

### Example 2:
```cpp
nums = [1, 2, 2, 3, 3]
```
- Frequency of elements:
  - `1` appears 1 time.
  - `2` appears 2 times.
  - `3` appears 2 times.
  
- The maximum frequency is `2` (for elements `2` and `3`).
- There are 2 elements (`2` and `3`) with this frequency.

**Output:** `4` (because both `2` and `3` appear 2 times, so the total frequency count is `2 + 2 = 4`)

### Approach Explanation:

1. **Count the Frequency of Each Element:**
   - The first step is to calculate how many times each element occurs in the list. We can use a `unordered_map` (hash map) where:
     - The key is the element.
     - The value is the frequency of that element.

2. **Find the Maximum Frequency:**
   - Once we know how many times each element appears, we need to find the maximum frequency from all elements.

3. **Count How Many Elements Have the Maximum Frequency:**
   - After identifying the maximum frequency, count how many different elements share this maximum frequency.

### Detailed Approach with Example:

Given `nums = [1, 2, 2, 3, 3, 3, 4]`, follow these steps:

- **Step 1:** Create a frequency map:
  ```
  freqMap = {1: 1, 2: 2, 3: 3, 4: 1}
  ```
- **Step 2:** Find the maximum frequency:
  ```
  maxFreq = 3
  ```
- **Step 3:** Count how many elements have the maximum frequency:
  ```
  totalCount = 1 (Only element `3` appears 3 times)
  ```

## Problem Solution
```cpp
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freqMap;

        for(auto i : nums) freqMap[i]++;

        int maxFreq = 0;

        for(auto pair : freqMap) maxFreq = max(maxFreq, pair.second);

        int totalCount = 0;
        for (auto pair : freqMap) if (pair.second == maxFreq) totalCount += pair.second;
            
        return totalCount;
    }
};
```

## Problem Solution Explanation

```cpp
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freqMap;
```
- This line initializes an `unordered_map` called `freqMap`. The key is an integer (`int`), and the value is an integer representing how many times that key appears in the list.

```cpp
        for(auto i : nums) freqMap[i]++;
```
- This loop iterates through each element in the `nums` vector.
- For each element `i`, we increment its corresponding frequency in the `freqMap`.

```cpp
        int maxFreq = 0;
```
- This initializes a variable `maxFreq` that will hold the highest frequency of any element in the `nums` vector.

```cpp
        for(auto pair : freqMap) maxFreq = max(maxFreq, pair.second);
```
- This loop iterates through each key-value pair in `freqMap`.
- For each pair, we update `maxFreq` to the larger value between the current `maxFreq` and the frequency (`pair.second`).

```cpp
        int totalCount = 0;
        for (auto pair : freqMap) if (pair.second == maxFreq) totalCount += pair.second;
```
- We initialize a variable `totalCount` to 0.
- Then, we iterate through each pair in `freqMap` and check if the frequency (`pair.second`) equals `maxFreq`. If it does, we add the frequency to `totalCount`.

```cpp
        return totalCount;
    }
};
```
- Finally, we return the total count of all elements that have the maximum frequency.

### Step 3: Examples and Explanation

Let’s walk through the examples with the code.

#### Example 1: `nums = [1, 2, 2, 3, 3, 3, 4]`

1. **Frequency Map Creation:**
   ```
   freqMap = {1: 1, 2: 2, 3: 3, 4: 1}
   ```
   
2. **Finding the Maximum Frequency:**
   ```
   maxFreq = 3 (The maximum frequency is for element 3)
   ```
   
3. **Count Elements with Maximum Frequency:**
   ```
   totalCount = 3 (Only element `3` has the maximum frequency)
   ```

**Output:** `3`

#### Example 2: `nums = [1, 2, 2, 3, 3]`

1. **Frequency Map Creation:**
   ```
   freqMap = {1: 1, 2: 2, 3: 2}
   ```

2. **Finding the Maximum Frequency:**
   ```
   maxFreq = 2 (The maximum frequency is 2)
   ```

3. **Count Elements with Maximum Frequency:**
   ```
   totalCount = 4 (Both `2` and `3` have the maximum frequency of 2)
   ```

**Output:** `4`

### Step 4: Time and Space Complexity

#### Time Complexity:
- **Building the Frequency Map:** 
  - We loop through each element in `nums` to build the frequency map, which takes **O(n)** time, where `n` is the number of elements in `nums`.
  
- **Finding Maximum Frequency:**
  - We loop through each key-value pair in the map to find the maximum frequency, which takes **O(k)** time, where `k` is the number of distinct elements in the map.
  
- **Counting Elements with Maximum Frequency:**
  - We loop through each key-value pair again to count the elements that have the maximum frequency, which also takes **O(k)** time.

**Overall Time Complexity:** O(n + k), where `n` is the number of elements in `nums` and `k` is the number of distinct elements.

In the worst case, `k` can be equal to `n`, so the time complexity is **O(n)**.

#### Space Complexity:
- We use an `unordered_map` to store the frequency of each element, which requires **O(k)** space, where `k` is the number of distinct elements in the input array.

**Overall Space Complexity:** O(k), where `k` is the number of distinct elements.

### Step 5: Recommendations for Students

- **Practice with Different Inputs:** 
  - Try using an empty array `nums = []`, or an array where all elements are the same, e.g., `nums = [1, 1, 1, 1]`.
  
- **Handle Edge Cases:**
  - Consider cases where the array is empty or all elements have the same frequency.
  
- **Understand Hash Maps:**
  - Hash maps are efficient for counting frequencies because they provide average O(1) time complexity for both insertions and lookups.

- **Consider Alternative Approaches:**
  - While the `unordered_map` is efficient, consider how you would solve this problem if you were constrained to using a different data structure.
