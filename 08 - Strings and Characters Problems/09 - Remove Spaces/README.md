<h1 align='center'>Remove - Spaces</h1>

## Problem Statement

**Problem URL :** [Remove Spaces](https://www.geeksforgeeks.org/problems/remove-spaces0128/1)

![image](https://github.com/user-attachments/assets/7c3bfc9e-25ae-42b2-ac16-d0ae9f92fe46)

## Problem Solution
```cpp
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        int index = 0;

        while(i < n){
            int j = i + 1;

            while(j < n && chars[i] == chars[j]){
                j++;
            }
            chars[index++] = chars[j];
            int count = j - i;

            if(count > 9){
                string s_count = to_string(count);
                for(char c : s_count){
                    chars[index++] = c;
                }
            }

            i = j;
        }
        return index;
    }
};
```

## Problem Solution Explanation
This problem involves compressing a list of characters by replacing consecutive repeating characters with the character followed by the count of repetitions. The goal is to modify the input list `chars` in place and return the length of the new compressed list. Let’s break down the provided code and explain it step by step:

```cpp
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();  // 1
        int i = 0;  // 2
        int index = 0;  // 3
```

1. **`int n = chars.size();`**  
   - This stores the size of the input character vector `chars` in `n`.
   - Example: If `chars = ['a', 'a', 'b', 'b', 'b', 'c']`, then `n = 6`.

2. **`int i = 0;`**  
   - `i` is initialized to 0. It represents the starting point of each group of consecutive characters as we move through the vector.

3. **`int index = 0;`**  
   - `index` represents the position in the array where we will insert the compressed characters.

---

```cpp
        while(i < n){  // 4
            int j = i + 1;  // 5

            while(j < n && chars[i] == chars[j]){  // 6
                j++;  // 7
            }
```

4. **`while(i < n)`**  
   - This loop iterates through the characters in the input list `chars` until all characters are processed.
   - `i` marks the current position where the next group of characters begins.

5. **`int j = i + 1;`**  
   - `j` is initialized to `i + 1`. It is used to find how many consecutive characters are the same as `chars[i]`.

6. **`while(j < n && chars[i] == chars[j])`**  
   - This inner loop checks if `chars[j]` is the same as `chars[i]`. If so, it keeps increasing `j` to count how many characters in a row are the same.
   - Example: If `chars = ['a', 'a', 'b', 'b', 'b', 'c']`, and `i = 0` (pointing to the first `'a'`), `j` will move through the second `'a'` and stop at the first `'b'`.

7. **`j++;`**  
   - The index `j` is incremented to expand the group of consecutive characters.

---

```cpp
            chars[index++] = chars[j];  // 8
            int count = j - i;  // 9
```

8. **`chars[index++] = chars[j];`**  
   - After finding the entire group of consecutive characters, the character `chars[i]` is stored in `chars[index]`. Then `index` is incremented for the next insertion.
   - Example: If `chars = ['a', 'a', 'b', 'b', 'b', 'c']`, and `i = 0`, this will place `'a'` at `chars[index]` and move `index` forward.

9. **`int count = j - i;`**  
   - `count` is calculated as the difference between `j` and `i`. This gives the number of consecutive occurrences of `chars[i]`.
   - Example: For the two `'a'`s, `count = j - i = 2`.

---

```cpp
            if(count > 1){  // 10
                string s_count = to_string(count);  // 11
                for(char c : s_count){  // 12
                    chars[index++] = c;  // 13
                }
            }
```

10. **`if(count > 1)`**  
    - If the `count` of consecutive characters is greater than 1, the compressed version needs to include the count after the character.

11. **`string s_count = to_string(count);`**  
    - `count` is converted to a string (e.g., if `count = 2`, then `s_count = "2"`). This is necessary because the count will be added as individual characters.

12. **`for(char c : s_count)`**  
    - This loop iterates over each character in the string `s_count`. In case the count has more than one digit (like "12"), each digit is inserted individually.

13. **`chars[index++] = c;`**  
    - Each character in `s_count` is stored in the next available position in `chars`, and `index` is incremented after each insertion.
    - Example: If `count = 3`, this will place `'3'` in the `chars` array after the character `'b'`.

---

```cpp
            i = j;  // 14
        }
        return index;  // 15
    }
};
```

14. **`i = j;`**  
    - After processing the group of consecutive characters, `i` is moved to `j`, which is the start of the next group of characters.

15. **`return index;`**  
    - Finally, the function returns `index`, which is the length of the compressed version of the list.

---

### Example Walkthrough

Let’s walk through an example:

**Input:** `chars = ['a', 'a', 'b', 'b', 'b', 'c']`

- Initially, `i = 0`, `index = 0`, and `n = 6`.
- The first character is `'a'`. We count how many times it appears consecutively (`count = 2`), so we store `'a'` at `chars[0]` and then `'2'` at `chars[1]`.
  - `chars = ['a', '2', 'b', 'b', 'b', 'c']`, `index = 2`.
- Next, we move to `'b'`. We count that it appears 3 times (`count = 3`), so we store `'b'` at `chars[2]` and `'3'` at `chars[3]`.
  - `chars = ['a', '2', 'b', '3', 'b', 'c']`, `index = 4`.
- Finally, we process `'c'`, which appears once, so we just store `'c'` at `chars[4]`.
  - `chars = ['a', '2', 'b', '3', 'c', 'c']`, `index = 5`.
- The final compressed array is `['a', '2', 'b', '3', 'c']`, and the function returns `5`.

### Output
- Compressed length = `5`.

