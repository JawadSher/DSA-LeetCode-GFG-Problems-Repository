#include<iostream>
using namespace std;

int binary_search(int arr[], int n, int k){
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;
    while(start <= end){
        if(arr[mid] == k){
            return mid;
        }
        
        if(k > arr[mid]){
            start = mid +1;
        }else{
            end = mid-1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int main(){
    int new_array[] = {10, 20, 30, 40, 50, 60, 70};
    int size = sizeof(new_array) / sizeof(int);
    int key = 30;
    int key1 = 70;
    
    int key_index = binary_search(new_array, size, key);
    cout<<"Index of value "<<key<<" is "<<key_index;
    
    cout<<endl;
        
    int key_index1 = binary_search(new_array, size, key1);
    cout<<"Index of value "<<key1<<" is "<<key_index1;
    
    return 0;
}
