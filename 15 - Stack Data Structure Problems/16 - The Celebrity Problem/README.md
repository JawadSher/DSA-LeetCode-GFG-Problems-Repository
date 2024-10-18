<h1 align='center'>The - Celebrity - Problem</h1>

## Problem Statement

**Problem URL :** [The Celebrity Problem](https://www.geeksforgeeks.org/problems/the-celebrity-problem/1)

![image](https://github.com/user-attachments/assets/f0cb4225-edcf-45e5-8899-f1c32816a86a)

## Problem Explanation

You are at a party with **N** people. A celebrity is defined as someone who:
1. **Does not know anyone else** at the party (this means, for the celebrity, all entries in their row are `0`).
2. **Everyone else knows the celebrity** (this means, in the celebrity's column, all entries except the diagonal must be `1`).

Given a matrix `M` where:
- `M[i][j] = 1` means person `i` knows person `j`.
- `M[i][j] = 0` means person `i` does not know person `j`.

Your task is to identify the celebrity. If there is no celebrity, return `-1`.

### Example:

Consider the following matrix `M` for 4 people:
```cpp
M = [
  [0, 0, 1, 0],  // Person 0 knows person 2
  [0, 0, 1, 0],  // Person 1 knows person 2
  [0, 0, 0, 0],  // Person 2 knows no one
  [0, 0, 1, 0]   // Person 3 knows person 2
]
```

Here, person `2` is the celebrity because:
- Person `2` does not know anyone (all entries in row `2` are `0`).
- Everyone else knows person `2` (all entries in column `2` are `1` except the diagonal).

### Approach:

#### Using a Stack:
We can solve this problem using a **stack** in **O(N)** time. The idea is:
1. Push all the people into the stack.
2. Pop two people at a time and compare them:
   - If person `a` knows person `b`, then `a` cannot be a celebrity.
   - If person `a` doesn't know person `b`, then `b` cannot be a celebrity.
3. Continue this until one person remains. This person is the potential celebrity.
4. Finally, verify whether this person is indeed a celebrity by checking their row and column.

## Problem Solution
```cpp
class Solution {
  private:
    bool knows(vector<vector<int>> & mat, int a, int b){
        if(mat[a][b] == 1) return true;
        
        return false;
    }
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        stack<int> st;
        
        int n = mat.size();
        
        for(int i = 0; i < n; i++){
            st.push(i);
        }
        
        while(st.size() > 1){
            int a = st.top();
            st.pop();
            
            int b = st.top();
            st.pop();
            
            if(knows(mat, a, b)){
                st.push(b);
            }else{
                st.push(a);
            }
        }
        
        int candidate = st.top();
        
        bool rowCheck = true;
        for(int i = 0; i < n; i++){
            if(mat[candidate][i] == 1){
                rowCheck = false;
                break;
            }
        }
        
        
        bool colCheck = true;
        for(int i = 0; i < n; i++){
            if(i != candidate && mat[i][candidate] == 0){
                colCheck = false;
                break;
            }
        }
        
        
        if(rowCheck && colCheck) return candidate;
        
        return -1;
    }
};
```

## Problem Solution Explanation

```cpp
class Solution {
  private:
    // Helper function to determine if person 'a' knows person 'b'.
    bool knows(vector<vector<int>> &mat, int a, int b){
        if(mat[a][b] == 1) return true;
        return false;
    }
```
- **Line 1-7**: 
  - This is a helper function `knows(mat, a, b)` which checks if person `a` knows person `b`. 
  - If `mat[a][b] == 1`, it means person `a` knows person `b`, and the function returns `true`. Otherwise, it returns `false`.

```cpp
  public:
    // Main function to find the celebrity.
    int celebrity(vector<vector<int> >& mat) {
        stack<int> st;
        
        int n = mat.size();
```
- **Line 9-13**: 
  - The main function `celebrity()` takes the matrix `mat` as input.
  - We declare a stack `st` to help us filter out possible celebrity candidates.
  - `n` is the size of the matrix, which represents the number of people at the party.

```cpp
        // Push all people (0 to n-1) onto the stack.
        for(int i = 0; i < n; i++){
            st.push(i);
        }
```
- **Line 14-17**: 
  - We push all people, indexed from `0` to `n-1`, onto the stack. Initially, everyone is a potential celebrity.

```cpp
        // Eliminate non-celebrities.
        while(st.size() > 1){
            int a = st.top();
            st.pop();
            
            int b = st.top();
            st.pop();
            
            // If person 'a' knows person 'b', 'a' can't be a celebrity.
            if(knows(mat, a, b)){
                st.push(b);
            } else { 
                // If person 'a' doesn't know person 'b', 'b' can't be a celebrity.
                st.push(a);
            }
        }
```
- **Line 18-31**: 
  - We pop two people `a` and `b` from the stack at a time.
  - If `a` knows `b`, then `a` cannot be a celebrity, so we push `b` back into the stack.
  - If `a` doesn't know `b`, then `b` cannot be a celebrity, so we push `a` back into the stack.
  - This loop reduces the number of candidates until only one person remains, who could be a potential celebrity.

```cpp
        int candidate = st.top();
```
- **Line 32**: 
  - The remaining person in the stack is the potential celebrity.

```cpp
        // Check if the candidate knows anyone in their row.
        bool rowCheck = true;
        for(int i = 0; i < n; i++){
            if(mat[candidate][i] == 1){
                rowCheck = false;
                break;
            }
        }
```
- **Line 33-39**: 
  - This loop checks the row of the potential celebrity.
  - If `candidate` knows anyone (`mat[candidate][i] == 1` for any `i`), then they cannot be a celebrity, so `rowCheck` becomes `false`.

```cpp
        // Check if everyone knows the candidate (column check).
        bool colCheck = true;
        for(int i = 0; i < n; i++){
            if(i != candidate && mat[i][candidate] == 0){
                colCheck = false;
                break;
            }
        }
```
- **Line 40-47**: 
  - This loop checks the column corresponding to the potential celebrity.
  - If any person `i` does not know the candidate (`mat[i][candidate] == 0` for any `i`), then the candidate cannot be a celebrity, so `colCheck` becomes `false`.

```cpp
        // If both rowCheck and colCheck are true, candidate is the celebrity.
        if(rowCheck && colCheck) return candidate;
        
        return -1;
    }
};
```
- **Line 48-52**: 
  - If both `rowCheck` and `colCheck` are true, the candidate is indeed the celebrity, and we return their index.
  - If not, we return `-1`, indicating there is no celebrity.

### Example Walkthrough:

Let's consider a matrix `mat` with 3 people at a party:
```cpp
mat = [
  [0, 1, 1],  // Person 0 knows person 1 and 2
  [0, 0, 0],  // Person 1 knows no one
  [1, 1, 0]   // Person 2 knows person 0 and 1
]
```
- **Step 1**: Push everyone onto the stack: `[0, 1, 2]`.
- **Step 2**: Compare people:
  - Compare person `2` and `1`. Person `2` knows person `1`, so `2` can't be a celebrity. Push `1` back.
  - Compare person `1` and `0`. Person `0` knows person `1`, so `0` can't be a celebrity. Push `1` back.
- **Step 3**: Now, `1` is the only person left in the stack, so they are the potential celebrity.
- **Step 4**: Perform the row and column checks:
  - Row check: Person `1` doesn't know anyone.
  - Column check: Everyone knows person `1`.
- Therefore, person `1` is the celebrity, and the function returns `1`.

### Time Complexity:
- **O(N)**: 
  - The stack operations (pushing and popping) take linear time.
  - The row and column checks also take linear time.
  
Thus, the overall time complexity is **O(N)**.

### Space Complexity:
- **O(N)**: We use a stack to store all the people, which takes up space proportional to the number of people at the party.

This approach is efficient because we avoid a brute force solution, cutting down the time complexity to **O(N)** from **O(N^2)**.
