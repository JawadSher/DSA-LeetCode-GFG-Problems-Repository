<h1 align='center'>Trie - Data Structure - Example</h1>

### **What is a Trie?**
A **Trie** is a specialized tree-like data structure designed to store strings efficiently, particularly for operations involving prefixes. It’s widely used in scenarios like:

- **Autocomplete Systems**: Quickly finding words starting with a given prefix.
- **Spell Checkers**: Searching for valid words.
- **Search Engines**: Matching queries with indexed terms.

A Trie organizes characters hierarchically so that common prefixes are shared among words. This structure ensures that operations like insertion, search, and deletion are efficient.



#### **How Trie Stores Data**

- **Nodes**:
  Each node in the Trie represents a single character. 
- **Root**:
  The root node is an empty node (`'\0'`) that serves as the starting point.
- **Children**:
  Every node has an array (or map) of pointers to its child nodes. For English lowercase letters, the size of the array is usually 26 (representing 'a' to 'z').
- **Terminal Nodes**:
  A flag `isTerminal` in each node marks whether the node represents the end of a valid word.

#### **Example: Storing Words in a Trie**
Suppose we want to store the words `cat`, `car`, and `dog`. The Trie would look like this:

```
          (root)
           /  \
          c    d
         / \    \
        a   a    o
       /     \     \
      t       r     g
      *       *     *
```
- Each letter is stored in a node.
- Common prefixes like `ca` are shared.
- `*` marks the end of a valid word (`isTerminal = true`).



### **How Trie Works**

#### **1. Insertion**
- Start at the root node.
- For each character in the word:
  - Calculate its index (`char - 'a'`).
  - If a node for this character exists, move to that node.
  - Otherwise, create a new node.
- After processing all characters, mark the last node as `isTerminal = true`.

#### **2. Search**
- Start at the root node.
- Traverse the nodes following the characters in the word.
- If all characters are found and the last node is marked as `isTerminal`, the word exists.

#### **3. Deletion**
- Traverse the Trie to locate the word.
- Unmark `isTerminal` at the last node.
- Recursively delete nodes if they are no longer part of any other word.



### **Implementation in Detail**

#### **Class Structure**

**`TrieNode`**: Represents a single character in the Trie.
```cpp
class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        for (int i = 0; i < 26; i++) 
            children[i] = NULL;
        isTerminal = false;
    }
};
```

**`Trie`**: Manages the Trie operations.
```cpp
class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0'); // Root is initialized with null character
    }
};
```



### **Insertion Operation**

#### **Explanation**
1. Traverse the Trie, following the characters of the word.
2. If a character node doesn’t exist, create it.
3. After processing the last character, mark the node as `isTerminal`.

#### **Code**
```cpp
void insertUtil(TrieNode* root, string& word, int index) {
    if (index == word.size()) {
        root->isTerminal = true; // Mark the end of the word
        return;
    }

    int charIndex = word[index] - 'a';
    if (root->children[charIndex] == NULL) 
        root->children[charIndex] = new TrieNode(word[index]);

    insertUtil(root->children[charIndex], word, index + 1);
}

void insertWord(string word) {
    insertUtil(root, word, 0);
}
```

#### **Example Flow**
Insert `"cat"` into an empty Trie:
1. `'c'`: Create a new node at `children[2]`.
2. `'a'`: Create a new node at `children[0]`.
3. `'t'`: Create a new node at `children[19]` and mark it `isTerminal = true`.



### **Search Operation**

#### **Explanation**
1. Traverse the Trie using the characters of the word.
2. If you reach the last character and its node is `isTerminal`, the word exists.
3. If a character is missing, the word doesn’t exist.

#### **Code**
```cpp
bool searchUtil(TrieNode* root, string& word, int index) {
    if (index == word.size())
        return root->isTerminal;

    int charIndex = word[index] - 'a';
    if (root->children[charIndex] == NULL)
        return false;

    return searchUtil(root->children[charIndex], word, index + 1);
}

bool searchWord(string word) {
    return searchUtil(root, word, 0);
}
```

