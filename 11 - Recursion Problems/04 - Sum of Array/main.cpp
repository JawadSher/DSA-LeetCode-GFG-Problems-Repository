#include <iostream>
using namespace std;

int sum(int *arr, int n){
  if(n == 0){
    return 0;
  }

  return *(arr) + sum(arr + 1, n-1);
}

int main() {
  int new_array[] = {10, 20, 30, 40, 50};

  int total = sum(new_array, 5);
  cout<<"The sum new_array is : "<< total <<endl;
  return 0;
}
