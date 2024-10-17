<h1 align='center'>Help - Classmates</h1>

## Problem Statement

**Problem URL :** [Help Classmates](https://www.geeksforgeeks.org/problems/help-classmates--141631/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/99e84e1d-6772-4177-b3ed-110e5488aa6a)
![image](https://github.com/user-attachments/assets/92f01cc2-37fd-4ff3-b571-885fa487a8a0)

## Problem Explanation

You are given an array `arr[]` of size `n`. For each element in the array, the task is to find the next smaller element on its right. If no such smaller element exists, return `-1`.

### Example

**Input:**
```
arr = [4, 8, 5, 2, 25]
```

**Output:**
```
[2, 5, 2, -1, -1]
```

### Explanation:
- For the element `4`, the next smaller element on the right is `2`.
- For `8`, the next smaller element is `5`.
- For `5`, the next smaller element is `2`.
- For `2`, no smaller element exists to the right, so the result is `-1`.
- For `25`, no smaller element exists to the right, so the result is `-1`.

### Approach

To solve this efficiently, we can use a **stack**. Instead of a brute-force method, where for each element you look to the right and find the smaller one (which takes O(n²) time), we can use a stack to reduce this to O(n).

We iterate through the array from right to left, maintaining a stack of elements. The stack helps us keep track of the next smaller element. If the element at the top of the stack is greater than or equal to the current element, we pop it because it cannot be the next smaller element. Once we find a smaller element, we add it to the result for the current index and push the current element onto the stack.

### Example Walkthrough

Let’s walk through the example:

**Input: `arr = [4, 8, 5, 2, 25]`**

1. Start with an empty stack and process elements from the right to the left.
2. For `25`, no smaller element exists on the right, so the output is `-1`. Push `25` onto the stack.
3. For `2`, no smaller element exists on the right, so the output is `-1`. Push `2` onto the stack.
4. For `5`, the top of the stack is `2`, which is smaller than `5`, so the output for `5` is `2`. Push `5` onto the stack.
5. For `8`, the top of the stack is `5`, which is smaller than `8`, so the output for `8` is `5`. Push `8` onto the stack.
6. For `4`, the top of the stack is `8`, which is greater than `4`. We pop `8`, and now the stack's top is `5`, which is also greater than `4`. We pop `5`, and now the stack's top is `2`, which is smaller than `4`, so the output for `4` is `2`. Push `4` onto the stack.

Final output: `[2, 5, 2, -1, -1]`.
## Problem Solution
```cpp
class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        stack<int> st;
        st.push(-1);
        
        vector<int> ans(n);
        
        for(int i = n-1; i >= 0; i--){
            int current = arr[i];
            
            while(st.top() >= current){
                st.pop();
            }
            
            ans[i] = st.top();
            st.push(current);
        }
        
        return ans;
    } 
};
```

## Problem Solution Explanation
Let's explain the code in a structured way, similar to the format in your image. Each step will focus on a specific line or section of the code, with clear explanations. 

#### Step 1: Initialize a stack
```cpp
stack<int> st;
```
- **What it does**: This line initializes an empty stack of integers.
- **Why it's important**: The stack will be used to keep track of elements as we traverse the array. It helps in efficiently finding the next smaller element for each current element we process.

---

#### Step 2: Push -1 onto the stack
```cpp
st.push(-1);
```
- **What it does**: We push `-1` onto the stack as a placeholder.
- **Why it's important**: This acts as a default value for cases where there is no smaller element to the right of an array element. It ensures that we have a value to return when needed.

---

#### Step 3: Create an answer array
```cpp
vector<int> ans(n);
```
- **What it does**: Initializes a vector `ans` of size `n` (the same size as the input array).
- **Why it's important**: This vector will store the results (the next smaller elements) for each element in the input array.

---

#### Step 4: Loop through the array from right to left
```cpp
for(int i = n-1; i >= 0; i--){
```
- **What it does**: This loop starts from the last element of the array and goes to the first element.
- **Why it's important**: By processing from right to left, we can efficiently find the next smaller element that has already been processed and is still in the stack.

---

#### Step 5: Store the current element
```cpp
int current = arr[i];
```
- **What it does**: The current element of the array is stored in a variable `current`.
- **Why it's important**: This allows us to easily compare `current` with elements in the stack to find the next smaller element.

---

#### Step 6: Check the top of the stack
```cpp
while(st.top() >= current){
```
- **What it does**: This while loop checks if the top of the stack is greater than or equal to the current element.
- **Why it's important**: If the top element is not smaller, it cannot be the next smaller element for the current item, so we need to pop it off.

---

#### Step 7: Pop elements from the stack
```cpp
st.pop();
```
- **What it does**: Removes the top element from the stack.
- **Why it's important**: This helps to discard elements that cannot serve as the next smaller element for the current element.

---

#### Step 8: Store the result in the answer array
```cpp
ans[i] = st.top();
```
- **What it does**: The current element’s next smaller element (now at the top of the stack) is stored in the answer array.
- **Why it's important**: This line populates the answer array with the correct results as we find them.

---

#### Step 9: Push the current element onto the stack
```cpp
st.push(current);
```
- **What it does**: The current element is pushed onto the stack.
- **Why it's important**: This allows the next elements to compare against this current element to find their next smaller elements.

---

#### Step 10: Return the answer array
```cpp
return ans;
```
- **What it does**: Finally, the method returns the populated answer array.
- **Why it's important**: This provides the result to the caller, containing the next smaller elements for each element in the input array.

---

Let's go through some detailed examples to illustrate how the "Help Classmates" problem works with the given code.

### Example 1:
**Input:**  
```plaintext
arr = [4, 8, 5, 2, 25]
```

**Step-by-Step Execution:**
1. **Initialize Stack and Answer Array:**
   - Stack: `[-1]`
   - Answer Array: `[0, 0, 0, 0, 0]`
   
2. **Process Each Element from Right to Left:**
   - **i = 4 (Current = 25)**:
     - Stack top (`-1`) is not >= 25. 
     - `ans[4] = -1` (the top of the stack).
     - Push `25` onto the stack.
     - Stack: `[-1, 25]`
     - Answer Array: `[0, 0, 0, 0, -1]`
  
   - **i = 3 (Current = 2)**:
     - Stack top (`25`) is >= 2. Pop it.
     - Stack top (`-1`) is not >= 2. 
     - `ans[3] = -1` (the top of the stack).
     - Push `2` onto the stack.
     - Stack: `[-1, 2]`
     - Answer Array: `[0, 0, 0, -1, -1]`
  
   - **i = 2 (Current = 5)**:
     - Stack top (`2`) is not >= 5. 
     - `ans[2] = 2` (the top of the stack).
     - Push `5` onto the stack.
     - Stack: `[-1, 2, 5]`
     - Answer Array: `[0, 0, 2, -1, -1]`

   - **i = 1 (Current = 8)**:
     - Stack top (`5`) is not >= 8.
     - `ans[1] = 5` (the top of the stack).
     - Push `8` onto the stack.
     - Stack: `[-1, 2, 5, 8]`
     - Answer Array: `[0, 5, 2, -1, -1]`

   - **i = 0 (Current = 4)**:
     - Stack top (`8`) is >= 4. Pop it.
     - Stack top (`5`) is >= 4. Pop it.
     - Stack top (`2`) is not >= 4.
     - `ans[0] = 2` (the top of the stack).
     - Push `4` onto the stack.
     - Stack: `[-1, 2, 4]`
     - Answer Array: `[2, 5, 2, -1, -1]`

**Final Output:**
```plaintext
[2, 5, 2, -1, -1]
```

---

### Example 2:
**Input:**
```plaintext
arr = [1, 3, 2, 4]
```

**Step-by-Step Execution:**
1. **Initialize Stack and Answer Array:**
   - Stack: `[-1]`
   - Answer Array: `[0, 0, 0, 0]`

2. **Process Each Element from Right to Left:**
   - **i = 3 (Current = 4)**:
     - Stack top (`-1`) is not >= 4.
     - `ans[3] = -1`.
     - Push `4` onto the stack.
     - Stack: `[-1, 4]`
     - Answer Array: `[0, 0, 0, -1]`

   - **i = 2 (Current = 2)**:
     - Stack top (`4`) is >= 2. Pop it.
     - Stack top (`-1`) is not >= 2.
     - `ans[2] = -1`.
     - Push `2` onto the stack.
     - Stack: `[-1, 2]`
     - Answer Array: `[0, 0, -1, -1]`

   - **i = 1 (Current = 3)**:
     - Stack top (`2`) is not >= 3.
     - `ans[1] = 2`.
     - Push `3` onto the stack.
     - Stack: `[-1, 2, 3]`
     - Answer Array: `[0, 2, -1, -1]`

   - **i = 0 (Current = 1)**:
     - Stack top (`3`) is >= 1. Pop it.
     - Stack top (`2`) is >= 1. Pop it.
     - Stack top (`-1`) is not >= 1.
     - `ans[0] = -1`.
     - Push `1` onto the stack.
     - Stack: `[-1, 1]`
     - Answer Array: `[-1, 2, -1, -1]`

**Final Output:**
```plaintext
[-1, 2, -1, -1]
```

---

### Example 3:
**Input:**
```plaintext
arr = [10, 3, 7, 4, 8]
```

**Step-by-Step Execution:**
1. **Initialize Stack and Answer Array:**
   - Stack: `[-1]`
   - Answer Array: `[0, 0, 0, 0, 0]`

2. **Process Each Element from Right to Left:**
   - **i = 4 (Current = 8)**:
     - Stack top (`-1`) is not >= 8.
     - `ans[4] = -1`.
     - Push `8` onto the stack.
     - Stack: `[-1, 8]`
     - Answer Array: `[0, 0, 0, 0, -1]`

   - **i = 3 (Current = 4)**:
     - Stack top (`8`) is >= 4. Pop it.
     - Stack top (`-1`) is not >= 4.
     - `ans[3] = -1`.
     - Push `4` onto the stack.
     - Stack: `[-1, 4]`
     - Answer Array: `[0, 0, 0, -1, -1]`

   - **i = 2 (Current = 7)**:
     - Stack top (`4`) is not >= 7.
     - `ans[2] = 4`.
     - Push `7` onto the stack.
     - Stack: `[-1, 4, 7]`
     - Answer Array: `[0, 0, 4, -1, -1]`

   - **i = 1 (Current = 3)**:
     - Stack top (`7`) is >= 3. Pop it.
     - Stack top (`4`) is >= 3. Pop it.
     - Stack top (`-1`) is not >= 3.
     - `ans[1] = -1`.
     - Push `3` onto the stack.
     - Stack: `[-1, 3]`
     - Answer Array: `[0, -1, 4, -1, -1]`

   - **i = 0 (Current = 10)**:
     - Stack top (`3`) is not >= 10.
     - `ans[0] = 3`.
     - Push `10` onto the stack.
     - Stack: `[-1, 3, 10]`
     - Answer Array: `[3, -1, 4, -1, -1]`

**Final Output:**
```plaintext
[3, -1, 4, -1, -1]
```

---

### Summary of Examples:
- In each case, we processed the array from the rightmost element to the left.
- The stack helped to keep track of potential next smaller elements, allowing us to efficiently find and return results.
- The final outputs illustrate the next smaller elements for each input scenario clearly.

### Time Complexity:
- **Overall Complexity**: \(O(n)\), where \(n\) is the number of elements in the array.
- **Reason**: Each element is pushed and popped from the stack at most once.

### Space Complexity:
- **Overall Complexity**: \(O(n)\) for the stack and the answer array.
