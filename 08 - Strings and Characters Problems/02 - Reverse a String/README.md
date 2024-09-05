<h1 align='center'>Reverse - A - String</h1>

## Problem Statement

**Problem URL :** [Reverse a String](https://www.geeksforgeeks.org/problems/reverse-a-string/1)

![image](https://github.com/user-attachments/assets/cb094eca-9366-41ab-87bd-6c31d7a570b8)

## Problem Solution
```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    string reverseWord(string str)
    {
       int i = 0;
       int j = str.size() -1;
       
       while(i <= j){
           swap(str[i], str[j]);
           i++;
           j--;
       }
       
       return str;
    }
};
int main() {
	int t;
	cin>>t;
	while(t--)
	{
    	string s;
    	cin >> s;
    	Solution ob;
    	cout << ob.reverseWord(s) << endl;
	}
	return 0;
}
```

## Problem Solution Explanation
Let's go through the code step by step.

### Header Files
```cpp
#include<bits/stdc++.h>
```
- This includes all the standard C++ header files in one line. It's often used in competitive programming for convenience but is generally not recommended for large projects. This includes headers like `<iostream>`, `<vector>`, `<algorithm>`, and many others.

### Using Namespace
```cpp
using namespace std;
```
- This line allows us to use all the standard C++ library components without having to prefix them with `std::`. For example, we can write `cout` instead of `std::cout`.

### Class Definition
```cpp
class Solution
{
```
- A class named `Solution` is defined. In competitive programming, solutions are often encapsulated in classes like this for structure.

### Public Access Specifier
```cpp
public:
```
- `public` makes the following methods accessible from outside the class.

### Function to Reverse the Word
```cpp
string reverseWord(string str)
```
- This function takes a `string` parameter `str` and returns the reversed version of it.
  
### Variables Initialization
```cpp
int i = 0;
int j = str.size() - 1;
```
- `i` is initialized to `0`, representing the starting index of the string.
- `j` is initialized to `str.size() - 1`, which is the index of the last character in the string.

### Reversing the String using Two Pointers
```cpp
while(i <= j)
{
    swap(str[i], str[j]);
    i++;
    j--;
}
```
- This `while` loop runs as long as `i` is less than or equal to `j`.
  - `swap(str[i], str[j])` swaps the characters at indices `i` and `j` in the string.
  - `i++` increments the left pointer, moving it towards the center.
  - `j--` decrements the right pointer, moving it towards the center.
  
  This technique is known as the **two-pointer technique** and efficiently reverses the string in place.

### Return Reversed String
```cpp
return str;
```
- After the loop completes, the modified (reversed) string is returned.

### Main Function
```cpp
int main() {
    int t;
    cin>>t;
```
- The `main()` function begins. 
- `t` is declared to store the number of test cases.
- `cin >> t;` takes the input for the number of test cases.

### Test Case Loop
```cpp
while(t--)
{
    string s;
    cin >> s;
    Solution ob;
    cout << ob.reverseWord(s) << endl;
}
```
- This `while` loop runs `t` times (once for each test case). 
- Inside the loop:
  - A string `s` is declared, and the input string is stored in `s` using `cin >> s;`.
  - An object `ob` of the `Solution` class is created.
  - `ob.reverseWord(s)` is called to reverse the string `s`, and the result is printed using `cout`.

### Return Statement
```cpp
return 0;
```
- The `main()` function returns `0`, indicating that the program executed successfully.

### Example

For an input like:
```
2
hello
world
```

The output will be:
```
olleh
dlrow
```

- The program reverses each input string and prints the reversed version.
