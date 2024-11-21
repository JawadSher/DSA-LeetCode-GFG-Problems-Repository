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
