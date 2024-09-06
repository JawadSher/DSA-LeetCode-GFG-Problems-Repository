#include <iostream>
using namespace std;

void replaceSpace(string& s){
  string part = "@40";
  for(int i = 0; i < s.length(); i++){
    if(s[i] == ' '){
      s.replace(i, 1, part);
    }
  }
}

int main() {  
  string str = "Hello World 2";
  replaceSpace(str);

  cout<<"updated str : "<<str<<endl;
  return 0;
}
