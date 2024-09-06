#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string removeChars(string string1, string string2) {
        for(int i = 0; i < string1.length(); i++){
            for(int j = 0; j < string2.length(); j++){
                char ch = string2[j];
                if(ch == string1[i]){
                    string1.replace(i, 1, "");
                    i--;
                }
            }
        }
        
        return string1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string string1,string2;
        cin >> string1; 
        cin >> string2;
        Solution ob;
        cout << ob.removeChars(string1,string2) << endl;
    }
    return 0;
}
