#include <iostream>
#include <algorithm>
using namespace std;

int partition(int *arr, int s, int e){
  int pivot = arr[s];

  int count = 0;
  for(int i = s+1; i <= e; i++){
    if(arr[i] <= pivot){
      count++;
    }
  }

  int pivotIndex = s + count;
  swap(arr[pivotIndex], arr[s]);

  int i = s, j = e;

  while(i < pivotIndex && j > pivotIndex){
    while(arr[i] <= pivot){
      i++;
    }

    while(arr[j] > pivot){
      j--;
    }

    if(i < pivotIndex && j > pivotIndex){
      swap(arr[i++], arr[j--]);
    }
  }

  return pivotIndex;
}

void quickSort(int *arr, int s, int e){
  if(s >= e) return;

  int index = partition(arr, s, e);

  quickSort(arr, s, index-1);
  quickSort(arr, index+1, e);

}

int main() {
  int new_array[] = {3, 2, 1, 5, 4, 0};
  int n = 6;

  cout<<"Un-sorted Before : ";
  for(int i = 0; i < n; i++){
    cout<< new_array[i] << " ";
  }cout<<endl;

  quickSort(new_array, 0, n-1);
  
  cout<<"sorted After : ";
  for(int i = 0; i < n; i++){
    cout<< new_array[i] << " ";
  }cout<<endl;


  return 0;
}
