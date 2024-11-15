<h1 align='center'>Smallest - Range - in K - Lists</h1>

## Problem Statement

**Problem URL :** [Smallest Range in K Lists](https://www.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1)

![image](https://github.com/user-attachments/assets/c672e8fc-cfc7-459c-8fae-79e5175483ba)
![image](https://github.com/user-attachments/assets/be221229-359a-43ec-8105-d7a030254fa9)

## Problem Explanation
The task is to find the smallest range that includes at least one element from each of the `k` sorted lists (arrays). The range is defined as `[start, end]`, where:
- `start` is the smallest number in the range.
- `end` is the largest number in the range.

**Example:**
```plaintext
Input:
k = 3, n = 5
arr = [[4, 7, 9, 12, 15],
       [0, 8, 10, 14, 20],
       [6, 12, 16, 30, 50]]

Output:
[6, 8]
Explanation:
- The range `[6, 8]` contains at least one element from each list:
  - From the first list: 7
  - From the second list: 8
  - From the third list: 6
```



#### **Approach:**
We use a **min-heap** (priority queue) to solve this problem. The algorithm works as follows:

1. **Initialization:**
   - Start by adding the first element of each list to the min-heap.
   - Track the minimum (`mini`) and maximum (`maxi`) values among the elements in the heap.

2. **Range Calculation:**
   - The current range is `[mini, maxi]`.
   - As we process the heap, check if the current range is smaller than the previous range. If it is, update the range.

3. **Heap Operations:**
   - Remove the smallest element (`mini`) from the heap.
   - Add the next element from the same list to the heap.
   - Update `mini` and `maxi`.

4. **Termination:**
   - Stop when any of the lists is exhausted, as we can no longer include an element from every list.

## Problem Solution
```cpp
class Node{
    public:
        int data;
        int row;
        int col;
        
        Node(int data, int row, int col){
            this -> data = data;
            this -> row = row;
            this -> col = col;
        }
};

class compare{
    public:
        bool operator()(Node* a, Node* b){
            return a -> data > b -> data;
        }
};
class Solution{
    public:
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        priority_queue<Node*, vector<Node*>, compare> minHeap;
        
        for(int i = 0; i < k; i++){
            int element = arr[i][0];  
            
            mini = min(mini, element);
            maxi = max(maxi, element);
            
            minHeap.push(new Node(element, i, 0));
        }
        
        
        int start = mini, end = maxi;
        
        while(!minHeap.empty()){
            Node* temp = minHeap.top();
            minHeap.pop();
            
            mini = temp -> data;
            
            if(maxi - mini < end - start){
                start = mini;
                end = maxi;
            }
            
            if(temp -> col + 1 < n){
                maxi = max(maxi, arr[temp->row][temp->col + 1]);
                minHeap.push(new Node(arr[temp->row][temp->col + 1], temp -> row, temp -> col + 1));
            }else break;
            
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
   - The `Node` class is used to store three pieces of information:
     - `data`: The value of the current element.
     - `row`: The row index of the element (corresponding to the list it belongs to).
     - `col`: The column index of the element in its row.

2. **Custom Comparator:**
   ```cpp
   class compare {
   public:
       bool operator()(Node* a, Node* b) {
           return a->data > b->data;
       }
   };
   ```
   - This comparator defines the priority for the heap. 
   - It ensures the heap works as a **min-heap**, with the smallest element at the top.

3. **Initialization:**
   ```cpp
   priority_queue<Node*, vector<Node*>, compare> minHeap;
   int mini = INT_MAX;
   int maxi = INT_MIN;
   ```
   - `minHeap`: Stores the smallest elements across all lists.
   - `mini` and `maxi`: Track the smallest and largest values in the current range.

4. **Push Initial Elements into the Heap:**
   ```cpp
   for (int i = 0; i < k; i++) {
       int element = arr[i][0];
       mini = min(mini, element);
       maxi = max(maxi, element);
       minHeap.push(new Node(element, i, 0));
   }
   ```
   - For each list, add its first element to the heap.
   - Update `mini` and `maxi` to reflect the smallest and largest values.

5. **Track the Best Range:**
   ```cpp
   int start = mini, end = maxi;
   ```
   - Initialize the range `[start, end]` with the initial `mini` and `maxi`.

6. **Process the Min-Heap:**
   ```cpp
   while (!minHeap.empty()) {
       Node* temp = minHeap.top();
       minHeap.pop();
       mini = temp->data;

       if (maxi - mini < end - start) {
           start = mini;
           end = maxi;
       }

       if (temp->col + 1 < n) {
           int nextElement = arr[temp->row][temp->col + 1];
           maxi = max(maxi, nextElement);
           minHeap.push(new Node(nextElement, temp->row, temp->col + 1));
       } else {
           break;
       }
   }
   ```
   - Extract the smallest element (`mini`) from the heap.
   - Check if the current range `[mini, maxi]` is smaller than `[start, end]`.
   - Add the next element from the same list to the heap, and update `maxi`.
   - Stop if any list is exhausted.

7. **Return the Result:**
   ```cpp
   return {start, end};
   ```
   - Return the smallest range `[start, end]`.



### Step 3: Examples and Explanation

#### Example 1:
```plaintext
Input:
k = 3, n = 5
arr = [[4, 7, 9, 12, 15],
       [0, 8, 10, 14, 20],
       [6, 12, 16, 30, 50]]

Output:
[6, 8]
```
**Execution Steps:**
1. Initialize heap: `[4, 0, 6]`, `mini = 0`, `maxi = 6`.
2. Extract `mini = 0`, add `7` to the heap: `[4, 6, 7]`, `maxi = 7`.
3. Extract `mini = 4`, add `8` to the heap: `[6, 7, 8]`, `maxi = 8`.
4. Extract `mini = 6`, update range `[6, 8]`.



### Step 4: Time and Space Complexity

#### **Time Complexity:**
- **Heap Operations:** Each insertion and deletion in the heap takes \(O(\log k)\), where \(k\) is the number of lists.
- **Total Elements Processed:** \(n \times k\) elements are processed (each list has \(n\) elements).
- **Overall:** \(O(n \times k \times \log k)\).

#### **Space Complexity:**
- The heap stores at most \(k\) elements at any time: \(O(k)\).
- Additional space for the `Node` objects: \(O(k)\).
- **Overall:** \(O(k)\).



### Step 5: Recommendations for Students
1. **Understand the Min-Heap:**
   - Practice problems that involve heap data structures to solidify your understanding.
   - Implement custom comparators and understand their use cases.

2. **Optimize for Edge Cases:**
   - Test with edge cases like single-element lists or lists with duplicate elements.

3. **Debugging Tips:**
   - Print the heap contents at each step to debug and understand the flow.

By practicing such problems, you'll develop skills in working with advanced data structures like heaps and improve problem-solving efficiency!
