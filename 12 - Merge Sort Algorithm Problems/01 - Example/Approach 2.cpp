#include <iostream>
using namespace std;

void merge(int *arr, int s, int e) {
    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1;  // Length of the left half
    int len2 = e - mid;      // Length of the right half

    // Create a temporary array to store the merged result
    int *temp = new int[len1 + len2];

    int i = s;         // Starting index for left half
    int j = mid + 1;   // Starting index for right half
    int k = 0;         // Index for the temp array

    // Merge both halves into the temp array
    while (i <= mid && j <= e) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // Copy any remaining elements from the left half
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy any remaining elements from the right half
    while (j <= e) {
        temp[k++] = arr[j++];
    }

    // Copy the sorted elements back into the original array
    for (int x = 0, y = s; x < len1 + len2; x++, y++) {
        arr[y] = temp[x];
    }

    // Free the temporary array
    delete[] temp;
}

void mergeSort(int *arr, int s, int e) {
    // Base case: if the subarray has 1 or 0 elements, it's already sorted
    if (s >= e) return;

    int mid = s + (e - s) / 2;

    // Sort the left half
    mergeSort(arr, s, mid);

    // Sort the right half
    mergeSort(arr, mid + 1, e);

    // Merge the two sorted halves
    merge(arr, s, e);
}

int main() {
    int un_sorted_arr[5] = {2, 5, 1, 6, 9};
    int n = 5;

    cout << "Un-sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << un_sorted_arr[i] << " ";
    }
    cout << endl;

    // Sort the array
    mergeSort(un_sorted_arr, 0, n - 1);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << un_sorted_arr[i] << " ";
    }
    cout << endl;

    return 0;
}
