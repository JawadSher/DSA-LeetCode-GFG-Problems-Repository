#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    char getMaxOccuringChar(string str)
    {
        int arr[26] = {0};
        int number = 0;
        
        for(int i = 0; i < str.length(); i++){
            char ch = str[i];
            
            if(ch >= 'a' && ch <= 'z'){
                number = ch - 'a';
            }else{
                number = ch - 'A';
            }
            
            arr[number]++;
        }
        
        int maxi, ans;
        for(int i = 0; i < 26; i++){
            if(maxi < arr[i]){
                ans = i;
                maxi = arr[i];
            }
        }
        
        char maxChar = 'a' + ans;
        return maxChar;
    }

};

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
