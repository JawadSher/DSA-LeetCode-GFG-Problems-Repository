#include <iostream>
#include <algorithm>
using namespace std;

void bubble_sort(int new_array[], int n){
  int swapped = false;

  for(int i = 0; i < n-1; i++){

    for(int j = 0; j < n-i-1; j++){
      if(new_array[j] > new_array[j+1]){
        swap(new_array[j], new_array[j+1]);
        swapped = true;
      }
    }

    if(!swapped){
      break;
    }
  }

}

int main() {
  int new_array[6] = {10, 1, 7, 6, 14, 9};
  bubble_sort(new_array, 6);

  for(int i = 0; i < 6; i++){
    cout<<new_array[i] << " ";
  }
  return 0;
}
