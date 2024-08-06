#include <iostream>
using namespace std;

double median_of_array(int nums_1[], int n, int nums_2[], int m) {
    int t_size = n + m;
    int index_1 = (t_size - 1) / 2;  // The correct 0-based middle index for odd size
    int index_2 = t_size / 2;        // The correct 0-based middle index for even size

    int elmnt_1 = -1;
    int elmnt_2 = -1;

    int i = 0, j = 0, k = 0;

    // Merge arrays until one is exhausted
    while (i < n && j < m) {
        if (nums_1[i] < nums_2[j]) {
            if (k == index_1) elmnt_1 = nums_1[i];
            if (k == index_2) elmnt_2 = nums_1[i];
            i++;
        } else {
            if (k == index_1) elmnt_1 = nums_2[j];
            if (k == index_2) elmnt_2 = nums_2[j];
            j++;
        }
        k++;
    }

    // If nums_1 is not exhausted
    while (i < n) {
        if (k == index_1) elmnt_1 = nums_1[i];
        if (k == index_2) elmnt_2 = nums_1[i];
        i++;
        k++;
    }

    // If nums_2 is not exhausted
    while (j < m) {
        if (k == index_1) elmnt_1 = nums_2[j];
        if (k == index_2) elmnt_2 = nums_2[j];
        j++;
        k++;
    }

    // Calculate median
    if (t_size % 2 == 1) {
        return elmnt_2;
    } else {
        return (elmnt_1 + elmnt_2) / 2.0;
    }
}

int main() {
    int array_1[] = {1, 2, 3};
    int n = sizeof(array_1) / sizeof(array_1[0]);

    int array_2[] = {1, 2, 3, 4};
    int m = sizeof(array_2) / sizeof(array_2[0]);

    double median = median_of_array(array_1, n, array_2, m);
    cout << "The median value is: " << median << endl;

    return 0;
}
