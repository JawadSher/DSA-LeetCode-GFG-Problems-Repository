class Solution {
public:
    int reverse(int x) {
        int reverse_Num = 0;
        int i = 0;
        while(x){
            int digit = x % 10;
            if(reverse_Num > INT_MAX/10 || reverse_Num < INT_MIN/10){
                return 0;
            }
            reverse_Num = reverse_Num * 10 + digit;
            i++;
            x = x/10;
        }
        return reverse_Num;
    }
};
