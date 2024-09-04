<h1 align='center'></h1>

## Problem Statement

**Problem URL :** [Sum of Two Numbers Represented as Arrays](https://www.geeksforgeeks.org/problems/sum-of-two-numbers-represented-as-arrays3110/1)

![image](https://github.com/user-attachments/assets/ef8977d7-9907-409f-9971-0a967a17d5ce)

## Problem Explanation
In this problem, you are given two numbers, each represented as an array of digits. Your task is to find the sum of these two numbers and return the result as an array of digits. The arrays `arr1` and `arr2` represent two non-negative integers where each digit of the numbers is stored as an element in the arrays. The problem can be outlined as follows:

1. **Input**:
   - Two arrays `arr1` and `arr2`, where each array represents a non-negative integer. For example, if `arr1 = [1, 2, 3]`, it represents the number 123.
  
2. **Output**:
   - An array that represents the sum of the two numbers. For example, if `arr1 = [1, 2, 3]` and `arr2 = [4, 5, 6]`, the output should be `[5, 7, 9]` because 123 + 456 = 579.

## Problem Solution
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> reversed(vector<int> arr){
        int i = 0;
        int j = arr.size() - 1;
        
        while(i < j){
            swap(arr[i++], arr[j--]);
        }
        
        return arr;
    }
    vector<int> findSum(vector<int> &arr1, vector<int> &arr2) {
        int i = arr1.size() - 1;
        int j = arr2.size() - 1;
        
        int carry = 0;
        vector<int> result;
        
        while(i >= 0 || j >= 0 || carry != 0){
            int sum = carry;
            
            if(i >= 0) sum += arr1[i--];
            if(j >= 0) sum += arr2[j--];
            carry = sum / 10;
            result.push_back(sum % 10);
        }
        
        return reversed(result);
    }
};

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {

        vector<int> arr1, arr2;
        string input1;
        getline(cin, input1);
        stringstream ss(input1);
        int number1;
        while (ss >> number1) {
            arr1.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream sss(input2);
        int number2;
        while (sss >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        // Function calling
        vector<int> v;
        v = ob.findSum(arr1, arr2);

        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";

        cout << endl;
    }

    return 0;
}
```

## Problem Solution Explanation

Now, let’s break down the provided solution step by step.

```cpp
class Solution {
  public:
  
    vector<int> reversed(vector<int> arr){
        int i = 0;
        int j = arr.size() - 1;
        
        while(i < j){
            swap(arr[i++], arr[j--]);
        }
        
        return arr;
    }
```

1. **Line 1-12**: The `reversed` function
   - This helper function reverses the elements of the input array `arr`. 
   - The `i` pointer starts at the beginning of the array, and the `j` pointer starts at the end. They move towards each other, swapping elements until they meet in the middle.
   - The function returns the reversed array.

**Example:**
- Input: `arr = [1, 2, 3]`
- Output: `reversed(arr) = [3, 2, 1]`

```cpp
    vector<int> findSum(vector<int> &arr1, vector<int> &arr2) {
        int i = arr1.size() - 1;
        int j = arr2.size() - 1;
        
        int carry = 0;
        vector<int> result;
```

2. **Line 14-20**: Initial Setup
   - The `findSum` function starts by initializing pointers `i` and `j` to the last indices of `arr1` and `arr2`, respectively. This is because we add numbers starting from the least significant digit (rightmost digit).
   - The `carry` variable is initialized to `0`. This will store the carry value during the addition process.
   - An empty vector `result` is initialized to store the digits of the sum as they are calculated.

```cpp
        while(i >= 0 || j >= 0 || carry != 0){
            int sum = carry;
            
            if(i >= 0) sum += arr1[i--];
            if(j >= 0) sum += arr2[j--];
            carry = sum / 10;
            result.push_back(sum % 10);
        }
        
        return reversed(result);
    }
```

3. **Line 21-30**: Addition Loop
   - The loop continues as long as there are digits left in `arr1` or `arr2` to add, or there is a carry left to process.
   - Inside the loop, the `sum` is initialized with the value of `carry`.
   - If `i >= 0`, the current digit from `arr1` is added to `sum`, and then `i` is decremented.
   - If `j >= 0`, the current digit from `arr2` is added to `sum`, and then `j` is decremented.
   - The `carry` is updated to `sum / 10`, which represents any carry-over to the next higher place value.
   - The current digit of the result is `sum % 10`, which is added to the `result` vector.

**Example of Addition:**
- Let's assume `arr1 = [9, 4, 5]` and `arr2 = [2, 8, 5]`.
- Starting from the last digit: 
  - `5 + 5 = 10`, so `carry = 1` and `result = [0]`.
  - `4 + 8 + carry = 13`, so `carry = 1` and `result = [0, 3]`.
  - `9 + 2 + carry = 12`, so `carry = 1` and `result = [0, 3, 2]`.
- The loop ends, but since `carry = 1`, it is added to the result as `result = [0, 3, 2, 1]`.

4. **Line 31**: Return the Reversed Result
   - The `result` vector now contains the sum in reverse order, so it is reversed before being returned.

**Example:**
- Final result in reverse order: `[0, 3, 2, 1]`
- Reversed: `[1, 2, 3, 0]`

```cpp
// Driver Code
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {

        vector<int> arr1, arr2;
        string input1;
        getline(cin, input1);
        stringstream ss(input1);
        int number1;
        while (ss >> number1) {
            arr1.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream sss(input2);
        int number2;
        while (sss >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        // Function calling
        vector<int> v;
        v = ob.findSum(arr1, arr2);

        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";

        cout << endl;
    }

    return 0;
}
```

5. **Driver Code**:
   - The driver code takes input for multiple test cases. For each test case:
     - It reads two lines of input, converts them into integer arrays `arr1` and `arr2`, and calls `findSum`.
     - The result is printed as a space-separated list of digits.

**Example Input/Output**:
- **Input**:
  ```
  1
  9 4 5
  2 8 5
  ```
- **Output**:
  ```
  1 2 3 0
  ```

### Conclusion

The provided solution efficiently computes the sum of two large numbers represented as arrays of digits by iterating over the arrays from right to left, managing the carry, and constructing the result. This approach ensures correctness even when the arrays are of different lengths or when there's a carry that extends the result's length.
