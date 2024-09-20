#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void reversed(string &new_str, int i){

  int n = new_str.size()-i-1;
  if(i >= n) return ;

  swap(new_str[i], new_str[n]);

  reversed(new_str, i+1);
}

int main() {
  string new_str = "ABCDEF";
  int i = 0;
  // int j = new_str.size();

  cout << "Before : " << new_str <<endl;

  reversed(new_str, i);

  cout<< "After : " << new_str <<endl;
  return 0;
}
