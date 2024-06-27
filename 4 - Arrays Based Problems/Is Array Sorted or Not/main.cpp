// Linear Approach
#include<iostream>
using namespace std;

void check_sorting(int arr[], int s) {
    bool isSorted = true;
    string order = "";

    if (s < 2){
        isSorted = true;
        order = "Array is too small to determine order";
    }else{
        bool Ascending = true;
        bool Descending = true;
        
        for(int i = 1; i < s; i++){
            if(arr[i] < arr[i-1]){
                Ascending = false;
            }
            if(arr[i] > arr[i-1]){
                Descending = false;
            }
        }
        if(Ascending){
            order = "Ascending Order";
        }else if(Descending){
            order = "Descending Order";
        }else{
            order = "Un-ordered Array";
            isSorted = false;
        }
    }
    
    string sorted = isSorted ? "True" : "False";
    cout << "Order: " <<sorted << "\n" <<"Status: "<< order << endl;
}

int main() {
    int my_array_1[] = {10, 20, 30, 40, 50, 60};
    int my_array_2[] = {60, 50, 40, 30, 20, 10};
    int my_array_3[] = {60, 30, 50, 40, 20, 10};
    int size = 6;
    
    cout<<"-----> First Array <-----"<<endl;
    check_sorting(my_array_1, size);
    cout<<endl;
    cout<<"-----> Second Array <-----"<<endl;
    check_sorting(my_array_2, size);
    cout<<endl;
    cout<<"-----> Third Array <-----"<<endl;
    check_sorting(my_array_3, size);
    return 0;
}
