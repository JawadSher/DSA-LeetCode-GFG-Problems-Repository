// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int min_bananas(int arr[], int h, int n){
    int min_bananas = 1;
    int max_bananas = 0;
    
    for(int i = 0; i < n; i++){
        max_bananas = max(max_bananas, arr[i]);
    }
    
    for(int speed = min_bananas; speed <= max_bananas; speed++){
        int total_hours = 0;
        
        for(int i = 0; i < n; i++){
            total_hours += (arr[i] + speed - 1) / speed;
        }
        
        if(total_hours <= h){
            return speed;
        }
    }
    return -1;
}
int main() {
    int piles[] = {3,6,7,11};
    int h = 8;
    int n = sizeof(piles) / sizeof(piles[0]);
    int output = min_bananas(piles, h, n);
    cout<<"Minimum bananas can be : "<<output;
    return 0;
}
