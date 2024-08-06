// Online C++ compiler to run C++ program online
#include <iostream>
#include <climits>
using namespace std;

double median(int nums1[], int m, int nums2[], int n){
    
    if(m > n){
        return median(nums2, n, nums1, m);
    }
    
    int start = 0;
    int end = m;
    cout<<"end : "<<end<<endl;
    
    while(start <= end){
        int px = start + (end - start)/2;
        cout<<"px : "<<px<<endl;
        int py = (m + n + 1)/2 - px;
        cout<<"py : "<<py<<endl;
        
        int x1 = (px == 0) ? INT_MIN : nums1[px -1];
        int x2 = (py == 0) ? INT_MIN : nums2[py - 1];
        
        int x3 = (px == m) ? INT_MAX : nums1[px];
        cout<<"x3 : "<<x3<<endl;
        int x4 = (py == n) ? INT_MAX : nums2[py];
        cout<<"x4 : "<<x4<<endl;
        
        if(x1 <= x4 && x2 <= x3){
            
            if((m+n % 2 == 1)){
                return max(x1, x2);
            }else{
                return (max(x1, x2) + min(x3, x4))/2.0;
            }
        }
        
        if(x1 > x4){
            end = px - 1;
        }else{
            start = px + 1;
        }
    }
    return - 1;
}
int main() {
   int array_1[] = {1, 2, 3};
    int m = sizeof(array_1) / sizeof(array_1[0]);
    
    int array_2[] = {1, 2, 3, 4, 5};
    int n = sizeof(array_2) / sizeof(array_2[0]);
    
    double median_value = median(array_1, m, array_2, n);
    cout<<"The median value is : "<<median_value;

    return 0;
}
