class Solution {
  public:
    // Function to reverse words in a given string
    string reverseWords(string &s) {
        // Create a vector to store individual words from the string
        vector<string> words;
        
        // Temporary string to hold each word while reading from the string
        string word;
        
        // Create an input string stream to split the string 's' into words
        istringstream iss(s);
        
        // While there are words in the string stream, extract them and push to the 'words' vector
        while(iss >> word) 
            words.push_back(word);  // Extract each word and add it to the vector
        
        // Reverse the vector of words
        reverse(words.begin(), words.end());
        
        // Initialize an empty string to store the result
        string ans = "";
        
        // Loop through the reversed vector of words
        for(int i = 0; i < words.size(); i++){
            // Add the current word to the result string
            ans += words[i];
            
            // If this is not the last word, add a space between words
            if(i != words.size() - 1) 
                ans += " ";
        }
        
        // Return the final reversed string
        return ans;
    }
};
