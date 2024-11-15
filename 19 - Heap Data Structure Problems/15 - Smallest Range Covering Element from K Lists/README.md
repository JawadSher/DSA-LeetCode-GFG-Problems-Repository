<h1 align='center'>Smallest - Range - Covering - Element From - K Lists</h1>

## Problem Statement

**Problem URL :** [Smallest Range Covering Element From k Lists](https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/)

![image](https://github.com/user-attachments/assets/5a5951b7-1f5e-40e4-bde6-99270a0de706)

## Problem Explanation
You are given `k` sorted lists of integers. Your task is to find the smallest range \([start, end]\) such that at least one number from each list is included in the range.

**Key Points:**
1. The range \([start, end]\) is defined as the difference \(end - start\), and you aim to minimize this difference.
2. Each list contributes at least one number to the range.

**Example:**
```plaintext
Input: nums = [[4, 10, 15, 24, 26],
               [0, 9, 12, 20],
               [5, 18, 22, 30]]

Output: [20, 24]
Explanation:
- The range [20, 24] includes at least one element from each list:
  - From the first list: 24
  - From the second list: 20
  - From the third list: 22
```



#### **Approach:**

We use a **min-heap (priority queue)** to solve this problem efficiently. Here's how it works:

1. **Initialization:**
   - Start by adding the first element from each list into the min-heap.
   - Track the minimum (`mini`) and maximum (`maxi`) values among the elements in the heap.

2. **Heap Operations:**
   - Extract the smallest element (`mini`) from the heap.
   - Calculate the range `[mini, maxi]`.
   - If this range is smaller than the previously recorded range, update it.

3. **Add the Next Element:**
   - From the same list as the extracted element, add the next element to the heap.
   - Update the value of `maxi` if the new element is larger.

4. **Termination:**
   - Stop when any list is exhausted, as we can no longer include an element from every list.

## Problem Solution
```cpp
class Node {
    public:
        int data;
        int row;
        int col;

        Node(int data, int row, int col) { 
            this->data = data;
            this->row = row;
            this->col = col;
        }
};

class compare{
    public:
        bool operator()(Node* a, Node* b){
            return a -> data > b -> data;
        }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        priority_queue<Node*, vector<Node*>, compare> pq;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i = 0; i < k; i++){
            int element = nums[i][0];

            maxi = max(maxi, element);
            mini = min(mini, element);

            pq.push(new Node(element, i, 0));
        }

        int start = mini;
        int end = maxi;

        while(!pq.empty()){
            Node* temp = pq.top();
            pq.pop();

            mini = temp -> data;

            if(maxi - mini < end - start){
                start = mini;
                end = maxi;
            }

            if(temp -> col + 1 < nums[temp -> row].size()){
                int nextElement = nums[temp -> row][temp -> col + 1];

                maxi = max(nextElement, maxi);
                pq.push(new Node(nextElement, temp -> row, temp -> col + 1));
            }else{
                break;
            }
        }

        return {start, end};
    }
};

```

## Problem Solution Explanation

1. **Node Class:**
   ```cpp
   class Node {
   public:
       int data;
       int row;
       int col;

       Node(int data, int row, int col) { 
           this->data = data;
           this->row = row;
           this->col = col;
       }
   };
   ```
   - The `Node` class stores information about an element:
     - `data`: The value of the element.
     - `row`: The index of the list (row) to which the element belongs.
     - `col`: The index of the element within its list (column).

2. **Custom Comparator:**
   ```cpp
   class compare {
   public:
       bool operator()(Node* a, Node* b) {
           return a->data > b->data;
       }
   };
   ```
   - This comparator ensures the heap functions as a **min-heap**, meaning the smallest element is at the top.

3. **Priority Queue Declaration:**
   ```cpp
   priority_queue<Node*, vector<Node*>, compare> pq;
   ```
   - A min-heap (`pq`) to store nodes representing the smallest elements from the lists.

4. **Initialize `mini` and `maxi`:**
   ```cpp
   int mini = INT_MAX;
   int maxi = INT_MIN;
   ```
   - `mini`: Tracks the smallest value in the current range.
   - `maxi`: Tracks the largest value in the current range.

5. **Add First Elements to the Heap:**
   ```cpp
   for (int i = 0; i < k; i++) {
       int element = nums[i][0];
       maxi = max(maxi, element);
       mini = min(mini, element);
       pq.push(new Node(element, i, 0));
   }
   ```
   - Add the first element of each list to the heap.
   - Update `mini` and `maxi` based on these elements.

6. **Initialize the Range:**
   ```cpp
   int start = mini;
   int end = maxi;
   ```
   - The range \([start, end]\) is initialized using the smallest and largest elements.

7. **Process the Heap:**
   ```cpp
   while (!pq.empty()) {
       Node* temp = pq.top();
       pq.pop();
       mini = temp->data;

       if (maxi - mini < end - start) {
           start = mini;
           end = maxi;
       }

       if (temp->col + 1 < nums[temp->row].size()) {
           int nextElement = nums[temp->row][temp->col + 1];
           maxi = max(nextElement, maxi);
           pq.push(new Node(nextElement, temp->row, temp->col + 1));
       } else {
           break;
       }
   }
   ```
   - Extract the smallest element (`mini`) from the heap.
   - Check if the range `[mini, maxi]` is smaller than the current `[start, end]`.
   - Add the next element from the same list to the heap if available. Update `maxi` as needed.

8. **Return the Result:**
   ```cpp
   return {start, end};
   ```
   - Return the smallest range `[start, end]`.



### Step 3: Examples and Explanation

#### Example 1:
```plaintext
Input: nums = [[4, 10, 15, 24, 26],
               [0, 9, 12, 20],
               [5, 18, 22, 30]]

Output: [20, 24]
```

**Execution Steps:**
1. Add the first elements: `[4, 0, 5]`, `mini = 0`, `maxi = 5`.
2. Extract `mini = 0`, add 9: `[4, 5, 9]`, `maxi = 9`.
3. Extract `mini = 4`, add 10: `[5, 9, 10]`, `maxi = 10`.
4. Extract `mini = 5`, add 18: `[9, 10, 18]`, `maxi = 18`.
5. Extract `mini = 9`, add 12: `[10, 12, 18]`, `maxi = 18`.
6. Extract `mini = 10`, add 15: `[12, 15, 18]`, `maxi = 18`.
7. Extract `mini = 12`, add 20: `[15, 18, 20]`, `maxi = 20`.
8. Extract `mini = 15`, add 24: `[18, 20, 24]`, `maxi = 24`.
9. Extract `mini = 18`, add 22: `[20, 22, 24]`, `maxi = 24`.
10. Extract `mini = 20`. Update range to `[20, 24]`.



### Step 4: Time and Space Complexity

#### **Time Complexity:**
- **Heap Operations:** Each insertion and deletion in the heap takes \(O(\log k)\), where \(k\) is the number of lists.
- **Total Elements Processed:** Each list contributes \(n\) elements, so \(n \times k\) elements are processed.
- **Overall Complexity:** \(O(n \times k \times \log k)\).

#### **Space Complexity:**
- The heap stores at most \(k\) elements at any time: \(O(k)\).
- Additional space for the `Node` objects: \(O(k)\).
- **Overall Complexity:** \(O(k)\).



### Step 5: Recommendations for Students

1. **Practice Heap Problems:**
   - Familiarize yourself with heap operations and custom comparators.

2. **Debugging Tip:**
   - Print the contents of the heap during each iteration to visualize the algorithm’s progression.

3. **Edge Cases:**
   - Test with edge cases like:
     - Single-element lists.
     - Lists of unequal lengths.

By solving such problems, you'll develop a deeper understanding of advanced data structures and their applications!
