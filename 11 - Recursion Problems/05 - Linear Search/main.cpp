#include <iostream>
using namespace std;

bool isFound(int *arr, int n, int key){
  if(n == 0){
    return false;
  }

  if(*arr == key) return true;

  return isFound(arr + 1, n-1, key);
}

int main() {
  int new_array[] = {10, 20, 30, 15, 11, 19};
  int key = 11;
  bool result = isFound(new_array, 6, key);
  cout<<"Is key present : "<<(result ? "True" : "False")<< endl;
  
  return 0;
}
