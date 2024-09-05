#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    string reverseWords(string S) 
    {   
        istringstream iss(S);
        vector<string> v;
        string word;
        string reversed = "";
        
        while (getline(iss, word, '.')) {
            if (!word.empty()) {
                v.push_back(word);
            }
        }

        for(int i = v.size() -1; i >= 0; i--){
            reversed += v[i];
            if(i > 0){
                reversed += '.';
            }
        }
        
        return reversed;
    } 
};

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
