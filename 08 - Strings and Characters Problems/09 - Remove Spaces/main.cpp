class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        int index = 0;

        while(i < n){
            int j = i + 1;

            while(j < n && chars[i] == chars[j]){
                j++;
            }
            chars[index++] = chars[j];
            int count = j - i;

            if(count > 9){
                string s_count = to_string(count);
                for(char c : s_count){
                    chars[index++] = c;
                }
            }

            i = j;
        }
        return index;
    }
};