#### **Example Flow**
Search for `"cat"`:
1. Traverse `'c'`, `'a'`, and `'t'`.
2. Check `isTerminal` at `'t'`. If `true`, the word exists.



### **Deletion Operation**

#### **Explanation**
1. Find the word and unmark `isTerminal` at the last node.
2. Recursively delete nodes that are no longer part of any word.

#### **Code**
```cpp
bool removeUtil(TrieNode* root, string& word, int index) {
    if (index == word.size()) {
        if (!root->isTerminal)
            return false;

        root->isTerminal = false;

        for (int i = 0; i < 26; i++)
            if (root->children[i] != NULL)
                return false;
        return true;
    }

    int charIndex = word[index] - 'a';
    TrieNode* child = root->children[charIndex];
    if (child == NULL)
        return false;

    bool shouldDeleteChild = removeUtil(child, word, index + 1);

    if (shouldDeleteChild) {
        delete child;
        root->children[charIndex] = NULL;

        for (int i = 0; i < 26; i++)
            if (root->children[i] != NULL)
                return false;
        return true;
    }

    return false;
}

void removeWord(string word) {
    removeUtil(root, word, 0);
}
```

#### **Example Flow**
Delete `"cat"`:
1. Unmark `isTerminal` at `'t'`.
2. Delete `'t'` if it has no children.
3. Repeat for `'a'` and `'c'`.



### **Complexity Analysis**

| Operation | Time Complexity | Space Complexity |
|--|-|--|
| Insert     | O(L)      | O(26.L) |
| Search     | O(L)        | O(1)         |
| Delete     | O(L)       | O(1)        |



### **Trie vs. Hashmap**

Both **Tries** and **HashMaps** are data structures used for storing and searching strings or key-value pairs efficiently. However, their design and usage differ based on the scenario. Let's explore the key aspects and "why" of each.



### **1. Storage Structure**
#### **Trie:**
- A **tree-like structure** where each node represents a character of a string.
- Words are stored as paths from the root to terminal nodes.
- Each level of the Trie corresponds to a character in the string.

**Why?**
- Tries store common prefixes only once, which saves space when dealing with many strings that share prefixes.

**Example:**
Storing `["cat", "car", "cart"]`:
```
       root
       /  \
      c    ...
     /
    a
   / \
  t   r
       \
        t
```
Here, the prefix `"ca"` is shared among all three words, reducing redundancy.



### **HashMap:**
- Stores key-value pairs where the key (e.g., a string) is hashed to an index in a hash table.
- Each word is an independent key, so no prefixes are shared.

**Why?**
- HashMaps are designed for fast **exact match lookups** and do not inherently group data by common prefixes.

**Example:**
Storing `["cat", "car", "cart"]`:
```plaintext
{
  "cat": true,
  "car": true,
  "cart": true
}
```
Each word is treated as a separate key with no explicit relationship between them.



### **2. Lookup Time Complexity**
#### **Trie:**
- **O(L)**, where \(L\) is the length of the word.
- Each character in the word is traversed from the root.

**Why?**
- Tries allow lookup character by character, making prefix-based operations efficient.

**Example:**
To search for `"cat"` in the Trie:
1. Start at root.
2. Go to the child node `'c'`.
3. Move to `'a'`.
4. Reach `'t'` and check `isTerminal`.



### **HashMap:**
- **O(1)** for average-case lookups if the hash function is efficient.
- Can degrade to **O(n)** in the worst case (e.g., hash collisions).

**Why?**
- Hashing converts keys directly into indices, making direct lookups very fast.

**Example:**
To search for `"cat"` in a HashMap:
1. Compute the hash of `"cat"`.
2. Access the corresponding bucket in constant time.



