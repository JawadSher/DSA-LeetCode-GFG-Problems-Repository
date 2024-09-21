#include <iostream>
using namespace std;

void merge(int *arr, int s, int e){
  int mid = s + (e - s)/2;
  
  int len1 = mid - s + 1;
  int len2 = e - mid;

  int *left = new int[len1];
  int *right = new int[len2];

  int MainIndex = s;
  for(int i = 0; i < len1; i++){
    left[i] = arr[MainIndex++];
  }

  MainIndex = mid + 1;
  for(int i = 0; i < len2; i++){
    right[i] = arr[MainIndex++];
  }

  int leftIndex = 0;
  int rightIndex = 0;
  MainIndex = s;

  while(leftIndex < len1 && rightIndex < len2){
    if(left[leftIndex] < right[rightIndex]){
      arr[MainIndex++] = left[leftIndex++];
    }else{
      arr[MainIndex++] = right[rightIndex++];
    }
  }

  while(leftIndex < len1){
    arr[MainIndex++] = left[leftIndex++];
  }

  while(rightIndex < len2){
    arr[MainIndex++] = right[rightIndex++];
  }

  delete[] left;
  delete[] right;
}

void mergeSort(int *arr, int s, int e){
  // base case
  if(s >= e) return;

  int mid = s + (e - s)/2;

  mergeSort(arr, s, mid);
  mergeSort(arr, mid+1, e);

  merge(arr, s, e);
}

int main() {
  int un_sorted_arr[5] = {2, 5, 1, 6, 9};
  int n = 5;


  cout<< "Un-sorted Array : ";
  for(int i = 0; i < n; i++){
    cout<< un_sorted_arr[i] << " ";
  }cout<<endl;
  

  mergeSort(un_sorted_arr, 0, n-1);


  cout<< "Sorted Array : ";
  for(int i = 0; i < n; i++){
    cout<< un_sorted_arr[i] << " ";
  }cout<<endl;
  return 0;
}
