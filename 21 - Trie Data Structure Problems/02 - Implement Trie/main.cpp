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
