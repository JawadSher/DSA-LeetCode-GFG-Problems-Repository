#include <iostream>
using namespace std;

int main() {
    int n;
    int range = 5;
    int ans = 0;
    while(range){
        cout<<"Enter the value of n : ";
        cin>>n;
        ans = ans * 10 + n;
        range--;
    }
    cout<<"Concatenated Number is : "<<ans;
   
    return 0;
}
