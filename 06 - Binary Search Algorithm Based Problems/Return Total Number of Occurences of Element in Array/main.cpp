#include<iostream>
using namespace std;

int first_Index(int arr[], int n, int k){
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start)/2;
    int index = -1;
    
    while(start <= end){
        if(arr[mid] == k){
            index = mid;
            end = mid - 1;
        }else if(k < arr[mid]){
            end = mid - 1;
        }else{
            start = mid +1;
        }
        mid = start + (end - start)/2;
    }
    return index;
};

int last_Index(int arr[], int n, int k){
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) /2;
    int index = -1;
    
    while(start <= end){
        if(arr[mid] == k){
            index = mid;
            start = mid + 1;
        }else if(k < arr[mid]){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return index;
};


int main(){
    int new_array[] = {10, 20, 30, 30, 30, 40, 50, 60, 70};
    int size = sizeof(new_array) / sizeof(int);
    int key = 30;
    
    int first_index = first_Index(new_array, size, key);
    int last_index = last_Index(new_array, size, key);
    int total_occurences = (last_index - first_index) +1;
    cout<<"Total Number of Occurences is "<<total_occurences<<" of Element "<<key;
    
    return 0;
}
