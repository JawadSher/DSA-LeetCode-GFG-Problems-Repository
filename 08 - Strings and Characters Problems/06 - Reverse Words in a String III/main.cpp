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
        string char_reversed;

        while(iss >> word){
            words.push_back(word);
        }

        for(int i = 0; i < words.size(); i++){
            string c_word = words[i];
            int s = 0;
            int e = c_word.size() - 1;

            while(s<e){
                swap(c_word[s], c_word[e]);
                s++;
                e--;
            }
            
            char_reversed += c_word;

            if(i < words.size() - 1){
                char_reversed += ' ';
            }
        }


        return char_reversed;
    }
};
