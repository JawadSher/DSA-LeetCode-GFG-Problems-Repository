<h1 align='center'>Subsequences - of - String</h1>

## Problem Statement

**Problem URL :** [None]()

The goal of the problem is to generate all possible non-empty subsequences of a given string. A subsequence is a sequence derived from another sequence where some elements may be deleted without changing the order of the remaining elements.

For example, given the string "ABCD", the possible subsequences are:
- A
- B
- C
- D
- AB
- AC
- AD
- BC
- BD
- CD
- ABC
- ABD
- ACD
- BCD
- ABCD

### Approach

This code uses a recursive approach to generate all possible subsequences of the input string. Here’s how it works step by step:

1. **Base Case**: When the index exceeds the length of the input string, we check if the `output` string is not empty. If it is not, we add it to the `answer` vector.
  
2. **Recursive Case**:
   - **Exclusion**: First, the function makes a recursive call without including the current character at the `index`. This allows us to explore subsequences that do not contain that character.
   - **Inclusion**: Next, the function includes the current character in the `output` string and makes another recursive call to explore subsequences that include this character.

3. **Sorting**: After generating all subsequences, the code sorts the `answer` vector to ensure a consistent order.

4. **Output**: Finally, it prints all the generated subsequences.

## Pseudocode
Here’s the pseudocode for generating all non-empty subsequences of a string, along with a detailed explanation to help beginners understand the process.

```plaintext
function generateSubsequences(input_str):
    answer = empty list       // To store all subsequences
    output = empty string      // To build the current subsequence
    index = 0                 // Start at the first character

    call solve(input_str, output, answer, index)

    sort answer                // Sort the subsequences
    print "Sub-Sequences of given String: "
    for each subsequence in answer:
        print subsequence

function solve(input_str, output, answer, index):
    if index >= length of input_str:
        if output is not empty:
            add output to answer
        return

    // Exclude the character at index
    call solve(input_str, output, answer, index + 1)

    // Include the character at index
    character = input_str[index]
    output = output + character  // Append the character to output
    call solve(input_str, output, answer, index + 1)
```

### Explanation of Pseudocode

1. **Function `generateSubsequences(input_str)`**:
   - Initializes an empty list `answer` to store the resulting subsequences.
   - Initializes an empty string `output` to build the current subsequence.
   - Sets the `index` to `0`, indicating the start of the string.
   - Calls the `solve` function to start the recursive process.
   - Sorts the `answer` list to ensure a consistent order.
   - Prints all the subsequences stored in `answer`.

2. **Function `solve(input_str, output, answer, index)`**:
   - Checks if the current `index` is greater than or equal to the length of `input_str`. If so, it means we've processed all characters.
     - If `output` is not empty, adds it to `answer`.
     - Returns to the previous call.
   - **Exclusion Step**: Calls `solve` without including the character at the current `index`, effectively exploring the subsequences that do not contain that character.
   - **Inclusion Step**: 
     - Retrieves the character at the current `index`.
     - Appends this character to `output`.
     - Calls `solve` again, this time including the character, exploring subsequences that do include it.

### Summary

This pseudocode breaks down the recursive logic into clear steps:
- The main function initializes the process.
- The recursive function builds subsequences by exploring both possibilities: including and excluding each character.
- The structure of the pseudocode allows beginners to grasp the recursive approach and understand how subsequences are generated systematically.

### Example Walkthrough

For the string "AB":
1. Start with `index = 0` (character 'A'):
   - Exclude 'A': call `solve` with `index = 1`.
     - For `index = 1` (character 'B'):
       - Exclude 'B': call `solve` with `index = 2` (add empty string to `answer`).
       - Include 'B': output becomes "B", add to `answer`.
   - Include 'A': output becomes "A", call `solve` with `index = 1`.
     - Exclude 'B': add "A" to `answer`.
     - Include 'B': output becomes "AB", add to `answer`.

