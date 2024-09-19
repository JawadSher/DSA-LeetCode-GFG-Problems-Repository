#include <iostream>
using namespace std;

bool isSorted(int *arr, int n){
  if(n == 0 || n == 1){
    return true;
  }

  if(*arr > *(arr + 1)){
    return false;
  }else{
    return isSorted(arr+1, n-1);
  }

}

int main() {
  int new_array[6] = {10, 20, 30, 40, 50, 60};
  
  bool result = isSorted(new_array, 6);

  cout<<"Is Array sorted : "<< (result ? "True" : "False") <<endl;
  return 0;
}
