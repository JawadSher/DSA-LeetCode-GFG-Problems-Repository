#include<iostream>
using namespace std;

bool search_matrix(int arr[][4], int s, int col, int key ){
    int start = 0;
    int end = s - 1;
    int mid = start + (end - start)/2;
    
    while(start <= end){
        int rows = mid / col;
        int cols = mid % col;
        
        if(arr[rows][cols] == key){
            cout<<"Element Found at Row: "<<rows<<" and Index: "<<cols<<endl;
            return true;
        }else if(arr[rows][cols] > key){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return false;
    
}

int main(){
    int matrix[][4] = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    
    int target_key = 30;
    int size = sizeof(matrix) / sizeof(int);
    bool is_found = search_matrix(matrix, size, 4, target_key);
    
    if(is_found){
        cout<<"Element Found";
    }else{
        cout<<"Element Not Found";
    }
    
    return 0;
}
