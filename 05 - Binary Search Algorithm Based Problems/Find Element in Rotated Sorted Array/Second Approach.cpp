#include<iostream>
using namespace std;

int search_rotated_array(int arr[], int n, int k){
    int start = 0;
    int end = n - 1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(arr[mid] == k){
            return mid;
        }
        if(arr[start] <= arr[mid]){
            if(k >= arr[start] && k < arr[mid]){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }else{
            if(k > arr[mid] && k <= arr[end]){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        mid = start + (end - start)/2;
    }
    return -1;
}
int main(){
    int new_array[] = {10, 20, 30, 1, 2, 3, 5};
    int key = 2;
    int size = sizeof(new_array) / sizeof(int);
    cout<<"Element in Found on Index : "<<search_rotated_array(new_array, size, key)<<endl;
    cout<<"Element is : "<<new_array[search_rotated_array(new_array, size, key)];
   
    return 0;
}
