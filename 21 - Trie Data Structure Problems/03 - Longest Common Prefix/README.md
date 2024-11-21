<h1 align='center'>Longest - Common - Prefix</h1>

## Problem Statement

**Problem URL :** [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/)

![image](https://github.com/user-attachments/assets/10b79c3e-2c71-457b-9abb-b3ccb0c7298b)

## Problem Explanation
#### Problem:
Given a list of strings, you need to find the **longest common prefix** (LCP) that is common to all the strings in the list.

#### Explanation for Beginners:
The problem asks us to find the longest string that appears at the start of all given strings. For example, if we are given the following list of strings:
- `["flower", "flow", "flight"]`

The longest common prefix is **"fl"** because it is the longest string that is common at the beginning of all the strings in the list.

#### Example 1:
**Input**: `["flower", "flow", "flight"]`  
**Output**: `"fl"`

- All the strings start with `"fl"`, so that is the longest common prefix.

#### Example 2:
**Input**: `["dog", "racecar", "car"]`  
**Output**: `""` (No common prefix)

- There is no common prefix in any of the strings, so the output is an empty string.

#### Approach:
1. **Iterate through each string in the list**: We need to compare each string to see what part of the string matches with the others.
2. **Use a Trie (Prefix Tree)**: A Trie is a tree-like data structure that is used to store a collection of strings. It’s perfect for this problem because we can easily traverse the Trie to find the common prefix between all strings.
3. **Insert words into the Trie**: As we insert each word into the Trie, we track the common prefix by checking how much of the word shares a path with the other words already inserted.
4. **Find the longest common prefix**: By traversing the Trie from the root, we check how much of the prefix is common to all the words.

## Problem Solution
```cpp
class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        int childCount;
        bool isTerminal;

        TrieNode(int data){
            this -> data = data;
            for(int i = 0; i < 26; i++) children[i] = NULL;
            isTerminal = false;
            childCount = 0;
        }
};

class Trie{
    public:
        TrieNode* root;
        Trie(char ch){ 
            root = new TrieNode(ch);
        }

        void insertUtil(TrieNode* root, string& word, int index){
            if(index == word.size()){
                root -> isTerminal = true;
                return;
            }

            int charIndex = word[index] - 'a';
            if(root -> children[charIndex] == NULL){
                root -> children[charIndex] = new TrieNode(word[index]);
                root -> childCount++;
            }

            insertUtil(root -> children[charIndex], word, index+1);
        }

        void insertWord(string& word){
            insertUtil(root, word, 0);
        }

        void lcp(string str, string& ans){
            TrieNode* node = root;
            for(int i = 0; i < str.length(); i++){
                char ch = str[i];

                if(node -> childCount == 1) {
                    ans.push_back(ch);

                    int index = ch - 'a';

                    node = node -> children[index];
                }else break;

                if(node -> isTerminal) break;
            }
        }
    
    ~Trie() {
        deleteTrie(root);
    }
    private:
        void deleteTrie(TrieNode* node) {
        if (!node) return;
        for (int i = 0; i < 26; i++) {
            deleteTrie(node->children[i]);
        }
        delete node;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        for(string& str : strs) if(str.empty()) return "";

        Trie* t = new Trie('\0');

        for(int i = 0; i < strs.size(); i++) t->insertWord(strs[i]);

        string first = strs[0];
        string ans = "";

        t -> lcp(first, ans);

        return ans;
    }
};
```

## Problem Solution Explanation

Let’s break down the given code line by line.

#### TrieNode Class:

```cpp
class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        int childCount;
        bool isTerminal;

        TrieNode(int data){
            this -> data = data;
            for(int i = 0; i < 26; i++) children[i] = NULL;
            isTerminal = false;
            childCount = 0;
        }
};
```

- **TrieNode**: This class represents each node in the Trie.
    - `data`: Stores the character of the node.
    - `children`: An array of pointers to the 26 children (for each letter a to z).
    - `childCount`: Keeps track of the number of children nodes (this is used to identify whether we have a common prefix).
    - `isTerminal`: A flag that indicates whether this node marks the end of a word.

#### Trie Class:

```cpp
class Trie {
    public:
        TrieNode* root;
        Trie(char ch){ 
            root = new TrieNode(ch);
        }
```

- **Trie**: This class represents the Trie data structure itself.
    - `root`: Points to the root of the Trie (initially an empty node).
    - The constructor initializes the `root`.

#### Insert Function:

```cpp
void insertUtil(TrieNode* root, string& word, int index){
    if(index == word.size()){
        root -> isTerminal = true;
        return;
    }

    int charIndex = word[index] - 'a';
    if(root -> children[charIndex] == NULL){
        root -> children[charIndex] = new TrieNode(word[index]);
        root -> childCount++;
    }

    insertUtil(root -> children[charIndex], word, index+1);
}
```

- **insertUtil**: A recursive function to insert a word into the Trie.
    - It inserts the word starting from the root, character by character.
    - If a node doesn’t exist for the current character, a new node is created.
    - If the node is the last character of the word, we mark it as `isTerminal = true`.

#### Insert Word:

```cpp
void insertWord(string& word){
    insertUtil(root, word, 0);
}
```

- **insertWord**: This function is used to insert a word starting from the root of the Trie. It calls the `insertUtil` helper function with the root node.

#### Longest Common Prefix (LCP) Function:

```cpp
void lcp(string str, string& ans){
    TrieNode* node = root;
    for(int i = 0; i < str.length(); i++){
        char ch = str[i];

        if(node -> childCount == 1) {
            ans.push_back(ch);

            int index = ch - 'a';

            node = node -> children[index];
        }else break;

        if(node -> isTerminal) break;
    }
}
```

- **lcp**: This function finds the longest common prefix.
    - It starts from the root of the Trie and processes the input string character by character.
    - If a node has only one child (i.e., there’s only one possible path), it is added to the prefix.
    - The loop stops when:
        - The node has more than one child (i.e., we can’t extend the prefix).
        - A node is a terminal node (i.e., it marks the end of a word).
  
#### Destructor:

```cpp
~Trie() {
    deleteTrie(root);
}
```

- The destructor ensures that the memory allocated for the Trie nodes is freed when the Trie object is destroyed.

#### Helper Function to Delete Trie:

```cpp
void deleteTrie(TrieNode* node) {
    if (!node) return;
    for (int i = 0; i < 26; i++) {
        deleteTrie(node->children[i]);
    }
    delete node;
}
```

- **deleteTrie**: This recursive function deletes all nodes in the Trie to avoid memory leaks.



#### Solution Class:

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        for(string& str : strs) if(str.empty()) return "";

        Trie* t = new Trie('\0');

        for(int i = 0; i < strs.size(); i++) t->insertWord(strs[i]);

        string first = strs[0];
        string ans = "";

        t -> lcp(first, ans);

        return ans;
    }
};
```

- **longestCommonPrefix**: This is the main function where:
    - It checks if the list of strings is empty or contains an empty string (if true, return empty).
    - It creates a Trie and inserts each string from the list into the Trie.
    - After inserting all the strings, it uses the `lcp` function to find the longest common prefix.



### Step 3: Example Walkthrough

Let's use the following example to understand how the code works:

**Example**:  
Input: `["flower", "flow", "flight"]`

1. Insert "flower", "flow", and "flight" into the Trie.
    - The Trie will look like this:
      ```
      root -> f -> l -> o -> w -> e -> r
                             -> f -> l -> i -> g -> h -> t
      ```

2. Now, find the longest common prefix using the `lcp` function:
    - Start with "flower". The first character `'f'` has only one child `'l'`, so add `'f'` to the prefix.
    - The next character `'l'` also has only one child `'o'` or `'f'`, so add `'l'` to the prefix.
    - The next characters `'o'` and `'w'` diverge, so the longest common prefix stops at "fl".
    
Output: `"fl"`



### Step 4: Time and Space Complexity

#### Time Complexity:
- **Insert Operation**: Inserting a single word takes O(L) time, where L is the length of the word. For N words, the time complexity will be O(N * L).
- **Longest Common Prefix**: The LCP function checks each character of the first word, so it takes O(L) time, where L is the length of the first word.

Thus, the total time complexity is O(N * L), where N is the number of words and L is the average length of the words.

#### Space Complexity:
- **Trie Storage**: The space complexity depends on the number of nodes in the Trie. In the worst case, if all characters in all words are distinct, the space complexity will be O(N * L).
  
Thus, the space complexity is O(N * L).



### Step 5: Additional Recommendations

- **Edge Cases**: Consider edge cases like:
  - An empty list of strings.
  - A list with strings that have no common prefix.
  - A list where all strings are the same.
  
- **Optimization**: The given solution is efficient for most use cases. However, for extremely large inputs, you might want to optimize memory usage by compressing the Trie (using techniques like path compression).
