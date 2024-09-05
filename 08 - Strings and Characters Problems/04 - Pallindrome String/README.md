<h1 align='center'>Pallindrome - String</h1>

## Problem Statement

**Problem URL :** [Pallindrome String](https://www.geeksforgeeks.org/problems/palindrome-string0817/1)

![image](https://github.com/user-attachments/assets/20156b1a-751b-42a7-980f-333bced9804a)

## Problem Solution
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	
	
	int isPalindrome(string S)
	{
	    int i = 0;
	    int j = S.length() - 1;
	    
	    if(S.length() <= 0){
	        return 1;
	    }
	    
	    while(i < j){
	        if(S[i] != S[j]){
	            return 0;
	        }
	        i++;
	        j--;
	    }
	    
	    return 1;
	}

};

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
```

## Problem Solution Explanation
Let's go through the given code step by step, explaining each line and block in detail. The goal of this program is to determine whether a given string is a palindrome or not.

```cpp
#include <bits/stdc++.h>
using namespace std;
```
- **`#include <bits/stdc++.h>`**: This line includes all the standard libraries of C++. It’s a common practice in competitive programming to include this to avoid including individual libraries separately.
- **`using namespace std;`**: This allows the use of standard functions and objects (like `cin`, `cout`, `vector`, etc.) without prefixing them with `std::`.

---

```cpp
class Solution{
public:
	int isPalindrome(string S) {
```
- **`class Solution`**: This defines a class called `Solution`. Inside this class, there is a public function `isPalindrome` that checks whether the given string `S` is a palindrome.
- **`int isPalindrome(string S)`**: This is the function signature that takes a string `S` as input and returns an integer (1 for a palindrome, 0 for not a palindrome).

---

```cpp
int i = 0;
int j = S.length() - 1;
```
- **`int i = 0`**: This initializes an integer `i` to `0`. This variable `i` will represent the starting index of the string.
- **`int j = S.length() - 1`**: This initializes an integer `j` to the last index of the string `S`. The `S.length() - 1` gives the index of the last character in the string. This variable `j` will represent the ending index of the string.

---

```cpp
if(S.length() <= 0){
    return 1;
}
```
- **`if(S.length() <= 0)`**: This checks if the string `S` is empty (i.e., has a length of 0). An empty string is technically considered a palindrome.
- **`return 1`**: If the string is empty, the function returns `1`, indicating that it is a palindrome.

---

```cpp
while(i < j){
    if(S[i] != S[j]){
        return 0;
    }
    i++;
    j--;
}
```
- **`while(i < j)`**: This loop runs as long as the start pointer `i` is less than the end pointer `j`. This ensures that the function compares characters from the start and the end of the string until the middle is reached.
- **`if(S[i] != S[j])`**: Inside the loop, this checks if the characters at positions `i` and `j` are different. If they are not equal, the string is not a palindrome.
    - **`return 0;`**: If any mismatch is found, the function immediately returns `0`, indicating that the string is not a palindrome.
- **`i++`**: If the characters at positions `i` and `j` are the same, increment `i` to move towards the middle from the start.
- **`j--`**: Similarly, decrement `j` to move towards the middle from the end.

---

```cpp
return 1;
```
- After the loop ends (i.e., all characters were equal while comparing), the function returns `1`, indicating that the string is a palindrome.

---

### `main()` Function

```cpp
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
```
- **`ios_base::sync_with_stdio(0);`**: This disables the synchronization between C++'s `cin/cout` and C’s `scanf/printf`, which makes input/output operations faster.
- **`cin.tie(NULL);`**: This unties `cin` from `cout`, meaning input won’t wait for output to be flushed. This also improves the speed of input/output.
- **`cout.tie(NULL);`**: It is used to untie the output stream `cout`.

---

```cpp
int t;
cin >> t;
```
- **`int t;`**: This declares an integer `t` which will store the number of test cases.
- **`cin >> t;`**: This reads the number of test cases from input.

---

```cpp
while(t--) {
    string s;
    cin >> s;

    Solution ob;
    cout << ob.isPalindrome(s) << "\n";
}
```
- **`while(t--)`**: This loop runs `t` times, where `t` is the number of test cases. After each iteration, `t` is decremented by 1.
- **`string s;`**: This declares a string `s` which will store the input string for the current test case.
- **`cin >> s;`**: This reads the string `s` from the input.
- **`Solution ob;`**: This creates an object `ob` of the class `Solution`.
- **`cout << ob.isPalindrome(s) << "\n";`**: This calls the `isPalindrome()` function on the string `s` and prints the result. If the function returns `1`, it prints `1` (indicating the string is a palindrome), otherwise it prints `0`.

---

### Example Walkthrough:

#### Test Case 1:
**Input:**
```
2
racecar
hello
```

**Execution:**
1. **First Test Case (`racecar`):**
   - The function compares the characters at positions `0` and `6`, `1` and `5`, `2` and `4`, and `3` and `3`. Since all characters match, the string is a palindrome. The output is `1`.
   
2. **Second Test Case (`hello`):**
   - The function compares the characters at positions `0` and `4` (h != o), so it returns `0` (not a palindrome). The output is `0`.

**Output:**
```
1
0
```

This is how the program works for multiple test cases, checking if each input string is a palindrome or not.
