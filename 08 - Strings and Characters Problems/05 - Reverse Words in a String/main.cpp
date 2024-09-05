class Solution {
public:
    string removeSpaces(string s){
        int start = s.find_first_not_of(" ");
        if(start == string::npos){
            return "";
        }
        int end = s.find_last_not_of(" ");

        string new_str = s.substr(start, end - start + 1);
        return new_str;
    }
    string reverseWords(string s) {
        istringstream iss(removeSpaces(s));
        vector<string> words;
        string word;

        while(iss >> word){
            words.push_back(word);
        }

        for(int i = words.size() -1; i > 0; i--){
            reversed += words[i] + " ";
        }

        if(!words.empty()){
            reversed += words[0];
        }

        return reversed;
    }
};
