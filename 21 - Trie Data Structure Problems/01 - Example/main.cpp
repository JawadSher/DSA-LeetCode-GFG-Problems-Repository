#include <iostream>
using namespace std;

class TrieNode{
  public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(int data){
      this -> data = data;
      for(int i = 0; i < 26; i++) children[i] = NULL;
      isTerminal = false;
    }
};

class Trie{
  public:
    TrieNode* root;

    Trie(){
      root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string& word, int index){
      if(index == word.size()) {
        root -> isTerminal = true;
        return;
      }

      int charIndex = word[index] - 'a';
      if(root -> children[charIndex] == NULL) root -> children[charIndex] = new TrieNode(word[index]);
      
      insertUtil(root->children[charIndex], word, index+1);
    }
    void insertWord(string word){
      for (char& c : word) c = tolower(c);
      insertUtil(root, word, 0);
    }
    
    bool searchUtil(TrieNode* root, string word, int index){
      if(index == word.size()) return root -> isTerminal;

      int charIndex = word[index] - 'a';
      if(root -> children[charIndex] == NULL) return false;

      return searchUtil(root->children[charIndex], word, index+1);
    }

    bool searchWord(string word){
      for (char& c : word) c = tolower(c);
      return searchUtil(root, word, 0);
    }

    bool removeWordUtil(TrieNode* root, string word, int index){
      if(index == word.size()){
        if(!root -> isTerminal) return false;
        
        root -> isTerminal = false;

        for(int i = 0; i < 26; i++) if(root -> children[i] != NULL) return false;
        return true;
      } 

      int charIndex = word[index] - 'a';
      TrieNode* child = root -> children[charIndex];
      if(child == NULL) return false;

      bool shouldDeleteChild = removeWordUtil(child, word, index + 1);

      if(shouldDeleteChild){
        delete child;
        root -> children[charIndex] = NULL;

        if(!root -> isTerminal){
          for(int i = 0; i < 26; i++) if(root->children[i] != NULL) return false;
          return true;
        }
      }

      return false;
    }
    void removeWord(string word){
      for (char& c : word) c = tolower(c);
      removeWordUtil(root, word, 0);
    }
};

int main() {
  Trie* t = new Trie();

  // Insert words
  t->insertWord("abcd");
  t->insertWord("abc");
  t->insertWord("trie");


  // Search words
  cout << "------------- Search Words -------------" << endl;
  cout << "abc : "<<(t->searchWord("abc") ? "Found\n" : "Not Found\n");
  cout << "abcd : "<<(t->searchWord("abcd") ? "Found\n" : "Not Found\n");
  cout << "trie : "<<(t->searchWord("trie") ? "Found\n" : "Not Found\n");
  cout << "tried : "<<(t->searchWord("tried") ? "Found\n" : "Not Found\n");

  // Remove words
  cout << "------------- Remove Words -------------" << endl;
  t->removeWord("abc");
  t->removeWord("abcd");

  cout << "abc : "<<(t->searchWord("abc") ? "Found\n" : "Not Found\n");
  cout << "abcd : "<<(t->searchWord("abcd") ? "Found\n" : "Not Found\n");

  // Cleanup
  delete t; 
  
  return 0;
}
