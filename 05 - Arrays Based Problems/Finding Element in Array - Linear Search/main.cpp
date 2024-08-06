// Linear Search Approach
#include<iostream>
#include<climits>
using namespace std;

bool findElement(int arr[], int n, int element){
    bool isPresent = false;
    for(int i = 0; i < n; i++){
        if(element == arr[i]){
            isPresent = true;
            break;
        }
    }
    return isPresent;
}

int main(){
    int my_arr[] = {10, 20, 30, -50, -30, 100, 1000};
    int size = sizeof(my_arr)/sizeof(int);
    
    int target_element = 100;
    bool Status = findElement(my_arr, size, target_element);
    string output = (Status) ? "Element is Present" : "Element is Absent";
    cout<<output;
    
    return 0;
}


