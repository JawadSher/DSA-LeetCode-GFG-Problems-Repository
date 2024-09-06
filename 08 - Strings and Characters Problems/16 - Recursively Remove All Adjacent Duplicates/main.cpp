#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        string removeAdjecent(const string& s){
           string unique_s;
           
           int i = 0;
           while(i < s.length()){
               if(s[i] == s[i+1] && i+1 < s.length()){
                   while(s[i] == s[i+1] && i+1 < s.length()){
                       i++;
                   }
               }else{
                   unique_s += s[i];
               }
               
               i++;
            }
           return unique_s;
        }
  public:
    string rremove(string s) {
       
       string current = s;
       string previous;
       do{
           previous = current;
           current = removeAdjecent(current);
       }while(current != previous);
       
       return current;
    }   
};
int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}
