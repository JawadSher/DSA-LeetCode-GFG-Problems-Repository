<h1 align='center'>Phone - Directory</h1>

## Problem Statement

**Problem URL :** [Phone Directory](https://www.geeksforgeeks.org/problems/phone-directory4628/1)

![image](https://github.com/user-attachments/assets/f2f60d5c-34b1-49f6-a0a7-5ad9746ec8f9)
![image](https://github.com/user-attachments/assets/4ba5724e-ffbd-4afa-b1c7-c90d2b49832d)
![image](https://github.com/user-attachments/assets/6c1e9517-3eed-472a-85de-82a335c1c23b)

## Problem Explanation
The problem at hand is about implementing a **phone directory system** where we are given a list of contacts and a query string. For each prefix of the query string, we need to return a list of contacts that start with that prefix.

#### Problem Breakdown with Example:

- **Input:**
  - `contacts[] = ["GEEKS", "FOR", "GEE", "SKEE", "GEEKSFORGEEKS"]`
  - `query = "GEE"`

- **Output:**
  - `GEE -> ["GEEKS", "GEE", "GEEKSFORGEEKS"]`
  - `GEEKS -> ["GEEKS", "GEEKSFORGEEKS"]`
  - `GEEKSF -> ["GEEKSFORGEEKS"]`

#### Approach:
To solve the problem, we can use a **Trie (Prefix Tree)** to store the contacts and quickly search for all contacts that share a given prefix.

1. **Trie (Prefix Tree)**: 
   - The Trie allows us to efficiently search for all words that start with a given prefix. Each node in the Trie represents a character, and the edges represent possible subsequent characters in the word. This helps in optimizing the search process as we can retrieve all words that start with a certain prefix in **O(P)** time, where **P** is the length of the prefix.

2. **Inserting words into the Trie**: For each contact, we insert it character by character into the Trie. Each node will store pointers to its child nodes, and when we reach the end of a word, we mark the node as terminal.

3. **Searching for suggestions**: For each character in the query, we navigate the Trie to find the relevant nodes that match the prefix. From the current node, we perform a **depth-first search (DFS)** to gather all contacts that start with the prefix.

## Problem Solution
```cpp
class TrieNode {
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
        
        Trie(char ch) {
            root = new TrieNode(ch);
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
        
        void insertWord(string word){
            insertUtil(root, word, 0);
        }
        
        
        
        void printSuggestions(TrieNode* curr, vector<string>& temp, string prefix){
            if(curr -> isTerminal){
                temp.push_back(prefix);
            }
            
            for(char ch = 'a'; ch <= 'z'; ch++){
                TrieNode* next = curr -> children[ch - 'a'];
                if(next != NULL){
                    prefix.push_back(ch);
                    printSuggestions(next, temp, prefix);
                    prefix.pop_back();
                }
            }
        }
        
        vector<vector<string>> getSuggestions(string str){
            TrieNode* prev = root;
            vector<vector<string>> output;
            
            string prefix = "";
            
            for(int i = 0; i < str.length(); i++){
                char lastChar = str[i];
                prefix.push_back(lastChar);
                
                TrieNode* curr = prev -> children[lastChar - 'a'];
                if(curr == NULL) {
                    for(int j = i; j < str.length(); j++) output.push_back({"0"});
                    break;
                }
                
                vector<string> temp;
                printSuggestions(curr, temp, prefix);
                
                if(temp.empty()) output.push_back({"0"});
                else{
                    sort(temp.begin(), temp.end());
                    output.push_back(temp);
                }
                
                prev = curr;
            }
            
            return output;
        }
        
};

class Solution {
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        Trie* t = new Trie('\0');
        
        for(int i = 0; i < n; i++){
            string str = contact[i];
            t -> insertWord(str);
        }
        
        return t -> getSuggestions(s);
    }
};
```

## Problem Solution Explanation
Below is a detailed **line-by-line explanation** of the given code.

#### TrieNode Class:
```cpp
class TrieNode {
public:
    char data;                    // Stores the character at this node.
    TrieNode* children[26];        // Array to store child nodes (one for each letter of the alphabet).
    bool isTerminal;               // Indicates whether this node is the end of a word.

    TrieNode(char data) {
        this -> data = data;       // Initialize the character at this node.
        for(int i = 0; i < 26; i++) children[i] = NULL;  // Initializing all children to NULL.
        isTerminal = false;  // Mark as non-terminal initially.
    }
};
```
- **`TrieNode` class**:
  - The `TrieNode` class represents a single node in the Trie.
  - **`data`**: Stores the character for that node.
  - **`children[26]`**: An array of size 26, where each index represents a letter of the alphabet. For example, `children[0]` is for 'a', `children[1]` is for 'b', and so on.
  - **`isTerminal`**: A boolean variable that indicates whether this node is the end of a word. For example, if the word ends at this node, `isTerminal` is `true`.

#### Trie Class:
```cpp
class Trie {
public:
    TrieNode* root;

    Trie(char ch) {
        root = new TrieNode(ch);  // Initialize the Trie with a root node.
    }
```
- **`Trie` class**:
  - **`root`**: This is the root node of the Trie.
  - **`Trie(char ch)`**: Constructor initializes the Trie with a root node having an arbitrary character `ch`.

##### Insert Word Function:
```cpp
    void insertUtil(TrieNode* root, string word, int index) {
        if(index == word.size()) {
            root -> isTerminal = true;  // Mark end of word when we reach the last character.
            return;
        }
        
        int charIndex = word[index] - 'a';  // Calculate the index of the current character.
        if(root -> children[charIndex] == NULL)  // If no node exists for this character, create one.
            root -> children[charIndex] = new TrieNode(word[index]);
        
        insertUtil(root -> children[charIndex], word, index+1);  // Recurse to next character.
    }
```
- **`insertUtil` function**:
  - This function recursively inserts the characters of a word into the Trie.
  - **Base Case**: If `index == word.size()`, it means we have inserted all characters of the word. So, we mark this node as `isTerminal = true` to signify that the word ends here.
  - **`charIndex`**: This calculates the index of the character in the `children` array (0 for 'a', 1 for 'b', ..., 25 for 'z').
  - **Checking and Creating Children**: If the child node for the current character doesn’t exist, we create a new `TrieNode`.
  - **Recursive Call**: The function then recursively calls itself to insert the next character in the word.

```cpp
    void insertWord(string word) {
        insertUtil(root, word, 0);  // Start inserting the word from the root node.
    }
```
- **`insertWord` function**: This is the public function that starts the insertion process. It calls `insertUtil` starting from the root node.

##### Print Suggestions Function:
```cpp
    void printSuggestions(TrieNode* curr, vector<string>& temp, string prefix) {
        if(curr -> isTerminal) {
            temp.push_back(prefix);  // If a terminal node is reached, add the prefix to suggestions.
        }

        for(char ch = 'a'; ch <= 'z'; ch++) {
            TrieNode* next = curr -> children[ch - 'a'];
            if(next != NULL) {
                prefix.push_back(ch);  // Add the character to the prefix.
                printSuggestions(next, temp, prefix);  // Recurse to find more suggestions.
                prefix.pop_back();  // Backtrack to try other children.
            }
        }
    }
```
- **`printSuggestions` function**:
  - This function is used to generate the list of all possible words from a given node (starting from a specific character).
  - **Terminal Node Check**: If the current node (`curr`) is terminal, we add the current prefix to the `temp` vector.
  - **Recursive DFS**: We loop through all characters (`a` to `z`) and recursively explore the children. If the child node exists, we append the character to the `prefix` and continue exploring deeper nodes.

##### Get Suggestions Function:
```cpp
    vector<vector<string>> getSuggestions(string str) {
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for(int i = 0; i < str.length(); i++) {
            char lastChar = str[i];
            prefix.push_back(lastChar);
            TrieNode* curr = prev -> children[lastChar - 'a'];

            if(curr == NULL) {
                for(int j = i; j < str.length(); j++) output.push_back({"0"});  // If no suggestions, add "0".
                break;
            }

            vector<string> temp;
            printSuggestions(curr, temp, prefix);  // Get all suggestions for the current prefix.

            if(temp.empty()) output.push_back({"0"});  // If no suggestions, add "0".
            else {
                sort(temp.begin(), temp.end());  // Sort suggestions lexicographically.
                output.push_back(temp);
            }

            prev = curr;  // Move to the next character in the query.
        }

        return output;  // Return all suggestions.
    }
```
- **`getSuggestions` function**:
  - This function finds all possible suggestions for each prefix of the query string.
  - **Loop through the query string**: We loop through each character in the query string.
  - **Prefix Update**: For each character in the query string, we append it to the `prefix` and try to find the corresponding child node in the Trie.
  - **If No Match**: If no child node is found (i.e., the prefix does not exist in the Trie), we add `{"0"}` to the output, indicating no suggestions.
  - **Get Suggestions**: If the node for the current prefix exists, we call `printSuggestions` to gather all suggestions starting from that node.
  - **Sort and Add Suggestions**: If there are any suggestions, we sort them lexicographically before adding them to the output. If there are no suggestions, we add `{"0"}` to indicate that there are no suggestions for the current prefix.
  - **Move to the Next Character**: After processing the current prefix, we move on to the next character in the query.

#### Solution Class:
```cpp
class Solution {
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        Trie* t = new Trie('\0');  // Create a new Trie instance.
        
        for(int i = 0; i < n; i++) {
            string str = contact[i];
            t -> insertWord(str);  // Insert each contact into the Trie.
        }
        
        return t -> getSuggestions(s);  // Get suggestions for the query string.
    }
};
```
- **`displayContacts` function**:
  - **Create Trie**: A new `Trie` object is created.
  - **Insert Contacts**: We loop through the list of contacts and insert each one into the Trie using the `insertWord` function.
  - **Get Suggestions**: After inserting all the contacts, we call `getSuggestions` to retrieve the suggestions for the query string.

### Time and Space Complexity

- **Time Complexity**:
  - **Insertion**: Each word is inserted character by character. The time complexity for inserting a word is `O(L)` where `L` is the length of the word. Inserting `n` words would take `O(n * L)` time.
  - **Query**: For each character in the query, we look up a node and recursively gather suggestions. For each prefix, we perform a DFS to gather all suggestions. The complexity for each query is `O(m * L * 26)` where `m` is the length of the query string.
  
- **Space Complexity**:
  - **Trie Storage**: The Trie requires space to store all nodes for each word. The space complexity is `O(n * L)` where `n` is the number of words and `L` is the average length of the words.

### Conclusion:
- The Trie is an efficient data structure for this problem as it allows quick prefix-based searches and word insertions.
- The approach leverages recursion to handle both insertion and prefix suggestion generation.

### Step 5: Additional Recommendations

- **Efficient Search**: The Trie is highly efficient for prefix-based searches, but keep in mind that it consumes more memory compared to other methods.
- **Edge Cases**: Make sure to handle cases where no matches are found by returning `0` as shown in the solution.
