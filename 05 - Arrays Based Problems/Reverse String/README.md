<h1 align='center'>Reverse - String</h1>

## Problem Statement

![image](https://github.com/user-attachments/assets/d8ecacb7-9954-46de-ae0e-e2bb3b0c721e)

## Problem Solution
```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        
        int left = 0;
        int right = n-1;

        while(left <= right){
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};
```

## Problem Solution Explanation
Let's break down the C++ code for reversing a string using a vector of characters, line by line:

### Class Definition

1. **`class Solution {`**  
   This line begins the definition of the `Solution` class. In C++, a class is a blueprint for creating objects, and it can contain member functions and variables.

2. **`public:`**  
   The `public` access specifier means that the members (functions and variables) that follow can be accessed from outside the class.

### Function Definition

3. **`void reverseString(vector<char>& s) {`**  
   This line declares a member function `reverseString` of the `Solution` class. The function takes a single parameter, `s`, which is a reference to a vector of characters (`vector<char>&`). The function returns `void`, meaning it does not return any value.

### Function Body

4. **`int n = s.size();`**  
   This line initializes an integer `n` with the size of the vector `s`. `s.size()` returns the number of elements in the vector `s`.

5. **`int left = 0;`**  
   This line initializes an integer `left` to 0. This variable will be used as the starting index for the swapping process.

6. **`int right = n-1;`**  
   This line initializes an integer `right` to `n-1`. This variable will be used as the ending index for the swapping process. Initially, `right` points to the last element of the vector.

### Swapping Elements

7. **`while(left <= right) {`**  
   This line begins a `while` loop that will continue to execute as long as `left` is less than or equal to `right`. The loop is responsible for swapping elements from the start and end of the vector and moving towards the center.

8. **`swap(s[left], s[right]);`**  
   This line swaps the elements at indices `left` and `right` in the vector `s`. The `swap` function is a standard library function that exchanges the values of its two arguments.

9. **`left++;`**  
   This line increments the `left` index by 1, moving it towards the center of the vector.

10. **`right--;`**  
    This line decrements the `right` index by 1, moving it towards the center of the vector.

### End of Function and Class

11. **`}`**  
    This line marks the end of the `while` loop.

12. **`}`**  
    This line marks the end of the `reverseString` function.

13. **`}`**  
    This line marks the end of the `Solution` class definition.

### Summary

- The `reverseString` function reverses the order of elements in the vector `s` in place.
- It uses two pointers, `left` and `right`, which start at the beginning and end of the vector, respectively.
- The function swaps the elements pointed to by `left` and `right`, then moves the pointers towards the center until they meet or cross.
- This approach ensures that all elements are swapped to achieve the reversed order.
