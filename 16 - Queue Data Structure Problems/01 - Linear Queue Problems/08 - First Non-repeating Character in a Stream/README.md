<h1 align='center'>First - Non-repeating - Character - in a - Stream</h1>

## Problem Statement

**Problem URL :** [First Non-repeating Character in a Stream](https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1)

![image](https://github.com/user-attachments/assets/4496bf07-1185-41d2-ac67-c303db60e2b2)
![image](https://github.com/user-attachments/assets/f275cbf5-bdb9-4bb6-882a-e9a2477055ae)

## Problem Explanation

Given a stream of characters (a string), your task is to find the first non-repeating character in the stream at each step. If all characters are repeating at a certain point, output a placeholder character (commonly `#`).

### Example

1. **Example 1:**
   - **Input:** `AABCC`
   - **Output:** `A#C`
   - **Explanation:**
     - After processing 'A': First non-repeating character is 'A'.
     - After processing second 'A': First non-repeating character is '#'.
     - After processing 'B': First non-repeating character is 'C'.
     - After processing 'C': First non-repeating character is 'C'.

2. **Example 2:**
   - **Input:** `aabc`
   - **Output:** `a#c`
   - **Explanation:**
     - After processing 'a': First non-repeating character is 'a'.
     - After processing second 'a': First non-repeating character is '#'.
     - After processing 'b': First non-repeating character is 'c'.
     - After processing 'c': First non-repeating character is 'c'.

### Approach

To solve this problem, we can use a combination of a hash map (to keep track of character frequencies) and a queue (to maintain the order of characters as they appear in the stream).

1. **Character Frequency Count:**
   - Use an unordered map to count the frequency of each character.

2. **Queue for Order:**
   - Use a queue to maintain the characters in the order they appear in the stream.

3. **Processing Each Character:**
   - For each character in the input string:
     - Increment its count in the hash map.
     - Push it into the queue.
     - Check the front of the queue:
       - If the front character's count is greater than 1, it means it’s repeating, so pop it from the queue.
       - If the front character's count is 1, it’s the first non-repeating character, and we add it to the result string.
     - If the queue becomes empty, append `#` to the result string.
## Problem Solution
```cpp
class Solution {
	public:
		string FirstNonRepeating(string A){
            unordered_map<char, int> count;
            queue<int> q;
            
            string ans = "";
            
            for(int i = 0; i < A.length(); i++){
                char ch = A[i];
                
                count[ch]++;
                q.push(ch);
                
                while(!q.empty()){
                    if(count[q.front()] > 1) q.pop();
                    else {
                        ans.push_back(q.front());
                        break;
                    }
                }
                if(q.empty()) ans.push_back('#');
            }
            
            return ans;
		}

};
```

## Problem Solution Explanation

1. **Initialization of Data Structures:**
   ```cpp
   unordered_map<char, int> count; // Map to store the frequency of each character
   queue<char> q; // Queue to maintain the order of characters
   string ans = ""; // Resultant string
   ```

2. **Iterate Through Each Character:**
   ```cpp
   for(int i = 0; i < A.length(); i++) {
       char ch = A[i]; // Get the current character
       count[ch]++; // Increment the count for this character
       q.push(ch); // Push the character into the queue
   ```
   - This loop iterates through the string, processing one character at a time.

3. **Processing the Queue:**
   ```cpp
   while(!q.empty()) {
       if(count[q.front()] > 1) // If the character at the front is repeating
           q.pop(); // Remove it from the queue
       else {
           ans.push_back(q.front()); // Otherwise, add it to the result
           break; // Break the loop
       }
   }
   ```
   - This nested loop checks the front character in the queue. If it's repeating, it pops it from the queue. If it's non-repeating, it appends it to the result string and breaks out of the loop.

4. **Handle Empty Queue:**
   ```cpp
   if(q.empty()) ans.push_back('#'); // If the queue is empty, append '#'
   ```
   - If all characters processed so far are repeating, `#` is added to the result string.

5. **Return the Result:**
   ```cpp
   return ans; // Return the string containing first non-repeating characters
   ```

### Complexity Analysis

1. **Time Complexity:**
   - **Frequency Count:** The for loop iterates over the string once, which is \( O(N) \), where \( N \) is the length of the string.
   - **Queue Processing:** In the worst case, each character can be pushed and popped from the queue, making the queue processing also \( O(N) \).
   - Therefore, the overall time complexity is:
     - **Total Time Complexity:** \( O(N) \)

2. **Space Complexity:**
   - **Hash Map:** The unordered map can store up to \( O(26) \) characters for lowercase English letters (or \( O(256) \) for extended ASCII), which is a constant.
   - **Queue:** In the worst case, all characters might be unique and thus stored in the queue, leading to \( O(N) \) space usage.
   - Therefore, the overall space complexity is:
     - **Total Space Complexity:** \( O(N) \)

### Summary of Complexities

- **Time Complexity:** \( O(N) \)
- **Space Complexity:** \( O(N) \)

This approach effectively finds the first non-repeating character at each point in the input stream, utilizing a hash map and a queue for efficient tracking.
