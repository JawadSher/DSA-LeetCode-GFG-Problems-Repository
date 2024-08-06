// Simple grid with repeating sequences of numbers in reverse order in each row.
#include <iostream>
using namespace std;

int main() {

    int N;
    cout<<"Enter the value of N: ";
    cin>>N;

    int row= 1;
    while(row <= N) {

        int col = 1;
        while(col <= N) {
            cout<<N-col+1<<" ";
            col++;
        }
        cout<<endl;
        row++;
    }

    return 0;
}
