#include <iostream>
using namespace std;

void sortArray(int *arr, int n){
  
  // base case - already sorted
  if(n == 0 || n == 1) return;

  for(int i = 0; i < n-1; i++){
    if(arr[i] > arr[i + 1]){
      swap(arr[i], arr[i+1]);
    }
  }

  sortArray(arr, n-1);
}

int main() {
  int new_arr[5] = {2, 5, 1, 6, 9};

   cout<<"Before : ";
  for(int i = 0; i < 5; i++){
    cout<< new_arr[i] << " ";
  }cout<<endl;

  sortArray(new_arr, 5);
  
  cout<<"After : ";
  for(int i = 0; i < 5; i++){
    cout<< new_arr[i] << " ";
  }
  return 0;
}