Final `answer` would contain: `["A", "B", "AB"]`.

This systematic approach and the pseudocode should make it easier for beginners to follow along and understand how subsequences are generated.

## Problem Solution
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void solve(string input_str, string output, vector<string> &answer, int index){
  if(index >= input_str.length()){
    if(output.length() > 0){
      answer.push_back(output);
    }

    return;
  }

  solve(input_str, output, answer, index+1);
  
  int character = input_str[index];
  output.push_back(character);

  solve(input_str, output, answer, index+1);
}

void subsequence(string &input_str){
  string output;
  vector<string> answer;
  int index = 0;

  solve(input_str, output, answer, index);

  sort(answer.begin(), answer.end());

  cout<<"Sub-Sequences of given String : ";
  for(int i = 0; i < answer.size(); i++){
    cout<<answer[i]<< " ";
  }cout<<endl;
}

int main() {
  string input_str = "ABCD";
  
  subsequence(input_str);

  return 0;
}
```

## Problem Solution Explanation
Here’s the code with a line-by-line explanation:

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
```
- Includes necessary headers for input/output, algorithms, vectors, and strings.

```cpp
void solve(string input_str, string output, vector<string> &answer, int index) {
```
- Defines a recursive function `solve` that takes:
  - `input_str`: The original string from which we derive subsequences.
  - `output`: The current subsequence being formed.
  - `answer`: A reference to the vector that stores all valid subsequences.
  - `index`: The current position in the string being considered.

```cpp
    if(index >= input_str.length()) {
```
- Checks if the `index` has exceeded the length of `input_str`. If so, we hit the base case.

```cpp
        if(output.length() > 0) {
            answer.push_back(output);
        }
```
- If `output` is not empty, it adds the formed subsequence to the `answer` vector.

```cpp
        return;
```
- Ends the current recursive call, returning control to the previous call.

```cpp
    solve(input_str, output, answer, index + 1);
```
- Makes a recursive call to `solve`, excluding the character at `input_str[index]`. It moves to the next index.

```cpp
    int character = input_str[index];
    output.push_back(character);
```
- Retrieves the current character from `input_str` and adds it to the `output` string to include it in the next subsequence.

```cpp
    solve(input_str, output, answer, index + 1);
```
- Makes another recursive call to `solve`, this time including the character at `input_str[index]`.

```cpp
}

void subsequence(string &input_str) {
```
- Defines the `subsequence` function that initiates the process of generating subsequences.

```cpp
    string output;
    vector<string> answer;
    int index = 0;
```
- Initializes an empty string `output` for the current subsequence, a vector `answer` to store all subsequences, and sets the starting index to `0`.

```cpp
    solve(input_str, output, answer, index);
```
- Calls the `solve` function to start generating subsequences from the original string.

```cpp
    sort(answer.begin(), answer.end());
```
- Sorts the `answer` vector for a consistent order of output.

```cpp
    cout << "Sub-Sequences of given String : ";
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
}
```
- Prints all the subsequences stored in the `answer` vector.

```cpp
int main() {
    string input_str = "ABCD";
    subsequence(input_str);
    return 0;
}
```
- The `main` function initializes the input string and calls the `subsequence` function to generate and display the subsequences.

### Time and Space Complexity

- **Time Complexity**: \(O(2^n)\), where \(n\) is the length of the input string. This is because each character has two possibilities: to be included in a subsequence or not. Therefore, the total number of subsequences is \(2^n\).

- **Space Complexity**: 
  - The space required for the `answer` vector can go up to \(O(2^n)\) in the worst case, storing all possible subsequences.
  - The recursive call stack can go as deep as \(O(n)\), where \(n\) is the length of the string.

### Summary

This code effectively generates all non-empty subsequences of a string using recursion. The approach systematically explores the inclusion and exclusion of each character, resulting in all possible combinations. The complexity analysis shows that this problem grows exponentially with the input size, which is typical for problems involving combinations or subsets.
