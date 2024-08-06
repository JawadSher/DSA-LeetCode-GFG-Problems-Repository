#include<iostream>
using namespace std;

int main(){
  int N;
  cout<<"Enter the value of N : ";
  cin>>N;

  int row = 1;
  while(row <= N){
    int col = 1;
    while(col <= row){
      char ch = 'A' + row + col - 2;
      cout<<ch<<" ";
      col++;
    }
    cout<<endl;
    row++;
  }
  return 0;
}
