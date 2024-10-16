class Solution {
public:
    int minAddToMakeValid(string s) {
        int close = 0;
        int open = 0;

        for(int i = 0; i < s.length(); i++){
            char ch = s[i];

            if(ch == '('){
                open++;
            }else if(ch == ')'){
                if(open > 0){
                    open--;
                }else{
                    close++;
                }
            }
        }

        return open + close;
    }
};
