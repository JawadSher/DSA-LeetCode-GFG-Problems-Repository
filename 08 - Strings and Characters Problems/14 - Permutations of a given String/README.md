
<h1 align='center'>Permutations - of a - Given - String</h1>

## Problem Statement

**Problem URL :** [Permutations of a given String](https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1)

![image](https://github.com/user-attachments/assets/e45ad560-682a-4d89-8c1f-41952a3b6fe7)
![image](https://github.com/user-attachments/assets/61cc5c46-c42f-47bc-a6e8-c0d58fcad1a5)

## Problem Explanation
Given a string `S`, the task is to find all permutations of the string in lexicographically sorted order without any duplicates.

### Example:
**Input:**
```
S = "ABC"
```
**Output:**
```
ABC ACB BAC BCA CAB CBA
```

### Approach:

The idea is to generate all possible permutations of the given string `S` and ensure that the permutations are unique (if there are repeated characters in `S`). Finally, the permutations are returned in lexicographical order.

## Problem Solution
```cpp
#include<bits/stdc++.h>
using namespace std;
class Solution
{
    private:
        void permute(string& S, int l, int r, set<string>& ans){
            
            if(l == r){
                ans.insert(S);
            }else{
                
            
                for(int i = l; i <= r; i++){
                    
                    swap(S[l], S[i]);
                    
                    permute(S, l+1, r, ans);
                    
                    swap(S[l], S[i]);
                }
            }
            
        }
	public:
		vector<string>find_permutation(string S)
		{
		   int n = S.length();
		   set<string> ans;
		   int l = 0;
		   int r = n-1;
		   permute(S, l, r, ans);
		   vector<string> result(ans.begin(), ans.end());
		   return result;
		}
};

int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
```

## Problem Solution Explanation

```cpp
#include<bits/stdc++.h>
using namespace std;
```

- **Header Files:** We include `bits/stdc++.h` which includes all standard C++ libraries such as vectors, sets, etc.

```cpp
class Solution {
```

- **Class Definition:** We define a class `Solution` that encapsulates the solution methods.

```cpp
    private:
        void permute(string& S, int l, int r, set<string>& ans){
```

- **Private Helper Function `permute`:** This recursive function generates permutations of the string `S` by swapping characters at different positions.
  - Parameters:
    - `S`: The string whose permutations we are finding.
    - `l`: The starting index of the current permutation window.
    - `r`: The ending index of the string.
    - `ans`: A `set<string>` to store unique permutations.

```cpp
            if(l == r){
                ans.insert(S);
            }else{
```

- **Base Case (Line 1-3):** If `l == r`, it means we've generated a new permutation. So, we insert the current permutation (`S`) into the set `ans`.
- **Recursive Case (Line 4):** If `l != r`, we need to explore further permutations by swapping characters.

```cpp
                for(int i = l; i <= r; i++){
```

- **Loop (Line 5):** This loop iterates over the range from `l` to `r`. For every position `i` in this range, we swap the character at index `l` with the character at index `i`.

```cpp
                    swap(S[l], S[i]);
```

- **Swapping (Line 6):** We swap the character at index `l` with the character at index `i` to generate a new arrangement for the current recursive call.

```cpp
                    permute(S, l+1, r, ans);
```

- **Recursive Call (Line 7):** After swapping, we recursively call `permute` with the next index (`l+1`), which explores the next position for further swapping.

```cpp
                    swap(S[l], S[i]);
```

- **Backtrack (Line 8):** After returning from the recursive call, we swap the characters back to their original positions to maintain the original string configuration (backtracking). This ensures that each recursive branch starts with the correct initial configuration of the string.

```cpp
                }
```

- **End of Loop (Line 9):** This closes the loop, ensuring all possible swaps for the current recursive level have been explored.

```cpp
        }
```

- **End of Function (Line 10):** This closes the `permute` function.

```cpp
    public:
        vector<string> find_permutation(string S)
        {
           int n = S.length();
           set<string> ans;
           int l = 0;
           int r = n-1;
           permute(S, l, r, ans);
```

- **Public Function `find_permutation`:** This is the main function that the user calls to find all permutations.
  - We initialize `n` as the length of string `S`.
  - We create a `set<string> ans` to store unique permutations.
  - We call the helper function `permute` with the initial parameters `S`, `l = 0`, `r = n-1`, and `ans`.

```cpp
           vector<string> result(ans.begin(), ans.end());
           return result;
        }
```

- **Collecting the Results:**
  - After all the permutations are found and stored in the `set ans`, we transfer the unique permutations into a vector `result` (since the `set` is sorted by default).
  - We return the `result` vector containing the permutations.

```cpp
};
```

- **End of Class:** This closes the `Solution` class definition.

```cpp
int main(){
    int t;
    cin >> t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.find_permutation(S);
        sort(ans.begin(), ans.end());
        for(auto i: ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
```

- **Main Function:**
  - **Input:** We read the number of test cases `t` from the user.
  - For each test case:
    - We input the string `S`.
    - We create an object `ob` of the `Solution` class.
    - We call `find_permutation(S)` to get all the permutations of the string.
    - The permutations are sorted and printed one by one.

---

### Example Walkthrough:

#### Test Case:
```
S = "ABC"
```

- **Step 1:** Initial call to `permute(S, 0, 2)`:
  - Swap characters at index 0 with index 0 (`ABC` remains the same).
  - Recur with `permute(S, 1, 2)`.
  
- **Step 2:** In the recursive call, swap characters at index 1 with index 1 (`ABC`).
  - Recur with `permute(S, 2, 2)` (base case reached: add `"ABC"` to `ans`).
  
- **Step 3:** Backtrack and swap characters at index 1 with index 2 (`ACB`).
  - Recur with `permute(S, 2, 2)` (add `"ACB"` to `ans`).
  
- **Step 4:** Backtrack again to the top level and swap characters at index 0 with index 1 (`BAC`).
  - Follow the same recursive steps to add `"BAC"` and `"BCA"` to `ans`.
  
- **Step 5:** Continue similarly for other permutations, resulting in:
```
ABC, ACB, BAC, BCA, CAB, CBA
```

### Approach Explanation:

- **Backtracking:** This is a classic backtracking problem where we swap characters to generate all possible permutations of the string. The idea is to systematically explore all possible permutations by swapping each character and recursively building the permutations.

- **Set for Unique Results:** The use of a `set<string>` ensures that only unique permutations are stored, automatically avoiding duplicates if the input string contains repeated characters.

