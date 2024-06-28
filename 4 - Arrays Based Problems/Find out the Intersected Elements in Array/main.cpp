#include<iostream>
#include<vector>
using namespace std;

void intersection(int arr[], int arr1[], int n){
    vector<int> intersected_elements;
    
    int i = 0;
    int j = 0;
    
    while(i < n && j < n){
        if(arr[i] == arr1[j]){
            intersected_elements.push_back(arr[i]);
            i++;
            j++;
        }else if(arr[i] < arr1[j]){
            i++;
        }else{
            j++;
        }
    }
    
    cout<<"Intersected Elements are : ";
    for(auto elements : intersected_elements){
        cout<<elements<<" ";
    }
}

int main(){
    int new_array[5] = {1, 2, 2, 3, 4};
    int new_array1[5] = {2, 2, 3, 3, 6};
    
    intersection(new_array, new_array1, 5);
    
    return 0;
}
