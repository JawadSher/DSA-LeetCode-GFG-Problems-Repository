<h1 align='center'>Find - Median - From - Data - Stream</h1>

## Problem Statement

**Problem URL :** [Find Median From Data Stream](https://leetcode.com/problems/find-median-from-data-stream/)

![image](https://github.com/user-attachments/assets/82528e9c-86b6-4595-86a2-bab708022e8d)
![image](https://github.com/user-attachments/assets/1efa30c8-37a1-4e2d-a641-2f57ad275661)

## Problem Explanation
The task is to continuously find the median of a stream of integers. 

- **Median Definition**: The median of a sorted dataset is:
  - The middle value if the dataset has an odd number of elements.
  - The average of the two middle values if the dataset has an even number of elements.
- **Constraints**:
  - We cannot store all the numbers and sort them after every insertion, as it would be inefficient for large data streams.

#### **Example**
1. Numbers: `[5]`  
   Median: `5` (only one number).
2. Numbers: `[5, 10]`  
   Median: `(5 + 10) / 2 = 7.5`.
3. Numbers: `[5, 10, 3]`  
   Sorted: `[3, 5, 10]`  
   Median: `5`.



#### **Approach**
We use two heaps:
1. **Max-Heap** (`maxHeap`): Stores the smaller half of the numbers. The maximum number of this half is the top of the heap.
2. **Min-Heap** (`minHeap`): Stores the larger half of the numbers. The minimum number of this half is the top of the heap.

**Steps**:
1. Insert the number into one of the heaps:
   - If the number is smaller than or equal to the top of `maxHeap`, add it to `maxHeap`.
   - Otherwise, add it to `minHeap`.
2. Balance the heaps:
   - Ensure that the difference in sizes between `maxHeap` and `minHeap` is at most 1.
   - If `maxHeap` has too many elements, move the top of `maxHeap` to `minHeap`.
   - If `minHeap` has too many elements, move the top of `minHeap` to `maxHeap`.
3. Find the median:
   - If the heaps are of equal size, the median is the average of the tops of both heaps.
   - If one heap has more elements, the median is the top of that heap.

## Problem Solution
```cpp
class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.size() == 0 || num <= maxHeap.top()) maxHeap.push(num);
        else minHeap.push(num);

        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }else if (minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(minHeap.size() ==  maxHeap.size()) return (maxHeap.top() + minHeap.top()) / 2.0;
        else return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```

## Problem Solution Explanation

```cpp
class MedianFinder {
public:
    priority_queue<int> maxHeap; // Max-heap for the smaller half
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap for the larger half
```

- **Explanation**:
  - `maxHeap` keeps the smaller numbers, and the largest of these numbers is the top.
  - `minHeap` keeps the larger numbers, and the smallest of these numbers is the top.



```cpp
    MedianFinder() { }
```

- **Explanation**:
  - Constructor to initialize the `MedianFinder` object.
  - No specific setup is required here.



```cpp
    void addNum(int num) {
        if(maxHeap.size() == 0 || num <= maxHeap.top()) 
            maxHeap.push(num); 
        else 
            minHeap.push(num);
```

- **Explanation**:
  - If `maxHeap` is empty or `num` is less than or equal to the largest number in `maxHeap`, add it to `maxHeap`.
  - Otherwise, add it to `minHeap`.

- **Example**:
  Adding `10` when both heaps are empty:
  - `maxHeap = [10]`, `minHeap = []`.

  Adding `15`:
  - `maxHeap.top() = 10`. Since `15 > 10`, add it to `minHeap`.
  - Result: `maxHeap = [10]`, `minHeap = [15]`.



```cpp
        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }else if (minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
```

- **Explanation**:
  - If `maxHeap` has more than one extra element, move its top to `minHeap`.
  - If `minHeap` has more elements, move its top to `maxHeap`.

- **Example**:
  Adding `5` to `maxHeap = [10]`, `minHeap = [15]`:
  - `maxHeap = [10, 5]`, `minHeap = [15]` (unbalanced).
  - Move `10` to `minHeap`.
  - Result: `maxHeap = [5]`, `minHeap = [10, 15]`.



```cpp
    double findMedian() {
        if(minHeap.size() == maxHeap.size()) 
            return (maxHeap.top() + minHeap.top()) / 2.0;
        else 
            return maxHeap.top();
    }
};
```

- **Explanation**:
  - If the sizes of `maxHeap` and `minHeap` are equal, return the average of their tops.
  - Otherwise, return the top of `maxHeap` (it will always have more elements if sizes are unequal).



### **Step 3: Examples and Expected Outputs**

#### Example Input: `[5, 15, 1, 3]`
1. Add `5`:
   - `maxHeap = [5]`, `minHeap = []`.
   - Median: `5`.

2. Add `15`:
   - `maxHeap = [5]`, `minHeap = [15]`.
   - Median: `(5 + 15) / 2 = 10`.

3. Add `1`:
   - `maxHeap = [5, 1]`, `minHeap = [15]` (unbalanced).
   - Move `5` to `minHeap`.
   - `maxHeap = [1]`, `minHeap = [5, 15]`.
   - Median: `5`.

4. Add `3`:
   - `maxHeap = [3, 1]`, `minHeap = [5, 15]` (balanced).
   - Median: `(3 + 5) / 2 = 4`.



### **Step 4: Time and Space Complexity**

#### **Time Complexity**
1. **Insertion**:
   - Inserting into a heap takes \(O(\log n)\).
   - Balancing takes \(O(\log n)\).
   - Total per insertion: \(O(\log n)\).
2. **Finding Median**:
   - Fetching the top of the heaps takes \(O(1)\).
   - Total: \(O(1)\).

For \(n\) numbers:
- **Total Time Complexity**: \(O(n \log n)\).



#### **Space Complexity**
- Both heaps together store all elements: \(O(n)\).
- **Total Space Complexity**: \(O(n)\).



### **Step 5: Additional Recommendations**
1. **Practice Similar Problems**:
   - "Sliding Window Median."
   - "Kth Largest Element in a Stream."
2. **Edge Cases**:
   - Single number: `[5]`.
   - All numbers are the same: `[10, 10, 10]`.
   - Stream of negative numbers.

3. **Debugging Tip**:
   - Visualize the heaps after each insertion to understand their balance.

This detailed explanation ensures a beginner-friendly understanding of the problem and solution. 😊
