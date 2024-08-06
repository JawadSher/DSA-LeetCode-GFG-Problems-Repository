#include<iostream>
using namespace std;

int is_possible(int books[], int n, int s, int mid){
    int stdnt_count = 1;
    int page_sum = 0;
    
   for(int i = 0; i < n; i++){
        if(page_sum + books[i] <= mid){
        page_sum += books[i];
    }else{
        stdnt_count++;
        if(page_sum + books[i] > mid && stdnt_count > s){
            return false;
        }
        page_sum += books[i];
    }
  }
    return true;
}

int book_allocation(int books[], int n, int s){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += books[i];
    }
    
    int start = 0;
    int end = sum - 1;
    int ans = -1;
    int mid = start + (end - start)/2;
    
    while(start <= end){
        if(is_possible(books, n, s, mid)){
            ans = mid;
            end = mid - 1;
        }else{
            start = mid + 1; 
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

int main(){
    int books[4] = {10, 20, 30, 40};
    int students = 2;
    int minimum_pages = book_allocation(books, 4, students);
    cout<<"Minimum Number of Pages can be : "<<minimum_pages;
    return 0;
}