### **3. Space Complexity**
#### **Trie:**
- **O(Σ × N)**, where \(Σ\) is the size of the character set (e.g., 26 for lowercase English letters), and \(N\) is the total number of characters in all strings.
- Space-efficient for shared prefixes but uses extra memory for pointers.

**Why?**
- Each node has up to \(Σ\) children, leading to high overhead for sparse Tries.

**Example:**
For `"cat"` and `"car"`, Trie saves space by storing `"ca"` only once.



### **HashMap:**
- **O(M × K)**, where \(M\) is the number of keys, and \(K\) is the average key length.
- Consumes more memory since each key is stored fully.

**Why?**
- HashMaps do not share prefixes, so duplicate prefixes take extra space.

**Example:**
For `"cat"` and `"car"`, both keys are stored independently.



### **4. Operations**
#### **Trie:**
- **Insertion**: Adds characters one by one, **O(L)**.
- **Search**: Checks characters one by one, **O(L)**.
- **Prefix Queries**: Efficient, retrieves all words starting with a prefix.

**Why?**
- The character-wise structure makes Tries inherently suitable for prefix-based operations.

**Example:**
Finding all words with prefix `"ca"` in Trie:
- Start at root.
- Traverse `"c" -> "a"`.
- Collect all descendants: `"cat", "car", "cart"`.



### **HashMap:**
- **Insertion/Search**: Hash the entire string, **O(1)** (average case).
- **Prefix Queries**: Inefficient, requires iterating over all keys.

**Why?**
- HashMaps are not designed for prefix queries since the hash of a prefix differs from the hash of a full key.

**Example:**
Finding all words with prefix `"ca"`:
- Iterate through all keys and check if they start with `"ca"`. Time complexity: **O(M × K)**.



### **5. Applications**
#### **Trie:**
1. **Autocomplete Systems**:
   - Efficiently find all completions for a given prefix.
2. **Spell Checkers**:
   - Quickly verify if a word exists or suggest corrections.
3. **IP Routing**:
   - Store and query hierarchical data like IP addresses.

**Why?**
- Trie’s prefix-based structure makes it optimal for these tasks.

**Example:**
For the prefix `"do"`:
- A Trie can instantly return completions like `"dog", "door", "dot"`.



### **HashMap:**
1. **Key-Value Lookups**:
   - Retrieve values (e.g., phonebook, caching systems).
2. **Unique Word Counting**:
   - Count occurrences of words or detect duplicates efficiently.

**Why?**
- HashMap’s direct access property is ideal for exact-match lookups.

**Example:**
Count occurrences in `"cat car cat"`:
- HashMap: `{"cat": 2, "car": 1}`.



### **6. Edge Cases**
#### **Trie**:
- If the dataset is sparse (few words, or unrelated words), Tries can waste memory due to unused nodes.

**Example**:
Storing `"zebra"` in an empty Trie requires nodes for `'z', 'e', 'b', 'r', 'a'`.

### **HashMap**:
- Poor hash functions can lead to collisions, degrading performance.

**Example**:
If `"abc"` and `"cba"` hash to the same bucket, lookup becomes slower.


### **Use Trie**:
- Autocomplete systems, prefix-matching problems, and hierarchical data (e.g., IP addresses).

### **Use HashMap**:
- Caching, counting, and situations where exact key matching is required.


| Feature            | Trie                          | HashMap                      |
|--|-|--|
| **Structure**       | Tree-like hierarchy           | Key-value pairs              |
| **Prefix Search**   | Efficient                    | Inefficient                  |
| **Insertion/Search**| O(L)                     | O(L)                     |
| **Space Efficiency**| Higher                       | Lower                        |
| **Use Case**        | Autocomplete, prefix search  | Direct key-value mapping     |


### **Conclusion**

- **Choose Trie** for prefix-based operations like autocomplete.
- **Choose Hashmap** for fast key-value lookups. 
