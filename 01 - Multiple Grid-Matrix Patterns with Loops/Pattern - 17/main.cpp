#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter the value of N : ";
    cin >> N;

    int row = 1;
    while (row <= N) {
        int col = 1;
        while (col <= N - row + 1) {
            cout << "*" << " ";
            col = col + 1;
        }

        int space = 1;
        while (space < row) {
            cout << "-" << " ";
            space = space + 1;
        }

        cout << endl;
        row = row + 1;
    }

    return 0;
}
