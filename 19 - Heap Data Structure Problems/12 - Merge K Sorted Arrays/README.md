<h1 align='center'>Merge - K Sorted - Arrays</h1>

## Problem Statement

**Problem URL :** [Merge K Sorted Arrays](https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1)

![image](https://github.com/user-attachments/assets/6b30d386-267d-4dc6-8fcf-f30cfa6aaac0)

## Problem Explanation
We are given `K` sorted arrays. Our goal is to merge all these sorted arrays into a single sorted array.

**Example**:
Let’s say we have `K = 3` arrays as follows:
- `arr[0] = [1, 4, 7]`
- `arr[1] = [2, 5, 8]`
- `arr[2] = [3, 6, 9]`

We need to merge them into one sorted array: `[1, 2, 3, 4, 5, 6, 7, 8, 9]`.

### Approach:

To merge these arrays, we can use a **min-heap** (or priority queue) to efficiently find the smallest element among the arrays. The approach is as follows:

1. **Initialize a min-heap** and push the first element of each array into it. Each element in the heap will store:
   - The value of the element
   - The index of the array it came from
   - The index of the element within that array

2. **Extract the smallest element from the min-heap** (top of the heap) and add it to the final merged array.

3. **Push the next element** from the array of the extracted element into the min-heap.

4. **Repeat** this process until the min-heap is empty, at which point we have our fully sorted merged array.

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

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<Node*, vector<Node*>, compare> pq;
        
        for(int i = 0; i < K; i++){
            Node* temp = new Node(arr[i][0], i, 0);
            pq.push(temp);
        }
        
        vector<int> answer;
        
        while(pq.size() > 0){
            Node* temp = pq.top();
            answer.push_back(temp -> data);
            pq.pop();
            
            int i = temp -> row;
            int j = temp -> col;
            
            if(j+1 < arr[i].size()){
                Node* next = new Node(arr[i][j+1], i, j+1);
                pq.push(next);
            }
        }
        
        return answer;
    }
};
```

## Problem Solution Explanation

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
```

1. **Explanation**:
   - We define a `Node` class to store each element we push into the min-heap.
   - Each `Node` stores:
     - `data`: the value of the element.
     - `row`: the index of the array the element belongs to.
     - `col`: the index of the element within that array.



```cpp
class compare{
    public:
        bool operator()(Node* a, Node* b){
            return a -> data > b -> data;
        }
};
```

2. **Explanation**:
   - We define a comparator class `compare` for the min-heap.
   - The comparator function is used by the heap to prioritize nodes based on their `data` value.
   - This comparator makes the min-heap place the smallest element at the top.



```cpp
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
```

3. **Explanation**:
   - The `mergeKArrays` function is part of the `Solution` class. It takes:
     - `arr`: a 2D vector where each row is a sorted array.
     - `K`: the number of sorted arrays.
   - It returns a sorted, merged array.



```cpp
        priority_queue<Node*, vector<Node*>, compare> pq;
```

4. **Explanation**:
   - We declare a min-heap `pq` using the `compare` class as the comparator.
   - This min-heap will help us find the smallest element among the arrays efficiently.



```cpp
        for(int i = 0; i < K; i++){
            Node* temp = new Node(arr[i][0], i, 0);
            pq.push(temp);
        }
```

5. **Explanation**:
   - We iterate through each of the `K` arrays and push the first element of each array into the min-heap `pq`.
   - We create a `Node` for each element, storing its value, the array index (`row`), and its index in the array (`col`).
   - This initializes the heap with the first element of each array.



```cpp
        vector<int> answer;
```

6. **Explanation**:
   - We declare a `vector<int> answer` to store the merged sorted array.



```cpp
        while(pq.size() > 0){
```

7. **Explanation**:
   - We continue processing while there are elements in the min-heap.



```cpp
            Node* temp = pq.top();
            answer.push_back(temp -> data);
            pq.pop();
```

8. **Explanation**:
   - We get the smallest element (`temp`) from the heap (`pq.top()`) and add its `data` to `answer`.
   - Then, we remove it from the heap using `pq.pop()`.



```cpp
            int i = temp -> row;
            int j = temp -> col;
```

9. **Explanation**:
   - We retrieve the `row` (`i`) and `col` (`j`) of the array that `temp` belongs to.



```cpp
            if(j+1 < arr[i].size()){
                Node* next = new Node(arr[i][j+1], i, j+1);
                pq.push(next);
            }
```

10. **Explanation**:
    - If there is a next element in the current array (`j+1 < arr[i].size()`), we push it into the heap.
    - We create a new `Node` with this next element, storing its value, the row (`i`), and the new column (`j+1`).



```cpp
        return answer;
    }
};
```

11. **Explanation**:
    - Finally, we return `answer`, which contains the merged sorted array.



### Step 3: Example Walkthrough

**Example**:  
Input:
```cpp
arr = [
    [1, 4, 7],
    [2, 5, 8],
    [3, 6, 9]
]
K = 3
```

Process:
1. Initialize the min-heap with the first element of each array: `[1, 2, 3]`.
2. Extract `1` (smallest), add it to `answer`, and push `4` from the first array.
3. Heap becomes `[2, 3, 4]`. Extract `2`, add to `answer`, push `5`.
4. Continue this process, and `answer` will eventually be `[1, 2, 3, 4, 5, 6, 7, 8, 9]`.

Output: `[1, 2, 3, 4, 5, 6, 7, 8, 9]`

### Step 4: Time and Space Complexity

1. **Time Complexity**:  
   - We push and pop each element from the min-heap once, and there are `N * K` elements (where `N` is the average length of each array).
   - Each push/pop operation in the min-heap takes `O(log K)` time.
   - Overall, the time complexity is `O(N * K * log K)`.

2. **Space Complexity**:
   - The space complexity is `O(K)` for the heap, as we store up to `K` elements at any time.

### Step 5: Additional Recommendations

For students:
- Understand how a min-heap works, as it is crucial for handling sorted data efficiently.
- Practice similar merging problems, like merging two sorted lists, before tackling `K` sorted arrays.
- Trace through the code with different inputs to become comfortable with the flow and logic.

This explanation should give you a clear understanding of how the solution works, along with step-by-step guidance on each line and example-driven insights.
