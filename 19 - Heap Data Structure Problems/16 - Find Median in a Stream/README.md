<h1 align='center'>Find - Median - In a - Stream</h1>

## Problem Statement

**Problem URL :** [Find Median In a Stream](https://www.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1)

![image](https://github.com/user-attachments/assets/9072d191-dae3-4990-b8e5-ae7b81c01c1b)
![image](https://github.com/user-attachments/assets/fd90f719-56a0-460c-a76b-ece0c3aafad0)
![image](https://github.com/user-attachments/assets/62686092-9d2f-49d9-82b3-3e107412a4b3)

## Problem Explanation
The task is to find the **median** of a stream of integers. The median is the middle value in a sorted list of numbers. If the list has an odd number of elements, the median is the middle one. If the list has an even number of elements, the median is the average of the two middle numbers.

For example:
1. **Input**: [2, 3, 4]  
   **Output**: 3  
   The sorted stream is [2, 3, 4], and 3 is the median.

2. **Input**: [2, 3, 4, 5]  
   **Output**: (3 + 4) / 2 = 3.5  
   The sorted stream is [2, 3, 4, 5], and the median is the average of the two middle numbers.

The problem asks for an **efficient solution** to find the median as new numbers are added to the stream. A naive approach of sorting the numbers repeatedly would be too slow for large inputs.



#### **Approach**
We use the **two-heap approach** to maintain the stream of numbers efficiently:
1. **Divide the Stream**:
   - Use a **max-heap** to store the smaller half of the numbers.
   - Use a **min-heap** to store the larger half of the numbers.

2. **Maintain Balance**:
   - Ensure the heaps are balanced such that their sizes differ by at most 1.
   - If the max-heap size exceeds the min-heap by more than 1, move the largest element of the max-heap to the min-heap.
   - If the min-heap size exceeds the max-heap, move the smallest element of the min-heap to the max-heap.

3. **Calculate Median**:
   - If both heaps are of the same size, the median is the average of their tops.
   - Otherwise, the median is the top of the max-heap (since the max-heap will always contain one extra element if the sizes differ).

## Problem Solution
```cpp
class Solution
{   
    public:
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        void insertHeap(int &x)
        {
            if(maxHeap.size() == 0 || x < maxHeap.top()) maxHeap.push(x);
            else minHeap.push(x);
            
            balanceHeaps();
        }
    
        void balanceHeaps(){
            if(maxHeap.size() > minHeap.size() + 1){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }else if(minHeap.size() > maxHeap.size()){
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
        
        double getMedian(){
            if(maxHeap.size() == minHeap.size()) return (minHeap.top() + maxHeap.top()) / 2.0; 
            else return maxHeap.top();
        }
};

```

## Problem Solution Explanation
Let’s explain the code line by line with examples.

```cpp
class Solution
{
public:
    // Priority queues to represent maxHeap and minHeap
    priority_queue<int> maxHeap; 
    priority_queue<int, vector<int>, greater<int>> minHeap;
```

- **Explanation**:
  - We declare two heaps:
    - `maxHeap`: A max-heap to store the smaller half of the numbers. The largest element in this half will be at the top.
    - `minHeap`: A min-heap to store the larger half of the numbers. The smallest element in this half will be at the top.

- **Example**:
  After adding `[2, 3, 4]`:
  - `maxHeap`: [2] (top = 2).
  - `minHeap`: [3, 4] (top = 3).



```cpp
void insertHeap(int &x)
{
    if(maxHeap.size() == 0 || x < maxHeap.top()) 
        maxHeap.push(x); // Add the number to maxHeap if it's smaller than or equal to the max of maxHeap
    else 
        minHeap.push(x); // Otherwise, add it to minHeap
```

- **Explanation**:
  - If `maxHeap` is empty, the first number goes into it.
  - Otherwise, compare `x` with the top of `maxHeap`:
    - If `x` is smaller than or equal to the top of `maxHeap`, it belongs to the smaller half, so add it to `maxHeap`.
    - Otherwise, add it to `minHeap`.

- **Example**:
  Adding `3` to empty heaps:
  - `maxHeap = [3]`, `minHeap = []`.

  Adding `5` when `maxHeap = [3]`:
  - `maxHeap.top() = 3`. Since `5 > 3`, add `5` to `minHeap`.
  - Result: `maxHeap = [3]`, `minHeap = [5]`.



```cpp
balanceHeaps();
```

- **Explanation**:
  - After inserting a number, the heaps may become unbalanced.
  - Call the `balanceHeaps` function to ensure the difference in sizes between the two heaps is at most 1.



```cpp
void balanceHeaps()
{
    if(maxHeap.size() > minHeap.size() + 1)
    {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
    else if(minHeap.size() > maxHeap.size())
    {
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }
}
```

- **Explanation**:
  - If `maxHeap` has more than one extra element, move the top of `maxHeap` to `minHeap`.
  - If `minHeap` has more elements, move the top of `minHeap` to `maxHeap`.

- **Example**:
  Adding `7` to heaps:
  - Before balancing: `maxHeap = [3, 2]`, `minHeap = [5, 7]`.
  - Balance by moving `5` to `maxHeap`.
  - After balancing: `maxHeap = [5, 3, 2]`, `minHeap = [7]`.



```cpp
double getMedian()
{
    if(maxHeap.size() == minHeap.size())
        return (minHeap.top() + maxHeap.top()) / 2.0; 
    else
        return maxHeap.top();
}
```

- **Explanation**:
  - If both heaps are of equal size, the median is the average of their tops.
  - If they are unequal, the median is the top of `maxHeap` because it contains the middle element when the total number of elements is odd.

- **Example**:
  Heaps after adding `[2, 3, 4, 5]`:
  - `maxHeap = [3, 2]`, `minHeap = [4, 5]`.
  - Median = `(3 + 4) / 2 = 3.5`.

### **Step-by-Step Example**

Let’s walk through an example input: `[5, 15, 1, 3]`.

1. **Add `5`**:
   - `maxHeap = [5]`, `minHeap = []`.
   - Median = `5`.

2. **Add `15`**:
   - Add `15` to `minHeap`.
   - Heaps: `maxHeap = [5]`, `minHeap = [15]`.
   - Median = `(5 + 15) / 2 = 10`.

3. **Add `1`**:
   - Add `1` to `maxHeap`.
   - Balance the heaps: Move `5` to `minHeap`.
   - Heaps: `maxHeap = [3, 1]`, `minHeap = [5, 15]`.
   - Median = `5`.

4. **Add `3`**:
   - Add `3` to `maxHeap`.
   - Balance the heaps: Move `5` to `maxHeap`.
   - Heaps: `maxHeap = [5, 3, 1]`, `minHeap = [15]`.
   - Median = `(3 + 5) / 2 = 4`.



### **Time and Space Complexity**

#### **Time Complexity**
1. **Insertion**:
   - Pushing into a heap takes \(O(\log n)\).
   - Balancing the heaps involves \(O(\log n)\).
   - Total per insertion: \(O(\log n)\).

2. **Median Calculation**:
   - Fetching the top of the heaps takes \(O(1)\).
   - Total: \(O(1)\).

For \(n\) numbers:
- **Total Time**: \(O(n \log n)\).



#### **Space Complexity**
- Two heaps store \(O(n)\) elements combined.
- **Total Space**: \(O(n)\).



### **Additional Recommendations**
1. **Understand the Two-Heap Approach**: Visualize the heaps to understand how the numbers are distributed and balanced.
2. **Edge Cases**: Test inputs like:
   - A single number.
   - A stream of equal numbers.
3. **Practice Similar Problems**: Try variations like "Sliding Window Median" to reinforce your knowledge.

This line-by-line explanation should make the logic and flow of the code clear. Happy learning! 😊



### **Step 5: Additional Recommendations**
1. **Understand the Two-Heap Approach**: Practice using max-heap and min-heap together for solving median problems. This approach is efficient and widely applicable.
2. **Handle Edge Cases**: Test scenarios like:
   - A single element.
   - A stream with only increasing or decreasing numbers.
3. **Practice Similar Problems**: Try problems like "Sliding Window Median" to enhance understanding of heap-based solutions.

By following this explanation, you can solve and debug similar problems effectively. Happy coding! 😊
