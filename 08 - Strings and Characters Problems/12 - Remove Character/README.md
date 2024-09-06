
<h1 align='center'>Remove - Character</h1>

## Problem Statement

**Problem URL :** [Remove Character](https://www.geeksforgeeks.org/problems/remove-character3815/1)

![image](https://github.com/user-attachments/assets/b8a89b0c-9285-4c0a-9b3d-3fbcc8f889fb)
![image](https://github.com/user-attachments/assets/29f78c33-0edb-4e36-b296-12d6097f75a6)


## Problem Solution
```cpp
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

```

## Problem Solution Explanation

