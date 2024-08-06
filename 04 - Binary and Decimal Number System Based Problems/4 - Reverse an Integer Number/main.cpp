#include <iostream>
using namespace std;

int reverser(int num){
    int reverse_num = 0;
    while(num){
        int digit = num % 10;
        reverse_num = reverse_num * 10 + digit;
        num = num / 10;
    }
    return reverse_num;
}

int main() {
    int num = 123456;
    cout<<"Before Reverse : "<<num<<endl;
    int r_value = reverser(num);
    cout<<"After Reverse : "<<r_value;
    return 0;
}
