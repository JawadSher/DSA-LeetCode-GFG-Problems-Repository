<h1 align='center'>Letter - Combination - Of a - Phone - Number</h1>

## Problem Statement

**Problem URL :** [Letter Combination of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)

![image](https://github.com/user-attachments/assets/0dd0a214-6b93-4b9a-b3b4-c2d3518704fc)
![image](https://github.com/user-attachments/assets/1b1c7d67-1657-4068-8acf-1956393591b7)

Given a string of digits from `2-9` on a phone's dial pad, return **all possible letter combinations** that these numbers could represent. The mapping of digits to letters is:

- 2 -> "abc"
- 3 -> "def"
- 4 -> "ghi"
- 5 -> "jkl"
- 6 -> "mno"
- 7 -> "pqrs"
- 8 -> "tuv"
- 9 -> "wxyz"

The task is to generate all possible letter combinations that the input digits could form. If the input is an empty string, return an empty list.

#### Example:

- **Input**: `digits = "23"`
- **Output**: `["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]`


#### Approach : Recursive Backtracking (Depth-First Search)
This problem can be solved efficiently using **recursion and backtracking**. Here’s the idea:
1. **Backtracking**: We will try every possible combination by "building" the string letter by letter, starting with the first digit and exploring all characters mapped to that digit.
2. **Recursion**: We make recursive calls to process each digit, moving from left to right. For each character corresponding to a digit, we append it to a partial combination and move to the next digit.

## Problem Solution
```cpp
class Solution {
private:
    void solve(string digit, string output, int index, vector<string>&answer, string mapping[]){
        // base case
        if(index >= digit.length()){
            answer.push_back(output);

            return;
        }   

        int number = digit[index] - '0';
        string value = mapping[number];

        for(int i = 0; i < value.length(); i++){
            output.push_back(value[i]);
            solve(digit, output, index+1, answer, mapping);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> answer;

        if(digits.length() == 0) return answer;
        string output;
        int index = 0;

        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        solve(digits, output, index, answer, mapping);

        return answer;
    }
};
```

## Problem Solution Explanation
Let’s break down the code in a more structured and detailed way, focusing on each part of the implementation and providing examples to clarify how it works.

### Problem: Letter Combinations of a Phone Number

**Given Input**: A string of digits (e.g., `"23"`).

**Expected Output**: All possible letter combinations corresponding to those digits (e.g., `["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]`).

#### Class and Method Definition

```cpp
class Solution {
```
- This declares a class named `Solution` which will contain the methods to solve the problem.

#### Private Recursive Function

```cpp
private:
    void solve(string digits, string current, int index, vector<string>& result, string mapping[]) {
```
- **Function Purpose**: This private function `solve` is responsible for generating all combinations recursively.
- **Parameters**:
  - `string digits`: The input digit string (e.g., `"23"`).
  - `string current`: The current combination of letters being formed.
  - `int index`: The current index in the digit string being processed.
  - `vector<string>& result`: The output vector that will store all the valid combinations.
  - `string mapping[]`: An array that maps each digit to its corresponding letters.

#### Base Case

```cpp
if (index == digits.length()) {
    result.push_back(current);  // Add the complete combination to the result
    return;
}
```
- **Base Case**: This checks if we have processed all digits. If `index` equals the length of `digits`, it means we have a complete letter combination stored in `current`.
- **Example**: If `current` is `"ad"` when `index` equals 2 (length of "23"), it is added to `result`.

#### Get Current Digit's Letters

```cpp
int number = digits[index] - '0';  // Convert character to integer (e.g., '2' -> 2)
string value = mapping[number];    // Get the corresponding letters for the digit
```
- **Convert Character to Integer**: This line converts the character at `digits[index]` to its corresponding integer. For example, if `digits[index]` is `'2'`, `number` becomes `2`.
- **Mapping Retrieval**: It retrieves the string of letters corresponding to this digit. For instance, if `number` is `2`, then `value` will be `"abc"`.

#### Loop Through Letters

```cpp
for (int i = 0; i < value.length(); i++) {
    current.push_back(value[i]);  // Append the letter to the current combination
    solve(digits, current, index + 1, result, mapping);  // Recursively call for the next digit
    current.pop_back();  // Backtrack: remove the letter to try other combinations
}
```
- **Loop**: This iterates through each letter mapped to the current digit.
  - **Example**: For `value = "abc"`, it will loop through each character `'a'`, `'b'`, and `'c'`.
  
- **Appending to Current**: The line `current.push_back(value[i])` appends the current letter to the `current` combination.
  - **Example**: If the loop is at `i = 0`, `current` becomes `"a"`.

- **Recursive Call**: It then calls `solve` recursively for the next index (`index + 1`).
  - **Example**: After appending `'a'`, it calls `solve("23", "a", 1, result, mapping)`, moving on to process the second digit.

- **Backtracking**: After returning from the recursive call, `current.pop_back()` removes the last letter to backtrack and try the next letter.
  - **Example**: After exploring combinations with `"a"`, it will backtrack to `""` and then append `'b'`, forming combinations like `"b"` and continuing the process.

#### Public Function to Initialize the Process

```cpp
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;  // To store all combinations

        // If input is empty, return an empty list
        if (digits.empty()) return result;
```
- **Function Purpose**: This is the public function `letterCombinations` that initializes the process of finding combinations.
- **Check for Empty Input**: If the `digits` string is empty, it returns an empty `result`.

#### Digit Mapping

```cpp
string mapping[10] = {
    "",     // 0 has no letters
    "",     // 1 has no letters
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz"  // 9
};
```
- **Mapping Array**: This array maps each digit to its corresponding letters. Digits `0` and `1` are mapped to empty strings since they do not represent any letters.

#### Start the Recursive Process

```cpp
string current = "";  // Empty string to hold current combination
solve(digits, current, 0, result, mapping);  // Start the recursion from index 0
return result;
```
- **Initialize Current**: An empty string `current` is initialized to start forming combinations.
- **Recursive Call**: `solve` is called with the initial parameters to start the recursive exploration.
- **Return Result**: Finally, it returns the `result` vector containing all the letter combinations.

---

### Example Walkthrough

#### Input: `"23"`

1. **First Call**: `solve("23", "", 0, result, mapping)`
   - **Current Digit**: `2`, **Mapped Letters**: `"abc"`
   - Loop through letters `'a'`, `'b'`, and `'c'`.

2. **First Loop (i=0)**: 
   - **Current**: `"a"`
   - **Next Call**: `solve("23", "a", 1, result, mapping)`
     - **Current Digit**: `3`, **Mapped Letters**: `"def"`
     - Loop through letters `'d'`, `'e'`, and `'f'`.

3. **Next Loop (i=0)**: 
   - **Current**: `"ad"`
   - **Base Case**: Adds `"ad"` to `result`.

4. **Next Loop (i=1)**:
   - **Current**: `"ae"`
   - **Base Case**: Adds `"ae"` to `result`.

5. **Next Loop (i=2)**:
   - **Current**: `"af"`
   - **Base Case**: Adds `"af"` to `result`.

6. **Backtrack** to `"a"` and then to `""` and proceed with next letters:
   - For `b`: 
     - Combinations `"bd"`, `"be"`, `"bf"` are added.
   - For `c`: 
     - Combinations `"cd"`, `"ce"`, `"cf"` are added.

### Final Output

After processing all combinations, the final result for the input `"23"` will be:

```cpp
["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
```
