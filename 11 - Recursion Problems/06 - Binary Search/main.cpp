#include <iostream>
using namespace std;

bool isFound(int *arr, int s, int e, int key){
  if(s > e) return false;

  int mid = s + (e - s) / 2;

  if(arr[mid] == key) return true;

  if(arr[mid] < key){
    return isFound(arr, mid+1, e, key);
  }else{
    return isFound(arr, s, mid-1, key);
  }
}

int main() {
  int new_array[] = {10, 20, 30, 40, 50, 60, 70};
  int key = 90;
  int s = 0;
  int e = 6;

  bool result = isFound(new_array, s, e, key);
  cout<< "Is key found : "<< (result ? "True" : "False") <<endl;
  return 0;
}
