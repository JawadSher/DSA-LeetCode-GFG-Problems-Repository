<h1 align='center'>Implement - Trie - Prefix Tree</h1>

## Problem Statement

**Problem URL :** [Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/)

![image](https://github.com/user-attachments/assets/040a264e-6d5a-4009-86a9-bcb89906f794)
![image](https://github.com/user-attachments/assets/990215c8-f77f-43d6-a745-23a47a02ac87)

## Problem Explanation
A **Trie** (also known as a **Prefix Tree**) is a special tree-like data structure used for storing strings, where each node represents a character of the string. It is used to perform efficient retrieval operations for prefix-based searches.

#### **Problem Overview**
You need to implement a **Trie** with the following methods:
1. **`insert(word)`** - Inserts a word into the Trie.
2. **`search(word)`** - Returns `true` if the word exists in the Trie, otherwise returns `false`.
3. **`startsWith(prefix)`** - Returns `true` if there is any word in the Trie that starts with the given prefix.

#### **Example Explanation**

Let's take an example to understand how the Trie works:
- Insert the word `"apple"`.
- Insert the word `"app"`.
- Insert the word `"banana"`.
  
Here is what happens step by step:

1. **Inserting "apple"**:
    - Start with an empty Trie.
    - Add `'a'` at the root.
    - Add `'p'` under `'a'`, `'p'` under the first `'p'`, `'l'` under `'p'`, and `'e'` under `'l'`.
    - Mark `'e'` as the terminal character.

   The Trie now looks like:
   ```
   root -> a -> p -> p -> l -> e (isTerminal)
   ```

2. **Inserting "app"**:
    - Start at the root.
    - The path for `'a'` and `'p'` already exists.
    - Add the second `'p'` and mark it as terminal.

   The Trie now looks like:
   ```
   root -> a -> p -> p (isTerminal) -> l -> e (isTerminal)
   ```

3. **Inserting "banana"**:
    - Add `'b'`, `'a'`, `'n'`, `'a'`, `'n'`, `'a'` following the same approach.

   The Trie now looks like:
   ```
   root -> a -> p -> p (isTerminal) -> l -> e (isTerminal)
                     -> b -> a -> n -> a -> n -> a (isTerminal)
   ```

4. **Search for "app"**:
    - Traverse the Trie from the root, checking each character in the word `"app"`.
    - Since the word exists, return `true`.

5. **Search for "appl"**:
    - Traverse the Trie, but the character `'l'` does not exist after the prefix `"app"`, so return `false`.

6. **startsWith("ban")**:
    - Traverse the Trie, the characters `'b'`, `'a'`, `'n'` are found, so return `true`.

#### **Approach to Solve the Problem**

1. **Create the TrieNode class**:
    - Each node in the Trie stores:
      - A character `data`.
      - An array `children[26]` to represent 26 possible children (one for each letter of the alphabet).
      - A boolean `isTerminal` to indicate if the node marks the end of a word.
  
2. **Create the Trie class**:
    - The Trie class has a `root` node, which is a TrieNode.
    - The `insert` method will insert characters into the Trie recursively.
    - The `search` method will check whether a word exists by traversing the Trie.
    - The `startsWith` method will check if a prefix exists by traversing the Trie.

## Problem Solution
```cpp
class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char data){
            this -> data = data;
            for(int i = 0; i < 26; i++) children[i] = NULL;
            isTerminal = false;
        }
};
class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word, int index){
        if(index == word.size()){
            root -> isTerminal = true;
            return;
        }

        int charIndex = word[index] - 'a';
        if(root -> children[charIndex] == NULL) root -> children[charIndex] = new TrieNode(word[index]);

        insertUtil(root -> children[charIndex], word, index+1);
    }
    void insert(string word){
        insertUtil(root, word, 0);
    }
    
    bool searchUtil(TrieNode* root, string word, int index){
        if(index == word.size()) return root -> isTerminal;

        int charIndex = word[index] - 'a';
        if(root -> children[charIndex] == NULL) return false;

        return searchUtil(root -> children[charIndex], word, index+1);
        
    }
    bool search(string word) {
        return searchUtil(root, word, 0);
    }

    bool startsWithUtil(TrieNode* root, string prefix, int index){
        if(index == prefix.size()) return true;
        
        int charIndex = prefix[index] - 'a';
        if(root -> children[charIndex] == NULL) return false;

        return startsWithUtil(root -> children[charIndex], prefix, index+1);
    }

    bool startsWith(string prefix){
        return startsWithUtil(root, prefix, 0);
    } 
        
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```

## Problem Solution Explanation
Here’s a detailed explanation of the given **Trie** implementation in C++:

```cpp
class TrieNode {
public:
    char data;
    TrieNode* children[26];  // Array to hold 26 children (for each letter in the alphabet)
    bool isTerminal;  // Marks if the node represents the end of a word

    TrieNode(char data) {
        this->data = data;  // Initialize the node with the given character
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;  // Initialize all children pointers to NULL (no child initially)
        }
        isTerminal = false;  // Initially, the node is not terminal (it doesn't mark the end of a word)
    }
};
```

#### **Explanation of TrieNode class**:
1. **`char data`**: 
   - This stores the character of the current node. Each node in the Trie represents a single character of the word.
   
2. **`TrieNode* children[26]`**: 
   - This is an array of pointers to child TrieNodes. Each index of this array corresponds to a letter from `a` to `z`. For example, `children[0]` points to 'a', `children[1]` points to 'b', and so on.
   
3. **`bool isTerminal`**: 
   - This boolean flag indicates whether the current node is the end of a word. If `isTerminal` is `true`, it means the node marks the last character of a complete word. If it's `false`, it is just an intermediate node.

4. **Constructor**: 
   - The constructor initializes the node with a character (`data`), and all child pointers are set to `NULL`. It also sets `isTerminal` to `false`.

```cpp
class Trie {
public:
    TrieNode* root;  // The root of the Trie (doesn't store any character)
```

#### **Explanation of the Trie class**:
- **`TrieNode* root`**: 
  - This is a pointer to the root node of the Trie. The root node doesn't store any character (`'\0'`), and it is just the starting point for all words inserted into the Trie.

```cpp
    Trie() {
        root = new TrieNode('\0');  // Initialize the root with a dummy character ('\0')
    }
```

#### **Trie Constructor**:
- The constructor creates the root node of the Trie. The root node is initialized with a null character (`'\0'`) since it does not represent any specific letter but serves as the starting point for all insertions.

```cpp
    void insertUtil(TrieNode* root, string word, int index) {
        if (index == word.size()) {
            root->isTerminal = true;  // If we've reached the end of the word, mark the node as terminal
            return;
        }

        int charIndex = word[index] - 'a';  // Calculate the index of the character (0 for 'a', 1 for 'b', etc.)

        // If the child node for the current character doesn't exist, create a new TrieNode
        if (root->children[charIndex] == NULL) {
            root->children[charIndex] = new TrieNode(word[index]);
        }

        // Recursively insert the remaining characters of the word
        insertUtil(root->children[charIndex], word, index + 1);
    }
```

#### **`insertUtil` function**:
- **Base Case (Line 4)**:
   - The function checks if `index == word.size()`. If true, it means we have inserted all the characters of the word. The current node (represented by `root`) should be marked as a terminal node (`root->isTerminal = true`), indicating the word ends here.

- **Calculate `charIndex` (Line 6)**:
   - The `charIndex` variable is used to map the character to the corresponding index in the `children` array. For example, if the character is `'a'`, then `charIndex = 0`, for `'b'`, `charIndex = 1`, and so on.

- **Check for Existing Child Node (Lines 8-10)**:
   - If the child node for the current character (`root->children[charIndex]`) does not exist, a new `TrieNode` is created and added at the appropriate position in the `children` array.

- **Recursive Insertion (Line 13)**:
   - The function is then called recursively on the child node of the current character (`root->children[charIndex]`) and proceeds with the next character in the word (`index + 1`).

```cpp
    void insert(string word) {
        insertUtil(root, word, 0);  // Start the insertion from the root node
    }
```

#### **`insert` function**:
- This is the public function that calls the `insertUtil` function, passing the root node, the word to be inserted, and the starting index (`0`).

```cpp
    bool searchUtil(TrieNode* root, string word, int index) {
        if (index == word.size()) {
            return root->isTerminal;  // If we've reached the end of the word, return whether the node is terminal
        }

        int charIndex = word[index] - 'a';  // Calculate the index of the character

        // If the child node for the current character doesn't exist, return false
        if (root->children[charIndex] == NULL) {
            return false;
        }

        // Recursively search for the remaining characters of the word
        return searchUtil(root->children[charIndex], word, index + 1);
    }
```

#### **`searchUtil` function**:
- **Base Case (Line 4)**:
   - When the `index` reaches the end of the word (`index == word.size()`), the function checks whether the current node (`root`) is terminal. If `root->isTerminal` is `true`, it means the word exists in the Trie and it returns `true`. If not, it returns `false`.

- **Character Index Calculation (Line 6)**:
   - The index for the current character is calculated in the same way as in the `insertUtil` function.

- **Child Node Check (Lines 8-10)**:
   - If the child node for the current character (`root->children[charIndex]`) is `NULL`, it means the word doesn’t exist in the Trie, so the function returns `false`.

- **Recursive Search (Line 13)**:
   - The function calls itself recursively for the next character in the word (`index + 1`) until the whole word is checked.

```cpp
    bool search(string word) {
        return searchUtil(root, word, 0);  // Start the search from the root node
    }
```

#### **`search` function**:
- This is the public function that calls the `searchUtil` function, passing the root node, the word to search for, and the starting index (`0`).

```cpp
    bool startsWithUtil(TrieNode* root, string prefix, int index) {
        if (index == prefix.size()) {
            return true;  // If we've reached the end of the prefix, return true
        }

        int charIndex = prefix[index] - 'a';  // Calculate the index of the character

        // If the child node for the current character doesn't exist, return false
        if (root->children[charIndex] == NULL) {
            return false;
        }

        // Recursively check for the remaining characters of the prefix
        return startsWithUtil(root->children[charIndex], prefix, index + 1);
    }
```

#### **`startsWithUtil` function**:
- **Base Case (Line 4)**:
   - If the `index` equals the size of the prefix (`index == prefix.size()`), it means the entire prefix has been found, so the function returns `true`.

- **Character Index Calculation (Line 6)**:
   - Similar to the other functions, the `charIndex` is calculated to map the current character of the prefix to the correct position in the `children` array.

- **Child Node Check (Lines 8-10)**:
   - If the child node for the current character doesn’t exist, it means no word with the given prefix exists, so it returns `false`.

- **Recursive Check (Line 13)**:
   - The function calls itself recursively to check for the next character in the prefix.

```cpp
    bool startsWith(string prefix) {
        return startsWithUtil(root, prefix, 0);  // Start checking the prefix from the root node
    }
};
```

#### **`startsWith` function**:
- This public function calls `startsWithUtil`, passing the root node, the prefix, and the starting index (`0`).


### Step 3: Example Walkthrough

**Example 1:**

```cpp
Trie* obj = new Trie();
obj->insert("apple");
obj->insert("app");

bool searchResult = obj->search("apple"); // Expected: true
bool startsWithResult = obj->startsWith("app"); // Expected: true
```

1. **Inserting "apple"**:
   - `'a' -> 'p' -> 'p' -> 'l' -> 'e'` (Terminal at 'e')
2. **Inserting "app"**:
   - `'a' -> 'p' -> 'p'` (Terminal at second 'p')
3. **Searching "apple"**:
   - The word exists in the Trie, so it returns `true`.
4. **startsWith "app"**:
   - The prefix "app" exists in the Trie, so it returns `true`.

**Example 2:**

```cpp
bool searchResult2 = obj->search("banana"); // Expected: false
```

- The word `"banana"` doesn't exist in the Trie, so it returns `false`.

### Step 4: Time and Space Complexity

#### **Time Complexity:**

- **insert(word)**: The time complexity is **O(m)** where `m` is the length of the word. Inserting each character requires constant time (since there are 26 possible characters).
- **search(word)**: The time complexity is **O(m)** where `m` is the length of the word.
- **startsWith(prefix)**: The time complexity is **O(k)** where `k` is the length of the prefix.

#### **Space Complexity:**

- The space complexity is **O(n)** where `n` is the total number of characters stored in the Trie. Each node represents one character and the Trie stores nodes for each character in all words inserted.

### Step 5: Additional Recommendations

1. **Edge Cases**:
   - Consider edge cases like inserting empty strings or searching for empty strings.
   - Handle cases where the input is a prefix of another word.
2. **Optimizations**:
   - You could improve the `startsWith` function by adding additional checks or making the `TrieNode` structure more efficient, like using a hash map for children nodes.
3. **Memory Management**:
   - Although `TrieNode` uses an array of fixed size (26), an optimization could involve using a hash map to handle cases where only a small subset of the alphabet is used.

