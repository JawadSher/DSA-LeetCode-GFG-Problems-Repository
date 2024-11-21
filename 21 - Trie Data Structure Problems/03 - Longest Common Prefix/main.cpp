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
