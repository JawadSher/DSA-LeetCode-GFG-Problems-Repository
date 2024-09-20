#include <iostream>
using namespace std;

void pallindrome(string new_str, int i){
  int n = new_str.size() - i - 1;

  if(i >= n){
    cout<< "Palindrom" <<endl;
    return;
  }

  if (new_str[i] != new_str[n]){
    cout<< "Not Palindrom" <<endl;
    return;
  }

  pallindrome(new_str, i+1);
}

int main() {
  string new_str = "ABBCCBBA";
  int i = 0;

  pallindrome(new_str, i);
  return 0;
}
