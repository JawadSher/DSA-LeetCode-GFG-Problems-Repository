// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int min_time(int arr[], int n, int t_trips){
    
    int min_time = 1;
    while(true){
        int trips = 0;
        for(int i = 0; i < n; i++){
            trips += min_time/arr[i];
        }
        if(trips == t_trips){
            return min_time;
        }
        min_time++;
    }
    return -1;
}
int main() {
    int bus_array[] = {1, 2, 3};
    int size = sizeof(bus_array) / sizeof(bus_array[0]);
    int trips = 5;
    
    int m_time = min_time(bus_array, size, trips);
    cout<<"Minimum time to Complete total Trips is : "<<m_time;
    return 0;
}
